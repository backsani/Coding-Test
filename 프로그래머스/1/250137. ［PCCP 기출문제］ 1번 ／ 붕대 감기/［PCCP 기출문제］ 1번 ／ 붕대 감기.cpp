#include <string>
#include <vector>

using namespace std;

enum State{
    Idle,
    Attack,
    Init
};

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    State current = State::Init;
    
    int maxHealth = health;
    int bandTime = 0;
    int bandCycle = 0;
    int attackTime = 0;
    int attackCycle = 0;
    
    while(health > 0){
        
        if(current == State::Init){
            bandCycle = bandage[0];
            current = State::Idle;
        }
        else if(current == State::Idle){
            attackTime++;
            bandTime++;
            if(attackTime == attacks[attackCycle][0]){
                current = State::Attack;
                continue;
            }
            if(bandTime == bandCycle){
                health += bandage[2];
                bandTime = 0;
            }
            health += bandage[1];
            if(health > maxHealth)
                health = maxHealth;
        }
        else if(current == State::Attack){
            health -= attacks[attackCycle][1];
            attackCycle++;
            bandTime = 0;
            
            if(health <= 0)
                health = -1;
            
            if(attackCycle >= attacks.size())
                break;
            current = State::Idle;
            
            
        }
        
    }
    
    return health;
}