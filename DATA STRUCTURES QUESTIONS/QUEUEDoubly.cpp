//#include<iostream>
//using namespace std;
//
//
//class deque{
//    int* dequeArr;
//    int maxSize, rear, front;
//
//public:
//    deque(int s) {
//        maxSize = s;
//        dequeArr = new int[s];
//        for (int i = 0; i < maxSize; i++)
//        {
//            dequeArr[i] = 0;
//        }
//        rear = front = -1;
//    }
//    bool isEmpty() {
//        if (rear == -1 && front == -1)return true;
//        else return false;
//    }
//    bool isFull(){
//        if ((rear+1)%maxSize==front)
//        {
//            cout << "Queue IS FULL\n"; return true;
//        }
//        return false;
//    }
//
//    void insertFront(int value) {
//        if (!isFull())
//        {
//
//        
//        if (isEmpty())
//        {
//            front = maxSize-1;
//        }
//        else front--;
//
//        dequeArr[front] = value;
//    
//    }
//        else cout << "LIST IS FULL>>>>\n";
//    }
//    void insertBack(int value) {
//        if (!isFull())
//        {
//
//            if (isEmpty())
//            {
//                rear = 0;
//            }
//            else rear++;
//
//            dequeArr[rear] = value;
//        }
//        else cout << "LIST IS FULL>>>>\n";
//    
//    }
//    int removeFront() {
//        if (isEmpty())
//        {
//            cout << "List is empty..\n";
//        }
//        else
//        {
//            int value = dequeArr[front];
//            dequeArr[front] = 0;
//            front++;
//            return value;
//        }
//
//    }
//    int removeBack() {
//        if (isEmpty())
//        {
//            cout << "List is empty..\n";
//        }
//        else
//        {
//            int value = dequeArr[rear];
//            dequeArr[rear] = 0;
//            rear--;
//            return value;
//        }
//    }
//    void display() {
//    
//        for (int i = 0; i < 10; i++)
//        {
//            cout<<dequeArr[i] << "  ";
//        }
//      
//        cout << endl;
//    
//    }
//    ~deque() {
//        delete [] dequeArr;
//    }
//};
//
//int main(){
//
//    deque q(10);
//    q.insertFront(1);
//    q.display();
//    q.insertFront(2);
//    q.display();
//    q.insertBack(5);
//    q.display();
//    q.insertBack(6);
//    q.display();
//    q.insertFront(3);
//    q.display();
//    q.insertFront(4);
//    q.display();
//    q.insertBack(7);
//    q.display();
//    q.insertBack(8);
//    
//    q.display();
//    q.display();
//    q.insertBack(7);
//    q.display();
//    q.insertBack(8);
//    q.display();
//    q.insertBack(7);
//    q.display();
//    q.insertBack(8);
//    q.display();
//    q.removeFront();
//    q.display();
//    q.removeFront();
//    q.display();
//    q.removeBack();
//    q.display();
//    q.removeBack();
//    q.display();
//
//    return 0;
//}