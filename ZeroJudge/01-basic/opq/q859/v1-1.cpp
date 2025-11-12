#include <array>
#include <iostream>

int main() {
    std::array<std::string, 12> data = {
        "Aspect of Combat", "Ringmaster Scarr", "Night Rose",       "Aspect of Speed",
        "Shrouded Striker", "Unstoppable",      "Aspect of Siphon", "Infernal Defenses",
        "The Machinist",    "Shogun X",         "Megalo Don",       "Aspect of Agility",
    };

    int n;
    while (std::cin >> n) {
        std::cout << data[n % 12] << '\n';
    }
}
