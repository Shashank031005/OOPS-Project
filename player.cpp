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

void batsmen :: setDetails(int r, int b, int f, int s, bool w) {
        runs = r;
        balls = b;
        strikeRate = (balls != 0) ? (static_cast<double>(runs) / balls) * 100 : 0;
        fours = f;
        sixes = s;
        wicket = w;
    }

void batsmen :: display() override {
        cout << "Batsman: " << name << " | Runs: " << runs << " | Balls: " << balls 
             << " | SR: " << strikeRate << " | Fours: " << fours 
             << " | Sixes: " << sixes << " | Out: " << (wicket ? "Yes" : "No") << endl;
    }

void bowler :: setDetails(int b, int rc, int m, int w) {
        balls = b;
        runsConceded = rc;
        economy = (balls != 0) ? (static_cast<double>(runsConceded) / (balls / 6)) : 0;
        maidens = m;
        wickets = w;
    }
void bowler ::  display() override {
        cout << "Bowler: " << name << " | Balls: " << balls << " | Runs: " << runsConceded 
             << " | Economy: " << economy << " | Maidens: " << maidens 
             << " | Wickets: " << wickets << endl;
    }
  
