#include <iostream>
#include <atomic>
#include <memory>

// Policy: Reference counting for shared ownership
struct RefCounted {
    template <typename T>
    class OwnershipPolicy {
    private:
        T* ptr_;
        std::atomic<int>* refCount_;
    public:
        OwnershipPolicy(T* ptr) : ptr_(ptr), refCount_(new std::atomic<int>(1)) {}
        OwnershipPolicy(const OwnershipPolicy& other) : ptr_(other.ptr_), refCount_(other.refCount_) {
            ++(*refCount_);
        }
        OwnershipPolicy& operator=(const OwnershipPolicy& other) {
            if (this != &other) {
                release();
                ptr_ = other.ptr_;
                refCount_ = other.refCount_;
                ++(*refCount_);
            }
            return *this;
        }
        ~OwnershipPolicy() { release(); }

        T* get() const { return ptr_; }
        void release() {
            if (refCount_ && --(*refCount_) == 0) {
                delete ptr_;
                delete refCount_;
            }
        }
    };
};

// Policy: No-op (no special thread safety)
struct NoThreading {
    struct ThreadingPolicy {
        void lock() {}
        void unlock() {}
    };
};

// Combine Policies into a SmartPointer
template <typename T,
          template <typename> class OwnershipPolicy = RefCounted::OwnershipPolicy,
          typename ThreadingPolicy = NoThreading::ThreadingPolicy>
class SmartPointer : private OwnershipPolicy<T>, private ThreadingPolicy {
public:
    explicit SmartPointer(T* ptr) : OwnershipPolicy<T>(ptr) {}

    T* operator->() {
        lock();
        return OwnershipPolicy<T>::get();
    }

    T& operator*() {
        lock();
        return *(OwnershipPolicy<T>::get());
    }

    ~SmartPointer() { unlock(); }

private:
    void lock() { ThreadingPolicy::lock(); }
    void unlock() { ThreadingPolicy::unlock(); }
};

// Example usage
struct Test {
    void sayHello() const { std::cout << "Hello, World!" << std::endl; }
};

int main() {
    // Create a smart pointer with ref-counting and no threading
    SmartPointer<Test> ptr(new Test);
    ptr->sayHello();

    // Copy demonstrates shared ownership
    SmartPointer<Test> ptr2 = ptr;
    ptr2->sayHello();

    return 0;
}
