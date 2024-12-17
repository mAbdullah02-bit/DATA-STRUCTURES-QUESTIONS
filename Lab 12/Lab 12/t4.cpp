//#include <iostream>
//#include <fstream>
//#include <cassert>
//#include <string>
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
//protected:
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
//    virtual ~HashMap() {
//        delete[] hashArray;
//    }
//};
//
//class QHashMap : public HashMap<string> {
//protected:
//    int getNextCandidateIndex(int key, int i) override {
//        return (key + i * i) % capacity;
//    }
//};
//
//class DHashMap : public HashMap<string> {
//protected:
//    static constexpr int PRIME = 7;
//
//    int getNextCandidateIndex(int key, int i) override {
//        int first_value = key % capacity;
//        int second_value = PRIME - (key % PRIME);
//        return (first_value + i * second_value) % capacity;
//    }
//};
//
//void populateHash(const string& filename, HashMap<string>* hash) {
//    ifstream file(filename);
//    if (!file) {
//        ofstream newFile(filename);
//        newFile << "9 Ali\n98 Bilal\n101 Abdulla\n";
//        newFile.close();
//        file.open(filename);
//    }
//
//    int id;
//    string name;
//    while (file >> id >> name) {
//        hash->insert(id, name);
//    }
//
//    file.close();
//}
//
//int main() {
//    HashMap<string>* map;
//
//    map = new HashMap<string>;
//    populateHash("students.txt", map);
//    cout << *map->get(9) << endl;
//    map->display();
//    map->deleteKey(9);
//    assert(map->get(9) == nullptr);
//    map->display();
//    delete map;
//
//    map = new HashMap<string>;
//    populateHash("students.txt", map);
//    cout << *map->get(98) << endl;
//    map->display();
//    map->deleteKey(98);
//    map->display();
//    assert(map->get(98) == nullptr);
//    delete map;
//
//    map = new HashMap<string>;
//    populateHash("students.txt", map);
//    map->display();
//    cout << *map->get(101) << endl;
//    map->deleteKey(101);
//    map->display();
//    assert(map->get(101) == nullptr);
//    delete map;
//
//    return 0;
//}
