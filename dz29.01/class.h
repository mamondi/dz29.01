#include <iostream>

template <typename T>
class Array {
private:
    class Node {
    public:
        T data;
        Node* next;
        Node* prev;
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;
    int grow;

public:
    Array();
    ~Array();

    int GetSize() const;
    void SetSize(int size, int grow = 1);
    int GetUpperBound() const;
    bool IsEmpty() const;
    void FreeExtra();
    void RemoveAll();
    T GetAt(int index) const;
    void SetAt(int index, const T& value);
    T& operator[](int index);
    const T& operator[](int index) const;
    void Add(const T& value);
    Array<T>* Append(const Array<T>& other);
    Array<T>& operator=(const Array<T>& other);
    T* GetData() const;
    void InsertAt(int index, const T& value);
    void RemoveAt(int index);
};