#include <array>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

class BrainFuck {
   private:
    static constexpr int buff_size = 30000;
    std::array<unsigned char, buff_size> buffer;
    int ptr;

    std::map<int, int> bracket_pair(const std::string& code) {
        std::map<int, int> res;
        std::stack<int> st;
        for (int i = 0; i < code.size(); i++) {
            if (code[i] == '[') {
                st.push(static_cast<int>(i));
            } else if (code[i] == ']') {
                int open_pos = st.top();
                st.pop();
                res[open_pos] = static_cast<int>(i);
                res[static_cast<int>(i)] = open_pos;
            }
        }
        return res;
    }

   public:
    BrainFuck() : buffer{}, ptr(0) { buffer.fill(0); }

    void run_code(const std::string& code) {
        std::map<int, int> bracket_map = bracket_pair(code);
        ptr = 0;

        for (int i = 0; i < code.size();) {
            switch (code[i]) {
                case '+':
                    buffer[ptr]++;
                    break;
                case '-':
                    buffer[ptr]--;
                    break;
                case '<':
                    ptr--;
                    if (ptr < 0) {
                        std::cerr << "Error: Pointer went below 0" << std::endl;
                        return;
                    }
                    break;
                case '>':
                    ptr++;
                    if (ptr >= buff_size) {
                        std::cerr << "Error: Pointer exceeded buffer size" << std::endl;
                        return;
                    }
                    break;
                case '.':
                    std::cout << buffer[ptr];
                    break;
                case ',':
                    buffer[ptr] = std::cin.get();
                    break;
                case '[':
                    if (buffer[ptr] == 0) {
                        i = bracket_map[static_cast<int>(i)];
                    }
                    break;
                case ']':
                    if (buffer[ptr] != 0) {
                        i = bracket_map[static_cast<int>(i)];
                    }
                    break;
                default:
                    break;
            }
            i++;
        }
    }
};

std::string GenSimpleBrainFuckCode(const std::string& s) {
    std::string res;
    char curr_val = 0;
    for (auto&& c : s) {
        if (curr_val > c) {
            res += std::string(curr_val - c, '-');
        } else if (curr_val < c) {
            res += std::string(c - curr_val, '+');
        }
        res += '.';
        curr_val = c;
    }
    return res;
}

int main() {
    std::string hello_world = "hello, world";
    std::string brain_fuck_code = GenSimpleBrainFuckCode(hello_world);
    BrainFuck bot;
    bot.run_code(brain_fuck_code);
}
