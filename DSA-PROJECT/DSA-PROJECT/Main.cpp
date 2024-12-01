#include <iostream>
#include <iomanip>
#include <string>
#include"Graphs.cpp"

#include <ctime> 

using namespace std;


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
    time_t now = time(0);          
    tm ltm;                        
    localtime_s(&ltm, &now);       


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
    string username, city, lastLogin, password, to, question, temp;
    Graph insta;
    Linkedlist database;
    bool loggedin = false;
    bool check;
    char ch;
    do {
        displayMenu();
        cin >> choice;

      

        system("cls"); 
        switch (choice) {
        case 1:
            if (!loggedin) {

                cout << BOLD << CYAN << "\n*******************************************" << RESET << endl;
                cout << BOLD << MAGENTA << "*             SIGN UP PORTAL              *" << RESET << endl;
                cout << BOLD << CYAN << "*******************************************" << RESET << endl;

                
                do {
                    cout << "Enter a username: ";
                    cin >> username;

                    check = database.search(username);
                    if (!isValidUsername(username))
                        cout << RED << "Invalid username!" << YELLOW << "Username must be at least 4 characters long, start with a letter, and contain only letters, digits, or underscores.\n" << RESET;
                    if (check)
                        cout << RED << "Username already taken!" << YELLOW << " Username must be Uniques.\n" << RESET;
                } while (!isValidUsername(username) && !check);

               
                do {
                    cout << "Create a strong password: ";
                    cin >> password;
                    if (!isStrongPassword(password))
                        cout << "Weak password! Password must be at least 8 characters long and include uppercase, lowercase, digits, and special characters.\n";

                } while (!isStrongPassword(password));
                cin.ignore();
                cout << BOLD << GREEN << "Enter your security question for password reset: " << RESET;
                getline(cin, question);
               
                cout << BOLD << GREEN << "Enter your city: " << RESET;
                getline(cin, city);

                
                lastLogin = getCurrentDateTime();
                cout << BOLD << GREEN << "Last login time set to: " << lastLogin << RESET << endl;

                insta.addUser(username, password, city, lastLogin);
                database.insertdata(username, password, question);
                loggedin = true;
               
                cout << BOLD << CYAN << "\n-------------------------------------------" << RESET << endl;
                cout << BOLD << YELLOW << "Sign-Up Successful!" << RESET << endl;
                cout << BOLD << CYAN << "-------------------------------------------" << RESET << endl;
                cout << GREEN << "Welcome, " << username << "! Your profile has been created.\n" << RESET;

            }
            else
            {
                cout << RED << "\n\nALREADY LOGGED IN :(\n" << RESET;
                cout << YELLOW << "\n\nLOGOUT TO CREATE NEW Account :(\n" << RESET;
            }

      
            break;
        case 2:
          
            cout << BOLD << CYAN << "\n*******************************************" << RESET << endl;
            cout << BOLD << MAGENTA << "*             LOGIN PORTAL                *" << RESET << endl;
            cout << BOLD << CYAN << "*******************************************" << RESET << endl;

            if (!loggedin) {


               
                do {
                    cout << "Enter your username: ";
                    cin >> username;
                    cin.ignore();
                
                    check = database.search(username);  
                    if (check == false) {
                        cout << "Username does not exist. Please try again.\n";
                    }
                } while (!check);

              
                do {
                    cout << "Enter your password: ";
                    cin >> password;
                    cin.ignore();

                   
                    if (!database.validate(username, password)) {
                        cout << "Incorrect password! Please try again.\n";
                    }
                } while (!database.validate(username, password));

                

                loggedin = true;
                lastLogin = getCurrentDateTime();
                insta.setlatestime(username, lastLogin);
                cout << BOLD << GREEN << "Last login time set to: " << lastLogin << RESET << endl;
                // Confirmation message
                cout << BOLD << CYAN << "\n-------------------------------------------" << RESET << endl;
                cout << BOLD << YELLOW << "Login Successful!" << RESET << endl;
                cout << BOLD << CYAN << "-------------------------------------------" << RESET << endl;
                cout << GREEN << "Welcome back, " << username << "! You are now logged in.\n" << RESET;
                cout << "To Change Password with security question y for yes n for no ";
                cin >> ch;
                cin.ignore();
                if (ch == 'y' || ch == 'Y')
                {
                    cout << YELLOW << "Enter your security question: \n" << RESET << endl;
                    getline(cin, question);
                    check = database.searchsecurity(username, question);
                    if (check)
                    {
                        do {
                            cout << YELLOW << "Create a New strong password: " << RESET;
                            cin >> password;
                            if (!isStrongPassword(password))
                                cout << BOLD << "Weak password! Password must be at least 8 characters long and include uppercase, lowercase, digits, and special characters.\n" << RESET;

                        } while (!isStrongPassword(password));
                        insta.setnewpassword(username, password);
                        database.updatepassword(username, password);
                        cout << GREEN << "PASSWORD UPDATED SUCCEFULLLY\n" << RESET;
                    }
                    else {
                        cout << RED << "Wrong Question " << RESET << endl;
                    }


                }
                else if (ch == 'n' || ch == 'N') cout << GREEN << "Proceeding.....  \n" << RESET << endl;
                else cout << RED << "Invalid input\n" << RESET;

            }
            else {
                cout << RED << "\n\nALREADY LOGGED IN :(\n" << RESET;
                cout << YELLOW << "\n\nLOGOUT First TO LOGIN TO A DIFFERENT ACCOUNT :(\n" << RESET;
            }
            break;

        case 3:
            
            if (loggedin) {
                cout << YELLOW << "To Confirm Logout press y for yes n for no " << RESET;
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                {

                    loggedin = false;
                    cout << BOLD << CYAN << "\n-------------------------------------------" << RESET << endl;
                    cout << BOLD << YELLOW << "Logout Successful!" << RESET << endl;
                    cout << BOLD << CYAN << "-------------------------------------------" << RESET << endl;
                    cout << GREEN << "See you soon User " << username << "! You are now logged out.\n" << RESET;
                }
                else if (ch == 'n' || ch == 'N') cout << GREEN << "Proceeding.....  \n" << RESET << endl;
                else cout << RED << "Invalid input\n" << RESET;
            }
            else {
                cout << RED << "\n\Not LOGGED IN :(\n" << RESET;
                cout << YELLOW << "\n\nLOG INTO A ACCOUNT First:(\n" << RESET;
            }

            break;
        case 4:
            if (loggedin) {
              
                cout << "ENTER USERNAME TO SEND REQUEST: ";
                cin >> to;
                if (username == to) {
                    cout << RED << "CANNOT FOLLOW YOURSELF\n" << RESET;
                }
                else
                    insta.sendfollowrequest(username, to);
                insta.addfollower(username, to);
            }
            else {
                cout << RED << "\n\Not LOGGED IN :(\n" << RESET;
                cout << YELLOW << "\n\nLOG INTO A ACCOUNT First:(\n" << RESET;
            }
           
            break;

        case 5:
            if (loggedin) {
               
                cout << BLUE << "YOUR Current Followers" << RESET << endl;
                insta.displayfollowers(username);
                cout << BLUE << "\n\nENTER THE NAME From Above U WANT TO FOLLOW BACK: " << RESET;
                cin >> to;
                    insta.sendfollowrequest(username, to);
                insta.addfollower(username, to);
            }
            else {
                cout << RED << "\n\Not LOGGED IN :(\n" << RESET;
                cout << YELLOW << "\n\nLOG INTO A ACCOUNT First:(\n" << RESET;
            }
            
            break;
        case 6:
           
            if (loggedin) {
                cout << BOLD << CYAN << "\n*******************************************" << RESET << endl;
                cout << BOLD << MAGENTA << "*           TIMELINE             *" << RESET << endl;
                cout << BOLD << CYAN << "*******************************************" << RESET << endl;
                cout << YELLOW << "WANT TO SHARE A POST (y for yes and n for no): " << RESET;
                cin >> ch;
                cin.ignore();
                if (ch == 'y' || ch == 'Y')
                {
                    cout << BLUE << "\n\nWrite A Post to Share: " << RESET;
                    getline(cin, temp);

                    insta.addpost(temp, username);
                    cout << GREEN << "posted.....  \n" << RESET << endl;
                }
                else if (ch == 'n' || ch == 'N') {
                    cout << GREEN << "Viewing Followers posts.....  \n" << RESET << endl;
                    insta.viewfollowerposts(username);
                }
                else cout << RED << "Invalid input\n" << RESET;
            }
            else {
                cout << RED << "\n\Not LOGGED IN :(\n" << RESET;
                cout << YELLOW << "\n\nLOG INTO A ACCOUNT First:(\n" << RESET;
            }

            
            break;
        case 7:
         
            if (loggedin) {
                cout << BOLD << CYAN << "\n*******************************************" << RESET << endl;
                cout << BOLD << MAGENTA << "*            NOTIFICATIONS             *" << RESET << endl;
                cout << BOLD << CYAN << "*******************************************" << RESET << endl;
                insta.displaynotificatios(username);
            }
            else {
                cout << RED << "\n\Not LOGGED IN :(\n" << RESET;
                cout << YELLOW << "\n\nLOG INTO A ACCOUNT First:(\n" << RESET;
            }
            break;
        case 8:
           
            if (loggedin) {
                cout << BOLD << CYAN << "\n*******************************************" << RESET << endl;
                cout << BOLD << MAGENTA << "*             INBOX              *" << RESET << endl;
                cout << BOLD << CYAN << "*******************************************" << RESET << endl;

                cout << BLUE << "ENTER USERNAME TO SEND Message: " << RESET;
                cin >> to;
                cin.ignore();
                if (username == to) {
                    cout << RED << "CANNOT Send Message to YOURSELF\n" << RESET;
                }
                else {
                    cout << BLUE << "ENTER Message TO deliver to: " << to << RESET << endl;;
                    getline(cin, temp);
             
                    insta.sendMessage(temp, username, to);
                    cout << GREEN << "MESSAGE SENT SUCCESSFULLY!\n" << RESET;
                }
            }
            else {
                cout << RED << "\n\Not LOGGED IN :(\n" << RESET;
                cout << YELLOW << "\n\nLOG INTO A ACCOUNT First:(\n" << RESET;
            }


         
            break;
        case 9:

            
            cout << BLUE << "ENTER USER NAME TO SEARCH: " << RESET;
            cin >> temp;
            if (insta.searchuser(temp)/*database.search(temp)*/) {
                cout << GREEN << "USER with Username " << temp << " exists!\n" << RESET;
            }
            else
            {
                cout << GREEN << "USER with Username " << temp << " does not exist!\n" << RESET;
            }



            break;
        case 10:
            if (loggedin) {

                
                cout << BLUE << "YOUR Current Followers are shown below" << RESET << endl;
                insta.displayfollowers(username);
                cout << YELLOW << "WANT TO SEE Suggestions? (y for yes and n for no): " << RESET;
                cin >> ch;
                cin.ignore();
                if (ch == 'y' || ch == 'Y')
                {
                 

                    cout << endl << endl<<CYAN<<"---------------Suggestions!-----------------\n"<<RESET;
                   insta.ShowSuggestions(username);

                                                    

                    cout << GREEN << "  \n" << RESET << endl;
                }
                else if (ch == 'n' || ch == 'N') {
                    cout << GREEN << "Suree.....  \n" << RESET << endl;
                    insta.BFS(username);
                   
                }
                else cout << RED << "Invalid input\n" << RESET;

            }
            else
            {
                cout << RED << "\n\Not LOGGED IN :(\n" << RESET;
                cout << YELLOW << "\n\nLOG INTO A ACCOUNT First:(\n" << RESET;
            }


        
            break;
        case 11:
            
            if (loggedin) {
                cout << BOLD << CYAN << "\n*******************************************" << RESET << endl;
                cout << BOLD << MAGENTA << "*       YOUR  POSTS             *" << RESET << endl;
                cout << BOLD << CYAN << "*******************************************" << RESET << endl;
                insta.displayposts(username);

            }
            else
            {
                cout << RED << "\n\Not LOGGED IN :(\n" << RESET;
                cout << YELLOW << "\n\nLOG INTO A ACCOUNT First:(\n" << RESET;
            }
            
            break;
        case 0:
            cout << CYAN << "\nThank you for using Mini Instagram. Goodbye!\n" << RESET;
            break;
        default:
            cout << RED << "\nInvalid choice. Please try again.\n" << RESET;

        }
    }
    while (choice != 0);
        system("pause");
        return 0;
 }   
    

    


    