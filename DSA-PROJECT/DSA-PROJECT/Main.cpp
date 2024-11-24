#include <iostream>
#include <iomanip> // For formatting
#include <string>
#include"Graphs.cpp"

#include <ctime> // For time functions
using namespace std;

// ANSI escape codes for colors
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string BOLD = "\033[1m";


string getCurrentDateTime() {
    time_t now = time(0);          // Get the current time
    tm ltm;                        // Create a tm structure to store the result
    localtime_s(&ltm, &now);       // Safe conversion to local time

    // Format the date and time as "YYYY-MM-DD HH:MM"
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", &ltm);
    return std::string(buffer);
}


void displayMenu() {
    cout << "\n";
    cout << BOLD << CYAN << "*******************************************" << RESET << "\n";
    cout << BOLD << MAGENTA << "*                                         *" << RESET << "\n";
    cout << BOLD << MAGENTA << "*             MINI INSTAGRAM              *" << RESET << "\n";
    cout << BOLD << MAGENTA << "*         ~ Social Made Simple ~          *" << RESET << "\n";
    cout << BOLD << MAGENTA << "*                                         *" << RESET << "\n";
    cout << BOLD << CYAN << "*******************************************" << RESET << "\n";
    cout << "\n" << BOLD << WHITE << "Choose an option:\n" << RESET;
    cout << YELLOW << "-------------------------------------------" << RESET << "\n";
    cout << GREEN << "1. " << WHITE << "Sign Up\n";
    cout << GREEN << "2. " << WHITE << "Log In\n";
    cout << GREEN << "3. " << WHITE << "Log Out\n";
    cout << GREEN << "4. " << WHITE << "Send Follow Request\n";
    cout << GREEN << "5. " << WHITE << "Cancel or Accept Requests\n";
    cout << GREEN << "6. " << WHITE << "View Posts (Timeline)\n";
    cout << GREEN << "7. " << WHITE << "View Notifications\n";
    cout << GREEN << "8. " << WHITE << "Messaging\n";
    cout << GREEN << "9. " << WHITE << "Search Users\n";
    cout << GREEN << "10. " << WHITE << "View Followers List\n";
    cout << GREEN << "11. " << WHITE << "View Your Newsfeed\n";
    cout << GREEN << "0. " << WHITE << "Exit\n";
    cout << YELLOW << "-------------------------------------------" << RESET << "\n";
    cout << WHITE << "Enter your choice: " << RESET;
}

