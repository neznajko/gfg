################################################################
# Total Decoding Messages
################################################################
# A top secret message containing letters from A-Z is being
# encoded to numbers using the following mapping:
# A ->  1
# B ->  2
# ...
# Z -> 26            
#                    
# You are an FBI agent. You have to determine the total number
# of ways that message can be decoded, as the answer can be
# large return the answer modulo 10^9 + 7.
# Note: An empty digit sequence is considered to have one
# decoding. It may be assumed that the input contains valid
# digits from 0 to 9 and If there are leading 0s, extra trailing
# 0s and two or more consecutive 0s then it is an invalid string.
################################################################
# Example: 1
################################################################
# Input: str = "123"
# Output: 3
# Explanation: "123" can be decoded as "ABC"(123), "LC"(12 3)
# and "AW"(1 23).
################################################################
# Example: 2
################################################################
# Input: str = "90"
# Output: 0
# Explanation: "90" cannot be decoded as it's an invalid string
# and we cannot decode '0'.
################################################################
# Expected Time Complexity: O(n)
# Expected Space Complexity: O(n), where n  = |str|
################################################################
class Solution:
    def CountWays( self, s ):
        if not s: return 1
        n = len( s )
        self.s = s
        self.cache = [ None ]* ( n + 1 )
        self.cache[( n - 1 ):] = int( s[ -1 ] != "0" ), 1
        return self.DP( 0 )
    def DP( self, j ):
        if self.cache[ j ]: return self.cache[ j ]
        if self.s[ j ] == "0": return 0
        takeOne = self.DP( j + 1 )
        twoDigit = int( self.s[ j:( j + 2 )])
        takeTwo = 0
        if twoDigit < 27:
            takeTwo = self.DP( j + 2 )
        self.cache[ j ] = ( takeOne + takeTwo ) % 1000000007
        return self.cache[ j ]
###############################################################=
# Test Cases Passed: 1 6                9/ 1 6   9
# Total Points Scored:          4                        /4
# Your Total Score:   1   0                       9 4
# Total Time Taken: 0 . 0            7
################################################################
print( Solution().CountWays( "12053724" ))
###################################__###########################
