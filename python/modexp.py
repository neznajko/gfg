                            ########
################################################################
# Modular Exponentiation for large numbers
################################################################
# Implement pow(x, n) % M.
################################################################
# In other words, given x, n and M, find (x^n) % M.
################################################################
# Expected Time Complexity: O(log(n))
# Expected Space Complexity: O(1)
################################################################
# Constraints:
# 1 ≤ x, n, M ≤ 10^9
################################################################
# Ok this is a math problem, vhich I know from the Dasgupta book
# :), The idea is to use a recurrence formula for smaller powers
# of n, becoz if n is even than x^n = [x^(n/2)][x^(n/2)], and if
# it i o x^n = x[x^(n/2)][x^(n/2)], zo ve go from x^n to x^(n/2)
#    s d
# t    d        s o           i                      i
# o x^(n/4) and o n, here n/2 s floor operation that s shifting.
# Vhen ve reach 0 the base case the result is 1.
################################################################
class Solution:
    ''''''
    def modexp( self, n ):
        """"""
        if n == 0: return 1
        isodd = n & 1 # check the fyorst bit
        n >>= 1 # n <- floor(n / 2)
        z = self.modexp( n )
        if isodd: return ( self.x * z * z ) % self.m
        else:     return ( z * z ) % self.m
    def PowMod( self, x, n, m ):
        """"""
        self.x = x
        self.m = m
        return self.modexp( n )
##############################################################_-
# Test Cases Passed: 101180 / 101180                          óö
# Total Points Scored: 4 / 4
# Your Total Score: 954
# Total Time Taken: 1.45
# Your Accuracy: 100%
# Attempts No.: 1
################################################################
print( Solution().PowMod( 2, 5, 10 ))
################################################################
########                                                ########
