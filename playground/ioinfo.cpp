#include "boost/filesystem.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <utility>
#include <regex>
using namespace std;
namespace bf = boost::filesystem;
string app_home = "__lookup_home__/";


bool lookup(string dir, string key, ostringstream& output)
{
    for (bf::directory_entry& f : bf::directory_iterator(dir))
    {
        bf::ifstream myfile (f);
        string line;

        // iterate over each line;
        while(getline(myfile, line))
        {
            // use regex to search for a pattern
        }
    }

    // successful lookup should return true;
}

int main(void)
{
    string name = "irfan";
    bf::path user_dir (app_home + name);

}
