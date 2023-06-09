################################################################
# Subset Sum Problem
################################################################
# Given an array of non-negative integers, and a value sum, 
# determine if there is a subset of the given set with sum equal
# to given sum. 
################################################################
# Example: 1 Input: N = 6 Arr[] = { 3, 34, 4, 12, 5, 2 } Sum = 9
# Output: 1 Explanation: Here there exists a subset with Sum = 9, 
# 4 + 3 + 2 = 9.
################################################################
# Expected Time Complexity: O( Sum * N )
# Expected Auxiliary Space: O( Sum * N )
###############################################################=
# d( j, som ):
# if som == 0: return True
# if j < 0: return False
# skp   <- d( j - 1, som )
# taike <- d( j - 1, som - A[j] )
########################################################_#######
###############################################################-
# Test Cases Passed:                                     36 / 36
# Total Points Scored:                                     4 / 4
# Your Total Score:                                         1130
# Total Time Taken:                                          3.1
################################################################
class Solution:
    def isSubsetSum( self, N, Arr, Sum ):
        self.cache = {}
        self.Arr = Arr
        return Solution.dp( self, N - 1, Sum )
    def dp( self, j, Sum ):
        if not Sum: return True
        if j < 0: return False
        key = j, Sum
        if key in self.cache: return self.cache[ key ]
        skp = self.dp( j - 1, Sum )
        taike = self.dp( j - 1, Sum - self.Arr[ j ])
        res = skp or taike
        self.cache[ key ] = res
        return res
################################################################
if __name__ == '__main__': 
    N = int( input())
    Arr = list( map( int, input().split()))
    Sum = int( input())
    ob = Solution()
    print( int( ob.isSubsetSum( N, Arr, Sum )))
###############################################################_
