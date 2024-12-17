//#include <iostream>
//#include <cassert>
//using namespace std;
//
//template <class v>
//struct HashItem {
//    int key;
//    v value;
//    short status;
//
//    HashItem() : key(-1), value(v()), status(0) {}
//};
//
//template <class v>
//class HashMap {
//private:
//    HashItem<v>* hashArray;
//    int capacity;
//    int currentElements;
//
//    virtual int getNextCandidateIndex(int key, int i) {
//        return (key + i) % capacity;
//    }
//
//public:
//    HashMap() : capacity(10), currentElements(0) {
//        hashArray = new HashItem<v>[capacity];
//    }
//
//    HashMap(int const capacity) : capacity(capacity), currentElements(0) {
//        if (capacity < 1) {
//            assert("Error: Capacity must be at least 1");
//        }
//        hashArray = new HashItem<v>[capacity];
//    }
//
//    void insert(int const key, v const value) {
//        int index = key % capacity;
//
//        if ((currentElements * 1.0 / capacity) >= 0.75) {
//            doubleCapacity();
//        }
//
//        for (int i = 0; i < capacity; i++) {
//            int candidateIndex = getNextCandidateIndex(key, i);
//            if (hashArray[candidateIndex].status != 2) {
//                hashArray[candidateIndex].key = key;
//                hashArray[candidateIndex].value = value;
//                hashArray[candidateIndex].status = 2;
//                currentElements++;
//               
//                return;
//            }
//        }
//    }
//
//    void doubleCapacity() {
//        int oldCapacity = capacity;
//        capacity *= 2;
//        HashItem<v>* newHashArray = new HashItem<v>[capacity];
//
//        for (int i = 0; i < oldCapacity; i++) {
//            if (hashArray[i].status == 2) {
//                int index = hashArray[i].key % capacity;
//                for (int j = 0; j < capacity; j++) {
//                    int candidateIndex = getNextCandidateIndex(hashArray[i].key, j);
//                    if (newHashArray[candidateIndex].status != 2) {
//                        newHashArray[candidateIndex] = hashArray[i];
//                        break;
//                    }
//                }
//            }
//        }
//
//        delete[] hashArray;
//        hashArray = newHashArray;
//    }
//
//    bool deleteKey(int const key) {
//        for (int i = 0; i < capacity; i++) {
//            if (hashArray[i].status == 2 && hashArray[i].key == key) {
//                hashArray[i].status = 1;
//                currentElements--;
//                
//                return true;
//            }
//        }
//        return false;
//    }
//
//    v* get(int const key) const {
//        for (int i = 0; i < capacity; i++) {
//            if (hashArray[i].status == 2 && hashArray[i].key == key) {
//                return &hashArray[i].value;
//            }
//        }
//        return nullptr;
//    }
//
//    void display() const {
//        cout << "Hash Table: \n";
//        for (int i = 0; i < capacity; i++) {
//            if (hashArray[i].status == 2) {
//                cout << "Index " << i << ": Key=" << hashArray[i].key << ", Value=" << hashArray[i].value << endl;
//            }
//            else if (hashArray[i].status == 1) {
//                cout << "Index " << i << ": [Deleted]" << endl;
//            }
//            else {
//                cout << "Index " << i << ": [Empty]" << endl;
//            }
//        }
//        cout << endl;
//    }
//
//    ~HashMap() {
//        delete[] hashArray;
//    }
//};
//
//int main() {
//    HashMap<string> map;
//
//    map.insert(1, "one");
//    map.insert(2, "two");
//    map.insert(3, "three");
//    map.display();
//    map.insert(12, "collision-one");
//    map.insert(22, "collision-two");
//    map.insert(32, "collision-three");
//
//    map.display();
//    if (map.get(1)) cout << *map.get(1) << endl;
//    if (map.get(2)) cout << *map.get(2) << endl;
//    if (map.get(3)) cout << *map.get(3) << endl;
//    if (map.get(12)) cout << *map.get(12) << endl;
//    if (map.get(22)) cout << *map.get(22) << endl;
//    if (map.get(32)) cout << *map.get(32) << endl;
//
//    map.deleteKey(2);
//    map.display();
//
//    if (!map.get(2)) cout << "key 2 deleted" << endl;
//
//    return 0;
//}
