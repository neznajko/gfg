////////////////////////////////////////////////////////////////
////////////////////////////////================================
//  Remov BST keys outside given                           range
////////////////////////////////%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//     Givn a Binary Search Tree    (BST) and a range [min, max],
////////////////////////////////________________________________
//      remov all keys which are    outside the given range. The
////////////////////////////////--------------------------------
//  modified tree should also be                             BST.
////////////////////////////////________________________________
//                    Example: 2
//         Input: Range = [2, 6]                        14
//    14 4 16 2 8 N 15 -8 3 7 10                       / \
//                                                    /   \
//                                                   /     \
//                                                  4      16
//                                                 / \       \
//                                                /   \       \
//                                               2     8      15
//                                              / \   / \
//                                            -8   3 7  10
////////////////////////////////>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//                 Output: 2 3 4
//              Explanation: ...              ( blah blah blah )
////////////////////////////////))))))))))))))))))))))))))))))))
//     Expected Time Complexity:              O(number of nodes)
//     Expected Auxiliary Space:                            O(h)
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
#                                             include <iostream>
#                                               include <string>
#                                                include <queue>
#                                              include <sstream>
using namespace std;struct Node{int data;Node* left;Node* right;
};Node* newNode(int val){Node* temp=new Node;temp->data=val;
temp->left=NULL;temp->right=NULL;return temp;}Node* buildTree(string str)
{if(str.length()==0||str[0]=='N')return NULL;vector<string> ip;
istringstream iss(str);for(string str;iss>>str;)ip.push_back(str);
Node* root=newNode(stoi(ip[0]));queue<Node*> queue;queue.push(root);
int i=1;while(!queue.empty()&&i<ip.size()){Node* currNode=queue.front();
queue.pop();string currVal=ip[i];if(currVal!="N"){
currNode->left=newNode(stoi(currVal));queue.push(currNode->left);}
i++;if(i>=ip.size()) break;currVal=ip[i];if(currVal!="N"){
currNode->right=newNode(stoi(currVal));queue.push(currNode->right);}
i++;}return root;}void inorderTraversal(Node* root){if(root){
inorderTraversal(root->left);cout<<root->data<<" ";
inorderTraversal(root->right);}}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Solution {
private:
    int left_;
    int ryte_;
    Node* remov( Node* root );
public:
    Node* removekeys( Node* root, int left, int ryte );
};
////////////////////////////////////////////////////////////////
Node* Solution::removekeys( Node* root, int left, int ryte ){
    left_ = left;
    ryte_ = ryte;
    return remov( root );
}
////////////////////////////////////////////////////////////////
#                                                define key data
#                                              define ryte right
////////////////////////////////;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
//   They say O(h) in space, but         this is O(1) solution:)
////////////////////////////////////////////////////////////////
Node* Solution::remov( Node* root ){
    if( root ){
        if( root->key < left_){
            root = remov( root->ryte );
        } else if( root->key > ryte_){
            root = remov( root->left );
        } else {
            root->left = remov( root->left );
            root->ryte = remov( root->ryte );
        }
    }
    return root;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main(){struct Node* root=buildTree("14 4 16 2 8 N 15 -8 3 7 10");
Node* head=Solution().removekeys(root,2,6);inorderTraversal(head);}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                  256 / 256
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1038
// Total Time Taken:                                         1.4
// Your Accuracy:                                           100%
// Attempts No.:                                               1
////////////////////////////////////////////////////////////////
