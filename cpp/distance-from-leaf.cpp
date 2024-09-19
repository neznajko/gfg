////////////////////////////////////////////////////////////////
// Count the nodes at distance K from leaf
////////////////////////////////////////////////////////////////
// Given a binary tree with n nodes and a non-negative integer k,
// the task is to count the number of special nodes
//
// A node is considered special if there exists at least one 
// leaf in its subtree such that the distance between the node
// and leaf is exactly k
//
// Note: Any such node should be counted only once. For example,
// if a node is at a distance k from 2 or more leaf nodes, then
// it would add only 1 to our count
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//                              |
// Input:                       | Input:
// Binary tree =                | Binary tree =
//         1                    |         1
//        / \                   |        /
//       /   \                  |       3
//      2     3                 |      /
//     / \   / \                |     5
//    4   5 6   7               |    / \
//           \                  |   7   8
//            8, k = 2          |        \
// Output: 2                    |         9, k = 4
// Explanation: 1, 3            | Output: 1
//                              | Explanation: 1
//                              |
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(Height of the Tree)
////////////////////////////////////////////////////////////////
// 1 ≤ n ≤ 10⁵
////////////////////////////////////////////////////////////////
# include <string>
# include <vector>
# include <sstream>
# include <queue>
# include <iostream>
# include <unordered_set>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
struct Node{int data;Node*left;Node*right;};
////////////////////////////////////////////////////////////////
Node*newNode(int val){Node *temp =new Node;temp->data=val;temp->
left=NULL;temp->right=NULL;return temp;}////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
Node* buildTree( string str){ if(str.length() == 0||str[0]=='N')
return NULL;vector <string> ip;istringstream iss(str);for(string 
str;iss>>str;)ip.push_back( str);Node*root=newNode(stoi(ip[0]));
queue<Node*>queue;queue.push( root);int i=1;while(!queue.empty()
&&i<ip.size()){Node*currNode = queue.front(); queue.pop();string 
currVal=ip[i];if(currVal != "N"){currNode->left = newNode( stoi(
currVal)); queue.push( currNode->left );}i++; if(i >= ip.size())
break;currVal = ip[i];if( currVal!="N"){currNode->right=newNode(
stoi(currVal)); queue.push( currNode->right);}i++;}return root;}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
template <template <typename ...> typename C, typename T>
ostream& operator <<( ostream& _ , const C <T> c ){
    _ << '[';
    if( !c.empty()) {
        _ << ' ';
        for( const T& value: c ){
            _ << value << ' ';
        }
    }
    return _ << ']';
}
////////////////////////////////////////////////////////////////
ostream& operator <<( ostream& _ , Node* node ){
    auto p = reinterpret_cast <uintptr_t> ( node );
    auto name = p & 0xfff;
    return _ << node->data << '(' << hex << name << ')';
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Solution {
private:
    vector <Node*> currpath; // current path
    vector <vector <Node*>> paths; // all root to leaf paths
    unordered_set <Node*> roots;
    void dfs( Node* node ){
        if( !node ) return;
        currpath.push_back( node );
        if( node->left == node->right ){ // leaf
            paths.push_back( currpath ); // copy
        } else {
            dfs( node->left );
            dfs( node->right );
        }
        currpath.pop_back();
    }
    bool checkpath( const vector <Node*> & path, int k ){
        int j = path.size() - k - 1;
        if( j < 0 ) return false;
        Node* root = path[ j ];
        if( roots.count( root ) > 0 ) return false;
        roots.insert( root );
        return true;
    }
public:
    int printKDistantfromLeaf( Node* root, int k ){
        dfs( root );
        int c = 0;
        for( const auto& path: paths ){
            if( checkpath( path, k )){
                ++c;
            }
        }
        return c;
    }
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main(){int t;string tc;getline(cin,tc);t=stoi(tc);while(t--)
{string s,ks;getline(cin,s);Node*root=buildTree(s);getline( cin,
ks);int k=stoi(ks);Solution obj;cout<<obj.printKDistantfromLeaf(
root,k)<<endl;}}////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                1115 / 1115
// Points Scored:                                          4 / 4
// Your Total Score:                                        1850 
// Time Taken:                                              0.49
// 1.3.13: A projectile fired from a gun has arrived at position
// with coordinates (x,y) The initial velocity of the projectile
// is v Find: a) tangent of the angle of the gun with respect of
// the horizont
// ^ y            .t=T             ' Zo x(t) = (vcosŒ)t
// |       .             .(x,y)    '    y(t) = (vsinŒ)t - g(t²|2)
// |    .                   .      '
// |  .                       .    ' t = x|vcosŒ
// | .                         .   ' y = (vsinŒ)x|vcosŒ -
// |/ Œ                            '     g(x²|2v²cos²Œ)
// +---------------------------> x '   = (tgŒ)x - (g|2v²cos²Œ)x²,
//                                 ' 1 = sin²Œ + cos²Œ, zo
// ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' 1|cos²Œ = 1 + tg²Œ
// y = (tgŒ)x - (g|2v²)(1 + tg²Œ)x²
// (tg²Œ)gx²|2v² - (tgŒ)x + gx²|2v² + y = 0 / * g|2
// (tg²Œ)(gx|2v)² - v(tgŒ)gx|2v + (gx|2v)² + gy|2 = 0 
// μ := (tgŒ)gx|2v, © = (gx|2v)² + gy|2
// μ² - vμ + © = 0, μ² - 2(v|2)μ + (v|2)² - (v|2)² + © = 0
// (μ - v|2)² = (v|2)² - ©, μ = v|2 ± sqrt((v|2)² - ©)
// tgŒ = (2v|gx)(v|2 ± sqrt((v|2)² - ©)) =
//     = (v² ± sqrt(v⁴ - 2gyv² - g²x²)|gx                      «
// b) boundary of the area of all possible hits
// Let's try to fix x and find the maximum possible y
// y = (tgŒ)x - (g|2v²)(1 + tg²Œ)x², b := tgŒ
// y = bx - (g|2v²)(1 + b²)x²
// dy|db = x - bgx²|v² = 0, bx = v²|g, zo
// y = v²|g - gx²|2v² - g(bx)²|2v² =
//   = v²|g - gx²|2v² - v²|2g =
//   = v²|2g - gx²|2v²                                         «
// c) the minimum initial projectile velocity necessary to hit a
// target at (x,y)
// Here we use the result of b) cos it gives the maximum
// reachable coordinates (x,y) at a given v:
// y = v²|2g - gx²|2v², u := v²|g
// y = u|2 - x²|2u, 2uy = u² - x²
// u² - 2uy + y² - y² - x² = (u - y)² - (x² + y²) = 0
// u = y + sqrt(x² + y²), zo v = sqrt(g(y + sqrt(x² + y²)))    «
////////////////////////////////////////////////////////////////
//
