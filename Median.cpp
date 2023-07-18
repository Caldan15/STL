#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Data{
public:
    int x;
    int size;
    //creating a vector
    vector <int> a;

    void input(){
        cout<<"Enter the size: ";
        cin>>size;
        cout<<"Enter the values: ";
        for(int i=0;i<size;i++)
        {
            cin>>x;
            //storing the values in the vector
            a.push_back(x);
        }
        //sorting
        sort(a.begin(),a.end());
    }

    int median(){
        //logic to find median
        if(size%2==1)
        {
            return a[size/2];
        }
        else
        {
            return (a[(size/2)-1]+a[(size/2)])/2;
        }
    }
};

int main()
{
    Data MyData;
    MyData.input();
    int median = MyData.median();
    cout<<median<<endl;


}
