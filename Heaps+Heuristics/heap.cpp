#include <cmath>
#include "heur.h"
#include <vector>
#include <set>
using namespace std;

// Complete
size_t BFSHeuristic::compute(const Board& b)
{
    return 0U;
}


// To be completed
size_t DirectHeuristic::compute(const Board& b)
{
    // Avoid compiler warnings -- replace this
    return 0;
    //start at right edge of a car, then loop until end of the row, and count the number of vehicles from there
    //get escape vehicle
    const Vehicle& escape_id = b.escapeVehicle();
    int start_row = escape_id.startr;
    int start_col = escape_id.startc;
    //loop from end of espace vehicle to end of grid
    int count =0 ;
    for(int i = start_col+escape_id.length; i < b.size(); i++ ){
        if(b.at(start_row, i) != Vehicle::INVALID_ID){
            count++;
        }
    }
    
    return count;



}

// To be completed
size_t IndirectHeuristic::compute(const Board& b)
{
    //for every direct blocking vehicle, see if ignoring every other vehicle, if it can move both up and down to clear, then its not indirect
    //so, to be indirect, the direct vehicle can only ever move in one direction, so the 
    // Avoid compiler warnings -- replace this

    //write a lot of helper functions
    //b can only move in 1 direction, so need a helper function, can b move upward?
    //  check if b can move upward: , 0+ b length, is it less or equal to than the row of the escape vehicle?
    //can b move down? is length of b less than equal to escape vehicle row - length of grid
    //grid size - length of b stricly greater than escape vehicle row
    //if can move up != can move down

    

    return 0;
}

