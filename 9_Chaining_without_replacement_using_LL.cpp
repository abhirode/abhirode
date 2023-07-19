
#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

int hashFunction(int val, int size)
{
    return val%size;
}

bool checkCollision(Node* a[], int hk)
{
    if(a[hk] != NULL)
    {
        return true;
    }

    return false;
}

int main()
{
    int n, choice;

    cout<<"Enter the size of hash table = ";
    cin>>n;

    Node* array[n];

    for(int i=0; i<n; i++)
    {
        array[i] = NULL;
    }

    while(1)
    {
        int hk, val, found=0;
        cout<<"\n--------------------------------------------\n";
        cout<<"1. Insert\n2. Search\n3. Delete\n4. Display\n0. Exit the Program\n";
        cout<<"--------------------------------------------\n";
        cout<<"Enter the choice = ";
        cin>>choice;

        switch(choice)
        {

            case 1:
            {
                cout<<"Enter value = ";
                cin>>val;
                hk = hashFunction(val, n);

                Node* temp = new Node(val);

                if(checkCollision(array, hk) == false)
                {
                    array[hk] = temp;
                }

                else
                {
                    Node* curr = array[hk];
                    while(curr->next != NULL)
                    {
                        curr = curr->next;
                    }

                    curr->next = temp;
                }
                cout<<"INSERTED SUCCESSFULLY!"<<endl;
            }
            break;
            
            case 2:
            {
                cout<<"Enter value to search = ";
                cin>>val;

                hk = hashFunction(val, n);
                Node* curr = array[hk];

                while(curr != NULL)
                {
                    if(curr->data == val)
                    {
                        found = 1;
                        break;
                    }

                    else
                    {
                        curr = curr->next;
                    }
                }

                if(found == 1)
                    cout<<"ELEMENT FOUND!"<<endl;
                
                else
                    cout<<"ELEMENT NOT FOUND!"<<endl;
            }
            break;

            case 3:
            {
                cout<<"Enter value to deleted = ";
                cin>>val;
                hk = hashFunction(val, n);
                Node* curr = array[hk];
                Node* prev;

                while(curr != NULL)
                {
                    if(curr->data == val)
                    {
                        found = 1;
                        break;
                    }

                    else
                    {
                        prev = curr;
                        curr = curr->next;
                    }
                }

                if(found == 1)
                {
                    prev->next = curr->next;
                    delete curr;

                    cout<<"DELETED SUCCESSFULLY!"<<endl;
                }

                else
                {
                    cout<<"ELEMENT NOT FOUND!"<<endl;
                }
            }
            break;

            case 4:
                cout<<"\nHASH TABLE IS :-\n";
                for(int i=0; i<n; i++)
                {
                    cout<<i<<"  -->  ";
                    Node* curr = array[i];
                    while(curr != NULL)
                    {
                        cout<<curr->data<<"  ";
                        curr = curr->next;
                    }
                    cout<<endl;
                }
            break;

            case 0:
                cout<<"THANK YOU!"<<endl;
                exit(0);
            break;
        }
    }
    
    return 0;
}