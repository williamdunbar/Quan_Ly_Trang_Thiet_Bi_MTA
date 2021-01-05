#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include "Console.h"
using namespace std;

struct ACCOUNT{
	char username[20];
	char password[20];
};

void Loading(){ 
	int x = 60;
	int y = 25;
	TextColor(12);
	gotoXY(x+20,y-2); cout << "FILE IS LOADING ... ";
	for(int i=0; i<=50; i++){ 
		TextColor(10);
		gotoXY(x+i-2,y);cout << LOADING;
		gotoXY(x+i-2,y+1);cout << LOADING;
		gotoXY(x+51-2,y); cout <<"   ";
		gotoXY(x+i-2,y+1);cout << LOADING;
		Sleep(80);
	}
}

void Khung_Dang_Nhap_hightlight(int a){
	int x = 69;
	int y ;
	if(a == 0){
		y = 9;
	}else y = 12;
	TextColor(380);
	gotoXY(x,y); cout <<"                                            ";
	gotoXY(x,y); cout <<"                                            ";	
	TextColor(3); 
}

void Khung_Dang_Nhap(){
	int x = 55, y = 7;
	TextColor(14);
	An_tro_chuot();
	gotoXY(x,y);	cout << GOC1;
	for(int i=1; i<61; i++){
		gotoXY(x+1*i,y);	cout << NGANG;
		Sleep(30);
	}
	gotoXY(x+60,y); cout <<GOC2;
	for(int j = 1; j<8; j++){
		gotoXY(x,y+j); cout<<DOC<<"                                                           "<<DOC;
		Sleep(30);
	}
	gotoXY(x,y+8); cout<<GOC4;
	for(int i=1; i<61; i++){
		gotoXY(x+1*i,y+8);cout << NGANG;
		Sleep(30);
	}
	gotoXY(x+60,y+8); cout <<GOC3;
	gotoXY(x+3,y+2); cout<<" USERNAME: ";
	gotoXY(x+3,y+5); cout<<" PASSWORD: ";
	TextColor(2);
	gotoXY(x+20, y-1); cout <<"DANG NHAP HE THONG";
	gotoXY(x+14,y+2);
	Khung_Dang_Nhap_hightlight(0);
	Khung_Dang_Nhap_hightlight(1);
	Khung_don(75,17,"      DANG NHAP   ");
}

bool Check_Account(ACCOUNT &account){
	char c[] = "myteacher";
	char d[] ="tongminhduc";
	TextColor(3);
	gotoXY(70,14);
	if(strcmp(account.username, c) == 0){
		if(strcmp(account.password,d) == 0){  
			cout<<"Wellcome teacher Tong Minh Duc !!!";
			An_tro_chuot();
			return true;
		}else {
			cout<<"Password is wrong !!!";
			return false;
		}
	}else{
		cout <<"Account is not exist !!!";
		return false;
	}
}

bool KeyEventProc(KEY_EVENT_RECORD ker, int &vitri, COORD toado, ACCOUNT &account )
{	char key = ker.uChar.AsciiChar;
	TextColor(124);
	if(ker.bKeyDown ){
		if(vitri <= 15){
			if(( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' ) || (key == SPACE)){
				if(toado.Y == 9) {
					cout <<key;
					account.username[vitri] = key;
				}
				if(toado.Y == 12){
					cout << "*";
					account.password[vitri] = key;	
				} vitri++;
			}
		}
		if(key == BACKSPACE && vitri > 0)
		{	vitri--;
			if(toado.Y == 9) account.username[vitri] = '\0';
			if(toado.Y == 12) account.password[vitri] = '\0';
			gotoXY(toado.X+vitri, toado.Y);
			cout<<" ";
			gotoXY(toado.X+vitri, toado.Y);
		}
		if(key == ENTER ){
			bool check = Check_Account(account);
			return check;
		}
	}
	return false;
}

bool Screen0_Mouse_event(MOUSE_EVENT_RECORD mer, int &vitri, ACCOUNT &account, COORD &toado)
{
	if(mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
			if(mer.dwMousePosition.X >= 69 && mer.dwMousePosition.X <=115 && mer.dwMousePosition.Y >= 9 && mer.dwMousePosition.Y <= 10){
				Hien_tro_chuot();
			 	vitri = strlen(account.username);
				gotoXY(69+vitri,9);
				toado.X = 69; toado.Y = 9;
			}
			else if(mer.dwMousePosition.X >= 69 && mer.dwMousePosition.X <=115&& mer.dwMousePosition.Y >= 12 && mer.dwMousePosition.Y <= 13){
				Hien_tro_chuot();
				vitri = strlen(account.password);
				gotoXY(69+vitri,12);
				toado.X = 69; toado.Y = 12;
			}else if(mer.dwMousePosition.X >= 75 && mer.dwMousePosition.X <=95&& mer.dwMousePosition.Y >= 17 && mer.dwMousePosition.Y <= 20){
				return Check_Account(account);
			}
	}
	if(mer.dwEventFlags == MOUSE_WHEELED){
		if(mer.dwButtonState == 4287102976){
			gotoXY(0,0); cout << mer.dwButtonState<<endl;
		}
		else if(mer.dwButtonState == 7864320){
			gotoXY(0,3); cout << mer.dwButtonState<<endl;
		} 
	}
	return false;
}

int Screen0(HANDLE &hStdin, INPUT_RECORD &irInBuf){
	DWORD cNumRead, i;
	
	
	Khung_Dang_Nhap();
	int vitri = 0;
	COORD toado;
	ACCOUNT account;
	account.username[0] = '\0';
	bool check = false;
    while(true){  
    		
    		ReadConsoleInput( hStdin, &irInBuf, 1, &cNumRead); 
	 		
            if(irInBuf.EventType == KEY_EVENT){
            	check = KeyEventProc(irInBuf.Event.KeyEvent, vitri, toado, account);
			}
			if(irInBuf.EventType == MOUSE_EVENT){
				check = Screen0_Mouse_event(irInBuf.Event.MouseEvent, vitri,account,toado);
			}
			if(check == true){
				Loading();
				break;
			}
	}
	Xoa_Full_Man_hinh();
	return 0;
}




