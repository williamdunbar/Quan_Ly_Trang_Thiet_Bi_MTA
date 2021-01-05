#pragma once;
#include<iostream>
#include<string.h>
#include"Console.h"
using namespace std;

void NoticeSearch(char *s1, char* s2);
void Welcome();
void Table();
void TableStatistical();
void Oxy();
void BangChuThich();
void MTA();
void THEMMOIDANHSACH();
void CAPNHATDANHSACH();
void DANHSACHSAPXEP();
void DANHSACHTIMKIEM();
void DANHSACHTHONGKE(string a[]);
void Exit_Frame();
void End();


void NoticeSort(char *s1, char* s2){
	TextColor(11);
	gotoXY(25,33); cout << "Thuat toan: "<< s1;
	gotoXY(25,34); cout << "Tu khoa: "<< s2;
}


void NoticeSearch(char *s1, char* s2){
	TextColor(13);
	gotoXY(25,33); cout << "Thuat toan: Tim kiem "<< s1;
	gotoXY(25,34); cout << "Tu khoa: "<< s2;
	TextColor(11);
	gotoXY(57,6); cout << s2;
}



void Welcome(){
	int x = 55; 
	int y = 2;
	int color =rand() % (6-1+1)+1;
	TextColor(270);	gotoXY(x+13,y-1); printf("  Nguyen Le Minh - Lop: ANHTTT k54  ");
	TextColor(color);
	gotoXY(x,y);	cout << GOC1;
	for(int i=1; i<61; i++){
		gotoXY(x+1*i,y);	cout << NGANG;
	}
	gotoXY(x+60,y); cout <<GOC2;
	gotoXY(x,y+1); cout<<"                                                           ";
	TextColor(color+1);
	gotoXY(x,y+2); cout<<"          CHUONG TRINH QUAN LY TRANG THIET BI HVKTQS         ";
	TextColor(color);
	gotoXY(x,y+3); cout<<"                                                           ";
	gotoXY(x,y+4); cout<<GOC4;
	for(int i=1; i<61; i++){
		gotoXY(x+1*i,y+4);cout << NGANG;
	}
	gotoXY(x+60,y+4); cout <<GOC3;
	MTA();
}

void Table(){
	int length;
	int x = 25, y = 8, z = 24;
	gotoXY(x,y);
	string Table_keyword[7] = {"  STT  ","    Ma Trang Thiet Bi    ","      Ten Trang Thiet Bi      ", "   Ngay san xuat   ", "   Ngay Su Dung   ", "    Chung Loai    ", "   Cap   "};
	for(int i=0; i<7; i++){ 
		length += Table_keyword[i].length();
	}
	TextColor(14);
	An_tro_chuot ();
	for(int j = 0; j<(length); j++){
		gotoXY(x+j, y);
		cout << TABLE_NGANG;
		gotoXY(x+j, y+3);
		cout << TABLE_NGANG;
		for(int k =0; k<22; k+= 2){
			gotoXY(x+j, y+3+k);
			cout << TABLE_NGANG;
		}
//		Sleep(10);
	}
	for(int j =0; j<=7; j++){
		gotoXY(x-1,y); cout << TABLE_GOC1;
		gotoXY(x+length-1,y); cout << TABLE_GOC2;
		gotoXY(x+length-1,y+23); cout << TABLE_GOC3;
		gotoXY(x-1,y+23); cout << TABLE_GOC4;
		for(int i = 1; i<23; i++){
			if(i==2 && j<7){
				TextColor(10);
				cout <<Table_keyword[j];
			}gotoXY(z,y+i);
		TextColor(14);
		cout << TABLE_DOC;
//			 Sleep(10); 
		}
		if(j<7) z +=Table_keyword[j].length();
		 gotoXY(z, y); cout << TABLE_GOC2;
		 gotoXY(z,y+23); cout << TABLE_GOC3;
	} Hien_tro_chuot();
}

