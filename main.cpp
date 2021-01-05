#include <iostream>
#include <stdio.h>
#include <windows.h>   
#include <vector>
#include <string.h>
#include <fstream>
#include "Console.h"
#include "LogScreen.h"          
#include "MenuScreen.h" 
#include "InputScreen.h"
#include "UpdateScreen.h"   
#include "SearchScreen.h"       
#include "StatisticalScreen.h"         
using namespace std;
                
//void Char_color(){
//	for(int i=0; i<500; i++){       
//		TextColor(i);
//		cout << i<<" "<<(char)i<<endl;
//	}          
//}  
      
int Run(){                                              
	HANDLE hStdin;   
	DWORD fdwMode, mode;                             
	INPUT_RECORD irInBuf ;  
	hStdin = GetStdHandle(STD_INPUT_HANDLE);       
    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;     
    Screen0(hStdin, irInBuf);                 
	while(true){
		switch(index1){           
			case -1: {        
				index1 = Screen1(hStdin, irInBuf);              
				break;       
			}      
			case 0:{
				index1 = Screen2(hStdin, irInBuf); 
				break; 
			}  
			case 1:{  
				index1 = Screen3(hStdin, irInBuf);
				break;   
			}
			case 2:{                
				index1 = ScreenSort(hStdin, irInBuf);  
				break;
			}   
			case 3:{       
				index1 = ScreenSearch(hStdin, irInBuf);  
				break; 
			}
			case 4:{
				index1 = ScreenStatistic(hStdin, irInBuf); 
				break;
			}      
		}       
	}                    
}        
               
                                           
        
int main(){                       
	resizeConsole(1300,800);                        
	Run();         
//	Char_color();   	  
	return 0;
}

