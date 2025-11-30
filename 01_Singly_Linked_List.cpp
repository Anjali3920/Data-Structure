#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val = 0) {
        data = val;
        next = nullptr;
    }
};

Node* head = nullptr;

void insertAtHead(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

Node* traverse(int n) {
    if (n <= 0) return nullptr;
    
    Node* temp = head;
    for (int i = 1; i < n && temp != nullptr; i++) {
        temp = temp->next;
    }
    return temp;
}

void insertInBetween(int value, int i) {
    if (i <= 0) {
        cout << "Invalid input" << endl;
        return;
    }
    
    if (i == 1) {
        insertAtHead(value);
        return;
    }
    
    Node* temp = traverse(i - 1);
    if (temp == nullptr) {
        cout << "Position out of bound" << endl;
        return;
    }
    
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteHead() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteInBetween(int i) {
    if (i <= 0) {
        cout << "Invalid position" << endl;
        return;
    }
    
    if (i == 1) {
        deleteHead();
        return;
    }
    
    Node* prev = traverse(i - 1);
    if (prev == nullptr || prev->next == nullptr) {
        cout << "Position " << i << " does not exist" << endl;
        return;
    }
    
    Node* temp = prev->next;
    prev->next = temp->next;
    delete temp;
}

void display() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

void defaultList() {
    head = nullptr;
    insertAtHead(5);
    insertAtHead(4);
    insertAtHead(3);
    insertAtHead(2);
    insertAtHead(1);
    
    cout << "Default Singly linked list: " << endl;
    display();
}

Node* search(int n) {
    Node* temp = head;
    
    while (temp != nullptr) {
        if (temp->data == n) {
            cout << "Pointer Of '" << n << "' is " << temp << endl;
            return temp;
        }
        temp = temp->next;
    }
    
    cout << "No Match Found" << endl;
    return nullptr;
}

void reverse() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
    cout << "List reversed successfully" << endl;
}

void choice() {
    int n;
    cout << "\nChoose one of the Following Options" << endl;
    cout << "1. Insert at Head" << endl;
    cout << "2. Insert at ith position" << endl;
    cout << "3. Delete at Head" << endl;
    cout << "4. Delete at ith position" << endl;
    cout << "5. Search for an element" << endl;
    cout << "6. Reverse the Linked List" << endl;
    cin >> n;
    
    if (n == 1) {
        int x;
        cout << "Enter the element to insert at Head: ";
        cin >> x;
        insertAtHead(x);
    }
    else if (n == 2) {
        int x, i;
        cout << "Enter the element to insert: ";
        cin >> x;
        cout << "Enter the Position: ";
        cin >> i;
        insertInBetween(x, i);
    }
    else if (n == 3) {
        deleteHead();
        cout << "Element at head deleted" << endl;
    }
    else if (n == 4) {
        int i;
        cout << "Enter the Position to delete: ";
        cin >> i;
        deleteInBetween(i);
    }
    else if (n == 5) {
        int x;
        cout << "Enter the element to search: ";
        cin >> x;
        search(x);
    }
    else if (n == 6) {
        reverse();
    }
    else {
        cout << "Invalid Option" << endl;
    }
}

int main() {
    cout << "**********************************************************************************" << endl;
    defaultList();
    cout << "**********************************************************************************" << endl;
    
    choice();
    
    cout << "Singly linked list: ";
    display();
    cout << endl;
    
    return 0;
}

