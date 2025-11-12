#include <iostream>
#include <unordered_map>
using namespace std;

const unsigned int ID_SIZE = 10;
const unordered_map<char, unsigned int> AREA_CODE{
    {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}, {'G', 16},
    {'H', 17}, {'I', 34}, {'J', 18}, {'K', 19}, {'L', 20}, {'M', 21}, {'N', 22},
    {'O', 35}, {'P', 23}, {'Q', 24}, {'R', 25}, {'S', 26}, {'T', 27}, {'U', 28},
    {'V', 29}, {'W', 32}, {'X', 30}, {'Y', 31}, {'Z', 33}};

bool is_valid(const char id[]) {
  unsigned int arr[ID_SIZE];
  for (unsigned int i = 0; i < ID_SIZE; i++) {
    if (i == 0) {
      unsigned int tmp;
      tmp = AREA_CODE.at(id[i]);
      arr[i] = tmp / 10 + tmp % 10 * 9;
    } else {
      arr[i] = id[i] - '0';
    }
  }

  const unsigned int WEIGHT[10] = {1, 8, 7, 6, 5, 4, 3, 2, 1, 1};
  unsigned int sum = 0;
  for (unsigned int i = 0; i < ID_SIZE; i++)
  {
    sum += arr[i] * WEIGHT[i];
  }
  if (sum % 10 == 0)
    return true;
  else
    return false;
}

int main() {
  char id[ID_SIZE];
  cin >> id;
  if (is_valid(id))
    cout << "real";
  else
    cout << "fake";
}
