// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
// C N T U T B N R   R E F O   T I G W T   R C E   E R S N A I N
//  o s r c   i a y t e   r m s r n   i h b a k t r p e e t t o 
////////////////////////////////////////////////////////////////
//\         \ \      \    \    \ \      \     \    \  \     \   
// C     u   a b      t    f    a s      c     t    o  p     h     
//  o   r c     i   y  r    r      t   g  o   s i    f  a   t e   
//   n t   t     n r    e    o      r n    n i   n       r n   s s
//    s           a      e    m      i      s     g       e     i 
//=======^=======t=======T======================================
//              n e       h                       y tree. It
//         a   i   g   .   e whole i              r
//          n       e s            n              a
//---v-------d-------r-------------p--------------n-------------
//                                 u              i
//                                 t represents a b
////////////////////////////////////////////////////////////////
//
//                           r r
//                           e e
//                           g p
//                           e r
//                       . T t e
//                       s h n s
//                       i e i e     e a
//                       s     n e r u n
//                       e     t h o l d a p
//                       h     s t o a     a         d b
//                       t         t v     i f p     l i
//                       n                 r o a     i n e w
//                       e                     r     h a e i e
// c                     r                     e s a c r r t h
// o                 s o a                     n n     y t h t
// n         , o     r f p                     t i
// t         o n r t i                         h a
// a         r e o w a                         e t
// i     d b e     o p                         s n
// n n i e y z                                 i o
// s a n w                                     s c
//     t o
//     e l
//     g l           . . . . . . . . , . . . . . . . . . . . . .
//     e o           .
//     r f           .      a    a(b(c))(d(e))
//                   .     / \
// same structure.        /   \
//                   .   b     d 
//    Always The     .  /     /
//     start integer . c     e
//        to values  .
// construct will    .
// the       be      .
// left      less    .
// child     than    .
// node      or      .
// of        equal   .
// the       to      .
// parent    10^5.   
//  first            .
//     if            .
//     it            .
// exists. 
////////////////////////////////////////////////////////////////
// Example:                                                    2
// Input:                                     "4(2(3)(1))(6(5))"
// Output:                                           3 2 1 4 5 6
// Explanation:                                             4
//                                                         / \
//                                                        /   \
//                                                       2     6
//                                                      / \   / 
//                                                     3   1 5   
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
////////////////////////////////////////////////////////////////
// Constraints:
// 1 <= |str| <= 10^5
////////////////////////////////////////////////////////////////
# include <iostream>
# include <string>
# include <utility> // move
# include <cctype>  // isdigit
////////////////////////////////////////////////////////////////
using namespace std;
///////////////////////////////////////////////////////////////_
class Node {
public:
    int   data;
    Node* left  = nullptr;
    Node* right = nullptr;
    Node( int data ): data( data ) {}
};
////////////////////////////////////////////////////////////////
void inorder( Node* root ){
    if( root ){
        inorder( root->left );
        cout << root->data << " ";
        inorder( root->right );
    }
}
////////////////////////////////////////////////////////////////
class Solution {
private:
    int    j;
    string str;
// _-_ _-_ _-_ _-_ _-_ _-_ _-_ _-_ _-_ _-_ _-_ _-_ _-_ _-_ _-_ _
    Node* cons(); //  -   -   -   -   -   -   -   -   -   -   -
public:
    Node* treeFromString( string str );
};
////////////////////////////////////////////////////////////////
// 1(2)(3) 
Node* Solution::cons() {
    Node* p{};
    int num{};
    // get the number if exists
    if( str[ j ] == ')' ) goto EXIT;
    for(; isdigit( str[ j ]) != 0; ++j ){
        num *= 10;
        num += str[ j ] - '0';
    }
    p = new Node( num );
    if( str[ j ] == '(' ){
        ++j;
        p->left = cons();
        if( j < str.size() and str[ j ] == '(' ){
            ++j;
            p->right = cons();
        }
    }
 EXIT:
    ++j;
    return p;
}
////////////////////////////////////////////////////////////////
Node* Solution::treeFromString( string str ){
    // Discard trivial inputs
    if( str.empty() or str == "()" ) return nullptr;
    if( str.back() != ')' ) return new Node( stoi( str ));
    // Initialize object's state
    j = 0;
    this->str = move( str );
    // Construct the tree and let's go
    return cons();
}
////////////////////////////////////////////////////////////////
int main() {
    inorder( Solution().treeFromString( "4(2(3)(1))(6(5))" ));
}
////////////////////////////////////////////////////////////////
// Test Cases Passed:                              11010 / 11010
// Total Points Scored:                                    4 / 4
// Your Total Score:                                         994
// Total Time Taken:                                        0.15
// Your Accuracy:                                           100%
// Attempts No.:                                               1
////////////////////////////////////////////////////////////////
//
