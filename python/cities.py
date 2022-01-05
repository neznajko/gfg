#!                                          /usr/bin/env python3
################################################################
# Shortest Path between Cities 
# Medium Accuracy: 68.11% Submissions: 1964 Points: 4
# Geek lives in a special city where houses are arranged in a
# hierarchial manner. Starting from house number 1, each house
# leads to two more houses.  
# 1 leads to 2 and 3. 
# 2 leads to 4 and 5. 
# 3 leads to 6 and 7. and so on. 
# Given the house numbers on two houses x and y, find the length
# of the shortest path between them.
################################################################
# Your Task:
# You don't need to read input or print anything. Complete the
# function shortestPath() which takes integers x and y as input
# parameters and returns the length of the shortest path from x
# to y.
################################################################
# Expected Time Complexity: O( log( max( x, y)))
# Expected Auxiliary Space: O( 1)
################################################################
class Solution:
    def shortestPath( self, x, y):
# Ok we have a heap structure like thus:
#            1          ----- 0
#       2         3     ----- 1
#    4     5   6     7  ----- 2
#   8 9   a b c d   e f ----- 3
# How to find their common root?
# One way is to shift by 1, the largest of them until they
# became equal. Wet's give it a try,
        dist = 0 # check this out ---------------------------[]
        while x != y:   # Debug by hand:
            if x < y:   # x = 4, y = b, dist = 0
                y >>= 1 #     4,     5,        1
            else:       #     4,     2,        2
                x >>= 1 #     2,     2,        3
            dist += 1   # Looks like vjorking!
        return dist     #
################################################################
if __name__ == '__main__': 
	t = int( input())
	for _ in range( t):
		x, y = map( int,input().strip().split())
		ob = Solution()
		print( ob.shortestPath( x, y))
################################################################
# log: - Às usual: 0.0 / 1.0
################################################################
