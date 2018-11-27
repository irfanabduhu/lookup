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

class User
{
protected:
    string id;
    string mname;
    string mpassword;
    string home_dir;

    size_t compute_key(string name)
    // help to generate a unique user id
    {
        hash<string> str_hash;
        size_t id = str_hash(name);
        srand(time(NULL));
        id += rand();
        return id;
    }

public:
    User(){}
    User(string ID, string password): id(ID),  mpassword(password)
    {
        mname = ID.substr(0, ID.length()-3);
        home_dir = (app_home+id);
    }
    string sign_up(string name, string password)
    {
        id = name + to_string(compute_key(name) % 1000);
        mname = name;
        mpassword = password;
        home_dir = app_home + id;
        // create a new directory for the user:
        bf::create_directory(home_dir);

        // store user_id and password in a .info file @user's home
        std::ofstream outfile(home_dir + "/__user.info");
        outfile << password;
        outfile.close();
        return id;
    }
    bool sign_in(string password)
    {
        string file_path = home_dir + "/__user.info";
        if (bf::exists(file_path))
        {
            std::ifstream info_file(file_path);
            string pass;
            getline(info_file, pass);
            return pass == password;
        }
        return false;
    }
};

int main(void)
{
    cout << "Welcome to LookUp!\n";
    cout << "Do you have an account? [y/n]\n";
    string response; cin >> response;
    while (response != "y" && response != "n")
    {
        cout << "Please enter a valid option [y/n].\n";
        cin >> response;
    }

    if (response == "y") // has an account
    {
        string id, password;
        cout << "User ID: "; cin >> id;
        cout << "\nPassword: "; cin >> password;
        User user(id, password);
        bool status = false;

        while (!status)
        {
            status = user.sign_in(password);
            if(status)
                cout << "Successfully signed in!\n";
            else
            {
                cout << "Password hasn't matched! Try again\n";
                cout << "Password: ";
                cin >> password;
            }
        }
    }
    else // doesn't have an account
    {
        cout << "Welcome to LookUp, your very own information retrieval system!\n";
        cout << "Please provide the following information to create a new account!\n";
        string name, password;
        cout << "Name: "; cin >> name;
        cout << "Password: "; cin >> password;
        User user;
        string id = user.sign_up(name, password);
        cout << "Your account has been created successfully!\n"
             << "Please save the following information for later access.\n";
        cout << "\n\nName: " << name << endl
             << "User ID: " << id << endl;
    }
}
