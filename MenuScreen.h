#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "Console.h"
#include"Interface.h"
using namespace std;



string Menu[6]={" Cap Nhat Danh Sach","    In Danh Sach","      Sap xep","      Tim kiem","      Thong Ke" ,"       Thoat"};
string Sap_xep[2] = {"    Thuat Toan", "      Tu Khoa"};
string Sx_Thuat_toan[4]={"   Selection Sort", "   Insertion Sort", "    Bubble Sort", "    Quick Sort"};
string Sx_Tu_khoa[5] = { " Ten Trang Thiet Bi", "   Ngay San Xuat","    Ngay Su Dung","     Chung Loai" ,"         Cap"};
string Tim_kiem[2] = { "      Tu Khoa","    Thuat Toan"};
string Tk_Thuat_Toan[2] = {"      Tuan Tu", "       Nhi Phan"};
string Tk_Tu_khoa[6] = {"       Ma TTB"," Ten Trang Thiet Bi", "   Ngay San Xuat","    Ngay Su Dung","     Chung Loai","         Cap"};
string Thong_ke[3] = {"   Ngay San Xuat","    Ngay Su Dung","       Cap"};

/*----------------------------------------------------------------------------------------------------------------------------------------------*/


void Khung_menu(int x, int y, string a[], int n){
	gotoXY(x,y);
	for(int i=0; i<n; i++){
		Khung_don(x,y + i*3,a[i]);
	}
	Khung_don(2,35,"     REFRRESH   ");
	TextColor(14);
	gotoXY(25, 36); cout <<"<-- Click here to reset menu";
	gotoXY(80, 36); cout <<"!!!  Click to choose anything you want !!!";
}

void Eraser(int x, int y){
	for(int i=0; i<28; i++){
		gotoXY(x,y+i); cout <<"                                                                                        ";
	}
}

void Reset(){
		index1 = -1;
		index2 = -1;
		index3 = -1;
		Eraser(25,8);
		Eraser(50,8);
		Khung_hieu_ung(2,35);
}


int Exit_function(MOUSE_EVENT_RECORD mouse){
	Exit_Frame();
	if(mouse.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
		if(mouse.dwMousePosition.X >=65 && mouse.dwMousePosition.X <= 80 && mouse.dwMousePosition.Y == 18){
		TextColor(4); gotoXY(70,13); cout<<"YES "; 
		TextColor(14); gotoXY(100,13); cout<<" NO ";
		Sleep(50); 
		return -2;
	}
	if(mouse.dwMousePosition.X >=95 && mouse.dwMousePosition.X <= 110 && mouse.dwMousePosition.Y == 18){
		TextColor(14); gotoXY(70,13); cout<<"YES "; 
		TextColor(4); gotoXY(100,13); cout<<" NO ";
		Sleep(50); 
		Reset();
	}
	}
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------*/


void Khung_menu_hieu_ung(int x, int y, string a[], int n, int k){
	gotoXY(x,y);
	for(int i=0; i<n; i++){
		if(i==k) Khung_hieu_ung(x,y+k*3);
		else Khung_don(x,y + i*3,a[i]);
	}
}

int Screen1_Mouse_event(MOUSE_EVENT_RECORD mer, int x, int y,string a[6],int n){
	if(mer.dwEventFlags == MOUSE_MOVED){
		for(int i=0; i<n; i++){
			if(mer.dwMousePosition.X >= x && mer.dwMousePosition.X <(x+20) && mer.dwMousePosition.Y > (y+i*3-1) && mer.dwMousePosition.Y <((y+i*3)+3)){
				Khung_menu_hieu_ung(x,y,a,n,i);
			}
		}
		if(mer.dwMousePosition.X <= x || mer.dwMousePosition.X >(x+20) || mer.dwMousePosition.Y <(y-1) || mer.dwMousePosition.Y >(y+n*3)){
			Khung_menu(x,y,a,n);
			if(mer.dwMousePosition.X >= 2 && mer.dwMousePosition.X <(2+20) && mer.dwMousePosition.Y > 35 && mer.dwMousePosition.Y <40) Khung_hieu_ung(2,35);
		}
	}
	if(mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
		for(int i=0; i<n; i++){
			if(mer.dwMousePosition.X >= x && mer.dwMousePosition.X <(x+20) && mer.dwMousePosition.Y > (y+i*3-1) && mer.dwMousePosition.Y <((y+i*3)+3)){
				Khung_hieu_ung(x,y+i*3);
				return i;
			}
		}
			if(mer.dwMousePosition.X >= 2 && mer.dwMousePosition.X <(2+20) && mer.dwMousePosition.Y > 35 && mer.dwMousePosition.Y <40) Reset();
	}
	return -1;
}

int Screen1(HANDLE &hStdin, INPUT_RECORD &irInBuf ) {
	Xoa_Full_Man_hinh();
 	DWORD  cNumRead,i; 
	Khung_menu(2,8,Menu,6);
	An_tro_chuot();
    while(true){  
    		ReadConsoleInput( hStdin, &irInBuf, 1, &cNumRead); 
	 		Welcome(); 
            if(irInBuf.EventType == MOUSE_EVENT){
                    switch(index1){
                    	case -1:{
                    		index1 = Screen1_Mouse_event(irInBuf.Event.MouseEvent, 2,8,Menu,6);break;
						}
                    	case 0: {
							index1 = -1;
							return 0;
						}
						case 1: {
							index1 = -1;
							return 1;
						}
						case 2:{
							switch(index2){
								case -1:{
									index2 = Screen1_Mouse_event(irInBuf.Event.MouseEvent, 25,14,Sx_Thuat_toan,4); break;
								}
								case 0:	case 1:	case 2: case 3:{
									index3 = Screen1_Mouse_event(irInBuf.Event.MouseEvent, 50,14,Sx_Tu_khoa,5); 
									if(index3 != -1)		return 2;
								}
							}break;
						}
						case 3:{
							switch(index2){
								case -1:{
									index2 = Screen1_Mouse_event(irInBuf.Event.MouseEvent, 25,17,Tk_Thuat_Toan,2);break;
								}
								case 0:	case 1: {
									index3 = Screen1_Mouse_event(irInBuf.Event.MouseEvent, 50,17,Tk_Tu_khoa,6);
									if(index3 != -1)	return 3;
								}
							}break;
						}
						case 4:{
							index2 = Screen1_Mouse_event(irInBuf.Event.MouseEvent, 25,20,Thong_ke,3);
							if(index2 == -1) break;
							else if(index2 == 0 || index2 == 1|| index2 == 2) return 4;
						}
						case 5:{
							index3 = Exit_function(irInBuf.Event.MouseEvent);
							if(index3 == -2){
								End();
							}
							break;
						}
					}
            } 
	}
}

