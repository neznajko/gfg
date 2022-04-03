////////////////////////////////////////////////////////////////
// Shortest Unique prefix for every word 
// Hard Accuracy: 78.63% Submissions: 5279 Points: 8
// Given an array of words, find all shortest unique prefixes to
// represent each word in the given array. Assume that no word is
// prefix of another.
// 
// Example 1:
// Input: 
// N = 4
// arr[] = {"zebra", "dog", "duck", "dove"}
// Output: z dog du dov
// Explanation: 
// z => zebra 
// dog => dog 
// duck => du 
// dove => dov 
//
// Example 2:
// Input: 
// N = 3
// arr[] =  {"geeksgeeks", "geeksquiz", "geeksforgeeks"};
// Output: geeksg geeksq geeksf
// Explanation: 
// geeksgeeks => geeksg 
// geeksquiz => geeksq 
// geeksforgeeks => geeksf
//
// Your task: You don't have to read input or print
// anything. Your task is to complete the function findPrefixes()
// which takes the array of strings and it's size N as input and
// returns a list of shortest unique prefix for each word
//  
// Expected Time Complexity: O(N*length of each word)
// Expected Auxiliary Space: O(N*length of each word)
//  
// Constraints:
// 1 ≤ N, Length of each word ≤ 1000
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <string>
////////////////////////////////////////////////////////////////
// This is the Trie data structure but before reading Algorithms
// Part II, by Sedgwick and Wayne, let's try something home
// cooked. The idea is to tuck the pointers to leafs of the trie
// and than having a parent link to each node to move up until
// the parent has two or more children, that will be the end of
// the word's prefix.
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
# define ALPHA    'a'
# define ALPHABET 26 
# define blastoff( C) (( C) - ALPHA)
////////////////////////////////////////////////////////////////
struct Node {
    Node* pare;
    Node* chil[ ALPHABET] = { nullptr};
    int nchil = 0;
    Node( Node* pare = nullptr): pare( pare) {}
};
////////////////////////////////////////////////////////////////
class Solution {
private:
    vector< Node*> leaf;
public:
    vector< string> findPrefixes( string* arr, int n);
    void insert_coin( const string& word, Node* p);
};
////////////////////////////////////////////////////////////////
void Solution::insert_coin( const string& word, Node* p) {
    for( int j = 0; j < word.size(); ++j) {
        int off = blastoff( word[ j]);
        if(! p->chil[ off]) {
            p->chil[ off] = new Node( p);
            p->nchil++;
        }
        p = p->chil[ off];
    }
    leaf.push_back( p);
}
////////////////////////////////////////////////////////////////
vector< string> Solution::findPrefixes( string* arr, int n) {
    Node* root = new Node();
    for( int j = 0; j < n; j++) {
        insert_coin( arr[ j], root);
    }
    vector< int> tail;
    for( auto p: leaf) {
        int cun = 0; // counter
        while( p->pare->nchil < 2) {
            p = p->pare;
            cun++;
        }
        tail.push_back( cun);
    }
    vector< string> ans;
    for( int j = 0; j < n; j++) {
        int off = arr[ j].size() - tail[ j];
        ans.push_back( arr[ j].substr( 0, off));
    }
    return ans;
}
////////////////////////////////////////////////////////////////
// The Python code didn't want to pass the last case, and had to
// rewrite it in C++.
// Test Cases Passed: 10005 / 10005
// Total Time Taken:    0.4 / 1.4
////////////////////////////////////////////////////////////////
int main() {
    int t;
    cin >> t;
    while( t--) {
        int n;
        cin >> n;
        
        string arr[ n];
        for( int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector< string> ans = ob.findPrefixes( arr, n);
        
        for( int i = 0; i < ans.size(); i++) {
            cout << ans[ i] <<" ";
        }
        cout << "\n";
    }
}
////////////////////////////////////////////////////////////////
