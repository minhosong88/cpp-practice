// Section 19
// Read File 2
// Continuous read of 3 data items in a loop
#include <iostream>
#include <iomanip>
#include <fstream>

int main()
{
    std::ifstream in_file;
    std::string line;
    int num;
    double total;
    in_file.open("test2.txt");
    if (!in_file)
    {
        std::cerr << "Problem Opening File" << std::endl;
        exit(1); // Calling Exit function
    }
    // EOF method returns true if end-of-file has been reached
    // while(in_file >>line >> num >> total) // has the same results
    while (!in_file.eof())
    {
        in_file >> line >> num >> total;
        std::cout << std::setw(10) << std::left << line << std::setw(10) << num << std::setw(10) << total << std::endl;
    }

    in_file.close();
    return 0;
}
