// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City
{
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country
{
    std::string name;
    std::vector<City> cities;
};

struct Tours
{
    std::string title;
    std::vector<Country> countries;
};
void ruler()
{
    std::cout << "1234567890123456789012345678901234567890123456789012345678901234567890" << std::endl;
}
int main()
{
    ruler();
    Tours tours{"Tour Ticket Prices from Miami",
                {
                    {
                        "Colombia",
                        {{"Bogota", 8778000, 400.98},
                         {"Cali", 2401000, 424.12},
                         {"Medellin", 2464000, 350.98},
                         {"Cartagena", 972000, 345.34}},
                    },
                    {
                        "Brazil",
                        {{"Rio De Janiero", 13500000, 567.45},
                         {"Sao Paulo", 11310000, 975.45},
                         {"Salvador", 18234000, 855.99}},
                    },
                    {
                        "Chile",
                        {{"Valdivia", 260000, 569.12},
                         {"Santiago", 7040000, 520.00}},
                    },
                    {"Argentina", {{"Buenos Aires", 3010000, 723.77}}},
                }};

    // Unformatted display so you can see how to access the vector elements

    std::cout << std::setw(50) << tours.title << std::endl;
    std::cout << std::setw(70) << std::setfill('-') << "-\n";
    std::cout << std::setfill(' ');
    std::cout
        << std::setw(11) << "Country" << std::setw(4) << "|" << std::setw(14) << "City" << std::setw(10) << "|" << std::setw(14) << "Population" << std::setw(5) << "|" << std::setw(7) << "Cost" << std::setw(4) << "|" << std::endl;
    std::cout << std::setw(70) << std::right << std::setfill('-') << "-\n";
    std::cout << std::setfill(' ');

    for (auto country : tours.countries)
    { // loop through the countries
        std::cout << std::setw(3) << " " << std::setw(11) << std::left << country.name << "|" << std::setw(54) << std::right << "|" << std::endl;
        std::cout << std::setw(70) << std::right << std::setfill('-') << "\n";
        std::cout << std::setfill(' ');

        for (auto city : country.cities)
        { // loop through the cities for each country
            std::cout << std::setw(15) << std::right << "|" << std::setw(5) << "" << std::left << std::setw(18) << city.name
                      << "|";
            std::cout << std::setw(6) << "" << std::setw(12) << std::left << city.population << std::right << "|";
            std::cout << std::setw(2) << "" << std::setw(8) << std::left << city.cost << "|\n";
        }
        std::cout << std::setw(70) << std::right << std::setfill('-') << "\n";
        std::cout << std::setfill(' ');
    }

    std::cout << std::endl
              << std::endl;
    return 0;
}

/*
Print Results:

                     Tour Ticket Prices from Miami
---------------------------------------------------------------------
    Country   |          City         |    Population    |   Cost   |
---------------------------------------------------------------------
   Colombia   |                                                     |
---------------------------------------------------------------------
              |     Bogota            |      8778000     |  400.98  |
              |     Cali              |      2401000     |  424.12  |
              |     Medellin          |      2464000     |  350.98  |
              |     Cartagena         |      972000      |  345.34  |
---------------------------------------------------------------------
   Brazil     |                                                     |
---------------------------------------------------------------------
              |     Rio De Janiero    |      13500000    |  567.45  |
              |     Sao Paulo         |      11310000    |  975.45  |
              |     Salvador          |      18234000    |  855.99  |
---------------------------------------------------------------------
   Chile      |                                                     |
---------------------------------------------------------------------
              |     Valdivia          |      260000      |  569.12  |
              |     Santiago          |      7040000     |  520     |
---------------------------------------------------------------------
   Argentina  |                                                     |
---------------------------------------------------------------------
              |     Buenos Aires      |      3010000     |  723.77  |
---------------------------------------------------------------------

*/