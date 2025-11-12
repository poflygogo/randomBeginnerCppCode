#include <stdio.h>  // 匯入標準輸入輸出模組

int main() {
    char text[100]; // 宣告一個字元陣列作為字符串變數。
                    // 這邊設置為 100，意思是我要開一個可以容納 100 個字元的字符串
    scanf("%s", text);
    printf("hello, %s\n", text);
}
