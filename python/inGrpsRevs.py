#? inGrpsRevs.py
################################################################
# https://practice.geeksforgeeks.org/problems/
# reverse-a-linked-list-in-groups-of-given-size/1
################################################################
# Reverse a Linked List in groups of given size.
# 
# Given a linked list of size N. The task is to reverse every k
# nodes (where k is an input to the function) in the linked
# list. If the number of nodes is not a multiple of k then
# left-out nodes, in the end, should be considered as a group
# and must be reversed (See Example 2 for clarification).
# 
# Example 2:
# Input:
# LinkedList: 1->2->3->4->5
# K = 3
# Output: 3 2 1 5 4
# Explanation: 
# The first 3 elements are 1,2,3 are reversed first and then
# elements 4,5 are reversed.Hence, the resultant linked list is
# 3->2->1->5->4.
#
# Your Task: You don't need to read input or print
# anything. Your task is to complete the function reverse()
# which should reverse the linked list in group of size k and
# return the head of the modified linked list.
# 
################################################################
# Expected Time Complexity : O(N)
# Expected Auxilliary Space : O(1)
# 
# Constraints:
# 1 <= N <= 10^4
# 1 <= k <= N
################################################################
# Test Cases Passed: 700 / 700
# Total Points Scored: 4 / 4
# Your Total Score: 766
# Total Time Taken: 0.39
# Your Accuracy: 100%
# Attempts No.: 1
def fR( head, k ):
    if not head.next: return None
    #
    prev = None
    cure = head.next
    next = None
    #
    while k > 0 and cure:
        next = cure.next
        cure.next = prev
        prev = cure
        cure = next
        k -= 1
    #
    new_head = head.next
    head.next = prev
    new_head.next = next
    #
    return new_head
###########____#################################################    
class Solution:
    def reverse( self, head, k ):
        if k == 1: return head
        # 
        ahead = Node( 0 )
        ahead.next = head
        p = ahead
        while p:
            p = fR( p, k )
        return ahead.next
#################################################### Driver Code
class Node: #                                        Driver Code
    def __init__( self, data ): #                    Driver Code
        self.data = data #                           Driver Code
        self.next = None #                           Driver Code
#################################################### Driver Code
class LinkedList: #                                  Driver Code
    def __init__( self ): #                          Driver Code
        self.head = None #                           Driver Code
    #                                                Driver Code
    def push( self, new_data ): #                    Driver Code
        new_node = Node( new_data ) #                Driver Code
        new_node.next = self.head #                  Driver Code
        self.head = new_node #                       Driver Code
    #                                                Driver Code
    def printList( self ): #                         Driver Code
        temp = self.head #                           Driver Code
        while temp: #                                Driver Code
            print( temp.data, end=" " ) #            Driver Code
            temp = temp.next #                       Driver Code
        print() #                                    Driver Code
#################################################### Driver Code
# t
# n
# v1 v2 .. vn
# k
if __name__ == '__main__':
    t = int( input() )
    while t > 0:
        llist = LinkedList()
        n = input()
        values = list( map( int, input().split()))
        for i in reversed( values ):
            llist.push( i )
        k = int( input() )
        new_head = LinkedList()
        ob = Solution()
        new_head = ob.reverse( llist.head, k )
        llist.head = new_head
        llist.printList()
        t -= 1
################################################################
# log: -I was sick last week or smt. and I think it was omicron,
# this is a simple problem, which will not secure me position as
# a Google Engineer, but I'm just trying to get into shape.
