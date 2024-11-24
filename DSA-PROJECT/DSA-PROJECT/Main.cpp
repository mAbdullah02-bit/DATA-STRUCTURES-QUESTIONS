//#include <iostream>
//#include <iomanip> // For formatting
//#include <string>
//#include"Graphs.cpp"
//
//using namespace std;
//
//// ANSI escape codes for colors
//const string RESET = "\033[0m";
//const string RED = "\033[31m";
//const string GREEN = "\033[32m";
//const string YELLOW = "\033[33m";
//const string BLUE = "\033[34m";
//const string MAGENTA = "\033[35m";
//const string CYAN = "\033[36m";
//const string WHITE = "\033[37m";
//const string BOLD = "\033[1m";
//
//void displayMenu() {
//    cout << "\n";
//    cout << BOLD << CYAN << "*******************************************" << RESET << "\n";
//    cout << BOLD << MAGENTA << "*                                         *" << RESET << "\n";
//    cout << BOLD << MAGENTA << "*             MINI INSTAGRAM              *" << RESET << "\n";
//    cout << BOLD << MAGENTA << "*         ~ Social Made Simple ~          *" << RESET << "\n";
//    cout << BOLD << MAGENTA << "*                                         *" << RESET << "\n";
//    cout << BOLD << CYAN << "*******************************************" << RESET << "\n";
//    cout << "\n" << BOLD << WHITE << "Choose an option:\n" << RESET;
//    cout << YELLOW << "-------------------------------------------" << RESET << "\n";
//    cout << GREEN << "1. " << WHITE << "Sign Up\n";
//    cout << GREEN << "2. " << WHITE << "Log In\n";
//    cout << GREEN << "3. " << WHITE << "Log Out\n";
//    cout << GREEN << "4. " << WHITE << "Send Follow Request\n";
//    cout << GREEN << "5. " << WHITE << "Cancel or Accept Requests\n";
//    cout << GREEN << "6. " << WHITE << "View Posts (Timeline)\n";
//    cout << GREEN << "7. " << WHITE << "View Notifications\n";
//    cout << GREEN << "8. " << WHITE << "Messaging\n";
//    cout << GREEN << "9. " << WHITE << "Search Users\n";
//    cout << GREEN << "10. " << WHITE << "View Followers List\n";
//    cout << GREEN << "11. " << WHITE << "View Your Newsfeed\n";
//    cout << GREEN << "0. " << WHITE << "Exit\n";
//    cout << YELLOW << "-------------------------------------------" << RESET << "\n";
//    cout << WHITE << "Enter your choice: " << RESET;
//}
//
//int main() {
//    int choice;
//    Graph insta;
//    do {
//        displayMenu();
//        cin >> choice;
//
//        // Clear screen for a clean menu look after each interaction
//
//        system("cls"); // Use "system('clear')" for Linux/Mac
//        switch (choice) {
//        case 1:
//            cout << GREEN << "\n[Sign Up Functionality]\n" << RESET;
//            // Call Sign Up function here
//            break;
//        case 2:
//            cout << GREEN << "\n[Log In Functionality]\n" << RESET;
//            // Call Log In function here
//            break;
//        case 3:
//            cout << GREEN << "\n[Log Out Functionality]\n" << RESET;
//            // Call Log Out function here
//            break;
//        case 4:
//            cout << GREEN << "\n[Send Follow Request Functionality]\n" << RESET;
//            // Call Follow Request function here
//            break;
//        case 5:
//            cout << GREEN << "\n[Cancel or Accept Requests Functionality]\n" << RESET;
//            // Call Cancel/Accept Requests function here
//            break;
//        case 6:
//            cout << GREEN << "\n[View Posts (Timeline) Functionality]\n" << RESET;
//            // Call Posts/Timeline function here
//            break;
//        case 7:
//            cout << GREEN << "\n[View Notifications Functionality]\n" << RESET;
//            // Call Notifications function here
//            break;
//        case 8:
//            cout << GREEN << "\n[Messaging Functionality]\n" << RESET;
//            // Call Messaging function here
//            break;
//        case 9:
//            cout << GREEN << "\n[Search Users Functionality]\n" << RESET;
//            // Call Search Users function here
//            break;
//        case 10:
//            cout << GREEN << "\n[View Followers List Functionality]\n" << RESET;
//            // Call Followers List function here
//            break;
//        case 11:
//            cout << GREEN << "\n[View Your Newsfeed Functionality]\n" << RESET;
//            // Call Newsfeed function here
//            break;
//        case 0:
//            cout << CYAN << "\nThank you for using Mini Instagram. Goodbye!\n" << RESET;
//            break;
//        default:
//            cout << RED << "\nInvalid choice. Please try again.\n" << RESET;
//        }
//    } while (choice != 0);
// system("pause");
//    return 0;
//}
