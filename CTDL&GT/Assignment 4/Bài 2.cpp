#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class NumberLinkedList {
public:
    Node* head;
    NumberLinkedList() : head(nullptr) {}
    void merge(NumberLinkedList& p1, NumberLinkedList& p2) {
        Node* mergedList = nullptr;
        Node* current = nullptr;
        Node* currentP1 = p1.head;
        Node* currentP2 = p2.head;
        while (currentP1 != nullptr || currentP2 != nullptr) {
            Node* newNode;
            if (currentP1 == nullptr || (currentP2 != nullptr && currentP2->data < currentP1->data)) {
                newNode = new Node(currentP2->data);
                currentP2 = currentP2->next;
            } else {
                newNode = new Node(currentP1->data);
                currentP1 = currentP1->next;
            }
            if (mergedList == nullptr) {
                mergedList = newNode;
                current = newNode;
            } else {
                current->next = newNode;
                current = newNode;
            }
        }
        head = mergedList;
    }
    void concatenate(NumberLinkedList& p1, NumberLinkedList& p2) {
        if (p1.head == nullptr) {
            head = p2.head;
        } else {
            head = p1.head;
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = p2.head;
        }
    }
    bool equal(NumberLinkedList& p1, NumberLinkedList& p2) {
        Node* currentP1 = p1.head;
        Node* currentP2 = p2.head;
        while (currentP1 != nullptr && currentP2 != nullptr) {
            if (currentP1->data != currentP2->data) {
                return false;
            }
            currentP1 = currentP1->next;
            currentP2 = currentP2->next;
        }
        return currentP1 == nullptr && currentP2 == nullptr;
    }
};

int main() {
    NumberLinkedList list1, list2, mergedList, concatenatedList;
    list1.head = new Node(1);
    list1.head->next = new Node(3);
    list1.head->next->next = new Node(5);
    list2.head = new Node(2);
    list2.head->next = new Node(4);
    list2.head->next->next = new Node(6);
    mergedList.merge(list1, list2);
    concatenatedList.concatenate(list1, list2);
    bool areEqual = mergedList.equal(list1, list2);
    cout << "Merged List: ";
    Node* currentMerged = mergedList.head;
    while (currentMerged != nullptr) {
        cout << currentMerged->data << " ";
        currentMerged = currentMerged->next;
    }
    cout << endl;
    cout << "Concatenated List: ";
    Node* currentConcatenated = concatenatedList.head;
    while (currentConcatenated != nullptr) {
        cout << currentConcatenated->data << " ";
        currentConcatenated = currentConcatenated->next;
    }
    cout << endl;
    cout << "Are the lists equal? " << (areEqual ? "Yes" : "No") << endl;
    return 0;
}
