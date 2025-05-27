#include<iostream>
#include<string>
#include<random>


struct Character{
    std::string name;
    int strength; //0-100
    int speed; // 0-100
    int agility; // 0-100
};




void CreateCharacter(Character &p,std::string name, int str, int spd, int agil){
    p.name = name;
    p.strength = str;
    p.speed = spd;
    p.agility = agil;
}

void GenerateEnemy(Character &enemy){
    enemy.name = "Enemy";
    enemy.strength = rand() % 101;
    enemy.speed = rand() % 101;
    enemy.agility = rand() % 101;
}

int NormalizePoints(Character &c){
//0 -> weight of strenght, 1-> weigth of speed , 2 -> weight of agility; w {0-10}
int w[3] = {10,6,4};
float max_points = w[1]*100+w[2]*100 + w[0]*100;
float points = c.speed * w[1] + c.strength*w[0] + c.agility*w[2];
int res = (points/max_points)*100;
return res;
}

void Fight(Character &p, Character &enemy){

    int player_points = NormalizePoints(p);
    int enemy_points = NormalizePoints(enemy);

    std::cout << p.name << "points = "<<  player_points << "\n";
    std::cout << enemy.name << "points = "<<  enemy_points << "\n";

    if(player_points > enemy_points) std::cout << p.name << " wygrywa------------- !\n";
    if(player_points < enemy_points) std::cout << enemy.name << " wygrywa---------------- !\n";
    if(player_points == enemy_points) std::cout << "Remis -------------------!\n";

}

void Disp(Character &c){
    std::cout << "NAME : " << c.name << "\n";
    std::cout << "specification: -----------------------\n";
    std::cout << "STRENGTH : " << c.strength << "\n";
    std::cout << "SPD : " << c.speed << "\n";
    std::cout << "AGILITY : " << c.agility << "\n";
}


int main(){

    Character Player;
    Character Enemy;

    CreateCharacter(Player,"Wladyslaw",80,60,24);
    Disp(Player);

    GenerateEnemy(Enemy);
    Disp(Enemy);

    Fight(Player,Enemy);

    return 0;
}