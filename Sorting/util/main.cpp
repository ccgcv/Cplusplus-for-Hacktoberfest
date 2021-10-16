#include "inputoutput.h"
#include <string>
#include <map>
#include <functional>

#include "sortfunctions.allheaders.h"


#undef INCLUDE
#undef QUOTE
#undef HEADER
#undef REGISTER_SORT_FUNCTION
#define REGISTER_SORT_FUNCTION(sortName)           { #sortName, [](std::vector<int>& data){ ccgcv::Hacktoberfest::Sort::sortName(&data[0], &data[data.size()]);}},
std::map<std::string, std::function<void(std::vector<int>&)>>   sortFunctions = {
    #include "sortfunctions.register"
    {"default", [](std::vector<int>& data){ ccgcv::Hacktoberfest::Sort::QuickSort(&data[0], &data[data.size()]);}}
};

std::string getSortFunction(int argc, char* argv[])
{
    std::string sortFunction = "default";
    if ((argc > 2) && (std::strncmp(argv[2], "--sort=", 7) == 0)) {
        sortFunction = argv[2] + 7;
    }
    return sortFunction;
}

int main(int argc, char* argv[])
{
    using ccgcv::Hacktoberfest::Sort::Util::getSortInput;
    using ccgcv::Hacktoberfest::Sort::Util::displayResult;

    std::string      sortName   = getSortFunction(argc, argv);
    std::vector<int> data       = getSortInput(argc, argv);
    sortFunctions[sortName](data);
    displayResult(data);

    return 0;
}

