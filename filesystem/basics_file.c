#include<stdio.h>

// Header file needed

#include<fcntl.h>

/*

System calls needed for files and its syntax :-

1. creat :- Create file
    
    1. Syntax :-

           int creat(const char *path, mode_t mode)
           => creat(path,mode)

    2. Return value :-

        if(return value > 0)File discriptor (smallest integer) 
        else -1 in case of error(path not found  , we don't have access)

    3.mode :- We can add 256 Modes together 

        1.For particular "USER" :-
             S_IRUSR :-  USER read 
             S_IWUSR :-  USER write
             S_IXUSR :-  USER execute

        2.For "GROUP" :-
             S_IRGRP :-  GROUP read
             S_IWGRP :-  GROUP write
             S_IXGRP :-  GROUP execute

        3.For "OTHER" :-
             S_IROTH :-  OTHER read
             S_IWOTH :-  OTHER write
             S_IXOTH :-  OTHER execute     
                
        
2.open :- Open + Create file
    
     1. Syntax :-

         int open(const char *path, int modes ) 
          => open(path,mode)

          it behave like creat when mode = O_CREATE

     2. Return value:-

        if(return value > 0)File discriptor (smallest integer) 
        else -1 in case of error(path not found  , we don't have access)

     3. Modes :-

        Mendetory:-
         1.O_RDONLY :- for read
         2.O_WRONLY :- for write
         3.O_RDWR   :- for execute

        Optional     
         4.O_CREATE :- If file is note available it creates a file **(It work similar to "creat")
         5.O_APPEND :- do not delete prevous content , add new content
         6.O_TRUNC  :- remove whole content
         7.O_EXCL   :- Exclusive open with some extra previlages
         8.O_RSYNC  :- Read mode syncronization
         9.O_SYNC   :- write mode sync 


3.fcntl :- We can apply some control on the file specified in Flag field
      
      1.Syntax :-
          
          int fcntl(int file discriptor, int flag)

      2.Return value :-
          
          1.Upon successful completion, the value returned depends on flag
          2. -1 or error if faild

      3.flag :-

          1.F_DUPFD :- Make exact copy of file discriptor  *
          2.F_GETFD :- Return file discriptor
          3.F_SETFD :- Set file discriptor 
          4.F_GETFL :- get status flag
          5.F_SETFL :- get status flag

4.Link :- Creates a duplicate (copy) of given file
   
      1. Syntax :-

          int link(const char *path1, const char *path2)

          path1 = actual path of file
          path2 = duplicate path of file
             
      2.Return value :-

          0 if success
         -1 or error if unsuccessful (path1 or path2 Not exist)
      
      3.Header file :- 

          #include<unistd.h>


5.Unlink :- Remove a path duplicate copy / Contradict of link

      1. Syntax:-

          int unlink(const char *path)

          remove a path inside it;
     
       2.Return value :-

          0 if success
         -1 or error if unsuccessful (path Not exist)

       3.Header file :- 

          #include<unistd.h>

6.read :- Read from file
   
       1.Syntax:-
         
         int read(int file discriptor, void *buffer, int no_of_bytes)

         buffer      = Stores the data you read from file
         no_of_bytes = Number of bytes you want to read from file 

       2.Return value:-

          Number of bytes you actually readed from file  
          -1 if error

       3.Header file:-
          
           #include<unistd.h>
        
 7.write :-Write into a file
   
       1.Syntax:-
         
         int write(int file discriptor, void *buffer, int no_of_bytes)

         buffer      = Write the data into the file from this buffer
         no_of_bytes = Number of bytes you want to write into file 

       2.Return value:-

          Number of bytes you actually Written into file  
          -1 if error

       3.Header file:-
          
           #include<unistd.h>

 8.lseek :- Move cursor of file (By default the cursor is set to end of content when writing else set to top left corner)   

       
          1.syntax:-

            int lseek(int file discriptor, int offset, int whence)  

            offset :- Number of byte (left,right) shift the cursor based on the value of whence

            whence :- 

                1.SEEK_SET :-  the file offset shall be set to offset bytes.

                2.SEEK_CUR :- the file offset shall be set to its current location plus offset.

                3.SEEK_END :- the file offset shall be set to the size of the file plus offset     
           
          2. Return value:-

               offset value from the bigning  
              -1 if error
           
           3.Header file:-
               
               #include<unistd.h>


9.pwrite :-
10.access:-
11.close :-


12.dup    :-  Duplicates an file discriptor
13.dup2   :-  Both are similar dup and dup2

         1.Syntax:-
             
             int dup(int file discriptor);
             int dup2(int fd1, int fd2);

         2.Return value:-

             File discriptor of success
             -1 or error if faild    

14.mkdir:-
15.mknode:-
16.INODE :- information releted to file             

*/