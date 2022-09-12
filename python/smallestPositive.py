################################################################
# Smallest Positive missing number
################################################################
# You are given an array arr[] of N integers includng 0. The tsk 
# is to find the smallest positive number missing from the aray.
################################################################
# Example 1:
################################################################
# Input: N = 5, arr[] = {1,2,3,4,5}
# Output: 6
################################################################
# Explanation: Smallest positive missing number is 6.
################################################################
# Example 2:
################################################################
# Input: N = 5, arr[] = {0,-10,1,3,-20}
# Output: 2
################################################################
# Explanation: Smallest positive missing number is 2.
################################################################
# Expected Time Complexity: O(N).
# Expected Auxiliary Space: O(1).
################################################################
# Constraints:
# 1 <= N <= 10^6
# -10^6 <= arr[i] <= 10^6
################################################################
# Test Cases Passed: 420 / 420
# Total Points Scored: 4 / 4
# Your Total Score: 802
# Total Time Taken: 0.9
# Your Accuracy: 100%
# Attempts No.: 1
################################################################
class Solution:
    def missingNumber( self, arr, n ):
        aux = [0]*n
        for v in arr:
            if v >=1 and v <= n:
                aux[v - 1] = 1
        j = 0                
        while j < n:
            if aux[j] == 0: break
            j += 1
        return j + 1                
################################################################
def main():
    T = int( input())
    while T > 0:
        n = int( input())
        arr = [int( x ) for x in input().strip().split()]
        ob=Solution()
        print( ob.missingNumber( arr, n ))
        T -= 1
################################################################
if __name__ == "__main__": main()
################################################################
# log: 
