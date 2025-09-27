#include <bits/stdc++.h>
using namespace std;

// Tạo bảng 5x5 từ khóa
vector<vector<char>> build_matrix(string key){
    bool used[26] = {0};
    vector<vector<char>> table(5, vector<char>(5));
    key += "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // J = I
    string filtered;
    for(char c:key){
        if(!isalpha(c)) continue;
        char up = toupper(c);
        if(up=='J') up='I';
        if(!used[up-'A']){
            used[up-'A'] = true;
            filtered.push_back(up);
        }
    }
    int idx=0;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            table[i][j] = filtered[idx++];
    return table;
}

// Tìm vị trí ký tự trong bảng
pair<int,int> find_pos(vector<vector<char>>& table, char c){
    if(c=='J') c='I';
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(table[i][j]==c) return {i,j};
    return {-1,-1};
}

// Chuẩn hóa văn bản (chia cặp)
string preprocess(string text, bool for_encrypt=true){
    string p;
    for(char c:text) if(isalpha(c)) p.push_back(toupper(c));
    for(int i=0;i<p.size();i++) if(p[i]=='J') p[i]='I';
    string out;
    for(int i=0;i<p.size();i++){
        out.push_back(p[i]);
        if(i+1<p.size() && p[i]==p[i+1]){
            out.push_back('X');
        }
    }
    if(out.size()%2==1) out.push_back('X');
    return out;
}

// Mã hóa / Giải mã
string playfair_process(string text, vector<vector<char>>& table, bool encrypt){
    string out;
    text = preprocess(text, encrypt);
    for(int i=0;i<text.size();i+=2){
        char a=text[i], b=text[i+1];
        auto [r1,c1] = find_pos(table,a);
        auto [r2,c2] = find_pos(table,b);
        if(r1==r2){ // cùng hàng
            if(encrypt){
                out.push_back(table[r1][(c1+1)%5]);
                out.push_back(table[r2][(c2+1)%5]);
            }else{
                out.push_back(table[r1][(c1+4)%5]);
                out.push_back(table[r2][(c2+4)%5]);
            }
        }else if(c1==c2){ // cùng cột
            if(encrypt){
                out.push_back(table[(r1+1)%5][c1]);
                out.push_back(table[(r2+1)%5][c2]);
            }else{
                out.push_back(table[(r1+4)%5][c1]);
                out.push_back(table[(r2+4)%5][c2]);
            }
        }else{ // hình chữ nhật
            out.push_back(table[r1][c2]);
            out.push_back(table[r2][c1]);
        }
    }
    return out;
}

int main(){
    cout<<"Playfair\n";
    cout<<"Nhap du lieu: ";
    string text; getline(cin,text);
    cout<<"Nhap khoa: ";
    string key; getline(cin,key);

    auto table = build_matrix(key);

    cout<<"Chon:\n1) Ma hoa\n2) Giai ma\nLua chon: ";
    int choice; cin>>choice;

    if(choice==1){
        cout<<"Ma hoa: "<<playfair_process(text,table,true)<<"\n";
    }else if(choice==2){
        cout<<"Giai ma: "<<playfair_process(text,table,false)<<"\n";
    }else{
        cout<<"lua chon khong hop le.\n";
    }
}
