#ifndef ADAPTIVEHUFFMAN_H_INCLUDED
#define ADAPTIVEHUFFMAN_H_INCLUDED
#include<string>
using namespace std;

class Node{
public:
    Node();
    Node *left;
    Node *right;
    bool parent;
    int weight;
    char symbol;
   // int key;

};

class adaptiveHuffman {
public:
    adaptiveHuffman();
    Node* lookupSymbol( Node *,char);
    Node* lookupSymbol1( Node *,char);
    Node* Insert(Node *,char);
    Node* Insert2(Node *,char);
    void  updateWeight(Node *);
    void  updateWeight1(Node *);

    void Switch(Node *);
    void Switch1(Node *);

    bool found(Node *,char);
    bool found1(Node *,char);
   // Node* NYT(Node *);
    string NYTCode (Node *,string );
    string symbolCode(Node *,char c);
    string fixedCode(int,int,int);
    string BinaryRepresentation(int,int);
    string encoding(Node *,int,int,int,int,char);
    char decodeingFirstTime(int,int,string,string);
    int binaryToDecimal(string );
    char read1bit(Node *,string,string ,int,int);
    char indexToChar(int,string);
    string decoding(Node *,string,string ,int,int);
    string s;

    Node* root;
    Node* Droot;
    Node* NYT = new Node();
    Node* DNYT = new Node();

};



#endif // ADAPTIVEHUFFMAN_H_INCLUDED
#include"adaptiveHuffman.cpp"
#include"decodingHuffman.cpp"

