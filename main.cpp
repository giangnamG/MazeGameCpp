#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include"dohoa.h"
#include<fstream>
using namespace std;
struct toa_do{
	int toa_do_x;
	int toa_do_y;
};
toa_do td[2];
char c[2];
int level;
int check=0; // ktra xem nguoi choi co qua man khong de luu lai level
int map[50][120];
//----------------------------------------//
void Start();
void Rule();
void load_NV();
//-----------Level_1----------------------//
void loadmap1();
void level_1();
//-----------Level_2---------------------//
void loadmap2();
void level_2();
//---------------------------------------//
void Control(char );
void displayGame();
void saveGame();
void InforPlayer();
void endgame();
int main() {
	resizeConsole(1920,1080);

	c[0]='O';
	c[1]=' ';
	srand(time(NULL));
	while(true){
		Start();
	}
	getchar();
}
void Start() {
	int key;
	system("cls");
	textcolor(7);
	gotoxy(23, 9);	
	for (int i = 0; i < 30; i++) 
		putchar('_');
	
	textcolor(10);

	while (!_kbhit()) {
		gotoxy(25, 11);	cout << "NEW GAME\tPress N or n";
		gotoxy(25, 13); cout << "Infor player\tPress I or i";
		gotoxy(25, 15); cout << "RULE\t\tPress R or r\n";
		gotoxy(25, 17);	cout << "EXIT\t\tPress Esc\n";
		gotoxy(13, 1);	cout << ("MM         MM         AAAA         ZZZZZZZZZZZZZ   EEEEEEEEEE");
		gotoxy(13, 2);	cout << ("MM MM   MM MM        AA  AA                  ZZ    EE        ");
		gotoxy(13, 3);	cout << ("MM  MM MM  MM       AA    AA               ZZ      EE        ");
		gotoxy(13, 4);	cout << ("MM   MMM   MM      AA      AA            ZZ        EEEEEEEEEE");
		gotoxy(13, 5);	cout << ("MM         MM     AAAAAAAAAAAA         ZZ          EE        ");
		gotoxy(13, 6);	cout << ("MM         MM    AA          AA      ZZ            EE        ");
		gotoxy(13, 7);	cout << ("MM         MM   AA            AA   ZZZZZZZZZZZZZ   EEEEEEEEEE");
		cout << endl;
		textcolor(8 + rand() % 8);
		Sleep(700);
	}
	key = _getch();
	switch (key){
		case 'N':
		case 'n': level_1();
	 		break;
	 	case 'I':
	 	case 'i': InforPlayer();
	 		break;
	 	case 'R':
	 	case 'r': Rule();
	 		break;
		case 27: 
			system("cls");
			exit(0);
			break;
		default: {
			system("cls");
			break;
		}
	}
}
void InforPlayer(){
	system("cls");
	FILE *data = NULL;
	data = fopen("savegame.txt", "r+");
	char c;
	
	while((c = fgetc(data)) != EOF){
		cout << c;
	}
	getchar();
	fclose(data);
	Start();
}
void Rule(){
	system("cls");
	FILE * fp = NULL;
    //Mo file bang hàm fopen
    fp= fopen("rule.txt", "rt");
    char c;
    //Ðoc tung ku tu cua file cho toi khi gap EOF
    while ((c = fgetc(fp)) != EOF)
        cout << c;
		  
    getchar();
    fclose(fp);
    Start();
}

void displayGame() {
	system("cls");
	char c;
	textcolor(7);
	gotoxy(20, 7);
	printf("M E N U  !");
	textcolor(13);
	gotoxy(21, 10);	printf("NEW GAME\t\tY");
	gotoxy(21, 12);	printf("SAVE\t\tS");
	gotoxy(21, 14);	printf("QUIT\t\tEsc\n");
	c = getch();
	switch (c){
	case 27:system("cls");
			exit(0);			
			break;
	case 'S':
	case 's':saveGame();
			break;
	case 'Y':
	case 'y':level_1();
			break;
	default: displayGame();
	}
}
void saveGame(){
	system("cls");
	char name[30];
	gotoxy(10, 13);
	cout << "Nhap ho va ten: ";
	gets(name);
	string Level = "--Level ";
	string space="						";
	string infor = space+name + Level  + (char)(level+48); 
	
	ofstream data("savegame.txt",ios::app);
	data << infor<<endl;
	gotoxy(10, 15); cout << "Luu thanh cong !!";
	gotoxy(10, 17); cout << "Press anykey to exit !!";
	getchar();
	data.close();
	Start();
}

