################################################################
################################################################
##@@@@@@@@@@==========##########################################
##@@@@@ @@@@== =======##########################################
##@@@@@ @@@@== =======##########################################
##@@@@ @@           ==##########################################
##@@@  @@@@@=   ======##########################################
##4 44 44444 % % %%%%%##########################################
##4444 444 4%% %%% %%%##########################################
##4444 4 44       %% %##########################################
##4444 44444%% %%%%%%%##########################################
##4444444444%%%%%%%%%%##########################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
                         #
                         #                         からだ
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
# Power Of Numbers
################################################################
################################################################
################################################################
################################################################
# Given a number and its reverse. Find that number raised to the
# power of its own reverse.
# Note: As answers can be very large, print the result modulo
# 10^9 + 7.
################################################################
################################################################
################################################################
################################################################
# Expected Time Complexity: O( Log N )
# Expected Auxiliary Space: O( Log N )
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
class Solution:
    def power( self, N, R ): return chikara( N, R )
################################################################
################################################################
################################################################
################################################################
MOD = 1_000_000_007
def chikara( w, y ):
    """ w^y """
    if not y: return 1
    a = chikara( w, y//2 ) ** 2
    if y & 1: a *= w
    return a % MOD
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
def main():#####################################################
    T=int(input())##############################################
    while(T>0):#################################################
        N=input()###############################################
        R=N[::-1]###############################################
        ob=Solution()###########################################
        ans=ob.power(int(N),int(R))#############################
        print(ans)##############################################
        T-=1####################################################
if __name__=="__main__":########################################
    main()######################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
################################################################
# Test Cases Passed:                                 1120 / 1120
# Total Points Scored:                                     4 / 4
# Your Total Score:                                         1230
# Total Time Taken:                                         0.04