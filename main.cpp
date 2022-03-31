#include <iostream>
#include <random>
#include <limits>

namespace Random
{
    std::random_device rd;
    std::seed_seq seq{ rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd() };
    std::mt19937 mt{ seq };

    int getRandomInt(int min, int max)
    {
        std::uniform_int_distribution dist{ min, max };
        return dist(mt);
    }

} // namespace Random

int getIntFromUser()
{
    while (true)
    {
        int num{};
        std::cin >> num;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return num;
    }
}

bool playGame(int guesses, int number)
{
    std::cout << "Lets play the game!, guess the number generated| ;) \n";
    for (int guessCounter{ 1 }; guessCounter <= guesses; ++guessCounter)
    {
        std::cout << "Guess number #" << guessCounter << ':' << ' ';
        int guess{ getIntFromUser() };

        if (guess > number) std::cout << "Too high!\n";
        else if (guess < number) std::cout << "Too low!\n";
        else return true;
    }

    return false;
}

bool playAgain()
{
    while (true)
    {
        char ch{};
        std::cout << "Would you like play again? (y/n): ";
        std::cin >> ch;

        switch (ch)
        {
        case 'y': return true;
        case 'n': return false;
        }
    }
}



int main()
{
    int number{ Random::getRandomInt(1, 100) };
    constexpr int maxGuesses{ 7 };

    do {
        bool won{ playGame(maxGuesses, number) };

        std::cout << "\n=========\n";

        if (won) std::cout << "You Won!!.\n";
        else std::cout << "You Lost!!.\n";

        std::cout << "The number was: " << number << '\n';
        std::cout << "=========\n";

    } while (playAgain());

    return 0;
}
