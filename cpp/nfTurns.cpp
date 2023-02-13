////////////////////////////////////////////////////////////////
// Number of Turns in Binary Tree
////////////////////////////////////////////////////////////////
// Given a binary tree and data value of two of its nodes. Find
// the number of turns needed to reach from one node to another
// in the given binary tree.
////////////////////////////////////////////////////////////////
// Example:                                                    1
// Input:                                             1
//                                                   / \
// 1 2 3 4 5 6 7 8 N N N 9 10                       /   \
//                                                 /     \
//                                                /       \
//                                               /         \
//                                              2           3
//                                             / \         / \
//                                            /   \       /   \
//                                           4     5     6     7
//                                          /           / \      
//                                         8           9   a      
//                                                first node = 5
//                                               second node = a
// Output:                                                     4
// Explanation:                      Turns will be at 2, 1, 3, 6
//////////////////////////////////////////////////////////////// 
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(Height of Tree)
////////////////////////////////////////////////////////////////
# include <iostream>
# include <queue>
# include <string>
# include <sstream>
# include <vector>
# include <algorithm>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
struct Node {
    int data;
    Node* left  = NULL;
    Node* right = NULL;
    Node( int data_):
        data( data_)
    {}
};
////////////////////////////////////////////////////////////////
Node* buildTree(string str){   
    // Corner Case
    if(str.length()==0||str[0]=='N')return NULL;
    // Creating vector of strings from input string after spliting by space
    vector<string>ip;istringstream iss(str);for(string str;iss>>str;)
    ip.push_back(str);
    // Create the root of the tree
    Node* root=new Node(stoi(ip[0]));
    // Push the root to the queue
    queue<Node*> queue;queue.push(root);
    // Starting from the second element
    int i=1;while(!queue.empty()&&i<ip.size()){
        // Get and remove the front of the queue
        Node* currNode=queue.front();
        queue.pop();
        // Get the current node's value from the string
        string currVal=ip[i];
        // If the left child is not null
        if(currVal!="N"){
            // Create the left child for the current Node
            currNode->left=new Node(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->left);}
        // For the right child
        i++;if(i>=ip.size())break;currVal=ip[i];
        // If the right child is not null
        if(currVal!="N"){
            // Create the right child for the current node
            currNode->right=new Node(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);}i++;}return root;}
////////////////////////////////////////////////////////////////
template <typename T>
std::ostream& operator<<( std::ostream& ostrm, const std::vector<T>& vec ){
    ostrm << "[";
    for( int j = 0, n = vec.size(); j < n; ++j ){
        ostrm << " " << vec[ j ] << " ,"[ j < n - 1 ];
    }
    return ostrm << "]";
}
////////////////////////////////////////////////////////////////
struct Record {
    enum { NONE, LEFT, RYTE };
    int   turn;
    Node* node;
};
////////////////////////////////////////////////////////////////
ostream& operator<<( ostream& os, const Record& rec ){
    return( os << "(" << "NLR"[ rec.turn ] << " " <<
            rec.node->data << ")" );
}
////////////////////////////////////////////////////////////////
typedef vector<Record> nav_t;
////////////////////////////////////////////////////////////////
class Solution {
private: ///////////////////////////////////////////////////////
    nav_t nav_;
    ////////////////////////////////////////////////////////////
    static int nfTurns( const nav_t& nav_a, const nav_t& nav_b );
    static int count( const nav_t& nav, int i );
    void inodr( Record rec, int key );
    nav_t getnav( Node* root, int key );
public: ////////////////////////////////////////////////////////
    int NumberOFTurns( Node* root, int a, int b );
};
////////////////////////////////////////////////////////////////
int Solution::count( const nav_t& nav, int i ){
    int c{};
    for( int j = nav.size() - 1; j > i; --j ){
        if( nav[ j ].turn != nav[ j - 1 ].turn ){
            ++c;
        }
    }
    return c;
}
////////////////////////////////////////////////////////////////
# define DAT( nav, i ) (( nav )[ i ].node->data )
////////////////////////////////////////////////////////////////
int Solution::nfTurns( const nav_t& nav_a, const nav_t& nav_b ){
    int i{}; // first split position
    int n = min( nav_a.size(), nav_b.size());
    for(; i < n and DAT( nav_a, i ) == DAT( nav_b, i ); ++i ){
    }
    return count( nav_a, i ) + count( nav_b, i ) + ( i != n );
}
////////////////////////////////////////////////////////////////
void Solution::inodr( Record rec, int key ){
    const auto& root{ rec.node };
    if(! root ){
        return;
    }
    nav_.push_back( rec );
    if( root->data == key ){
        throw "kitchen sink";
    }
    inodr({ Record::LEFT, root->left  }, key );
    inodr({ Record::RYTE, root->right }, key );
    nav_.pop_back();
}
////////////////////////////////////////////////////////////////
nav_t Solution::getnav( Node* root, int key ){
    nav_.clear();
    try {
        inodr({ Record::NONE, root }, key );
    } catch( ... ){
        return nav_;
    }
    return {};
}
////////////////////////////////////////////////////////////////
int Solution::NumberOFTurns( Node* root, int a, int b ){
    auto nav_a{ getnav( root, a )};
    auto nav_b{ getnav( root, b )};
    return nfTurns( nav_a, nav_b );
}
////////////////////////////////////////////////////////////////
int main( int argc, char* argv[] ){
    Node* root{ buildTree( "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15" )};
    cout << Solution().NumberOFTurns( root, 9, 10 ) << endl;
}
////////////////////////////////////////////////////////////////
//                                                  1
//                                                 / \
//                                                /   \
//                                               /     \
//                                              /       \
//                                             /         \
//                                            2           3
//                                           / \         / \
//                                          /   \       /   \
//                                         4     5     6     7
//                                        / \   / \   / \   / \
//                                       8   9 a   b c   d e   f
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                  203 / 203
// Total Points Scored:                                    8 / 8
// Your Total Score:                                        1030
// Total Time Taken:                                        0.03
// Your Accuracy:                                            50%
// Attempts No.:                                               2
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
