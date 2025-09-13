#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class NumberSet {
private:
    Node* head;
public:
    NumberSet() : head(nullptr) {}
    bool isSet() {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        unordered_set<int> uniqueElements;
        Node* current = head;
        while (current != nullptr) {
            if (uniqueElements.find(current->data) != uniqueElements.end()) {
                return false;
            }
            uniqueElements.insert(current->data);
            current = current->next;
        }
        return true;
    }
    bool isSubset(NumberSet& otherSet) {
        Node* current = head;
        while (current != nullptr) {
            if (!otherSet.contains(current->data)) {
                return false;
            }
            current = current->next;
        }

        return true;
    }
    NumberSet unionSets(NumberSet& otherSet) {
        NumberSet result = *this; 
        Node* current = otherSet.head;
        while (current != nullptr) {
            if (!result.contains(current->data)) {
                result.insert(current->data);
            }

            current = current->next;
        }

        return result;
    }
    NumberSet intersectSets(NumberSet& otherSet) {
        NumberSet result;
        Node* current = head;
        while (current != nullptr) {
            if (otherSet.contains(current->data)) {
                result.insert(current->data);
            }

            current = current->next;
        }

        return result;
    }
    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    bool contains(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }

            current = current->next;
        }

        return false;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    NumberSet set1, set2, unionSet, intersectSet;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set2.insert(2);
    set2.insert(3);
    set2.insert(4);
    cout << "Set 1: ";
    set1.display();
    cout << "Set 2: ";
    set2.display();
    bool isSet1 = set1.isSet();
    cout << "Is Set 1 a set? " << (isSet1 ? "Yes" : "No") << endl;
    bool isSet2 = set2.isSet();
    cout << "Is Set 2 a set? " << (isSet2 ? "Yes" : "No") << endl;
    bool isSubset = set2.isSubset(set1);
    cout << "Is Set 2 a subset of Set 1? " << (isSubset ? "Yes" : "No") << endl;
    unionSet = set1.unionSets(set2);
    cout << "Union of Set 1 and Set 2: ";
    unionSet.display();
    intersectSet = set1.intersectSets(set2);
    cout << "Intersection of Set 1 and Set 2: ";
    intersectSet.display();

    return 0;
}
