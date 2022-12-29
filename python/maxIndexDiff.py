################################################################
# Maximum Index
###############################################################_
# Given an array Arr[] of N positive integers.
# The task is to find the maximum of j - i subjected to
# the constraint of Arr[i] <= Arr[j].
######################################################## Example
# Input:       N = 9
#              Arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
# Output:      6
# Explanation: In the given array Arr[1] < Arr[7] satisfying
# required condition (Arr[i] <= Arr[j]) thus giving the maximum
# difference of j - i which is 6 (7-1).
################################################################
# Expected Time Complexity: O(N)
# Expected Auxiliary Space: O(N)
################################################################
# I thought I've gone completely stupid and unable to do anything
# and was happy to found O(1) in space solution, vhether it's
# O(N) in time don't know but has passed the tests, the idea is
# that we can use the info gathered from the previous loops.
#-----     -----                 
#     -----
#                 i                                     -----
# q < i - 2     -----                     p = j - 2       j
################################################################
#  0 #  1 #  2 #  3 #  4 #  5 #  6 #  7 #  8 #  9 # 10 # 11 #
#    #    #    #    #    #    #    #    #    #    #    #    #
#  8 #  7 #  6 #  4 #    #    #    #    #    # 10 #  6 #  5 #
class Solution:
    def maxIndexDiff( self, a, n ):
        i, j = 0, n - 1 # 0, 11
        while a[ i ] > a[ j ]: i += 1 # i = 3
        # o o
        k = 0
        while True:
            k += 1 # 1, 2, 1
            p = j - k # 10, 9, 8
            if i - k <= 0: break # 2, 1, -1
            if a[ p ] <= a[ j ]: continue
            for q in range( i - k ):
                if a[ q ] <= a[ p ]:
                    i, j = q, p # 0, 9
                    k = 0
                    break
        return j - i
###############################################################_
if __name__ == "__main__":
    a = [ 9,34,8,10,3,2,80,30,33,1 ]
    n = len( a )
    ob = Solution()
    print( Solution().maxIndexDiff( a, n ))
################################################################
# Test Cases Passed: 1114 / 1114 
# Total Points Scored: 4 / 4     
# Your Total Score: 962          
# Total Time Taken: 0.39         
# Your Accuracy: 50%
# Attempts No.: 2
################################################################
