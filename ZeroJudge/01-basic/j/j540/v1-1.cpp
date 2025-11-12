#include <iostream>
#include <map>

bool Wordle(const std::string &target, const std::string &guess, const std::map<char, int> &counter_target)
{
    if (target.size() > guess.size())
    {
        std::cout << "Not enough letters\n";
        return false;
    }
    else if (target.size() < guess.size())
    {
        std::cout << "Too long\n";
        return false;
    }
    else if (target == guess)
    {
        std::cout << std::string(target.size(), 'O') << '\n';
        return true;
    }

    std::map<char, int> counter(counter_target); // copy
    std::string res = std::string(target.size(), 'X');
    for (int i = 0; i < target.size(); i++)
    {
        if (target[i] == guess[i])
        {
            res[i] = 'O';
            counter[guess[i]]--;
        }
    }

    for (int i = 0; i < target.size(); i++)
    {
        if (res[i] == 'X' && counter.count(guess[i]) && counter.at(guess[i]) > 0)
        {
            res[i] = 'Y';
            counter[guess[i]]--;
        }
    }

    std::cout << res << '\n';
    return false;
}

int main()
{
    std::string target, guess;
    int n;
    std::cin >> target;
    std::cin >> n;

    std::map<char, int> counter;
    for (char c : target)
    {
        counter[c]++;
    }

    while (n--)
    {
        bool solved = false;
        int times = 0;
        while (std::cin >> guess && guess != "#")
        {
            times++;
            if (solved)
            {
                continue;
            }
            else if (Wordle(target, guess, counter))
            {
                solved = true;
                std::cout << "Congradulat1ons ! You guessed " << times << " times\n";
            }
        }
        std::cout << '\n';
    }
}
