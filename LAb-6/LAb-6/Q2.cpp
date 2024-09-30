#include <iostream>
#include<string>
using namespace std;

class Clinic {
public:
	Clinic* next;
	string name;

	string appontment;
	string date_time;


};
class QUEUE {
	Clinic* front;
	Clinic* rear;
public:


	QUEUE() {
		front = rear = nullptr;
	}

	void Enqueue(string name, string appointment, string date_time) {
		Clinic* ptr = new Clinic;
		ptr->name = name;
		ptr->appontment = appointment;
		ptr->date_time = date_time;
		ptr->next = nullptr;
		if (isempty())
		{
			front = rear = ptr;
		}
		else
		{

			rear->next = ptr;

			rear = ptr;
		}


	}
	string Dequeue() {
	
		if (isempty())
		{
			cout << "LIST IS EMPTY!...\n";
			return "  ";
		}
		string data = front->name;
		
		Clinic* temp = front;
		front = front->next;
		delete temp;
		return data;	
	}

	bool isempty()
	{
		if (front == nullptr)
		{
			return true;
		}
		return false;
	}
	void display(){
		Clinic* temp = front;

		while (temp!=nullptr)
		{

			cout  << "name: " << temp->name << " Appointment reason:  " << temp->appontment << endl;;
			temp = temp->next;
		}
		cout << endl;
	}

};

class Doctor {
	string doctorname = "ASAB BILAL";

public:


	void denqueu(QUEUE& obj) {
	
		cout << obj.Dequeue() << " has been dealt with\n";
	}



};
class Patient {
public:


	void enqueu(QUEUE& obj,string s,string v , string t) {

		obj.Enqueue(s, v, t);
	}



};
int main() {

	QUEUE l1;
	Doctor d;
	Patient p;
	d.denqueu(l1);
	p.enqueu(l1, "Travis", "Headache", "2/10/24");
	
	
	p.enqueu(l1,"weekend", "BONE FRACTURUD","2/11/24");
	p.enqueu(l1,"eminem", "DEPRESSION", "2/12/24");
	l1.display();
	d.denqueu(l1);
	l1.display();


	system("pause");

	return 0;

}