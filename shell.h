#include <iostream>
#include <string>
#include <vector>

class shell
{
private:
    std::string version = "0.1";
    std::string current_command;
    std::vector<std::string> command_list = {"help", "ver"};

public:
    std::vector<std::string> parse_command(std::string command);
    void command_input();
    void command_render(std::string command);
    int find_command_index(std::string command);
    void kernel_version();
    void help();
};
int shell::find_command_index(std::string command)
{
    for (int i = 0; i < command_list.size(); i++)
    {
        if (command == command_list[i])
        {
            return i;
        }
    }
    return -1;
}
void shell::command_render(std::string command)
{
    auto vector = parse_command(command);
    int index = find_command_index(command);
    switch (index)
    {
    case 0:
        help();
        break;
    case 1:
        kernel_version();
        break;
    default:
        std::cout << "Unknown command" << std::endl;
        break;
    }
    command_input();
}
void shell::command_input()
{
    std::cout << ">>> ";
    std::cin >> current_command;
    if (find_command_index(current_command) != -1)
    {
        command_render(current_command);
    }
    else
    {
        std::cout << "Unknown command" << std::endl;
        command_render("help");
    }
}
void shell::help()
{
    for (int i = 0; i < command_list.size(); i++)
    {
        std::cout << command_list[i] << std::endl;
    }
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

    for (char ch : command)
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