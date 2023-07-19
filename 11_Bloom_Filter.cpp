
#include <bits/stdc++.h>
#define MAX 100
using namespace std;

class BloomFilter {
    public:
        int array[MAX];
        int n;

    void insert(int val);
    void search(int val);
    void display();

    //Hash functions for integer
    int hashFunction1(int val, int size);
    int hashFunction2(int val, int size);

    //Hash functions for string
    int H1(string s, int size);
    int H2(string s, int size);

    BloomFilter(int size)
    {
        n = size;
        for(int i=0; i<n; i++)
            array[i] = 0;
        memset(array, 0, sizeof(array));
    }
};

int BloomFilter::hashFunction1(int val, int size)
{
    return val%size;
}

int BloomFilter::hashFunction2(int val, int size)
{
    return (val/size)%size;
}

int BloomFilter::H1(string s, int size)
{
    int hk = 0;
    for(int i=0; i<size; i++)
    {
        hk = hk + (int)s[i];
    }

    hk = hk%size;
    return hk;
}

int BloomFilter::H2(string s, int size)
{
    int hk = 0;
    for(int i=0; i<size; i++)
    {
        hk = hk + ((int)s[i])*3;
    }

    hk = hk%size;
    return hk;
}

void BloomFilter::insert(int val)
{
    int hk1, hk2;

    hk1 = hashFunction1(val, n);
    hk2 = hashFunction2(val, n);

    if(array[hk1] == 1 && array[hk2] == 1)
    {
        cout<<"ELEMENT IS PROBABILY PRESENT!"<<endl;
    }

    else
    {
        array[hk1] = 1;
        array[hk2] = 1;
    }
}

void BloomFilter::search(int val)
{
    int hk1, hk2;

    hk1 = hashFunction1(val, n);
    hk2 = hashFunction2(val, n);

    if(array[hk1] == 1 && array[hk2] == 1)
    {
        cout<<"ELEMENT IS FOUND!"<<endl;
    }

    else
    {
        cout<<"ELEMENT NOT FOUND!"<<endl;
    }
}

void BloomFilter::display()
{
    cout<<"BIT ARRAY HASH TBALE IS :-\n"<<endl;
    cout<<"| ";
    for(int i=0; i<n; i++)
    {
        cout<<array[i]<<" | ";
    }
}

int main()
{
    int n, choice;
    cout<<"Enter the size of hash table = ";
    cin>>n;
    BloomFilter b(n);

    while(1)
    {
        int val;

        cout<<"\n--------------------------------------------------\n";
        cout<<"1. Insert\n2. Look Up\n3. Display Bit Array\n0. Exit the Program\n";
        cout<<"--------------------------------------------------\n";
        cout<<"\nEnter the choice = ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter the element  = ";
                cin>>val;
                b.insert(val);
                cout<<"ELEMENT INSERTED!"<<endl;
            break;  
            
            case 2:
                cout<<"Enter the element to search  = ";
                cin>>val;
                b.search(val);
            break;

            case 3:
                b.display();
            break;

            case 0:
                cout<<"THANK YOU!"<<endl;
                exit(0);
            break;

            default:
                cout<<"INVALID CHOICE!"<<endl;
            break;
        }
    }

    return 0;
}