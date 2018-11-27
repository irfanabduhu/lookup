#include <iostream>
#include "boost/filesystem.hpp"
#include <fstream>
#include <sstream>
#include <regex>
using namespace std;
int main(void)
{
    size_t v = 20913;
    ostringstream o;
    o << v;
    string s = o.str();
    cout << s << endl;

    string name = "man";
    size_t n = 10;
    string user = "a";
    string app_home = "b";
    string fasdfs = app_home + user + "/__user.info";
    cout << name + to_string(n) << endl;
}
