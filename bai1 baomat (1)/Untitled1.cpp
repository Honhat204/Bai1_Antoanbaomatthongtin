#include <bits/stdc++.h>
using namespace std;

string caesarEncrypt(string text, int k) {
    string res = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            res += char((c - base + k) % 26 + base);
        } else res += c;
    }
    return res;
}

string caesarDecrypt(string text, int k) {
    return caesarEncrypt(text, 26 - k);
}

int main() {
    string s;
    int key, choice;
    cout << "Nhap van ban: ";
    getline(cin, s);
    cout << "Nhap khoa (so nguyen): ";
    cin >> key;
    cout << "Chon che do (1 = Ma hoa, 2 = Giai ma): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Ma hoa: " << caesarEncrypt(s, key) << endl;
    } else {
        cout << "Giai ma: " << caesarDecrypt(s, key) << endl;
    }
}
