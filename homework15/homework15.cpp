#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);  // 讀入一行文字
    int word_count = 0;
    unordered_map<char, int> char_count;
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            char_count[tolower(s[i])]++;
        }
        else if (s[i] == ' ' || s[i] == ',' || s[i] == '.') {
            if (i > 0 && isalpha(s[i - 1])) {
                word_count++;
            }
        }
    }
    // 處理最後一個字
    if (isalpha(s[s.length() - 1])) {
        word_count++;
    }

    cout << word_count << endl;
    for (char c = 'a'; c <= 'z'; c++) {
        if (char_count.count(c) > 0) {
            cout << c << " " << char_count[c] << endl;
        }
    }
    return 0;
}
