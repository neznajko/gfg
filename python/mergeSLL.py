################################################################
# Merge two sorted linked lists                           
################################################################
# Given two sorted linked lists consisting of N and M nodes
# respectively. The task is to merge both of the list (in-place)
# and return head of the merged list.
################################################################
# Input:  {5,10,15,40}
#         {2,3,20}
# Output: {2,3,5,10,15,20,40}
################################################################
# Expected Time Complexity:  O(n+m)
# Expected Auxilliary Space: O(1)
################################################################
def sortedMerge( a, b ):
    """"""
    head = Node( 0 )
    c = head
    while True:
        if not a:
            c.next = b
            break
        if not b:
            c.next = a
            break
        if a.data <= b.data:
            c.next = a
            a = a.next
        else:
            c.next = b
            b = b.next
        c = c.next
    return head.next
################################################################
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
################################################################
# Test Cases Passed: 303 / 303 
# Total Points Scored: 4 / 4   
# Your Total Score: 958        
# Total Time Taken: 1.63       
# Your Accuracy: 100%          
# Attempts No.: 1              
################################################################
