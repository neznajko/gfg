////////////////////////////////////////////////////////////////
// Postorder Traversal (Iterative)
////////////////////////////////////////////////////////////////
// Given a binary tree. Find the postorder traversal of the tree
// without using recursion.
////////////////////////////////////////////////////////////////
// Example: 2
// Input: 8 1 5 N 7 10 6 N 10 6                       8
//                                                   / \
//                                                  /   \
//                                                 /     \
//                                                /       \
//                                               /         \
//                                              1           5  
//                                               \         / \
//                                                \       /   \
//                                                 7     10    6
//                                                  \   /
//                                                  10 6
// Output: 10 7 1 6 10 6 5 8 
//////////////////////////////////////////////////////////////// 
// Expected time complexity: O(N)
// Expected auxiliary space: O(N)
////////////////////////////////////////////////////////////////
# include             <iostream>
#        include                <vector>
#               include                 <queue>
#                      include                 <string>
#                             include                  <sstream>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
struct Node{int data;Node*left=nullptr;Node*right=nullptr;
Node(int data_):data(data_){}};
////////////////////////////////////////////////////////////////
Node*buildTree(string str){/*Corner Case*/if(str.length()==0||
str[0]=='N')return nullptr;/*Creating vector of strings from input*/
/*string after spliting by space*/vector<string>ip;istringstream
iss(str);for(string str;iss>>str;)ip.push_back(str);/*Create the*/
/*root of the tree*/Node*root=new Node(stoi(ip[0]));/*Push the root*/
/*to the queue*/queue<Node*>queue;queue.push(root);/*Starting from*/
/*the second element*/int i=1;while(!queue.empty()&&i<ip.size()){
/*Get and remove the front of the queue*/Node*currNode=queue.front();
queue.pop();/*Get the current node's value from the string*/
string currVal=ip[i];/*If the left child is not null*/if(currVal
!="N"){/*Create the left child for the current node*/currNode->left
=new Node(stoi(currVal));/*Push it to the queue*/queue.push(currNode
->left);}/*For the right child*/i++;if(i>=ip.size())break;currVal
=ip[i];/*If the right child is not null*/if(currVal!="N"){
/*Create the right child for the current node*/currNode->right=
new Node(stoi(currVal));/*Push it to the queue*/queue.push(currNode
->right);}i++;}return root;}
////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> postOrder( Node* root );
};
////////______///____////_____//////////////////////////////////
# define      key    data
#       define   ryte    right
//______//////___////____/////__________________________________
vector<int> Solution::postOrder( Node* root ){
    Node* p{ root };
    //      /  /                 1
    //     /  /               
    //    /  /                 N   2
    //   /  /                     3 4
    //  /  /
    // root 
    vector<Node*> stk;
    vector<int> post;
    while( !false ){
        if( p ){
            stk.push_back( p );
            p = p->left;
        } else {
            while( stk.back()->ryte == p ){ // p r
                p = stk.back();             // o
                post.push_back( p->key );   // s
                stk.pop_back();             // t
                if( stk.empty() ){          // o
                    goto et_voilà;          // r
                }                           // d
            }                               // e
            p = stk.back()->ryte;
        }
    }
 et_voilà:
    return post;
}
// _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ - - - - -
 //                     ..   .   .. ...  .  ..  ..  /// //  
  //                     . . . . .    .  . . . . . / /   / /
   //                     ..  . .  .   .  . . ..  . / /// //
    //                     .   . .   .  .  . . . . . / /   / /
     //                     .    .  ..   .   .  . . ..  /// / /
      // _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ - - - - -
int main() {
    Node* root{ buildTree( "8 1 5 N 7 10 6 N 10 6" )};
    vector<int> ans{ Solution().postOrder( root )} ;
    for( int i = 0; i < ans.size(); i++ ){
        cout << ans[ i ] << " ";
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                  125 / 125 
// Total Points Scored:                                    4 / 4    
// Your Total Score:                                        1054
// Total Time Taken:                                        0.18
// Your Accuracy:                                           100%
// Attempts No.:                                               1
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

