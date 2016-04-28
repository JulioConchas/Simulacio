#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;
#define MAX_LENGHT     128
#define ENTER           13
#define BACKSPACE        8

    char ch;
    char password[MAX_LENGHT];
    const char *mypass="asilas";
    int pos=0;

int main()
{
   cout <<"Please enter the password:\n";
   while(true)
     {
       ch=getch();
       if(pos>=MAX_LENGHT) {cout<<'\a'; continue;} /* beep if password is too long */

       if(ch==ENTER) break;  /* User have pressed ENTER*/

       else if(ch==BACKSPACE)  /* BACKSPACE was pressed*/
         {
           cout <<"\b \b";
           password[--pos]='\0';
         }
       else/* A..Z a...z  BUG: I forgot what... */
         {
           cout <<"*";
           password[pos++]=ch;
           password[pos]='\0';
         }
       if(pos<=0) pos=0;
     }

 /*if(strcmp(password,mypass)==0) cout <<"\nCorrect password!\n";
 else  cout <<"\nAccess denied!\n";
*/


    cout.flush();
    cin.get();
    return EXIT_SUCCESS;
}
