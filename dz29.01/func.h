
#include "class.h"

using namespace std;

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    DeleteAll();
}

template <typename T>
void DoublyLinkedList<T>::AddToHead(const T& value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::AddToTail(const T& value) {
    Node* newNode = new Node(value);
    if (!tail) {
        head = tail = newNode;
    }
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
DoublyLinkedList<T>* DoublyLinkedList<T>::Clone() {
    DoublyLinkedList<T>* cloneList = new DoublyLinkedList<T>();

    Node* current = head;
    while (current) {
        cloneList->AddToTail(current->data);
        current = current->next;
    }

    return cloneList;
}

template <typename T>
DoublyLinkedList<T>* DoublyLinkedList<T>::operator+(const DoublyLinkedList<T>& other) {
    DoublyLinkedList<T>* result = this->Clone();

    Node* currentOther = other.head;
    while (currentOther) {
        result->AddToTail(currentOther->data);
        currentOther = currentOther->next;
    }

    return result;
}

template <typename T>
DoublyLinkedList<T>* DoublyLinkedList<T>::operator*(const DoublyLinkedList<T>& other) {
    DoublyLinkedList<T>* result = new DoublyLinkedList<T>();

    Node* current = head;
    while (current) {
        if (other.Search(current->data) != -1) {
            result->AddToTail(current->data);
        }
        current = current->next;
    }

    return result;
}
