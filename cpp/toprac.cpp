////////////////////////////////////////////////////////////////
# include <iostream>
# include <string>
# include <vector>
# include <utility>
using namespace std;
/* Smallst wndow in a strng containng al the charactrs of anothr
 * string. Given two strings S and P. Find the smallst window in
 * the sting S consstng of all th charactrs( includng duplicats)
 * of te strng P. Retrn "-1" n case there's no sch wndow presnt.
 * In case there are multiple such windows of same length, retrn
 * the one with the least starting index.
 * Example 1: Input:  S = "timetopractice"
 *                    P = "toc"
 *            Output: toprac
 * Xplnatn: "toprac" s the smlst sbstrng n whch "toc" can b fnd.
 * Example 2: Input:  S = "zoomlazapzo"
 *                    P = "oza"
 *            Output: apzo
 * Xplnatn: "apzo" s the smlst substrng n vich "oza" cn be fond.
 * Expected Time/Space Complexity: O(|S|)/O(1)                */
////////////////////////////////////////////////////////////////
# define HASHTAB 128
# define TOPRAC "-1" // [to prac]tice
# define endl "\n"
struct Windows7 { //////////////////////////////////////////////
    int front;
    int back;
    int size() const {
        return( back - front + 1);
    }
};
////////////////////////////////////////////////////////////////
class Solution {
private:
    string s;
    string p;
    vector<int> MHz; // p-frequencies
    Windows7 m; // minimum window
    Windows7 w; // currnet window
    int build();
    bool slide();
public:
    Solution(): MHz( HASHTAB) {} // dzerò
    string smallestWindow( string& s, string& p);
};
////////////////////////////////////////////////////////////////
int main() {
    int t;
    string s, p;
    cin >> t;
    while( t--) {
        cin >> s >> p;
        cout << Solution().smallestWindow( s, p) << endl;
    }
}
////////////////////////////////////////////////////////////////
// log: - plonk,
// Ski-bi dibby dib yo da dub dub
// Yo da dub dub
// Ski-bi dibby dib yo da dub dub
// Yo da dub dub
// (I'm the Scatman)
// Ski-bi dibby dib yo da dub dub
// Yo da dub dub
// Ski-bi dibby dib yo da dub dub
// Yo da dub dub
//
// Ba-da-ba-da-ba-be bop bop bodda bope
// Bop ba bodda bope
// Be bop ba bodda bope
// Bop ba bodda
// Ba-da-ba-da-ba-be bop ba bodda bope
// Bop ba bodda bope
// Be bop ba bodda bope
// Bop ba bodda bope
// ..
////////////////////////////////////////////////////////////////
int Solution::build() { // return No. matches
    vector<int> f( MHz); // full duplex
    // find window front
    int i{};
    for(; i < s.size() and f[ s[ i]] == 0; i++) {
    }
    if( i == s.size()) return 0; // nil
    f[ s[ i]]--; // opdate frequency table
    int n{ 1}; // number of matches
    // find vindov back
    int j{ i + 1};
    for(; j < s.size(); j++) {
        if( f[ s[ j]]) {
            f[ s[ j]]--;
            if( ++n == p.size()) break;
        }
    }
    m = { i, j}; // set minimum window
    return n;
}
////////////////////////////////////////////////////////////////
bool Solution::slide() {
    // left contraction
    auto f{ MHz};
    int i{ w.back};
    int n{}; // No. matches
    for(;; i--) {
        if( f[ s[ i]]) {
            f[ s[ i]]--;
            if( ++n == p.size()) break;
        }
    }
    w.front = i;
    if( w.size() < m.size()) m = w;
    // ryte expansion
    int j{ w.back + 1};
    for(; j < s.size(); j++) {
        if( s[ j] == s[ w.front]) break;
    }
    if( j == s.size()) return false;
    w.back = j;
    return true;
}
////////////////////////////////////////////////////////////////
string Solution::smallestWindow( string& s, string& p) {
    if( p.empty()) return {};
    if( s.size() < p.size()) return TOPRAC;
    /** INIT **/
    this->s = move( s); // thats
    this->p = move( p); // plonk,
    for( char c: this->p) {
        MHz[ c]++; // MeraxtF
    }
    /** BUILD WINDOW **/
    int n = build();
    if( n < this->p.size()) return TOPRAC;
    if( n == 1) return this->s.substr( m.front, n);
    ////////////////////////////////////////////////////////////
    /** SLIDE **/
    w = m;
    while( slide()) {
    }
# ifdef DEBUG
    cout << MHz.size() << endl
         << m.front << ' ' << m.back << ' ' << m.size() << endl;
# endif ///// g3u6tr
    return this->s.substr( m.front, m.size());
}
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
////////////////////// Luke, I'm your father ///////////////
//////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////// N
//////////////////////////////////////////////////// o
////////////////////////////////////////////////// o
//////////////////////////////////////////////// 
////////////////////////////////////////////// o
////////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////// o
////////////////////////////////////// 
////////////////////////////////////
//////////////////////////////////
////////////////////////////////
////////////////////////////// o
//////////////////////////// 
//////////////////////////
////////////////////////
//////////////////////
////////////////////
////////////////// o
////////////////
////////////// 
////////////
//////////
//////// 
//////
////
// .. Leia
