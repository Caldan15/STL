#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void LISeq( int *a, int n )
{
    int  i, j, max = 0;
    vector<int> lis(n);
    fill(lis.begin(),lis.end(),1);
    for ( i = 1; i < n; i++ )
        for ( j = 0; j < i; j++ )
            if ( a[i] > a[j] && lis.at(i) < lis.at(j) + 1)
                lis.at(i) = lis.at(j) + 1;
    max = *max_element(lis.begin(),lis.end());

    int tmp = max;
    vector<int> index;
    for( i = n - 1; i >= 0; --i )
    if( lis.at(i) == tmp )
    {
        index.push_back( i );
        --tmp;
    }
    reverse( index.begin(), index.end());
    cout<<"\nLength :"<<max<<endl;
    cout<<"\nThe values : "<<endl;
    for(auto s:index)
    {
        cout<<a[s]<<endl;
    }
   /* Free memory to avoid memory leak */
   lis.clear();
   //return max;
}

int main()
{
    int a[]={7 ,6 ,2 ,3 ,4 ,1 ,8 ,5 ,9 ,10};
    int n = sizeof(a) / sizeof(a[0]);

    LISeq(a,n);

    return 0;
}
