
#include <bits/stdc++.h>
using namespace std;

class Node {

    public:
        int data;
        Node* left;
        Node* right;

        Node(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }

    Node* insertinBST(Node* root, int val);
    Node* searchinBST(Node* root, int key);
    Node* deleteinBST(Node* root, int key);
    Node* inorderSucc(Node* ptr);
    Node* inorderPre(Node* ptr);
    void preorderR(Node* root);
    void inorderR(Node* root);
    void postorderR(Node* root);
    void preorderNR(Node* root);
    void inorderNR(Node* root);
    void postorderNR(Node* root);
    void LOP(Node* root);
};

Node* Node::insertinBST(Node* root, int val)
{
    if(root == NULL)
    {
        return new Node(val);
    }

    if(val > root->data)
    {
        root->right = insertinBST(root->right, val);
    }

    else if(val < root->data)
    {
        root->left = insertinBST(root->left, val);
    }

    else
    {
        cout<<"Duplicate Value!"<<endl;
        return root;
    }

    cout<<"Inserted Successfully!"<<endl;
    return root;
}

Node* Node::searchinBST(Node* root, int key)
{
    if(root == NULL)
    {
        return root;
    }

    if(root->data == key)
    {
        cout<<"Element Found!"<<endl;
        return root;
    }

    else if(key > root->data)
    {
        searchinBST(root->right, key);
    }

    else
    {
        searchinBST(root->left, key);
    }
}

Node* Node::deleteinBST(Node* root, int key)
{
    if(root == NULL)
    {
        return root;
    }

    if(key > root->data)
    {
        root->right = deleteinBST(root->right, key);
        return root;
    }

    else if(key < root->data)
    {
        root->left = deleteinBST(root->left, key);
        return root;
    }

    else
    {
        //If one of the child is NULL
        if(root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        else if(root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        else
        {
            Node* succ = root->right;
            Node* parsucc = succ;
            while(succ->left != NULL)
            {
                parsucc = succ;
                succ = succ->left;
            }

            if(parsucc != root)
                parsucc->left = succ->right;
            
            else
                parsucc->right = succ->right;

            root->data = succ->data;
            delete succ;
        }

        return root;
    }
}

//Recursive Traversals
void Node::preorderR(Node* root)
{
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    preorderR(root->left);
    preorderR(root->right);
}

void Node::inorderR(Node* root)
{
    if(root == NULL)
        return;

    inorderR(root->left);
    cout<<root->data<<" ";
    inorderR(root->right);
}

void Node::postorderR(Node* root)
{
    if(root == NULL)
        return;

    postorderR(root->left);
    postorderR(root->right);
    cout<<root->data<<" ";
}

//Non - Recursive Traversals
void Node::preorderNR(Node* root)
{
    if(root == NULL)
        return;

    stack<Node*> s;
    s.push(root);

    while(!s.empty())
    {
        Node* t = s.top();
        cout<<t->data<<" ";
        s.pop();

        if(t->right != NULL)
            s.push(t->right);

        if(t->left != NULL)
            s.push(t->left);

    }
}

void Node::inorderNR(Node* root)
{
    if(root == NULL)
        return;

    stack<Node*> s1;
    Node* curr = root;

    while(curr != NULL || s1.empty() == false)
    {
        while(curr != NULL)
        {
            s1.push(curr);
            curr = curr->left;
        }

        Node* t = s1.top();
        s1.pop();
        cout<<t->data<<" ";
        curr = t->right;
    }
}

void Node::postorderNR(Node* root)
{
    if(root == NULL)
        return;

    stack<Node*> s1;
    stack<Node*> s2;

    s1.push(root);

    while(!s1.empty())
    {
        Node* t = s1.top();
        s1.pop();
        s2.push(t);

        if(t->left != NULL)
            s1.push(t->left);
            
        if(t->right != NULL)
            s1.push(t->right);

    }

    while(!s2.empty())
    {
        Node* t = s2.top();
        cout<<t->data<<" ";
        s2.pop();
    }
}

void Node::LOP(Node* root)
{
    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int count = q.size();

        while(count > 0)
        {
            Node* t = q.front();
            cout<<t->data<<" ";
            q.pop();

            if(t->left != NULL)
                q.push(t->left);

            if(t->right != NULL)
                q.push(t->right);

            count--;
        }
    }
}

int main()
{
    Node BST(0);
    Node* root = NULL;
    int choice;

    while(1)
    {
        int no_of_nodes, key;

        cout<<"\n\n--------------------------------------------------\n";
        cout<<"                       BST                         ";
        cout<<"\n--------------------------------------------------\n";
        cout<<"1. Insert\n2. Search\n3. Delete\n4. Display\n0. Exit the Program\n";
        cout<<"--------------------------------------------------\n";
        cout<<"Enter the Choice - ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"\nEnter the number of nodes - ";
                cin>>no_of_nodes;

                while(no_of_nodes--)
                {
                    int val;

                    cout<<"\nEnter value = ";
                    cin>>val;

                    root = BST.insertinBST(root, val);
                }

                cout<<"\nBST Constructed Sucessfully!"<<endl;
            break;
            
            case 2:
                cout<<"\nEnter the value to search = ";
                cin>>key;
                BST.searchinBST(root, key);
            break;

            case 3:
                cout<<"\nEnter the value to delete = ";
                cin>>key;
                BST.deleteinBST(root, key);
                cout<<"\nElement Deleted Successfully!"<<endl;
            break;

            case 4:

                cout<<"Recursive Preorder - \n";
                BST.preorderR(root);
                cout<<"\nNon - Recursive Preorder - \n";
                BST.preorderNR(root);
                cout<<"\n"<<endl;

                cout<<"Recursive Inorder - \n";
                BST.inorderR(root);
                cout<<"\nNon - Recursive Inorder - \n";
                BST.inorderNR(root);
                cout<<"\n"<<endl;

                cout<<"Recursive Postorder - \n";
                BST.postorderR(root);
                cout<<"\nNon - Recursive Preorder - \n";
                BST.postorderNR(root);
                cout<<"\n"<<endl;

                cout<<"Level Order Printing - "<<endl;
                BST.LOP(root);
            break;

            case 0:
                cout<<"Thank You!"<<endl;
                exit(0);
            break;

            default:
                cout<<"\nInvalid Choice!"<<endl;
            break;
        }
        
    }

    return 0;
}