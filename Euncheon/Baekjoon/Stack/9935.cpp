#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string input, explosion;
    cin >> input;
    cin >> explosion;


    string temp;

    int input_size = input.size();
    int explosion_size = explosion.size();
    for (int i = 0; i < input_size; i++) {
        temp += input[i];
        if (temp.length() >= explosion_size) {
            int idx = explosion_size - 1;
            
            for (auto it = temp.rbegin(); it < temp.rbegin() + explosion_size; it++) {
                if (*it != explosion[idx]) {
                    break;
                }
                idx--;
            }

            if (idx < 0) {
                for (int i = 0; i < explosion_size; i++) {
                    temp.pop_back();
                }
            }
        }

        // cout << temp << endl; //erase
    }

    if (temp.size()  == 0)
        cout << "FRULA";
    else
        cout << temp;
    

    return 0;
}
