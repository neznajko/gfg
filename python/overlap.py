################################################################
# Overlapping Intervals
################_###############################################
# Given a collectn of Intervals, the task is to merge all of the
# overlapping Intervals.
################################################################
# Example: 2
# Input:   {{6,8},{1,9},{2,4},{4,7}}
# Output:  {{1, 9}}
################################################################
# Your Task: Hafe vun.
################################################################
# Expected Time Complexity: O(N*Log(N)).
# Expected Auxiliary Space: O(Log(N)) or O(N).
################################################################
# Constraints:
# 1 ≤     N ≤ 100
# 0 ≤ x ≤ y ≤ 1000
################################################################


####                                                ####
####----            ####            ####           h ,,,    ====
####----            ####    fØlkS   ####           i ,,, ____
####----    ####    ####    .....   ####****       t ,,, 
####----sony####    ####    .....   #### _ _       a ,,,
####----====####    ####    .....   #### _ _    >>>> ,,,
####----====####1111####    .....   #### _ ooooo>>>> ,,,    ö_Ò
###[4:23AM]#################################################   #
class Solution:
    def overlappedInterval( self, intv ):
        self.intv, self.n = sorted( intv ), len( intv )
        j, ls = 0, []
        while j < self.n:
            mrged, j = self.Expand_Interval( j )
            ls.append( mrged )
        return ls
    def Expand_Interval( self, j ):
        min_left, max_ryte = self.intv[j]
        while True:
            j += 1
            if j >= self.n: break
            left, ryte = self.intv[j]
            if left > max_ryte: break
            if ryte > max_ryte: max_ryte = ryte
        return ( min_left, max_ryte ), j
################################################################
# Test Cases Passed: 304 / 304 #################################
# Total Points Scored: 4 / 4 ###################################
# Your Total Score: 814 ########################################
# Total Time Taken: 0.03 #######################################
# Your Accuracy: 50% ###########################################
# Attempts No.: 2 ##############################################
################################################################        
if __name__ == '__main__':                      # T
    T = int( input())                           # n
    for i in range( T ):                        # x1 y1 .. xn yn
        n = int( input())
        a = list( map( int, input().strip().split()))
        Intervals = []#                                         D
        j = 0#                                                  r
        for i in range( n ):#                                   i 
            x = a[j]#                                           v
            j += 1#                                             e
            y = a[j]#                                           r
            j += 1#                                             C  
            Intervals.append([ x, y ])#                         o
        obj = Solution()#                                       d
        ans = obj.overlappedInterval( Intervals )#              e
        for i in ans:
            for j in i:
                print( j, end = " " )
        print()
################################################################
# log:
