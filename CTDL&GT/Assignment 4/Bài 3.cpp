#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class NumberLinkedList {
private:
    Node* head;
public:
    NumberLinkedList() : head(nullptr) {}
    void sort() {
        if (head == nullptr || head->next == nullptr)  return;
        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            while (nextNode != nullptr) {
                if (current->data > nextNode->data) {
                    int temp = current->data;
                    current->data = nextNode->data;
                    nextNode->data = temp;
                }
                nextNode = nextNode->next;
            }
            current = current->next;
        }
    }
    void insertSorted(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr || value < head->data) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    NumberLinkedList List;
    List.insertSorted(3);
    List.insertSorted(1);
    List.insertSorted(4);
    List.insertSorted(2);
    cout << "Original List: ";
    List.print();
    List.sort();
    cout << "Sorted List: ";
    List.print();
    return 0;
}
