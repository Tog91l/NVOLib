include <iostream>
#include <string>
 
bool isVowel(char ch) {
    return ch == 'a' || ch == 'e';
}
 
bool isConsonant(char ch) {
    return ch == 'b' || ch == 'c' || ch == 'd';
}
 
int main() {
    int c;
    std::cin >> c;
 
    for (int i = 0; i < c; i++) {
        int nums;
        std::cin >> nums;
 
        std::string st;
        std::cin >> st;
 
        for (int j = st.length() - 1; j > 0; j--) {
            if (isConsonant(st[j]) && isVowel(st[j + 1])) {
                st.insert(j, ".");
            }
        }
 
        std::cout << st << std::endl;
    }
 
    return 0;
}
