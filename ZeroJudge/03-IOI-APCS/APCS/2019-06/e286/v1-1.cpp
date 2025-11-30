// Zerojudge e286
// APCS 2019-06 1 籃球比賽
// C++14

#include <iostream>
#include <sstream>  // istringstream
#include <string>

int readAndSum() {
    std::string s;
    std::getline(std::cin, s);
    std::istringstream iss(s);
    int sum = 0;
    int n;
    while (iss >> n) {
        sum += n;
    }
    return sum;
}

int main() {
    int game1_a = readAndSum();
    int game1_b = readAndSum();
    int game2_a = readAndSum();
    int game2_b = readAndSum();

    bool team_a_win1 = game1_a > game1_b;
    bool team_a_win2 = game2_a > game2_b;

    std::cout << game1_a << ':' << game1_b << '\n';
    std::cout << game2_a << ':' << game2_b << '\n';

    switch (team_a_win1 + team_a_win2) {
    case 0:
        std::cout << "Lose";
        break;
    case 1:
        std::cout << "Tie";
        break;
    case 2:
        std::cout << "Win";
        break;
    }
}
