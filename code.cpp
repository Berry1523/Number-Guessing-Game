#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int bestScore = 0;
    char playAgain;

    do {
        int min, max;
        cout << "Enter the minimum number: ";
        cin >> min;
        cout << "Enter the maximum number: ";
        cin >> max;

        // Validate range
        while (min >= max) {
            cout << "Invalid range. Minimum must be less than maximum. Try again.\n";
            cout << "Enter the minimum number: ";
            cin >> min;
            cout << "Enter the maximum number: ";
            cin >> max;
        }

        int number = rand() % (max - min + 1) + min;

        int maxAttempts;
        cout << "Enter maximum number of attempts: ";
        cin >> maxAttempts;

        int guess, attempts = 0;
        bool guessedCorrectly = false;

        cout << "\nStart guessing the number between " << min << " and " << max << "!\n";

        while (attempts < maxAttempts) {
            cout << "Attempt " << (attempts + 1) << ": ";
            cin >> guess;
            attempts++;

            if (guess < number) {
                cout << "Too low!\n";
            } else if (guess > number) {
                cout << "Too high!\n";
            } else {
                cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
                if (bestScore == 0 || attempts < bestScore) {
                    bestScore = attempts;
                    cout << "🎉 New best score!\n";
                }
                guessedCorrectly = true;
                break;
            }
        }

        if (!guessedCorrectly) {
            cout << "You've run out of attempts. The correct number was " << number << ".\n";
        }

        if (bestScore > 0) {
            cout << "Best score so far: " << bestScore << " attempts.\n";
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
