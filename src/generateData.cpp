#include "dataGenerator.h"

void dataGenerator::generateData(int startingrownum, int numOfRows)
{
    int endingrownum = startingrownum + numOfRows - 1;

    // Open the CSV file
    std::ifstream inputfile(inputFileName);
    if (!inputfile.is_open())
    {
        std::cerr << "Error opening input file : " << inputFileName << std::endl;
    }

    int currentRow = 1;
    std::string line;
    // Open the CSV file in append mode
    std::ofstream file(outputFileName, std::ios::app);

    if (!file.is_open())
    {
        std::cerr << "Error opening file for appending : " << outputFileName << std::endl;
        return;
    }
    while (std::getline(inputfile, line))
    {
        // Check if the current row is within the desired range
        if (currentRow >= startingrownum && currentRow <= endingrownum)
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

            /********** code to store the training data *********/
            {
                std::cout << currentRow << std::endl;
                Game game(row[DATA_FILE::movesIndex]);

                for (auto positions : game.game)
                {
                    file << positions.toCSV() << '\n';
                }
            }
        }

        // Increment the current row counter
        ++currentRow;

        // If we have reached the end of the desired range, break out of the loop
        if (currentRow > endingrownum)
            break;
    }

    // Close the file
    file.close();
    std::cout << "Data appended successfully!" << std::endl;

    startingRowNum = currentRow;
    setStartingRowNum(startingRowNum);
}
