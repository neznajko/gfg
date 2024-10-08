////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
///////88888888888888888888888888888888888888///////////////////
///////88888888888888888    88888888888888888///////////////////
///////8888                              8888///////////////////
///////88888888888888888    88888888888888888///////////////////
///////8888                              8888      /////////////
///////8888    8888888888888888888888    8888      /////////////
///////8888    88888,  "8888"  .88888    8888//    /////////////
///////8888    888                888    8888      /////////////
///////8888    888888888    888888888    8888//    /////////////
///////8888    888888888    888888888    8888//    /////////////
///////8888    88                  88    8888//    /////////////
///////8888    888888888    888888888    8888//    /////////////
///////8888    888888888    888888888    8888//    /////////////
///////8888    888888888    88888888*   ,8888//    /////////////
///////88888888888888888888888888888888888888//    /////////////
/////// s o u t h ///         ////         ////    /////////////
/////////////    ////         ////         ////    /////////////
/////////////    ////         ////        ,///"    /////////////
/////////////                                      /////////////
/////////////           ////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 南 mi-na-mi みなみ
////////////////////////////////////////////////////////////////
// Connect Nodes at Same Level
///////////////////////////////////////////////////////////////_
// Given a binary tree, connect the nodes that are at the same
// level. The structure of the tree Node contains an addition
// nextRight pointer for this purpose.
// Your function should set these pointers to point next right
// for each node.
//        10                10 --------> NULL
//       / \                / \
//      3   5      =>      3---5 -------> NULL
//     / \   \            / \   \
//    4   1   2          4---1---2 ------> NULL
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
////////////////////////////////////////////////////////////////
// 1 ≤ Number of nodes ≤ 10^5
// 0 ≤ Data of a node ≤ 10^5
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
// - Die Symmetrielinie der Mittelfigur( [starke] ,rote, `Linie`
// >von> %Scheitel% =bis= \Sohle\ ) :läßt: #sich# am ...
//
// [ s t r o n g ] , r e d , ` l i n e ` > f r o m > % a h e a d
// % = u n t i l = \ s o l e \ : l e t : # i t s e l f #
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
//  d d   d   d
//   e e   e   a
//    r r   r   s
//     
//      T T   F   T
//       i e   e   e
//        s p   r   l
//         c p   n   e
//          h i   s   f
//          t  c   e   o
//          a   h   h   n
//          b    c    e   t
//          l     a     r   e
//          e      r      T   l
//                  p       V   e
//                   e            p
//                    t             h
//                                    o
//                                     n
//                                      e
//
////////////////////////////////////////////////////////////////
# include <vector>
# include <queue>
# include <string>
# include <sstream>
# include <iostream>
////////////////////////////////////////////////////////////////
struct Node{int data;Node*left;Node*right;Node*nextRight;};
////////////////////////////////////////////////////////////////
Node*newNode(int val){Node*temp=new Node;temp->data=val;temp->
left=NULL;temp->right=NULL;temp->nextRight=NULL;return temp;}
////////////////////////////////////////////////////////////////
Node*buildTree(string str){if(str.length()==0||str[0]=='N')
return NULL;vector<string> ip;istringstream iss(str);for(string
str;iss>>str;)ip.push_back(str);Node*root=newNode(stoi(ip[0]));
queue<Node*>queue;queue.push(root);int i=1;while(!queue.empty()
&&i<ip.size()){Node*currNode=queue.front();queue.pop();string
currVal=ip[i];if(currVal!="N"){currNode->left=newNode(stoi(
currVal));queue.push(currNode->left);}i++;if(i>=ip.size())
break;currVal=ip[i];if(currVal!="N"){currNode->right=newNode(
stoi(currVal));queue.push(currNode->right);}i++;}return root;}
////////////////////////////////////////////////////////////////
void printSpecial(Node*root){if(root==NULL)return;Node*next_root
=NULL;while(root!=NULL){cout<<root->data<<" ";if(root->left&&(!
next_root))next_root=root->left;else if(root->right&&(!next_root
))next_root=root->right;root=root->nextRight;}printSpecial(
next_root);}
////////////////////////////////////////////////////////////////
void inorder(Node*root){if(root==NULL)return;inorder(root->left);
cout<<root->data<<" ";inorder(root->right);}
////////////////////////////////////////////////////////////////
class Solution{public:void connect(Node*root);};
////////////////////////////////////////////////////////////////
int main(){int t;scanf("%d\n",&t);while(t--){string s;getline(cin,
s);Node*root=buildTree(s);Solution obj;obj.connect(root);
printSpecial(root);cout<<endl;inorder(root);cout<<endl;}}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# define next nextRight
# define ryte right
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
Node* insert( Node* tail, Node* p ){ // tail--next-->p
    return tail->next = p;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//                                                  10 3 5 4 1 2
//  ` ahead[]
//    ahead[0]->next = root
//    level <- 0
//1:  p = ahead[level]->next
//    if !p: >>> exit >>>
//    tail = ahead[level+1] = new Node
//    for(; p; p = p->next ){
//      if p.left: tail = insert( tail, p.left )
//      if p.ryte: tail = insert( tail, p.ryte )
//    }
//    ++level
//    goto 1
// 
// ahead[0]------>10 -------> NULL
//                / \
//      [1]----->3---5 -----> NULL
//              / \   \
//      [2]--->4---1---2 ---> NULL
//
////////////////////////////////////////////////////////////////
void Solution::connect( Node* root ){
    vector<Node*> ahead( 1, newNode( 0 ));
    ahead[0]->next = root;
    int level{-1 };
 lab:
    Node* p{ ahead[++level]->next };
    if( !p ){ return; }
    ahead.push_back( newNode( 0 ));
    Node* tail{ ahead.back()};
    for(; p; p = p->next ){
        if( p->left ){ tail = insert( tail, p->left );}
        if( p->ryte ){ tail = insert( tail, p->ryte );}
    }
    goto lab;
}
///////////////////////////////////////////////////////////////_
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 1 かわさき 905-0877
// 2 リー (Lee) 5934-1026
// 3 ウッズ(Woods) 49-1509 
// 4 トンプソン(Tompson) 6782-3333
////////////////////////////////////////////////////////////////
// 曜、よう, 曜、ヨウ, 曜、よう, 曜、ヨウ
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                1115 / 1115
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1434
// Total Time Taken:                                        0.38
