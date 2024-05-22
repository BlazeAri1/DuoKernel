#include <string>
#include <vector>
class user
{
private:
    std::vector<std::string> user_permissions;
    std::vector<std::string>::iterator find_iter(std::string string,std::vector<std::string> vector);

public:
    std::string user_name;
    std::string user_password;
    void add_permission(std::string permission);
    void erase_permission(std::string permission);
    void set_name(std::string name);
    void set_password(std::string password);
};
std::vector<std::string>::iterator user::find_iter(std::string string,std::vector<std::string> vector)
{
    auto iter = vector.begin();
    while (*(iter) != string)
    {
        iter += 1;
    }
    return iter;
}
void user::add_permission(std::string permission)
{
    user_permissions.push_back(permission);
}
void user::erase_permission(std::string permission)
{
    user_permissions.erase(find_iter(permission,user_permissions));
}
void user::set_name(std::string name)
{
    user_name = name;
}
void user::set_password(std::string password)
{
    user_password = password;
}
