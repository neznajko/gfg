################################################################
# Find whether path exist
################################################################
# Given a grid of size nxn filled with 0, 1, 2, 3. Check whether
# there is a path posble from the source to destination. You can
# traverse up, down, right and left.
#
# The description of cells is as follows:
# 
# A value of cell 1 means Source.
# A value of cell 2 means Destination.
# A value of cell 3 means Blank cell.
# A value of cell 0 means Wall.
#
# Note: There are only a single source and a single destination.
################################################################
# Example 1: Input: grid = {{3,0,3,0,0},{3,0,0,0,3},{3,3,3,3,3},
# {0,2,3,0,0},{3,0,0,1,3}} Output: 0 Explanation: The grid is:
# 3 0 3 0 0 
# 3 0 0 0 3 
# 3 3 3 3 3 
# 0 2 3 0 0 
# 3 0 0 1 3 
# There is no path to reach at (3,1) i,e at 
# destination from (4,3) i,e source.
################################################################
# Example 2: Input: grid = {{1,3},{3,2}} Output: 1 Explanation:
# The grid is
# 1 3
# 3 2
# There is a path from (0,0) ie source to (1,1) ie destination.
################################################################
# Expected Time Complexity: O(n^2)
# Expected Auxiliary Space: O(n^2)
################################################################
# Constraints:
# 1 ≤ n ≤ 500
################################################################
import numpy as np
from collections import deque
################################################################
# Ok we have to reach from 1( sors ) to 2( dest ) via 3( wall )?
# By the way Im workng with msys2 on windows10, and had very big
# "fun" trying installing numpy. pip install numpy isn't working
# at all, so if you want to try it, there is a dedicated package
# numpy which can be installed via pacman.
UP   = np.array([ -1,  0 ])
RYTE = np.array([  0, +1 ])
DOWN = -UP
LEFT = -RYTE
COMPASS = UP, RYTE, DOWN, LEFT
class Solution:
    ''''''
    def find_sors( self ):
        for point, value in np.ndenumerate( self.grid ):
            if value == 1: return np.array( point )

    def in_bounds( self, p ):
        return( all( self.lower_limit < p ) and
                all( self.upper_limit > p ))

    def is_Possible( self, grid ):
        n = len( grid )
        self.grid = np.array( grid )
        self.lower_limit = np.array([ -1, -1 ])
        self.upper_limit = np.array([  n,  n ])
        deq = deque([ self.find_sors() ])
        #
        while len( deq ):
            r = deq.popleft()
            for dr in COMPASS:
                p = r + dr
                if not self.in_bounds( p ): continue
                i, j = p
                if self.grid[i][j] == 2: return True
                if self.grid[i][j] == 3:
                    deq.append( p )
        return False
################################################################
# Test Cases Passed: 10 / 10
# Total Points Scored: 4 / 4
# Your Total Score: 798
# Total Time Taken: 0.11
# Your Accuracy: 100%
# Attempts No.: 1            
################################################################_
if __name__ == '__main__':
    T = int( input())
    for i in range( T ):
        n = int( input())
        grid = []
        for _ in range( n ):
            a = list( map( int, input().split()))
            grid.append( a )
        obj = Solution()
        ans = obj.is_Possible( grid )
        if( ans ):
            print( "1" )
        else:
            print( "0" )
###############################################################=
# log: -You can't fight Deep State by telling SHALLOW! jokes:)
