#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

// void stopwatch(){
//     int frame = 0;
//     srand(time(0));

//     while(frame<5){
//         cout<<"sending frame: "<<frame<<endl;
//         if(rand()%2==0){
//             cout<<"frame "<<frame<<" Lost ! retransmitting "<<endl;
//             sleep(1);
//             continue;
//         }
//         cout<<"frame "<<frame<<" received successfully "<<endl;
//         cout<<"ack for frame "<<frame<<" received "<<endl;
//         frame++;
//     }
// }


void stopwatch(){
    srand(time(0));
    for(int frame =0;frame<5;frame++){
        cout<<"sending frame: "<<frame<<endl;
        if(rand()%2==0){
            cout<<"frame "<<frame<<" lost! retransmitt"<<endl;
            sleep(1);
            continue;
        }
        cout<<"frane "<<frame<<" received successfully "<<endl;
        cout<<"ack. for frame "<<frame<<" received:"<<endl;
        frame++;
    }
}

int main(){
    stopwatch();
    return 0;
}