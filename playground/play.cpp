#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <utility> // make_pair, pair
using namespace std;


size_t compute_key(string name)
{
    hash<string> str_hash;
    return str_hash(name);
}

bool add_user(string name, string password, map<string, Secret>& users)
{
    if (users.find(name) == users.end()) // the user doesn't exist
    {
        users[name] = make_pair(password, compute_key(name));
        return true; // add_user is successful.
    }
    else // the user already exist;
        return false; // add_user is unsuccessful.
}

int main(void)
{

    map<string, Secret> users;

    add_user("irfan", "eat_n_sleep", users);
    add_user("talha", "run_n_code", users);

    for (auto [k, v] : users)
        cout << k << " : " << v.first << ", " << v.second << endl;
}
