#include <algorithm> // std::copy
#include <iostream>
#include <iterator> // std::ostream_iterator
#include <numeric>  // iota
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    std::iota(arr.begin(), arr.end(), 1);

    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
}