bool isStrongPassword(const std::string& password) {
    if (password.length() < 8)
        return false;

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    for (char c : password) {
        if (isupper(c)) hasUpper = true;
        else if (islower(c)) hasLower = true;
        else if (isdigit(c)) hasDigit = true;
        else if (ispunct(c)) hasSpecial = true;
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}
bool isValidUsername(const std::string& username) {
    if (username.length() < 4 || !isalpha(username[0]))
        return false;

    for (char c : username) {
        if (!isalnum(c) && c != '_')
            return false;
    }

    return true;
}

int main() {
    int choice;
    string username, city, lastLogin, password,to;
    Graph insta;
    bool loggedin = false;
    do {
        displayMenu();
        cin >> choice;

        // Clear screen for a clean menu look after each interaction

        system("cls"); // Use "system('clear')" for Linux/Mac
        switch (choice) {
        case 1:
            if (!loggedin) {
            
            cout << BOLD << CYAN << "\n*******************************************" << RESET << endl;
            cout << BOLD << MAGENTA << "*             SIGN UP PORTAL              *" << RESET << endl;
            cout << BOLD << CYAN << "*******************************************" << RESET << endl;
            bool check;
            // Input username
            do {
                cout << "Enter a username: ";
                cin >> username;
                
             check  = insta.checkvalidity(username);
                if (!isValidUsername(username) && !check)
                    cout << "Invalid username! Username must be at least 4 characters long, start with a letter, and contain only letters, digits, or underscores.\n";
            } while (!isValidUsername(username)&& !check);

            // Input and validate password
            do {
                cout << "Create a strong password: ";
                cin >> password;
                if (!isStrongPassword(password))
                    cout << "Weak password! Password must be at least 8 characters long and include uppercase, lowercase, digits, and special characters.\n";
              
            } while (!isStrongPassword(password));
            cin.ignore();
            // Input city
            cout << BOLD << GREEN << "Enter your city: " << RESET;
            getline(cin, city);

            // Automatically fetch the current date and time
            lastLogin = getCurrentDateTime();
            cout << BOLD << GREEN << "Last login time set to: " << lastLogin << RESET << endl;
            
            insta.addUser(username,password,city,lastLogin);
            loggedin = true;
            // Confirmation message
            cout << BOLD << CYAN << "\n-------------------------------------------" << RESET << endl;
            cout << BOLD << YELLOW << "Sign-Up Successful!" << RESET << endl;
            cout << BOLD << CYAN << "-------------------------------------------" << RESET << endl;
            cout << GREEN << "Welcome, " << username << "! Your profile has been created.\n" << RESET;

            }
            else
            {
                cout<<RED << "\n\nALREADY LOGGED IN :(\n"<<RESET;
                cout<<YELLOW << "\n\nLOGOUT TO CREATE NEW Account :(\n"<<RESET;
            }

            // Call Sign Up function here
            break;
        case 2:
            cout << GREEN << "\n[Log In Functionality]\n" << RESET;
            cout << BOLD << CYAN << "\n*******************************************" << RESET << endl;
            cout << BOLD << MAGENTA << "*             LOGIN PORTAL                *" << RESET << endl;
            cout << BOLD << CYAN << "*******************************************" << RESET << endl;

            if (!loggedin) {
                bool check;

                // Input username
                //do {
                //    cout << "Enter your username: ";
                //    cin >> username;

                //    // Check if username exists
                //    check = insta.checkUsernameExistence(username);  // Use actual check for username existence
                //    if (!check) {
                //        cout << "Username does not exist. Please try again.\n";
                //    }
                //} while (!check);

                // Input password
               // do {
                    cout << "Enter your password: ";
                    cin >> password;

                    // Check if password matches the username
                 //   if (!insta.checkPasswordMatch(username, password)) {
                   //     cout << "Incorrect password! Please try again.\n";
                  //  }
               // } while (!insta.checkPasswordMatch(username, password));

                // Mark the user as logged in
                loggedin = true;

                // Confirmation message
                cout << BOLD << CYAN << "\n-------------------------------------------" << RESET << endl;
                cout << BOLD << YELLOW << "Login Successful!" << RESET << endl;
                cout << BOLD << CYAN << "-------------------------------------------" << RESET << endl;
                cout << GREEN << "Welcome back, " << username << "! You are now logged in.\n" << RESET;

            }
            else {
                cout << RED << "\n\nALREADY LOGGED IN :(\n" << RESET;
                cout << YELLOW << "\n\nLOGOUT TO LOG INTO A DIFFERENT ACCOUNT :(\n" << RESET;
            }
            break;

        case 3:
            cout << GREEN << "\n[Log Out Functionality]\n" << RESET;
           
            loggedin = false;
            // Call Log Out function here
            break;
        case 4:
            cout << GREEN << "\n[Send Follow Request Functionality]\n" << RESET;
            cout << "ENTER USERNAME TO SEND REQUEST";
          
            cin >> to;
       
            insta.insertfriendrequest(username,to);
            // Call Follow Request function here
            break;
        case 5:
            cout << GREEN << "\n[Cancel or Accept Requests Functionality]\n" << RESET;
            insta.displayfriendrequests(username);
            insta.addfriend(username);
            // Call Cancel/Accept Requests function here
            break;
        case 6:
            cout << GREEN << "\n[View Posts (Timeline) Functionality]\n" << RESET;
            // Call Posts/Timeline function here
            break;
        case 7:
            cout << GREEN << "\n[View Notifications Functionality]\n" << RESET;
            // Call Notifications function here
            break;
        case 8:
            cout << GREEN << "\n[Messaging Functionality]\n" << RESET;
            // Call Messaging function here
            break;
        case 9:
            cout << GREEN << "\n[Search Users Functionality]\n" << RESET;
            // Call Search Users function here
            break;
        case 10:
            cout << GREEN << "\n[View Followers List Functionality]\n" << RESET;
            // Call Followers List function here
            break;
        case 11:
            cout << GREEN << "\n[View Your Newsfeed Functionality]\n" << RESET;
            // Call Newsfeed function here
            break;
        case 0:
            cout << CYAN << "\nThank you for using Mini Instagram. Goodbye!\n" << RESET;
            break;
        default:
            cout << RED << "\nInvalid choice. Please try again.\n" << RESET;
        }
    } while (choice != 0);
 system("pause");
    return 0;
}
