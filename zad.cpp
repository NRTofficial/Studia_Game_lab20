#include<iostream>
#include<string>
#include<random>


struct Character{
    std::string name;
    int strength; //0-100
    int speed; // 0-100
    int agility; // 0-100

    int experience;
    int level;
};

class Game{

private:
Character selected_character;
Character ene;
public:

Game(){
    Character ch;
    CreateCharacter(ch,"Wladyslaw",80,60,24,20,69);
    CreateCharacter(ch,"Stanislaw",60,60,50,50,50);
    CreateCharacter(ch,"Karteslaw",40,100,85,20,40);
    CreateCharacter(ch,"Koloslaw",100,90,15,50,99);
}

std::vector<Character>Players;


void GenerateNewPlayer(){   
    Character ch;
    int str,spd,agil,exp,lev;
    std::string n;
    std::cout << "podaj imie: ";
    std::cin >> n;
    std::cout << "podaj sile (0-100): ";
    std::cin >> str;
    std::cout << "podaj speed (0-100): ";
    std::cin >> spd;
    std::cout << "podaj zwinnosc (0-100)";
    std::cin >> agil;
    std::cout << "podaj doswiadczenie (0-100)";
    std::cin >> exp;
    std::cout << "podaj level: (0-100)";
    std::cin >> lev;

    CreateCharacter(ch,n,str,spd,agil,exp,lev);
    selected_character = ch;
    std::cout << "\n ----------- Character Created! ---------\n\n";

}
void CreateCharacter(Character &p,std::string name, int str, int spd, int agil,int exp, int lev){
    p.name = name;
    p.strength = str;
    p.speed = spd;
    p.agility = agil;
    p.experience = exp;
    p.agility = agil;
    p.level = lev;
    Players.push_back(p);
}

void CreateNewCharacter(Character &p,std::string name, int str, int spd, int agil,int exp, int lev){

    CreateCharacter(p,name,str,spd,agil,exp,lev);
    std::string NewName;
    
    for(auto P:Players){
        if(P.name == p.name){
            std::cout << "gracz o takiej nazwie juz istnieje!\n";
            std::cout << "podaj nowa nazwe:";
            std::cin >> NewName;
            p.name = NewName;
          
            break;
        }
    }
}

void LoadCharacter(std::string name){

    for(auto p:Players) {
        if(name == p.name){
            selected_character = p;
            break;
        }
    }
}

void Select(){
    int i = 0;
    std::cout << "podaj index postaci: \n";
    std::cin >> i;
    selected_character = Players[i];

    std::cout << "\nSelected Character: " << selected_character.name << "\n\n";

}

void DispCharacters(){
    int i = 0; 
    for(auto p:Players) {
        std::cout << "index :" << i << "\n";
        Disp(p);
        i++;
    }
}


void Leveling(Character c){
    if(c.experience > 100) {
        c.experience == c.experience - 100;
        c.level++;
    }
}

void GenerateEnemy(Character &enemy){
    enemy.name = "Enemy";
    enemy.strength = rand() % 101;
    enemy.speed = rand() % 101;
    enemy.agility = rand() % 101;
    enemy.experience = rand() % 101;
    enemy.level = rand() % 101;
}

int NormalizePoints(Character &c){
    //0 -> weight of strenght, 1-> weigth of speed , 2 -> weight of agility; w {0-10} 3->experiecne 4-> level;
    int w[5] = {10,6,4,8,5};
    float max_points = w[1]*100+w[2]*100 + w[0]*100 + w[3]*100; + w[4]*100;
    float points = c.speed * w[1] + c.strength*w[0] + c.agility*w[2] + c.experience*w[3] + c.level*w[4];
    int res = (points/max_points)*100;

    return res;
}

void Fight(Character &p, Character &enemy){

    int player_points = NormalizePoints(p);
    int enemy_points = NormalizePoints(enemy);

    std::cout << p.name << "points = "<<  player_points << "\n";
    std::cout << enemy.name << "points = "<<  enemy_points << "\n";

    if(player_points > enemy_points) {
        std::cout << p.name << " wygrywa------------- !\n";
        p.experience += player_points-enemy_points;
        Leveling(p);
    }
    if(player_points < enemy_points) {
        std::cout << enemy.name << " wygrywa---------------- !\n";
        enemy.experience += enemy_points-enemy_points;
        Leveling(enemy);
    }
    if(player_points == enemy_points) std::cout << "Remis -------------------!\n";

}

void Disp(Character &c){
    std::cout << "NAME : " << c.name << "\n";
    std::cout << "specification: -----------------------\n";
    std::cout << "STRENGTH : " << c.strength << "\n";
    std::cout << "SPD : " << c.speed << "\n";
    std::cout << "AGILITY : " << c.agility << "\n";
    std::cout << "EXPERIENCE : " << c.experience<< "\n";
    std::cout << "LEVEL: " << c.level << "\n\n";
}

void Init(){
    int game_controller;

    std::cout << "1-stworz postac << \n" << "2-wybierz postac" << "\n";
    std::cin >> game_controller;

    switch (game_controller)
    {
    case 1:
        GenerateNewPlayer();

        break;
    case 2:
        DispCharacters();
        Select();
    default:
        
        break;
    }

    Disp(selected_character);
    GenerateEnemy(ene);
}


void InGame(){
    Disp(ene);
}

};


int main(){

    Game game;
    // Character Player;
    // Character Enemy;

    // game.CreateCharacter(Player,"Wladyslaw",80,60,24,20,69);
    // game.Disp(Player);

    // game.GenerateEnemy(Enemy);
    // game.Disp(Enemy);

    // game.Fight(Player,Enemy);

    std::cout << "loading game -------------------\n";
    game.Init();



    // while(true){

    // }

    return 0;
}