#include "boost/filesystem.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;
namespace bf = boost::filesystem;
string app_home = "__lookup_home__/";


size_t compute_key(string name)
// instead of storing password directly, store its hash.
{
    hash<string> str_hash;
    return str_hash(name);
}


bool add_user(string name, string password, map<string, size_t>& users)
{
    if (users.find(name) == users.end()) // the user doesn't exist
    {
        users[name] = compute_key(password);
        // create a new directory for the user:
        bf::create_directory(app_home + name);
        return true; // add_user is successful.
    }
    else // the user already exist;
        return false; // add_user is unsuccessful.
}


bool sign_in(string name, string password, map<string, size_t>& users)
{
    return compute_key(password) == users[name];
}


int main(void)
{
    // first off, make a home.
    // if a directory already exists, it doesn't override.
    bf::create_directory(app_home);

    map<string, size_t> users;
    add_user("irfan", "eat_n_sleep", users);
    add_user("talha", "run_n_code", users);
    add_user("imran", "line_a_ay", users);

    for (auto k : v) cout <<
    cout << compute_key("imran") % 1000000 << endl;
}
