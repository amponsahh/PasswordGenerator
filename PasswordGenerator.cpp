#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <cctype>
using namespace std;

int main()
{
    string length, repeat, password, dictionary = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789!@#$%^&*()_+/?|<>,.;':[]{}\"\\";
    int n = 0, remainder = 0, x = 0, output = 0, valid = 0, again = 0;
    
    cout << "dictionary: " << dictionary << endl;
    srand((unsigned int)time(NULL));

    do {

        do { // length validation 
            cout << "Define password length: ";
            cin >> length;
            for (char i : length) {
                if (isdigit(i)) {
                    valid = 1;
                }
                else {
                    valid = 0;
                    break;
                }
            }
            cout << length << " is " << ((valid) ? "a valid" : "an invalid") << " whole number!\n";
        } while (!valid);


        //excute code here 
        n = (int)((dictionary.size() - 1) - 0 + 1);
        remainder = RAND_MAX % n;

        for (int i = 0; i < stoi(length); i++) {
            do {
                x = rand();
                output = x % n;
            } while (x >= RAND_MAX - remainder);
            password += dictionary[(output)];

            //unique back 2 back generation
            if ((password.size() > 1) && (password[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(i) - 1] == password[i])) {
                password.pop_back();
                i--;
            }
        }        
        cout << "Generating a password with " << length << ((stoi(length) >= 2) ? " characters\nHere you go:\n" : " character\nHere you go:\n") << password << endl;


        do { // repetition validation 
            cout << "Would you like to generate another password? (Y/N): ";
            cin >> repeat;
            valid = (((repeat.size() == 1) && (isalpha(repeat[0])) && ((toupper(repeat[0]) == 'Y') || toupper(repeat[0]) == 'N')) ? 1 : 0);
            cout << repeat << " is " << ((valid) ? "a valid" : "an invalid") << " input!\n";
        } while (!valid);

        
        again = (toupper(repeat[0]) == 'Y' ? 1 : 0);
        cout << "Alright, " << ((again) ? "let's do this again!\n" : "goodbye!\n");
        password = "";
    } while (again);

    system("pause");
    return 0;
}