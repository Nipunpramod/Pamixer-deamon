## Pamixer-deamon for pulse audio 
This is simple tool  for pulse audio control on the function keys . You can easily install on your computer . This tool not only for function keys it can use any keys in your computer . All you have to do is follow instruction .

- **findKeyboard** is simple shell script for find keyboard event 

   		 ./findKeyboard
    
![](assets/1.jpg)
   
-  Afterthat you must edit **config.txt** file 

   		 nano config.txt
    
![](assets/2.png)

- This executeable file find youre function key code . 

    	 sudo  ./findkeys

![](assets/3.jpg)

- After that, you need to edit **src/pamixer-deamon.c** file with the values obtained earlier.

   		 nano src/pamixer-deamon.c

![](assets/4.png)

- After you run **install** shell script . Thats all

    	sudo ./install
    
![](assets/5.jpg)



   

`    

 
