#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>

int main() {
    // Specify the directory and file name
    std::filesystem::path dir = "./data"; // Directory where CSV will be saved
    std::filesystem::path filePath = dir / "output.csv"; // Full path to the file

    // Create a vector of rows, each being a vector of strings
    std::vector<std::vector<std::string>> data = {
        {"Name", "Age", "City"},
        {"John", "30", "New York"},
        {"Alice", "28", "Los Angeles"},
        {"Bob", "35", "Chicago"}
    };

    // Check if the directory exists, if not, create it
    if (!std::filesystem::exists(dir)) {
        std::filesystem::create_directory(dir);
        std::cout << "Directory created: " << dir << std::endl;
    }

    // Open a CSV file for writing
    std::ofstream file(filePath);

    if (file.is_open()) {
        // Write each row
        for (const auto& row : data) {
            for (size_t i = 0; i < row.size(); ++i) {
                file << row[i];
                if (i < row.size() - 1) {
                    file << ","; // Separate columns by commas
                }
            }
            file << "\n"; // Move to the next line after each row
        }
        file.close(); // Close the file
        std::cout << "CSV file has been written to: " << filePath << std::endl;
    } else {
        std::cerr << "Unable to open the file: " << filePath << std::endl;
    }

    return 0;
}
