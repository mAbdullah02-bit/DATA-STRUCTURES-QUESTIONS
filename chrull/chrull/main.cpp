#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string>
#include<ctime>
#include "BST.cpp"
#include "Graph.cpp"
using namespace std;


string getTimestampp() {
    time_t s = time(0);
    char Buffer[26];
    ctime_s(Buffer, sizeof(Buffer), &s);
    string timestampp = Buffer;

    return timestampp;
}

int main() {
    //cout<<"\033[31m#\033[0m"; // red
    //cout<< "\033[34m@\033[0m"; // dark blue
    //cout << "\033[32m&\033[0m"; //green
    //cout << "\033[35m%\033[0m";//purple
    //cout << "\033[33m*\033[0m";//yellow
    //cout << "\033[36m+\033[0m";//sky blue
    //cout << endl;
    cout << "\033[31m\n\n\n\t\t\t\t\t\t\t Insta Update 2.0\033[0m\n";

    char choice;
    Users g;
    BST b;
    do {
        cout << "\033[31m\n\n\n\t\t\t\t\t\t\t    Mini Instagram!\033[0m\n";
        cout << "\033[36m\t\t\t\t\t\t\t   +---------------+\033[0m\n\n";
        cout << "\n\033[36m\t\t\t\t\t\t\t      1.Sign up\n\n";
        cout << "\t\t\t\t\t\t\t      2.Login\n\n";
        cout << "\t\t\t\t\t\t\t      3.Exit\033[0m\n\n";
        cout << "\033[36m\t\t\t\t\t\t\t   +----------------+\033[0m\n\n";
        cout << "\033[31m\t\t\t\t\t\t\t  Enter Your Choice: ";
        cin >> choice;

        cout << "\033[0m";
        switch (choice) {
        case '1': {
            string name;
            string password;
            string city;
            string security;
            do {
                cout << "\n\033[36m\t\t\t\t\t\t\t  Enter Username:  ";
                cin >> name;
                if (g.findVertex(name) != nullptr) {
                    cout << "\t\t\t\t\t\t\tUsername " << name << " already exists!" << endl;
                }
                else {
                    break;
                }

            } while (true);

            do {
                cout << "\t\t\t\t\t\t\t  Enter Password:  ";
                cin >> password;

                if (password.length() < 6) {
                    cout << "\t\t\t\t\tPassword should be at least 6 characters long. Please try again.\n";
                }
                else if (!g.DigitsInPass(password)) {
                    cout << "\t\t\t\t  Password should contain at least 1 digit to make it strong. Please try again.\n";
                }
                else {
                    break;
                }


            } while (true);

            cout << "\t\t\t\t\t\t\t  Enter your City:  ";
            cin >> city;
            cout << "\t\t\t\t\t   Enter Your Father's name for Security:  ";
            cin >> security;
            g.addUser(name, password, city, security);
            b.insertNode(name, city);
            system("pause");
            break;
        }

        case '2': {

            string name;
            string password;

            cout << "\033[36m\t\t\t\t\t\t\t  Enter username:  ";
            cin >> name;

            if (g.bfs(name)) {
                bool validPassword = false;

                while (!validPassword) {
                    cout << "\t\t\t\t\t\t\t  Enter Password:  ";
                    cin >> password;
                    if (g.passwordChecker(name, password)) {
                        validPassword = true;
                        int choice2;
                        do {
                            system("pause");
                            system("cls");
                            cout << "\033[31m\n\n\n\t\t\t\t\t\t\t    Mini Instagram!\033[0m\n";
                            cout << "\033[36m\t\t\t\t\t\t        +----------------------+\033[0m\n\n";
                            cout << "\n\t\t\t\t\t\t\t  \033[36m1.Send Follow Request\n";
                            cout << "\t\t\t\t\t\t\t  2.Check Follow Requests\n";
                            cout << "\t\t\t\t\t\t\t  3.See Following\n";
                            cout << "\t\t\t\t\t\t\t  4.See Followers\n";
                            cout << "\t\t\t\t\t\t\t  5.Create Post\n";
                            cout << "\t\t\t\t\t\t\t  6.See your News Feed\n";
                            cout << "\t\t\t\t\t\t\t  7.See News Feed of People You Follow\n";
                            cout << "\t\t\t\t\t\t\t  8.Send Message\n";
                            cout << "\t\t\t\t\t\t\t  9.See Inbox Messages\n";
                            cout << "\t\t\t\t\t\t\t  10.Notifications\n";
                            cout << "\t\t\t\t\t\t\t  11.Search User\n";
                            cout << "\t\t\t\t\t\t\t  12.Display All Users\n";
                            cout << "\t\t\t\t\t\t\t  13.See Friend Suggestions\n";
                            cout << "\t\t\t\t\t\t\t  14.See Mutual Friends\n";
                            cout << "\t\t\t\t\t\t\t  15.Logout\n\033[0m";
                            cout << "\033[31m\t\t\t\t\t\t\t  Enter Choice: ";
                            cin >> choice2;
                            cout << "\033[0m";
                            switch (choice2) {
                            case 1: {
                                string followName;
                                g.DisplayNames(name);
                                while (true) {
                                    cout << "\t\t\t\t\t\t  \033[36mEnter the Username to Follow: ";
                                    cin >> followName;

                                    if (g.findVertex(followName) == nullptr) {
                                        cout << "\033[36m\t\t\t\t\t\t No Such Account Exists! Enter a Valid Username.\n";
                                    }
                                    else {
                                        // Exit the loop if a valid username is found
                                        break;
                                    }
                                }
                                if (g.isAlreadyFollowing(name, followName)) {
                                    cout << "\033[36m\t\t\t\t\t\t\t  Friend Request aAlready Sent!!!\n";

                                }
                                else {
                                    g.sendRequest(name, followName);
                                }
                                break;
                            }

                            case 2: {
                                string option;

                                if (g.findVertex(name)->followRequests.IsEmpty()) {
                                    cout << "\033[36m\t\t\t\t\t\t\tNo Follow Requests to Respond to.\n";
                                    break; // Exit the case if there are no requests
                                }

                                g.checkRequest(name);

                                do {
                                    cout << "\t\t\t\t\t  \033[31mDo You Want to Accept the Request? (yes/no/back/bulk): ";
                                    cin >> option;

                                    if (option != "yes" && option != "Yes" && option != "no" && option != "No" && option != "back" && option != "Back" && option != "Bulk" && option != "bulk") {
                                        cout << "\033[36m\t\t\t\t\t\t  Invalid input. Please enter 'yes', 'no', or 'back'.\n";
                                    }
                                } while (option != "yes" && option != "Yes" && option != "no" && option != "No" && option != "back" && option != "Back" && option != "Bulk" && option != "bulk");

                                g.askAccept(name, option);

                                break;
                            }
                            case 3: {
                                g.displayFollowing(name);
                                break;
                            }
                            case 4: {
                                g.displayFollowers(name);
                                break;
                            }
                            case 5: {
                                string post;

                                cin.ignore();
                                cout << "\033[36m\t\t\t\t\t\t\t  Enter a Post: ";
                                getline(cin, post); // Read the post
                                string timest = getTimestampp();
                                g.createPost(name, post, timest); // Create the post
                                break;
                            }
                            case 6: {
                                cout << "\033[36m";
                                g.displayPosts(name);
                                break;
                            }
                            case 7: {
                                cout << "\033[36m";
                                g.displayNewsFeed(name);
                                break;
                            }
                            case 8: {
                                string receiver;
                                string message;
                                bool valid = false;
                                while (!valid) {
                                    cout << "\033[36m\t\t\t\t\t\t   Enter The Name of The User: ";
                                    cin >> receiver;
                                    if (g.findVertex(receiver)) {
                                        valid = true; // Valid username found
                                    }
                                    else {
                                        cout << "\033[36m\t\t\t\t\t\t  Invalid Username. Please Enter a Valid Username.\n";
                                    }
                                }
                                cin.ignore();
                                cout << "\033[36m\t\t\t\t\t\tEnter Message: ";
                                getline(cin, message);
                                
                                g.sendMessage(name, receiver, message);
                                break;
                            }

                            case 9: {
                                string friendName;
                                bool valid = false;
                                while (!valid) {
                                    cout << "\033[36m\t\t\t\t\t\t\t  Enter the Name of The Follower: ";
                                    cin >> friendName;
                                    if (g.findVertex(friendName)) {
                                        valid = true; // Valid username found
                                    }
                                    else {
                                        cout << "\033[36m\t\t\t\t\t\t  Invalid Username. Please Enter a Valid Username.\n";
                                    }
                                }
                                g.displayMessage(name, friendName);
                                break;
                            }
                            case 10: {
                                g.displayNotifications(name);
                                break;
                            }
                            case 11: {
                                string username;
                                cout << "\033[36m\t\t\t\t\t\t  Enter The Username You Want to Search: ";
                                cin >> username;
                                if (b.search(username, b.root) == nullptr) {
                                    cout << "\033[36m\t\t\t\t\t\t\t  User Doesnt Exists on Instagram!!\n";
                                }
                                else {
                                    cout << "\033[36m\t\t\t\t\t\t\t  User Exists on Instagram!!\n";
                                }
                                break;
                            }
                            case 12: {
                                cout << "\033[36m\t\t\t\t\t\t\t  Users: \n";
                                b.displayBSTUsers(b.root);
                                break;
                            }
                            case 13: {
                                g.followSuggestions(name);
                                break;
                            }
                            case 14: {
                                g.MutualFriends(name);
                                break;
                            }
                            case 15: {
                                cout << "\033[36m\t\t\t\t\t\t\t  Logging Out...\n";
                                break;
                            }
                            default: {
                                cout << "\033[36m\t\t\t\t\t\t\t  Enter a Valid Choice!!!\n";
                                break;
                            }
                            }

                            //g.displayVertex(name);
                        } while (choice2 != 15);
                    }
                    else {
                        string choice3;
                        cout << "\t\t\t\t\t\t\t  \033[36mIncorrect Password! Try Again\n";
                        cout << "\t\t\t\tDo You Want to Reset Password? (yes for Resetting, Any Other for Exiting): ";
                        cin >> choice3;
                        if (choice3 == "Yes" || choice3 == "yes") {
                            g.securityQuestion(name);
                        }
                    }
                }
            }
            else {
                cout << "\033[36m\t\t\t\t\t\t\t  No Account with This Username!!!\n";
            }
            system("pause");
            break;
        }

        case '3': {
            cout << "\033[36m\t\t\t\t\t\t\t  Exiting....\n";
            system("pause");
            break;
        }
        default: {
            cout << "\033[36m\t\t\t\t\t\t\t  Invalid Choice!!\n";
            system("pause");
            break;
        }
        }
        system("cls");
    } while (choice != '3');
    cout << "\033[0m";
    system("pause");
    return 0;
}