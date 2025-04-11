#include<bits/stdc++.h>
#include<unistd.h>

using namespace std;
#define window_size 4

void goback(){
    int frame = 0;
    srand(time(0));
    while(frame<10){
        int windowend = min(frame+window_size,10);
        cout<<"sending frame: ";
        for(int i=frame;i<windowend;i++){
            cout<<i<<" ";
        }
        cout<<endl;

        int lostframe = frame+ rand()%window_size;
        cout<<"frame "<<lostframe<<" lost! retransmiting from frame "<<lostframe<<endl;

        sleep(1);
        frame = lostframe;
    }
}

int main(){
    goback();
    return 0;
}