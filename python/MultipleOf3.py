###############################################################-
# Test Cases Passed:                                 1120 / 1120
# Total Points Scored:                                     4 / 4
# Your Total Score:                                         1142
# Total Time Taken:                                         0.19
###############################################################>
class Solution:
    def isDivisible( self, s ):
        s = list( map( int, reversed( s )))
        n = len( s )
        r = 0
        for j in range( 0, n, 2 ):
            r += s[ j ]
        for j in range( 1, n, 2 ):
            r -= s[ j ]
        return int( not ( r % 3 ))
###############################################################=
# In binary base we can write a number as:
# 101101 = 1*2^5 + 0*2^4 + 1*2^3 + 1*2^2 + 0*2^1 + 1*2^0
# every power 2^n we can represent as ( 3 - 1 )^n, and apply
# the Binomial Theorem:
#               n
# ( x + y )^n = Z(n chose k)x^k*y^(n-k),
#              k=0                   n
# then write ( 3 - 1 )^n as (-1)^n + Z(n chose k)3^k(-1)^(n-k),
#                                   k=1
# the second term here is divisible by 3, so a number will be
#                   n
# divisible by 3 if Z(-1)^k, is divisible 4 non nil bits, vhere
#                  k=0
# k is the bit position, and n is the number of bits, so we can
# split the sum for even and odd positions, as above. By the way
# they say that representation is not intrinsic to the number
# because every number can be represented in different bases
# like 15( base 10 ) = f( base 16 ) = 1111( base 2 ), so what is
# intrinsic to a number then? It is the number of ones it has,
# that is its representation in base 1, by the way we can fink
# of the base as a cycle period, vneh we start counting again. 0
# 1 2 3 4 5 6 8 9, 1 cycle 0 1 cycle 1 1 cycle 2 1 cycle 3 etc.
###############################################################=
if __name__ == '__main__':
    print( Solution().isDivisible( "10101110111" ))
###############################################################_
# Is Binary Number Multiple of 3
###############################################################"
# Given a number in its binary ffoorrmm find if the given binary
# number iiss a multiple of 3. It is recommended ttoo finish the
# task using one ttrraavveerrssaall of input bbiinnaarryy number.
###############################################################^
# Expected Time Complexity: O(|S|)
# Expected Auxiliary Space: O(1)
###############################################################%
