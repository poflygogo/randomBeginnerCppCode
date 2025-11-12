#include <iostream>
#include <vector>

int main()
{
    std::vector<int> status(7, 0);
    int run;
    std::cin >> status[0] >> status[1] >> status[2] >> run;
    status[3] = 1;

    int sum = 0;
    for (int i = 0; i < run; i++)
    {
        sum += status[i];
    }
    std::cout << sum << '\n';
    
    for (int i = run; i < run + 3; i++)
    {
        std::cout << status[i] << ' ';
    }
}