void Control(char t){
		
		if(t=='d'){
			if(map[td[0].toa_do_y][td[0].toa_do_x+1]==1)	
				return ;
			else{
				td[1].toa_do_x=td[0].toa_do_x;
				td[0].toa_do_x++;
				td[1].toa_do_y=td[0].toa_do_y;	
			}	
		}else if(t=='a'){
			if(map[td[0].toa_do_y][td[0].toa_do_x-1]==1 || td[0].toa_do_x-1<=0)
				return ;
			else{
				td[1].toa_do_x=td[0].toa_do_x;
				td[0].toa_do_x--;
				td[1].toa_do_y=td[0].toa_do_y;	
			}	
		}else if(t=='w'){
			if(map[td[0].toa_do_y-1][td[0].toa_do_x]==1 || td[0].toa_do_y-1<=0)
				return ;
			else{
				td[1].toa_do_y=td[0].toa_do_y;
				td[0].toa_do_y--;
				td[1].toa_do_x=td[0].toa_do_x;	
			}	
		}else if(t=='s'){
			if(map[td[0].toa_do_y+1][td[0].toa_do_x]==1)
				return ;
			else{
				td[1].toa_do_y=td[0].toa_do_y;
				td[0].toa_do_y++;
				td[1].toa_do_x=td[0].toa_do_x;		
			}
		}
	
}
void load_NV(){
	//status
	gotoxy(110,11); cout <<"                              ";
	gotoxy(110,11); cout <<"status (x,y): "<<td[0].toa_do_x<<", "<<td[0].toa_do_y;
	for(int i=1;i>=0;i--){
		gotoxy(td[i].toa_do_x,td[i].toa_do_y);
		cout << c[i];
	}
}

void loadmap1(){
	system("cls");
	td[0].toa_do_x=5;
	td[0].toa_do_y=6;
	td[1].toa_do_x=td[0].toa_do_x-1;
	td[1].toa_do_y=td[0].toa_do_y;
	
	FILE * data = NULL;
    data = fopen("map1.txt", "r+"); // r+ : cho phep doc va chinh sua file
    
    char c;
    int x=0,y=1;

    while ((c = fgetc(data)) != EOF)  {
        cout << c;
        x++;
    	if(x==104){
    		x=0;
    		y++;
		}
		if(c=='='||c=='|')
    		map[y][x]=1;
		else
			map[y][x]=0;
    }
	map[31][5]=1;
    fclose(data);
    gotoxy(110,3); cout << "Level 1";
    gotoxy(110,5); cout << "Nhiem vu: nhat 2 key (K) de thoat khoi MAZE'ngn !!!";
    gotoxy(110,9); cout <<"See Menu? (Press 'y or Y' to see list selections).";
}
void level_1(){
	textcolor(4);
	level = 0;
	loadmap1();
//	gotoxy(1,45);
//	
//	
//	see map (0,1)
//	for(int y=1;y<=44;y++){
//		for(int x=0;x<=103;x++)
//			cout << map[y][x];
//			cout << endl;
//	}
//	gotoxy(1,1);
	int key=0;
	char t;
	int check1=0,check2=0;// cho phep lay chia khoa 1 lan duy nhat
	while(true){
		t = getch();
		if(t=='E')
			break;
		if(t=='y'||t=='y')
			displayGame();
		Control(t);
		load_NV();
		if(td[0].toa_do_x==6&&td[0].toa_do_y==6&&key==0)
			map[6][5]=1;
		// get key
		if(td[0].toa_do_x==25&&td[0].toa_do_y==3&&!check1){
			key++;
			check1=1;
		}
		if(td[0].toa_do_x==96&&td[0].toa_do_y==23&&!check2){
			key++;
			check2=1;
		}
		gotoxy(110,7); cout <<"key: "<<key;
		if(key==2)
			map[31][5]=0;
			
		if(td[0].toa_do_x==5&&td[0].toa_do_y==31)
			level_2();	
	}
}

