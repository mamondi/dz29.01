#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
    class Node{
    public:

        T data;
        Node* prev;
        Node* next;
        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void AddToHead(const T& value);
    void AddToTail(const T& value);
    void DeleteFromHead();
    void DeleteFromTail();
    void DeleteAll();
    void Show();
    void InsertAtPosition(const T& value, int position);
    void DeleteAtPosition(int position);
    int Search(const T& value);
    int Replace(const T& oldValue, const T& newValue);
    void Reverse();

    DoublyLinkedList<T>* Clone();
    DoublyLinkedList<T>* operator+(const DoublyLinkedList<T>& other);
    DoublyLinkedList<T>* operator*(const DoublyLinkedList<T>& other);
};