#include <iostream>
#include <string>
#include <random>
using namespace std;

int main()
{
    string dictionary = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789!@#$%^&*()_+/?|<>,.;':[]{}\"\\";
    string length;
    bool valid;

    cout << "dictionary: " << dictionary << endl;
    do {
        cout << "Define password length: ";
        cin >> length;
        for (char i : length) {
            if (isdigit(i)) {
                valid = true;
            }
            else {
                valid = false;
                break;
            }
        }
        cout << length << " is " << ((valid) ? "a valid" : "an invalid") << " number!\n";
    } while (!valid);

    srand(time(NULL));
    string password;
    for (int i = 0; i < stoi(length); i++) {
        password += dictionary[(0 + (rand() % ((dictionary.size() - 1)) - 0 + 1))];
        if ((password.size() >= 2) && (password[i] == password[i - 1])) { //unique back 2 back generation
            password.pop_back();
            i--;
        }
    }
    cout << "Generating a password with " << length << ((stoi(length) >= 2) ? " characters\nHere you go:\n" : " character\nHere you go:\n") << password << endl << endl;
    system("pause");
    return 0;
}