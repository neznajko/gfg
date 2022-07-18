#! /usr/bin/env                                          python3
################################################################
# Find Missing And Repeating
################################################################ _____
# Medium Accuracy: 37.77% Submissions: 100k+ Points: 4           _____
# Given an unsorted array Arr of size N of positive integers. On ě____
# number 'A' from set {1, 2, …N} is missing and one number 'B' o čćŰŗś
# twice in array. Find these two numbers.                        -----
################################################################
# Example 1, Input:                                  Output: 2 1
#            N = 2
#            Arr[] = {2, 2}
################################################################ ==
# Explanation: Repeating number is 2 and smallest positive missi ŋĝ
# number is 1.                                                   ~~
################################################################ ______
# Your Task: You don't need to read input or print anything. You Ř-----
# task is to complete the function findTwoElement() which takes  ======
# the array of integers arr and n as parameters and returns an a ŔŕăŸ--
# of integers of size 2, denoting the answer (The first index co ňŧäĮńś
# B and second index contains A).                                ______
################################################################
# Expected Time Complexity: O(N)
# Expected Auxiliary Space: O(1)
################################################################
# Constraints:
# 1 ≤ N ≤ 10⁵                                               2075
# 1 ≤ Arr[i] ≤ N
################################################################ --
# I've checked the hint for this one:), and it basically gives t Ħē
# solution, but there are some dirty tricks here, and have decid ėĐ
# to write it anyway.                                            ==
################################################################ --
# Test Cases Passed: 340 / 340
# Total Time Taken: 0.34 / 1.85
class Solution:
    def findTwoElement( self, a, n ):
        rep, miss = None, None
        if 0: import pdb; pdb.set_trace()
        ########################################################
        for y in a:
            # use absolute value as an index( dirty, but not che Śś
            # trick namba one )                                  --
            j = abs( y ) - 1
            if a[j] < 0:
                rep = j + 1
            else: 
                a[j] = -a[j]
        # Dirty trick namba two: the index of the only left posi ţĬʋė
        # namba will correspond to the missing namba.            ____
        for j, y in enumerate( a ):
            if y > 0: 
                miss = j + 1
                break
        return rep, miss
################################################################
####----____````,,,,    >>>>""""    ääää____\\\\,,,,    ....>>>>        
if __name__ == '__main__':
    tc          = int(              input   (   )              )
    while tc    > 0                                            :
        n       = int(              input   (   )              )
        arr =   list(   map(int,    input().strip().split(   )))
        ob                          =       Solution(          )
        ans     =       ob.findTwoElement(  arr,    n          )
        print(  str(    ans[0       ])  +   " " +   str(ans[1]))
        tc                              =   tc  -              1
################################################################
# log:
