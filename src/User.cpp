#include "boost/filesystem.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
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
    string generate_id(string name)
    {
        string id = "";
        for (char c : name)
        {
            if (isalpha(c)) id += c;
            else id += '_';
        }
        id += to_string(compute_key(id) % 1000);
        return id;
    }
    string generate_filename(string title)
    {
        string name = "";
        for (char c : title)
        {
            if (isalpha(c) || isdigit(c)) name += c;
            else name += '_';
        }
        return name;
    }
    string get_name(string id)
    {
        string name = "";
        for (char c : id.substr(0, id.length()-3))
        {
            if (isalpha(c)) name += c;
            else name += ' ';
        }
        return name;
    }
public:
    User(){}
    User(string ID, string password): id(ID),  mpassword(password)
    {
        mname = get_name(ID);
        home_dir = (app_home+id+ "/");
    }
    string sign_up(string name, string password)
    {
        id = generate_id(name);
        mname = name;
        mpassword = password;
        home_dir = app_home + id + "/";
        // create a new directory for the user:
        bf::create_directory(home_dir);

        // store user_id and password in a .info file @user's home
        std::ofstream outfile(home_dir + "__user.info");
        outfile << password;
        outfile.close();
        return id;
    }
    bool sign_in(string password)
    {
        string file_path = home_dir + "__user.info";
        if (bf::exists(file_path))
        {
            std::ifstream info_file(file_path);
            string pass;
            getline(info_file, pass);
            return pass == password;
        }
        return false;
    }
    string name(void) { return mname; }
    string home(void) { return home_dir; }
};
