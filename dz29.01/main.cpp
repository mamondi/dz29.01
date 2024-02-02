#include "func.h"

int main() {
    DoublyLinkedList<int> list1, list2;

    while (true) {
        cout << "\nDoubly Linked List Menu:\n";
        cout << "1. Add to Head (List 1)\n";
        cout << "2. Add to Tail (List 1)\n";
        cout << "3. Delete from Head (List 1)\n";
        cout << "4. Delete from Tail (List 1)\n";
        cout << "5. Show (List 1)\n";
        cout << "6. Clone (List 1)\n";
        cout << "7. Add to Head (List 2)\n";
        cout << "8. Add to Tail (List 2)\n";
        cout << "9. Delete from Head (List 2)\n";
        cout << "10. Delete from Tail (List 2)\n";
        cout << "11. Show (List 2)\n";
        cout << "12. Clone (List 2)\n";
        cout << "13. Concatenate Lists (List 1 + List 2)\n";
        cout << "14. Intersection of Lists (List 1 * List 2)\n";
        cout << "15. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter value to add to head (List 1): ";
            cin >> value;
            list1.AddToHead(value);
            break;
        }
        case 2: {
            int value;
            cout << "Enter value to add to tail (List 1): ";
            cin >> value;
            list1.AddToTail(value);
            break;
        }
        case 3:
            list1.DeleteFromHead();
            break;
        case 4:
            list1.DeleteFromTail();
            break;
        case 5:
            cout << "List 1: ";
            list1.Show();
            break;
        case 6: {
            DoublyLinkedList<int>* cloneList1 = list1.Clone();
            cout << "List 1 Cloned. Showing cloned list:\n";
            cloneList1->Show();
            delete cloneList1;
            break;
        }
        case 7: {
            int value;
            cout << "Enter value to add to head (List 2): ";
            cin >> value;
            list2.AddToHead(value);
            break;
        }
        case 8: {
            int value;
            cout << "Enter value to add to tail (List 2): ";
            cin >> value;
            list2.AddToTail(value);
            break;
        }
        case 9:
            list2.DeleteFromHead();
            break;
        case 10:
            list2.DeleteFromTail();
            break;
        case 11:
            cout << "List 2: ";
            list2.Show();
            break;
        case 12: {
            DoublyLinkedList<int>* cloneList2 = list2.Clone();
            cout << "List 2 Cloned. Showing cloned list:\n";
            cloneList2->Show();
            delete cloneList2;
            break;
        }
        case 13: {
            DoublyLinkedList<int>* concatenatedList = list1 + list2;
            cout << "Lists Concatenated. Showing concatenated list:\n";
            concatenatedList->Show();
            delete concatenatedList;
            break;
        }
        case 14: {
            DoublyLinkedList<int>* intersectionList = list1 * list2;
            cout << "Lists Intersection. Showing intersection list:\n";
            intersectionList->Show();
            delete intersectionList;
            break;
        }
        case 15:
            return 0;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}