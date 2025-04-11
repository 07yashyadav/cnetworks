// #include<bits/stdc++.h>
// #include<unistd.h>
// using namespace std;
// #define window_size 4

// void selectivereject(){
//     vector<bool>received(10,false);
//     srand(time(0));
//     for(int frame =0;frame<10;frame++){
//         if(rand()%3==0){
//             cout<<"frame "<<frame<<" lost! "<<endl;
//         }
//         else{
//             cout<<"frmae "<<frame<<" received successfully "<<endl;
//             received[frame] = true;
//         }
//     }
//         cout<<" retransmitting "<<endl;
//         for(int frame = 0;frame<10;frame++){
//             if(!received[frame]){
//                 cout<<" retransmitting frame "<<frame<<endl;
//                 sleep(1);
//             }
//         }
//         cout<<" all frames trasmitted ";
//     }



// int main(){
//     selectivereject();
//     return 0;
// }

#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

#define windowsize 4

void selectivereject(){
    vector<bool>received(10,false);
    for(int frame = 0;frame<10;frame++){
        if(rand()%3==0){
            cout<<"frame "<<frame<<"lost! "<<endl;
        }
        else {
            cout<<"frame "<<frame<<" received successfully "<<endl;
            received[frame]= true;
        }
    }

    cout<<"retransmitting!!"<<endl;
    for(int frame =0;frame<10;frame++){
        if(!received[frame]){
            cout<<"retransmitting frmae "<<frame<<endl;
            sleep(1);
        }
    }
    cout<<"all transmitted!"<<endl;
}

int main(){
    selectivereject();
    return 0;
}