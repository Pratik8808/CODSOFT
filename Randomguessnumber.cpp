#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));
    int randomNumber = rand() % 100 + 1;
    int userGuess;
    bool isGuessed = false;

    while (!isGuessed) {
        cout << "Guess the number between 1 and 100: ";
        cin >> userGuess;

        if (userGuess == randomNumber) {
            cout << "Congratulations! You guessed the correct number." << endl;
            isGuessed = true;
        } else if (userGuess > randomNumber) {
            cout << "Your guess is too high. Try again." << endl;
        } else {
            cout << "Your guess is too low. Try again." << endl;
        }
    }

    return 0;
}