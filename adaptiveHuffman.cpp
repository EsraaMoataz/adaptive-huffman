#include<string>
#include<bits/stdc++.h>
//#include"adaptiveHuffman.h"
using namespace std;
string code;
//Node node;
Node:: Node(){
parent=0;
    left=NULL;
    right=NULL;
    weight=0;
     symbol=NULL;}

adaptiveHuffman::adaptiveHuffman()
{
  /*  node.parent=0;
    node.left=NULL;
    node.right=NULL;
    node.weight=0;
     node.symbol=NULL; */
     root = NYT;
     NYT->left=NULL;
     NYT->right=NULL;
     NYT->symbol=NULL;
     NYT->weight=0;
     NYT->parent=0;

     Droot = DNYT;
     DNYT->left=NULL;
     DNYT->right=NULL;
     DNYT->symbol=NULL;
     DNYT->weight=0;
     DNYT->parent=0;


}

Node * adaptiveHuffman::lookupSymbol(Node *root,char c)
{
    if((root->left== NYT ) && root->right->symbol!=c){return NULL;}
    if(root->right->symbol==c){root->right->weight++;return root->right;}
    else if(root->left->symbol==c){return root->left;}
    else if(root->right->parent)
        {
            root->right->weight++;
            lookupSymbol(root->right,c);
    }
    else if(root->left->parent)
        {
            root->left->weight++;

        lookupSymbol(root->left,c);
       }

 return root;
}string ss="";
string adaptiveHuffman::symbolCode(Node *root,char c)
{

if((root->left==NYT) && root->right->symbol!=c){return ss;}
    if(root->right->symbol==c)
        {
            code+='1';
            return code;
        }
    else if(root->left->symbol==c)
        {
            code+='0';
            return code;
        }
    else if(root->right->parent){code+='1';ss=symbolCode(root->right,c);}
    else if(root->left->parent){code+='0';ss=symbolCode(root->left,c);}
 return ss;
}
string adaptiveHuffman::BinaryRepresentation(int value,int Size)
{
   string binarycode;
    string temp,reverse_temp;
    int cnt=0;
    while(value!=0)
        {
            if(value%2==0)
                { temp+='0';
                  cnt++;
                }
            else
            {
                temp+='1';
                cnt++;
            }
            value=value/2;
        }
        int y=Size-cnt;
        while(y--)
        {
            binarycode+='0';

        }
        for(int i=temp.size()-1;i>=0;i--)
        {
            reverse_temp+=temp[i];
        }
        binarycode+=reverse_temp;

        return binarycode;

}
string adaptiveHuffman:: fixedCode(int e,int r,int i)
{
    string fixedcode;
    if(i>=1 && i<2*r)
    {
        fixedcode=BinaryRepresentation(i-1,e+1);
    }
    else if(i>=2*r)
    {
        fixedcode=BinaryRepresentation(i-r-1,e);
    }
    return fixedcode;


}
string code1="";
string adaptiveHuffman::encoding(Node* root1,int i,int e,int r,int m,char c)
{
    string symbol;
    if(found(root,c))
    {   code="";
        ss="";
        symbol=symbolCode(root,c);
        //Insert(root,c);
        //updateWeight(root);
       Node* tree = new Node();
        tree=lookupSymbol(root,c);
        //tree->weight++;
         Switch(root);
         //cout<<endl<<symbol;
    }
    else
    {
           code1="";
        symbol=NYTCode(root ,"");
        //if(c=='v')cout<<symbol<<endl;
        symbol+=fixedCode(e,r,i);
         //if(c=='v')cout<<symbol<<endl;
         Insert(root,c);//if(root->left==NYT)cout<<root->right->weight<<endl;
         updateWeight(root);
         //cout<<c<<endl;
         Switch(root);
    }
    return symbol;
}



bool adaptiveHuffman::found(Node *root,char c)
{

     if(((root->left == NYT) && root->right->symbol!=c)||root==NYT){return 0;}
    if( (root->right!=NULL)&&root->right->symbol==c){return 1;}
    else if(root->left!=NULL&&root->left->symbol==c){return 1;}
    else if(root->right!=NULL&&root->right->parent){found(root->right,c);}
    else if(root->left!=NULL&&root->left->parent){found(root->left,c);}
    //return 0;
}




/*Node * adaptiveHuffman::NYT(Node *root)
{
 if(root->left == NTY) {return root->left;}

    else if(root->right->parent){NYT(root->right);}
    else if(root->left->parent){NYT(root->left);}

}*/


string adaptiveHuffman::NYTCode (Node *root,string s1="")
{

    if(root->left == NYT)
    {
            s1+='0';
            return s1;
    }

    else if(root->right!=NULL && root->right->parent  )
    {
        //code+='1';
        code1=NYTCode(root->right,s1+'1');
    }
    else if(root->left!=NULL && root->left->parent)
    {
        //code+='0';
        code1=NYTCode(root->left,s1+'0');

    }

return code1;
}


/*
string adaptiveHuffman::NYTCode (Node *root)
{

    if(root->left == NYT)
    {
            //code+='0';
            return "0";
    }

    else if(root->right!=NULL && root->right->parent  )
    {
        //code+='1';
        code+='1'+NYTCode(root->right);
    }
    else if(root->left!=NULL && root->left->parent)
    {
        //code+='0';
        code+=NYTCode(root->left)+'0';
    }

return code;
}*/






void adaptiveHuffman::updateWeight(Node *root)
{     //cout<<"jj"<<endl;
    if(root->left==NYT){return;}  // is NYT
    if(root->parent){root->weight++;}
    if(root->right->parent){updateWeight(root->right);}//cout<<"jj"<<endl;
    else if(root->left->parent){updateWeight(root->left);}
     //cout<<"tt"<<endl;
}






void adaptiveHuffman::Switch(Node *root)
{
    Node *temp;
    //int tempKey;
    if(root->left==NYT){return;}

    if(root->left->weight > root->right->weight)
    {
       temp=root->right;
       root->right=root->left;
       root->left=temp;
       //tempKey=root->right->key;
       //root->right->key=root->left->key;
       //root->left->key=tempKey;


    }
    if(root->right->parent){Switch(root->right);}
    else if(root->left->parent){Switch(root->left);}

}

bool b = 1;
Node* adaptiveHuffman::Insert(Node *root1,char c)
{

    if(root1==NYT)
    {
        root1=new Node;
        root1->parent=1;
         root1->left=NYT;
         Node* node2=new Node;
        root1->right=node2;
        node2->left=NULL;
        node2->right=NULL;
        node2->symbol=c;
        node2->weight=1;
        //root1->left->weight=0;
        root1->weight=1;
       // root1->key=(2*m)-1;
        //root1->right->key=root1->key-1;
        //root1->left->key=root1->key-2;
      if(b) {b=0;root = root1;}
      return root1;
    }


      if(root1->left!=NULL&&(root1->left->parent||root1->left==NYT)){root1->left=Insert(root1->left,c);}
      else if(root1->right!=NULL && (root1->right->parent)){root1->right=Insert(root1->right,c);}


   /* else if(found(root,c))
    {
        tree=lookupSymbol(root,c);
        tree->weight++;
    }*/
    return root1;
}





