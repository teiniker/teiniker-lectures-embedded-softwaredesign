#include "table.h"
#include <stdexcept>

using namespace std;


UserTable::UserTable(void)
{
    _table = vector<User>();
}

void UserTable::insertUser(const User& user)
{
    _table.push_back(user);
}

void UserTable::updateUser(const User& user)
{
    for (size_t i = 0; i < _table.size(); i++)
    {
        if (_table[i].id() == user.id())
        {
            _table[i] = user;
            return;
        }
    }
    throw invalid_argument("User not found");
}

User& UserTable::findById(const int id)
{
    for (size_t i = 0; i < _table.size(); i++)
    {
        if (_table[i].id() == id)
        {
            return _table[i];
        }
    }
    throw invalid_argument("User not found");
}

User& UserTable::findByUsername(const string& username)
{
    for (size_t i = 0; i < _table.size(); i++)
    {
        if (_table[i].username() == username)
        {
            return _table[i];
        }
    }
    throw invalid_argument("User not found");
}

size_t UserTable::size() const
{
    return _table.size();
}
