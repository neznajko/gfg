#######################################################*
# Test Cases Passed:                           104 / 104
# Total Points Scored:                             4 / 4
# Your Total Score:                                 1146
# Total Time Taken:                                 0.02
#######################################################_
COINS = 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000
#######################################################=
class Solution:
    def minPartition( self, N ):
        coins = list( COINS )
        ls = []
        while N > 0:
            while coins[ -1 ] > N:
                coins.pop()
            ls.append( coins[ -1 ])
            N -= coins[ -1 ]
        return ls
#######################################################-
if __name__ == '__main__':
    print( Solution().minPartition( 117 ))
#######################################################=
# Minimum number of Coins             ..................
######################################..................
# Given an infinite supply of each denomination of......
# Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500,.
# 2000 } and a target value N. Find the minimum number..
# of coins and/or notes needed to make the change for...
# Rs N. You must return the list containing the value...
# of coins required.                  ..................
#######################################################>
# Expected Time Complexity: O(N)      ..................
# Expected Auxiliary Space: O(N)
#######################################################%
