#include <iostream>

using namespace std;

int main(void) {
    double x, y;
    char oper;

    cout << "CALCULATOR\n\n";
    cout << "X: ";
    cin >> x;
    cout << "OPERATION: ";
    cin >> oper;
    cout << "Y: ";
    cin >> y;

    cout << "\nAns: ";
    
    switch (oper) {
        case '+':
            cout << x + y;
            break;
        case '-':
            cout << x - y;
            break;
        case '/':
            cout << x / y;
            break;
        case '*':
            cout << x * y;
            break;
        default:
            cout << x;
    }
}