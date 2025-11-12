#include <iostream>
using namespace std;

const int ID_NUMBER_SIZE = 9;
const pair<char, int> AREA_CODE[26] = {
    {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}, {'G', 16},
    {'H', 17}, {'I', 34}, {'J', 18}, {'K', 19}, {'L', 20}, {'M', 21}, {'N', 22},
    {'O', 35}, {'P', 23}, {'Q', 24}, {'R', 25}, {'S', 26}, {'T', 27}, {'U', 28},
    {'V', 29}, {'W', 32}, {'X', 30}, {'Y', 31}, {'Z', 33}};
const int WEIGHT[9] = {8, 7, 6, 5, 4, 3, 2, 1, 1};

int main() {
    char id_number[ID_NUMBER_SIZE];
    int sum = 0;
    cin >> id_number;
    for (int i = 0; i < ID_NUMBER_SIZE; i++) {
        sum += (id_number[i] - '0') * WEIGHT[i];
    }
    int mod = (10 - sum % 10) % 10;
    for (pair<char, int> item : AREA_CODE) {
        if ((item.second / 10 + item.second % 10 * 9) % 10 == mod) {
            cout << item.first;
        }
    }
    cout << endl;
}