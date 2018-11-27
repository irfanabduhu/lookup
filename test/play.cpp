#include "boost/filesystem.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
// #include "User.cpp"

using namespace std;
namespace bf = boost::filesystem;
string app_home = "__lookup_home__/";

int main(void)
{
    // ostringstream result;
    // string home_dir = app_home + "Irfan479";
    // for (bf::directory_entry& f : bf::directory_iterator(home_dir))
    // {

    //     bf::ifstream myfile (f);
    //     string line;

    //     // iterate over each line;
    //     while(getline(myfile, line))
    //     {
    //         // use regex to search for a pattern
    //         size_t found = line.find("neon");
    //         if (found != string::npos)
    //             result << line << endl;
    //     }
    // }
    // cout << result.str();

    // string title;
    // cout << "Title: ";
    // getline(cin, title);

    // string body;
    // ostringstream out;
    // string tmp;
    // while (getline(cin, tmp))
    // {
    //     if (tmp == "END") break;
    //     out << tmp + "\n";
    // }

    // ofstream file("check.txt");
    // file << out.str();

  string title = "something, doesn't working";
  string res;
  for (char c : title)
  {
    if (isalpha(c) || isdigit(c)) res += c;
    else res += '_';
  }
  cout << res << endl;
}
