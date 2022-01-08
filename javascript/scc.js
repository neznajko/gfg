#!                                             /usr/bin/env node
////////////////////////////////////////////////////////////////
// Given a Directed Graph wit V vertics (Numbered from 0 to V-1)
// and E edges, Find the number of strongly connected components
// in the graph.
'use strict'; // becoz there is no -pedantic
//////////////////////////////////////////////////// DRIVER CODE
process.stdin.resume();              // 
process.stdin.setEncoding( 'utf-8'); //

let inputString = '';
let currentLine = 0;

process.stdin.on( 'data', inputStdin => {
    inputString += inputStdin;
});
process.stdin.on( 'end', _ => {
    inputString = inputString.trim().split( '\n').map( string => {
        return string.trim();
    });
    main();    
});
function readLine() {
    return inputString[ currentLine++];
}
function main() {   
    let t = parseInt( readLine());
    let i = 0;
    for(; i < t; i++) {
        let input_ar0 = readLine().split( ' ').map( x => parseInt( x));
        let v = input_ar0[ 0];
        let e = input_ar0[ 1];
        let arr = [];
        let obj = new Solution();
        for( let i = 0; i < e; i++) {
            let input_line = readLine().split( ' ');
            arr.push( input_line);
        }
        let ans = obj.kosaraju( arr, v, e);
        console.log( ans);
    }
}
////////////////////////////////////////////////////////////////
class Solution { // Reverse topological sorting and more ..
    kosaraju( grr, V, notUsed) { // Dasgupta et al.[ Chapta 3]
        // construct graph in adjacency list format
        let f = Array.from({ length: V}); // That will create
        // array with size V full of undefined values;
        this.g = f.map( u => []); // Here it's important to use
        // map rather than fill, becos it will clone the same
        // stuff that is references to same object.
        this.r = f.map( v => []); // reversed graph
        for( const [ u, v] of grr) { // They have to make a song
            this.g[ u].push( v);     // Const It Be!
            this.r[ v].push( u);     // .. const it be-e-e..-e.
        }
        // uncomment at your own risk
        // console.log( this.g);
        // console.log( this.r)
        // [ ok] make reverse topological sort
        this.vizted = f.fill( false); // visited nodes
        this.ls = []; // thats the desired dfs order( reversed)
        this.rtopsort(); // now ls has to be full
        this.vizted = f.fill( false); // reset
        // console.log( this.ls)
        // automatic comment from ai bot:
        // [20:31] - What the geek is going on here?
        return this.scc();
    }
////////////////////////////////////////////////////////////////
    rtopsort() { // reverse topological sort
        for( let j = 0; j < this.r.length; j++) {
            if(! this.vizted[ j]) this.rexplore( j);
            // If not visited reverse explore j node.
        }
    }
    rexplore( j) {
        this.vizted[ j] = true; // mark as visited
        for( const u of this.r[ j]) {
            if(! this.vizted[ u]) this.rexplore( u);
            // recursivly explore non-visited nodes
        }
        this.ls.push( j); // post action( that's the sort)
    }
    scc() { // Strongly Connected Component
        let cc = 0;
        // post descending order( mua-ha-ha)
        for( let j = this.ls.length - 1; j > -1; j--) {
            const u = this.ls[ j]; // copy
            if(! this.vizted[ u]) {
                this.explore( u);
                cc++;
            }
        }
        return cc;
    }
    explore( u) { // str8 graph
        this.vizted[ u] = true;
        for( const v of this.g[ u]) { 
            if(! this.vizted[ v]) this.explore( v);
        }
    }
}
////////////////////////////////////////////////////////////////
// log: - What do you think, about thoughts like -NOW-OR-NEVER-,
// -DO-OR-DO-NOT-, etc.?, and I'm not asking whether you've gave
// up lifting shampoos in the bathroom,, but how do you approach
// things in general e.g. when you want to change your life stop
// smoking start training do you say NOW OR NEVER, DO OR DO NOT,
// or you say: Let's give it a try?
// - Total Time Taken: 0.6/1.0
////////////////////////////////////////////////////////////////
////                                                        ////
