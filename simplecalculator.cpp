#include <iostream>

using namespace std;

int main() {
    double number1, number2, result;
    char op;

    cout << "Enter the first number: ";
    cin >> number1;

    cout << "Enter the second number: ";
    cin >> number2;

    cout << "Enter the operation (+, -, *, /): ";
    cin >> op;

    switch (op) {
        case '+':
            result = number1 + number2;
            cout << "Result: " << result << endl;
            break;

        case '-':
            result = number1 - number2;
            cout << "Result: " << result << endl;
            break;

        case '*':
            result = number1 * number2;
            cout << "Result: " << result << endl;
            break;

        case '/':
            if (number2 == 0) {
                cout << "Error! Division by zero is not allowed." << endl;
                return 0;
            }
            result = number1 / number2;
            cout << "Result: " << result << endl;
            break;

        default:
            cout << "Error! Invalid operation." << endl;
            return 0;
    }

    return 0;
}