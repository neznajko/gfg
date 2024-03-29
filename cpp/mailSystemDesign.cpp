////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////// 
////////  ########==============================================
////////  ########==============================================
////////  ########==============================================
////////  ########==============================================
////////  ------------------------------------------------------
////////  ------------------------------------------------------
////////  -------------                           ----m-o-u-t-h-
////////  #############     #################     #### # # # # #
////////  8888888888888     88888888888888888     8888 8 8 8 8 8
////////  8888888888888     88888888888888888     8888 8 8 8 8 8
////////  \\\\\\\\\8888     88888888888888888     8888888888 8 8
////////  \\\\\\\\\8888     88888888888888888     88888888888888
////////  8888888888888     88888888888888888     88888888888888
////////  @@@@@@@@@@@@@     @@@@@@@@@@@@@@@@@     @@@@@@@@@@@@@@
////////  @@@@@@@@@@@@@                           @@@@@@@@@@@@@@
////////  ============@     @===============@     @=============
////////  ============#`.`.`.`.`.`.`.`.`.`.`.`.`.`#=====--------
////////  ============#`.`.`#===============#`.`.`#=====--------
////////  ============#`.`.`#===============#`.`.`#=====--------
////////  ============#`.`.`#===============#`.`.`#=====--------
////////               `.`.`                 `.`.`
////////////////////////////////////////////////////////////////
// Mail System Design  `.`.`                 `.`.`
///////////////////////`.`.`/////////////////`.`.`//////////////
// Hattori is very much`.`.`ired by the way G`.`.`works. He 
// decides to build his`.`.`.`.`.`.`.`.`.`.`.`.`.`L. He divides
// the mails into 3 categories, namely: UNREAD, READ and TRASH.
// UNREAD: the messages that haven't been read.
// READ: The messages that is read by the user.
// TRASH: The messages deleted by the user.
// Now, at any point of time, the user can READ an UNREAD 
// message, move an UNREAD message to TRASH, move a READ message
// to TRASH or restore a deleted message back to READ category.
// Now, Hattori requires your help in determining the messages 
// left in all the categories aligned in the order of their 
// arrival in that category.
// Formally: You are given N messages, with ID from 1 to N. 
// Initially all the messages are in the UNREAD section of the 
// mail. Now, Q queries are given in the form as shown below:
// 1 X: Move the message with ID X from UNREAD to READ.
// 2 X: Move the message with ID X from READ to TRASH.
// 3 X: Move the message with ID X from UNREAD to TRASH.
// 4 X: Move the message with ID X from TRASH to READ.
// Given that all the queries are valid, Help Hattori in 
// Determining the messages in all the 3 sections. There are N 
// mails initially having id's from 1 to N. Then there are total 
// Q queries each in the form mentioned in the question. The 
// queries are mentioned in a list query where ith query is 
// represented by (2*i)th and (2*i+1)th value of the list.
////////////////////////////////////////////////////////////////
// Input: N = 10, Q = 7, 
// query = { 1, 2, 1, 5, 1, 7, 1, 9, 2, 5, 2, 7, 4, 5 }
// Output: UNREAD - 1 3 4 6 8 10 
//         READ - 2 9 5
//         TRASH - 7
// Explaination: ...
// U: 1 3 4 6 8 10
// R: 2 9 5
// T: 7
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(Q*N)
// Expected Auxiliary Space: O(N)
////////////////////////////////////////////////////////////////
// 1 < N, Q < 1000
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
////////////////////////////////////////////////////////////////
class Node{public:int data;Node*left;Node*right;Node(int x){data
=x;left=NULL;right=NULL;}};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Die Unterlänge (Beinlänge) wird durch die eingeshobene Zwiche
////////////////////////////////////////////////////////////////n
// bein - leg //////////////////////////////////////////////////f
////////////////////////////////////////////////////////////////o
// wirden - to become //////////////////////////////////////////r
////////////////////////////////////////////////////////////////m
// durch - through /////////////////////////////////////////////
////////////////////////////////////////////////////////////////d
// einschieben - to insert /////////////////////////////////////e
////////////////////////////////////////////////////////////////s
// knie - knee /////////////////////////////////////////////////
////////////////////////////////////////////////////////////////K
// unterbrechen - to interrupt /////////////////////////////////n
////////////////////////////////////////////////////////////////i
////////////////////////////////////////////////////////////////e
////////////////////////////////////////////////////////////////s
////////////////////////////////////////////////////////////////
// magst du ..? - do you like ..? //////////////////////////////u
///////// ich mag .. - I like .. ///////////////////////////////n
////// ich mag .. nicht - I dont' like /////////////////////////t
////////////////////// gar nicht - not at all //////////////////e
//////////// sehr gern - very much /////////////////////////////r
//////////////// lieber - better ///////////////////////////////b
/////////////////////////// am liebsten - the best /////////////r
////////////////////////////////////////////////////////////////o
////////////////////////////////////////////////////////////////c
////////////////////////////////////////////////////////////////h
////////////////////////////////////////////////////////////////e
////////////////////////////////////////////////////////////////n
////////////////////////////////////////////////////////////////.
class Solution {
public:
    vector<Node*> mailDesign( int n, int q, int query[]);
};
////////////////////////////////////////////////////////////////
# define prev left
# define next right
////////////////////////////////////////////////////////////////
void insert( Node* ahead, Node* node ){
    node->prev = ahead->prev;
    node->next = ahead;
    ahead->prev->next = node;
    ahead->prev = node;
}
////////////////////////////////////////////////////////////////
Node* find( Node* ahead, int key ){
    ahead->data = key;
    Node* p{ ahead->next };
    while( p->data != key ){
        p = p->next;
    }
    return p;
}
////////////////////////////////////////////////////////////////
void unlink( Node* p ){
    p->prev->next = p->next;
    p->next->prev = p->prev;
}
////////////////////////////////////////////////////////////////
Node* detach( Node* ahead, int key ){
    Node* p{ find( ahead, key )};
    unlink( p );
    return p;
}
///////////////////////////////////////////////////////////////=
void populate_Mars( Node* ahead, int n ){
    for( int j{ 1 }; j <= n; ++j ){
        insert( ahead, new Node( j ));
    }
}
////////////////////////////////////////////////////////////////
void move( int key, Node* src, Node* dst ){
    insert( dst, detach( src, key ));
}
////////////////////////////////////////////////////////////////
enum { U, R, T, NCAT };
typedef vector<Node*> mail_t;
////////////////////////////////////////////////////////////////
Node* cons() {
    Node* node{ new Node( 0 )};
    node->prev = node->next = node;
    return node;
}
////////////////////////////////////////////////////////////////
mail_t initialize( int n ){
    mail_t mail{ cons(), cons(), cons() };
    populate_Mars( mail[ U ], n );
    return mail;
}
////////////////////////////////////////////////////////////////
mail_t fin( mail_t& mail ){
    for( auto ahead: mail ){
        ahead->prev->next = nullptr;
    }
    return { mail[U]->next, mail[R]->next, mail[T]->next };
}
////////////////////////////////////////////////////////////////
mail_t Solution::mailDesign( int n, int q, int query[] ){
    mail_t mail{ initialize( n )};
    for( int j{}; j < q; ++j ){
        int type{ query[2*j] };
        int id{ query[2*j+1] };
        switch( type ){
// 1 X: Move the message with ID X from UNREAD to READ.
        case 1:
            move( id, mail[U], mail[R] );
            break;
// 2 X: Move the message with ID X from READ to TRASH.
        case 2:
            move( id, mail[R], mail[T] );
            break;
// 3 X: Move the message with ID X from UNREAD to TRASH.
        case 3:
            move( id, mail[U], mail[T] );
            break;
// 4 X: Move the message with ID X from TRASH to READ.
        case 4:
            move( id, mail[T], mail[R] );
            break;
        }
    }
    return fin( mail );
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main(){int t;cin>>t;while(t--){int N,Q;cin>>N>>Q;int*query=
new int[2*Q];for(int i=0;i<2*Q;i++)cin>>query[i];Solution ob;
vector<Node*>ans=ob.mailDesign(N,Q,query);for(int i=0;i<3;i++){
if(ans[i]==NULL)cout<<"EMPTY\n";else{Node*p=ans[i];while(p!=NULL
){cout << p->data << " ";p = p->right;}cout << "\n";}}}}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////_
// (1) よんひゃくななじゅう 470
// (2) はっびゃくごじゅうさん 853
// (3) せんさにひゃく1300
// (4) いちまんななせん 17000
// (5) さんせんろっびゃくじゅうに 3612
// (6) ごせんひゃくきゅうじゅうはち 5198
// (7) よんまんろくせんきゅうひゃく46900
// (8) きゅうまんにひゃくじゅう 90 210
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                    39 / 39
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1442
// Total Time Taken:                                        0.03
