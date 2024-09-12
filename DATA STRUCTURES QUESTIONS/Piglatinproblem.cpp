#include<iostream>
using namespace std;

class node {
public:
    char ch;
    node* next;
    node* prev;

    node(char c) {
        ch = c;
        next = nullptr;
        prev = nullptr;
    }
};

class doubly {
    node* head;
public:
    doubly() {
        head = nullptr;
    }

   
    void create_from_string(const string& str) {
        for (char c : str) {
            insert_at_end(c);
        }
    }

 
    void insert_at_end(char ch) {
        node* ptr = new node(ch);
        if (head == nullptr) {
            head = ptr;
            head->next = head;
            head->prev = head;
        }
        else {
            node* last = head->prev;
            last->next = ptr;
            ptr->prev = last;
            ptr->next = head;
            head->prev = ptr;
        }
    }

    void rotate() {
    
    
        if (head==nullptr)
        {
            cout << "EMPTY LSIT!...\n";
                    }
        else
        {

            head=head->next;

        }
    
    
    
    
    }
    void transformpiglating() {
    
        if (head->ch == 'a' || head->ch == 'e' || head->ch == 'i' || head->ch == 'o' || head->ch == 'u'
            || head->ch == 'A' || head->ch == 'E' || head->ch == 'I' || head->ch == 'O' || head->ch == 'U' || head->ch == 'y' || head->ch == 'Y')
        {
            create_from_string("-way");
            return;
        }
        else {
            insert_at_end('-');
            node* temp = head;
            do
            {
                if (head->ch == 'a' || head->ch == 'e' || head->ch == 'i' || head->ch == 'o' || head->ch == 'u'
                    || head->ch == 'A' || head->ch == 'E' || head->ch == 'I' || head->ch == 'O' || head->ch == 'U' || head->ch == 'y' || head->ch == 'Y')
                    break;

                rotate();
            } while (temp!=head);
            if (!(head->ch == 'a' || head->ch == 'e' || head->ch == 'i' || head->ch == 'o' || head->ch == 'u'
                || head->ch == 'A' || head->ch == 'E' || head->ch == 'I' || head->ch == 'O' || head->ch == 'U' || head->ch == 'y' || head->ch == 'Y'))
            {
                create_from_string("way");
            }else
            create_from_string("ay");

        
            return;
    
        }
        create_from_string("-way");
    
    }
    void display_as_string() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        node* temp = head;
        string result;
        do {
            result += temp->ch;
            temp = temp->next;
        } while (temp != head);
        cout << "String from linked list: " << result << endl;
    }
};

int main() {
    doubly obj;
    string str;

    cout << "Enter a string: ";
    cin >> str;

    obj.create_from_string(str); 
    obj.display_as_string(); 
    obj.transformpiglating();
    obj.display_as_string();
    return 0;
}
