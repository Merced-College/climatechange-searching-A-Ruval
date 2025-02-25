#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <string>
#include "StateClimate.h"

// Utility function to convert a string to uppercase
std::string toUpperCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// Define the binary search function to find the first occurrence
int binarySearch(const std::vector<StateClimate>& data, const std::string& stateName) {
    std::string upperStateName = toUpperCase(stateName);
    int left = 0, right = data.size() - 1;
    
    while (left <= right) {
        int middle = left + (right - left) / 2;
        std::string middleStateName = toUpperCase(data[middle].getStateName());
        
        if (middleStateName == upperStateName) {
            // Move left to find the first occurrence
            while (middle > 0 && toUpperCase(data[middle - 1].getStateName()) == upperStateName) {
                middle--;
            }
            return middle;
        }
        
        if (middleStateName < upperStateName) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    
    return -1;
}

// Define a function to search and display all instances of a state's climate data
void searchAndDisplay(const std::vector<StateClimate>& data, const std::string& stateName) {
    int index = binarySearch(data, stateName);
    if (index == -1) {
        std::cout << "State not found. Please try again." << std::endl;
        return;
    }

    std::string upperStateName = toUpperCase(stateName);

    // Linear search from the binary search index to find all instances
    while (index < data.size() && toUpperCase(data[index].getStateName()) == upperStateName) {
        data[index].display();
        index++;
    }
}

int main() {
    std::vector<StateClimate> climateData;
    std::map<int, std::string> fipsToStateName = {
        {1, "ALABAMA"}, {2, "ALASKA"}, {4, "ARIZONA"}, {5, "ARKANSAS"}, 
        {6, "CALIFORNIA"}, {8, "COLORADO"}, {9, "CONNECTICUT"}, {10, "DELAWARE"}, 
        {11, "DISTRICT OF COLUMBIA"}, {12, "FLORIDA"}, {13, "GEORGIA"}, {15, "HAWAII"}, 
        {16, "IDAHO"}, {17, "ILLINOIS"}, {18, "INDIANA"}, {19, "IOWA"}, 
        {20, "KANSAS"}, {21, "KENTUCKY"}, {22, "LOUISIANA"}, {23, "MAINE"}, 
        {24, "MARYLAND"}, {25, "MASSACHUSETTS"}, {26, "MICHIGAN"}, {27, "MINNESOTA"}, 
        {28, "MISSISSIPPI"}, {29, "MISSOURI"}, {30, "MONTANA"}, {31, "NEBRASKA"}, 
        {32, "NEVADA"}, {33, "NEW HAMPSHIRE"}, {34, "NEW JERSEY"}, {35, "NEW MEXICO"}, 
        {36, "NEW YORK"}, {37, "NORTH CAROLINA"}, {38, "NORTH DAKOTA"}, {39, "OHIO"}, 
        {40, "OKLAHOMA"}, {41, "OREGON"}, {42, "PENNSYLVANIA"}, {44, "RHODE ISLAND"}, 
        {45, "SOUTH CAROLINA"}, {46, "SOUTH DAKOTA"}, {47, "TENNESSEE"}, {48, "TEXAS"}, 
        {49, "UTAH"}, {50, "VERMONT"}, {51, "VIRGINIA"}, {53, "WASHINGTON"}, 
        {54, "WEST VIRGINIA"}, {55, "WISCONSIN"}, {56, "WYOMING"}
    };

    std::ifstream file("/workspaces/climatechange-searching-A-Ruval/climdiv_state_year.csv");
    
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line); // Skip header line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        int fips, year;
        double temp, tempc;
        char comma;

        ss >> fips >> comma >> year >> comma >> temp >> comma >> tempc;

        // Get the state name from the fipsToStateName map
        std::string stateName = fipsToStateName[fips];
        climateData.emplace_back(fips, year, temp, tempc, stateName);
    }

    file.close();

    // Sort climateData by state name for binary search
    std::sort(climateData.begin(), climateData.end(), [](const StateClimate& a, const StateClimate& b) {
        return a.getStateName() < b.getStateName();
    });

    std::string stateName;
    while (true) {
        std::cout << "Enter a state name to search (or 'exit' to quit): ";
        std::getline(std::cin, stateName);
        
        if (stateName == "exit") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }

        searchAndDisplay(climateData, stateName);
    }

    return 0;
}
