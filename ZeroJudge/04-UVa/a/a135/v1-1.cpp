#include <iostream>
#include <map>

int main() {
    const std::map<std::string, std::string> data = {
        {"HELLO", "ENGLISH"},  {"HOLA", "SPANISH"}, {"HALLO", "GERMAN"},
        {"BONJOUR", "FRENCH"}, {"CIAO", "ITALIAN"}, {"ZDRAVSTVUJTE", "RUSSIAN"}};
    int test_case = 1;
    std::string s;
    while (std::cin >> s && s != "#") {
        std::cout << "Case " << test_case++ << ": ";
        if (data.find(s) != data.end()) {
            std::cout << data.at(s) << '\n';
        } else {
            std::cout << "UNKNOWN" << '\n';
        }
    }
}
