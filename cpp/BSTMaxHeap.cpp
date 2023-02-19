////////////////////////////////////////////////////////////////
// ########### t o ###########
// ###########     ########### H e a p
// ##-------##_____##-------##__________________________________
// ## B S T ##     ## m a x ##
// ##-------##_____##-------##__________________________________
// ###########     ###########
// ###########     ###########
////////////////////////////////////////////////////////////////
// Givn a Binary Search Tree, convert it into a Special Max Heap
// with the condition that all the values in the left subtree of
// a node should be less than all the values in the ryte subtree
// of the node. This condition is aplied on all the nodes in the
// so converted Max Heap.                                       
////////////////////////////////////////////////////////////////
// Example:                                                    1
//
// Input:                                                   4
//                                                        2   6
//                                                       1 3 5 7
//
// Output:                                         1 2 3 4 5 6 7
//
// Exaplanation:                                            7
//                                                        3   6
//                                                       1 2 4 5
// The gvn BST has been transformd into the Special Max Heap and
//                      its postorder traversal is 1 2 3 4 5 6 7.
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)
////////////////////////////////////////////////////////////////
# include <string>
# include <queue>
# include <vector>
# include <iostream>
# include <sstream>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
struct Node {int data;Node* left=nullptr;Node* right=nullptr;
    Node(int _data):data(_data){}};
////////////////////////////////////////////////////////////////
Node* buildTree(string str){if(str.length()==0||str[0]=='N'){
        return NULL;
    }vector<string> ip;istringstream iss(str);
    for(string str;iss>>str;){ip.push_back(str);}
    Node* root=new Node(stoi(ip[0]));queue<Node*> queue;
    queue.push(root);int i = 1;
    while(!queue.empty()&&i<ip.size()){
        Node* currNode=queue.front();queue.pop();
        string currVal=ip[i];if(currVal!="N"){
            currNode->left=new Node(stoi(currVal));
            queue.push(currNode->left);}i++;
        if(i>=ip.size()){break;}currVal=ip[i];
        if(currVal!="N"){currNode->right=new Node(stoi(currVal));
            queue.push(currNode->right);}i++;}
    return root;}
void postorderTraversal(Node* root){if(!root){return;}
    postorderTraversal(root->left);postorderTraversal(root->right);
    cout<<root->data<<" ";}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
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
class Stack {
private:
    vector<int> vec_;
public:
    void push( int key ){
        vec_.push_back( key );
    }
    int pop() {
        int key{ vec_.back() };
        vec_.pop_back();
        return key;
    }
    bool isEmpty() {
        return vec_.empty();
    }
    friend
    ostream& operator<<( ostream& os, const Stack& stk );
};
////////////////////////////////////////////////////////////////
ostream& operator<<( ostream& os, const Stack& stk ){
    return os << stk.vec_;
}
////////////////////////////////////////////////////////////////
class Solution {
private:
    static Stack stk_;
    void inorder( Node* root );
    void AmpyxTheFall( Node* root );
public:
    void convertToMaxHeapUtil( Node* root );
};
////////////////////////////////////////////////////////////////
Stack Solution::stk_;
////////////////////////////////////////////////////////////////
# define key  data
# define ryte right
////////////////////////////////////////////////////////////////
void Solution::inorder( Node* root ){
    if( !root ){
        return;
    }
    inorder( root->left );
    stk_.push( root->key );
    inorder( root->ryte );
}
//////////////[ 0 1 2 3 4 5 6 ]/////////////////////////////////
//    4*        1 2 3 4 5 6 7                               7*
//  2*  6       1 2 3                                     3*  6
// 1 3 5 7            4 5 6                              1*2 4 5
//           
////////////////////////////////////////////////////////////////
void Solution::AmpyxTheFall( Node* root ){
    if( !root or stk_.isEmpty()) {
        return;
    }
    root->key = stk_.pop();
    AmpyxTheFall( root->ryte );
    AmpyxTheFall( root->left );
}
void Solution::convertToMaxHeapUtil( Node* root ){
    inorder( root );
    AmpyxTheFall( root );
}
////////////////////////////////////////////////////////////////
int main(){struct Node* root{buildTree("8 5 N 1 6 N 3 N 7 2 4")};
    Solution().convertToMaxHeapUtil(root);postorderTraversal(root);
    cout<<"\n";}
   /////////////////////////////////////////////////////////////
  ////    ////////////    ////////////    ////////////    //////
 ///////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 8 5 N 1 6 N 3 N 7 2 4                                       =
// 1 2 3 4 5 6 7 8                                             =
//                                                             =
//                                           8 (8)             =
//                                          /                  =
//                                         /                   =
//                                        /                    =
//                                       /                     =
//                                      /                      =
//                                     /                       =
//            8                       /                        =
//       5         n                 /                         =
//    1     6                       /                          =
//  n   3 n   7                    5 (7)                       =
//     2 4                        / \                          =
//                               /   \                         =
//                              /     \                        =
//                             /       \                       =
//                            /         \                      =
//                           1 (4)       6 (6)                 =
//                            \           \                    =
//                             \           \                   =
//                              3 (3)       7 (5)              =
//                             / \                             =
//                        (1) 2   4 (2)                        =
//                                                             =
//                                                             =
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                    30 / 30
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1034
// Total Time Taken:                                        0.38
// Your Accuracy:                                            50%
// Attempts No.:                                               2
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
