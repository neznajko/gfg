################################################################
# Maximum Meetings in One Room
################################################################
# There is one meeting room in a firm. There are N meetings in the
# form of (S[i], F[i]) where S[i] is the start time of meeting i
# and F[i] is the finish time of meeting i. The task is to find the
# maximum number of meetings that can be accommodated in the meeting
# room. You can accommodate a meeting if the start time of the meeting
# is strictly greater than the finish time of the previous meeting.
# 
# Note: If two meetings can be chosen for the same slot then choose
# meeting with smaller index in the given array.
################################################################
# Example:     2
# Input:       N = 1
#              S = {3}
#              F = {7}
# Output:      {1}
# Explanation: Since there is only one meeting, we can attend the
#              meeting.
################################################################
# Expected Time Complexity: O(N*log(N))
# Expected Auxiliary Space: O(N)
################################################################
# Constraints:
# 1 <= N <= 10^5
# 1 <= S[i] <= F[i] <= 10^9
################################################################
# Plan B:
# 1. Make list with tuple elements (s[j], f[j], j).
# 2. Sort with respect of f, j.
# 3. Create an output list, initialized with the first value of
#    the sorted list ls.
# 4. Make a loop over ls, starting from the second element.
# 5. Check if element starting value is greather than the finish
#    value of the last output element.
# 6. If so append to output list.
# 7. Chill.
# Plan A: Someone has acta cool..
class Solution:
    def maxMeetings( self, n, s, f ):
        # [B1 Make list.]
        ls = list( zip( s, f, range( n )))
        # [A2 Sorting.]
        ls.sort( key=lambda t: t[1] )
        # [B3 Output.]
        oput = [ ls[0][2] + 1 ]
        # [B4 Make it happen.]
        for lm in ls[1:]:
            # [B5 Check Check]
            if lm[0] > f[ oput[-1] - 1 ]:
                # [B6 Add]
                oput.append( lm[2] + 1 )
        # [A7 Vamos a bailar]
        oput.sort()
        return oput
################################################################
# Test Cases Passed: 101020 / 101020 << haha
# Your Total Score: 818
# Total Time Taken: 1.81
# Correct Submission Count: 2 << first time it hangup
# Attempts No.: 3
################################################################
class IntArray:
    def Input( self, n ):
        return [ int( i ) for i in input().strip().split() ]
    def Print( self, arr):
        for i in arr:
            print( i, end=" " )
        print()
################################################################
if __name__ == "__main__":
    t = int( input())
    for _ in range( t ):
        N = int( input())
        S = IntArray().Input( N )
        F = IntArray().Input( N )
        obj = Solution()
        res = obj.maxMeetings( N, S, F )
        IntArray().Print( res )
########_#######################################################
# log: -I'm very happy that I'm and will not be part of what was
# the name,.. concept art community. You suck even more than the
# modern art.
