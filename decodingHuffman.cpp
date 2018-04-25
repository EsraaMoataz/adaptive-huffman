#include<bits/stdc++.h>
#include<string>
#include<math.h>
using namespace std;
int a=0;

bool adaptiveHuffman::found1(Node *root,char c)
{

     if(((root->left == DNYT) && root->right->symbol!=c)||root==DNYT){return 0;}
    if( (root->right!=NULL)&&root->right->symbol==c){return 1;}
    else if(root->left!=NULL&&root->left->symbol==c){return 1;}
    else if(root->right!=NULL&&root->right->parent){return found1(root->right,c);}
    else if(root->left!=NULL&&root->left->parent){return found1(root->left,c);}
    //return 0;
}
int adaptiveHuffman::binaryToDecimal(string s)
{
    int decimal_value=0;
    int counter=s.size()-1;
    for(int i=0;i<s.size();i++)
    {
        decimal_value+=(s[i]-'0')*pow(2,counter);
        counter--;
    }
    return decimal_value;

}
bool bol=0;

char  adaptiveHuffman:: decodeingFirstTime(int e,int r,string Set,string s)
{
    string ebit;
    int decimalValue=0;
    int index=0;
    string updatedString;

        ebit=s.substr(a,e);


     a+=e;
    //cout<<ebit<<endl;
    decimalValue=binaryToDecimal(ebit);
    //cout<<decimalValue<<endl;


        if(decimalValue<r)
    {
        ebit+=s[a];
        decimalValue=binaryToDecimal(ebit);
        index=decimalValue+1;
        a+=1;

    }
    else
    {index=decimalValue+r+1;}


     return Set[index-1];

}
char adaptiveHuffman::indexToChar(int index,string Set)
{
    return Set[index];
}

char c;
 char adaptiveHuffman::read1bit(Node *root,string Set,string s,int e,int r)
 {

     if(root==DNYT)
     {

        return decodeingFirstTime(e,r,Set,s);
     }
     else if(root!=DNYT && root->parent==0)
        {
            //cout<<root->symbol<<endl;
            return root->symbol;
        }

     if(s[a]=='0')
     {
         a++;
        c=read1bit(root->left,Set,s,e,r);
        //return c;
     }

     else if(s[a]=='1')
     {
        a++;
       c=read1bit(root->right,Set,s,e,r);

     }

     return c;

 }
 void adaptiveHuffman::Switch1(Node *root)
{
    Node *temp;
    //int tempKey;
    if(root->left==DNYT){return;}

    if(root->left->weight > root->right->weight)
    {
       temp=root->right;
       root->right=root->left;
       root->left=temp;
       //tempKey=root->right->key;
       //root->right->key=root->left->key;
       //root->left->key=tempKey;


    }
    if(root->right->parent){Switch1(root->right);}
    else if(root->left->parent){Switch1(root->left);}

}
void adaptiveHuffman::updateWeight1(Node *root)
{     //cout<<"jj"<<endl;
    if(root->left==DNYT){return ;}  // is NYT
    if(root->parent){root->weight++;}
    if(root->right->parent){updateWeight1(root->right);}//cout<<"jj"<<endl;
    else if(root->left->parent){updateWeight1(root->left);}
     //cout<<"tt"<<endl;
}


 Node* adaptiveHuffman::Insert2(Node *root1,char c)
{
    if(root1==DNYT)
    {
        root1=new Node;
        root1->parent=1;
         root1->left=DNYT;
         Node* node2=new Node();
        root1->right=node2;
        node2->left=NULL;
        node2->right=NULL;
        node2->symbol=c;
        node2->weight=1;
        root1->weight=1;
      if(b) {b=0;Droot = root1;}
      return root1;
    }

           else if(root1->left!=NULL&&(root1->left->parent||root1->left==DNYT)){root1->left=Insert2(root1->left,c);}
      else if(root1->right!=NULL && (root1->right->parent)){root1->right=Insert2(root1->right,c);}



    return root1;
}
Node * adaptiveHuffman::lookupSymbol1(Node *root,char c)
{
    if((root->left== DNYT ) && root->right->symbol!=c){return NULL;}
    if(root->right->symbol==c){root->right->weight++;return root->right;}
    else if(root->left->symbol==c){return root->left;}
    else if(root->right->parent)
        {
            root->right->weight++;
            return lookupSymbol1(root->right,c);
    }
    else if(root->left->parent)
        {
            root->left->weight++;

        return lookupSymbol1(root->left,c);
       }

 return root;
}

 string adaptiveHuffman:: decoding(Node *root,string Set,string s,int e,int r)
 {
     string output;
    Droot = DNYT;
char c=decodeingFirstTime(e,r,Set,s);
     output+=c;

     Insert2(Droot,c);
    updateWeight1(Droot);
   Switch1(Droot);

     while(a<s.size())
     {
         c=read1bit(Droot,Set,s,e,r);

         if(found1(Droot,c)){
    //Node* tree =new Node();

    lookupSymbol1(Droot,c);
    Switch1(Droot);
   }
   else{
    Insert2(Droot ,c);
   updateWeight1(Droot);
   Switch1(Droot);}
 output+=c;

     }

     return output;
 }
//abcdefghijklmnopqrstuvwxyz
//011000010000010010101101111111011001111110110




//000100000010100010100011100010011100110110111101






