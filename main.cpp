#include <iostream>
#include <vector>
#include <string>
#include<cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAP_W = 40;
const int MAP_H = 20;

struct Item {
    string name;
    int atkBonus;
    int defBonus;




};
struct Entity {
    char sym;
    int x, y;
    string name;
    int hp, maxHp;
    int baseAtk, baseDef;

}
Item weapon;

int getAtk() {
    return baseAtk + weapon.atkBonus;
}   
    int getDef() {
    return baseDef + weapon.defBonus;
    } 


struct Room {
    int x, y, w, h;
    int cx() { return x + w / 2; }
    int cy() { return y + h / 2; }

};
//globals

vector<string>dungeon;
vector<Room> rooms;
Entity player;
vector<Entity> enemies;
vector<string> logs;

//engine functions
void addLog(string msg){
    logs.push_back(msg);
    if (logs.size() > 4){
        logs.erase(logs.begin());
    }
}
void carveH(int x1,int x20: x++){
    for (int x = min (x1,x2);
x<= max(x1,x2); x++){
    dungeon[y][x] = '.';
}
}

void carveV(int y1,int y2, int x){
    for (int y = min(y1,y2); y <= max(y1,y2); y++){
        dungeon[y][x] = '.';
    }
}
void generateMap(){
    dungeon.assign(
        MAP_H,string(MAP_W,'#')
    );

    //for 5 connected rooms
    for (int i=0;i<5; i++){
        room r;
        r.w =5 + (rand() % 5);
        r.h =4 + (rand() %4);
        r.x = rand() % (MAP_W - r.w -1) +1;
        r.y = rand() % (MAP_H - r.h -1) +1;
    }

    //carve room
    for(int y=r.y; y< r.y+r.h;y++){
        for (int x = r.x; x < r.x + r.w; x++){
            dungeon[y][x] = '.';
        }
    }
}
//gurenteed connectivity;
//connect to previous room
if (!rooms.empty()){
    Room prev = rooms.back();
    if (rand()%2 ==0){
        carveH(prev.cx(), r.cx(), prev.cy());
        carveV(prev.cy(), r.cy(), r.cx());
    } else {
        carveV(prev.cy(), r.cy(), prev.cx());
        carveH(prev.cx(), r.cx(), r.cy());
    }
}

rooms.push_back(r);
    }
}   

void combat(Entity&atk,Entity& def){
    // Damage atk min 0
int dmg = atk.getAtk() - def.getDef();
if (dmg < 0) dmg = 0;
 def.hp -= dmg;

 addLog(atk.name + " hits " + 
    def.name + " for " + to_string(dmg));
 }
 void enemyTurn(){
    for(auto& e : enemy){
        if (e.hp <=0) continue;
        //calculate distance 
        int dx= player.x = e.x;
        int dy = player.y - e.y;
        int dist = sqrt(dx*dx + dy*dy);

        if (dist <=1){
            //adjacent:Attack player
            combat(e, player);
        }
        else if (dist <8){
            //pathfind toward player 
            //smpl greedy lgic
            //avding walls
            int nx = e.x + (dx > 0 ? 1;
            (dx < 0 ? -1 : 0));
            int ny = e.y + (dy > 0 ? 1 :
                 (dy < 0 ? -1:0));
                 
                 // horizontal move
                 if 9abs(dx) > abs(dy)&&
                    dungeon[e.y][nx] == '.'){
                    e.x = nx;
                    }
                    //try
                    else if (dungeon[ny][e.x] == '.'){
                        e.y = ny;
                    }
                }
            }
            
        }
        void render(){
            //clear
            cout << "\033[2J\033[1;1H";
        //copy map
        vector<string> screen = dungeon;
        //draw alive 
        for (auto& e : enemies){
            if (e.hp>0){
                screen[e.y][e.x]= e.sym;
            }

            }
        }
        }
        //draw player
        screen[player.y][player.x]=player.sym;

        //prntscr
        for (string row:screen){
            cout << row << '\n';
        }
        //prnt UI
        cout <<"=======================\n";
        cout <<"HP:"<<player.hp << "/"
            << player.maxHp << " ATK:" << player.getAtk()
            <<"\n";
            cout << "Wpn:"
            << player.weapon.name << "\n";
            cout <<"-----------------------\n";
            for(string 1; logs){
                cout << ">" << 1 << "\n";
            }
        }
         int main(){
            srand(time(nullptr));
            //1.gen map
            generateMap();
            //2.Setup Player
            Room start = rooms[0];
            player = {
                '@',start.cx(),start.cy(),
                "Hero", 20,20,5,2,
                {"Rusty Sword"  , 2,0
                };

                //setp enemies
                for (int i=1; i< rooms.size(); i++){
                    Room& r = rooms[i];
                    enemies.push_bak({
                        'g',r.cx(),r.cy(),
                    "goblin",10,10,4,1,
                {"fists",0,0}
                    });
            }
            addLog("Dungeon Entered!");

            //game loop
            while (player.hp > 0){
                render();
                //input
                char input;
                cin >> input;
                int dx=0, dy=0;
                if (input == 'w') dy = -1;
                else if (input == 's') dy = 1;
                else if (input == 'a') dx = -1;
                else if (input == 'd') dx = 1;

                int nx = player.x + dx;
                int ny = player.y + dy;

                //check move
                if (dungeon[ny][nx] == '.'){
                    player.x = nx;
                    player.y = ny;
                }
                //check combat
                for (auto& e : enemies){
                    if (e.hp > 0 && e.x == player.x && e.y == player.y){
                        combat(player, e);
                    }
                }
                enemyTurn();
         }   
        }
        
    
 





