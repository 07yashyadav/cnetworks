#include<bits/stdc++.h>
using namespace std;

int Nrzl(vector<int>&data){
    int transitons = 0;
    for (int i=1;i<data.size();i++){
        if(data[i]!=data[i-1]) transitons++;
    }
    return transitons;
}

int Nrzi(vector<int> &data){
    int transitions = 0;
    for (int i=0;i<data.size();i++){
        if(data[i]==1) transitions++;
    }

    return transitions;
}

int bipolar(vector<int>&data){
    int transition = 0;
    for (int i=1;i<data.size();i++){
        if(data[i]||data[i-1]) transition++;
    }
    return transition;
}


int pseudoternary(vector<int>&data){
    int transition =0 ;
    for(int i=1;i<data.size();i++){
        if(!(data[i] && data[i-1])) transition++;
    }
    return transition;
}

int menchester(vector<int> &data,int n){
    int transition =0;
    for(int i=1;i<n;i++){
        if((data[i]==0 && data[i-1]==1) && (data[i]==1 && data[i-1]==0)) transition++;
    }
    return (n*2-transition-1);
}

int differential(vector<int>&data,int n){
    int transition=0;
    for(int i=1;i<n;i++){
        if((data[i]==0 && data[i-1]==1)||(data[i]==1 && data[i-1]==0)) transition++;
    }
    return n*2-transition-1;

}
int main(){
    int n;
    cout<<"Enter the size :"<<endl;
    cin>>n;

    vector<int> data;
    for (int i=0;i<n;i++){
        bool x;
        cout<<"enter the bit:"<<i+1<<endl;
        cin>>x;
        data.push_back(x);
    }

    cout<<"The no of transitions in nrz-l is:"<<Nrzl(data);
    // cout<<"THe no of transitions in nrz-I:"<<Nrzi(data);
    // cout<<"transitions bipolar : "<<bipolar(data);
    // cout<<"transiotn pseudoternary:"<<pseudoternary(data);
    // cout<<"menchester : "<<menchester(data,n);
    // cout<<"differential menchester:"<<differential(data,n);
}