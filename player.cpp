#include "player.hpp"

bool batsmen:: allout()
{
    wickets+=1;
    if(wickets<10)
        return true;
    else    
        return false;
}
