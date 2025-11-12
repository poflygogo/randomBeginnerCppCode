#include <iostream>
#include <vector>

int main() {
    int stage, health;
    std::cin >> stage >> health;
    std::vector<int> die(stage), reward(stage);
    for (int i = 0; i < stage; i++) {
        std::cin >> die[i];
    }
    for (int i = 0; i < stage; i++) {
        std::cin >> reward[i];
    }
    int i = 0;
    for (i = 0; i < stage; i++) {
        health -= die[i];
        if (health < 0) {
            break;
        }
        health += reward[i];
    }
    std::cout << i + 1;
}
