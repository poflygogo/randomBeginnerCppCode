#include <array>
#include <iostream>

int cnt = 1;
std::array<int, 8> path;

bool IsValid(int idx)
{
    int target = path[idx];
    for (int i = 0; i <= idx - 1; i++)
    {
        int diff = idx - i;
        if (path[i] == target - diff || path[i] == target || path[i] == target + diff)
        {
            return false;
        }
    }
    return true;
}

void EightQueen(int idx = 0)
{
    if (idx == 8)
    {
        std::cout << cnt++ << ": ";
        for (auto &&i : path)
        {
            std::cout << i;
        }
        std::cout << '\n';
        return;
    }

    for (int i = 1; i <= 8; i++)
    {
        path[idx] = i;
        if (IsValid(idx))
        {
            EightQueen(idx + 1);
        }
    }
}

int main()
{
    EightQueen();
}
