//   `   `   `   `   `   `   `   `   `   `   `   `   `####
//````````````/\  `   `   `   `   `   `   `   `   `#######
//           / /   `   `   `   `   `   `   `   `##########
//````````/\/ /`/\  `   `   `   `   `   `   `#############
//````````\  / /  \  `   `   `   `   `   `################
//````````/  \/ /\ \  `   `   `   `   `###################
//       / /\  / /  \  `   `   `   `######################
//      / / /  \/ /\ \``/\  `   `########||##|||#||||#####
//``````\/ / /\  / / / / /   `##########|  #|   # |  #####
//        / / /  \/ / / / `############# ||# || #  #######
//````````\ \/ /\  / / /#########    ####  ##   # ########
//         \  / /  \/ /#########    ######################
//          \ \/ /\  /#########    ##                ##   
//           \  / /  \########    ##    \\    \\    ##    
//            \/ / /\ \######    ##    ##    ##    ##    #
//````````````` / /  \/                                   
//             / /````\\\\\    \\    \\    \\    \\    \\\
//            / /######\\\    ##    ##    ##    ##    ##\\
//````````````\/########\    ##                ##    ####\
//`````````````#########    ###\\\\\\\\\\\\\\\\##\\\\#####
//#####################    #####\\\\\\\\\\\\\\\\##\\\\####
//#####################\\\\######\\\\\\\\\\\\\\\\##\\\\###
//  N-Queen Problem, 車、kuruma, くるま
//////////////////////////////////////////////////////////
// The n-queens puzzle is the problem of placing n queens
// on a (n×n) chessboard such that no two queens can
// attack each other. Given an integer n, find all
// distinct solutions to the n-queens puzzle. Each
// solution contains distinct board configurations of the
// n-queens’ placement, where the solutions are a
// permutation of [1,2,3..n] in increasing order, here the
// number in the ith place denotes that the ith column
// queen is placed in the row with that number. For
// example below figure represents a chessboard [3 1 4 2].
//////////////////////////////////////////////////////////
// [ _ q _ _ ]
// [ _ _ _ q ]
// [ q _ _ _ ]
// [ _ _ q _ ]
//////////////////////////////////////////////////////////
// Input: 1 Output: [1]
// Explaination: Only one queen can be placed in the
// single cell available.
//////////////////////////////////////////////////////////
// Input: 4 Output: [2 4 1 3 ] [3 1 4 2 ]
// Explaination: These are the 2 possible solutions.
//////////////////////////////////////////////////////////
// Expected Time Complexity: O(n!)
// Expected Auxiliary Space: O(n2) 
//////////////////////////////////////////////////////////
// 1 ≤ n ≤ 10 
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
/// Albreht Dürrer hat sich in seinem Dresdner Skizzenbuch
////////// um die Formeneinfachheit durch Einschreibung in
/////////////////// stereometrische Figuren bemüht (l.o.). 
//////////////////////////////////////////////////////////
// Skizzenbuch - sketchbook
// stereometrische - stereo-metric
// bemüht - engaged
// l.o.( links oben ) - top left
// schreiben - write
// einfach - simple
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
// return array of size n filled with zeroes
function cons( n ){
    return Array( n ).fill( 0 );
}
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
// außerdem noch etwas? - anything else?
// Ich hätte gern - I would like
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
class Solution {
    nQueen( n ){
        // make array for tagging the horizontal positions
        // of the queens
        this.hrz = cons( n );
        // if we have n x n square then the number of the
        // diagonals of given direction is 2 * n - 1
        const NDIAG = 2 * n - 1;
        // create marking arrays for queens' diagonals
        this.diagu = cons( NDIAG );
        this.diagv = cons( NDIAG );
        // make array for the current board position
        this.board = cons( n );
        // finally make array for all board positions
        this.all = [];
        // call the dfs function that will do the job
        this.dfs( 0 );
        // return the obtained result
        return this.all;
    }
    // this is the backtracking function, basically it's
    // a recursive for loop, that examines all variants
    dfs( x ){
        const n = this.board.length; // shortcut
        // check if done, x here is the board column
        if( x == n ){
            // push to all copy of the current board
            this.all.push( this.board.slice());
        }
        // loop over all rows, and check if we can put a
        // queen there
        for( let y = 0; y < n; ++y ){
            // add n - 1 so u can't be negative
            const u = n - 1 + y - x;
            const v = y + x;
            // check if there are queens on the same
            // horizontall or diagonals
            if( this.hrz[ y   ] ||
                this.diagu[ u ] ||
                this.diagv[ v ] ){
                continue;
            }
            // Marky Mark
            this.board[ x ] = y + 1;
            this.hrz[ y   ] = 1;
            this.diagu[ u ] = 1;
            this.diagv[ v ] = 1;
            // go to next level
            this.dfs( x + 1 );
            // undo
            this.board[ x ] = 0;
            this.hrz[ y   ] = 0;
            this.diagu[ u ] = 0;
            this.diagv[ v ] = 0;
        }
    }
}
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
////  0,0      x               givn x,y
////   +- - - - - - - - - - +  find u,v
//// u .       |            |\ y-u=x, u=y-x
////   | .     |            |  v-y=x, v=y+x
////   |   .   |            |  zo u,v can represent
////   |     . |            |  diagonal coordinates, and
//// y | - - - +            |  used to check if two queens
////   |     `              |  have same diagonals.
////   |   `                |      \
////   | `                  |       \
//// v `                    |        \
////   + - - - - - - - - - -+         \
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
// ki, き、木、tree, wood
// ano ki wa totemo ooki desu ne
// あの｜き｜は｜とても｜大きい｜です｜ね。
// That tree is really big, isn't it?
// 
// moku, もく、tree, wood
// mokuyoobi ni kaimono imashoo
// 木よう日｜に｜かいもの｜いましょう。
// Let's go shopping on Thursday.
//
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
console.log( new Solution().nQueen( 4 ));
//////////////////////////////////////////////////////////
// (1) sono pen wa nihyakujyu en desu
//     その｜ペン｜は｜にひゃくじゅう｜えん｜です。
// (2) ano konpyuuta wa rokumanhassen en desu
//     あの｜コンピューたー｜は｜ろくまんはっせん｜えん｜です。
// (3) sono saifu wa yonsensanpyaku en desu
//     その｜さいふ｜は｜よんせんさんぴゃく｜えん｜です。
// (4) kono jishyo wa sanzengohyaku en desu
//     この｜じしょ｜は｜さんぜんごひゃく｜えん｜です。
// (5) ano jitensha wa ichimannanasen en desu
//     あの｜じてんしゃ｜は｜いちまんななせん｜えん｜です。
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
// Test Cases Passed:                              10 / 10
// Total Points Scored:                              8 / 8
// Your Total Score:                                  1598
// Total Time Taken:                                  0.06
