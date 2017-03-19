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
   /* void preorder(Node *temp)
    {
        if(temp==NULL)
        {
            return;
        }
        cout<<temp->data<<"\t";
        preorder(temp->l);
        preorder(temp->r);
    }
    */
   Node *getR()
    {
        return root;
    }
void Postorder(Node* temp)
    {
     if (temp==NULL)
        return;
     Postorder(temp->l);
     Postorder(temp->r);
     cout<<temp->data<<endl;
    }
void Inorder(Node *temp)
    {

     if (temp== NULL)
          return;
     Inorder(temp->l);
     cout<<temp->data<<endl;
      Inorder(temp->r);
    }
void Preorder(Node* temp)
    {

     if (temp == NULL)
          return;
     cout<<temp->data<<endl;
    Preorder(temp->l);
    Preorder(temp->r);
    }
};
int main()
{
    BT b;
    b.createBT();
    int x;
    cout<<"Preorder::\n";
   b.Preorder(b.getR());
   cout<<"Postorder::\n";
   b.Postorder(b.getR());
   cout<<"Inorder::\n";
   b.Inorder(b.getR());
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
}
