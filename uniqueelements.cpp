#include <iostream>
#include<set>
using namespace std;

int main()
{
    int array[]={20,33,65,43,89,45,68,30,33,67,55,23,20,36,5,43,89,45,68,30,33,67,22,86,10,8,48,20,76,90,41,56,68,54,36,76,33,90,5,8};
    cout<<"Displaying Array elements"<<endl;
    for(int i:array)
        cout<<i<<" ";
    cout<<"\n";
    int n = sizeof(array)/sizeof(array[0]);
    cout<<"The number of elements in the array "<<n<<endl;
    set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(array[i]);
    }
    cout<<"Number of unique elements in the array "<<s.size()<<endl;
    return 0;
}