void TableStatistical(){
	int length;  
	int x = 25, y = 3, z = 24;
	gotoXY(x,y);
	TextColor(11);
	string Label[3] = {" Thong Ke ", " So Luong ", " Ti Le (%)" };
	for(int j = 0; j<8; j += 2){
		for(int i = 1; i<120; i++){
			gotoXY(x+i,y+j); 	cout << TABLE_NGANG;
		}
	}
	for(int j = 0; j<140; j += 20){
		gotoXY(x+j,y);		cout <<(char)194;
		gotoXY(x+j,y+6); 	cout <<(char)193;
		for(int i = 1; i<6; i++){
			gotoXY(x+j,y+i);	cout << TABLE_DOC;
		}
	}
	TextColor(14);
	for(int i = 0; i<3; i++){
		gotoXY(x+2, y+1+i*2);		cout << Label[i];
	}
	
}
void Oxy(){
	COORD OXY;
	OXY.X = 15, OXY.Y = 37;
	TextColor(9);
	gotoXY(OXY.X+1,10); 	cout << "b) Do Thi";
	gotoXY(OXY.X+1,2); 	cout << "a) Bang thong ke so luong trang thiet bi";
	TextColor(15);
	for(int i = 0; i<25; i++){
		gotoXY(OXY.X,OXY.Y -i);
		cout <<TABLE_DOC;
	}
	gotoXY(OXY.X, OXY.Y -25);	cout << (char)94;
	gotoXY(OXY.X+2,12);	cout << "So luong";
	for(int i = 0; i<90; i++){
		gotoXY(OXY.X+i, OXY.Y );
		cout <<TABLE_NGANG;
	}
	gotoXY(OXY.X+89,OXY.Y);	cout <<(char)62;
	gotoXY(OXY.X,OXY.Y );
	cout << TABLE_GOC4;
	for(int i = 3; i<25; i+=3){
		for(int j = 1; j<80; j++){
			gotoXY(OXY.X+j,OXY.Y -i);	cout <<"-";
		}
		
	}
}


void BangChuThich(){
	int x = 110, y = 20;
	TextColor(14);
	for(int i = 1; i<=10; i++){
		gotoXY(x,y+i);		cout << DOC;
		gotoXY(x+40,y+i);	cout << DOC;
	}
	for(int i = 1; i<=40; i++){
		gotoXY(x+i,y);		cout << NGANG;
		gotoXY(x+i,y+10);		cout << NGANG;
	} 
	gotoXY(x,y); cout << GOC1;
	gotoXY(x+40,y); cout << GOC2;
	gotoXY(x+40,y+10); cout << GOC3;
	gotoXY(x,y+10); cout << GOC4;
	gotoXY(112,21); 
	TextColor(9); cout << "c) Chu Thich";
}

void MTA(){
	int x = 130, y= 5 ;
	srand(time(NULL));
	int color = rand() % (13-2+1)+2;
	TextColor(color);     
	gotoXY(x,y  ); cout<<"  ***                       ***  ";    
	gotoXY(x,y+1); cout<<"  *****                   *****  ";       
	gotoXY(x,y+2); cout<<"  *** ***               *** ***   ";       
	gotoXY(x,y+3); cout<<"  ***   ***           ***   ***   ";       
	gotoXY(x,y+4); cout<<"  ***     ***       ***     ***   ";       
	gotoXY(x,y+5); cout<<"  ***       ***   ***       ***   ";       
	gotoXY(x,y+6); cout<<"  ***         *****         ***   ";       
	gotoXY(x,y+7); cout<<"  ***                       ***   ";       
	gotoXY(x,y+8); cout<<"  ***                       ***   ";   
	int color1 = rand() % (13-2+1)+2;
	TextColor(color1);    
	gotoXY(x,y+9); cout<<"                                  ";       
	gotoXY(x,y+10); cout<<"      **********************     ";       
	gotoXY(x,y+11); cout<<"      **********************     ";       
	gotoXY(x,y+12); cout<<"               ***                ";       
	gotoXY(x,y+13); cout<<"               ***                ";       
	gotoXY(x,y+14); cout<<"               ***                ";       
	gotoXY(x,y+15); cout<<"               ***                ";       
	gotoXY(x,y+16); cout<<"               ***                ";       
	gotoXY(x,y+17); cout<<"               ***                ";       
	gotoXY(x,y+18); cout<<"               ***                ";       
	gotoXY(x,y+19); cout<<"               ***                ";
	int color2 = rand() % (13-2+1)+2;    
	TextColor(color2);   
	gotoXY(x,y+20); cout<<"                                  ";       
	gotoXY(x,y+21); cout<<"               ***                ";       
	gotoXY(x,y+22); cout<<"             *** ***              ";       
	gotoXY(x,y+23); cout<<"            ***   ***             ";       
	gotoXY(x,y+24); cout<<"           ***     ***            ";       
	gotoXY(x,y+25); cout<<"          ***       ***           ";       
	gotoXY(x,y+26); cout<<"         ***         ***          ";       
	gotoXY(x,y+27); cout<<"        *****************         ";       
	gotoXY(x,y+28); cout<<"       *******************        ";       
	gotoXY(x,y+29); cout<<"      ***               ***       ";       
	gotoXY(x,y+30); cout<<"     ***                 ***      ";    
		TextColor(color+1);    
}

