#include "lib.h"

#include <algorithm>

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

std::vector<int> splitToFourInts(const std::string &str, char d)
{
    std::vector<int> r;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    try
    {
        while(stop != std::string::npos)
        {
            r.push_back(std::stoi(str.substr(start, stop - start)));
            start = stop + 1;
            stop = str.find_first_of(d, start);
        }

        r.push_back(std::stoi(str.substr(start)));
    }
    catch(std::exception&)
    {
        return {};
    }

    if (r.size() < 4)
        return{};

    return r;
}

std::vector<std::vector<int>> filter(const std::vector<std::vector<int>>& ips, int pos1, int pos2)
{
    std::vector<std::vector<int>> res;

    std::copy_if(ips.begin(), ips.end(), std::back_inserter(res), [&pos1, &pos2](const std::vector<int>& el){
        if (pos2 < 0)
            return el[0] == pos1;
        else
            return el[0] == pos1 && el[1] == pos2;
    });
    return res;
}

std::vector<std::vector<int>> filter_any(const std::vector<std::vector<int>>& ips, int val)
{
    std::vector<std::vector<int>> res;

    std::copy_if(ips.begin(), ips.end(), std::back_inserter(res), [&val](const std::vector<int>& ip){
        for (int byte : ip)
        {
            if (byte == val)
                return true;
        }
        return false;
    });
    return res;
}