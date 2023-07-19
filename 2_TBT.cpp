
#include <bits/stdc++.h>
using namespace std;

class Node {

    public:
        int data;
        Node* left;
        Node* right;
        bool lthread;
        bool rthread;
    
    Node* insertinTBT(Node* root, int val);
    Node* searchinTBT(Node* root, int val);
    Node* deleteinTBT(Node* root, int val);
    Node* caseA(Node* root, Node* par, Node* ptr);
    Node* caseB(Node* root, Node* par, Node* ptr);
    Node* caseC(Node* root, Node* par, Node* ptr);
    Node* inorderSucc(Node* ptr);
    Node* inorderPre(Node* ptr);
    void preoderR(Node* root);
    void inorderR(Node* root);
    void postorderR(Node* root);
    void preoderNR(Node* root);
    void inorderNR(Node* root);
    Node* leftMost(Node* n);
};

Node* Node::insertinTBT(Node* root, int val)
{
    //1). Set ptr and par
    Node* ptr = root;
    Node* par = NULL;

    //2). While ptr is not NULL 
    //check for duplicate value and look for proper position to insert a new node
    while(ptr != NULL)
    {
        if(ptr->data == val)
        {
            cout<<"\nDuplicate Value!"<<endl;
            return root;
        }

        par = ptr;

        if(ptr->data > val)
        {
            if(ptr->lthread == false)
                ptr = ptr->left;
            
            else
                break;
        }

        else
        {
            if(ptr->rthread == false)
                ptr = ptr->right;

            else    
                break;
        }
    }

    //3). Make a new node and insert it depending on the cases
    //Case 1 - Root Node

    Node* temp = new Node;
    temp->data = val;
    temp->lthread = true;
    temp->rthread = true;

    //Case 1 - Root Node
    if(par == NULL)
    {
        root = temp;
        temp->left = NULL;
        temp->right = NULL;
    }

    //Case 2 - Left Child
    else if(val < par->data)
    {
        temp->left = par->left;
        temp->right = par;
        par->left = temp;
        par->lthread = false;
    }

    //Case 3 - Right Child
    else
    {
        temp->right = par->right;
        temp->left = par;
        par->right = temp;
        par->rthread = false;
    }

    cout<<"Inserted Successfully!"<<endl;
    return root;
}

Node* Node::searchinTBT(Node* root, int val)
{
    if(root == NULL || root->data == val)
    {
        cout<<"Element Found!"<<endl;
        return root;
    }

    if(val > root->data)
    {
        if(root->rthread == false)
            searchinTBT(root->right, val);
    }

    else
    {
        if(root->lthread == false)
            searchinTBT(root->left, val);
    }
}

Node* Node::deleteinTBT(Node* root, int val)
{
    int found = 0;
    Node* ptr = root;
    Node* par = NULL;

    while(ptr != NULL)
    {
        if(ptr->data == val)
        {
            found = 1;
            break;
        }

        par = ptr;

        if(val < ptr->data)
        {
            if(ptr->lthread == false)
                ptr = ptr->left;

            else
                break;
        }

        else
        {
            if(ptr->rthread == false)
                ptr = ptr->right;

            else
                break;
        }
    }

    if(found == 0)
    {
        cout<<"Element not found!"<<endl;
        return root;
    }

    //Case 3 - Node having both child
    if(ptr->lthread == false && ptr->rthread == false)
        caseC(root, par, ptr);

    //Case 2 (A) - Only left child
    else if(ptr->lthread == false)
        caseB(root, par, ptr);

    else if(ptr->rthread == false)
        caseB(root, par, ptr);

    //Case 1 - No child
    else
        caseA(root, par, ptr);

    return root;
}

Node* Node::caseC(Node* root, Node* par, Node* ptr)
{
    Node* parrsucc = ptr;
    Node* succ = ptr->right;

    while(succ->left != NULL && succ->lthread == false)
    {
        parrsucc = succ;
        succ = succ->left;
    }

    ptr->data = succ->data;

    if(succ->lthread == true && succ->rthread == true)
        root = caseA(root, parrsucc, succ);

    else
        root = caseB(root, parrsucc, succ);

    return root;
}

Node* Node::caseB(Node* root, Node* par, Node* ptr)
{
    Node* child;

    if(ptr->lthread == false)
        child = ptr->left;

    else
        child = ptr->right;

    if(par == NULL)
        root = child;

    if(ptr == par->left)
        par->left = child;

    else
        par->right = child;

    Node* p = inorderPre(ptr);
    Node* s = inorderPre(ptr);

    if(ptr->left == false)
        p->right = s;

    else
    {
        if(ptr->right == false)
            s->left = p;
    }

    delete ptr;
    return root;
}

