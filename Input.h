#pragma once
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <vector>
#include <string.h>
#include "Console.h"
#include "Interface.h"
using namespace std;

void FormatDate(char *a, int vitri, COORD toado);
/*-----------------------------------------Cac phuong thuc nhap tu ban phim---------------------------------------------------------------*/
int Screen2_key_event(KEY_EVENT_RECORD ker, COORD toado, char *a, int size);
int Screen2_key_alphabet(KEY_EVENT_RECORD ker, COORD toado, char *a,  int size);
int Screen2_key_number(KEY_EVENT_RECORD ker, COORD toado, char *a, int size);
int KeyEventSearch(KEY_EVENT_RECORD ker, COORD toado, char *a, int size);
int KeyNumberSearch(KEY_EVENT_RECORD ker, COORD toado, char *a, int size);

bool Check_Full(LIST_THIET_BI* list ,THIETBI &ttb, COORD &toado);//Kiem tra tat ca cac truong da duoc dien chua
bool SaveList(LIST_THIET_BI* list ,THIETBI &ttb, COORD &toado);
/*-----------------------------------------------------Cac ham xu ly chuot-----------------------------------------------------*/
int Screen2_Mouse_move(MOUSE_EVENT_RECORD mer,LIST_THIET_BI &list, COORD &toado);
int Screen2_Mouse_click(MOUSE_EVENT_RECORD mer,LIST_THIET_BI &list, COORD &toado, THIETBI &ttb);
int Screen2_Mouse_event(MOUSE_EVENT_RECORD mer,LIST_THIET_BI &list, COORD &toado, THIETBI &ttb);
void ResetInput(LIST_THIET_BI &list, COORD &toado, THIETBI &ttb);
void XuLyToaDo(KEY_EVENT_RECORD ker, COORD &toado, THIETBI &ttb);


void FormatDate(char *a, int vitri, COORD toado){
	if(a[0]>='4' && a[0]<='9'){
		a[1] = a[0];	a[0] = '0';
		gotoXY(toado.X, toado.Y);
		cout << a[0]<<a[1];
		vitri = 2;
	}
	if(a[3]>='2' && a[3]<='9'){
		a[4] = a[3];	a[3] = '0';
		gotoXY(toado.X+3, toado.Y);
		cout << a[3]<<a[4] ;
		vitri = 5;
	}
	if(vitri == 2 || vitri == 5){
		a[vitri] = '/';
		cout<<a[vitri]; 
	}
}

void ResetInput(LIST_THIET_BI &list, COORD &toado, THIETBI &ttb){
	THIETBI temp;
	ttb = temp;
	toado.X = 0; toado.Y = 1;
	XoaDulieu();
	while(!list.empty()){
		list.pop_back();
	}
}

