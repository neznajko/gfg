//                                                               う  u
//      @@@````````````````````````###                           け ke
//      @@@          ,,,,          ###                           る ru
//      @@@@@@@@@@@@@    ==''''#######                  recevoir f
//      @@@@@@@....========    #######                           受
//      `                  ````      ,                  erhalten g                           
//      `                            ,                  отримати u
//      `    ||||||||||||||||||||    ,                  ricevere i
//      `                            ,                   recibir s
//      @@@@@                    |||||                   receive e
//______@@@@@@@@     ````     ||||||||__________________________
//------@@@@@@@@@@@@      ||||||||||||--------------------------
//------@@@@@@@@     ####     ||||||||--------------------------
//------@@@@      ##########      ||||--------------------------
//------````      ``````````      ````--------------------------
//------````````     ````     ````````--------------------------
//------````````````      ````````````--------------------------
//
//------````````     ````     ````````--------------------------
//
// 
//------`````                    `````--------------------------
////////////////////////////////////////////////////////////////
// Count the subarrays having product less than k
////////////////////////////////////////////////////////////////
// Given an array of positive numbers, the task is to find the
// number of possible contiguous subarrays having product less
// than a given number k.
////////////////////////////////////////////////////////////////
// Input: n = 4, k = 10, a[] = {1, 2, 3, 4} Output: 7
// Explanation: The contiguous subarrays are {1}, {2}, {3}, {4} 
// {1, 2}, {1, 2, 3} and {2, 3}, in all these subarrays product 
// of elements is less than 10, count of such subarray is 7.
// {2,3,4} will not be a valid subarray, because 2*3*4=24 which 
// is greater than 10.
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)
////////////////////////////////////////////////////////////////
// 1<=n<=10^6
// 1<=k<=10^5
// 1<=a[i]<=10^5
////////////////////////////////////////////////////////////////
// a 24 24 12  4, k = 10
//    0  1  2  3
// i           ^
// j           ^
// b 4
// s 6
class Solution {
    countSubArrayProductLessThanK( a, n, k ){
        let i = 0;
        let j = 0;
        let s = 0;
        let b = a[ i ]; // backup
        while( true ){
            if( a[ j ] < k ){
                if( i == j ){
                    ++s;
                } else {
                    a[ i ] *= a[ j ];
                    while( a[ i ] >= k ){
                        const t = a[ i ] / b;
                        b = a[ ++i ];
                        a[ i ] = t;
                        if( i == j ){ break; }
                    }
                    s += j - i + 1;
                }
            } else {
                i = j + 1;
                b = a[ i ];
            }
            if( ++j == n ){ break; }
        }
        return s;
    }
}
////////////////////////////////////////////////////////////////
const a = [ 1, 2, 3, 4 ];
const n = a.length;
const k = 10;
new Solution().countSubArrayProductLessThanK( a, n, k );
////////////////////////////////////////////////////////////////
// log:        Birth and death are the harmonies between all and
//                  nothing, if you defeat death you defeat life
// Test Cases Passed:                                1122 / 1122
// Points Scored:                                          4 / 4
// Your Total Score:                                        1762
// Time Taken:                                              0.21
