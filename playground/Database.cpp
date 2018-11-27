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

class Database // : private User
{
public:
    string get_dir()
    { return home_dir; }

    string create_directory()
    {
        string dir = app_home + id;
        bf::create_directory(dir);
        return dir;
    }
};
