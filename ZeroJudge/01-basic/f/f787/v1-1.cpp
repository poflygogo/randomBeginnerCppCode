#include <iostream>
#include <sstream>
#include <vector>

struct Player
{
    int id;
    std::string name;
    int health;
    int damage;
    std::vector<std::string> items;
    int next_player_id;
};

int main()
{
    int total_player, target;
    std::string s;
    std::istringstream iss;
    std::cin >> total_player >> target;
    std::cin.ignore();
    std::vector<Player> players(total_player);
    for (int i = 0; i < total_player; i++)
    {
        players[i].id = i;
        std::getline(std::cin, s);
        iss.clear();
        iss.str(s);
        iss >> players[i].name >> players[i].health >> players[i].damage;
        while (iss >> s)
        {
            players[i].items.push_back(s);
        }
        players[i].next_player_id = std::stoi(players[i].items.back()) - 1;
        players[i].items.pop_back();
    }

    std::vector<bool> visited(total_player, false);
    target--;
    while (!visited[target])
    {
        visited[target] = true;
        Player *p = &players[target];
        p->health = std::max(0, p->health - p->damage);
        int cnt = p->damage;
        while (cnt-- && !p->items.empty())
        {
            p->items.pop_back();
        }

        std::cout << p->name << ' ';
        if (p->health > 0)
        {
            std::cout << p->health << ' ';
            for (const std::string &item : p->items)
            {
                std::cout << item << ' ';
            }
            std::cout << '\n';
        }
        else
        {
            std::cout << "dead.\n";
        }

        target = p->next_player_id;
    }
}
