#include <iostream>
#include <string>
class shell
{
private:
    std::string version = "0.1";

public:
    void shell::kernel_version();
    void shell::help();
};
void shell::help()
{
    std::cout << "Commands:\nhelp\nver" << std::endl;
}
void shell::kernel_version()
{
    std::cout << "DuoKernel version: " << version << std::endl;
}