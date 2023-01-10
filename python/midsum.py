################################################################
#                      s
#                     t
#             e      n               d      s
#            l      e               e      y
#           d      m               t      a
#   m      d      e           o   r      r   
#  u   f  i      l        f  w   o      r
# S   o  M      E        o  t   s      a     
################################################################
#                                                      s
#                                                     t
#          d s                     s               e n     d .
#     n   e y             . e   n y               l e     e y
#    e   t a         e   h g   e a   d           d m     g a
#   v   r r 1 d 2   z   c r e v r d n e m   e o d e   e r r
#  i   o r r n r f i   a e h i r n i h u f h w i l f h e r
# G 2 s a A a A o s N e M t g a a f t s o t t m e o t m a
################################################################
# Example:                                                     1
# Input:                                                   N = 5
#                                       Ar1[] = {1, 2, 4, 6, 10}
#                                       Ar2[] = {4, 5, 6, 9, 12}
# Output:                                                     11
# Explanation:                       The merged array looks like
#  {1,2,4,4,5,6,6,9,10,12}. Sum of middle elements is 11 (5 + 6).
################################################################
# Expected Time Complexity: O(log N)
# Expected Auxiliary Space: O(1)
################################################################
# This is a search problem, and the running time is like a binary
# search vhich is a divide and conquer algorithm, but here is more
# challenging to figure how to narrow the searching area so to speak.
# Lets mark one array with lower letters and the other with upper
# letters, like so:
# a b c d e f g h, we take the mid element of both the arrays and 
# A B C D E F G H  compare them d < D? If this is true than we
# 0 1 2 3 4 5 6 7  discard a, b, c, and the equal number of elements
#                  F G H, because it's not super difficult to see
#                  that they can't be mid elements of the merged
#                  array. So we got thus:
# 0 1 2 3 4 5 6 7  Here again we repeat the same stuff, now let's
#       d e f g h  say C < f, than ve got thus:
# A B C D E
#
# 0 1 2 3 4 5 6 7, and than let's say after D < e we'll have:
#       d e f
#     C D E
#
# 0 1 2 3 4 5 6 7, I could'n figure how to reduce thus more, so this
#       d e        is the base case, here we just take the sum of
#       D E        the maximum of the fisrt elements and the minimum
#                  of the second elements, and that's it.
# Basically I don't think this is a very medium problem, it's true
# that this might be subjective, but for me it's a difficult problem.
################################################################
class Solution:
    def findMidSum( self, lower, upper, öò ):
        i, j = u, v = 0, len( lower ) - 1
        while j - i > 1:
            k = ( i + j )>> 1
            w = ( u + v )>> 1
            if lower[ k ] < upper[ w ]:
                n = k - i
                i = k  
                v -= n
            else:
                n = w - u
                u = w 
                j -= n
        return( max( lower[ i ], upper[ u ]) +
                min( lower[ j ], upper[ v ]))
################################################################
_1 = [ 5, 10, 12, 16, 17, 18, 22, 24, 27, 29, 29, 29 ]
_2 = [ 5,  7,  9, 10, 10, 13, 16, 18, 20, 22, 26, 29 ]
################################################################
print( Solution().findMidSum( _1, _2 , None ))
################################################################
# Test Cases Passed:                                   315 / 315
# Total Points Scored:                                     4 / 4
# Your Total Score:                                          982
# Total Time Taken:                                         0.17
# Your Accuracy:                                             50%
# Attempts No.:                                                2
################################################################

