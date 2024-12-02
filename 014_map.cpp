#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> ageMap;
    ageMap["Alice"] = 25;
    ageMap["Bob"] = 30;

    for (const auto& pair : ageMap) {
        std::cout << pair.first << ": " << pair.second << " years old" << std::endl;
    }
    return 0;
}
