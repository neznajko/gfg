################################################################
# Add Binary Strings
################################################################
# Given two binary strings A and B consisting of only 0s and 1s. 
# Find the resultant string after adding the two Binary Strings.
# Note: The input strings may contain leading zeros but the 
# output string should not have any leading zeros.
################################################################
# Input: A = "1101", B = "111"
# Output: 10100
################################################################
# Expected Time Complexity: O(max(|A|,|B|))
# Expected Auxiliary Space: O(max(|A|,|B|))
################################################################
# 1 ≤ |A|,|B| ≤ 10⁶
################################################################
################################################################
################################################################
################################################################
import re
from collections import deque
################################################################
################################################################
################################################################
################################################################
def discard_leading_zeroes( s ):
    s = re.sub( r"^0+", "", s )
    if not s: s = "0"
    return s
################################################################
################################################################
def add_leading_zeroes( m, s ):
    return '0' * ( m - len( s )) + s
################################################################
################################################################
################################################################
class Solution:
    def addBinary( self, A, B ):
        A = discard_leading_zeroes( A )
        B = discard_leading_zeroes( B )
        m = max( len( A ), len( B ))
        A = add_leading_zeroes( m, A )
        B = add_leading_zeroes( m, B )
        deq = deque()
        c = 0
        for j in reversed( range( m )):
            s = ord( A[ j ]) + ord( B[ j ]) + c
            d = s & 1
            c = ( s >> 1 ) & 1
            deq.appendleft( d )
        if c: deq.appendleft( c )
        return ''.join( map( str, deq ))
################################################################
################################################################
################################################################
################################################################
if __name__ == '__main__':         #############################
    T=int(input())                 #############################
    for i in range(T):             #############################
        a,b = input().split(" ")   #############################
        ob = Solution()            #############################
        answer = ob.addBinary(a,b) #############################
        print(answer)
################################################################
################################################################
################################################################
################################################################
# Test Cases Passed:                                 1022 / 1022
# Points Scored:                                           4 / 4
# Your Total Score:                                         1858 
# Time Taken:                                               0.56
# 1.3.15: On the inner surface of a smooth cylinder with radius
# R an object is released in a direction having angle æ with
# respect to the vertical. What initial velocity it must have so
# it returns to the starting position?
#
#  v   ^ vcosæ         vTsinæ = 2(pi)R // 2(pi)nR, see below
#   ` æ|               vcosæ - g(T|2) = 0
#    ` |               T is a time for one cycle, in vertical
#     `|               direction at T|2 velocity will be 0, zo
#  <---+               v = [2(pi)R]|Tsinæ
#  vsinæ               T = 2vcosæ|g
#                      v² = [2g(pi)R]|sin2æ
#                      the answer is v = sqrt([2g(pi)nR]|sin2æ),
#                      where n is 1, 2, 3, .., bcoz it will be 
#                      at starting position not only if it makes 
#                      one cycle but aslo 2, 3, etc.
################################################################
#
