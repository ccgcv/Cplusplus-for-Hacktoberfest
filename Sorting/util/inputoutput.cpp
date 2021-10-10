
#include "inputoutput.h"
#include <iostream>

std::vector<int> ccgcv::Hacktoberfest::Sort::Util::getSortInput(int argc, char* argv[])
{
    std::vector<int>    data;

    std::cout << "Enter Size Of the Array:\n";
    int n;
    std::cin >> n;

    std::cout << "Enter elements:\n";
    for(int i = 0; i<n; ++i) {
        int val;
        if (std::cin >> val) {
            data.emplace_back(val);
        }
    }
    return data;
}

