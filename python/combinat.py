################################################################
################################################################
################################################################
################################################################
# Combination Sum
################################################################
################################################################
################################################################
################################################################
# Given an array of integers and a sum B, find all unique
# combinations in the array where the sum is equal to B. The
# same number may be chosen from the array any number of times
# to make B.
# 
# Note: 1. All numbers will be positive integers.
#       2. Elements in a combination (a1, a2, …, ak) must be in
#          non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
#       3. The combinations themselves must be sorted in
#          ascending order.
################################################################
################################################################
################################################################
################################################################
# Input: N = 4
#        arr[] = {7,2,6,5}
#        B = 16
# Output: (2 2 2 2 2 2 2 2)
#         (2 2 2 2 2 6)
#         (2 2 2 5 5)
#         (2 2 5 7)
#         (2 2 6 6)
#         (2 7 7)
#         (5 5 6)
################################################################
# Expected Time Complexity: O(2^N)
# Expected Auxiliary Space: O(2^N)
################################################################
################################################################
# 1 <= N <= 30
# 1 <= A[i] <= 20
# 1 <= B <= 100
################################################################
################################################################
################################################################
################################################################
class Solution:

    def combinationalSum( self, a, B ):
        self.a = sorted( set( a ))
        self.n = len( self.a )
        self.combinat = []
        self.ls = []
        self.f( 0, B )
        return self.combinat

    def f( self, levl, target_sum ):
        if target_sum == 0:
            self.combinat.append( self.ls[ : ])
        if levl >= self.n: return
        for j in range( levl, self.n ):
            key = self.a[ j ]
            if key > target_sum: break
            self.ls.append( key )
            self.f( j, target_sum - key )
            self.ls.pop()            

################################################################
################################################################
################################################################
################################################################
if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        a = list(map(int,input().strip().split()))
        s = int(input())
        ob = Solution()
        result = ob.combinationalSum(a,s)           ############
        if(not len(result)):                        ############
            print("Empty")                          ############
            continue                                ############
        for i in range(len(result)):                ############
            print("(", end="")                      ############
            size = len(result[i])                   ############
            for j in range(size - 1):               ############
                print(result[i][j], end=" ")        ############ 
            if (size):                              ############
                print(result[i][size - 1], end=")") ############
            else:                                   ############
                print(")", end="")                  ############
        print()                                     ############
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
# Test Cases Passed:                                   215 / 215
# Points Scored:                                           4 / 4
# Your Total Score:                                         1830 
# Time Taken:                                               3.24