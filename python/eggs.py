########################################################
# Egg Dropping Puzzle 
# Medium Accuracy: 54.38% Submissions: 39030 Points: 4
########################################################
# Egg Dropping Puzzle
#
# You are given N identical eggs and you have access to
# a K-floored building from 1 to K.
#
# There exists a floor f where 0 <= f <= K such that any
# egg dropped at a floor higher than f will break, and 
# any egg dropped at or below floor f will not break.
# There are few rules given below.
#
# An egg that survives a fall can be used again.
# A broken egg must be discarded.
# The effect of a fall is the same for all eggs.
# If the egg doesn't break at a certain floor, it will
# not break at any floor below.
# If the eggs breaks at a certain floor, it will break
# at any floor above.
# Return the minimum number of moves that you need to
# determine with certainty what the value of f is.
#
# For more description on this problem see wiki page
#
# Expected Time Complexity : O(N*K)
########################################################
import math
########################################################
class Solution:
    def eggDrop( self, n, k):
        self.tab = [[ 0]*( k + 1) for _ in range( n + 1)]
        return self.egs( n, k)

    def egs( self, n, k):
        if n == 1: return k
        if k == 0: return 0
        if self.tab[ n][ k]: return self.tab[ n][ k]
        min_res = math.inf
        for f in range( 1, k // 2 + 2):
            p = 1 + self.egs( n - 1, f - 1) # broken egg
            q = 1 + self.egs( n, k - f) # not broken
            res = max( p, q)
            if res < min_res: min_res = res
        self.tab[ n][ k] = min_res
        return min_res
########################################################
# 134/134
# 0.1/1.7
########################################################
if __name__ == '__main__':
    test_cases = int( input())
    for cases in range( test_cases):
        n, k = map( int, input().strip().split())
        ob = Solution()
        print( ob.eggDrop( n, k))
########################################################
