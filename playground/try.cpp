#include <iostream>
#include "boost/filesystem.hpp"
#include <fstream>
#include <sstream>
#include <regex>
using namespace std;
namespace bf = boost::filesystem;


int main(void)
{
    /////////////////////////////////////////////////////
    // ostringstream accumulator (ostringstream::ate); //
    // accumulator << "quick\n";                       //
    // accumulator << "fast\nslow\n";                  //
    // //accumulator.str("quick\n");                   //
    // cout << accumulator.str();                      //
    /////////////////////////////////////////////////////

    string str = "The ape was at the apex";
    regex pattern ("(ape[^ ]?)"); // starts with ape and not followed by a spac
    smatch matches;

    cout << std::boolalpha;
    while(regex_search(str, matches, pattern))
    {
        cout << "Is there a match : " << matches.ready() << '\n';
        cout << "Are there no matches : " << matches.empty() << '\n';
        cout << "Number of matches : " << matches.size() << '\n';
        cout << matches.str(1) << "\n"; // print the first match
        str = matches.suffix().str(); // get rid of the first match
    }

    size_t id = 1089312;
    string val = string(7, id);
    cout << val << endl;


}
