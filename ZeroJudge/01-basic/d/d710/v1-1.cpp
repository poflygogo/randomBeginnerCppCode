#include <iostream>
#include <vector>

// -----------------------------------------------------
// 宣告物件

struct Car
{
    std::string brand, color;
    friend std::ostream &operator<<(std::ostream &os, const Car &item);
};

class ParkinLot
{
  private:
    int size;
    std::vector<Car> data;

  public:
    ParkinLot();
    ParkinLot(int n);
    void push(Car info);
    void query(std::string &type, std::string &target);
};

// -----------------------------------------------------
// 實作方法的細節

// 重載 << 運算子，簡化輸出
std::ostream &operator<<(std::ostream &os, const Car &item)
{
    os << item.brand << ' ' << item.color << '\n';
    return os;
}

// 構造方法，無參數版
ParkinLot::ParkinLot()
{
    size = 0; // 沒用到，隨便塞一個數字，也可以不寫
}

// 構造方法，有參數版
ParkinLot::ParkinLot(int n)
{
    size = n;
    data.reserve(n);
}

void ParkinLot::push(Car info)
{
    data.push_back(info);
}

void ParkinLot::query(std::string &type, std::string &target)
{
    if (type == "brand")
    {
        for (const Car &item : data)
        {
            if (item.brand == target)
            {
                std::cout << item;
            }
        }
    }
    else
    {
        for (const Car &item : data)
        {
            if (item.color == target)
            {
                std::cout << item;
            }
        }
    }
}

// -----------------------------------------------------
// 入口函式

int main()
{
    int n, m;
    std::string brand, color, type, target;
    while (std::cin >> n >> m)
    {
        ParkinLot obj(n);
        while (n--)
        {
            std::cin >> brand >> color;
            obj.push(Car({brand, color}));
        }
        while (m--)
        {
            std::cin >> type >> target;
            obj.query(type, target);
        }
        std::cout << '\n';
    }
}
