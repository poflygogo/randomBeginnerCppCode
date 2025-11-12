#include <iomanip> // 為了使用 setprecision
#include <iostream>

using namespace std;

int main()
{
    int w;   // 體重，單位：公斤
    float h; // 身高，單位：公尺

    // 輸入體重和身高
    cin >> w >> h;

    // 計算 BMI
    float BMI = w / (h * h);

    // 設定輸出格式，固定小數點後 1 位
    cout << fixed << setprecision(1) << BMI << endl;

    return 0;
}
