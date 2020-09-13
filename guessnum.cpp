#include <iostream>     /* File: symbolic-constant.cpp */
#include <random>
#include <ctime>
using namespace std;
/*missions:
 * 1.define data type
 * 2.use loops(e.g. for loop)
 * 3.boolean value uses
 * 4.increment and modulo operation
 * 5.unsigned and signed numbers(coercion)*/

/*Questions:
 * 1. will the loop end with multiple semicolon during times that without using {}?
 * e.g. if(x==4) x++; y--; else y++; x--;
 */

//game version 1.1
// Explanation:
// make a program that guess the number
// have auto mode or player mode
// make a counter to count how many times you play the program successfully
// no end for program

/*Improvements:
 * 1. add initialize() for combining callgamemode() and difficulty
 * 2. Extract playing data to txt file*/
int callgamemode()
{
    int gamemode;
    cout <<"Select the mode(call the number):\n1.player mode\t2.auto mode\n" << ">";
    cin >> gamemode;
    cout << endl;
    return gamemode;
}

int change_difficulty(int difficulty)
{

    // six difficulty mode from 0-5, 5 is boss mode(0-10000000000), 0 and 6 is unlimited mode(range has no limitation), while 0 has no range hint
    cout << "Choose difficulty by inputting corresponding integer: \n" <<
         "1. Easy(1~10)\t 2. Medium(1~100)\t 3. Hard(1~10000)\t 4.Insane(1~10000000)\n>";
    cin >> difficulty;
    return difficulty;

}

void game(bool automode)
/* basically the game have these steps:
 * 1.choose difficulty
 * 2.input guess number
 * 3.tell wrong or correct, give hints for number is larger or smaller than answer
 * 4.counter+1
 * 5.repeat 2-4 until success, tell counter number to indicate how many time you try
 * if automode,
 * 1.replace step 2 with generating a random number
 * 2. step3
 * 3. step4
 * 4. restricting the random number range
 */
{
    long long unsigned range, num, guess_num, large_ans, small_ans, n_index,x,y,game_counter;
    double ans_range;
    int difficulty = 1;
    bool match = false;
    gamestart:
    difficulty = change_difficulty(difficulty);
    // range set for random generating numbers
    /*
    if (difficulty == 1)
    {
        range = 10;
    }
    else if (difficulty == 2)
    {
        range = 100;
    }
    else if (difficulty == 3)
    {
        range = 10000;
    }
    else if (difficulty == 4)
    {
        range = 10000000;
    }
    else if (difficulty == 5)
    {
        range = 1000000000000;
    }
    else if (difficulty == 0 or difficulty == 6)
    {
        range = 18446744073709551615;
    }
    else
    {
        cout<< "Enter a valid difficulty please";
        difficulty = 0;
        goto gamestart;
    }
     */
    switch (difficulty)
    {
        default:
            cout<< "Enter a valid difficulty please\n";
            difficulty = 0;
            goto gamestart;
        case 0:
            range = 18446744073709551615;
            break;
        case 1:
            range = 10;
            break;
        case 2:
            range = 100;
            break;
        case 3:
            range = 10000;
            break;
        case 4:
            range = 10000000;
            break;
        case 5:
            range = 1000000000000;
            break;
        case 6:
            range = 18446744073709551615;
            break;
    }
    // random is very hard
    random_device dev;
    mt19937 generator{static_cast<std::mt19937::result_type>(time(nullptr))};
    uniform_int_distribution<long long unsigned> dis(1,range);
    num = dis(generator);
    n_index = 1;

    //initialize hint for guess_num around ans
    for (int i = 3; i<=difficulty; i++)
    {
        n_index*=100;
    }
    ans_range = static_cast<double>(1)/static_cast<double>(100*n_index);
    large_ans = num+n_index;
    small_ans = num-n_index;
    //remove after test
    cout<<n_index << "\t"<<ans_range<<"\t"<< range<<"\t"<<num<<"\t"<<large_ans<<"\t"<<small_ans<<endl;
    //
    x = 1;
    y = range;
    game_counter = 0;
    while (!match)
    {   game_initialize:
        // auto mode solving vs player mode solving
        if (automode)
        {
            cout << "Type in your guess number:\n>";
            // random number generate
            random_device ar;
            mt19937_64 foo{static_cast<std::mt19937_64::result_type>(time(nullptr))};
            uniform_int_distribution<long long unsigned> ran(x,y);
            guess_num = ran(foo);
            cout << guess_num << endl;

        }
        else
        {
            cout << "Type in your guess number:\n>";
            cin >> guess_num;
        }
        game_counter +=1;
        if(guess_num <=0)
        {
            cout<< "Please type in a valid number!(from 1~"<<range<<")"<<endl;
            goto game_initialize;
        }
        if (difficulty>=3 && ((guess_num>=num && guess_num<=large_ans) or (guess_num<=num && guess_num>=small_ans)))
        {
            cout<<"Your guess number is already around the answer! The range is around "<<y-x<<" !"<<endl;
        }
        if (guess_num == num)
        {
            cout<< "Bingo! Congratulation!\nYou have tried "<< game_counter << " to guess the correct answer!"<<endl;
            match = true;
        }
        else if (guess_num  < num)
        {
            cout<< "Your guess number is smaller than the answer"<<endl;
            x=guess_num;

        }
        else if (guess_num  > num)
        {
            cout<< "Your guess number is larger than the answer"<<endl;
            y=guess_num;
        }

    }
}


int main()
{
    int gamemode, decision1;
    int counter = 0;
    int playercounter = 0;
    int autocounter = 0;
    int difficulty;
    bool decision = true;
    bool automode = false;

    // gamemode selection: player mode or auto mode
    cout << "\tGuess the Number!\n";
    gamemode = callgamemode();

    start:
    while (decision) {
        if (gamemode == 1)
            // player mode operations
        {
            automode = false;
            game(automode);
            playercounter++;
        }
        else if (gamemode == 2)
            // auto mode operations
        {
            automode = true;
            game(automode);
            autocounter++;
        }
        else
            // Enter correct number
        {
            cout << "Enter the valid number please\n>";
            cin >> gamemode;
            cout << endl;
            goto start;
        }
        counter++;


        // start next game?
        nextgame:
        cout << "Wanna to play again?\nInput the number:\n1.Play again\t2.Change gamemode\t3.print counter\t4.exit\n>";
        cin >> decision1;
        cout << endl;
        playagain:
        if (decision1 == 1)
            // Play again
        {
            goto start;
        }
        else if (decision1 == 2)
            // Change gamemode
        {
            gamemode = callgamemode();
        }
        else if (decision1 == 3)
            // print success game counter
        {
            cout << "You have play " << counter << " game(s), while " << playercounter<< " time(s) play in player mode, and "
                 << autocounter << " time(s) play in auto mode.";
            goto nextgame;
        }
        else if (decision1 == 4)
            // Exit
        {
            decision = false;
            cout << "Have a nice day, bye!";
        }
        else
            // Enter correct number
        {
            cout << "Enter the valid number please\n>";
            cin >> decision1;
            cout << endl;
            goto playagain;
        }
    }
    return 0;
}


