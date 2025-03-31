////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Count distinct elements in every window
////////////////////////////////////////////////////////////////
// Given an integer array arr[] and a number k. Find the count 
// of distinct elements in every window of size k in the array.
////////////////////////////////////////////////////////////////
// Input: arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
// Output:  [3, 4, 4, 3]
////////////////////////////////////////////////////////////////
// 1 <= k <= arr.size() <= 10^5
// 1 <= arr[i] <= 10^5
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int t = int.Parse( Console.ReadLine());
Console.WriteLine( t );
while( t-- > 0 ){
	int[] a = Console.ReadLine()
		             .Split( ' ' )
		             .Select( int.Parse )
		             .ToArray();
	Console.WriteLine( " " + string.Join( " ", a ));
	int k = int.Parse( Console.ReadLine());
	Console.WriteLine( " " + k );
    
    Solution solution = new Solution();
    var result = solution.countDistinct( a, k );

    Console.WriteLine( string.Join( " ", result ));
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// [ Algorithm ]
// a - array of integers
// k - window size
// => list of unique counts for all windows
// -------------------------------------------------------------
// [ 1. Initialize ]
// f := Create frequency mapping ( key => count ), where key are
// values from the array a and fill f with first k values
// i := 0
// j := k
// counts := [ len( f.keys )]
// [ 2. Check j ]
// if j >= len( a ), goto [ 5. Exit ]
// [ 3. Advance ]
// Decrease key=a[i] count, if it turns nil, remove the key
// Increase key=a[j] count, add a key if not existing
// counts.add( len( f.keys ))
// [ 4. Loop ]
// i <- i + 1
// j <- j + 1
// goto 2
// [ 5. Exit ]
// return counts
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Solution {
    public List <int> countDistinct( int[] a, int k ){
        // [ 1. Initialize ]
        var f = new Dictionary <int,int> ();
        int i = 0;
        int j = 0;
        for(; j < k; ++j ){
            int key = a[ j ];
            if( f.ContainsKey( key )){
                f[ key ]++;
            } else {
                f[ key ] = 1;
            }
        }
        var cons = new List <int> { f.Count }; // COuNtS
        // [ 2. Check j ]
        while( j < a.Length ){
            // [ 3. Advance ]
            int key = a[ i ];
            if( --f[ key ] == 0 ){
                f.Remove( key );
            }
            key = a[ j ];
            if( f.ContainsKey( key )){
                f[ key ]++;
            } else {
                f[ key ] = 1;
            }
            cons.Add( f.Count );
            // [ 4. Loop ]
            ++i;
            ++j;
        }
        // [ 5. Exit ]
        return cons;
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                1111 / 1111
// Points Scored:                                          4 / 4
// Your Total Score:                                        1902 
// Time Taken:                                               0.1 
// 1.2.3. Decide which of the following represent true 
// statements about the nature of sets. For any that are false, 
// provide a specific example where the statement in question 
// does not hold.
// (a) If A(1)⊇A(2)⊇A(3)⊇A(4) ... are all sets containing an 
// infinite number of elements, then the intersection ⋂A(n) is 
// infinite as well
//
// So if we take A(n) as in the text to be the natural numbers 
// greater or equal to n: A(n) = { n, n + 1, ... }, one could 
// argue that the intersection, say Cross, is the empty set, be 
// cos if m is an element of Cross, it must be an element of all
// sets A(j), but it obviously is not in A(m + 1). So we can't 
// write a single number that belongs to Cross, but how about 
// numbers that we can't write anyway like infinetly many nines:
// 999999999999999999999999999999999999999999999.., or
// 14343434348491783589656555.., not to mention
// 239434396967559568596555555585039393.., that continues
// forever, I mean these are clear candidates, in real numbers
// like 0.94554474.. and 0.54384434.. we also have infinite
// expansions, and we can say 0.94554474.. > 0.54384434.., 
// but can we say 94554474.. > 54384434.., and what is
// 949414814348438034.. + 1? So, it seems that all these 
// infinite sequences are simply not numbers, but let's say 
// represent the many faces of the infinity
// (b) ......
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
