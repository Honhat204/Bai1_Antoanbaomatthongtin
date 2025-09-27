#include <bits/stdc++.h>
using namespace std;

// Giữ lại chữ cái, chuyển thành chữ hoa
string only_letters_upper(string s){
    string t;
    for(char c:s) if(isalpha(c)) t.push_back(toupper(c));
    return t;
}

// Mã hoá Vigenere
string vigenere_encrypt(string plain, string key){
    string p = only_letters_upper(plain);
    string k = only_letters_upper(key);
    string out;
    int n = p.size();
    for(int i=0;i<n;i++){
        char c = (p[i]-'A' + (k[i%k.size()]-'A'))%26 + 'A';
        out.push_back(c);
    }
    return out;
}

// Giải mã Vigenere
string vigenere_decrypt(string cipher, string key){
    string c = only_letters_upper(cipher);
    string k = only_letters_upper(key);
    string out;
    int n = c.size();
    for(int i=0;i<n;i++){
        char p = (c[i]-'A' - (k[i%k.size()]-'A') + 26)%26 + 'A';
        out.push_back(p);
    }
    return out;
}

int main(){
    cout<<"Vigenere \n";

    string text; 
    cout<<"Nhap du lieu: ";
    getline(cin,text);

    cout<<"Nhap khoa(chu cai): ";
    string key; 
    cin>>key;

    cout<<"Chon:\n1) Ma hoa\n2) Giai ma\nLua chon: ";
    int choice; cin>>choice;

    if(choice==1){
        cout<<"Ma hoa: "<<vigenere_encrypt(text,key)<<"\n";
    }else if(choice==2){
        cout<<"Giai ma: "<<vigenere_decrypt(text,key)<<"\n";
    }else{
        cout<<"Lua chon khong hop le.\n";
    }
}
