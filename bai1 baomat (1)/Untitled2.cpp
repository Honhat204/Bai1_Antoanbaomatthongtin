#include <bits/stdc++.h>
using namespace std;

int mod(int a, int m){ a%=m; if(a<0) a+=m; return a; }

// Euclidean mở rộng để tìm nghịch đảo modulo
int egcd(int a,int b,int &x,int &y){
    if(b==0){ x=1; y=0; return a; }
    int x1,y1;
    int g=egcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return g;
}
int modinv(int a,int m){
    int x,y;
    int g=egcd(a,m,x,y);
    if(g!=1) return -1;
    return mod(x,m);
}

string affine_encrypt(string plain,int a,int b){
    string out;
    for(char c: plain){
        if(isalpha(c)){
            char up=toupper(c);
            int x=up-'A';
            int y=mod(a*x+b,26);
            out.push_back('A'+y);
        }
    }
    return out;
}

string affine_decrypt(string cipher,int a,int b){
    int ainv=modinv(a,26);
    if(ainv==-1) return "[ERROR] a không khả nghịch mod 26";
    string out;
    for(char c: cipher){
        if(isalpha(c)){
            char up=toupper(c);
            int y=up-'A';
            int x=mod(ainv*(y-b),26);
            out.push_back('A'+x);
        }
    }
    return out;
}

int main(){
    cout<<"Affine \n";

    string text; 
    cout<<"Nhap du lieu: "; 
    getline(cin,text);

    int a,b; 
    cout<<"Nhap a: "; cin>>a; 
    cout<<"Nhap b: "; cin>>b;

    cout<<"Chon:\n1) Ma hoa\n2) Giai ma\nLua chon: ";
    int choice; cin>>choice;

    if(choice==1){
        cout<<"Ma hoa: "<<affine_encrypt(text,a,b)<<"\n";
    }else if(choice==2){
        cout<<"Giai ma: "<<affine_decrypt(text,a,b)<<"\n";
    }else{
        cout<<"Lựa chọn không hợp lệ.\n";
    }
}
