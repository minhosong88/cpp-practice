// Section 19
// Read File 4
// Read and display Shakespeare Sonnet 18 poem using unformatted get
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream in_file;
    in_file.open("poem2.txt");
    if (!in_file)
    {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    // Reading character by character with unformatted get
    char c{};
    while (in_file.get(c))
    {
        std::cout << c;
    }
    std::cout << std::endl;

    return 0;
}