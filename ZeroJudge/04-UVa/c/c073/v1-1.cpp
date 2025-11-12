#include <algorithm>  // std::find, std::copy
#include <iostream>
#include <iterator>  // std::ostream_iterator
#include <numeric>   // std::iota
#include <vector>

class Blocks {
   private:
    int n;
    std::vector<std::vector<int>> blocks;
    std::vector<int> locate;

    void reset(std::vector<int>& arr, const int block_id) {
        while (arr.back() != block_id) {
            int k = arr.back();
            arr.pop_back();
            blocks[k].push_back(k);
            locate[k] = k;
        }
    }

   public:
    Blocks(int n) {
        this->n = n;
        blocks.resize(n);
        for (int i = 0; i < n; i++) {
            blocks[i].push_back(i);
        }
        locate.resize(n);
        std::iota(locate.begin(), locate.end(), 0);
    }

    void exceed(const std::string& comm, const int a, const std::string& mode, const int b) {
        // ignore illegal command
        if (a == b || locate[a] == locate[b]) {
            return;
        }

        if (comm == "move") {
            reset(blocks[locate[a]], a);
            if (mode == "onto") {
                reset(blocks[locate[b]], b);
            }
            std::vector<int>& arr1 = blocks[locate[a]];
            std::vector<int>& arr2 = blocks[locate[b]];
            arr2.push_back(arr1.back());
            arr1.pop_back();
            locate[a] = locate[b];

        } else if (comm == "pile") {
            if (mode == "onto") {
                reset(blocks[locate[b]], b);
            }
            std::vector<int>& arr1 = blocks[locate[a]];
            std::vector<int>& arr2 = blocks[locate[b]];
            auto it = std::find(arr1.begin(), arr1.end(), a);
            arr2.insert(arr2.end(), it, arr1.end());
            for (auto i = it; i < arr1.end(); i += 1) {
                locate[*i] = locate[b];
            }
            arr1.erase(it, arr1.end());
            locate[a] = locate[b];

        } else {  // debug message
            std::cout << "huh? what is \"" << comm << "\"?\n";
        }
    }

    void PrintResult() {
        for (int i = 0; i < blocks.size(); i++) {
            std::cout << i << ": ";
            // zerojudge 採寬鬆比對，所以可以這樣寫
            // 如果是嚴格比對，注意行尾不要輸出多於空格
            std::copy(blocks[i].begin(), blocks[i].end(),
                      std::ostream_iterator<int>(std::cout, " "));
            std::cout << '\n';
        }
    }
};

int main() {
    int n, a, b;
    std::string comm, mode;
    while (std::cin >> n) {
        Blocks s(n);
        while (std::cin >> comm && comm != "quit") {
            std::cin >> a >> mode >> b;
            s.exceed(comm, a, mode, b);
        }
        s.PrintResult();
    }
}
