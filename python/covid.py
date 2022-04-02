########################################################
# Covid Spread
# Medium Accuracy: 61.95% Submissions: 9472 Points: 4
#
# Aterp is the head nurse at a city hospital. City
# hospital contains R*C number of wards and the
# structure of a hospital is in the form of a 2-D
# matrix. Given a matrix of dimension R*C where each
# cell in the matrix can have values 0, 1, or 2 which
# has the following meaning:
# 0: Empty ward
# 1: Cells have uninfected patients
# 2: Cells have infected patients
# 
# An infected patient at ward [i,j] can infect other
# uninfected patient at indexes [i-1,j], [i+1,j],
# [i,j-1], [i,j+1] (up, down, left and right) in unit
# time. Help Aterp determine the minimum units of time
# after which there won't remain any uninfected patient
# i.e all patients would be infected. If all patients
# are not infected after infinite units of time then
# simply return -1.
########################################################
import pdb
def input( f=open( "NPUT")): return f.readline().rstrip()
########################################################
from collections import deque
class Solution:
    
    def helpaterp( self, hospital):
        self.h = hospital
        self.n = len( hospital)
        self.m = len( hospital[ 0])
        self.deq = deque() # bfs covid infected queue
        R = range( self.n)
        Q = range( self.m)
        for i in R:
            for j in Q:
                if self.h[ i][ j] == 2:
                    self.deq.append(( i, j))
        t = self.bfs() # get the timing
        for i in R: # ck if all infected
            for j in Q:
                if self.h[ i][ j] == 1: return -1 # nop
        return t

    def ck( self, u, v): # bfs helper function
        if self.h[ u][ v] == 1:
            self.h[ u][ v] = 2
            self.deq.append(( u, v))
    
    def bfs( self):
        t = -1 # timing
        n = self.n
        m = self.m
        while True:
            size = len( self.deq)
            if size == 0: break
            t += 1
            for _ in range( size):
                i, j = self.deq.popleft()
                if i > 0:     self.ck( i - 1, j) # Up
                if j < m - 1: self.ck( i, j + 1) # Ryte
                if i < n - 1: self.ck( i + 1, j) # Down
                if j > 0:     self.ck( i, j - 1) # West
        return t

########################################################
# Test Cases Passed: 82 / 82
# Total Time Taken:  0.3/6.5
########################################################
if __name__ == '__main__':
    t = int( input())
    for tcs in range( t):
        rc = input().split() # row and column
        r = int( rc[0])    
        c = int( rc[1])
        
        hospital = []
        
        for i in range( r):
            hospital.append([ int( j) for j in input().split()])
            
        ob = Solution()
        
        print( ob.helpaterp( hospital))
########################################################
