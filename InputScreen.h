#pragma once
#include<iostream>
#include"Console.h"
#include"Input.h"
#include"Interface.h"
using namespace std;

#define	TABLE_NGANG	char(196)
#define TABLE_DOC	char(179)
#define TABLE_GOC1	char(218)
#define TABLE_GOC2	char(191)
#define TABLE_GOC3	char(217)
#define TABLE_GOC4	char(192) 

void XuLyEnter(KEY_EVENT_RECORD ker,LIST_THIET_BI* list,THIETBI &ttb, COORD &toado);
int Screen2(HANDLE &hStdin, INPUT_RECORD &irInBuf);
/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void XuLyEnter(KEY_EVENT_RECORD ker,LIST_THIET_BI* list,THIETBI &ttb, COORD &toado){
	char key = ker.uChar.AsciiChar;
	if(ker.bKeyDown){
		if(key == ENTER){
			if(toado.X == 7){
				SaveList(list,ttb, toado);
			}else {
				toado.X++;	
			}
		}
	}
}


void XuLyToaDo(KEY_EVENT_RECORD ker, COORD &toado, THIETBI &ttb){
	COORD local_coord;
	for(int i = 1; i<=10;i++){
		TextColor(11);
		if(toado.Y == i) local_coord.Y = 10+i*2;
	}if(toado.X == 0){
		gotoXY(27,local_coord.Y);
		cout << toado.Y;
		gotoXY(35,local_coord.Y);
		toado.X = 1;
	}else if(toado.X == 1){
		local_coord.X = 40 ;
		Screen2_key_event(ker, local_coord, ttb.maTTB,10);
	}else if(toado.X == 2){
		local_coord.X = 65;
		Screen2_key_event(ker, local_coord, ttb.tenTTB,30);
	}else if(toado.X == 3){
		local_coord.X = 90;
		Screen2_key_number(ker,local_coord, ttb.nsx,11);
	}else if(toado.X == 4){
		local_coord.X = 110;
		Screen2_key_number(ker,local_coord, ttb.nsd, 11);
	}else if(toado.X == 5){
		local_coord.X = 128;
		Screen2_key_alphabet(ker,local_coord, ttb.chung_loai,20);
	}else if(toado.X == 6){
		local_coord.X = 145;
		Screen2_key_number(ker,local_coord, ttb.cap,2);
	}
}


int Screen2(HANDLE &hStdin, INPUT_RECORD &irInBuf){
	LIST_THIET_BI list;
	DWORD cNumRead, i; 
	COORD toado; toado.X=0; toado.Y =1;
	Xoa_Full_Man_hinh();
	THEMMOIDANHSACH();
	Table();
	Hien_tro_chuot();
	THIETBI ttb;
	char a[20];
    while(true){  
    		ReadConsoleInput( hStdin, &irInBuf, 1, &cNumRead); 
			if(irInBuf.EventType == MOUSE_EVENT){
				if(Screen2_Mouse_event(irInBuf.Event.MouseEvent,list, toado,ttb) == -1)
					return -1;
			}
			else if(irInBuf.EventType == KEY_EVENT){
				XuLyEnter(irInBuf.Event.KeyEvent,&list,ttb, toado);
			}
			XuLyToaDo(irInBuf.Event.KeyEvent,toado,ttb);
	}
}  
