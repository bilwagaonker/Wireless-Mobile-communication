# Wireless-Mobile-communication

- The need of safety for our homes can be accomplished by making the locks more electrical and coping up with the upcoming technology of internet of things. This idea is not just confined to the small spaces but also the large spaces like industrial spaces. For example, some technology devices are used for automatic door locking and unlocking.Such systems are usually made using digital keypads, RFID card readers etc. 
- The main objective of this project is to provide safety to personal spaces like home.
- In this system the user will be setting the password and when the correct passcode is entered, user will be given access by unlocking the door.
- If any intruder tries unlocking then the buzzer will create alarm and in the meantime SMS will be sent to the user alarming about intruder at the door.
- Main idea behind this project is a door opening system using a keypad and turning the buzzer on to give the alarm in case wrong password is entered and sending message using the GSM SIM800C module. LCD Display is used to display the status of the password entered. After 3 times of entering wrong code, it doesn’t allow to enter any further keys. GSM is the most secure mode of communication that has been established till now and it is the secure way through which messages get delivered. Another advantage of GSM Module is that the communication is possible from remote locations that don’t have internet connection.

# Arduino Code

You can download the code from the repo. (file is named as final_code.ino)

# Some hardware and output images

After giving the power supply and uploading the code to the Arduino Board, “Enter password” message appears. 
![image](https://user-images.githubusercontent.com/57268153/122006024-f361d280-cdd3-11eb-981d-2ada4b302263.png)

While entering the password, it appears in ** format, to maintain the privacy on display.
![image](https://user-images.githubusercontent.com/57268153/122006062-01175800-cdd4-11eb-82ca-de715b9552c1.png)

After entering the correct password with correct taps we get the message “Access Granted” “Welcome” and as we observe the servo motor has moved by 90 degrees. That means door has opened.
![image](https://user-images.githubusercontent.com/57268153/122006099-0ffe0a80-cdd4-11eb-9afc-14fafc153eeb.png)

Relocking message:	
![image](https://user-images.githubusercontent.com/57268153/122006126-1be9cc80-cdd4-11eb-8129-c0df25fcbc3a.png)

After a wrong tap, buzzer buzzes and LCD displays “Code Wrong”.
![image](https://user-images.githubusercontent.com/57268153/122006168-26a46180-cdd4-11eb-92b5-c38e1beb0e0a.png)

After maximum number (3) of wrong taps the buzzer buzzes for 5 seconds and LCD displays “Wait for 5 seconds”, “Access denied” after that.
![image](https://user-images.githubusercontent.com/57268153/122006245-3ae85e80-cdd4-11eb-816d-c47ab474aa1c.png)

![image](https://user-images.githubusercontent.com/57268153/122006308-4c316b00-cdd4-11eb-97c8-a988bcd50627.png)


