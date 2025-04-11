# include<bits/stdc++.h>
using namespace std;



string Ones_complement(string data)
{
   for (int i = 0; i < data.length(); i++) {
       if (data[i] == '0')
           data[i] = '1';
       else
           data[i] = '0';
   }
   return data;
}

string checkSum(string data,int block_size)
{
    int n=data.size();
    if(n%block_size!=0)
    {
        data.insert(0, block_size - (n % block_size), '0');
    }

    string result=data.substr(0, block_size);

    for(int i=block_size;i<data.length();i+=block_size)
    {
       string next_block=data.substr(i,block_size);
       string sum(block_size,'0');
       int carry=0;
       
       for(int k=block_size-1;k>=0;k--)
       {
        int bitSum=(result[k]-'0')+(next_block[k]-'0')+carry;
        sum[k]=(bitSum%2)+'0';
        carry=bitSum/2;
       }

       while(carry)
       {
        for(int k=block_size-1;k>=0 && carry ;k--)
        {
            int bitSum=(sum[k]-'0')+carry;
            sum[k]=(bitSum%2)+'0';
            carry=bitSum/2;
        }
       }
       result=sum;

    }

    return Ones_complement(result);

}

bool checker(string sent_message,string rec_message,int block_size)
{
    string sender_checkSum=checkSum(sent_message,block_size);
    string receiver_checkSum=checkSum(rec_message+sender_checkSum,block_size);
    
    if(count(receiver_checkSum.begin(),receiver_checkSum.end(),'0')==block_size)
    {
        return true;
    }
    else {
        return false;
    }

}

int main()
{
   string sent_message;
   cout << "Enter the string 1 (msg to be sent): \n";
   cin >> sent_message;
   string recv_message;
   cout << "Enter the string 2 (msg received): \n";
   cin >> recv_message;
   int block_size = 8;
   if (checker(sent_message, recv_message, block_size)) {
       cout << "No Error";
   }
   else {
       cout << "Error";
   }
   return 0;
}

