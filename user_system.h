#include "user.h"
class user_system
{
private:
    std::vector<user> user_list;
    int find_user(std::string user_name, std::string password);

public:
    void add_user(user user1);
    void delete_user(user delete_user);
    bool login_user(std::string user_name, std::string user_password);
};
void user_system::add_user(user user1)
{
    user_list.push_back(user1);
}
void user_system::delete_user(user delete_user)
{
    auto iter = user_list.end() - 1;
    auto user1 = *(iter);
    *(iter) = delete_user;
    user_list.pop_back();
    *(iter) = user1;
}
int user_system::find_user(std::string user_name, std::string password)
{
    for (int i = 0; i < user_list.size(); i++)
    {
        if (user_list[i].user_name == user_name && user_list[i].user_password == password)
        {
            return i;
        }
    }
    return -1;
}
bool user_system::login_user(std::string user_name, std::string user_password)
{
    if (find_user(user_name, user_password) != -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
