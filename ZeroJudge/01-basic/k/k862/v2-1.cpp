#include <iostream>
#include <map>

struct Node {
    std::string name;
    Node* parent;

    Node(std::string s) : name(s), parent(nullptr) {}
};

int stepToRoot(const Node& target) {
    int cnt = 0;
    Node* curr = target.parent;
    while (curr != nullptr) {
        cnt++;
        curr = curr->parent;
    }
    return cnt;
}

int main() {
    int n;
    std::string a, b;
    std::map<std::string, Node*> tree;
    std::cin >> n;
    while (n--) {
        std::cin >> a >> b;
        if (tree[a] == nullptr) {
            Node* tmp = new Node(a);
            tree[a] = tmp;
        }
        if (tree[b] == nullptr) {
            Node* tmp = new Node(b);
            tree[b] = tmp;
        }
        tree[a]->parent = tree[b];
    }
    std::cin >> a >> b;
    std::cout << stepToRoot(*tree.at(b)) - stepToRoot(*tree.at(a));
}
