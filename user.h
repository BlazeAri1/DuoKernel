#include <string>
#include <vector>
#include "permission.h"
std::vector<std::string> user_names;
class user
{
private:
    std::vector<permission> user_permissions;
    std::vector<permission>::iterator find_iter(permission perm, std::vector<permission> vector);
    bool check_name(std::string name);
    bool is_root(user user1);

public:
    std::string user_name;
    std::string user_password;
    void add_permission(permission permission);
    void erase_permission(permission permission);
    bool set_name(std::string name);
    void set_password(std::string password);
};
bool user::is_root(user user1)
{
    for (int i = 0; i < user_permissions.size(); i++)
    {
        if (user_permissions[i] == root)
        {
            return true;
        }
    }
    return false;
}
std::vector<permission>::iterator user::find_iter(permission perm, std::vector<permission> vector)
{
    auto iter = vector.begin();
    while (*(iter) != perm)
    {
        iter += 1;
    }
    return iter;
}
void user::add_permission(permission permission)
{
    user_permissions.push_back(permission);
}
void user::erase_permission(permission permission)
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
