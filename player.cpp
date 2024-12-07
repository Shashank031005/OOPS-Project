#include "player.hpp"

friend istream& operator >> (istream& i,batsmen& b){
cout<<"Enter the name of the player";
i>>b.name;
b.runs=0;
b.balls=0;
b.strikeRate=0;
b.fours=0;
b.sixes=0;
b.wicket=false;
}
    
friend ostream& operator << (ostream& o,batsmen& b){
     o << "Batsman: " << b.name << " | Runs: " << b.runs << " | Balls: " << b.balls 
             << " | SR: " << b.strikeRate << " | Fours: " << b.fours 
             << " | Sixes: " << b.sixes << " | Out: " << (b.wicket ? "Yes" : "No") << endl;
}

friend istream& operator >> (istream& i,bowler& b){
cout<<"Enter the name of the player";
i>>b.name;
b.runsConceded=0;
b.balls=0;
b.economy=0;
b.maidens=0;
b.wickets=0;
}
    
friend ostream& operator << (ostream& o,bowler& b){
    o << "Bowler: " << b.name << " | Balls: " << b.balls << " | Runs: " << b.runsConceded 
             << " | Economy: " << b.economy << " | Maidens: " << b.maidens 
             << " | Wickets: " << b.wickets << endl;
}
  
