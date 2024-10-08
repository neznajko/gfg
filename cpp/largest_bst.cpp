//                              88888888888888888888888888
// --------------------.        88888888888888888888888888
// ------------------.  `.      88888888888888888888888888
// ----------------.  `.  `._   88888888888888888888888888
// --------------.  `.  `.___   88888888888888888888888888
// ------------. atttend_____   8888//     888888888888888
// ----------.  `'''''''_____   8888//     888888888888888
// --------.  `. '''''''_____   8888//     888888888888888
// ------.  `.  `'''''''_____   8888/      888888888888888
// ----.  `.  `._'''''''___                         888888
// --.  `.  `.___'''''''___      / / /      / / / / 888888
//    `.  `._____'''''''___     / / //     / / / / /888888
//      `._______'''''''_____   8888//     888888888888888
//               '''''''        8888//     888888888888888
//               '''''''        8888//     888888888888888
// 88888888888888'''''''88888   8888/      888888888888888
// 88888888888888'''''''888                         888888
// 88888888888888'''''''888     / / / / / / / / / / 888888
// 88888888888888'''''''888      / / / / / / / / / /888888
// 888888888888       8888888   88888888888888888888888888
// 8888888888       888888888   88888888888888888888888888
// 88888888       88888888888   88888888888888888888888888
// 888888       8888888888888   88888888888888888888888888
///////       ////////////////////////////////////////////
// Largest BST
//////////////////////////////////////////////////////////
// Given a binary tree. Find the size of its largest
// subtree that is a Binary Search Tree.
// Note: Here size is equal to the number of nodes in the
// subtree.
//////////////////////////////////////////////////////////
// Input: 1
//       / \
//      4   4
//     / \
//    6   8 Output: 1
// Explanation: There's no sub-tree with size greater than
// which forms a BST. All the leaf Nodes are the BSTs with
// size equal to 1.
//////////////////////////////////////////////////////////
// Input: 6                          6 6 3 N 2 9 3 N 8 8 2
//    6       3
//      2   9   3
//       8 8 2 Output: 2
// Explanation: The following sub-tree is a BST of size 2:
// 2                                                     
//  8                                                    d
//////////////////////////////////////////////////////////
// Expected Time Complexity: O(N)                      doe
// Expected Auxiliary Space: O(Height of the BST)     does
//////////////////////////////////////////////////////////
// 1 ≤ Number of nodes ≤ 10^5                       does
// 1 ≤ Data of a node ≤ 10^6                       does
//////////////////////////////////////////////////////////
// Zusätzliches zu den Breitenausdehnungen:      does
//////////////////////////////////////////////////////////
// Zusätzlich - additionally                   does
// zus"tzlich             Ausdehnen - expand  does
//    a         zu - to   ausdehnen          does
// zus"tzlich   zu        ausdehnen         does
//    a         zu        ausdehnen        does
// zus"tzlich   zu                        does
//    a                                  does
//////////////////////////////////////////////////////////
using namespace                        std;
//////////////////////////////////////////////////////////
# include                            <iostream>
# include                           <queue>
# include                          <string>
# include                         <sstream>
//////////////////////////////////////////////////////////
// ein Kilo - a kilo            does
// ein Pfund - half a kilo     does
// ...zusammen - ...altogetherdoes
// was macht das? - what doesdoest come to?
//////////////////////////dodoes//////////////////////////
///////////////////////////does///////////////////////////
//////////////////////////////////////////////////////////
struct Node{int data;Node*left;Node*right;};
//////////////////////////////////////////////////////////
Node*newNode(int val){Node*temp=new Node;temp->data=val;
temp->left=NULL;temp->right=NULL;return temp;}
//////////////////////////////////////////////////////////
Node*buildTree(string str){if(str.length()==0||str[0]== 
'N')return NULL;vector<string> ip;istringstream iss(str);
for(string str;iss>>str;)ip.push_back(str);Node*root= 
newNode(stoi(ip[0]));queue<Node*>queue;queue.push(root);
int i=1;while(!queue.empty()&&i<ip.size()){Node*currNode 
=queue.front();queue.pop();string currVal=ip[i];if(
currVal!="N"){currNode->left=newNode(stoi(currVal));queue.
push(currNode->left);}i++;if(i>=ip.size())break;currVal=
ip[i];if(currVal!="N"){currNode->right=newNode(stoi(
currVal));queue.push(currNode->right);}i++;}return root;}
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
/////////////       4       //////////////////////////////
/////////////   2       6   //////////////////////////////
///////////// 1   3   5   7 //////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
# define inf 1000001
//////////////////////////////////////////////////////////
struct BST {
    int size;
    int min_key;
    int ma8_key;
} nil{ 0, inf, 0 }, nop{ -1, 0, 0 };
//////////////////////////////////////////////////////////
inline int key( Node* node ){
    return node->data;
}
//////////////////////////////////////////////////////////
class Solution {
    int ma8{};
    BST check( Node* node );
public:
    int largestBst( Node* root );
};
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
BST Solution::check( Node* node ){
    if( !node ){
         return nil;
    }
    BST left{ check( node->left )};
    BST ryte{ check( node->right )};
    if( left.size < 0 or ryte.size < 0 ){
        return nop;
    }
    if( key( node ) <= left.ma8_key ){
        return nop;
    }
    if( key( node ) >= ryte.min_key ){
        return nop;
    }
    int size = left.size + 1 + ryte.size;
    ma8 = max( ma8, size );
    return { size,
             min( key( node ), left.min_key ),
             max( key( node ), ryte.ma8_key )};
}
//////////////////////////////////////////////////////////
int Solution::largestBst( Node* root ){
    check( root );
    return ma8;
}
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////// anata no kyoodai wa nan nin imasu ka
//////// あなた の きょうだい は なん 人 います か。
//////// doyoobi wa watashi no tanjoobi desu
//////// 土曜日 は わたし の たんじょう日 です。
//////// mai toshi watashi wa nihon ni ikimasu
//////// まい 年 わたし は 日ほん に いきます。          
////////                                            [ GO ]
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
int main(){int t;scanf("%d ",&t);while(t--){string s,ch;
getline(cin,s);Node*root=buildTree(s);Solution ob;cout<<ob
.largestBst(root)<<endl;}}
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
// sore wa nan desu ka
// それ｜は｜なん｜です｜か。
// (1) kore wa jitensha desu( bicycle )
//     これ｜は｜じてんしゃ｜です。
// (2) kore wa booshi desu( hat )
//     これ｜は｜ぼうし｜です。
// (3) kore wa enpitsu desu( pencil )
//     これ｜は｜えんぴつ｜です。
// (4) kore wa kasa desu( umbrella )
//     これ｜は｜かさ｜です。
// (5) kore wa jisho desu( dictionary )
//     これ｜は｜じしょ｜です。
// (6) kore wa kaban desu( bag )
//     これ｜は｜かばん｜です。
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
// Test Cases Passed:                              23 / 23
// Total Points Scored:                              4 / 4
// Your Total Score:                                  1574
// Total Time Taken:                                  0.04
