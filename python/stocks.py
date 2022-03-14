################################################################
# Stock buy and sell 
# Medium Accuracy: 39.53% Submissions: 69785 Points: 4
################################################################
# The cost of stock on each day is given in an array A[] of size
# N. Find all the days on which you buy and sell the stock so
# that in between those days your profit is maximum.  Note:
# There may be multiple possible solutions. Return any one of
# them. Any correct solution will result in an output of 1,
# whereas wrong solutions will result in an output of 0.
################################################################
# Example 1:
# Input:
# N = 7
# A[] = {100,180,260,310,40,535,695}
# Output:
# 1
# Explanation:
# One possible solution is (0 3) (4 6) We can buy stock on day
# 0, and sell it on 3rd day, which will give us maximum
# profit. Now, we buy stock on day 4 and sell it on day 6.
################################################################
# Example 2:
# Input:
# N = 5
# A[] = {4,2,2,2,4}
# Output:
# 1
# Explanation:
# There are multiple possible solutions.  one of them is (3 4)
# We can buy stock on day 3, and sell it on 4th day, which will
# give us maximum profit.
################################################################
# Your Task:
# The task is to complete the function stockBuySell() which
# takes an array A[] and N as input parameters and finds the
# days of buying and selling stock. The function must return a
# 2D list of integers containing all the buy-sell pairs. If
# there is No Profit, return an empty list.
################################################################
# Note: Since there can be multiple solutions, the driver code
# will return 1 if your answer is correct, otherwise, it will
# return 0. In case there's no profit the driver code will
# return the string "No Profit" for a correct solution.
################################################################# 
# Expected Time Complexity: O(N)
# Expected Auxiliary Space: O(N)
################################################################
# Constraints:
# 2 ≤ N ≤ 10^6
# 0 ≤ A[i] ≤ 10^6
################################################################
class Solution:
    def stockBuySell( self, A, n):
        bs = [] # buy-sell list
        A.append( None) # add Sentinel
        j = 0 # current position
        while True:
            # srch for buying position, that is a sequence
            # A[j] < A[j+1]
            A[ n] = A[ j] + 1 # make sure the condition exists
            while A[ j] >= A[ j+1]: j += 1
            if j == n - 1: break # done
            buy = j
            # srch for selling position( A[j] > A[j+1])
            A[ n] = A[ j] - 1 # make sure it exists
            j += 1
            while A[ j] <= A[ j+1]: j += 1
            sell = j
            bs.append(( buy, sell))
        A.pop()
        return bs
#################################################### Driver Code
def check( ans, A, p):
    c = 0
    for i in range( len( ans)):
        c += A[ans[i][1]] - A[ans[i][0]]
    if c == p:
        return 1 
    else:
        return 0
################################################################
if __name__ == '__main__':
    t = int( input())
    while t > 0:
        n = int( input())
        A = [int( x) for x in input().strip().split()]
        ob = Solution()
        ans = ob.stockBuySell( A, n)
        p = 0
        for i in range( n - 1):
            p += max( 0, A[i+1] - A[i])
        if len( ans) == 0:
            print( "No Profit", end="")
        else:
            print( check( ans, A, p), end="")
        print()
        t -= 1
################################################################
# log: -That "joke" with Bakalova doesn't work you've been using
# it last couple of years, after you've bought the elections and
# everyone see the results if you want to give lessons try teach
# Putin lesson, it's easy trying looking cool on me I don't have
# nothing. There are at least two reasons for this war or should
# I say operation, cos I don't believe it is 20 year master plan
# the first is the riots that happen in USA recently and the big
# fraud and your incompetence which the disaster in Ukraine only
# proves. The second is the massive stupidity of people, raising
# in cult the male gender not bending not giving up only pushing
# forward stuff vs gender and anti-woman rythorics which created
# an aura to which Putin wanted to fit in. I don't have problems
# not talking, if you think that it will solve all your problems
# here we go.
################################################################
# Test Cases Passed: 232 / 232
# Total Time Taken:  0.9 / 2.2
