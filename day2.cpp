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

enum class Result
{
    Lose = 'X',
    Draw = 'Y',
    Win = 'Z'
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

Choice Convert(RPS rps)
{
    int raw = static_cast<int>(rps) - 'A' + 'X';

    return static_cast<Choice>(raw);
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

Choice GetChoiceForResult(RPS rps, Result requiredResult)
{
    return
        (requiredResult == Result::Draw) ? Convert(rps) :
        (requiredResult == Result::Lose) ?
            (rps == RPS::Paper) ? Choice::Rock :
            (rps == RPS::Scissors) ? Choice::Paper :
            /* (rps == RPS::Rock) ?*/ Choice::Scissors :
            (rps == RPS::Paper) ? Choice::Scissors :
            (rps == RPS::Scissors) ? Choice::Rock :
            /* (rps == RPS::Rock) ?*/ Choice::Paper;
            
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
    int score1{0}, score2{0};

    while(getline(std::cin, line))
    {
        std::stringstream ss(line);
        ss >> first >> second;
        // std::cout << Print(RPS(first)) << '\n';
        auto rps = static_cast<RPS>(first);
        score1 += ScoreRound(rps, static_cast<Choice>(second));

        auto requiredChoice = GetChoiceForResult(rps, static_cast<Result>(second));
        score2 += ScoreRound(rps, requiredChoice);
    }

    std::cout 
        << "Day 2, part 1: Rock, paper, scissors score: " << score1 << '\n'
        << "Day 2, part 2: Rock, paper, scissors score: " << score2 << '\n';
    return 0;
}
