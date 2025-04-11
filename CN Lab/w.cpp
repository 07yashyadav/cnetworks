#include<bits/stdc++.h>
using namespace std;

string Xor(string dividend,string divisor){
    int n =divisor.length();
    for(int i =0;i<dividend.length()-n;){
        for(int j=0;j<n;j++){
            dividend[i+j]=(dividend[i+j]==divisor[j])?'0':'1';
        }
        while(i<dividend.length() && dividend[i]!='1') i++;
    }

    return dividend.substr(dividend.length()-n+1);

}
string encode(string data,string divisor){
    int m = divisor.length();
    string paddeddata = data + string(m-1,'0');
    string remainder = Xor(paddeddata,divisor);

    return data+remainder;
}

bool check(string received,string divisor){
    string remainder = Xor(received,divisor);
    return remainder.find('1')==string::npos;
}

int main(){
    string data,divisor;
    cout<<"data"<<endl;
    cin>>data;

    cout<<"divisor"<<endl;
    cin>>divisor;

    string transmitted = encode(data,divisor);
    cout<<"transmitted"<<transmitted<<endl;

    string received;
    cout<<"received"<<endl;
    cin>>received;

    if(check(received,divisor)) cout<<"no error";
    else cout<<"error";
}