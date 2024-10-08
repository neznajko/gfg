################################################################ Folgen 
################################################################ 
#######################   ###################################### 
######  ###############     #################################### 
####      #############    ##################################### 
######      ##########    ######################################
########      #######   ########################################
##########      #### ########################################### S
############  #### ############################################# U
#####     ########                  ######## ################### i
#########     ##### ############### #####      ################# V
############ ######                  ## ####     ############### R
###########  ###### ##########################    ############## E
##########    ####                  ############  ##############
###########    #### ############### ############# ##############
############ ######                  ############ ##############
##########   ###### ############################ ###############
######## ###    #############################  #################
###### #######       #################      ####################
###################                    ######################### 
########################          ############################## 
################################################################ おい
################################################################ 追
# Minimum Swaps to Sort
################################################################
# Given an array of n distinct elements. Find the minimum number
# of swaps required to sort the array in strictly increasing
# order
################################################################
# Input: nums = {10, 19, 6, 3, 5}
# Output: 2
# Explanation: swap 10 with 3 and swap 19 with 5
################################################################
# Expected Time Complexity: O(nlogn)
# Expected Auxiliary Space: O(n)
################################################################
# 1 ≤ n ≤ 10^5
# 1 ≤ nums[i] ≤ 10^6
################################################################
class Solution:
    ''''''
    def minSwaps( self, a ):
        M = { value: j for j, value in enumerate( a )}
        nswaps = 0
        for j, value in enumerate( sorted( a )):
            i = M[ value ]
            if i != j:
                nswaps += 1
                M[a[i]], M[a[j]] = M[a[j]], M[a[i]]
                a[i], a[j] = a[j], a[i]
        return nswaps
################################################################
if __name__=='__main__': #######################################
	T=int(input()) #########################################
	for i in range(T): #####################################
		n=int(input()) #################################
		nums=list(map(int,input().split())) ############
		obj=Solution() #################################
		ans=obj.minSwaps(nums) #########################
		print(ans) #####################################
################################################################
# Test Cases Passed:                                     50 / 50
# Points Scored:                                           4 / 4
# Your Total Score:                                         1726 
# Time Taken:                                               0.87
