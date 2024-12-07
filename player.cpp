#include "player.hpp"

friend istream& operator >> (istream& i,batsmen& b){
cout<<"Enter the name of the player";
i>>b.name;
    
friend ostream& operator << (ostream& o,batsmen& b){
     o << "Batsman: " << b.name << " | Runs: " << b.runs << " | Balls: " << b.balls 
             << " | SR: " << b.strikeRate << " | Fours: " << b.fours 
             << " | Sixes: " << b.sixes << " | Out: " << (b.wicket ? "Yes" : "No") << endl;
}
  
