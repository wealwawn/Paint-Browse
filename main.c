#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
//Libraries included above
//Constants defined below
#define NUM_COLORS 20
#define LEN_COLOR 21
#define LEN_FAMILY 10

//Function Prototypes and string pointer declarations
void displayWelcome(void);
void displayCredits(void);
void pauseRecords(void);
int selectOption(void);
char* toLower(char* s);
char *str1;
char *str2;
char *str3;



int main(void)
{
    //Integer declaration for the do loop condition
    int goAgain = 0;
    //Provided arrays declared
    char colors[NUM_COLORS][LEN_COLOR + 1] = {"Whisper White", "Sunwashed Brick", "Breezeway", "Etched Glass", "Lunar Surface", "Nightingale Gray", "Studio Clay",
                                              "Corn Stalk", "Wave Top", "After Rain", "Perfect Penny", "Basswood", "Sustainable", "Explorer Blue", "Dark Cobalt Blue", "Lingonberry Punch", "Wild Mustang", "Laurel Tree", "Ocean Abyss", "Cracked Pepper"
                                             };

    char families[NUM_COLORS][LEN_FAMILY + 1] = {"white", "orange", "blue", "gray", "gray", "gray", "white", "yellow", "blue", "blue", "orange", "neutral", "green", "blue", "blue", "red", "brown", "green", "teal", "gray"};
    //Option integer for switch statment declared, total declared and set to 0
    int option;
    int total = 0;
    //Call of displayWelcome
    displayWelcome();
    //Loop declared to iterate switch statement
    do
    {
        //selectOption is called to get user input
        option =  selectOption();

        switch(option)
        {

        //Display all Paints option
        case 1:
            //Total reset to 0
            total = 0;
            //For loop declared to iterate through every array entry
            for(int index=0; index<NUM_COLORS; index++)
            {
                //Prints out the information of the paint based on the index
                printf("%i) Family: %s  Color:%s \n", index+1, families[index], colors[index]);
                //Adds to the total as a criteria of the following if
                total++;
                //If statement to pause the records after 10
                if(total == 10)
                {
                    //fflush statement to clear the buffer after taking the option
                    fflush(stdin);
                    //Print to the user that they need to hit a key to get the rest of entries
                    printf("Press any key to continue.");
                    //Call of the pause records functionn
                    pauseRecords();
                }

            }
            break;


        //search for paints by family (exact match, case insensitive) and display the data and the number of matches
        case 2:
            //Total reset to 0 to be used to count number of matches
            total = 0;
            //Print to let the user know what input we are asking for
            printf("Enter the family of paints you wish to look for.");
            // Array declared and set to our str1 pointer to prep for fgets
            char family_Search[LEN_FAMILY];
            str1 = family_Search;
            // Fgets statement to receive input from the user
            fgets(str1, LEN_FAMILY, stdin);
            // For loop declared to iterate through the arrays
            for(int index=0; index<NUM_COLORS; index++)
            {
                //If statement declared checking to see if the strings are equal
                if (strncasecmp(str1, families[index], strlen(str1)-1 ) == 0)
                {
                    //Prints a match using the index
                    printf("%i) Family: %s  Color:%s \n", index+1, families[index], colors[index]);
                    //Total added to to track number of matches
                    total++;
                }
            }
            //Print to report the number of matches to the user
            printf("There are a total of %i matches.", total);
            break;
        //Search for paints by color (allow for partial matches, case insensitive) and display the data and the number of matches
        case 3:
            //Total cleared to prepare for the number of matches
            total = 0;
            //Print to let the user know what input we are asking for
            printf("Enter the color of paints you wish to look for.");
            // Array declared and set to our str1 pointer to prep for fgets
            char color_Search[LEN_FAMILY];
            str3 = color_Search;
            // Fgets statement to receive input from the user
            fgets(str3, LEN_COLOR, stdin);
            //toLower function used to make case insensitive search work
            toLower(str3);
            //strcspn used to strip newline character from fgets
            str3[strcspn(str3, "\n")] = 0;
            // For loop declared to iterate through the arrays
            for(int index=0; index<NUM_COLORS; index++)
            {
                //string set within loop
                str2 = colors[index];
                //toLower function used to make case insensitive search work
                toLower(str2);
                //If loop declared to compare the strings
                if (strstr(str2, str3) == 0)
                {
                // empty if statement to fall through, no idea why this works, tried to do != 0 instead
                }
                else
                {
                    //information printed of a match, tried to do this differently but this worked, no idea why
                    printf("%i) Family: %s  Color:%s \n", index+1, families[index], colors[index]);
                    //total added to count matches
                    total++;
                }
            }
            //number of matches printed
            printf("There are a total of %i matches.", total);
            break;
        //Exit case
        case 4:
            //Calls the displayCredits function to print a credits statement
            displayCredits();
            //sets goAgain to 1 to end the do while loop to return 0 in main
            goAgain =1;
            break;


        }

    }
    while(goAgain == 0);
}

    /*Function Name: displayWelcome
Purpose: To display a welcome message to the application
Parameters: void (none)
Return: void (none)
 */
void displayWelcome(void)
{
    printf("Welcome to Justin Nunley's paint program!\n");
}

    /*Function Name: selectOption
Purpose: To prompt the user and take input to return to main
Parameters: dvoid
Return: int option
 */