int Screen2_key_event(KEY_EVENT_RECORD ker, COORD toado, char *a, int size){
	int vitri = strlen(a);	
	gotoXY(toado.X + vitri, toado.Y);
	char key = ker.uChar.AsciiChar;
	TextColor(11);
	if(ker.bKeyDown ){
		if(vitri < size-1){
			if(( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' ) || (key == SPACE) || (key == '-')){
				cout <<key;
				a[vitri] = key;
			}
		}
		if(key == BACKSPACE && vitri > 0)
		{	vitri--;
			a[vitri] = '\0';
			gotoXY(toado.X+vitri, toado.Y);
			cout<<" ";
			gotoXY(toado.X+vitri, toado.Y);
		}  
	}
	return 1;
}   

int Screen2_key_alphabet(KEY_EVENT_RECORD ker, COORD toado, char *a,  int size){
	int vitri = strlen(a);	
	gotoXY(toado.X + vitri, toado.Y);
	char key = ker.uChar.AsciiChar;
	TextColor(11);
	if(ker.bKeyDown ){
		if(vitri < size-1){
			if(( key >= 'A' && key <= 'Z') || ( key >='a' && key <= 'z' ) || (key == SPACE)){
				cout <<key;
				a[vitri] = key;
			}
		}
		if(key == BACKSPACE && vitri > 0)
		{	vitri--;
			a[vitri] = '\0';
			gotoXY(toado.X+vitri, toado.Y);
			cout<<" ";
			gotoXY(toado.X+vitri, toado.Y);
		}
	}
	return 1;
}

int Screen2_key_number(KEY_EVENT_RECORD ker, COORD toado, char *a, int size){
	int vitri = strlen(a);	
	gotoXY(toado.X + vitri, toado.Y);
	char key = ker.uChar.AsciiChar;
	TextColor(11);
	if(ker.bKeyDown){
		if(vitri < size-1){
			if(( key <= '9' && key >= '0')){
				cout <<key;
				a[vitri++] = key;
				if(toado.X == 90 || toado.X == 110){
					FormatDate(a,vitri,toado); 
				}
			}
		}
		if(key == BACKSPACE && vitri > 0)
		{	vitri--;
			a[vitri] = '\0';
			gotoXY(toado.X+vitri, toado.Y);
			cout<<" ";
			gotoXY(toado.X+vitri, toado.Y);
		}
	}	
	return 1;
}

int KeyEventSearch(KEY_EVENT_RECORD ker, COORD toado, char *a, int size){
	int vitri = strlen(a);	
	gotoXY(toado.X + vitri, toado.Y);
	char key = ker.uChar.AsciiChar;
	gotoXY(23,0);
	cout << key;
	TextColor(11);
	if(ker.bKeyDown ){
		if(vitri < size-1){
			if(( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' ) || (key == SPACE) || (key == '-')){
				gotoXY(toado.X + vitri, toado.Y);
				cout << key;
				gotoXY(toado.X + vitri+1, toado.Y);
				cout << "_";
				a[vitri] = key;
			}
		}
		if(key == BACKSPACE && vitri > 0)
		{	vitri--;
			a[vitri] = '\0';
			gotoXY(toado.X+vitri, toado.Y);
			cout<<"_";
			gotoXY(toado.X+vitri+1, toado.Y);
			cout <<" ";
			gotoXY(toado.X+vitri, toado.Y);
		}  
	}
	return 1;
}    

int KeyNumberSearch(KEY_EVENT_RECORD ker, COORD toado, char *a, int size){
	int vitri = strlen(a);	
	gotoXY(toado.X + vitri, toado.Y);
	Hien_tro_chuot();
	char key = ker.uChar.AsciiChar;
	TextColor(11);
	if(ker.bKeyDown ){
		if(vitri < size-1){
			if(( key <= '9' && key >= '0')){
				cout <<key;
				a[vitri++] = key;
				if(index3 == 2 || index3 == 3){
					FormatDate(a,vitri,toado); 
				}
			}
		}
		if(key == BACKSPACE && vitri > 0)
		{	vitri--;
			a[vitri] = '\0';
			gotoXY(toado.X+vitri, toado.Y);
			cout<<" ";
			gotoXY(toado.X+vitri, toado.Y);
		}
	}
	return 1;
} 


bool Check_Full(LIST_THIET_BI* list ,THIETBI &ttb, COORD &toado){
	if(strlen(ttb.maTTB) == 0){
		Note_Frame("                Ma Trang Thiet Bi IS EMPTY!!!"); return false;
	}else if(strlen(ttb.tenTTB) == 0){
		Note_Frame("               Ten Trang Thiet Bi IS EMPTY!!!"); return false;
	}else if(strlen(ttb.nsx) == 0){
		Note_Frame("                Ngay San Xuat IS EMPTY!!!"); return false;
	}else if(strlen(ttb.nsd) == 0){
		Note_Frame("               Ngay Su Dung IS EMPTY!!!"); return false;
	}else if(strlen(ttb.chung_loai) == 0){
		Note_Frame("                 Chung loai IS EMPTY!!!"); return false;
	}else if(atoi(ttb.cap) <1|| atoi(ttb.cap) >5){ 
		Note_Frame("                       Cap IS EMPTY !!!"); return false;
	}
	return true;
}


bool SaveList(LIST_THIET_BI* list ,THIETBI &ttb, COORD &toado){
	THIETBI temp;
	if(Check_Full(list, ttb, toado) == false) return false;
	else{
		if(toado.Y <=9){
			list->push_back(ttb);
			ttb	= temp;	
			toado.X = 0;	toado.Y++;
		}else Note_Frame("              TABLE IS FULL! PLEASE SAVE OLD DATA!   ");
	}
	return true;

	
}

int Screen2_Mouse_click(MOUSE_EVENT_RECORD mer,LIST_THIET_BI &list, COORD &toado, THIETBI &ttb){
	if(mer.dwMousePosition.X >=1 && mer.dwMousePosition.X <= 25 && mer.dwMousePosition.Y >=1 && mer.dwMousePosition.Y <= 3){
			return -1;
		}
		if(mer.dwMousePosition.X >=75 && mer.dwMousePosition.X <= 95 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 36){
			Button(80, 33, "     SAVE", true);
			InFile("Input.txt",&list, "a+b");
			Button(80, 33, "     SAVE", false);
			ResetInput(list, toado, ttb);
		}	
		for(int i=0; i<10; i++){ 
			if(mer.dwMousePosition.Y >= (11+i*2) && mer.dwMousePosition.Y <= (13+i*2)){
				toado.Y = (i+1);
				if(mer.dwMousePosition.X >= 24 && mer.dwMousePosition.X <=31 )toado.X = 0;
				if(mer.dwMousePosition.X >= 32 && mer.dwMousePosition.X <= 57) toado.X = 1;
				if(mer.dwMousePosition.X >= 58 && mer.dwMousePosition.X <= 86) toado.X = 2;
				if(mer.dwMousePosition.X >= 87 && mer.dwMousePosition.X <= 105) toado.X = 3;
				if(mer.dwMousePosition.X >= 106 && mer.dwMousePosition.X <= 123) toado.X = 4;
				if(mer.dwMousePosition.X >= 124 && mer.dwMousePosition.X <= 141) toado.X = 5;
				if(mer.dwMousePosition.X >= 142 && mer.dwMousePosition.X <= 152) toado.X = 6;
			}
		}
}


int Screen2_Mouse_move(MOUSE_EVENT_RECORD mer,LIST_THIET_BI& list, COORD &toado){
	if(mer.dwMousePosition.X >=70 && mer.dwMousePosition.X <= 105 && mer.dwMousePosition.Y >=30 && mer.dwMousePosition.Y <= 40){
			An_tro_chuot();
			if(mer.dwMousePosition.X >=75 && mer.dwMousePosition.X <= 95 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 35){
				Button(80, 33, "     SAVE",true);
			}else Button(80, 33, "     SAVE",false);
			Hien_tro_chuot();
		}
		if(mer.dwMousePosition.X >=0 && mer.dwMousePosition.X <= 30 && mer.dwMousePosition.Y >=0 && mer.dwMousePosition.Y <= 9){
			An_tro_chuot();
			if(mer.dwMousePosition.X >=1 && mer.dwMousePosition.X <= 25 && mer.dwMousePosition.Y >=1 && mer.dwMousePosition.Y <= 3){
				Button(1,1,"     BACK", true);
			}else Button(1,1,"     BACK", false);
			Hien_tro_chuot();
		}
}


int Screen2_Mouse_event(MOUSE_EVENT_RECORD mer,LIST_THIET_BI &list, COORD &toado, THIETBI &ttb){
	if(mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
		if(Screen2_Mouse_click(mer,list,toado,ttb) == -1)
			return -1;
	}else if(mer.dwEventFlags == MOUSE_MOVED){
		Screen2_Mouse_move(mer,list,toado);
	} return 0;
} 

   

