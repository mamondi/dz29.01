#include "class.h"

using namespace std;

int main() {
    DoublyLinkedList<int> myLinkedList;

    while (true) {
        cout << "\nDoubly Linked List Menu:\n";
        cout << "1. Add to Head\n";
        cout << "2. Add to Tail\n";
        cout << "3. Delete from Head\n";
        cout << "4. Delete from Tail\n";
        cout << "5. Delete All\n";
        cout << "6. Show\n";
        cout << "7. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter value to add to head: ";
            cin >> value;
            myLinkedList.AddToHead(value);
            break;
        }
        case 2: {
            int value;
            cout << "Enter value to add to tail: ";
            cin >> value;
            myLinkedList.AddToTail(value);
            break;
        }
        case 3:
            myLinkedList.DeleteFromHead();
            break;
        case 4:
            myLinkedList.DeleteFromTail();
            break;
        case 5:
            myLinkedList.DeleteAll();
            break;
        case 6:
            myLinkedList.Show();
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}