Node* Node::caseA(Node* root, Node* par, Node* ptr)
{
    if (par == NULL)
        root = NULL;

    else if(ptr == par->left) 
    {
        par->lthread = true;
        par->left = ptr->left;
    }

    else
    {
        par->rthread = true;
        par->right = ptr->right;
    }

    delete ptr;
    return root;
}

Node* Node::inorderSucc(Node* ptr)
{
    if(ptr->rthread == true)
        return ptr->right;

    ptr = ptr->right;
    while(ptr->left != NULL && ptr->lthread == false)
    {
        ptr = ptr->left;
    }

    return ptr;
}

Node* Node::inorderPre(Node* ptr)
{
    if(ptr->lthread == true)
        return ptr->left;

    ptr = ptr->left;
    while(ptr->right != NULL && ptr->rthread == false)
    {
        ptr = ptr->right;
    }

    return ptr;
}

//Recursive Traversal
void Node::preoderR(Node* root)
{
    if(root == NULL)
        return;

    cout<<root->data<<" ";

    if(root->lthread == false)
        preoderR(root->left);

    if(root->rthread == false)
        preoderR(root->right);
}

void Node::inorderR(Node* root)
{
    if(root == NULL)
        return;

    if(root->lthread == false)
        inorderR(root->left);

    cout<<root->data<<" ";

    if(root->rthread == false)
        inorderR(root->right);
}

void Node::postorderR(Node* root)
{
    if(root == NULL)
        return;

    if(root->lthread == false)
        postorderR(root->left);

    if(root->rthread == false)
        postorderR(root->right);

    cout<<root->data<<" ";
}

//Non-Recursive Traversals
void Node::preoderNR(Node* root)
{

    if(root == NULL)
    {
        cout<<"TBT is Empty!"<<endl;
        return;
    }

    else
    {
        Node* curr = root;
        while(curr != NULL)
        {
            cout<<curr->data<<" ";
            
            if(curr->lthread == false)
                curr = curr->left;

            else if(curr->rthread == false)
                curr = curr->right;

            else
            {
                while(curr != NULL && curr->rthread == true)
                    curr = curr->right;

                if(curr != NULL)
                    curr = curr->right;
            }
        }
    }
}

Node* Node::leftMost(Node* n)
{
    if(n == NULL)
        return NULL;

    while(n->left != NULL && n->lthread == false)
        n = n->left;
    
    return n;
}

void Node::inorderNR(Node* root)
{
    if(root == NULL)
        return;

    Node* curr = leftMost(root);

    while(curr != NULL)
    {
        cout<<curr->data<<" ";

        if(curr->rthread == true)
            curr = curr->right;

        else
            curr = leftMost(curr->right);
    }
}

int main()
{

    Node TBT;
    Node* root = NULL;
    int choice;

    while(1)
    {
        int no_of_nodes, key;

        cout<<"\n\n---------------------------------------------\n";
        cout<<"                  TBT                   \n";                             
        cout<<"---------------------------------------------\n";
        cout<<"1. Insert\n2. Search\n3. Delete\n4. Display\n0. Exit the Program\n";
        cout<<"-----------------------------------------\n";
        cout<<"Enter the Choice - ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"\nNumber of nodes = ";
                cin>>no_of_nodes;
                while(no_of_nodes--)
                {
                    int val;
                    cout<<"\nEnter Value = ";
                    cin>>val;
                    root = TBT.insertinTBT(root, val);
                }

                cout<<"\bTBT Constructed!"<<endl;
            break;

            case 2:
                cout<<"\nEnter value to search = ";
                cin>>key;
                TBT.searchinTBT(root, key);
            break;

            case 3:
                cout<<"\nEnter element to delete = ";
                cin>>key;
                root = TBT.deleteinTBT(root, key);
            break;

            case 4:
                cout<<"\nRecursive Preorder - \n";
                TBT.preoderR(root);
                cout<<"\nNon - Recursive Preorder - \n";
                TBT.preoderNR(root);
                cout<<"\n"<<endl;

                cout<<"Recursive Inorder - \n";
                TBT.inorderR(root);
                cout<<"\nNon - Recursive Inorder - \n";
                TBT.inorderNR(root);
                cout<<"\n"<<endl;

                cout<<"Recursive Postorder - \n";
                TBT.postorderR(root);
                cout<<endl;
            break;

            case 0:
                cout<<"Thank You!"<<endl;
                exit(0);
            break;

            default:
                cout<<"Invalid Choice!"<<endl;
            break;
        }

    }

    return 0;
}