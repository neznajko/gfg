////////////////////////////////////////////////////////////////
// Closest Three Sum
////////////////////////////////////////////////////////////////
// Given an array, arr of integers, and another number target,
// find three integers in the array such that their sum is
// closest to the target. Return the sum of the three integers
////////////////////////////////////////////////////////////////
// Note: If there are multiple solutions, return the maximum one
////////////////////////////////////////////////////////////////
// Input: arr[] = [-7, 9, 8, 3, 1, 1], target = 2
// Output: 2
// Explanation: There is only one triplet present in the array
// where elements are -7,8,1 whose sum is 2
////////////////////////////////////////////////////////////////
// Input: arr[] = [5, 2, 7, 5], target = 13
// Output: 14
// Explanation: There is one triplet with sum 12 and other with
// sum 14 in the array. Triplet elements are 5, 2, 5 and 2, 7, 5
// respectively. Since abs(13 - 12) == abs(13 - 14) maximum 
// triplet sum will be preferred i.e 14
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(n^2)
// Expected Auxiliary Space: O(1)
////////////////////////////////////////////////////////////////
// 3 ≤ arr.size() ≤ 10^3
// -10^5 ≤ arr[i] ≤ 10^5
// 1 ≤ target ≤ 10^5
////////////////////////////////////////////////////////////////
# include <vector>
# include <sstream>
# include <iostream>
# include <algorithm>
# include <cmath>
# include <utility>
# include <climits>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
// a = -7 9 8 3 1 1, target = 18
//        -
//     -7 1 1 3 8 9
//              > <
// a = 5 2 7 5, target = 13
//       -
//     2 5 5 7
//     >     <
////////////////////////////////////////////////////////////////
// 新しいウインドウ(W)
ostream& operator <<( ostream& _ , const vector <int> &vec ){
    _ << '[';
    if( vec.size()){
        _ << ' ';
        for( int y: vec ){
            _ << y << ' ';
        }
    }
    return _ << ']';
}
////////////////////////////////////////////////////////////////
// > あそこ に 銀行　 が あります。
// + あそこ に 図書館 が あります。
// - あそこ に 病院　 が あります。
// : あそこ に 喫茶店 が あります。
// ^ あそこ に 猫　　 が あります。
////////////////////////////////////////////////////////////////
class Solution {
private:
    static pair <int,int> closest( const vector <int> &a,
                                   int target,
                                   int anchor ){
        // a=[-7,1,1,3,8,9],target=2,anchor=4
        target -= a[ anchor ];// target=-6
        int mindif = INT_MAX;
        int maxsum = 0;
        int i = 0;
        int j = a.size() - 1;// j=6
        while( i < j ){
            if( i == anchor ){ ++i; continue; }
            if( j == anchor ){ --j; continue; }
            int sum = a[ i] + a[ j];// sum=2,10
            int dif = target - sum;// dif =-8
            if(      dif == 0 ){ return { dif, sum };}
            else if( dif  < 0 ){ --j; }// i=1
            else { ++i; }
            dif = abs( dif );// dif=8
            if( mindif  > dif ){
                mindif = dif;// mindif=8
                maxsum = sum;// maxsum=2( BUG FOUND )
            } else
            if( mindif == dif ){
                maxsum = max( maxsum, sum );
            }
        }
        return { mindif, maxsum };
    }
public:
    // a=[-7,9,8,3,1,1],target=2
    static int threeSumClosest( vector <int> &a, int target ){
        sort( a.begin(), a.end());
        // a=[-7,1,1,3,8,9]
        int mindif = INT_MAX;
        int maxsum = 0;
        for( int anchor = a.size() - 2; anchor > 0; --anchor ){
            // anchor=4
            auto p = closest( a, target, anchor );
            int dif = p.first;
            int sum = p.second + a[ anchor ];
            if( mindif  > dif ){
                mindif = dif;
                maxsum = sum;
            } else
            if( mindif == dif ){
                maxsum = max( maxsum, sum );
            }
        }
        return maxsum;
    }
};
////////////////////////////|/| /|  /|   /|    /|     ////////// 
/////////////////////////// / |/ | / |  / |   / |    ///////////  
////////////////////////// /  /  |/  | /  |  /  |   ////////////
///////////////////////// /  /   /   |/   | /   |  /////////////
int main(){int t;cin>>t;while(t--){cin.ignore();vector <int>arr;
string input; getline( cin, input); stringstream ss( input); int 
number;while(ss>>number){arr.push_back(number);}int key;cin>>key
;Solution ob;cout<<ob.threeSumClosest(arr,key)<<endl;}}/////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                1115 / 1115
// Points Scored:                                          4 / 4
// Your Total Score:                                        1866 
// Time Taken:                                               0.2
// 1.4.18*: A boy who can swim with speed two times less then
// the speed of a river, want to swim to the other shore so that
// the river carries him away as less as possible. At what angle
// with respect to the shore he must swim? At what distance he
// will be carried away if the width of the river is 200m?
//
// When the river is still the boy should swim perpendicular to
// the shore so at first sight it seems that with respect to the
// system moving alongside the river the boy should swim
// perpendicular to the shore, but that's wrong. So this problem
// is like a previous problem about a decaying nucleus; the
// boy can swim in all directions with velocity v, the edge of
// the vector will form a circle:
//    . .    if to every position of v we add the velocity of
//  .     .  the river u = 2v as vector we'll translate the
// .       . circle at distance u:                . .B    . .
// .   `   . So the velocity of the boy will    .     . .     .
//  .  O  .  have one end at O and the other   .       .       .
//    . .    will be any point of circle D, so .   `T  .   `O  .
//       C   the carry will be minimum if the   .     . .     .
//           angle TOB is maximum that is when  D . .   C . .
// TBO is 90°, so for the angle the boy should swim α := BTO, we
// have: cosα = BT/TO = 1\2, zo α = 60° to find the displacement
// x we can see that the boy will swim in direction OB with
// β := TOB = 30°:
// ==================================, zo tgβ = w|x
//      `          x        |          x = wctβ = √(3)200m ≈
//          `               |          ≈ 346m                  «
//              `           | w
//                  `       |
//                   β  `   |
// =========================`========
////////////////////////////////////////////////////////////////
