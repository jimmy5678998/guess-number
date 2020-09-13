# guess-number
This is a simple program about guessing the number, you can choose difficulty and mode to have fun.

Difficulty:
There are 4 difficulty: 1. Easy(1-10) 	 2. Medium(1-100)	 3. Hard(1-10000)	 4.Insane(1-10000000), with 3 hidden difficulty, you can find them from code.

Mode:
You can choose player mode, where you will be the player and guess the number by yourself. Or you can choose auto mode, watching the program solve the game. 
Auto mode uses simple random number generating code to solve it, but I am new to C++ so there are some bugs on it, it is not a good program and need to be refined.

The game flow:
Player mode:
 * 1.choose difficulty
 * 2.input guess number
 * 3.tell wrong or correct, give hints for number is larger or smaller than answer
 * 4.counter+1
 * 5.repeat 2-4 until success, tell counter number to indicate how many time you try
 if auto mode:
 * 1.replace step 2 with generating a random number
 * 2. step3
 * 3. step4
 * 4. restricting the random number range
