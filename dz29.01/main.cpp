#include "func.h"

using namespace std;

int main() {
    Array<int> arr;

    while (true) {
        cout << "\nArray Menu:\n";
        cout << "1. Get Size\n";
        cout << "2. Set Size\n";
        cout << "3. Get Upper Bound\n";
        cout << "4. Is Empty\n";
        cout << "5. Free Extra\n";
        cout << "6. Remove All\n";
        cout << "7. Get At\n";
        cout << "8. Set At\n";
        cout << "9. Add\n";
        cout << "10. Append\n";
        cout << "11. Operator =\n";
        cout << "12. Get Data\n";
        cout << "13. Insert At\n";
        cout << "14. Remove At\n";
        cout << "99. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Size: " << arr.GetSize() << endl;
            break;
        case 2: {
            int size, grow;
            cout << "Enter size: ";
            cin >> size;
            cout << "Enter grow: ";
            cin >> grow;
            arr.SetSize(size, grow);
            break;
        }
        case 3:
            cout << "Upper Bound: " << arr.GetUpperBound() << endl;
            break;
        case 4:
            cout << (arr.IsEmpty() ? "Array is empty" : "Array is not empty") << endl;
            break;
        case 5:
            arr.FreeExtra();
            cout << "Extra memory freed\n";
            break;
        case 6:
            arr.RemoveAll();
            cout << "Array cleared\n";
            break;
        case 7: {
            int index;
            cout << "Enter index: ";
            cin >> index;
            try {
                cout << "Value at index " << index << ": " << arr.GetAt(index) << endl;
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 8: {
            int index, value;
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter value: ";
            cin >> value;
            try {
                arr.SetAt(index, value);
                cout << "Value set successfully\n";
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 9: {
            int value;
            cout << "Enter value to add: ";
            cin >> value;
            arr.Add(value);
            cout << "Value added successfully\n";
            break;
        }
        case 10: {
            Array<int> other;
            other.Add(1);
            other.Add(2);
            other.Add(3);
            Array<int>* result = arr.Append(other);
            cout << "Arrays appended. New array size: " << result->GetSize() << endl;
            delete result;
            break;
        }
        case 11: {
            Array<int> other;
            other.Add(1);
            other.Add(2);
            other.Add(3);
            arr = other;
            cout << "Arrays assigned successfully\n";
            break;
        }
        case 12: {
            int* data = arr.GetData();
            cout << "Array data: ";
            for (int i = 0; i < arr.GetSize(); ++i)
                cout << data[i] << " ";
            cout << endl;
            delete[] data;
            break;
        }
        case 13: {
            int index, value;
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter value: ";
            cin >> value;
            try {
                arr.InsertAt(index, value);
                cout << "Value inserted successfully\n";
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 14: {
            int index;
            cout << "Enter index: ";
            cin >> index;
            try {
                arr.RemoveAt(index);
                cout << "Value removed successfully\n";
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 99:
            return 0;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
