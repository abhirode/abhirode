
#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int hashFunction(int value)
{
    return value%10;
}

bool isCollision(int arr[], int hashkey)
{
    if(arr[hashkey] != -1)
    {
        return true;
    }

    return false;
}

int main()
{
    int hashTable[MAX], size, choice;
    char repeat;
    cout<<"\nEnter the size of Hash Table - ";
    cin>>size;
    memset(hashTable, -1, sizeof(hashTable));

    while(1)
    {
        int value, hashKey, flag=0, temp, index;
        cout<<"\n-------------------------------------------------\n";
        cout<<"1. Insert\n2. Search\n3. Delete\n4. Display Hash Table\n0. Exit the Program\n";
        cout<<"-------------------------------------------------\n";
        cout<<"Enter the Choice - ";
        cin>>choice;

        switch (choice)
        {
            case 1:

                cout<<"\nEnter value - ";
                cin>>value;
                hashKey = hashFunction(value);

                if(isCollision(hashTable, hashKey))
                {
                    temp = hashTable[hashKey];
                    hashTable[hashKey] = value;
                    for(int i=hashKey+1; i<size; i++)
                    {
                        if(hashTable[i] == -1)
                        {
                                hashTable[i] = temp;
                                flag=1;
                                break;
                        }
                    }

                    //Circular Array
                    for(int i=0; i<hashKey; i++)
                    {
                        if(hashTable[i] == -1)
                        {
                            hashTable[i] = temp;
                            flag=1;
                            break;
                        }
                    }
                }

                else
                {
                    hashTable[hashKey] = value;
                    flag=1;
                }

                if(flag == 1)
                    cout<<"Inserted Successfully!"<<endl;
                
                else
                    cout<<"Hash Overflow!"<<endl;
                break;



            case 2:
                cout<<"Enter the value - ";
                cin>>value;
                hashKey = hashFunction(value);
                
                for(int i=hashKey; i<size; i++)
                {
                    if(hashTable[i] == value)
                    {
                        flag=1;
                        index = i;
                        break;
                    }
                }

                //Circular Array
                for(int i=0; i<hashKey; i++)
                {
                    if(hashTable[i] == value)
                    {
                        flag=1;
                        index = i;
                        break;
                    }
                }

                if(flag == 1)
                    cout<<"Element found at "<<index<<endl;

                else    
                break;

            case 3:
                cout<<"Enter value - ";
                cin>>value;
                hashKey = hashFunction(value);
                for(int i=hashKey; i<size; i++)
                {
                    if(hashTable[i] == value)
                    {
                        flag=1;
                        index=i;
                        break;
                    }
                }

                //Circular Array
                for(int i=0; i<hashKey; i++)
                {
                    if(hashTable[i] == value)
                    {
                        flag=1;
                        index=i;
                        break;
                    }
                }
                    
                if(flag=1)
                {
                    cout<<"Element found at "<<index<<endl;
                    hashTable[index]=-1;
                    cout<<"ELEMENT DELETED SUCCESSFULLY!"<<endl;
                }

                else
                {
                    cout<<"Element not found!"<<endl;
                }
                break;

            case 4:
                cout<<"HashTable is :- "<<endl;
                for(int i=0; i<size; i++)
                {
                    cout<<hashTable[i]<<" | ";
                }
                break;

            case 0:
                cout<<"Thank You!";
                exit(0);
                break;

            default:
                cout<<"Invalid Choice!";
                break;
        }
    }
    
    return 0;
}