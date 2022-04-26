####################################################################
# Word Ladder                                                  I####
# Hard Accuracy: 43.32% Submissions: 8595 Points:              8####
####################################################################
# Given two distinct words startWord and targetWord, and a  list####
# denoting wordList of unique words of equal lengths. Find   the####
# length of the shortest transformation sequence from  startWord####
# to targetWord. Keep the following conditions in mind         :####
####################################################################
# A word can only consist of lowercase characters. Only      one####
# letter can be changed in each transformation.             Each#### 
# transformed word must exist in the wordList including      the####
# targetWord. startWord may or may not be part of the wordList .####
# The second part of this problem can be found here            .####
####################################################################
# Example 1                                                    :####
# Input                                                        :####
# wordList = {"des","der","dfr","dgt","dfs"                    }####
# startWord = "der", targetWord= "dfs"                         ,####
# Output:                                                      3####
# Explanation                                                  :####
# The length of the smallest                      transformation#### e
# sequence from "der" to "dfs" is                              3#### v 
# i,e "der" -> "dfr" -> "dfs"                                  .#### i
#################################################################### l
# Your  T      a                         s                   k :||||
# You don't need to read or print anything, Your task i  s   t o|||| c o 
# complete the function wordLadderLength() which t  a    k    es|||| d e
# startWord, targetWord and wordList as input parame t e   r and||||
# returns the length of the shortest transformation seque n c  e|||| h
# from startWord to targetWord. If not possible return    0    .|||| e
#################################################################### r
# Expected Time Compelxity: O(     N       ^          2     * M)<<<< e
# Expected Auxiliary Space: O(N * M) where N = len g  t   h  o f<<<<
# wordList and M = |wordLi    s         t[     i            ]  |<<<<
####################################################################
# Constraints:
# 1 ≤ N ≤ 100
# 1 ≤ M ≤ 10                                         and    CHILL ..
####################################################################
def diff( s, t ):
    ''' With this comment I intend to shed a light into darkness '''
    if len( s ) != len( t ): return False
    c = 0
    for j in range( len( s )):
        if s[ j ] != t[ j ]:
            c += 1
            if c > 1: break
    return c
####################################################################
# Test Cases Passed: 509 / 509
# Total Time Taken: 0.09 / 1.86
####################################################################
class Solution:
    def wordLadderLength( self, staat, taagt, words ):
        deq = deque([ staat ])
        vzd = [ False ]*len( words )
        levl = 0
        while deq:
            levl += 1
            n = len( deq )
            for o_o in range( n ):
                s = deq.popleft()
                if s == taagt: return levl
                for j, t in enumerate( words ):
                    if vzd[ j ]: continue
                    if diff( s, t ) == 1:
                        deq.append( t )
                        vzd[ j ] = True
        return 0
################################################################
################################################################
from collections import deque ##################################
if __name__ == '__main__': ##################################### D
    T = int( input() ) ######################################### R
    for tt in range( T ): ###################################### I
        n = int( input() ) ##################################### V
        wordList = [] ########################################## E
        for i in range( n ): ################################### R
            wordList.append( input().strip() ) #################
        startWord = input().strip() ############################
        targetWord = input().strip() ########################### C O D E
        obj = Solution() ###############################################
        ans = obj.wordLadderLength( startWord, targetWord, wordList) ###
        print( ans ) ###################################################
################################################################
