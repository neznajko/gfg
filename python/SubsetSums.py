################################################################
# Subset Sums
################################################################
################################################################
###############################################################i
# Given a list arr of N integers, print sums of all subsets in t.
################################################################
###################################################### Example 1:
# Input: N = 2 arr[] = {2, 3}
# Output: 0 2 3 5
###################################################### Example 2:
# Input: N = 3 arr = {5, 2, 1}
# Output: 0 1 2 3 5 6 7 8
################################################################
################################################################
################################################################
################################################################
# Expected Time Complexity: O(2^N)
# Expected Auxiliary Space: O(2^N)
################################################################
# Ok dhis is one of the fyorst examples in combinatorics, to get
# all subsets of N elements, zo if ve haaf 4 bits ve can have up
###############################################################o
# to 2^4 = 16 diff values from 0 to 15, zo each bit configuratin
###############################################################i
# corresponds to a subset let's say 12 in binary is 1100, that s
##############################################################ar
# this is the subset {3,4} from {1,2,3,4} beecooz bits 3 and 4 e
# set. I phink I'm going to try writing a generator or something.
################################################################
def subset_gen( a, n ):
    def get_subset( bits ):
        subset = []
        offset = 0
        while bits:
            if bits & 1:
                subset.append( a[ offset ])
            offset += 1
            bits >>= 1
        return subset
    for bits in range( 1 << n ):
        yield get_subset( bits )
################################################################
class Solution:
    def subsetSums( self, arr, N ):
        sums = []
        for subset in subset_gen( arr, N ):
            sums.append( sum( subset ))
        return sums
################################################################
if __name__=='__main__':#                                      _
    T=int(input())#                                            _
    for i in range(T):#                                        _
        N=int(input())#                                        _
        arr=[int(x) for x in input().split()]#                 _
        ob=Solution()#                                         _
        ans=ob.subsetSums(arr,N)#                              _
        ans.sort()#                                            _
        for x in ans:#                                         _
            print(x,end=" ")#                                  _
        print()#
################################################################
# Test Cases Passed:                                   113 / 113
# Total Points Scored:                                     4 / 4
# Your Total Score:                                         1174
# Total Time Taken:                                         1.15
################################################################
