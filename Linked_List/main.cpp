#include <bits/stdc++.h>
#include "SLL.h"
using namespace std;

int main()
{
    SLL *s1 = new SLL();
    while (1)
    {
        cout << endl
             << "1. Add item to the end of the List" << endl
             << "2. Add item at the beginning of the list" << endl
             << "3. Add item at position pos in the List" << endl
             << "4. Return true if item is in the List" << endl
             << "5. Return the number of items in the List" << endl
             << "6. Return true if the List is empty" << endl
             << "7. Return the item at position pos in the List" << endl
             << "8. Return position of the specified element in the list" << endl
             << "9. Remove first element of the list" << endl
             << "10. Remove last element of the list" << endl
             << "11. Remove and return the item at position pos in the List" << endl
             << "12. Reverse the element of the list" << endl
             << "13. Sort the element of the list in ascending order" << endl
             << "14. Display Linked List" << endl
             << "15. Exit" << endl;

        int option, data, pos, a, b, c;
        cout << "Enter Your Option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter Data: ";
            cin >> data;
            s1->add(data);
            break;

        case 2:
            cout << "Enter Data: ";
            cin >> data;
            s1->addbegin(data);
            break;

        case 3:
            cout << "Enter Position: ";
            cin >> pos;
            cout << "Enter Data: ";
            cin >> data;
            s1->addanypos(pos, data);
            break;

        case 4:
            cout << "Enter Data: ";
            cin >> data;
            if (s1->contains(data))
            {
                cout << "Item is in the list" << endl;
            }
            else
            {
                cout << "Item is not in the list" << endl;
            }

            break;

        case 5:

            a = s1->size();
            cout << "Size: " << a << endl;
            break;

        case 6:
            if (s1->isEmpty())
            {
                cout << "The List Is Empty" << endl;
            }
            else
            {
                cout << "List is populated" << endl;
            }
            break;

        case 7:
            cout << "Enter Data:" << endl;
            cin >> pos;
            b = s1->get(pos);
            cout << b << endl;
            break;

        case 8:
            cout << "Enter Data:" << endl;
            cin >> data;
            c = s1->indexOf(data);
            if (c == 0)
            {
                cout << "Item Not Found" << endl;
            }
            else if (c == -1)
            {
                cout << "List is empty" << endl;
            }
            else
            {
                cout << "Position Is: " << c << endl;
            }
            break;

        case 9:
            s1->removefirst();
            cout << "First Item Removed" << endl;
            break;

        case 10:
            s1->removelast();
            cout << "Last Item Removed" << endl;
            break;

        case 11:
            cout << "Enter position:" << endl;
            cin >> data;
            s1->remove(data);
            cout << "Item Removed" << endl;
            break;

        case 12:
            s1->reverse();
            cout << "Reversed" << endl;
            break;

        case 13:
            s1->sort();
            cout << "Sorted" << endl;
            break;

        case 14:
            s1->display();
            break;

        case 15:
            cout << "Program Exited" << endl;
            break;

        default:
            cout << "Invalid Input. Try Again" << endl;
        }

        if (option == 15)
        {
            break;
        }
    }
    return 0;
}