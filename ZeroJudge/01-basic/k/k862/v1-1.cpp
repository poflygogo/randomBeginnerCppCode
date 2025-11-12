#include <iostream>
#include <map>

int stepToRoot(std::map<std::string, std::string>& tree, std::string target) {
    int cnt = 0;
    while (tree.count(target)) {
        cnt++;
        target = tree.at(target);
    }
    return cnt;
}

int main() {
    int n;
    std::string a, b;
    std::map<std::string, std::string> tree;
    std::cin >> n;
    while (n--) {
        std::cin >> a >> b;
        tree[a] = b;
    }
    std::cin >> a >> b;
    std::cout << stepToRoot(tree, b) - stepToRoot(tree, a);
}
