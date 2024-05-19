#include <iostream>
#include <string>
#include <vector>

class shell
{
private:
    std::string version = "0.1";

public:
    std::vector<std::string> parse_command(std::string command);
    void kernel_version();
    void help();
};
void shell::help()
{
    std::cout << "Commands:\nhelp\nver" << std::endl;
}
void shell::kernel_version()
{
    std::cout << "DuoKernel version: " << version << std::endl;
}
std::vector<std::string> shell::parse_command(std::string command)
{
    std::vector<std::string> result;
    std::string part = "";
    command = command + " "; // если последний символ - не пробел, последнего push_back не произойдет.

    for (char ch: command)
    {
        if (ch == ' ') // пропуск всех пробелов
        {
            result.push_back(part);
            part = "";
            continue;
        }
        part += ch;
    }
    return result;
}
