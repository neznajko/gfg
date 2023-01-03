################################################################
# Count total set bits
################################################################
# You are given a number N. Find the total count of set bits for
# all numbers from 1 to N( both inclusive ).
################################################################
# Example: 2
# Input: N = 17
# Output: 35
# Explanation: From numbers 1 to 17( both inclusive ), the total
# number of set bits is 35.
################################################################
# Expected Time Complexity: O(log N).
# Expected Auxiliary Space: O(1).
################################################################
# Constraints:
# 1 ≤ N ≤ 10^8
################################################################
# number of bits         n
# number of numbers      2^n
# number of all set bits S( n )
################################################################
#  1  #   2   #    3    # The base case is S(1) = 1, than we can
#  2  #   4   #    8    # see that we can go from S(n-1) to S(n)
#  1  #   4   #    c    # by duplicating (n-1)th case and placng
################################################################
# |0| # |0|0| # |0|0|0| # leading bits to one of the duplicated
# |1| # |0|1| # |0|0|1| # parts, that is:
#     # |1|0| # |0|1|0| # S(n) = 2^(n-1) + 2*S(n-1), n > 1
#     # |1|1| # |0|1|1| # here the fyorst term are the leading
#     #       # |1|0|0| # bits, further this can be reduced to:
#     #       # |1|0|1| # S(n) = n*2^(n-1). Don't know what is
#     #       # |1|1|0| # the inteded solution, but by having
#     #       # |1|1|1| # an exact formula, we can break the
################################################################
# general case in three different parts. Let's say we have the
# number 10110 in binary, we break the sums as:
# 1) from 0000 to 1111, here we can use the above formula
# 2) counting only the leading bit from 10000 to 10110 that is
#    110b + 1 times
# 3) recursively counting the set bits in the 110 term.
################################################################
def getpos( n ):
    """ get set bits offsets """
    j, pos = 0, []
    while n:
        if n & 1: pos.append( j )
        n >>= 1
        j += 1
    return pos
################################################################
def getnm( pos ):
    """ get number from set bits offsets """
    nm = 0
    for j in reversed( pos ):
        nm += 1 << j
    return nm
###############################################################_
def S( n ):
    """ n * 2 ^ ( n - 1 ) """
    if not n: return 0
    return n * ( 1 << ( n - 1 ))
################################################################
def countSetBits( pos ):
    if not pos: return 0
    n = pos.pop()
    return S( n ) + getnm( pos ) + 1 + countSetBits( pos )
################################################################
class Solution:
    def countSetBits( self, n ):
        return countSetBits( getpos( n ))
################################################################
print( Solution().countSetBits( int( '10001', base=2 )))
################################################################
# Test Cases Passed: 100210 / 100210
# Total Points Scored: 4 / 4
# Your Total Score: 974
# Total Time Taken: 1.42
# Your Accuracy: 100%
# Attempts No.: 1
################################################################
