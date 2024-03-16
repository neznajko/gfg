################################################################
# Check if frequencies can be equal
################################################################
# Given a string s which contains only lower alphabetic
# characters, check if it is possible to remove at most one
# character from this string in such a way that frequency of
# each distinct character becomes same in the string. Return
# true if it is possible to do else return false.
################################################################
# Input: s = "xyyz"
# Output: 1 
# Explanation: Removing one 'y' will make frequency of each
# character to be 1
################################################################
# Expected Time Complexity: O(|s|) 
# Expected Auxiliary Space: O(1)
################################################################
# 1 <= |s| <= 10^5
################################################################
################################################################
from collections import defaultdict
################################################################
################################################################
def check( s ):
    distrib_ch = defaultdict( int )
    for ch in s: distrib_ch[ ch ] += 1
    distrib_freq = defaultdict( int )
    for freq in distrib_ch.values():
        distrib_freq[ freq ] += 1
    width_freq = len( distrib_freq )
    if width_freq  > 2: return False
    if width_freq == 1: return True
    spectrum = distrib_freq.keys()
    low_freq = min( spectrum )
    high_freq = max( spectrum )
    if low_freq == 1 and distrib_freq[ low_freq ] == 1:
        return True
    if distrib_freq[ high_freq ] > 1: return False
    return high_freq - low_freq == 1
################################################################
################################################################
################################################################
################################################################
class Solution:
    def sameFreq( self, s ): return check( s )
################################################################
if __name__ == "__main__": #####################################
	T=int(input()) #########################################
	for _ in range(T): #####################################
		s = input() ####################################
		ob = Solution() ################################
		answer = ob.sameFreq(s) ########################
		if answer: #####################################
			print(1) ###############################
		else: ##########################################
			print(0) ###############################
################################################################
# Test Cases Passed:                                 1136 / 1136
# Points Scored:                                           4 / 4
# Your Total Score:                                         1698 
# Time Taken:                                               0.09
# log: Ask your preacher what is god, I've asked ChatGPT,
# basically it doesn't know very much either, ok something
# almighty all-powerful stuff that is ruling everything and
# everybody awe before its might. Do you think this stuff is
# ruling by democracy? Until there are religions there will be
# people following the footsteps of the almighty, until there
# are religions there will be dictators.
#
