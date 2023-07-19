#includebitsstdc++.h
using namespace std;
struct node
{
    int element;
    struct node left,right;
    int ht;

};

node insert(node ,int);
node Delete(node ,int);
void preorder(node );
void inorder(node );
int height( node );
node rotateright(node );
node rotateleft(node );
node RR(node );
node LL(node );
node LR(node );
node RL(node );
int balanceFactor(node );
int main()
{
    node root=NULL;
    int x,n,i,option;
    do {
        cout  “1. Create AVL Treen“;
        cout  “2. Delete Elementn“;
        cout  “3. End Programn“;
        cout  “Enter your choice “;
        cin  option;
        switch(option)
        {
            case 1 cout  “nEnter no. of elements  “;
                    cin  n;
                    root = NULL;
                    for( i = 0; i  n;i++) {

                        cout  “Enter element of tree “;
                        cin  x;
                        root = insert(root,x);
                    }
                    cout  “nPreorder sequencen“;
                    preorder(root);
                    cout  “nnInorder sequencen“;
                    inorder(root);
                    break;
             
            case 2 cout  “Enter a element to be deleted  “;
                    cin  x;
                    root = Delete(root,x);
                    cout  “Preorder sequencen“;
                    preorder(root);
                    cout  “nInorder sequencen“;
                    inorder(root);
                    break;
        }
    }while(option!=3);

    return 0;

}

node  insert(node T,int x)
{

    if(T == NULL){

        T = (node)malloc(sizeof(node));
        T - element = x;
        T - left = NULL;
        T - right = NULL;
    }
    else

        if(x  T-element)        
        {

            T - right = insert(T - right,x);
            if(balanceFactor(T) == –2)
                if( x  T - right - element)
                    T = RR(T);
                else
                    T = RL(T);

        }
        else
            if(xelement)
            {
                T - left = insert(T - left,x);
                if(balanceFactor(T)==2)
                    if(x  T- left - element)
                        T=LL(T);
                    else
                        T=LR(T);

            }

        T - ht = height(T);

        return(T);
}
node  Delete(node T,int x)
{
    node p;

    if(T == NULL)
    {
        return NULL;
    }
    else
        if(x  T-element)    
        {
            T - right = Delete(T - right,x);
            if(balanceFactor(T) == 2)
                if(balanceFactor(T - left) = 0)
                    T = LL(T);
                else
                    T = LR(T);
        }
        else
            if(x  T - element)
            {
                T - left = Delete(T-left,x);
                if(balanceFactor(T)==-2)    
                    if(balanceFactor(T-right)=0)
                        T=RR(T);
                    else
                        T=RL(T);
            }
            else
            {
                if(T - right != NULL)
                {
                    p = T - right;

                    while(p - left != NULL)
                        p = p - left;

                    T - element = p - element;
                    T - right = Delete(T - right,p-element);

                    if(balanceFactor(T) == 2)
                        if(balanceFactor (T - left) = 0)
                            T=LL(T);
                        else
                            T=LR(T);
                }
                else
                    return(T-left);
            }
    T -ht = height(T);
    return(T);
}
int height(node T)
{

    int lh,rh;
    if(T == NULL)
        return(0);
    if( T - left == NULL)
        lh = 0;
    else
        lh = 1 + T - left - ht;

    if(T - right == NULL)
        rh = 0;
    else
        rh=1+T-right-ht;

    if(lh  rh)
        return(lh);

    return(rh);
}

node  rotateright(node x)
{

    node y;
    y = x - left;
    x - left = y - right;
    y - right = x;
    x - ht = height(x);
    y - ht = height(y);
    return(y);
}

node  rotateleft(node x)
{
    node y;
    y = x - right;
    x - right = y - left;
    y - left = x;
    x - ht = height(x);
    y - ht = height(y);
    return(y);
}

node  RR(node T)
{

    T = rotateleft(T);
    return(T);
}

node  LL(node T)
{
    T = rotateright(T);
    return(T);
}

node  LR(node T)
{

    T - left = rotateleft(T-left);
    T = rotateright(T);
    return(T);
}

node  RL(node T)
{
    T - right = rotateright(T-right);
    T = rotateleft(T);
    return(T);
}
int balanceFactor(node T)
{
    int lh,rh;
    if( T == NULL)
        return(0);
    if(T - left == NULL)
        lh = 0;
    else
        lh = 1 + T-left-ht;
    if(T - right == NULL)
        rh = 0;
    else
        rh = 1 + T - right - ht;
    return(lh-rh);
}

void preorder(node T)
{
    if( T != NULL)
    {
        cout  “Balance factor “  T - element  ” “  balanceFactor(T)  endl;
        preorder(T-left);
        preorder(T-right);
    }
}
void inorder(node T)
{

    if( T != NULL)
    {
        inorder(T-left);
        cout  “Balance Factor “ element” “  balanceFactor(T)  endl;
        inorder(T-right);
    }
}