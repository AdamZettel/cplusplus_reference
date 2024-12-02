#include <iostream>
#include <fstream>

int main() {
    std::ofstream outfile("example.txt");
    outfile << "This is a test file." << std::endl;
    outfile.close();

    std::ifstream infile("example.txt");
    std::string line;
    std::getline(infile, line);
    std::cout << "Read from file: " << line << std::endl;
    infile.close();
    return 0;
}
