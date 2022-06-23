################################################################
# Majority Element
# Medium Accuracy: 48.6% Submissions: 100k+ Points: 4
################################################################
# Given an array A of N elements. Find the majority element in
# the array. A majority element in an array A of size N is an
# element that appears more than N/2 times in the array.
################################################################
# Example: 1
# Input: N = 3, A[] = {1,2,3} 
# Output: -1
# Explanation:
# Since, each element in {1,2,3} appears only once so there is
# no majority element.
################################################################
# Example: 2
# Input: N = 5, A[] = {3,1,3,3,2} 
# Output: 3
# Explanation: Since, 3 is present more than N/2 times, so it is 
# the majority element.
################################################################
# Your Task: The task is to complete the function
# majorityElement() which returns the majority element in the
# array. If no majority exists, return -1.
################################################################
# Expected Time Complexity: O(N).
# Expected Auxiliary Space: O(1).
################################################################
# Constraints:
# 1 ≤ N ≤ 10^7
# 0 ≤ A[i] ≤ 10^6
################################################################
# Test Cases Passed: 121 / 121
# Total Time Taken: 0.83 / 2.32
class Solution:
    def majorityElement( self, A, n ):
        # Define dictionary.,
        D = {}
        # Count A's frequencies:
        for y in A:
            if y in D:
                D[y] += 1
            else:
                D[y] = 1
        ## Check if majority element exist,.
        n >>= 1 # n <- n/2
        for key in D:
            if D[key] > n:
                return key
        return -1
################################################################
def main():
    T = int( input())
    while( T > 0):
        N = int( input())
        A = [ int(x) for x in input().strip().split() ]
        obj = Solution()
        print( obj.majorityElement( A, N ))
        T -= 1
if __name__ == "__main__": main()
################################################################
