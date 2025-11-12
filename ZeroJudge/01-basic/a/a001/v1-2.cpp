#include <iostream>     // 匯入輸入輸出模組

int main(){
    std::string s;           // 宣告一個字串變數
    std::cin >> s;
    std::cout << "hello, " << s << std::endl;
    return 0;
}

// 這是不使用 using namespace std 命名空間的作法
// 當有很多模組要匯入時這作法會很重要，可以用來避免命名空間汙染
// 實際專案中更鼓勵這種作法
