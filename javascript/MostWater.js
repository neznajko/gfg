                            ////////
///////////////////////////////////////////////////////////////=
// Container With Most Water
////////////////////////////////////////////////////////////////
// Givn N non negative integers a1,a2,..,aN where each represnts
// a point at coordinte (i, ai). N vertical lines are drawn such
// that the two endpnts of line i is at (i, ai) and (i, 0). Find
// two lines, which together with x axis forms a container, such
// that it contains the most water.
////////////////////////////////////////////////////////////////
// Example:     1
// Input:       N = 4
//              a[] = {1,5,4,3}
// Output:      6
// Explanation: 5 and 3 are distance 2 apart. So the size of the
// base = 2. Height of coóntainer = min(5, 3) = 3. So total area
// = 3 * 2 = 6.
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).
////////////////////////////////////////////////////////////////
// Constraints:
// 2 <= N    <= 10^5
// 1 <= A[i] <= 100
////////////////////////////////////////////////////////////////
function main() {
    console.log(( new Solution()).maxArea(
        [2,4,3,1],
        4
    ));
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed: 282 / 282 This is a nice problm but cmpred
// Total Points Scored: 4 / 4   to a similar at fst sight problm
// Your Total Score: 910        of finding mxmm area in hisogram
// Total Time Taken: 0.25       looks quite easy.             oó
// Your Accuracy: 100%
// Attempts No.: 1                              [ Ŧŵő ρòǐɳŧɵʁʐ ]
////////////////////////////////////////////////////////////////
class Solution {    
    maxArea( a, n ){
        let answ = 0;
        let i = 0,
            j = n - 1;
        for(; i < j ;){
            if( a[i] < a[j] ){
                answ = Math.max( answ, a[i]*( j - i ));
                i++;
            } else {
                answ = Math.max( answ, a[j]*( j - i ));
                j--;
            }
        }
        return answ;
    }
}
////////////////////////////////////////////////////////////////
// log:
////////////////////////////////////////////////////////////////
main();
////////////////////////////////////////////////////////////////
////                                                        ////
