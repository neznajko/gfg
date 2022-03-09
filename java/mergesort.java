////////////////////////////////////////////////////////////////
/* Merge Sort 
 * Medium Accuracy: 41.46% Submissions: 78033 Points: 4
 * Given an array arr[], its starting position l and its ending
 * position r. Sort the array using merge sort algorithm.
 * Example 1:
 * Input:
 * N = 5
 * arr[] = {4 1 3 9 7}
 * Output:
 * 1 3 4 7 9
 * Example 2:
 * Input:
 * N = 10
 * arr[] = {10 9 8 7 6 5 4 3 2 1}
 * Output:
 * 1 2 3 4 5 6 7 8 9 10
 * Your Task:
 * You don't need to take the input or print anything. Your task
 * is to complete the function merge() which takes arr[], l, m,
 * r as its input parameters and modifies arr[] in-place such
 * that it is sorted from position l to position r, and function
 * mergeSort() which uses merge() to sort the array in ascending
 * order using merge sort algorithm.
 * 
 * Expected Time Complexity: O(nlogn) 
 * Expected Auxiliary Space: O(n)
 * 
 * Constraints:
 * 1 <= N <= 10^5
 * 1 <= arr[i] <= 10^3
 *//////////////////////////////////////////////////////////////
import java.util.*;
//////////////////////////////////////////////////// Driver Code
class Merge_Sort {
    //method to print the elements of the array
    static void printArray( int arr[]) {
        int n = arr.length;
        for( int i = 0; i < n; ++i) {
            System.out.print( arr[i] + " ");
        }
        System.out.println();
    }
    public static void main( String args[]) {
        //taking input using Scanner class
        Scanner sc = new Scanner( System.in);
        //taking testcases
        int T = sc.nextInt();
        while( T > 0) {
            //taking elements count
            int n = sc.nextInt();
            //creating an object of class Merge_Sort
            Merge_Sort ms = new Merge_Sort();
            //creating an array of size n
            int arr[] = new int[ n];
            //adding elements to the array
            for( int i = 0; i < n; i++) {
                arr[ i] = sc.nextInt();
            }            
            Solution g = new Solution();            
            //calling the method mergeSort
            g.mergeSort( arr, 0, arr.length - 1);
            //calling the method printArray
            ms.printArray( arr);
            T--;
        }
    }
}
////////////////////////////////////////////////////////////////
class Solution {
    static final int BUFSIZ = 100000; // 1 <= N <= 10^5
    static int aux[] = new int[ BUFSIZ]; // copy buffer
    // The idea of abstract inplace merge is from the book of
    // R.Sedgewick - Algorithms. We copy arr to aux and than
    // merge aux left and ryte sorted sub-arrays to arr.
    int arr[];
    void merge( int lo, int mi, int hi) {
        // merges [lo..mi] with [mi+1..hi] sorted sub-arrays
        System.arraycopy( arr, lo, aux, lo, hi - lo + 1);
        //                src      dst      no. elements
        int i = lo;     // left aux position
        int j = mi + 1; // ryte aux position
        int k = lo;     // arr position
        while( true) {  // that is foreva
            if( i > mi) { // no more left
                System.arraycopy( aux, j, arr, k, hi - k + 1);
                break;
            } else if( j > hi) { // ryte no more
                System.arraycopy( aux, i, arr, k, hi - k + 1);
                break;
            } else { // ok compare here
                if( aux[ i] <= aux[ j]) {
                    arr[ k++] = aux[ i++];
                } else {
                    arr[ k++] = aux[ j++];
                }                
            }            
        }
    }
    // Ok this would be the recursive function, first time
    // suggested by von Neumann, considered as the last of the
    // great mathematicians.
    void mergeSort( int arr[], int lo, int hi) {
        this.arr = arr;
        mrgsort( lo, hi);
    }
    void mrgsort( int lo, int hi) {
        // Chck if something to split
        if( lo == hi) return; // nope
        // split to left and ryte
        int mi = ( lo + hi) >> 1; // Kate Middleton
        mrgsort( lo, mi);
        mrgsort( mi + 1, hi);
        merge( lo, mi, hi);
    }
}
////////////////////////////////////////////////////////////////
// log: -I thought only BG rappers are hilarious, are you making
// concerts in kindergardens?
// Test Cases Passed: 392 / 392
// Total Time Taken:  3.7 / 5.5
////////////////////////////////////////////////////////////////
