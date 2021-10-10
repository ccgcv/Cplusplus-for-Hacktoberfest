#ifndef  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_INPUTOUTPUT_H
#define  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_INPUTOUTPUT_H

#include <vector>

namespace ccgcv::Hacktoberfest::Sort::Util
{

std::vector<int> getSortInput(int argc, char* argv[]);
void displayResult(std::vector<int> const& sortedData);

}

#endif

