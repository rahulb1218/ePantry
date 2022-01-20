// ePantry.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <ctype.h>
#include <fstream>

using namespace std;
int main()
{
    std::string item;
    std::string date;
    std::string location;
    bool isDate = 0;
    std::string month = "";
    std::string day = "";
    std::string year = "";
    int monthInt = 0;
    int dayInt = 0;
    std::string newEntry;
    ofstream file;
    file.open("items.txt", std::ios_base::app);
    std::cout << "What item would you like to add? ";
    cin >> item; 
    while (isDate == 0)
    {
        std::cout << "\n";
        std::cout << "When is this expiring?(enter in this format: 01012022) ";
        cin >> date;
        int isInt = 0;
        for (int i = 0; i < date.length(); i++)
        {
            if (isdigit(date[i]))
            {
                isInt++;
            }
        }
        
        if (isInt == 8)
        {
            month = month + date[0] + date[1];
            day = day + date[2] + date[3];
            year = year + date[4] + date[5] + date[6] + date[7];
            monthInt = std::stoi(month);
            dayInt = std::stoi(day);

        }
        if (isInt == 8 && monthInt < 13 && dayInt < 32)
        {
            isDate = 1;
        }
    }
    date = month + "-" + day + "-" + year;
    std::cout << "\n";
    std::cout << "Where are you going to store this item? ";
    cin >> location;
    std::cout << "\n";
    newEntry = item + " " + date + " " + location + "\n";
    std::cout << newEntry;
    file << newEntry;
    file.close();



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
