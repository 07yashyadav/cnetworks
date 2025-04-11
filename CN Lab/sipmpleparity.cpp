#include<bits/stdc++.h>
using namespace std;
int parity(vector<int>&data){
    int rst  = 0;
    for(int i=1;i<=data.size();i++){
        if(data[i]==1) rst++;
    }
    if(rst%2==0) return true;
     return false;
}

int main(){
    int n;
    cout<<"enter the size"<<endl;
    cin>>n;
    vector<int> data;
    for(int i=0;i<n;i++){
        bool x;
        cout<<"Enter the bit "<<i+1<<endl;
        cin>>x;
        data.push_back(x);
    }

    cout<<"parity of no. is "<<(parity(data)?"odd":"even");
} 