//////////////////////////////////////////////////////////////// ------
// LRU Cache                                                     ------
// Medium Accuracy: 22.68% Submissions: 100k+ Points: 4          ------
//////////////////////////////////////////////////////////////// ------
// Design a data structure that works like a LRU Cache. Here cap ------
// denotes the capacity of the cache and Q denotes the number of ------
// queries. Query can be of two types:                           ------
//////////////////////////////////////////////////////////////// ------
// SET x y : sets the value of the key x with value y            ------
// GET x : gets the key of x if present else returns -1.         ------
//////////////////////////////////////////////////////////////// ------
// The LRUCache class has two methods, get() and set() which are ------
// defined as follows:                                           ------
//////////////////////////////////////////////////////////////// ------
// get(key): returns the value of the key if it already exists i N-----
// the cache otherwise returns -1.                               ------
// set(key, value) : if the key is already present, update its v ALUE.-
// If not present, add the key-value pair to the cache. If the c ACHE--
// reaches its capacity, it should invalidate the least recently ------
// used item before inserting the new item.                      ------
//////////////////////////////////////////////////////////////// ------
// In the constructor of the class the capacity of the cache sho ULD---
// be intitialized.                                              ------
//////////////////////////////////////////////////////////////// ------
// Example,                                                      ------
// Input:                                                        ------
// cap = 2                                                       ------
// Q = 8                                                         ------
// Queries =                                                     ------
// SET 1 2 SET 2 3 SET 1 5 SET 4 5 SET 6 7 GET 4 SET 1 2 GET 3   ------
// Output: 5 -1                                                  ------
// Explanation:                                                  ------
// Cache Size = 2                                                ------
// SET 1 2: 1 -> 2                                               ------
// SET 2 3: 1 -> 2, 2 -> 3 (the most recently used one is kept a T-----
// the rightmost position)                                       ------
//////////////////////////////////////////////////////////////// ------
// SET 1 5: 2 -> 3, 1 -> 5                                       ------
// SET 4 5: 1 -> 5, 4 -> 5 (Cache size is 2, hence we delete the ------
// least recently used key-value pair)                           ------
// SET 6 7: 4 -> 5, 6 -> 7                                       ------
// GET 4: Prints 5 (The cache now looks like 6 -> 7, 4->5)       ------
// SET 1 2: 4 -> 5, 1 -> 2 (Cache size is 2, hence we delete the ------
// least recently used key-value pair)                           ------
// GET 3 : No key value pair having key = 3. Hence, -1 is printe D.----
//////////////////////////////////////////////////////////////// ------
// Your Task: You don't need to read input or print anything. Co MPLETE
// the constructor and get(), set() methods of the class LRUcach E.---- 
//////////////////////////////////////////////////////////////// ------
// Expected Time Complexity: O(1) for both get() and set().      ------
// Expected Auxiliary Space: O(1) for both get() and set().      ------
// Although, you may use extra space for cache storage and imple----+ -
//////////////////////////////////////////////////////////////// -- | -
// Constraints:                                                  -- | -
// 1 <= cap <= 1000                 +-------------------------------+ -
// 1 <= Q <= 100000                 |                            ------
// 1 <= x, y <= 1000                +------>mentation purposes). ------
//////////////////////////////////////////////////////////////// ------
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
////////////////////////////////////////////////////////////////
public class LRUDesign {
public static void main(String[] args) throws IOException {
BufferedReader read =
new BufferedReader(new InputStreamReader(System.in));
int t = Integer.parseInt(read.readLine());
while (t-- > 0) {
int capacity = Integer.parseInt(read.readLine());
int queries = Integer.parseInt(read.readLine());
LRUCache cache = new LRUCache(capacity);
String str[] = read.readLine().trim().split(" ");
int len = str.length;
int itr = 0;
for (int i = 0; (i < queries) && (itr < len); i++) {
String queryType = str[itr++];
if (queryType.equals("SET")) {
int key = Integer.parseInt(str[itr++]);
int value = Integer.parseInt(str[itr++]);
cache.set(key, value);
}
if (queryType.equals("GET")) {
int key = Integer.parseInt(str[itr++]);
System.out.print(cache.get(key) + " ");
}
}
System.out.println();
}
}
}
////////////////////////////////////////////////////////////////
class Link {
    int  key;
    int  value;
    Link prev;
    Link next;
    // , , , , , , , , , , , , , , , , , , , , , , , , , , , , ,
    Link( int key, int value ){
        this.key   = key;
        this.value = value;
    }
    void dance() {
        prev.next = next;
        next.prev = prev;
    }
}
////////////////////////////////////////////////////////////////
class LRUCache {
    static final int TABSIZ = 1001;
    // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    final int cap;
    // .........................................................
    int size;
    // ---------------------------------------------------------
    Link ahead; // á - [hè:] - e - e - ð
    // Every key is an index here.
    Link tab[] = new Link[ TABSIZ ];
    // , , , , , , , , , , , , , , , , , , , , , , , , , , , , ,
    LRUCache( int cap ){
        this.cap   = cap;
        ahead      = new Link( 0, 0 );
        ahead.next = ahead;
        ahead.prev = ahead; // ahead.prev points to most recent
    }
    void print( String title ) {
        var b = new StringBuilder( title );
        b.append( String.format( "size/cap = %d/%d, ", size, cap ));
        for( Link f = ahead.next; f != ahead; f = f.next ){
            b.append( String.format("(%d,%d) ", f.key, f.value ));
        }
        System.out.println( b.toString() );
    }
    void add( Link f ){ // check this out
        ahead.prev.next = f;
        f.next          = ahead;
        f.prev          = ahead.prev;
        ahead.prev      = f;
    }
    public int get( int key ){
        Link f = tab[ key ];
        if( f == null ) return -1;
        f.dance();
        add( f );
        return ahead.prev.value;
    }
    public void set( int key, int value ){
        Link f = tab[ key ];
        if( f == null ){
            f = new Link( key, value );
            tab[ key ] = f;
            if( size < cap ){
                ++size;
            } else {
                Link lru = ahead.next;
                lru.dance();
                tab[ lru.key ] = null;
            }
        } else {
            f.value = value;
            f.dance();
        }
        add( f );
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 340 / 340
// Total Time Taken: 2.65
////////////////////////////////////////////////////////////////
