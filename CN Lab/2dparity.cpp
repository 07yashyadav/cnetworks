// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n,m;
//     cout<<"ENte the row and col no.:"<<endl;
//     cin>>n>>m;

//     vector<vector<int>>matrix(n,vector<int>(m,0));
//     vector<int> row(n,0);
//     vector<int> col(m,0);

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             int x;
//             cout<<"Enter the bit"<<endl;
//             cin>>x;
//             matrix[i][j]=x;
//             row[i]+=x;
//             col[j]+=x;
//         }
//     }

//     for(int i=0;i<n;i++){
//         if(row[i]%2==0) cout<<i+1<<" row has even parity"<<endl;
//         else cout<<i+1<<" row has oddd parity"<<endl;
//     }
//     cout<<endl<<endl;
//     for(int i=0;i<m;i++){
//         if(col[i]%2==0) cout<<i+1<<" col has even parity"<<endl;
//         else cout<<i+1<<" col has odd parity"<<endl;
//     }
// }

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cout<<"Ente row and col"<<endl;
    cin>>n>>m;

    vector<vector<int>>matrix(n,vector<int>(m,0));
    vector<int>row(n,0);
    vector<int>col(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cout<<"ente tje bits"<<endl;
            cin>>x;
            matrix[i][j]=x;
            row[i]+=x;
            col[j]+=x;
        }
    }

    for(int i=0;i<n;i++){
        if(row[i]%2==0) cout<<i+1<<" row has even parity"<<endl;
        else cout<<i+1<<" row has odd parity"<<endl;
    }

    cout<<endl<<endl;
    for(int j=0;j<m;j++){
        if(col[j]%2==0) cout<<j+1<<" col has even parity"<<endl;
        else cout<<j+1<<" col has odd paritu"<<endl;
    } 


}