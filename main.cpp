#include"adaptiveHuffman.h"
#include<math.h>
#include<string>
#include<bits/stdc++.h>


using namespace std;
int returnIndex(char c,string Set)
{
    for(int i=0;i<Set.size();i++)
    {
        if(Set[i]==c){return i;}

    }
}

int main()
{
    int option;
    string Set;
    string message;
    string encodedMessage;
    string decodedMessage;
    string sequence;
    int m=0,r,e,index;


    adaptiveHuffman huffman;
    cout<<"Enter Option number : "<<endl;
    cout<<"1)Encoding"<<endl;
    cout<<"2)Decoding"<<endl;
    cin>>option;
    cout<<"Enter the set of symbols : "<<endl;
    cin>>Set;
    for(int i=0;i<(int)Set.size();i++)
    {
        m++;
    }

  e=log2(m);
  r=m-pow(2,e);

//cout<<m<<" "<<e<<" "<<r<<endl;
    if(option==1)
    {
        cout<<"Enter the message to be encoded : "<<endl;
        cin>>message;

        for(int i=0;i<message.size();i++)
        {  //cout<<"Esraa"<<endl;
            index=returnIndex(message[i],Set);
           //cout<<"Hala"<<endl;
            code="";
            encodedMessage+=huffman.encoding(huffman.root,index+1,e,r,m,message[i]);
           // decodedMessage+=huffman.encoding(huffman.Droot,index+1,e,r,m,message[i]);
            //cout<<"Hasnaa"<<endl;
           // cout<<"vvvvvvv "<<huffman.root->right<<endl;
        }


        cout<<"The encoded message is : "<<endl;
        cout<<endl;
        cout<<encodedMessage<<endl;
    }
    else if(option==2)
    {
        cout<<"Enter the sequence to be decoded"<<endl;
        cin>>sequence;
        decodedMessage=huffman.decoding(huffman.Droot,Set,sequence,e,r);
        cout<<decodedMessage;
    }
    return 0;
}
/*
Enter the set of symbols :
abcdefghijklmnopqrstuvwxyz
The encoded message is :
aardva
00000000001000100011101100000
*/
