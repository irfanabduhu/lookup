class Database : private User
{
private:
    string home;

public:
    Database(string h) { home = h; }

    string add_note()
    {
        string title;
        cout << "Title: ";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, title);

        ostringstream os;
        os << title + "\n";

        string tmp;
        while (getline(cin, tmp))
        {
            if (tmp == "END") break;
            os << tmp + "\n";
        }

        string name = generate_filename(title) + ".txt";
        ofstream file(home + name, std::ofstream::out);
        file << os.str();
        file.close();
        return name;
    }
};
