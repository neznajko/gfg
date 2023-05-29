////////////////////////////////////////////////////////////////
// Delete a node from BST
////////////////////////////////////////////////////////////////
// Given a Binary Search Tree and a node value X. Delete the 
// node with the given value X from the BST. If no node with 
// value X exists, then do not make any change.
////////////////////////////////////////////////////////////////
// Example: 2
// Input: 1                              1 N 2 N 8 5 11 4 7 9 12 
//         \
//          2
//           \
//            8
//           / \
//          5  11
//         / \ / \
//        4  7 9  12
// X = 9
// Output: 1 2 4 5 7 8 11 12
// Explanation: In the given input tree after deleting 9 will be
//     1
//      \
//       2
//        \
//         8
//        / \
//       5   11
//      / \   \
//     4   7   12
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O( Height of the BST )
// Expected Auxiliary Space: O( Height of the BST )
///////////////////////////////////////////////////////////////_
# include <iostream>
# include <vector>
# include <sstream>
# include <queue>
///////////////////////////////////////////////////////////////=
using namespace std;
////////////////////////////////////////////////////////////////
struct Node{int data;Node*left;Node*right;Node(int val){data= 
val;left=right=NULL;}};
////////////////////////////////////////////////////////////////
struct Node*deleteNode(struct Node*root,int key);
///////////////////////////////////////////////////////////////_
Node*buildTree(string str){if(str.length()==0||str[0]=='N')
return NULL;vector<string>ip;istringstream iss(str);for(
string str;iss>>str;)ip.push_back(str);Node*root=new Node(stoi(
ip[0]));queue<Node*>queue;queue.push(root);int i=1;while(!queue.
empty()&&i<ip.size()){Node*currNode=queue.front();queue.pop();
string currVal=ip[i];if(currVal!="N"){currNode->left=new Node(
stoi(currVal));queue.push(currNode->left);}i++;if(i>=ip.size())
break;currVal=ip[i];if(currVal!="N"){currNode->right=new Node(
stoi(currVal));queue.push(currNode->right);}i++;}return root;}
////////////////////////////////////////////////////////////////
void inorder(Node*root,vector<int>&v){if(root==NULL)return;
inorder(root->left,v);v.push_back(root->data);
inorder(root->right,v);}
////////////////////////////////////////////////////////////////
int main(){string s;getline(cin,s);Node*root1=buildTree(s);
getline(cin,s);int k=stoi(s);root1=deleteNode(root1,k);
vector<int>v;inorder(root1,v);for(auto i:v)cout<<i<<" ";
cout<<endl;}
////////////////////////////////////////////////////////////////
# define ryte right
////////////////////////////////////////////////////////////////
Node * Delete( Node * top ){
    Node * res;
    if( !top->ryte ){
        res = top->left;
    } else {
        Node * p{ top->ryte };
        for(; p->left; p = p->left ){
        }
        p->left = top->left;
        res = top->ryte;
    }
    delete top; 
    top = nullptr;
    return res;
}
////////////////////////////////////////////////////////////////
void Search( Node * p, const int key ){
    if( p->left ){
        if( p->left->data == key ){
            p->left = Delete( p->left );
            throw "voila'";
        } else {
            Search( p->left, key );
        }
    }
    if( p->ryte ){
        if( p->ryte->data == key ){
            p->ryte = Delete( p->ryte );
            throw "voila'";
        } else {
            Search( p->ryte, key );
        }
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                    31 / 31
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1122
// Total Time Taken:                                        0.03
////////////////////////////////////////////////////////////////
Node * deleteNode( Node * root, int key ){
    Node * const atop{ new Node( 0 )};
    atop->left = root;
    try{
        Search( atop, key );
    } catch( ... ){}
    return atop->left;
}
////////////////////////////////////////////////////////////////
// I've asked ChatGPT, do you have an idea how to delete a node 
// from BST, and it said Certainly!.. and then started spiting 
// with velocity 1 word/sec, don|t know the code might work, but 
// it was interesting to see having some difficulties answering., 
// once I've told: you are like C-3PO, and it said thank you for 
// the comparison:) By the way I don|t think, might be wrong of
// course that there is any software revolution here, the
// success is due to the large amount of online data available,
// and the large amount of computing power that only companies
// like Microsoft or Google can afford, to my understanding this
// is just complicated brute force. I might be wrong, don|t know
// but I don|t think neural networks is the future of ai.
////////////////////////////////////////////////////////////////

