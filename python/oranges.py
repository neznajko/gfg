################################################################
# Rotten Oranges
################################################################
# Given a grid of dimension nxm where each cell in the grid can 
# have values 0, 1 or 2 which has the following meaning:
# 0: Empty cell
# 1: Cells have fresh oranges
# 2: Cells have rotten oranges
################################################################
# We have to determine what is the earliest time after which all
# the oranges are rotten. A rotten orange at index [i,j] can rot
# other fresh orange at indexes [i-1,j],[i+1,j],[i,j-1],[i,j+1]
#(up, down, left and right) in unit time.
################################################################
# Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
# Output: 1
# Explanation: The grid is 0 1 2
#                          0 1 2
#                          2 1 1, oranges at positions (0,2),
# (1,2), (2,0) will rot oranges at (0,1), (1,1), (2,2) and (2,1)
# in unit time.
################################################################
# Input: grid = {{2,2,0,1}}
# Output: -1
# Explanation: The grid is 2 2 0 1
# Oranges at (0,0) and (0,1) can't rot orange at (0,3).
################################################################
# Expected Time Complexity: O(n*m)
# Expected Auxiliary Space: O(n*m)
################################################################
# 1 ≤ n, m ≤ 500
################################################################
################################################################
################################################################
################################################################
from collections import deque
################################################################
################################################################
class Solution:
    def orangesRotting( self, grid ):
        print( *grid, sep='\n' )
        # 
        n = len( grid )
        m = len( grid[ 0 ])
        I = range( n )
        J = range( m )
        deq = deque()
        t = -1
        fresh = 0
        # 
        for i in I:
            for j in J:
                orange = grid[ i ][ j ]
                if orange == 2:
                    deq.append(( i, j ))
                elif orange == 1:
                    fresh += 1
        #
        #
        if fresh == 0: return 0
        def stuff():
            nonlocal fresh
            if grid[ i_][ j_] == 1:
                grid[ i_][ j_] = 2
                fresh -= 1
                deq.append(( i_, j_ ))
        while deq:
            t += 1
            s = len( deq )
            for _ in range( s ):
                i, j = deq.popleft()
                # up
                i_, j_ = i - 1, j
                if i_ >= 0: stuff()
                # right
                i_, j_ = i, j + 1
                if j_ < m: stuff()
                # down
                i_, j_ = i + 1, j
                if i_ < n: stuff()
                # left
                i_, j_ = i, j - 1
                if j_ >= 0: stuff()
        if fresh == 0: return t
        return -1
    #
    #
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
T=int(input()) #################################################
for i in range(T): #############################################
	n,m=map(int,input().split()) ###########################
	grid=[] ################################################
	for _ in range(n): #####################################
		a=list(map(int,input().split())) ###############
		grid.append(a) #################################
	obj=Solution() #########################################
	ans=obj.orangesRotting(grid) ###########################
	print(ans) #############################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
# Test Cases Passed:                                     46 / 46
# Total Points Scored:                                     4 / 4
# Your Total Score:                                         1694
# Total Time Taken:                                         1.72