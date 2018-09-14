#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

bool add_user(string name, string password, map<string, string>& users)
{
    if (users.find(name) == users.end()) // the user doesn't exist
    {
        users[name] = password;
        return true; // add_user is successful.
    }
    else // the user already exist;
        return false; // add_user is unsuccessful.
}

int main(void)
{
    map<string, string> users;

    //////////////////////////////////////////////
    // example: add_user                        //
    // add_user("irfan", "eat_n_sleep", users); //
    // add_user("talha", "run_n_code", users);  //
    // for (auto [k, v]: users)                 //
    //     cout << k << ": " << v << endl;      //
    //////////////////////////////////////////////
}
