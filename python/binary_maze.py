########---------------------------------###############
########---------------------------------###############
########---------------------------------###############
########---------------------------------###############
#       ================----------------2`.`,`,`.`.`.`.`
#       ================---   -----------`.`.`.`.`.`.`.`
#       ===   f====   ==---   -----' .---',',`,','.',",'
#       ====-  =====y  =---   ----` d----','.',`.`.`.`.`
#       ======  ====== `---   ---`.------`.`.`.`.`.`.`.`
#       ================---   -----------`.`,`,`.`.`.`.`
#       ==========                     --`.`.`.`.`.`.`.`
#       ================-`     '---------`.`.`.`.`.`.`.`
#       Y      YYYYYYYY" ,Щ   Щ, 'ЩЩЩЩЩЩz`.`,`,`.`.`.`.`
#       YYYY   YYYYYY" ,ЩЩЩ   ЩЩЩ. `ЩЩЩЩY`.`,`,`.`.`.`.`
#       YYYY   YYYY` .YYЩЩЩ   ЩЩЩЩЩ_ "ЩЩZ`.`.`.`.`.`.`.`
#       YYYY   YY` _YYYYЩЩЩ   ЩЩЩЩЩЩЩ, 'W`.`.`.`.`.`.`.`
#       YYYY   YYYYYYYYYЩЩЩ   ЩЩЩЩЩЩЩЩЩЩW`.`.`.`.`.`.`.`
#       YYY  _  "YYYYYYYЩЩЩЩЩЩЩЩЩЩЩЩЩЩЩЩY`.`.`.`.`.`.`.`
#       Y` ,AYY=__                     ЩЩ`.`.`.`.`.`.`.`
#       YYYYYYYYYYYYYYYYЩЩЩЩЩЩЩЩЩЩЩЩЩЩЩЩZ`.`,`,`.`.`.`.`
########YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY###############
########YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY###############
########YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY###############
########YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY###############
########YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY###############
########YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY###############
########YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY###############
        ####                             めい
        ####                             メイ
########################################################
########################################################
########################################################
########################################################
# Shortest Distance in a Binary Maze                      ..
###########################################################
# Given a n*m matrix grid where each element can either ###
# be 0 or 1. You need to find the shortest distance between
# a given source cell to a destination cell. The path can #
# only be created out of a cell if its value is 1. ########
# If the path is not possible between source cell and #####
# destination cell, then return -1. Note: You can move  ###
# into an adjacent cell if that adjacent cell is filled ###
# with element 1. Two cells are adjacent if they share a ##
# side. In other words, you can move in one of the four ###
# directions, Up, Down, Left and Right. The source and ####
# destination cell are based on the zero based indexing. ##
###########################################################
# Input: grid[][] = {{1, 1, 1, 1}, src = {0, 1} ########
#                    {1, 1, 0, 1}, dst = {2, 2} ########
#                    {1, 1, 1, 1}, #####################
#                    {1, 1, 0, 0}, #####################
#                    {1, 0, 0, 1}} #####################
# Output: 3 ############################################
# Explanation: 0,1->1,1->2,1->2,2 ######################
########################################################
# Expected Time Complexity: O(n*m) #####################
# Expected Space Complexity: O(n*m) ####################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
#######################################################_
class Fin( Exception ):
    def __init__( self, levl ):
        self.levl = levl
########################################################
########################################################
########################################################
#######################################################=
class Solution:
    def shortestPath( self, grid, src, dst ):
        for r in grid:
            r.insert( 0, 0 )
            r.append( 0 )
        gard = [0] * len( grid[ 0 ])
        grid.insert( 0, gard )
        grid.append( gard )
        src = ( src[0] + 1, src[1] + 1 )
        dst = ( dst[0] + 1, dst[1] + 1 )
        try:
            bfs( grid, src, dst )
        except Fin as f:
            return f.levl
        return -1
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
from collections import deque
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
def bfs( grid, src, dst ):
    n = len( grid )
    m = len( grid[0] )
    deq = deque([ src ])
    i, j = src
    grid[i][j] = 0
    while deq:
        i, j = deq.popleft()
        if ( i, j ) == dst: raise Fin( -grid[i][j] )
        i_ = i - 1 # 北
        if grid[i_][j] > 0:
            deq.append(( i_, j ))
            grid[i_][j] = grid[i][j] - 1
        j_ = j + 1 # 東
        if grid[i][j_] > 0: 
            deq.append(( i, j_ ))
            grid[i][j_] = grid[i][j] - 1
        i_ = i + 1 # 南 
        if grid[i_][j] > 0: 
            deq.append(( i_, j ))
            grid[i_][j] = grid[i][j] - 1
        j_ = j - 1 # 西
        if grid[i][j_] > 0: 
            deq.append(( i, j_ ))
            grid[i][j_] = grid[i][j] - 1
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
if __name__=="__main__":################################
    for _ in range(int(input())):#######################
        n,m=map(int,input().strip().split())############
        grid=[]#########################################
        for i in range(n):##############################
            grid.append([int(i) for i in input().strip().split()])
        src=[0]*2#################################################
        src[0],src[1]=map(int,input().strip().split())############
        dst=[0]*2#################################################
        dst[0],dst[1]=map(int,input().strip().split())############
        obj=Solution()############################################
        print(obj.shortestPath(grid, src, dst))###################
########################################################
########################################################
########################################################
########################################################
# Test Cases Passed:                           124 / 124
# Total Points Scored:                             4 / 4
# Your Total Score:                                 1254
# Total Time Taken:                                 0.34