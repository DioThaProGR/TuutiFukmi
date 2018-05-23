#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Stats {
	private:
		double hp;
		double def;
		double atk;
		int exp;
		int lvl;
	public:
		void setHp(double h){
			hp = h;
		}
		void setDef(double d){
			def = d;
		}
		void setAtk(double a){
			atk = a;
		}
		void setLvl(int l){
			lvl = l;
		}
		int addExp(int e){
			exp += e;
			return (exp);
		}
		double getHp(){
			return (hp);
		}
		double getAtk(){
			return (atk);
		}
		double getDef(){
			return (def);
		}
		void setExp(int ex){
			exp = ex;
		}
		int getExp(){
			return(exp);
		}
};

class Hero: public Stats{
	private:
		string name;
		char cls;
	public:
		void setName(string n){
			name = n;
		}
		void setClas(char c){
			cls = c;
		}
		char checkClass() {
			return (cls);
		}
		string getName(){
			return(name);
		}
};

class Enemies: public Stats{
	  private: 
		 string name;
		 int type;
	  public:
	  	void setType(int t){
	  		type = t;
		  }
 	    void setName(string n){
 	    	name = n;
		 }
		 string getName(){
		 	return(name);
		 }
		 int getType(){
		 	return(type);
		 }
};

class Area: public Enemies{
	private:
		int area;
		int maxlvl;
		int elvl;
		int nume;
	public:
		void setArea(int a){
			area = a;
		}
		int getArea(){
			return(area);
		}
		void setMaxlvl(int m){
			maxlvl = m;
		}
		int getMaxlvl(){
			return(maxlvl);
		}
		void setElvl(int e){
			elvl = e;
		}
		int getElvl(){
			return (elvl);
		}
		void setNume(int ne){
			nume = ne;
		}
		int getNume(){
			return(nume);
		}
};


class AreaEnemies: public Area{
	private:
		int en;
	public:
		void setEn(int e){
			en = e;
		}
		int getEn(){
			return(en);
		}
};
int main() {
	//Objects
	Hero p1;
	Enemies slime, orc;
	Area a1;
	AreaEnemies n1;
	//Variables
	char clas;
	string name;
	int Elvl;
	
	srand(time(NULL));
	
	//Starting
	cout << "Enter your Name: "<< endl;
	cin >> name;
	p1.setName(name);
	cout << endl;
	cout << "Choose your class: " << endl << "W: Warrior		M: Mage" << endl;
	cin >> clas;
	p1.setClas(clas);
	
	cout <<endl;
	cout <<"Name: " << p1.getName() << endl;
	
	if (p1.checkClass() == 'w' || p1.checkClass() == 'W'){
		cout << "Class: Warrior "<< endl;
	}
	else if (p1.checkClass() == 'm' || p1.checkClass() == 'M'){
		cout << "Class: Mage "<< endl;
	}
	else{
		cout << "You failed as a player..." << endl;
	}
	
	p1.setLvl(1);
	
	//Starting Stats
	if (p1.checkClass() == 'w' || p1.checkClass() == 'W'){
		p1.setHp(23);
		p1.setAtk(7);
		p1.setDef(8);
	}
	else if (p1.checkClass() == 'm' || p1.checkClass() == 'M'){
		p1.setHp(18);
		p1.setAtk(11);
		p1.setDef(5.5);
	}
	p1.setExp(0);
	cout << "---Stats---" << endl <<"Health: " << p1.getHp() << endl << "Attack: " << p1.getAtk() << endl << "Defence: " <<p1.getDef() << endl << "Exp: " << p1.getExp() <<endl << endl;
	
	system("pause");
	
	//Enemies
	slime.setLvl(1);
	slime.setHp(4);
	slime.setAtk(2);
	slime.setDef(3.5);
	slime.setType(0);
	slime.setName("Slime");
	
	orc.setLvl(1);
	orc.setHp(5);
	orc.setAtk(3.5);
	orc.setDef(3);
	orc.setType(1);
	orc.setName("Orc");
	
	//Area1
	a1.setArea(1);
	a1.setMaxlvl(a1.getArea() + (a1.getArea()* 3));
	Elvl = rand() % a1.getMaxlvl() + a1.getArea();
	a1.setElvl(Elvl);
	a1.setNume(a1.getArea() + 1);
	cout << "Area " << a1.getArea() << endl << "Enemies are level " << a1.getElvl() << endl;
	
	system("pause");
	
	//Spawn Enemies
	n1.setEn(rand() % 1);
	if (n1.getEn() == 0){
		cout << "A level " <<a1.getElvl() << " " << slime.getName() << " has appeared!" << endl;
		cout << "---Stats---" << endl <<"Health: " << slime.getHp() << endl << "Attack: " << slime.getAtk() << endl << "Defence: " <<slime.getDef() << endl << endl;
	}
	else if (n1.getEn() == 1){
		cout << "A " << orc.getName() << " has appeared!" << endl;
		cout << "---Stats---" << endl <<"Health: " << orc.getHp() << endl << "Attack: " << orc.getAtk() << endl << "Defence: " <<orc.getDef() << endl << endl;
	}
	
	system("pause");
	return 0;
}
