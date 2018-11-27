#include "User.cpp"

class Search : private User
{
private:
    string home;
public:
    /**
     * @return titles
     */
    Search (string home_dir) : home(home_dir) {}

    string scan(string key)
    {
        ostringstream out;
        for (bf::directory_entry& f : bf::directory_iterator(home))
        {
            bf::ifstream myfile (f);
            string line;
            string title;
            getline(myfile, title);

            // iterate over each line;
            while(getline(myfile, line))
            {
                // use regex to search for a pattern
                size_t found = line.find(key);
                if (found != string::npos)
                {
                    out << title << endl;
                    break;
                }
            }
        }
        return out.str();
    }

    /**
     * @return excerpts.
     */
    string lookup(string key)
    {
        ostringstream out;
        for (bf::directory_entry& f : bf::directory_iterator(home))
        {
            bf::ifstream myfile (f);
            string line;

            // iterate over each line;
            while(getline(myfile, line))
            {
                // use regex to search for a pattern
                size_t found = line.find(key);
                if (found != string::npos)
                    out << line + "\n\n";
            }
        }
        return out.str();
    }
};
