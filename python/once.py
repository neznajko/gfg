###############################################################_
# Test Cases Passed:                                   201 / 201
# Total Points Scored:                                     4 / 4
# Your Total Score:                                         1154
# Total Time Taken:                                         0.28
###############################################################=
class Solution:
    def search( self, A, N ):
        lowr, uppr = 0, N - 1
        while lowr < uppr:
            midl = ( lowr + uppr )// 2
            left, ryte = midl - 1, midl + 1
            if left > -1 and A[ left ] == A[ midl ]:
                ryte = midl
            elif ryte < N and A[ ryte ] == A[ midl ]:
                left = midl
            else:
                return A[ midl ]
            # < head: lowr, .. >, left, ryte, < tail: .. uppr >
            nfheads = left - lowr
            nftails = uppr - ryte
            # check which is odd
            if nfheads & 1:
                uppr = left - 1
            else:
                lowr = ryte + 1
        return A[ lowr ]
###############################################################_
if __name__ == "__main__":
    A = [ 1, 1, 2, 2, 3, 4, 4 ]
    N = len( A )
    print( Solution().search( A, N ))
###############################################################=
# Find the element that appears once
###############################################################_
# Given a sorted array A[] of N positive integers having all the
# numbers occurring exactly twice, except for one number which
# will occur only once. Find the number occurring only once.
###############################################################%
# Example: 1
# Input: { 1, 1, 2, 5, 5 }
# Output: 2
###############################################################<
# Expected Time Complexity: O(log(N))
# Expected Auxiliary Space: O(1)
###############################################################~
