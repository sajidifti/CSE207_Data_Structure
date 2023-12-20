#include <iostream>
#include <math.h>
#include "heapADT.h"
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int s;
    cout << "Enter Size of Min Heap" << endl;
    cin >> s;
    MinHeap obj(s);
    cout << "Min Heap Created" << endl;

    int option, val;

    do
    {
        cout << "What operation do you want to perform? "
             << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Get Minimum" << endl;
        cout << "5. Extract Minimum" << endl;
        cout << "6. Height of Heap" << endl;
        cout << "7. Print Heap" << endl;
        cout << "8. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "INSERT Operation -" << endl;
            cout << "Enter VALUE to INSERT in HEAP: ";
            cin >> val;
            obj.insertKey(val);
            cout << endl;
            break;
        case 2:
            cout << "SEARCH Operation -" << endl;
            cout << "Enter VALUE to SEARCH in HEAP: ";
            cin >> val;
            obj.linearSearch(val);
            break;
        case 3:
            cout << "DELETE Operation -" << endl;
            cout << "Enter INDEX of Heap Array to DELETE: ";
            cin >> val;
            obj.deleteKey(val);
            break;
        case 4:
            cout << "GET Min value : " << obj.getMin();
            cout << endl;
            break;
        case 5:
            cout << "EXTRACT Min value : " << obj.extractMin();
            cout << endl;
            break;
        case 6:
            cout << "HEAP TREE HEIGHT : " << obj.height() << endl;
            break;

        case 7:
            cout << "PRINT Heap Array : " << endl;
            obj.printArray();

            cout << endl;
            break;

        case 8:
            system("cls");
            break;

        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}