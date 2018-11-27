#include "Search.cpp"
#include "Database.cpp"

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

    string home;

    if (response == "y") // has an account
    {
        string id, password;
        cout << "User ID: "; cin >> id;
        password = getpass("Password: ");
        //cout << "\nPassword: "; cin >> password;
        User user(id, password);

        bool status = false;

        while (!status)
        {
            status = user.sign_in(password);
            string name = user.name();
            if(status)
            {
                cout << "\nSuccessfully signed in! Welcome " + name + "!\n";
                home = user.home();
            }
            else
            {
                cout << "Password hasn't matched! Try again\n";
                password = getpass("Password: ");
            }
        }
    }

    else // doesn't have an account
    {
        cout << "Welcome to LookUp, your very own information retrieval system!\n";
        cout << "Please provide the following information to create a new account!\n";
        string name, password;
        cout << "Name: ";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, name);
        password = getpass("Password: ");

        User user;
        string id = user.sign_up(name, password);
        cout << "\nYour account has been created successfully!\n"
             << "Please save the following information for later access.\n";
        cout << "Name: " << name << endl
             << "User ID: " << id + "\n\n";
        home = user.home();
    }

    cout << "What do you want to do today?!" << endl
         << "1. Add note\n"
         << "2. Search for desired files.\n"
         << "3. Extract information\n"
         << "0. Log out\n";

    int mode; cin >> mode;

    while (mode != 0)
    {
        if(mode == 1)
        {
            Database user_db(home);
            string title = user_db.add_note();
            cout << title + " added successfully.\n\n";
        }
        else if (mode == 2)
        {
            string key;
            cout << "What are you looking for? ";
            cin >> key;
            Search user_search(home);
            string result = user_search.scan(key);
            if (result.empty())
                cout << "No match found.\n";
            cout << result;
        }
        else if (mode == 3)
        {
            string key;
            cout << "What are you looking for? ";
            cin >> key;
            Search user_search(home);
            string result = user_search.lookup(key);
            if (result.empty())
                cout << "No match found.\n";
            cout << result;
        }
        else
        {
             cout << "Error! Choose a valid option [0/1/2/3].\n\n";
             cin >> mode;
             continue;
        }
        cout << "What do you want to do?! [0/1/2/3]. ";
        cin >> mode;
    }
    cout << "Moriturus te saluto.\n";
}
