#include "dataGenerator.h"

int main()
{
    dataGenerator a(DATA_FILE::defaultInputFileName, DATA_FILE::defaultOutputFileName, DATA_FILE::defaultCacheFileName, DATA_FILE::latestRow);

    a.setStartingRowNum(69);

    std::cout << a.getStartingRowNum() << std::endl;

    return 0;
}