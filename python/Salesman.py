                          ####
########################################################
# Travelling Salesman Problem 
# Hard Accuracy: 50.56% Submissions: 2310 Points: 8
# Given a matrix cost of size n where cost[i][j] denotes
# the cost of moving from city i to city j. Your task is
# to cmplete a tour from the city 0 (0 basd indx) to all
# other cities such that you visit each city atmost once
# and then at the end come back to city 0 in min cost.
# Example 1:
# Input: cost = {{0,111},
#                {112,0}}
# Output: 223
# Explanation: We can visit 0->1->0 and 
# cost = 111 + 112.
# Example 2: 
# Input: cost = {{0,1000,5000},
#                {5000,0,1000},
#                {1000,5000,0}}
# Output: 3000
# Explanation: We can visit 0->1->2->0 and cost 
# = 1000 + 1000 + 1000 = 3000
########################################################
# Your Task:
# You don't need to read or print anyhting. Your task is
# to complete the function total_cost() which takes cost 
# as input parameter and returns the total cost to visit 
# each city exactly once starting from city 0, and again 
# comback to city 0.
#
# Expected Time Complexity: O(2^n*n^2)
# Expected Space Compelxity: O(2^n*n)
# 
# Constraints:
# 1 <= n <= 10
# 1 <= cost[i][j] <= 10^3
########################################################
from math import inf
########################################################
class Solution:
    def total_cost( self, cost):
        return Salesman( cost)
#######################################################=
def Salesman( w): #
    n = len( w) - 1 # discard 0
    if n < 1: return 0 # guarantee some travel
    Sm = 1 << n # maximum set
    C = [[ 0]*n for j in range( Sm)] # cost           
    for S in range( 1, Sm): # O(2^n)                  
        for off in range( n): # O(n)                  
            mask = 1 << off # town mask               
            bit = S & mask # chck if town is in set   
            if not bit: continue # nop                
            S1 = S &( ~mask) # poke off
            if not S1: #
                C[ S][ off] = w[ 0][ off + 1] #
                break #
            # loop over S1 bits                       
            m = inf # minimum cost
            for u in range( n): # O(n)
                if not S1 &( 1 << u): continue #
                d = C[ S1][ u] + w[ u + 1][ off + 1] # 
                if d < m: m = d #
            C[ S][ off] = m #
    #
    m = inf #
    for j, v in enumerate( C[ Sm - 1]): #
        d = v + w[ j + 1][ 0] #
        if d < m: m = d #
    return m #                                         
#######################################################_
if __name__ == '__main__':
	T = int( input())
	for i in range( T):
		n = int( input())
		cost = []
		for _ in range( n):
			cost.append( list( map( int, input().split())))
		obj = Solution()
		ans = obj.total_cost( cost)
		print( ans)
########################### https://youtu.be/1B7Sf0DzSwY
# log: Test Cases Passed: 90/90
#      Total Time Taken:  0.1/27.1
########################################################
####                                                ####
