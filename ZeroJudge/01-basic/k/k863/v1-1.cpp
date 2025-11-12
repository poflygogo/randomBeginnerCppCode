#include <iostream>
#include <map>

int main() {
    using namespace std;
    const map<string, int> date = {
        {"ShunZhi", 1644},  {"KangXi", 1662},   {"YongZheng", 1723}, {"QianLong", 1736}, {"JiaQing", 1796},
        {"DaoGuang", 1821}, {"XianFeng", 1851}, {"TongZhi", 1862},   {"GuangXu", 1875},  {"XuanTong", 1909}};
    string a;
    int b;
    cin >> a >> b;
    cout << date.at(a) + b - 1;
}
