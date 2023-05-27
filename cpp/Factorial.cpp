////////////////////////////////////////////////////////////////
// Factorials of large numbers
////////////////////////////////////////////////////////////////
// Given an integer N, find its factorial. Return a list of 
// integers denoting the digits that make up the factorial of N.
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N^2)
// Expected Auxilliary Space: O(1)                 that,s false!
////////////////////////////////////////////////////////////////
// Constraints: 1 ≤ N ≤ 1000
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <deque>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> factorial( int N );
};
////////////////////////////////////////////////////////////////
int main(){int N;cin>>N;Solution ob;vector<int>result=ob.
factorial(N);for(int i=0;i<result.size();++i){cout<<result[i];
}cout<<endl;}
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                  102 / 102
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1118
// Total Time Taken:                                        1.31
////////////////////////////////////////////////////////////////
void P( deque<int>& q, int n ){
    int c{};
    for( auto s{ q.size()}; s; --s ){
        c += q.back()* n;
        q.pop_back();
        q.push_front( c % 10 );
        c /= 10;
    }
    for(; c; c /= 10 ){
        q.push_front( c % 10 );
    }
}
///////////////////////////////////////////////////////////////=
vector<int> Solution::factorial( int N ){
    deque<int> q{ 1 };
    for( int n{ 2 }; n <= N; ++n ){
        P( q, n );
    }
    return vector<int>( q.begin(), q.end());
}
///////////////////////////////////////////////////////////////_
// log: The only way to handle greatness is to be great.
////////////////////////////////////////////////////////////////
