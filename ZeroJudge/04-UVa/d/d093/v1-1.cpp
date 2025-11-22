#include <iostream>  // std::cin, std::cout
#include <memory>    // std::unique_ptr
#include <string>
#include <vector>  // std::vector

struct Figure {
    char type;
    virtual ~Figure() = default;
    virtual bool is_contained(double x, double y) = 0;
};

struct Circle : Figure {
    double x, y, r;
    bool is_contained(double px, double py) override { return (px - x) * (px - x) + (py - y) * (py - y) < r * r; }
};

struct Rectangle : Figure {
    double x1, y1, x2, y2;
    bool is_contained(double px, double py) override { return px > x1 && px < x2 && py < y1 && py > y2; }
};

int main() {
    std::vector<std::unique_ptr<Figure>> figures;
    char type;
    while (std::cin >> type && type != '*') {
        if (type == 'c') {
            auto c = std::make_unique<Circle>();
            c->type = type;
            std::cin >> c->x >> c->y >> c->r;
            figures.push_back(std::move(c));
        } else if (type == 'r') {
            auto r = std::make_unique<Rectangle>();
            r->type = type;
            std::cin >> r->x1 >> r->y1 >> r->x2 >> r->y2;
            if (r->x1 > r->x2) {
                std::swap(r->x1, r->x2);
            }
            if (r->y1 > r->y2) {
                std::swap(r->y1, r->y2);
            }
            figures.push_back(std::move(r));
        }
    }

    int test_case = 1;
    double px, py;
    while (std::cin >> px >> py && px != 9999.9 && py != 9999.9) {
        std::string point = "Point " + std::to_string(test_case++) + " is ";
        bool is_contained = false;

        for (size_t i = 0; i < figures.size(); ++i) {
            if (figures[i]->is_contained(px, py)) {
                std::cout << point << "contained in figure " << i + 1 << '\n';
                is_contained = true;
            }
        }
        if (!is_contained) {
            std::cout << point << "not contained in any figure\n";
        }
    }
}

// 也許......有些過度設計了
