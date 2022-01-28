# Lab 1
#### Name: Matthew Teets
#### Date: 1/27/22
#### Class: CSCI 3800

#

This project creates a rudimentary server-client datagram that allows communinication between a server program and a client program.

#

### **The two programs:**
- server.c
  - Creates and binds a DGRAM socket to the server address
  - Server remains open, listening for datagram packets from the client program
  - Messages from the client is processed and printed to the terminal
  - These steps are looped until the program is manually terminated using Control + C
- client.c
  - Creates a datagram socket 
  - Promts the user for a message to send to the server
  - If successfully sent, conformation message will be displayed on both server and client side
  - These steps loop until the user sends the message 'STOP' to the server
    - This will terminate the client’s connection to the server
    
#

### **How to run:**
- Connect to CSE-grid
  - Example: ssh username@csegrid.ucdenver.pvt
  - Connect two terminal windows to this Linux server
    - One for the server and one for the client
- cd to the file containing the c programs and makefile

#

- Terminal window used to run server1.c
```
  $ host csci-gnode-NUM   (This will give the IP address for the server)
  $ make -f Makefile      
  $ ./server1 [SERVER-PORT-NUMBER]   (any number >= 1000)         
```
Example: $ ./server1 1234

#

- Terminal window used to run client1.c
```
  $ make -f Makefile
  $ ./client1 [SERVER-IP-ADDRESS] [SERVER-PORT-NUMBER]
```
Example: $ ./client1 132.534.194.53 1234
  
  
  
  
