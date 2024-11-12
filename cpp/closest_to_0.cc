////////////////////////////////////////////////////////////////
// Pair Sum Closest to 0
////////////////////////////////////////////////////////////////
// Given an integer array of N elements. You need to find the ma :
// ximum sum of two elements such that sum is closest to zero
////////////////////////////////////////////////////////////////
// Input: N = 3, arr[] = {-8 -66 -60}
// Output: -68
// Explanation: Sum of two elements closest to zero is -68 using
// numbers -60 and -8
////////////////////////////////////////////////////////////////
// Input: N = 6, arr[] = {-21 -67 -37 -18 4 -65}
// Output: -14
// Explanation: Sum of two elements closest to zero is -14 using
// numbers -18 and 4
////////////////////////////////////////////////////////////////
// Note : In Case if we have two of more ways to form sum of two
// elements closest to zero return the maximum sum
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(1)
////////////////////////////////////////////////////////////////
// 2 ≤ N ≤ 5*10^5
// -10^6 ≤ arr[i] ≤ 10^6
////////////////////////////////////////////////////////////////
//　 _＿＿＿＿＿_  　　　　  _＿＿＿＿_ 
//　| 　　大学　 | 　　　　 | 　　　　 |
//　|_＿＿＿＿＿_| 　　　　 | スーパー |
//　| 　ホテル　 | 　　　　 | 　　　　 |
//　|_＿＿＿＿＿_| 　公園　 |_＿＿＿＿_|
//　  　喫茶店　   　　　　   　　　　  
//　 _＿＿＿＿＿_  ＿＿＿＿  _＿＿＿＿_
//　| レストラン ||　　　　|| 　　　　 |
//　|_＿＿＿＿＿_||　高校　||_＿＿＿＿_|
//　| 　　　　　 ||＿＿＿＿|| 　　　　 |
//　|_＿＿＿＿＿_| 　　　　 |_＿＿＿＿_|
//
// 1. 大学はどこですか。
//    ホテル の 後ろ です。
// 2. 喫茶店 は どこ です か。
//    ホテル の なか です。
// 3. スーパー は どこ です か。
//    公園 の 隣 です。
// 3. 高校 は どこ です か。
//    公園 の 前 です。
// 5. レストラン は どこ です か。
//    ホテル の 前 です。
//  _＿＿＿_   　　　   _＿＿＿＿_ 
// | 　　　 |  　　　  | 　　　　 |
// | 　　　 |  　　　  | 　病院　 |
// |_＿＿＿_| _＿＿＿_ |_＿＿＿＿_|
// | 　　　 || 　　　 || 　　　　 |
// | 　　　 || 郵便局 || デパート |
// |_＿＿＿_||_＿＿＿_||_＿本屋＿_|
//   　　　    　　　    バス亭　  
//  _＿＿＿_  _＿＿＿_  _＿＿＿_
// | 　　　 || 　　　 || 　　　 |
// | 図書館 || 銀行　 ||_＿＿＿_|
// |_＿＿＿_||_＿＿＿_|| 　　　 |
//   　　　    　　　  |_＿＿＿_|
//
// 4. 銀行 は どこ です か。
//    郵便局 の 前 です。
// 1. 病院 は どこ です か。
//    デパート の 後ろ です。
// 2. バス亭 は どこ です か。
//    デパート の 前 です。
// 4. 本屋 は どこ です か。
//    デパート の 中 です。
// 5. 郵便局 は どこ です か。
//    銀行 の 前 です。
////////////////////////////////////////////////////////////////
# include <iostream>
# include <algorithm>
# include <climits>
# include <cstdlib>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
class Solution {
public:
    int closestToZero( int a[], int n )
    {
        sort( a, a + n );
        int mindif = INT_MAX;
        int maxsum = INT_MIN;
        int i = 0;
        int j = n - 1;
        while( i < j ){
            int sum = a[i] + a[j];
            int dif = abs( sum );
            if( dif < mindif ){
                mindif = dif;
                maxsum = sum;
            } else
            if( dif == mindif ){
                maxsum = max( maxsum, sum );
            }
            if( sum < 0 ){
                ++i;
            } else
            if( sum > 0 ){
                --j;
            } else {
                ++i;
                --j;
            }
        }
        return maxsum;
    }
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main (){int t;cin>>t;while(t--){int n;cin>>n;int arr[n];for(
int i=0;i<n;i++) cin>>arr[i];Solution ob;cout<<ob.closestToZero(
arr,n)<<endl;}}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                         72
// Time Taken:                                              0.15
// Points Scored:                                              4
// Your Total Score:                                        1874
// ==                   1.5.15: Build an example graph of the de <
// ==    2L             pendency of vB from time if vA is consta -
// =E , , , , , _D      nt. Find formula for that dependency, if
// ==\   C`    /o|      x(0) = 0                                
// == \   `x  /  |      ////////////////////////////////////////
// ==  \  `  /   |      Zo here we go again, at time 0 DA was DC
// ==   \ ` /    * B    zo we can think of this motion as compos %
// ==    \o/            ition of two independent motions perpend _
// ==     |A            icular to each other, namely rotation ov =
// ==     |             er center D, and motion alongside its ra
// ==     |             dius. At first sight it seems, the speed
// ==     V vA          with which DA increases is same as vB, b /
// ==                   ut actually we have to take the full len \
// gth that is EAD, so the length with which EA + AD will increa ,
// se is equal to the length with which DB will decrease, so it' `
// s two times larger. Let's α is the ADE angle, then the alnogs -
// ide speed is equal to vAsinα = vA[x|√(x² + L²)], zooooooooooo >
// oooo vB = 2vA[x|√(x² + L²)] = 2(vA)²t|√[(vA)²t² + L²]       «
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
