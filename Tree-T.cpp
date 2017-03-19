#include <iostream>
using namespace std;
class BT;
class Node
{

public:
    int data;
    Node *r, *l;
    Node (int x)
    {
        data=x;
        r=l=NULL;
    }
    Node()
    {

    }
    friend class BT;
};
class BT
{
    public:
    Node *root1,*root2;

    BT()
    {
        root1=root2=NULL;
    }
    /*
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
    */
    Node* newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->l = temp->r = NULL;
    return temp;
}
void Preorder(Node* temp)
    {

     if (temp == NULL)
          return;
    cout<<temp->data<<endl;
    Preorder(temp->l);
    Preorder(temp->r);
    }
    Node *getR1()
    {
        return root1;
    }
    Node *getR2()
    {
        return root2;
    }
  int identicalTrees(Node* a, Node* b)
    {
    if (a==NULL && b==NULL)
        return 1;
    if (a!=NULL && b!=NULL)
    {
        return
        (
            a->data==b->data && identicalTrees(a->l, b->l) && identicalTrees(a->r, b->r)
        );
    }
    return 0;
    }

};
int main()
{

    BT b;

    Node *root1 = b.newNode(1);
    root1->l = b.newNode(2);
    root1->r = b.newNode(3);
    root1->l->l = b.newNode(4);
    root1->l->r = b.newNode(5);
    b.Preorder(b.getR1());
    Node *root2 = b.newNode(1);
    root2->l = b.newNode(2);
    root2->r = b.newNode(3);
    root2->l->l = b.newNode(4);
    root2->l->r = b.newNode(5);
    b.Preorder(b.getR2());
    if(b.identicalTrees(root1, root2))
        cout<<"Both tree are identical.";
    else
        cout<<"Trees are not identical.";

}