void THEMMOIDANHSACH(){
	int x = 45;
	int y = 3;
	TextColor(13);
	gotoXY(x,y);   cout <<"--.--|                            o        |          |                     |";    
 	gotoXY(x,y+1); cout <<"  |  |---.,---.,-.-.    ,-.-.,---..    ,---|,---.,---.|---.  ,---.,---.,---.|---.";
  	gotoXY(x,y+2); cout <<"  |  |   ||---'| | |    | | ||   ||    |   |,---||   ||   |  `---.,---||    |   |";
  	gotoXY(x,y+3); cout <<"  `  `   '`---'` ' '    ` ' '`---'`    `---'`---^`   '`   '  `---'`---^`---'`   '";

	Sleep(80);
	Button(x+35, y+30, "     SAVE", false);
	Button(1,1,"     BACK", false);
}

void CAPNHATDANHSACH(){
	
	int x = 45, y = 3;
	TextColor(13);
	gotoXY(x,y); 	cout<<",---.                   |         |            |          |                       |    ";
	gotoXY(x,y+1); 	cout<<"|    ,---.,---.    ,---.|---.,---.|---     ,---|,---.,---.|---.    ,---.,---.,---.|---.";
	gotoXY(x,y+2); 	cout<<"|    ,---||   |    |   ||   |,---||        |   |,---||   ||   |    `---.,---||    |   |";
	gotoXY(x,y+3); 	cout<<"`---'`---^|---'    `   '`   '`---^`---'    `---'`---^`   '`   '    `---'`---^`---'`   '";
	
	Button(1,1,"     BACK", false);
	Button(x ,y+30,"      ADD", false); 
	Button(x+35, y+30,"     EDIT", false);
	Button(x+70, y+30,"    DELETE", false);
	Button(x+110,y+15,"     Next >>", false);
	Button(x-40,y+15," << Previous", false);	
}

void DANHSACHSAPXEP(){
	Xoa_Full_Man_hinh();
	Table();
	int x = 45, y = 3;
	TextColor(13);
	gotoXY(x,y); 	cout<<",---.                                    |          |                       |    ";
	gotoXY(x,y+1); 	cout<<"`---.,---.,---.    .  ,,---.,---.    ,---|,---.,---.|---.    ,---.,---.,---.|---.";
	gotoXY(x,y+2); 	cout<<"    |,---||   |     >< |---'|   |    |   |,---||   ||   |    `---.,---||    |   |";
	gotoXY(x,y+3); 	cout<<"`---'`---^|---'    '  ``---'|---'    `---'`---^`   '`   '    `---'`---^`---'`   '";
	gotoXY(x,y+4);  cout<<"          |                 |     ";
	
	Button(1,1,"     BACK", false);
	Button(x+15 ,y+30," < Exchange >", false); 
	Button(x+70, y+30,"   < Save > ", false);
	Button(x+110,y+15,"     Next >>", false);
	Button(x-40,y+15," << Previous", false);	
}

