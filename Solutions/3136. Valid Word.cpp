#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) {
            return false;
        }

        bool containsVowel = false;
        bool containsConsonant = false;

        for (char ch : word) {
            if (!isalnum(static_cast<unsigned char>(ch))) {
                return false;
            }

            bool thisOneIsAVowel = false;
            for (char vowel : {'a', 'e', 'i', 'o', 'u'}) {
                if (tolower(ch) == vowel) {
                    containsVowel = true;
                    thisOneIsAVowel = true;
                }
            }
            if (!thisOneIsAVowel && isalpha(static_cast<unsigned char>(ch))) {
                containsConsonant = true;
            }
        }

        return containsVowel && containsConsonant;
    }
};

int main() {
    Solution s;
    
    cout << s.isValid("234Adas") << "\n";
    cout << s.isValid("b3") << "\n";
    cout << s.isValid("a3$e") << "\n";
    cout << s.isValid("AhI") << "\n";
    cout << s.isValid("UuE6") << "\n";

    return 0;
}