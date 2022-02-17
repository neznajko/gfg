////////////////////////////////////////////////////////////////
/* Divisn without usng multiplication, division and mod operator 
 * Medium Accuracy: 75.21% Submissions: 4981 Points: 4
 * Givn two integrs dividend and divisr. Find the quotient after
 * dividng dividend by divisor witout using multiplicatn, divisn
 * and mod operator.
 *
 * Your task:
 * You don't have to read input or print anything. Your task is to
 * complete the function divide() which takes two integers a and b
 * as input and returns the quotient after dividing a by b.
 *
 * Expected Time Complexity: O(log(a))
 * Expected Auxiliary Space: O(1)
 *
 * Constraints : -10^9 <= a,b <= 10^9
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
////////////////////////////////////////////////////////////////
# include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
typedef long long int long_t; // LLong, loong, lounge_t,
////////////////////////////////////////////////////////////////
class Solution {
private:
    bool _negative = false;
    void chck( long_t& y); // check if y is negative
public:
    long_t divide( long_t a, long_t b);
};
void Solution::chck( long_t& y) {
    if( y < 0) {
        y = -y;
        _negative = !_negative;
    }
}
long_t Solution::divide( long_t a, long_t b) {
    // Figure sign of the result and make both a, b positive.
    chck( a);
    chck( b);
    // make an offset loop and get the quotient
    int q{};
    // 2^30 = 1073741824( Why long long?)
    // -I got it, so the shift can work.
    for( off_t j{ 30}; a >= b and j > -1; j--) {
        if( b << j <= a) {
            a -= b << j;
            q |= 1 << j;
        }
    }
    return _negative ? -q : q;
}
////////////////////////////////////////////////////////////////
int main() {
	int t;
	cin >> t;
	while( t--)	{
		long_t a, b;
		cin >> a >> b;
		Solution ob;
		cout << ob.divide( a, b) << "\n";
	}
}
////////////////////////////////////////////////////////////////
// log: https://youtu.be/ni7IsBVqCMA
// Test Cases Passed: 10151/10151
// Total Time Taken:  0.0/1.0
// It's interesting that in usual division time complexity is if
// not mistaken quadratic with respect of number of bits that is
// log(a) square, vhether here it's log(a).
////////////////////////////////////////////////////////////////
