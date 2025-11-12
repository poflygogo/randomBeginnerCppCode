#include <algorithm>
#include <iostream>
#include <vector>

class IndentationError : public std::runtime_error
{
  public:
    IndentationError(const std::string &msg) : std::runtime_error(msg) {};
};

std::vector<int> expectIndent;
bool shouldIndent = false;

bool IndentChecker(const std::string &text)
{
    int indent = std::find_if(text.begin(), text.end(), [](char c) { return std::isalpha(c); }) - text.begin();

    // 該縮進時不縮進
    if (shouldIndent && indent == (expectIndent.empty() ? 0 : expectIndent.back()))
    {
        throw IndentationError("expected an indented block");
    }

    // 不該縮進時縮進
    if (!shouldIndent && indent > (expectIndent.empty() ? 0 : expectIndent.back()))
    {
        throw IndentationError("unexpected indent");
    }

    if (!shouldIndent && indent < (expectIndent.empty() ? 0 : expectIndent.back()))
    {
        // 未與任何區塊對齊
        if (indent > 0 && std::find(expectIndent.begin(), expectIndent.end(), indent) == expectIndent.end())
        {
            throw IndentationError("unindent does not match any outer indentation level");
        }
        else if (indent == 0)
        {
            expectIndent.clear();
        }
        else
        {
            expectIndent.erase(std::find(expectIndent.begin(), expectIndent.end(), indent) + 1, expectIndent.end());
        }
    }

    if (shouldIndent)
    {
        expectIndent.push_back(indent);
    }

    return text.back() == ':';
}

int main()
{
    int cnt = 1;
    std::string s;
    while (std::getline(std::cin, s))
    {
        try
        {
            shouldIndent = IndentChecker(s);
            cnt++;
        }
        catch (const IndentationError &e)
        {
            std::cout << "line " << cnt << '\n' << s << '\n' << e.what();
            break;
        }
    }

    if (std::cin.fail())
    {
        std::cout << "Indention OK";
    }
}
