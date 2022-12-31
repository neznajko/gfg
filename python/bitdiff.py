################################################################
# Sum of bit differences
################################################################
# Stand out from the crowd. Prepare with Complete Interview
# Preparation  
################################################################
# Given an integer array of N integers, find sum of bit differences
# in all pairs that can be formed from array elements. Bit difference
# of a pair (x, y) is count of different bits at same positions in
# binary representations of x and y. For example, bit difference
# for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111
# (first and last bits differ in two numbers).
# 
# Note: (x, y) and (y, x) are considered two separate pairs.
################################################################
# Example 1:
# 
# Input: 
# N = 2
# arr[] = {1, 2}
# Output: 4
# Explanation: All pairs in array are (1, 1)
# (1, 2), 2, 1), (2, 2)
# Sum of bit differences = 0 + 2 + 2 + 0
#                        = 4
# Example 2:
# 
# Input:
# N = 3 
# arr[] = {1, 3, 5}
# Output: 8
# Explanation: 
# All pairs in array are (1, 1), (1, 3),
# (1, 5), (3, 1), (3, 3) (3, 5),(5, 1),
# (5, 3), (5, 5)
# Sum of bit differences =  0 + 1 + 1 +
#                           1 + 0 + 2 +
#                           1 + 2 + 0 
#                        = 8
################################################################
# Expected Time Complexity: O(N)
# Expected Auxiliary Space: O(1)
# 
# Constraints:
# 1 <=      N <= 10^5
# 1 <= arr[i] <= 10^5
################################################################
# 2 ^ 16 = 65,536 
# 2 ^ 17 = 131,072
NOOFBITS = 17
class Solution:
    def sumBitDifferences( self, arr, siz ):
        bitsum = [ 0 ] * NOOFBITS
        for n in arr:
            j = 0
            while n > 0:
                bitsum[ j ] += n & 1
                n >>= 1
                j += 1
        total = 0
        for noofones in bitsum:
            noofzeroes = siz - noofones
            total += noofones * noofzeroes * 2
        return total
################################################################
# Test Cases Passed: 360 / 360 
# Total Points Scored: 4 / 4   
# Your Total Score: 966        
# Total Time Taken: 2.49       
# Your Accuracy: 100%          
# Attempts No.: 1              
################################################################
print( Solution().sumBitDifferences([ 5, 7, 2, 4, 8 ], 5 ))
################################################################
# This buffer is for text that is not saved, and for Lisp evaluation.
# To create a file, visit it with C-x C-f and enter text in its buffer.
#
# 2: 0 0 - 0  3: 0 0 0 - 0  4: 0 0 0 0 - 0  5: 0 0 0 0 0 - 5 x 0 = 0
#    0 1 - 1     0 0 1 - 2     0 0 0 1 - 3     0 0 0 0 1 - 4 x 1 = 4
#    1 0 - 1     0 1 0 - 2     0 0 1 0 - 3     0 0 0 1 1 - 3 x 2 = 6
#    1 1 - 0     1 0 0 - 2     0 1 0 0 - 3     0 0 1 1 1 - 2 x 3 = 6
#                0 1 1 - 2     1 0 0 0 - 3     0 1 1 1 1 - 1 x 4 = 4
#                1 0 1 - 2     0 0 1 1 - 4     1 1 1 1 1 - 0 x 5 = 0
#                1 1 0 - 2     0 1 0 1 - 4
#                1 1 1 - 0     0 1 1 0 - 4
#                              1 0 0 1 - 4
#                              1 0 1 0 - 4
#                              1 1 0 0 - 4
#                              0 1 1 1 - 3
#                              1 1 1 0 - 3
#                              1 1 0 1 - 3
#                              1 0 1 1 - 3
#                              1 1 1 1 - 0
# arr[] = {1, 2}      . 3 7              | 8 5 7                       .
# Output: 4           . 1 1 2 x 0 x 2 = 0| 0 1 1  1 x 2 x 2 = 4        .
#                     . 1 1 2 x 0 x 2 = 0| 0 0 1  2 x 1 x 2 = 4        .
# 01                  . 0 1 1 x 1 x 2 = 2| 0 1 1  1 x 2 x 2 = 4        .
# 10                  . -----------------+ 1 0 0  1 x 2 x 2 = 4        .
#                     .     0 + 0 + 2 = 2+---------------------        .
# arr[] = {1, 3, 5}   .                      4 + 4 + 4 + 4 = 16        ,
# Output: 8           . 2 3 4 5 |                                      .
#                     . 0 1 0 1 ' 2 x 2 x 2 = 8                        .
# 001                 . 1 1 0 0 | 2 x 2 x 2 = 8                        .
# 011                 . 0 0 1 1 | 2 x 2 x 2 = 8                        .
# 101                 . --------+--------------                        .
#                     .          8 + 8 + 8 = 24                        .
# 2, 3, 4, 5    => 24 . 5 7 2 4 8 |                                    .
# 3, 7          => 2  . 1 1 0 0 0 | 2 x 3 x 2 = 12                     .
# 8, 5, 7       => 16 . 0 1 1 0 0 ¦ 2 x 3 x 2 = 12                     .
# 5, 7, 2, 4, 8 => 44 . 1 1 0 1 0 | 2 x 3 x 2 = 12                     .
#                     . 0 0 0 0 1 | 4 x 1 x 2 = 8                      .
#                     . ----------+---------------                     .
#                     .      12 + 12 + 12 + 8 = 44                     .
########################################################################
