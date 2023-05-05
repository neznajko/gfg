////////////////////////////////////////////////////////////////
// Permutations of a given string
////////////////////////////////////////////////////////////////
// Given a string S. The task is to print all unique 
// permutations of the given string in lexicographically sorted
// order.
////////////////////////////////////////////////////////////////
// Example: 2
////////////////////////////////////////////////////////////////
// Input: ABSG
// Output: ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA 
// BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA 
// SGAB SGBA
// Explanation: Given string ABSG has 24 permutations.
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(n!*n)
// Expected Space Complexity: O(n)
////////////////////////////////////////////////////////////////
# include <vector>
# include <string>
# include <iostream>
# include <algorithm>
# include <utility>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
// This is one algorithm that I know from Knuth books. Despite
// the fact that I've wrote it in many languages I have 
// forgotten:) and had to rethink it again.
class Solution {
    string s;
    int back{ -1 };
    vector<string> answ;
    void Visit(){
        answ.push_back( string( s.begin() + 1, s.end()));
    }
    int FindI(){
        int i{ back - 1 };
        for(; s[ i ] >= s[ i + 1 ]; --i ){
        }
        return i;
    }
    int FindJ( char value ){
        int j{ back };
        for(; s[ j ] <= value; --j ){
        }
        return j;
    }
    void Reverse( int i ){
        int j{ back };
        while( i < j ){
            swap( s[ i++ ], s[ j-- ]);
        }
    }
public:
    vector<string> find_permutation( string& s );
};
////////////////////////////////////////////////////////////////
int main(){
    string s{ "DCBA" };
    vector<string> ans{ Solution().find_permutation( s )};
    for( const auto& i: ans ){
        cout << i << " ";
    }
}
////////////////////////////////////////////////////////////////
vector<string> Solution::find_permutation( string& s ){
    if( s.empty()){
        return {};
    }
    back = ( int )s.size();
    s.push_back(' ');
    sort( s.begin(), s.end());
    this->s = move( s );
    while( true ){
        Visit();
        int i{ FindI()};
        if( !i ){
            break;
        }
        int j{ FindJ( this->s[ i ])};
        swap( this->s[ i ], this->s[ j ]);
        Reverse( i + 1 );
    }
    return answ;
}
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                      5 / 5
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1102
// Total Time Taken:                                        0.01
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
