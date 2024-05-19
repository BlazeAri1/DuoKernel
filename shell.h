#include <iostream>
#include <string>
#include <vector>
#include <map>

class shell {
private:
    std::string version = "0.1";
    std::string current_command;
    std::vector<std::string> command_list = {"help", "ver", "sideload"};
    std::map<std::string, std::string> sideload_command_list;

public:
    std::vector<std::string> parse_command(std::string command);

    void command_input();

    void command_render(const std::string &command);

    int find_command_index(const std::string &command);

    void kernel_version();

    void help();

    void sideload();
};

int shell::find_command_index(const std::string &command)
{
    for (int i = 0; i < command_list.size(); i++) {
        if (command == command_list[i]) {
            return i;
        }
    }
    return -1;
}

void shell::command_render(const std::string &command)
{
    auto vector = parse_command(command);
    int index = find_command_index(command);
    switch (index) {
        case 0:
            help();
            break;
        case 1:
            kernel_version();
            break;
        case 2:
            sideload();
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
    if (find_command_index(current_command) != -1) {
        command_render(current_command);
    } else {
        if (sideload_command_list.find(current_command) == sideload_command_list.end()) {
            std::cout << "Unknown command" << std::endl;
        } else {
            system(sideload_command_list[current_command].c_str());
        }
        command_input();
    }
}

void shell::help()
{
    std::cout << "List of commands\n";
    for (int i = 0; i < command_list.size(); i++) {
        std::cout << command_list[i] << std::endl;
    }
}

void shell::kernel_version()
{
    std::cout << "DuoKernel version: " << version << std::endl;
}

void shell::sideload()
{
    std::string run_command = "";
    std::string command_name;
    std::string folder;
    std::string filename;

    int selection;
    std::cout << "Enter type of app to sideload:\n"
                 "1. Python script\n"
                 "2. Lua script\n"
                 "3. Node.js script\n"
                 "4. Node.js package (via npm)\n"
                 "5. Deno script (supports TypeScript)\n"
                 "> ";
    std::cin >> selection;
    if (selection > 5) {
        std::cout << "This type of app does not exists." << std::endl;
        return;
    }
    std::cout << "Enter command name:\n"
                 "> ";
    std::cin >> command_name;
    if (command_name.empty()) {
        std::cout << "Can't create a command with empty name." << std::endl;
        return;
    }
    if (selection == 4) {
        std::cout << "Enter name of folder with package:\n"
                     "> ";
        std::cin >> folder;
        run_command = "cd " + folder + " && npm run start:prod";
    } else {
        std::cout << "Enter name of script (without filename extension):\n"
                     "> ";
        std::cin >> filename;
        switch (selection) {
            case 1:
                run_command = "python " + filename + ".py";
                break;
            case 2:
                run_command = "lua " + filename + ".lua";
                break;
            case 3:
                run_command = "node " + filename + ".js";
                break;
            case 5:
                run_command = "deno run " + filename;
                char is_ts;
                std::cout << "Is this a TypeScript script? (y/n)\n"
                             "> ";
                std::cin >> is_ts;
                if (is_ts == 'y') {
                    filename += ".ts";
                } else {
                    filename += ".js";
                }
        }
    }

    sideload_command_list[command_name] = run_command;
}

std::vector<std::string> shell::parse_command(std::string command)
{
    std::vector<std::string> result;
    std::string part = "";
    command = command + " "; // если последний символ - не пробел, последнего push_back не произойдет.

    for (char ch: command) {
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