void loadmap2(){
	system("cls");
	td[0].toa_do_x=48;
	td[0].toa_do_y=1;
	td[1].toa_do_x=td[0].toa_do_x;
	td[1].toa_do_y=td[0].toa_do_y-1;
	
	
//  toa do gan loi thoat
//	td[0].toa_do_x=97;
//	td[0].toa_do_y=19;
//	td[1].toa_do_x=td[0].toa_do_x;
//	td[1].toa_do_y=td[0].toa_do_y-1;
	

	FILE * data = NULL;
    data = fopen("map2.txt", "r+"); 
    
    char c;
    int x=0,y=1;

    while ((c = fgetc(data)) != EOF)  {
        cout << c;
        x++;
    	if(x==104){
    		x=0;
    		y++;
		}
		if(c=='='||c=='|')
    		map[y][x]=1;
		else
			map[y][x]=0;
    }
	map[19][103]=1;
    fclose(data);
    gotoxy(110,3); cout << "Level 2";
    gotoxy(110,5); cout << "Nhiem vu: nhat 2 key (K) de thoat khoi MAZE'ngn !!!";
    gotoxy(110,9); cout <<"See Menu? (Press 'y or Y' to see list selections).";
}
 
void level_2(){
	textcolor(13);
	level+=1;
	loadmap2();
//	gotoxy(1,45);
//       see map (0,1)
//	for(int y=1;y<=44;y++){
//		for(int x=0;x<=103;x++)
//			cout << map[y][x];
//			cout << endl;
//	}
//	gotoxy(1,1);
	int key=0;
	char t;
	int check1=0,check2=0;// cho phep lay chia khoa 1 lan duy nhat
	while(true){
		t = getch();
		if(t=='E')
			break;
		if(t=='y'||t=='y')
			displayGame();
		Control(t);
		load_NV();
		// get key
		if(td[0].toa_do_x==34&&td[0].toa_do_y==15&&!check1){
			key++;
			check1=1;
		}
		if(td[0].toa_do_x==56&&td[0].toa_do_y==29&&!check2){
			key++;
			check2=1;
		}
		gotoxy(110,7); cout <<"key: "<<key;
		if(key==2)
			map[19][103]=0;
			
		if(td[0].toa_do_x==103&&td[0].toa_do_y==19){
			level+=1;
			endgame();
		}
	}
}

void endgame(){
	system("cls");
	while (!_kbhit()) {
	gotoxy(25, 3);	cout << ("WW                     WW  IIIIIIIIII  NN    NN   NN    NN   EEEEEEEE   RRRRRRRR");
	gotoxy(25, 4);	cout << (" WW                   WW       II      NNN   NN   NNN   NN   EE         RR      R");
	gotoxy(25, 5);	cout << ("  WW       WWW       WW        II      NNNN  NN   NNNN  NN   EE         RR      R");
	gotoxy(25, 6);	cout << ("   WW     WW WW     WW         II      NN NN NN   NN NN NN   EEEEEEEE   RRRRRRRR");
	gotoxy(25, 7);	cout << ("    WW   WW   WW   WW          II      NN  NNNN   NN  NNNN   EE         RR RR");
	gotoxy(25, 8);	cout << ("     WW WW     WW WW           II      NN   NNN   NN   NNN   EE         RR   RR");
	gotoxy(25, 9);	cout << ("      WW         WW        IIIIIIIIII  NN    NN   NN    NN   EEEEEEEE   RR     RR");
	gotoxy(25,13);  cout <<"Press M to see menu !";
	gotoxy(25,14);  cout <<"Press Esc to exit !";
	gotoxy(25,11);  cout <<"Tuy chon: ";
	textcolor(8 + rand() % 8);
	Sleep(800);
	}
	char t;
	t=getch();
	switch(t){
		case 'M':
		case 'm':
			displayGame();
			break;
		case 27:
			system("cls");
			exit(0);
			break;
		default : endgame();
			break;
	}
}

