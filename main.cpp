#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "users.h"
#include "messages.h"
#include <filesystem>

using namespace std;

int main()
{

    string users_filename, messages_filename;

#if defined(__linux__)
    users_filename = "/tmp/users.txt";
    messages_filename = "/tmp/messages.txt";
#elif defined(__WIN32__)
    users_filename = "./users.txt";
    messages_filename = "./messages.txt";
#endif
    
    vector<User> users{{"Alex", "alex", "1111"}, {"Viktor", "viktor", "2222"}, {"Sergey", "sergey", "3333"}};
    write_users(users_filename, users);
    vector<User> const users_read = read_users(users_filename);
    print_users(users_read);

    auto permissions = std::filesystem::perms::group_all |
        std::filesystem::perms::others_all;
    std::filesystem::permissions(users_filename, permissions, std::filesystem::perm_options::remove);

    vector<Message> messages{{"Hi!", "alex", "viktor"}, {"Hello!", "viktor", "alex"}, {"Privet!", "sergey", "alex"}};
    write_messages(messages_filename, messages);
    vector<Message> const messages_read = read_messages(messages_filename);
    print_messages(messages_read);

    permissions = std::filesystem::perms::group_all |
        std::filesystem::perms::others_all;
    std::filesystem::permissions(messages_filename, permissions, std::filesystem::perm_options::remove);

    return 0;
}
