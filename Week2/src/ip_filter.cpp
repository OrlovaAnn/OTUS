#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "lib.h"

int main()
{
    std::vector<std::vector<int>> ip_pool;

    for(std::string line; std::getline(std::cin, line);)
    { 
        auto res4 = splitToFourInts(split(line, '\t').at(0), '.');
        if (res4.empty())
            break;

        if ( res4.size() == 4 )
        {
            ip_pool.emplace_back(std::move(res4));
        }
    }    

    std::sort(ip_pool.begin(), ip_pool.end(), [&ip_pool](std::vector<int>& right, std::vector<int>& left){
        for (size_t i = 0; i < right.size(); i++)
        {
            if (right[i] != left[i])
                return right[i] > left[i];
        }
        return true;
    });

    auto print_ips = [](const std::vector<std::vector<int>>& ips)->void
    {
        for(auto c_iter = ips.cbegin(); c_iter != ips.cend(); ++c_iter)
        {
            for(auto ip_part = c_iter->begin(); ip_part != c_iter->end(); ++ip_part)
            {
                if (ip_part != c_iter->begin())
                {
                    std::cout << ".";
                }
                std::cout << *ip_part;
            }
            std::cout << std::endl;
        }
    };

    print_ips(ip_pool);

    print_ips(filter(ip_pool, 1));

    print_ips(filter(ip_pool, 46, 70));

    print_ips(filter_any(ip_pool, 46));

    return 0;
}
