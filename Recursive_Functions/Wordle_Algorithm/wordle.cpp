// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#include "wordle.h"
#include "dict-eng.h"

using namespace std;


// Add prototypes of helper functions here
std::set<string> word_gen(const std::string& in, const std::string& floating, std::string& prefix);
bool isrealword( const std::string& in, const std::set<std::string>& dict);



// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    // Add your code here
    std::set<string> new_word;
    if(in == ""){
        return new_word;

    }


    //base case: 1 letter word
    
    std::string empty = "";
    new_word = word_gen(in, floating, empty);

    
    std::set<string> final_words = {};
    for(std::set<string>::iterator it = new_word.begin(); it != new_word.end(); it++){
        
        if(isrealword(*it, dict) == true){
            final_words.insert(*it);

        }
        
    }

    return final_words;

    //-i-- dn
    //youre going to 

    //or is it like for each spot, you check if 

    //call word_gen

    //run output through isrealWord

    //iterate through set, add it to a new set if true, else remove, then print out all sets
  
}


// Define any helper functions here


//need a function to see if the modified in is a word
bool isrealword(const std::string& in, const std::set<std::string>& dict){
    //maybe iterate through dict?

    if(dict.find(in) != dict.end()){
        return true;
    }
    else{
        return false;
    }
   
}

//helper that generates all the words
//will return all possible combinations of letters
std::set<string> word_gen( const std::string& in, const std::string& floating, std::string& prefix){
    
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::set<string> newword;

    //base case 1
    

    //base case 2: word is one letter
    //check you only need to guess "one more"
    //the options, could use the letter given to you by in, the letter given by floating, and an alphabet
    if((in.size() - prefix.size()) == 1){
        //means you have one more to guess
        int in_size = in.size();
        if(floating.size() == 1){
        //so letter has to be one of the floating
            std::set<string> recword = {prefix+floating};//check syntax bc wtf
            return recword;
        }
        
        else if(in[in_size-1] != '-'){
            std::set<string> newword1 = {prefix+in[in_size-1]};
            return newword1;

        }
        else{
            std::set<string> alph = {};
            for(int i = 0; i < 26 ; i++){
                alph.insert(prefix+alphabet[i]);

            }
            return alph;
        }

    }
    else{
        //word longer than 1 letter
        //check if theres a fixed letter
        //
       
        

        int pref_size = prefix.size();
        long unsigned int dash_count = std::count(in.begin()+pref_size, in.end(), '-');
       
        if(in[pref_size] != '-'){
            //then 
            prefix.push_back(in[pref_size]);
            newword = word_gen(in, floating, prefix);

            //concatenate the sets witrh the set property.

        }

        else if(floating.size() == dash_count){
            //loop through floating 
           // std::cout<<"here" << std::endl;
            for(long unsigned int i = 0; i < floating.size(); i++){
               
                char temp = floating[i];
                const string temp_floating = floating.substr(0,i) + floating.substr(i+1,-1);//-1 means to the end of the string. 
                string temp_string = prefix;
                temp_string.push_back(temp);
                std::set<string> temp_set =  word_gen(in, temp_floating, temp_string);
                newword.insert(temp_set.begin(), temp_set.end());

            }
            //at each step in recusion, figure out every possible letter in the spot, similar 3 conditions as in basecase of like floating, in 
            //rememebr when recursing, remove floating letter from floating
        }
        else{
            //make sure alphabet[i] not in floating to avoid duplicate.
           // std::cout<<prefix<<std::endl;
            for(int i = 0; i < 26; i++){
                    
                    int floating_ind = floating.find(alphabet[i]);
                    if(floating_ind != -1){
                        //alphabet[i] was found at some point
                        char temp = floating[floating_ind];
                        const string temp_floating = floating.substr(0,floating_ind) + floating.substr(floating_ind+1,-1);//-1 means to the end of the string. 
                        string temp_string = prefix;
                        temp_string.push_back(temp);
                        std::set<string> temp_set =  word_gen(in, temp_floating, temp_string);
                        newword.insert(temp_set.begin(), temp_set.end());
                        
                    }
                    else{
                        
                        string temp_string = prefix;
                        char alph_temp = alphabet[i];
                        temp_string.push_back(alph_temp);
                        std::set<string> temp_set =  word_gen(in, floating, temp_string);
                        newword.insert(temp_set.begin(), temp_set.end());

                    }
                
                
            }
        }


    }
    return newword;
    //if more than one letter, s

  





//return a set of words
}
