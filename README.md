#Expected Summary Code:
Should go to Host: ecse3038-lab5-tester.onrender.com on route message and print out the 2 lines on an lcd using an esp32 using a get request and api key

##void_setup 
sets baud rate and initialises lcd and connects device to internet

##void_loop
continuously performs the http get request on the route /message at given api then converts the javascript which the the 2 lines of text are contained into to character arrays to be printed on lcds. 
It also returns the https status as well within the http.begin to http.end block.

#Riddle: I have no wings but I can fly, you look at me in the sky. What am I. 
