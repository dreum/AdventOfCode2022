#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>

template<class T, int Size>
struct TopN
{
    void Insert(T& element)
    {
        Container[Size] = element;
        std::sort(begin(Container), end(Container), std::greater{});
    }

    friend 
    std::ostream& operator<<(std::ostream& os, TopN& topN)
    {
        auto begin = std::begin(topN.Container);
        auto end = std::end(topN.Container);
        --end;
        for(auto elem = begin; elem != end; ++elem)
            os << *elem << ' ';

        os << "Sum is " << std::accumulate(begin, end, 0);

        return os;
    }

    std::array<T, Size+1> Container{};
};



int main()
{
    std::vector<int> calories;
    std::string line;
    int tempCalories{0};
    TopN<int, 3> maxCalories;
    while(getline(std::cin, line))
    {
        if(line.empty())
        {
            // calories.push_back(tempCalories);
            maxCalories.Insert(tempCalories); 
            tempCalories = 0;
        }
        else
        {
            tempCalories += std::stoi(line);
        }
    }
    // calories.push_back(tempCalories);
    maxCalories.Insert(tempCalories); 
    // for(auto output : calories)
    //     std::cout << output << '\n';
    std::cout << "Day 1, part 1: Highest Calories: " << maxCalories.Container[0] << '\n';
    std::cout << "Day 1, part 2: Highest Calories: " << maxCalories << '\n';
    return 0;
}
