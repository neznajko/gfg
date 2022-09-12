################################################################
# Word Boggle
################################################################
# Givn a dictionary of distnct words and an M x N brd where evry
# cell has one chractr. Find all posble words from the dictionry
# that can be formed by a sequence of adjacent characters on the
# board. We can move to any of 8 adjacent characters.
################################################################
# Note: A cell can be used only once in one word.
################################################################
# Input:                                              Example 1:
# N = 1
# dictionary = {"CAT"}
# R = 3, C = 3
# board = {{C,A,P},{A,N,D},{T,I,E}}
# Output:
# CAT
# Explanation: 
# C* A P
# A* N D
# T* I E
################################################################
# Expected Time Complexity: O(N*W + R*C^2) <- wtf?
# Expected Auxiliary Space: O(N*W + R*C)
################################################################
# Constraints:
# 1 ≤ N ≤ 15
# 1 ≤ R, C ≤ 50
# 1 ≤ length of Word ≤ 60
################################################################
# Each word can consist of both lowercase and uppercase letters.
################################################################
from itertools import product
##_#############################################################
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# 
# 
# 
# 
# 
# 
################################################################
COMPASS = ((-1,-1), (-1,0), (-1,1),
           ( 0,-1),         ( 0,1),
           ( 1,-1), ( 1,0), ( 1,1))
################################################################
class Board:
    def __init__( self, board ):
        self.chars = board
        self.shape = tuple( map( len, ( board, board[0] )))
        self.coors = tuple( product( *map( range, self.shape )))

################################################################
class DontGoogle( Exception ): pass
################################################################
def fill( value, rows, cols ):
    return [[ value ]*cols for r in range( rows )]
################################################################
class Boggle:    
    def __init__( self, word, board ):
        self.word = word
        self.board = board
        self.levl = 0
        self.vzit = fill( False, *board.shape )

    def check_char( self, i, j ):
        return self.board.chars[i][j] == self.word[ self.levl ]

    def search( self ):
        for i, j in self.board.coors:
            if self.check_char( i, j ):
                try:
                    self.dfs( i, j )
                except DontGoogle:
                    return True
        return False

    def add( self, r, dr ): # (x,y) + (dx,dy)
        r = list( r )
        for j in 0, 1:
            r[j] += dr[j]
            if r[j] < 0 or r[j] >= self.board.shape[j]:
                return -1, None
        return tuple( r )

    def ok( self, i, j ):
        return not ( i == -1 or
                     not self.check_char( i, j ) or
                     self.vzit[i][j] )

    def enter( self, i, j ):
        self.levl += 1
        if self.levl == len( self.word ):
            raise DontGoogle
        self.vzit[i][j] = True

    def exit( self, i, j ):
        self.levl -= 1
        self.vzit[i][j] = False

    def dfs( self, i, j ):
        self.enter( i, j )
        r = i, j
        for dr in COMPASS:
            u, v = self.add( r, dr )
            if self.ok( u, v ):
                self.dfs( u, v )
        self.exit( i, j )
        
################################################################
# Test Cases Passed: 462 / 462
# Total Points Scored: 4 / 4
# Your Total Score: 806
# Total Time Taken: 2.75
# Your Accuracy: 25%
# Attempts No.: 4
################################################################
# This is a problem from Google and it's a nice one.
################################################################
class Solution:
    def wordBoggle( self, board, dictionary ):
        board = Board( board )
        # output list
        ls = []
        for word in dictionary:
            if Boggle( word, board ).search():
                ls.append( word )
        return ls
    
################################################################
# t
# N
# word1 word2 .. wordN
# R C
# 11 12 .. 1C
# 21 22 .. 2C
# .. .. .. ..
# R1 R2 .. RC
if __name__ == "__main__":
    t = int( input())
    for _ in range( t ):
        N = int( input())
        dictionary = [x for x in input().strip().split()]
        line = input().strip().split()
        R = int( line[0])
        C = int( line[1])
        board = []
        for _ in range( R):
            board.append( [x for x in input().strip().split()] )
        obj = Solution()
        found = obj.wordBoggle( board, dictionary)
        if len( found ) == 0:
            print( -1)
            continue
        found.sort()
        for i in found:
            print( i, end=' ')
        print()
################################################################
# log:
