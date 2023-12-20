#include <iostream>
using namespace std;

int main()
{
    int option, position, value;
    do
    {
        cout << "What Operation u want to perform?? select an option between 1-6 Or, Enter 0 for exit" << endl;
        cout << "1. insert(H, K) " << endl;
        cout << "2. getMin(H) " << endl;
        cout << "3. extractMin(H) " << endl;
        cout << "4. delete(H) " << endl;
        cout << "5. decreaseKey(H) " << endl;
        cout << "0. Exit " << endl;

        cout << endl;

        cin >> option;

        switch (option)
        {
        case 0:
            cout << "You successfully exited the code." << endl;
            break;
        case 1:
            cout << "You successfully exited the code." << endl;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            cout << "Default" << endl;
        }

    } while (option != 0);

    return 0;
}