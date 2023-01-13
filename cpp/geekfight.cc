////////////////////////////////////////////////////////////////
// _    _
// _    _  _       _ _     _    _    _        _ _        _
// _       _     _       _  _         _    _    _    _     _
// _      _   _   _    _      _   _     _  _    _  _     _  _
// _    _   _        _      _     _  _
// `   `   `        `     `    `    `  `   `        `     `
// `  `       `    `    `   `    `     `     `    `  ` `
// `     `    `     `  `   `    `      `  `     `  `     `
// `      `  `        `  `   `    `  `    `     `   `     `   `
// `     `       `   `   `    `
// Geek fight
// Geek is playing a video game that contains N monsters having
// varying power denoted by power[i]. Geek will play total Q
// rounds and for each round, the power of Geek is Q[i]. He can
// kill all monsters having power <= Q[i].
// All the monsters which were dead in the previous round will
// be reborn, such that for each round there will be N monsters.
// Since Geek wants to win each round, he wants to count the
// number of monsters he can kill in each round and total sum of
// their powers. Can you help him?
////////////////////////////////////////////////////////////////
// Example:                                                    1
// Input:                                                  N = 7
//                              powers[] = {1, 2, 3, 4, 5, 6, 7}
//                                              Q[] = {3, 10, 2}
// Output:                             {{3, 6}, {7, 28}, {2, 3}}
// Explanation:  1. For round 1, Geek has power 3, hence, it can
//    kill the monsters with power 1, 2 and 3. Hence, count is 3
//                                 and total sum = 1 + 2 + 3 = 6.
// 2. For round 2, Geek has power 10, hence, it can kill all the
// monsters. Hence, count is 7 and total sum =
// 1 + 2 + ... + 7 = 28.
// 3. For round 3, Geek has power 2, hence, it can kill the
// first two monsters. Hence, count is 2 and total sum =
// 1 + 2 = 3.
////////////////////////////////////////////////////////////////
// Your Task: You don't need to read input or print anything.
// Your task is to complete the function win() which takes an
// array of size N and another array of size Q and return list
// of pairs as output.
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(N)
////////////////////////////////////////////////////////////////
# include <vector>        // vector
# include <iostream>      // cout
# include <utility>       // pair
# include <algorithm>     // sort
# include <unordered_map> // what is this?
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
typedef pair   < int, int > Pair;
typedef vector <      int > Vector;
typedef vector <     Pair > List;
////////////////////////////////////////////////////////////////
class Solution {
public:
    List win( Vector& power, int oo, Vector& Q, int ox );
};
////////////////////////////////////////////////////////////////
List Solution::win( Vector& power, int oo, Vector& Q, int ox ){
// 1. Sort power vector,
    sort( power.begin(), power.end());
//    If in a given round The Geek has power x, after this we can
//    use binary search to found the monsters with powers <= x
//    for O(log( N )).    
// 2. Backup Q, append 0 and sort it
    auto Q1{ Q };
    Q.push_back( 0 );
    sort( Q.begin(), Q.end());
//    The idea of the zero guard is to avoid duplicates in Q by
//    checking vheter current element is equal to the previous one,
//    also becasue now Q is in increasing order we can calculate
//    the sum without recalculating the lower terms.
// 3. Create map: Geek power -> ( Nf Monsters, Total Sum ).
//    Initialize the variables sum and it.
    unordered_map < int, Pair > tab;
    int sum{};
    auto it{ power.begin() };
//    Because the output list is per round, that is in Q1 order,
//    when looping over Q we save the results in a fast hash table
//    for later retrieval.
// 4. Start looping Q from the second element( skipping the fyorst ).
    for( int k = 1, n = Q.size(); k < n; ++k ){
// 5.     Check for duplicates
        if( Q[k] == Q[k - 1] ) continue;
// 6. Using binary search, find first j: Q[k] < power[j]
        auto pilot{ upper_bound( it, power.end(), Q[k] )};
//        upper_bound is a shortcut library function
// 7. update sum for all elements in the range [ it, pilot )
        while( it != pilot ) sum += *it++;
// 8. Save the result to the hash table map,
        tab[ Q[k] ] = Pair( pilot - power.begin(), sum );
//        Thats not going to work!,:)
    }
// 9. Get the result
    List result;
    for( auto y: Q1 ) result.push_back( tab[ y ]);
// 10. Get out
    return result;
}
////////////////////////////////////////////////////////////////
int main() {
    Vector   power{ 1, 7, 3, 4, 5, 6, 2 };
    Vector   Q{              3,   10, 2 };
    Solution ob;
    for( auto it: ob.win( power, -1, Q, -1 )){
        cout << it.first << " " << it.second << endl;
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                  150 / 150
// Total Points Scored:                                    4 / 4
// Your Total Score:                                         986
// Total Time Taken:                                        0.23
// Your Accuracy:                                           100%
// Attempts No.:                                               1
////////////////////////////////////////////////////////////////
