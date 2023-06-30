#include "users.h"

User::User()
{

}

User::~User()
{

}

User::User(string const& name, string const& login, string const& pass)
{
    setName(name);
    setLogin(login);
    setPass(pass);
}

string const& User::getName() const
{
    return _name;
}

void User::setName(string const& name)
{
    _name = name;
}

string const& User::getLogin() const
{
    return _login;
}

void User::setLogin(string const& login)
{
    _login = login;
}

string const& User::getPass() const
{
    return _pass;
}

void User::setPass(string const& pass)
{
    _pass = pass;
}

vector<User> read_users(string const& filename)
{
    ifstream fin(filename, std::ios::in);
    if (!fin)
        return {};
        vector<User> users;
        while (true)
        {
            string name, login, pass;
            fin >> name >> login >> pass;
            if (fin.eof())
                break;
            users.push_back({name, login, pass});
        }
        fin.close();
        return users;
}

void write_users(string const& filename, vector<User> const& users)
{
    ofstream fout(filename, std::ios::out | std::ios::app);
    if(!fout)
        return;
    for (auto const& user : users)
    {
        fout << user.getName() << endl
                << user.getLogin() << endl
                    << user.getPass() << endl;
    }
    fout.close();
}

void print_users(vector<User> const& users)
{
    cout << users.size() << endl;
    for (auto const& user : users)
    {
        cout << user.getName() << endl
                << user.getLogin() << endl
                    << user.getPass() << endl;
    }
}
