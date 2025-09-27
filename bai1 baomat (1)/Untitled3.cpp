#include <bits/stdc++.h>
using namespace std;

// Giữ lại chữ cái, chuyển thành chữ hoa
string only_letters_upper(string s){
    string t;
    for(char c:s) if(isalpha(c)) t.push_back(toupper(c));
    return t;
}

// Mã hoá hoán vị cột
string perm_encrypt(string plain, vector<int> key){
    string p = only_letters_upper(plain);
    int cols = key.size();
    int rows = (p.size() + cols - 1) / cols;
    while((int)p.size() < rows * cols) p.push_back('X'); // padding

    vector<string> grid(rows, string(cols,'X'));
    int idx = 0;
    for(int r=0;r<rows;r++)
        for(int c=0;c<cols;c++) grid[r][c] = p[idx++];

    string out;
    for(int k=1;k<=cols;k++){
        int col=-1;
        for(int j=0;j<cols;j++) if(key[j]==k) col=j;
        for(int r=0;r<rows;r++) out.push_back(grid[r][col]);
    }
    return out;
}

// Giải mã hoán vị cột
string perm_decrypt(string cipher, vector<int> key){
    string c = only_letters_upper(cipher);
    int cols = key.size();
    int rows = (c.size() + cols - 1) / cols;

    vector<string> grid(rows, string(cols,'X'));
    int idx=0;
    for(int k=1;k<=cols;k++){
        int col=-1;
        for(int j=0;j<cols;j++) if(key[j]==k) col=j;
        for(int r=0;r<rows;r++) grid[r][col]=c[idx++];
    }

    string out;
    for(int r=0;r<rows;r++)
        for(int j=0;j<cols;j++) out.push_back(grid[r][j]);
    return out;
}

int main(){
    cout<<"Hoan vi\n";

    string text; 
    cout<<"Nhap du lieu: "; 
    getline(cin,text);

    cout<<"Nhap khoa (vi du: 4312): ";
    string keystr; cin>>keystr;
    vector<int> key; for(char ch:keystr) key.push_back(ch-'0');

    cout<<"Chon :\n1) Ma hoa\n2) Giai ma\nLua chon: ";
    int choice; cin>>choice;

    if(choice==1){
        cout<<"Ma hoa: "<<perm_encrypt(text,key)<<"\n";
    }else if(choice==2){
        cout<<"Giai ma: "<<perm_decrypt(text,key)<<"\n";
    }else{
        cout<<"Lua chon khong hop le.\n";
    }
}
