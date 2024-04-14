#include "game.h"
#include <chrono>
#include <algorithm>
#include <fstream>

void compilingPieceVision();

const std::string gamesFileName = "data/games.csv";

int main()
{

    compilingPieceVision();

    auto start = std::chrono::high_resolution_clock::now();

    const int startLine = 2, endLine = 3;

    // Open the CSV file
    std::ifstream file(gamesFileName);
    if (!file.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::vector<std::vector<std::string>> data; // Store the CSV data

    // Read only rows from 5 to 10
    int currentRow = 1;
    std::string line;
    while (std::getline(file, line))
    {
        // Check if the current row is within the desired range
        if (currentRow >= startLine && currentRow <= endLine)
        {
            std::vector<std::string> row; // Store data for current row
            std::string cell;             // Store data for current cell
            size_t pos = 0;               // Position to track current position within the line
            while ((pos = line.find(',')) != std::string::npos)
            {
                cell = line.substr(0, pos); // Extract cell data
                row.push_back(cell);        // Add cell data to current row
                line.erase(0, pos + 1);     // Remove processed part of the line
            }
            row.push_back(line); // Add the last cell of the line
            data.push_back(row); // Add current row to the data vector
        }

        // Increment the current row counter
        ++currentRow;

        // If we have reached the end of the desired range, break out of the loop
        if (currentRow > endLine)
            break;
    }

    const int movesIndex = 26;
    const int resultIndex = 32;

    // std::cout << data[1][movesIndex] << std::endl;
    // std::cout << data[1][resultIndex] << std::endl;

    for (auto row : data)
    {
        Game a(row[movesIndex]);
        a.print();

        std::cout << "\n\n\n-------------------------------------------------------------------------------\n\n\n";
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    double elapsedTime = duration.count();

    std::cout << "Elapsed time: " << elapsedTime << " seconds" << std::endl;

    return 0;
}