int selectOption(void)
{
    int option;
    do
    {
        printf("Please enter the number of the option you wish to select from below for information about the available products:\n");
        printf("1) Display All Products Data.\n 2) Search for paints by family(only exact matches, any case) \n 3) Search for paints by color(Takes partial matches, any case) \n 4)Exit \n");
        scanf("%d", &option);
        fflush(stdin);
    }
    while (option >= 5 || option <0);
    return option;
}


  /*Function Name: displayCredits
Purpose: To display a credits message for the application with my first and last name
Parameters: void (none)
Return: void (none)
 */
void displayCredits(void)
{
    printf("Thanks for using Justin Nunley's Paint Program!");
}

  /*Function Name: pauseRecords
Purpose: Uses a getchar statement in a do while loop with a negative test for a new line character
to pause between the records of all of the paint data. This logic was borrowed from a forum
when looking up information on how to pause between displayed information
Parameters: void (none)
Return: void (none)
 */
void pauseRecords(void)
{
    int key;

    do
    {
        key = getchar();
    }
    while (key != '\n');
}
  /*Function Name: toLower
Purpose: to iterate through a string and turns the characters to lowercase to use a case insensitive search
this was a function that a friend helped me to help with case insensitivy with strstr
Parameters: char* s (character pointer to a string)
Return: s
 */
char* toLower(char* s)
{
    for(char *p=s; *p; p++) *p=tolower(*p);
    return s;
}


/*
Test Data 1
1
enter
enter
4
Expected Results
It should welcome, display the options and ask for input on the option, then print the first 10 paints, say Press any key to continue,
then display the next 10 paints, and then reprompt the user for options, then displays the credits and ends the process

Test Data 2
2
GRAY
4
Expected Results
It should welcome, display the options and ask for input on the option. then ask the user for the family of paint they wish to search for
then print the matches(4 gray families) and the total matches(4), nd then reprompt the user for option, then displays the credits and ends the process

Test Data 3
3
WHIS
4
Expected Results
It should welcome, display the options and ask for input on the option. then ask the user for the color of paint they wish to search for
then print the matches(1, Whisper White) and the total matches(1), and then reprompt the user for option, then displays the credits and ends the process
 */

 /*
 Sample Run 1
Welcome to Justin Nunley's paint program!
Please enter the number of the option you wish to select from below for information about the available products:
1) Display All Products Data.
 2) Search for paints by family(only exact matches, any case)
 3) Search for paints by color(Takes partial matches, any case)
 4)Exit
1
1) Family: white  Color:Whisper White
2) Family: orange  Color:Sunwashed Brick
3) Family: blue  Color:Breezeway
4) Family: gray  Color:Etched Glass
5) Family: gray  Color:Lunar Surface
6) Family: gray  Color:Nightingale Gray
7) Family: white  Color:Studio Clay
8) Family: yellow  Color:Corn Stalk
9) Family: blue  Color:Wave Top
10) Family: blue  Color:After Rain
Press any key to continue.
11) Family: orange  Color:Perfect Penny
12) Family: neutral  Color:Basswood
13) Family: green  Color:Sustainable
14) Family: blue  Color:Explorer Blue
15) Family: blue  Color:Dark Cobalt Blue
16) Family: red  Color:Lingonberry Punch
17) Family: brown  Color:Wild Mustang
18) Family: green  Color:Laurel Tree
19) Family: teal  Color:Ocean Abyss
20) Family: gray  Color:Cracked Pepper
Please enter the number of the option you wish to select from below for information about the available products:
1) Display All Products Data.
 2) Search for paints by family(only exact matches, any case)
 3) Search for paints by color(Takes partial matches, any case)
 4)Exit
4
Thanks for using Justin Nunley's Paint Program!
Process returned 0 (0x0)   execution time : 4.655 s
Press any key to continue.

 Sample Run 2
Welcome to Justin Nunley's paint program!
Please enter the number of the option you wish to select from below for information about the available products:
1) Display All Products Data.
 2) Search for paints by family(only exact matches, any case)
 3) Search for paints by color(Takes partial matches, any case)
 4)Exit
2
Enter the family of paints you wish to look for.GRAY
4) Family: gray  Color:Etched Glass
5) Family: gray  Color:Lunar Surface
6) Family: gray  Color:Nightingale Gray
20) Family: gray  Color:Cracked Pepper
There are a total of 4 matches.Please enter the number of the option you wish to select from below for information about the available products:
1) Display All Products Data.
 2) Search for paints by family(only exact matches, any case)
 3) Search for paints by color(Takes partial matches, any case)
 4)Exit
4
Thanks for using Justin Nunley's Paint Program!
Process returned 0 (0x0)   execution time : 6.586 s
Press any key to continue.



 Sample Run 3
Welcome to Justin Nunley's paint program!
Please enter the number of the option you wish to select from below for information about the available products:
1) Display All Products Data.
 2) Search for paints by family(only exact matches, any case)
 3) Search for paints by color(Takes partial matches, any case)
 4)Exit
3
Enter the color of paints you wish to look for.WHIS
1) Family: white  Color:whisper white
There are a total of 1 matches.Please enter the number of the option you wish to select from below for information about the available products:
1) Display All Products Data.
 2) Search for paints by family(only exact matches, any case)
 3) Search for paints by color(Takes partial matches, any case)
 4)Exit
4
Thanks for using Justin Nunley's Paint Program!
Process returned 0 (0x0)   execution time : 6.322 s
Press any key to continue.
 */
