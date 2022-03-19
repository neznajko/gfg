////////////////////////////////////////////////////////////////
/* Implement Atoi 
 * Medium Accuracy: 32.9% Submissions: 92428 Points: 4
 *
 * Your task is to implement the function atoi. The function
 * takes a string(str) as argument and converts it to an integer
 * and returns it.
 * 
 * Note: You are not allowed to use inbuilt function.
 * 
 * Example 1:
 * Input:
 * str = 123
 * Output: 123
 *
 * Example 2:
 * Input:
 * str = 21a
 * Output: -1
 *
 * Explanation: Output is -1 as all
 * characters are not digit only.
 * Your Task:
 *
 * Complete the function atoi() which takes a string as input
 * parameter and returns integer value of it. if the input
 * string is not a numerical string then returns -1.
 * 
 * Expected Time Complexity: O(|S|), |S| = length of string str.
 * Expected Auxiliary Space: O(1)
 * 
 * Constraints:
 * 1 ≤ length of S ≤ 10
 * 
 * Note:The Input/Ouput format and Example given are used for
 * system's internal purpose, and should be used by a user for
 * Expected Output only. As it is a function problem, hence a
 * user should not read any input from stdin/console. The task
 * is to complete the function specified, and not to write the
 * full code.
 *//////////////////////////////////////////////////////////////
# include <iostream>
# include <cctype>
using namespace std;
////////////////////////////////////////////////////////////////
class Solution {
  public:
    int atoi( const string& a);
};
int Solution::atoi( const string& a) {
    const bool neg = a[ 0] == '-';
    const int end = neg ? 0 : -1;
    int i = 0; // the integer
    int b = 1; // base
    for( int j = a.size() - 1; j > end; j--) {
        if(! isdigit( a[ j])) return -1;
        i += ( a[ j] - '0')*b;
        b *= 10;
    }    
    return neg ? -i : i;
}
// Test Cases Passed: 10008 / 10008
// Total Time Taken:    0.0 / 1.4
////////////////////////////////////////////////////////////////
int main() {
    int t;
    cin >> t;
    while( t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.atoi( s) << endl;
    }
}
////////////////////////////////////////////////////////////////
//    
//
