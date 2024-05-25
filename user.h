#include <string>
#include <vector>
std::vector<std::string> user_names;
class user
{
private:
    std::vector<std::string> user_permissions;
    std::vector<std::string>::iterator find_iter(std::string string, std::vector<std::string> vector);
    bool check_name(std::string name);

public:
    std::string user_name;
    std::string user_password;
    void add_permission(std::string permission);
    void erase_permission(std::string permission);
    bool set_name(std::string name);
    void set_password(std::string password);
};
std::vector<std::string>::iterator user::find_iter(std::string string, std::vector<std::string> vector)
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
    user_permissions.erase(find_iter(permission, user_permissions));
}
bool user::check_name(std::string name)
{
    if (user_names.size() != 0)
    {
        for (int i = 0; i < user_names.size(); i++)
        {
            if (user_names[i] == name)
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return true;
    }
}
bool user::set_name(std::string name)
{
    user system_user;
    if (system_user.check_name(name))
    {
        user_name = name;
        user_names.push_back(name);
        return true;
    }
    else
    {
        return false;
    }
}
void user::set_password(std::string password)
{
    user_password = password;
}