void DANHSACHTIMKIEM(){
	Xoa_Full_Man_hinh();
	Table();
	Hien_tro_chuot();
	
	int x = 45, y = 3;
	TextColor(13);
	for(int i = 0; i< 65; i++){
		gotoXY(x+10+i,y + 2); cout << TABLE_NGANG;
		gotoXY(x+10+i,y + 4); cout << TABLE_NGANG;
	}
	gotoXY(x+10, y+2); cout << TABLE_GOC1;
	gotoXY(x+75, y+2); cout << TABLE_GOC2;
	gotoXY(x+10, y+3); cout << TABLE_DOC;
	gotoXY(x+10, y+3); cout << TABLE_DOC;
	gotoXY(x+75, y+3); cout << TABLE_DOC;
	gotoXY(x+75, y+3); cout << TABLE_DOC;
	gotoXY(x+30, y+3); cout << TABLE_DOC;
	gotoXY(x+30, y+3); cout << TABLE_DOC;
	gotoXY(x+10, y+4); cout << TABLE_GOC4;
	gotoXY(x+75, y+4); cout << TABLE_GOC3;
	
	Button(1,1,"     BACK", false);
	Button(x+38, y+30,"   < Save > ", false);
	Button(x+110,y+15,"     Next >>", false);
	Button(x-40,y+15," << Previous", false);	 
}

void DANHSACHTHONGKE(){
	Xoa_Full_Man_hinh();
	int x = 25, y = 3, z = 24;
	TableStatistical();
	BangChuThich();
	Oxy();

	Button(1,1,"     BACK", false);
	
}

void Exit_Frame(){
	int x = 55; int y = 15;
	TextColor(12);
	gotoXY(x,y);	cout << GOC1;
	for(int i=1; i<61; i++){
		gotoXY(x+1*i,y);	cout << NGANG;
	}
	gotoXY(x+60,y); cout <<GOC2;
	TextColor(11); 
	gotoXY(x,y+1); cout<<"                    Do You Want To Exit ???                ";
	gotoXY(x,y+2); cout<<"                                                           ";
	TextColor(14); 
	gotoXY(x,y+3); cout<<"               YES                           NO            "; 
	TextColor(12);
	gotoXY(x,y+4); cout<<"                                                           ";
	gotoXY(x,y+5); cout<<"                                                           ";
	gotoXY(x,y+4); cout<<GOC4;
	for(int i=1; i<61; i++){
		gotoXY(x+1*i,y+4);cout << NGANG;
	}
	gotoXY(x+60,y+4); cout <<GOC3;
}

void End(){
	int x = 45;
	int y = 5;
	Xoa_Full_Man_hinh();
	while(true){
	TextColor(rand() % (13-2+1)+2);
	gotoXY(x,y+5); cout <<"                           .-.      .-.                       .-.  .-.  .-.";
	gotoXY(x,y+6); cout <<"                           : :      : :                       : :  : :  : :";
	gotoXY(x,y+7); cout <<"                           : :      : :                       : :  : :  : :";
	gotoXY(x,y+8); cout <<" .--.    .--.    .--.    .-' :      : `-.   .-..-.   .--.     : :  : :  : :";
	gotoXY(x,y+9); cout <<"' .; :  ' .; :  ' .; :  ' .; :      ' .; :  : :; :  ' '_.'    :_;  :_;  :_;";
	gotoXY(x,y+10);cout <<"`._. ;  `.__.'  `.__.'  `.__.'      `.__.'  `._. ;  `.__.'    :_;  :_;  :_;";
	gotoXY(x,y+11);cout <<" .-. :                                       .-. : "; 
	gotoXY(x,y+12);cout <<" `._.'                                       `._.'  ";
	Sleep(80);
	}
}
