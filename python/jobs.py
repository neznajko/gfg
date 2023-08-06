##############################################################-#
# Job Sequencing Problem
########a####################a#################################-
# Given set of N jobs where ech job[i] has a deadline and profit
# associated with it., Each job takes 1 unit of time to complete
#############################################################o##
# and only one job can be scheduled at a time. We earn the prfit
# associated with job if and only if the job is completed by its
# deadline,. Find the number of jobs done and the maximum profit.
# Note: Jobs will be given in the form (Jobid, Deadline, Profit)
# associated with that Job.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.`.
###############################################################=
# Expected Time Complexity: O( N log N )
# Expected Auxilliary Space: O( N )
###############################################################+
# Bascly here the problem is not very clear, the idea is that if
# we have time slots like 1 2 3 4 5 6 etc. and a job'as deadline
# 5 than it can be put in slots 1, 2, 3, 4, or fai.,.,.,.,.*,.,.
###############################################################=
# Test Cases Passed                                  : 215 / 215
# Total Points Scored:                                 4   /   4
# Your Total Score                      :                   1170
# Total Time Taken        :                                 6.64
###############################################################_
class Solution:
    def JobScheduling( self, jobs, n ):
        jobs.sort( key=lambda y: y.profit, reverse=True )
        m = max( jobs, key=lambda y: y.deadline )
        timeslots = [ 0 ]*( m.deadline + 1 )
        nfj = 0 # number of jobs
        total = 0 # total profit
        for job in jobs:
            d = job.deadline
            p = job.profit
            while d:
                if not timeslots[ d ]: # if nil
                    timeslots[ d ] = p
                    nfj += 1
                    total += p
                    break
                d -= 1
        return nfj, total
####################################################_##########:
class Job:#####################################################_
    def __init__(self,profit=0,deadline=0):############ d #####`
        self.profit=profit############################# r #####"
        self.deadline=deadline######################### i #####<
        self.id=0###################################### v #####+
####################################################### e #####>
if __name__=='__main__':############################### r #####.
    test_cases=int(input())############################   #####,
    for cases in range(test_cases):############################=
        n=int(input())################################# c #####<
        info=list(map(int,input().strip().split()))#### o #####>
        Jobs=[Job() for i in range(n)]################# d #####=
        for i in range(n):############################# e #####-
            Jobs[i].id=info[3*i]###############################%
            Jobs[i].deadline=info[3*i+1]#######################_
            Jobs[i].profit=info[3*i+2]#########################_
        ob=Solution()##########################################+
        res=ob.JobScheduling(Jobs,n)###########################=
        print(res[0],end=" ")##################################-
        print(res[1])##########################################'
###############################################################"
