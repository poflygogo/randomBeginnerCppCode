#include <iostream>
#include <sstream> // 要導入這個才能用 stringstream
#include <string>
using namespace std;

// 把邏輯分離出來寫，不然嵌套好多......
string Rabbit(stringstream &stream,
              const int &red,
              const int &white,
              const int &yellow,
              const int &black, 
              const int &poison_power,
              int &health) {
    int poison_level = 0;
    int food;
    while (stream >> food) {
        health -= poison_level * poison_power;
        if (health <= 0)
            break;
        switch (food) {
        case 1:
            health += red;
            break;
        case 2:
            health += white;
            break;
        case 3:
            health -= yellow;
            break;
        case 4:
            health -= black;
            poison_level++;
            break;
        default:
            break;
        }
        if (health <= 0)
            break;
    }
    return health <= 0 ? "bye~Rabbit" : to_string(health) + 'g';
}

int main() {
    stringstream stream;
    int t;
    cin >> t;
    while (t--) {
        string line;
        int x, y, z, w, n, m;
        cin >> x >> y >> z >> w >> n >> m;
        cin.ignore(); // 現在標準數據流(stdin)裡面長相是
                      // "\n...(一堆神秘字串)..." 此時如果直接使用 getline()
                      // 去讀，getline 發現 \n 就會立刻停止讀取
                      // 導致讀到一個空字串
                      // 所以需要使用 cin.ignore() 忽略 \n
                      // 這是混用 cin 和 getline 時，務必要注意的事項

        getline(cin, line);
        stream.clear();   // 使用前務必要重設狀態
        stream.str(line); // 這會讓指定的字串取代數據流的內容
                          // 如果要使用如下語法
                          //      stream << line;
                          // 應該先清理數據流的內容後才放進去，像這樣
                          //      stream.str("");
                          //      stream << line;
                          // 傳入一個空字串，就相當於清空裡面的殘留資料

        cout << Rabbit(stream, x, y, z, w, n, m) << endl;
    }
}
