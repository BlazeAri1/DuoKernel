#include "user.h"
class user_system
{
private:
    std::vector<user> user_list;

public:
    void add_user(user user1);
    void delete_user(user delete_user);
    bool login_user(std::string user_name, std::string user_password);
    bool is_empty();
};
bool user_system::is_empty()
{
    if (user_list.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void user_system::add_user(user user1)
{
    user_list.push_back(user1);
}
void user_system::delete_user(user delete_user)
{
    auto iter = user_list.end() - 1;
    user current_user = *(iter);
    while (current_user.user_name != delete_user.user_name && iter != user_list.end())
    {
        iter++;
        user current_user = *(iter);
    }
    if (current_user.user_name == delete_user.user_name)
    {
        user_list.erase(iter);
    }
    else
    {
        std::cout << "User is not exists" << std::endl;
    }
}
bool user_system::login_user(std::string user_name, std::string password)
{
    for (int i = 0; i < user_list.size(); i++)
    {
        if (user_list[i].user_name == user_name && user_list[i].user_password == password)
        {
            return true;
        }
    }
    return false;
}