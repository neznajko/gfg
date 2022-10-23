                            ########
###############################################################_
# Longest Common Subsequence
#####ë############è######################ó##é########ë##########
# Givn two sequencs, find the length of lngst subsequnce present
# in both of them. Both the strings are of uppercase.
################################################################
# Example     : 1
# Input       : A = 6
#             : B = 6
#             : str1 = ABCDGH
#             : str2 = AEDFHR
# Output      : 3
# Explanation : LCS for input Sequences “ABCDGH” and “AEDFHR” is
#             : “ADH” of length 3.
################################################################
# Expected Time Complexity: O(|str1|*|str2|)
# Expected Auxiliary Space: O(|str1|*|str2|)
################################################################
# Constraints: 1 <= size(str1), size(str2) <= 10^3
################################################################
# D[i,j] = max({ s[i] == t[j] } + D[i+1,j+1],               (A1)
#                                 D[i+1,j+0],
#                                 D[i+0,j+1])
################################################################
# s = ABDGH
# t = AEDFHR
#     0 1 2 3 4 5 6    ? is Guard, ve start backward and fill
#     A E D F H R ?    the D matrix.
# 0 A 3 2 2 1 1 0 0
# 1 B 2 2 2 1 1 0 0
# 2 D 2 2 2 1 1 0 0
# 3 G 1 1 1 1 1 0 0
# 4 H 1 1 1 1 1 0 0
# 5 ? 0 0 0 0 0 0 0
################################################################
# Test Cases Passed: 105 / 105 Formula (A1) can be written moreë
# Total Points Scored: 4 / 4   math like as Dⁱʲ and so forth but
# Your Total Score: 914        here it can be replacçed directly
# Total Time Taken: 0.12       with a matrix, vhich has m+1, n+1
# Your Accuracy: 100%          dimensions, initially filled vith
# Attempts No.: 1              zeroöóòøóöòôõōŏɵòøòóöòôõɵòøōŏøes.
################################################################
class Solution:
    def lcs( self, m, n, s, t ):
        # Create a (m+1)x(n+1) dp matrix full of nulls
        D = [[0]*(n + 1) for i in range(m + 1)]
        # boom the solution
        for i in reversed( range( m )):
            for j in reversed( range( n )):
                D[i][j] = max(( s[i] == t[j] ) + D[i+1][j+1],
                                                 D[i+1][j+0],
                                                 D[i+0][j+1])
        return D[0][0]
################################################################
# log:
################################################################
print( Solution().lcs(
    4, 3, "ABCD", "BCD"
))
###############################################################_
    ####                                                ###=
