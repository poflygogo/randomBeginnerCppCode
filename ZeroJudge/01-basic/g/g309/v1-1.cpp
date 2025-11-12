#include <iostream>
#include <map>

struct Node {
    int lft, rgt, cake;
};

void dfs(std::map<int, Node> &tree, int root) {
    if (root == -1) {
        return;
    }
    int k = 1 + (tree.at(root).lft != -1) + (tree.at(root).rgt != -1);
    if (tree.at(root).lft != -1) {
        tree[tree[root].lft].cake = tree.at(root).cake / k;
    }
    if (tree.at(root).rgt != -1) {
        tree[tree[root].rgt].cake = tree.at(root).cake / k;
    }
    tree[root].cake = tree[root].cake / k + tree[root].cake % k;
    dfs(tree, tree[root].lft);
    dfs(tree, tree[root].rgt);
}

int main() {
    int n, k;
    int a, lft, rgt;
    std::map<int, Node> tree;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        std::cin >> a >> lft >> rgt;
        tree[a] = {lft, rgt, 0};
    }
    tree[0].cake = k;
    dfs(tree, 0);
    for (int i = 0; i < n; i++) {
        std::cout << tree[i].cake << ' ';
    }
}
