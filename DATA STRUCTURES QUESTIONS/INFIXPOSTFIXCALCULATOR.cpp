//#include<iostream>
//#include<string>
//
//using namespace std;
//
//struct Node {
//
//	Node* next;
//	char data;
//	Node(char d) {
//		data = d;
//		next = nullptr;
//	}
//};
//
//class Stack {
//
//	Node* top;
//
//public:
//
//	Stack() {
//		top = nullptr;
//	}
//
//	bool isEmpty() {
//		return (top == nullptr);
//	}
//
//	void push(char d) {
//
//		Node* n = new Node(d);
//		n->next = top;
//		top = n;
//	}
//
//	char pop() {
//
//		if (isEmpty()) {
//			cout << "Empty!!";
//			return '\0';
//		}
//
//		Node* temp = top;
//		char val;
//
//		val = top->data;
//		top = top->next;
//
//		delete temp;
//		return val;
//	}
//
//	bool isOp(char c) {
//		return (c >= '0' && c <= '9');
//	}
//
//	char peek() {
//		if (!isEmpty()) {
//			return top->data;
//		}
//
//		return '\0';
//	}
//
//	int prec(char op) {
//		if (op == '%') {
//			return 2;
//		}
//
//		else if (op == '*' || op == '/') {
//			return 2;
//		}
//
//		else if (op == '+' || op == '-') {
//			return 1;
//		}
//
//		else {
//			return 0;
//		}
//
//	}
//
//	string inf_to_post(string s) {
//
//		string post;
//
//		for (int i = 0; i < s.length(); i++) {
//			char c = s[i];
//
//			if (c == ' ') {
//				continue;
//			}
//
//			else if (isOp(c)) {
//
//				string st;
//
//				while (i < s.length() && isOp(s[i])) {
//					st += s[i];
//					i++;
//				}
//
//				post += st;
//				post += ' ';
//				i--;
//
//			}
//
//			else if (c == '(') {
//				push(c);
//			}
//
//			else if (c == ')') {
//
//				while (!isEmpty() && peek() != '(') {
//					post += pop();
//					post += ' ';
//				}
//
//				if (!isEmpty()) {
//					pop();
//				}
//
//			}
//
//			else {
//
//				while (!isEmpty() && prec(peek()) >= prec(c)) {
//					post += pop();
//					post += ' ';
//				}
//
//				push(c);
//
//			}
//			cout << "Stack: ";
//			Node* current = top;
//
//			while (current != nullptr) {
//				cout << current->data << " ";
//				current = current->next;
//			}
//
//			cout << endl;
//
//		}
//		while (!isEmpty()) {
//			post += pop();
//			post += ' ';
//		}
//
//		return post;
//	}
//
//	string revStr(string s) {
//
//		Stack stk;
//		for (int i = 0; i < s.length(); i++) {
//			stk.push(s[i]);
//		}
//
//		string str;
//		while (!stk.isEmpty()) {
//			str += stk.pop();
//		}
//
//		return str;
//	}
//
//	string inf_to_pre(string s) {
//		string st;
//		string rev = revStr(s);
//
//		for (int i = 0; i < rev.length(); i++) {
//			if (rev[i] == '(') {
//				rev[i] = ')';
//			}
//
//			else if (rev[i] == ')') {
//				rev[i] = '(';
//			}
//
//		}
//
//		st = inf_to_post(rev);
//		string prefix = revStr(st);
//		return prefix;
//
//	}
//	int evaluate(string s) {
//		int op1, op2, res = 0;
//		Stack stk;
//
//		for (int i = 0; i < s.length(); i++) {
//			char c = s[i];
//			if (c == ' ') {
//				continue;
//			}
//
//			else if (isOp(c)) {
//				int num = 0;
//				while (i < s.length() && isOp(s[i])) {
//					num = num * 10 + (s[i] - '0');
//					i++;
//				}
//
//				stk.push(num);
//				i--;
//			}
//
//			else if (c == '+') {
//
//				op2 = stk.pop();
//				op1 = stk.pop();
//				res = op1 + op2;
//				stk.push(res);
//			}
//
//			else if (c == '-') {
//
//				op2 = stk.pop();
//				op1 = stk.pop();
//				res = op1 - op2;
//				stk.push(res);
//			}
//
//			else if (c == '*') {
//
//				op2 = stk.pop();
//				op1 = stk.pop();
//				res = op1 * op2;
//				stk.push(res);
//			}
//
//			else if (c == '/') {
//
//				op2 = stk.pop();
//				op1 = stk.pop();
//				res = op1 / op2;
//				stk.push(res);
//			}
//
//			else if (c == '%') {
//
//				op2 = stk.pop();
//				op1 = stk.pop();
//				res = op1 % op2;
//				stk.push(res);
//			}
//		}
//
//		int final = stk.pop();
//		return final;
//
//
//	}
//	~Stack() {
//		while (!isEmpty()) {
//			pop();
//		}
//		
//	}
//
//};
//int main() {
//
//	Stack s;
//	string str;
//
//	int choice;
//
//	do {
//
//	
//		cout << "Enter choice:\n";
//		cout << "1. Postfix \n";
//		cout << "2. Prefix\n";
//		cout << "0. Exit\n";
//
//		cin >> choice;
//
//		if (choice != 3) {
//			cout << "Input Exprsion: \n";
//			cin.ignore();
//			getline(cin, str);
//		}
//
//		switch (choice) {
//		case 1:
//		{
//
//			string postfix = s.inf_to_post(str);
//			cout << "Postfix: " << postfix << endl;
//			cout << "Result:" << s.evaluate(postfix) << endl;
//			break;
//		}
//
//		case 2:
//		{
//			string prefix = s.inf_to_pre(str);
//			string postfix = s.inf_to_post(str);
//			cout << "Prefix: " << prefix << endl;
//			cout << "Result: " << s.evaluate(postfix)<<"\n";
//			break;
//		}
//
//
//		default:
//
//			cout << "INVALIDE CHOICE ...!\n";
//			break;
//		}
//
//	} while (choice != 0);
//
//	system("pause");
//	return 0;
//}