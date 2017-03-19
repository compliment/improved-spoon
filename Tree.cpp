#include <iostream>
using namespace std;
class BT;
class Node
{
    int data;
    Node *r, *l;
public:
    Node (int x)
    {
        data=x;
        r=l=NULL;
    }
    friend class BT;
};
class BT
{
    Node *root;
    public:
    BT()
    {
        root=NULL;
    }
    void createBT()
    {
        int x;
        cout<<"Creating Tree\n Enter root data\n PS: -1=NULL\n\n";
        cin>>x;
        root=create(x);
    }
    Node *create (int x)
    {
        if (x==-1)
            return NULL;
        Node *temp = new Node(x);
        int y;
        cout<<"LeftChild of "<<x<<"::";
        cin>>y;
        temp->l=create(y);
        cout<<"RightChild of "<<x<<"::";
        cin>>y;
        temp->r=create(y);
        return temp;
    }
    int searchBT(Node *temp, int x)
    {
        if (temp==NULL)
        {
            return 0;
        }
        if (temp->data==x)
        {
            return 1;
        }
        if (searchBT(temp->l,x))
        {
            return 1;
        }
        if (searchBT(temp->l,x))
        {
            return 1;
        }
    }
    void preorder(Node *temp)
    {
        if(temp==NULL)
        {
            return;
        }
        cout<<temp->data;
        preorder(temp->l);
        preorder(temp->r);
    }
   Node *getR()
    {
        return root;
    }
};
int main()
{
    BT b;
    b.createBT();
    int x;
    cout<<"Element to Search\n";
    cin>>x;
    int a=b.searchBT(b.getR(),x);
    if (a==1)
    {
        cout<<"Found";
    }
    if(a==0)
    {
        cout<<"Not Found";
    }


   // b.preorder();
}
