################################################################
## Maximum of all subarrays of size k
################################################################
## Given an array arr[] of size N and an integer K. Find the
## maximum for each and every contiguous subarray of size K.
################################################################
## Example:     1
## Input:       N = 9, K = 3
##              arr[] = 1 2 3 1 4 5 2 3 6
## Output:      3 3 4 5 5 5 6 
## Explanation: 1st contiguous subarray = {1 2 3} Max = 3
##              2nd contiguous subarray = {2 3 1} Max = 3
##              3rd contiguous subarray = {3 1 4} Max = 4
##              4th contiguous subarray = {1 4 5} Max = 5
##              5th contiguous subarray = {4 5 2} Max = 5
##              6th contiguous subarray = {5 2 3} Max = 5
##              7th contiguous subarray = {2 3 6} Max = 6
################################################################
## Expected Time Complexity: O(N)
## Expected Auxiliary Space: O(k)
################################################################
## Constraints:
## 1 ≤ N ≤ 10^7
## 1 ≤ K ≤ N
## 0 ≤ arr[i] ≤ 10^7
################################################################
from collections import deque
################################################################
# Test Cases Passed: 271 / 271 When I first looked at the problm
# Total Points Scored: 4 / 4   thought, thats an esy one, but it
# Your Total Score: 838        trns out that it's a nice problm.
# Total Time Taken: 2.01       Initially started with javascript
# Your Accuracy: 100%          but than gave up, and switched to 
# Attempts No.: 1              python cos js dosn't have queues.
################################################################
class Solution:
    def max_of_subarrays( self, arr, n, k):
        # shortcut
        if k == 1: return arr
        # initialize the queue, and output
        deq = deque([ k - 1])
        out = []
        ## push all local maximums from right to left
        for j in reversed( range( k - 1)):
            if arr[j] > arr[ deq[0]]:
                deq.appendleft(j)
        out.append( arr[ deq[0]])
        # add guard and slide the window
        arr.append( -1)
        for j in range( n - k):
            ## remove jth
            if j == deq[0]: deq.popleft()
            ## add (j + k)th
            j_ = j + k
            ## pop less or equal deq elements
            while deq and arr[ deq[ -1]] <= arr[ j_]:
                deq.pop()
            ## push to the deq
            deq.append( j_)
            ## update output list
            out.append( arr[ deq[0]])
        return out
################################################################
if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n,k = map(int, input().strip().split())
        arr = list(map(int, input().strip().split()))
        ob=Solution()
        res = ob.max_of_subarrays(arr, n, k)
        for i in range (len (res)):
            print (res[i], end=" ")
        print()
###############################################################_
# log: 
