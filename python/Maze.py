########################################################
# You have got a maze, which is a n*n Grid. Every cell
# of the maze contains these numbers 1, 2 or 3. If it
# contains 1: means we can go Right from that cell only.
# If it contains 2: means we can go Down from that cell
# only. If it contains 3: means we can go Right and Down
# to both paths from that cell. We cant go out of the maze
# at any time. Initially, You are on the Top Left Corner
# of The maze(Entry). And, You need to go to the Bottom
# Right Corner of the Maze(Exit). You need to find the
# total number of paths from Entry to Exit Point. There
# may be many paths but you need to select that path which
# contains the maximum number of Adventure.
# The Adventure on a path is calculated by taking the sum
# of all the cell values thatlies in the path.
#
# Input: matrix = { {1,1,3,2,1},
#                   {3,2,2,1,2},
#                   {1,3,3,1,3},
#                   {1,2,3,1,2},
#                   {1,1,1,3,1}}
# Output: {4,18}
# Explanation: There are total 4 Paths Available 
# out of which The Max Adventure is 18. Total 
# possible Adventures are 18,17,17,16. Of these 
# 18 is the maximum.
#
# Expected Time Complexity: O(n^2)
# Expected Space Complexity: O(n^2)
#  
########################################################
def wtf( p): return( p%1000000007)
RYTE, DOWN = 1, 2
class Solution:
    def FindWays( self, maze): #########################
        n = len( maze)
        def cons(): return [[0]* n for _ in range( n)]
        # setup adventures and paths fst row and col
        adv = cons(); adv[0][0] = maze[0][0]
        pts = cons(); pts[0][0] = 1
        for j in range( 1, n):
            if maze[0][j-1] == DOWN: break
            adv[0][j] = adv[0][j-1] + maze[0][j]
            pts[0][j] = 1
        for i in range( 1, n):
            if maze[i-1][0] == RYTE: break
            adv[i][0] = adv[i-1][0] + maze[i][0]
            pts[i][0] = 1
########################################################
#         +-------+
#         | i-1,j | adv[i, j] = max(adv[up], adv[left])
# +-------+-------+ pts[i, j] = pts[up] + pts[left], if
# | i,j-1 |  i,j  | allowed
# +-------+-------+
########################################################
        for i in range( 1, n):
            for j in range( 1, n):
                if maze[i-1][j] != RYTE and pts[i-1][j]:
                    adv[i][j] = adv[i-1][j] + maze[i][j]
                    pts[i][j] = pts[i-1][j]
                if maze[i][j-1] != DOWN and pts[i][j-1]:
                    adv[i][j] = max( adv[i][j], adv[i][j-1] + maze[i][j])
                    pts[i][j] += pts[i][j-1]
        if not pts[-1][-1]: return( 0, 0)
        return( wtf( pts[-1][-1]), adv[-1][-1])
########################################################
if __name__ == '__main__':
    T = int( input())
    for i in range( T):
        n = int( input())
        matrix = []
        for _ in range( n):
            cur = list( map( int, input().split()))
            matrix.append( cur)
        obj = Solution()
        ans = obj.FindWays( matrix)
        for _ in ans:
            print( _, end = " ")
        print()
########################################################
# log: Test Cases Passed: 230 / 230
#      Total Time Taken: 0.21 / 1.24
