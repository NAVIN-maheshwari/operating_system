/*
 access :- we are asking for some permissions specified in mode

 1.Syntax :- 
     
     int access(const char *path, int mode)

 2.Return value:-

     if succeed return 0
     else return -1 or errno

 3.mode value :-

     F_OK :-  we are asking : is file exist or not ? (if yes return 0 else -1)
     X_OK :-  can i execute : (if yes return 0 else -1)   
     W_OK :-  can i write   : (if yes return 0 else -1)
     R_OK :-  can i read    : (if yes return 0 else -1)    

*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{
   const char*path = "C:\\Users\\Navin\\Desktop\\os\\filesystem\\abc.txt";
   
   int ans1  = access(path,F_OK);

   if(ans1 == 0)
   {
      printf("file exist %d \n",ans1);
   }
   else
   {
       printf("file not exist \n");
   }
//-----------------------------------------------------------//


   int ans2  = access(path,X_OK);

   if(ans2 == 0)
   {
      printf("YES you can execute the file %d \n",ans2);
   }
   else
   {
       printf("You can't execute a file \n");
   }


//-------------------------------------------------------------------//

   int ans3  = access(path,W_OK);

   if(ans3 == 0)
   {
      printf("Yes you can write %d \n",ans3);
   }
   else
   {
       printf("You can't write \n");
   }

//---------------------------------------------------------------------//

int ans4  = access(path,R_OK);

   if(ans4 == 0)
   {
      printf("Yes you can read %d \n",ans4);
   }
   else
   {
       printf("You can't read \n");
   }


  
}