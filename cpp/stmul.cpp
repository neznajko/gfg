////////////////////////////////////////////////////////////////
// Multiply two strings
////////////////////////////////////////////////////////////////
// Medium Accuracy: 26.16% Submissions: 100k+ Points: 4
////////////////////////////////////////////////////////////////
// Given two numbers as strings s1 and s2. Calculate their Produ ct.
// Note: The numbers can be negative.                            ---
////////////////////////////////////////////////////////////////
// Your Task: You don't need to read input or print anything. Yo ur--
// task is to complete the function multiplyStrings() which take s===
// two strings s1 and s2 as input and returns their product as a ====
// string.                                                       ;;;;
// Note: You are not allowed to use any built-in function or con vèrt
// the strings to integer.                                       ````
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(n1 * n2)
// Expected Auxiliary Space: O(n1 + n2)
////////////////////////////////////////////////////////////////
// Constraints:
// 1 ≤ n1,n2 ≤ 10³
////////////////////////////////////////////////////////////////
#                                             include <iostream>
#                                               include <string>
////////////////////////////////////////////////////////////////
                                            using namespace std; 
////////////////////////////////////////////////////////////////
                                                class Solution {
                                                         public:
                 string multiplyStrings( string& s, string& t );
                                                              };
////////////////////////////////////////////////////////////////
// s must have enough space, left padded with zeroes
// s: 099
// t:   1
int inc( string& s, const string& t ){
    int i = s.size() - 1, // i: 2
        j = t.size() - 1; // j: 0
    int c = 0; // guess what!
    for(; j >= 0; i--, j-- ){ // j: -1, i: 1
        int sum = ((s[i] - '0') +
                   (t[j] - '0')); // sum: 10
        sum += c; // sum: 10
        c = sum / 10; // c: 1
        s[i] = sum % 10 + '0'; // s: 090
    }
    if( c == 1 ){ // perform carry on remainin digits of s
        while( true ){
            if( s[i] == '9' ){ // true
                s[i--] = '0'; // s: 000, i: 0
            } else {
                s[i]++; // s: 100
                break;
            }
        }
    }
    return i; // i: 0
}
////////////////////////////////////////////////////////////////
// à la Français( Dasgupta et al.)
// s*t = s*([t/10]*10 + t%10) = (s*[t/10])*10 + s*(t%10)         -----
// if t is string like 12345, than t%10 is the last character 5  -----
// that is t.back(); [t/10] is pop_back() and *10 is push_back(' 0').-
// There is no way how to reduce s*t if t is digit, so we have t o----
// implement it. Here s must have at least one leading zero, d s hould
// be in the range [1, 9].
void cross( string& s, int d ){
    const string t( s );
    for( int j = 1; j < d; j++ ){
        inc( s, t );
    }
}
////////////////////////////////////////////////////////////////
// s*t = (s*[t/10])*10 + s*(t%10)
// make sure ::t is not empty here
// s: 525, t: 474
void mul( string& s, string &t ){
    int d = t.back() - '0'; // d = t%10
    t.pop_back();           // t = t/10
    if( t.empty() ){
        return cross( s, d );
    }
    // backup
    string copy = s; 
    // recursivly calculate first part
    mul( s, t );
    // multiply by 10
    s.push_back( '0' );
    // increment with the crossection
    if( d > 0 ){
        cross( copy, d );
        inc( s, copy );
    }
}
////////////////////////////////////////////////////////////////
struct st {
    bool  sign;
    int   len;
    char* bufr;
    st( const string& s );
};
////////////////////////////////////////////////////////////////
st::st( const string& s ){
    int off;
    switch( s.front() ){
        case '-':
            sign = true;
            off = 1;
            break;
        case '+':
            sign = false;
            off = 1;
            break;
        default:
            sign = false;
            off = 0;
            break;
    }
    // discard leading zeroes
    for(; s[off] == '0'; ++off )
        ;
    len = s.size() - off;
    bufr = (char *)s.data() + off;
}
////////////////////////////////////////////////////////////////
string Solution::multiplyStrings( string& s, string& t ){
    // f0rmat
    auto S = st( s ),
         T = st( t );
    if( T.len > S.len ){
        swap( S, T );
    }
    const bool sign = S.sign ^ T.sign;
    auto s1 = string( T.len + 1, '0' ) + string( S.bufr ),
         t1 = string( T.bufr );
    if( t1.empty() ) return "0";
    // do the math
    mul( s1, t1 );
    // post production
    // find first non nil digit
    int j = -1;
    while( s1[++j] == '0' )
        ;
    if( sign ){
        s1[--j] = '-';
    }
    return s1.substr( j );
}
////////////////////////////////////////////////////////////////
                                                    int main() {
                                                          int t;
                                                       cin >> t;
                                                   while( t-- ){
                                                       string a;
                                                       string b;
                                                  cin >> a >> b;
                                                   Solution obj;
                     cout << obj.multiplyStrings( a, b) << endl;
                                                               }
                                                               }
////////////////////////////////////////////////////////////////
// Test Cases Passed: 332 / 332
// Total Time Taken: 0.6
// Attempts No.: 5
//
// log:
