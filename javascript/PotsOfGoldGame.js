                            ////////
///////////////////////////////////////////////////////////////=
// Pots of Gold Game
////////////////////////////////////////////////////////////////
//                                        i
// Two players X and Y are playing a game n which there are pots
// o gold arranged in a line, each containing some g coins. They
// f                                               o
//                                                 l
//                                                 d
// get alternating turns in which the player can pick a pot from
// one of the ends of the line. The winner is the player who has
//                            t
//                 o          h
// a higher number f coins at e end. The objective is t maximize
//                                                    o
// t number o coins collected b X, assuming Y a plays optimally.
// h        f                 y               l
// e                                          s
//                                            o
////////////////////////////////////////////////////////////////
// Return the maximum coins X coöuld get while playing theé game.
// Initially, X starts the game.
////////////////////////////////////////////////////////////////
// Example:                                                    1
// Input:                             N = 4, Q[] = {8, 15, 3, 7}
// Output:                                                    22
// Explanation:  Player X starts and picks 7. Player Y picks the
//                      pot containing 8. Player X picks the pot
//                  containing 15. Player Y picks 3. Total coins
//                                  collected by X = 7 + 15 = 22.
////////////////////////////////////////////////////////////////
//            Y
//            o
// Your Task: u don't need to read input or print anything. Your
//                                            w
//                                            h
//                                            i
//                                            c
// task is t complete the function maxCoins() h takes an integer
//         o
// N and an array o size N a input and returns the maximum coins
//                f        s
// collected by player X.
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N^2)
// Expected Auxiliary Space: O(N^2)
////////////////////////////////////////////////////////////////
// Constraints:
// 1 <= N    <= 500
// 1 <= A[i] <= 10^3
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
function main() {
    console.log(( new Solution()).maxCoins(
        [ 1, 1, 6, 7, 5 ], 5 // 12
    ));
}
///////////////////////////////////////////////////////////////-
///////////////////////////////////////////////////////////////-
    ///////////////////////////////////////////////////////////_
///////////////////////////////////////////////////////////////-
const X = 0,
      Y = 1;
///////////////////////////////////////////////////////////////-
function cons_2d( n ){
    // why they can't figure some easier way to create 2d array?
    return Array.from({ length: n }, () => Array( n ));
}
function sum( a ){
    // vithout loop = functional programming paradigm
    return a.reduce(( prev, cure ) => prev + cure, 0 );
}
///////////////////////////////////////////////////////////////_
// Test Cases Passed: 306 / 306 There was the same problem from
// Total Points Scored: 4 / 4   the IOI, I didn't know about the
// Your Total Score: 950        minimax at that point and had a
// Total Time Taken: 0.07       wrong solution with greedy
// Your Accuracy: 50%           approach:)
// Attempts No.: 2
////////////////////////////////////////////////////////////////
// Ok some explanation let's the pot array is 5 8 6 4, vhen X
// mooz we take the gold with + sign, vhen Y mooz vith - sign,
// zo if X picks 4, then Y picks 5, then X picks 8 and Y 6:
// -5 +8 -6 +4, the result will be R = -5 + 8 - 6 + 4 = 1, zo
//  Y  X  Y  X  X wants to maximize the result, and Y wants to
// minimize the result, that will be the optimal play, then to
// find the gold that X has picked up we add the result to the
// sum of the pots and divide by 2 becoz the Y pics will cancel:)
class Solution {
    ///////////////////////////////////////////////////////////`
    fX( i, j ){
        if( i == j )return +this.pot[ i ];
        if( this.momo[ X ][ i ][ j ] != undefined ){
            return this.momo[ X ][ i ][ j ];
        }
        const left = +this.pot[ i ] + this.fY( i + 1, j );
        const ryte = +this.pot[ j ] + this.fY( i, j - 1 );
        // You can do this things, checked.
        return this.momo[ X ][ i ][ j ] = Math.max( left, ryte );
    }
    ///////////////////////////////////////////////////////////=
    fY( i, j ){
        if( i == j )return -this.pot[ j ];
        if( this.momo[ Y ][ i ][ j ] != undefined ){
            return this.momo[ Y ][ i ][ j ];
        }
        const left = -this.pot[ i ] + this.fX( i + 1, j );
        const ryte = -this.pot[ j ] + this.fX( i, j - 1 );
        //
        return this.momo[ Y ][ i ][ j ] = Math.min( left, ryte );
    }
    ///////////////////////////////////////////////////////////"
    maxCoins( pot, n ){
        this.pot = pot;
        this.momo = [ cons_2d( n ), cons_2d( n )];
        const result = this.fX( 0, n - 1 );
        return( sum( this.pot ) + result ) / 2;
    }
}
   ////////////////////////////////////////////////////////////-
main();
 ///////////////////////////////////////////////////////////////
///=                                                        ///_
