#include <bits/stdc++.h>
using namespace std;

class NumberLinkedList {
private:
    struct ListNode {
        int value;
        struct ListNode* next;
    };
    ListNode* head;

public:
    NumberLinkedList() {
        head = nullptr;
    }
    ~NumberLinkedList() {
        while (!empty()) {
            deletelast();
        }
    }
    void insertfirst(int x) {
        // Create a new ListNode with the given value
        ListNode* newNode = new ListNode;
        newNode->value = x;
        // Set the next of the new node to point to the current head
        newNode->next = head;
        // Update the head to point to the new node
        head = newNode;
    }
    bool empty() {
        return head == nullptr;
    }
    void insertlast(int x) {
        // Create a new ListNode with the given value
        ListNode* newNode = new ListNode;
        newNode->value = x;
        newNode->next = nullptr;
        if (empty()) {
            // If the list is empty, set the new node as the head
            head = newNode;
        } else {
            // Otherwise, traverse the list to find the last node
            ListNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            // Append the new node to the last node
            current->next = newNode;
        }
    }
    void deletefirst() {
        if (!empty()) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void deletelast() {
        if (!empty()) {
            if (head->next == nullptr) {
                // If there's only one element in the list, delete it
                delete head;
                head = nullptr;
            } else {
                // Otherwise, traverse the list to find the second-to-last node
                ListNode* current = head;
                while (current->next->next != nullptr) {
                    current = current->next;
                }
                // Delete the last node
                delete current->next;
                current->next = nullptr;
            }
        }
    }
    int length() {
        int cnt = 0;
        ListNode* current = head;
        while (current != nullptr) {
            cnt++;
            current = current->next;
        }
        return cnt;
    }
    void deletest(int x) {
        if (!empty()) {
            if (head->value == x) {
                // If the value to delete is in the head node
                deletefirst();
            } else {
                ListNode* current = head;
                while (current->next != nullptr && current->next->value != x) {
                    current = current->next;
                }
                if (current->next != nullptr) {
                    // Found the value, delete the node
                    ListNode* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                }
            }
        }
    }
    void displaylist() const {
        ListNode* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    NumberLinkedList list;
    list.insertlast(1);
    list.insertlast(2);
    list.insertlast(3);
    list.displaylist(); 
    list.insertfirst(0);
    list.displaylist(); 
    list.deletelast();
    list.displaylist();
    list.deletest(1);
    list.displaylist(); 
    list.pop();
    list.displaylist();
    list.push(5);
    list.displaylist();
    return 0;
}
