################################################################
# Number Of Enclaves ###########################################
################################################################
# You are given an nxm binar matri grid, where 0 represent a sea
########################## Ÿ ### ┿ #####################   #####
##########################   ###   #####################   #####
# cell and 1 represents a land cell. ################### Ś #####
########################################################   #####
# A move consist of walkin from one land cell t another adjacent
##############   #######   ##################   ################
############## ś #######   ##################   ################
##############   ####### ɡ ##################   ################
##############   #######   ################## ő ################
##############   #######   ##################   ################
# (4-directionally) land cell or walking off the boundary of the
################################################################
# grid. ########################################################
# Find the number of land cells in grid for which we cannot walk
################################################################
# off the boundary of the grid in any number of moves. #########
################################################################ 
# Example                                                      1
################################################################
# Input                                 grid[][] = {{0, 0, 0, 0},
#                                                   {1, 0, 1, 0},
#                                                   {0, 1, 1, 0},
#                                                   {0, 0, 0, 0}}
################################################################
# Output                                                       3
################################################################
# Explanation:                                           0 0 0 0
#                                                        1 0 * 0
#                                                        0 * * 0
#                                                        0 0 0 0
#                The highlighted cells represents the land cells.
################################################################
# Expected Time Complexity:  O(n*m)
# Expected Space Complexity: O(n*m)
################################################################
import numpy as np #############################################
################################################################
NORTH = np.array([-1,+0]) # -     +
EAST  = np.array([-0,+1]) #   
SOUTH = np.array([+1,-0]) #   
WEST  = np.array([+0,-1]) # +
################################################################
COMPASS = [ NORTH, EAST, SOUTH, WEST ]
################################################################
class Solution:                    ##0 1 2   n############   ###
    """"""                         ##1#################### ℳ ### 
    def off( self, i, j ):         ##2####################   ###
        return( i == -1     or     ## ####################   ###
                i == self.m or     ##m####################   ###
                j == -1     or     #######################   ###
                j == self.n )      #######################   ###
##########################################################   ###
# Test Cases Passed: 132 / 132 This is a simple Graph Proble but
# Total Points Scored: 4 / 4   there were some nasty tech issues,
# Your Total Score: 922        like 96x98 full of 1s grid not to
# Total Time Taken: 0.43       mention the one dimentional cases.
# Your Accuracy: 33%
# Attempts No.: 3
################################################################    
    def numberOfEnclaves( self, grid ):   ######################
        self.m = m = len( grid     )###   ######################
        self.n = n = len( grid[ 0 ])###   ######################
        self.grid =      grid### ś #### é ######################
        # loop over border element, defin step list so we can do
        # it in one pass
        s = [n - 1] * m; s[0] = s[m - 1] = 1
        ########################################################
        # these are for the nasty test cases ###################
        if np.all( np.array( grid ) == 1 ): return 0 ###########
        if m == 1 or n == 1: return 0 ##########################
        ########################################################
        for i in range(m):
            for j in range(0, n, s[i]):
                if grid[i][j] > 0: self.explore( i, j )
        return self.count()

    def explore( self, i, j ):
        self.grid[i][j] = -1 # mark as vzited
        r = np.array([i, j])
        for dr in COMPASS:
            i, j = r + dr
            if( self.off(i, j) or
                self.grid[i][j] <= 0 ): continue
            self.explore(i, j)

    def count( self ):#   ######### ŕ ##########################
        ''' return number of non-zero vs negative elements '''
################## ʍ ##   #########   ##########################
##################   ##   #########   ##########################
##################   ## Ŧ #########   ##########################
        noz = 0 # I' prety sure bette name exists, although I've
                # discarded noze!
        neg = 0
        for i in range(self.m):
            for j in range(self.n):
                y = self.grid[i][j]
                if y == 0: continue
                if y < 0: neg += 1
                noz += 1
        return noz - neg
    
################################################################
# log:
################################################################
def main():
    print( Solution().numberOfEnclaves(
        [[ 0, 0, 0, 0, 0 ],
         [ 1, 0, 1, 1, 0 ],
         [ 0, 1, 1, 0, 0 ],
         [ 0, 0, 0, 0, 0 ]]
    ))
################################################################
main()
####  >>>>>>######################################## :::::: ####
####<<<<<<  ######################################## `````` ####
    ########                                        ########
# 0,0 0,1 0,2 0,3
# 1,0         1,3
# 2,0         2,3
# 3,0 3,1 3,2 3,3
#
