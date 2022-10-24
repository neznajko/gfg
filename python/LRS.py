                            ########
###############################################################_
# Longest Repeating Subsequence
################################################################
# _ ë __ í _______________ è __________ ø ě ______ ì ______ ǜε _
# Givn strng str, find the lngth of the lngst repeatng subseqnce
# --------------------------------------------------------------
# such that it can be found twice in the given string.
################################################################
# === ω ==== ɪ ======== ǔɘə ===================== ɐ ====== α = ê
# The to identfied subseqncs A and B can use the sme ith chractr
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# from strng str if and only if that ith character has different
#     ∍                   â                               ℰ      
# indics in A and B. For exmple, A = "xax" and B = "xax" thn the
# '''''''''''''''''''''''''''' Ⅎ '''''''''''''''''''''''''''''''
# index of first "x" must be diferent in the original string for
# ==============================================================
# A and B.
##############[#################################################
# Example     : 1
# Input       : str = "axxzxy"
# Output      : 2
# Explanation : The given array with indexes looks like
#             : a x x z x y 
#             : 0 1 2 3 4 5
#             :
#             : The longest subsequence is "xx". 
#             : It appears twice as explained below.
#             :
#             : subsequence A
#             : x x
#             : 0 1  <-- index of subsequence A
#             : ------
#             : 1 2  <-- index of str 
#             :
#             : subsequence B
#             : x x
#             : 0 1  <-- index of subsequence B
#             : ------
#             : 2 4  <-- index of str 
#             :
#             : We are able to use character 'x' 
#             : (at index 2 in str) in both subsequences
#             : as it appears on index 1 in subsequence A 
#             : and index 0 in subsequence B.
##############v#################################################
# Expected Time Complexity:  O(n^2)
# Expected Space Complexity: O(n^2)
################################################################
################################################################
################################################################
################################################################
# Test Cases Passed: 150 / 150 The prev LCS problem was the hint
# Total Points Scored: 4 / 4   -------------------℥---ℒ---------
# Your Total Score: 918        to this one. They baicaly use the
# Total Time Taken: 3.42       `````````````````````````````````
# Your Accuracy: 100%          same formula with one exception.
# Attempts No.: 1              =================================
################################################################
# D{i,j} = max([ s[i] == t[j] && i != j ] + D{i+1,j+1},
#                                           D{i+1,j+0},
#                                           D{i+0,j+1})
###############################################################_
################################################################
# s: bbooobb
# t: bbooobb
#   t 0 1 2 3 4 5 6 7
# s   b b o o o b b ?
# 0 b 4 3 3 3 2 2 1 0
# 1 b 4 3 3 3 2 2 1 0
# 2 o 3 3 3 3 2 1 1 0
# 3 o 3 3 3 2 2 1 1 0
# 4 o 2 2 2 2 1 1 1 0
# 5 b 2 2 1 1 1 1 1 0
# 6 b 1 1 1 1 1 1 0 0
# 7 ? 0 0 0 0 0 0 0 0
###############################################################=
###############################################################=
###############################################################-
###############################################################_
class Solution:
    def LongestRepeatingSubsequence( self, s ):
        m = n = len(s)
        t = s
        D = [[0]*(n + 1) for i in range(m + 1)]
        for i in reversed( range( m )):
            for j in reversed( range( n )):
                D[i][j] = max(
                    (s[i] == t[j] and i != j) + D[i+1][j+1],
                                                D[i+1][j+0],
                                                D[i+0][j+1])
        return D[0][0]
###############################################################=
# log:
################################################################
print( Solution().LongestRepeatingSubsequence(
    "bbooobb"
))
###############################################################_
    ####                                                ###=
