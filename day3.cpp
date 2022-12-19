#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <range/v3/all.hpp>

int Convert(char c)
{
    if(c >= 'a' && c <= 'z')
        return c - 'a' + 1;

    return c - 'A' + 27;
}

int main()
{
    std::string line;
    char first, second;
    int sum{0};

    while(getline(std::cin, line))
    {
        std::vector<char> duplicates;
        auto cutoff = line.size() / 2;
        auto const chunks = line | ranges::views::chunk(cutoff);

        std::set<char> firstHalf{chunks[0].begin(), chunks[0].end()};
        std::set<char> secondHalf{chunks[1].begin(), chunks[1].end()};
        
        ranges::set_intersection(firstHalf, secondHalf, std::back_inserter(duplicates));
        if(!duplicates.empty())
        {
            sum += Convert(duplicates.front());
        }
    }

    std::cout 
        << "Day 3, part 1: Sum: " << sum << '\n';
    return 0;
}
