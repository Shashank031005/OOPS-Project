#include "player.hpp"

friend istream& operator >> (istream& i,batsmen& b){
cout<<"Enter the name of the player";
i>>b.name;
    
friend ostream& operator << (ostream&,batsmen&){
  
