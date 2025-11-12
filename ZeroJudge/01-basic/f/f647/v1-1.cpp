#include <array>
#include <deque>
#include <iostream>

int main()
{
    constexpr int kTotalCard = 52;
    const std::string kSuit = "SHDF";
    const std::array<std::string, 13> kRank = {"A", "2", "3",  "4", "5", "6", "7",
                                               "8", "9", "10", "J", "Q", "K"};

    // --------------------------------
    // 不是很重要的 IO 優化，可有可無的那種...
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // --------------------------------

    std::deque<int> deck;
    for (int i = 0; i < kTotalCard; i++)
    {
        deck.push_back(i);
    }

    int n, comm, a, b, k;
    std::cin >> n;
    while (n--)
    {
        std::cin >> comm;
        switch (comm)
        {
        case 1:
            std::cin >> a >> b;
            for (int i = a; i <= b; i++)
            {
                deck.push_front(deck[b - 1]);
                deck.erase(deck.begin() + b);
            }
            break;
        case 2:
            std::cin >> a >> b;
            a--;
            b--;
            for (int i = a; i <= b; i++)
            {
                deck.push_back(deck[a]);
                deck.erase(deck.begin() + a);
            }
            break;
        case 3:
            std::cin >> k;
            while (k--)
            {
                deck.push_front(deck.back());
                deck.pop_back();
            }
            break;
        case 4:
            std::cin >> k;
            while (k--)
            {
                deck.push_back(deck.front());
                deck.pop_front();
            }
            break;
        default:
            std::cout << "[Error] wtf is command=" << comm << "?\n";
            return 0;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << kSuit[deck[i] / 13] << kRank[deck[i] % 13] << ' ';
    }
}
