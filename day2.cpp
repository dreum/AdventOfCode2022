#include <string>
#include <iostream>
#include <sstream>

enum class RPS
{
    Rock = 'A',
    Paper = 'B',
    Scissors = 'C'
};

bool operator>(RPS rps1, RPS rps2)
{
    return
        (rps1 != rps2) && (
        (rps1 == RPS::Paper && rps2 == RPS::Rock) ||
        (rps1 == RPS::Scissors && rps2 == RPS::Paper) ||
        (rps1 == RPS::Rock && rps2 == RPS::Scissors) 
        );
}

enum class Choice
{
    Rock = 'X',
    Paper = 'Y',
    Scissors = 'Z'
};


int ScoreChoice(Choice choice)
{
    return static_cast<int>(choice) - 'X' + 1;
}

RPS Convert(Choice choice)
{
    int raw = ScoreChoice(choice) - 1 + 'A';

    return static_cast<RPS>(raw);
}

int ScoreRound(RPS rps, Choice choice)
{
    auto choiceAsRPS = Convert(choice);
    int result =
        (rps == choiceAsRPS) ? 3 :
        (rps > choiceAsRPS)  ? 0 :
        6;

    return result + ScoreChoice(choice);
}

std::string Print(RPS rps)
{
    switch (rps)
    {
    case RPS::Rock:
        return "Rock";
    case RPS::Paper:
        return "Paper";
    //case RPS::Scissors:
    
    }
    return "Scissors";
}

int main()
{
    std::string line;
    char first, second;
    int score{0};

    while(getline(std::cin, line))
    {
        std::stringstream ss(line);
        ss >> first >> second;
        // std::cout << Print(RPS(first)) << '\n';
        score += ScoreRound(static_cast<RPS>(first), static_cast<Choice>(second));
    }

    std::cout << "Day 2, part 2: Rock, paper, scissors score: " << score << '\n';
    return 0;
}
