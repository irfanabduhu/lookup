#include "boost/filesystem.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <utility>
#include <cstdlib>
#include <ctime>

using namespace std;
namespace bf = boost::filesystem;
string app_home = "__lookup_home__/";


size_t compute_id(string name)
// generate a unique user id
{
    hash<string> str_hash;
    srand(time(NULL));
    size_t id = str_hash(name) % 1000000;
    id += rand() % 1000000;
    return id;
}


bool sign_up(string name, string password, map<size_t, string>& users)
{
    // if (users.find(name) == users.end()) // the user doesn't exist
    // {
    size_t id = compute_id(name);
    users[id] = password;
    // create a new directory for the user:
    bf::create_directory(app_home + name);
    return true; // add_user is successful.
    // }
    // else // the user already exist;
    //     return false; // add_user is unsuccessful.
}


bool sign_in(string name, string password, map<string, size_t>& users)
{
    return password == users[id];
}


int main(void)
{
    // first off, make a home.
    // if a directory already exists, it doesn't override.
    bf::create_directory(app_home);

    map<size_t, string> users;
    sign_up("irfan", "eat_n_sleep", users);
    sign_up("talha", "run_n_code", users);
    sign_up("imran", "line_a_ay", users);
    cout << compute_id("imran") << endl;
}
