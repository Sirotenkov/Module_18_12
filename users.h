#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class User final
{
    public:
        User();
        User(string const& name, string const& login, string const& pass);
        ~User();

        string const& getName() const;
        void setName(string const& name);

        string const& getLogin() const;
        void setLogin(string const& login);

        string const& getPass() const;
        void setPass(string const& pass);

    private:
        string _name;
        string _login;
        string _pass;
};

vector<User> read_users(string const& filename);
void write_users(string const& filename, vector<User> const& users);
void print_users(vector<User> const& users);
