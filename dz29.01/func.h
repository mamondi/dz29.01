#include "class.h" 

template <typename T>
int Array<T>::GetSize() const {
    return size;
}

template <typename T>
void Array<T>::SetSize(int newSize, int newGrow) {
    if (newSize <= size) {
       
        while (size > newSize) {
            RemoveAt(size - 1);
        }
    }
    else {
        int additionalSize = newSize - size;
        int newSizeWithGrow = size + (additionalSize / newGrow + (additionalSize % newGrow != 0)) * newGrow;
        SetSize(newSizeWithGrow);
    }
}

template <typename T>
int Array<T>::GetUpperBound() const {
    return size - 1;
}

template <typename T>
bool Array<T>::IsEmpty() const {
    return size == 0;
}

template <typename T>
void Array<T>::FreeExtra() {
    SetSize(size, grow);
}

template <typename T>
void Array<T>::RemoveAll() {
    while (!IsEmpty()) {
        RemoveAt(size - 1);
    }
}

template <typename T>
T Array<T>::GetAt(int index) const {
    if (index >= 0 && index < size) {
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }
    else {
        cerr << "Index out of bounds." << endl;
        exit(1);
    }
}

template <typename T>
void Array<T>::SetAt(int index, const T& value) {
    if (index >= 0 && index < size) {
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        current->data = value;
    }
    else {
        cerr << "Index out of bounds." << endl;
        exit(1);
    }
}

template <typename T>
T& Array<T>::operator[](int index) {
    if (index >= 0 && index < size) {
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }
    else {
        cerr << "Index out of bounds." << endl;
        exit(1);
    }
}

template <typename T>
const T& Array<T>::operator[](int index) const {
    if (index >= 0 && index < size) {
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }
    else {
        cerr << "Index out of bounds." << endl;
        exit(1);
    }
}

template <typename T>
void Array<T>::Add(const T& value) {
    SetSize(size + 1, grow);
    tail->data = value;
    tail = tail->next;
}

template <typename T>
Array<T>* Array<T>::Append(const Array<T>& other) {
    Array<T>* result = new Array<T>();

    Node* current = head;
    while (current) {
        result->Add(current->data);
        current = current->next;
    }

    current = other.head;
    while (current) {
        result->Add(current->data);
        current = current->next;
    }

    return result;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        SetSize(other.size, other.grow);

        Node* currentThis = head;
        Node* currentOther = other.head;

        while (currentOther) {
            currentThis->data = currentOther->data;

            currentThis = currentThis->next;
            currentOther = currentOther->next;
        }
    }
    return *this;
}

template <typename T>
T* Array<T>::GetData() const {
    T* data = new T[size];
    Node* current = head;
    for (int i = 0; i < size; ++i) {
        data[i] = current->data;
        current = current->next;
    }
    return data;
}

template <typename T>
void Array<T>::InsertAt(int index, const T& value) {
    if (index >= 0 && index <= size) {
        if (index == size) {
            Add(value);
        }
        else if (index == 0) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            ++size;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }

            Node* newNode = new Node(value);
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
            ++size;
        }
    }
    else {
        cerr << "Index out of bounds." << endl;
        exit(1);
    }
}

template <typename T>
void Array<T>::RemoveAt(int index) {
    if (index >= 0 && index < size) {
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        if (current->prev) {
            current->prev->next = current->next;
        }
        else {
            head = current->next;
        }

        if (current->next) {
            current->next->prev = current->prev;
        }
        else {
            tail = current->prev;
        }

        delete current;
        --size;
    }
    else {
        cerr << "Index out of bounds." << endl;
        exit(1);
    }
}
