//Jesus Uribe Final

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <thread>

using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;
void Setup()
{
	//system start
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void Draw()
{	
	system("cls"); //system("clear");
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;
	//establishes grid and Worm 
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			//Grid
			if (j == 0)
				cout << "#";
			//Worm
			if (i == y && j == x)
				cout << "O";
			//Food
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}
	//Size of grid
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;
	//Score displayed on screen
	cout << "Score:" << score << endl;
}
void Input()
{
	//User input for worms direction.
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}
void Logic()
{
	
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	//if (x > width || x < 0 || y > height || y < 0)
	//	gameOver = true;
	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;
	//Game ending code
	for (int i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
	//Score count and how it is done
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}
//Thread made for music
void threadFn() {
	PlaySound(TEXT("Song.wav"), NULL, SND_LOOP | SND_SYNC);
}
int main()
{
		//call upon thread to paly song
		thread t1(threadFn);
		char name[50];
		cout << "What is your name?" << endl;
		//Name input
		cin.getline(name, 50);
		cout << name << " The other worms around have heard that you want to be the biggest worm on the tree. Word has it that there is a hidden area that has unlimited amnount of food." << endl;
		cout << "\n----------------------Press any key to continue----------------------" << endl;
		_getch();

		//choice one in game
		system("cls");
		int choiceOne_Path;
		cout << "Will you listen to this random worm?" << endl;
		cout << "\t >> Enter '1' to listen." << endl;
		cout << "\t >> Enter '2' to crawl away." << endl;
	retry:
		cout << "\nEnter your choice: ";
		//players choice input
		cin >> choiceOne_Path;
		//if stament player input 1
		if (choiceOne_Path == 1)
		{
			cout << "\n!!!----------------------Location of the hidden area.----------------------!!!" << endl;
			cout << "\n You will listen really!!!......... Ahem I mean ok before we start my name is Nick." << endl;
			cout << "I have came to this area because no one in my hometown is alive they all got eaten by birds." << endl;
			cout << "I told all of them of a way to become bigger so no birds can eat us but they didn't listen." << endl;
			
		}
		//else if statement player input 2
		else if (choiceOne_Path == 2)
		{
			cout << "\n!!!----------------------Attenion has been grabbed.----------------------!!!" << endl;
			cout << "\nYou: Crawl away" << endl;
			cout << "Random worm: Look this is exactly why everyone in my hometown is dead please just listen." << endl;
			cout << "Random worm: My name is Nick and I know the hidden area that holds unlimited food its just im to scared to go I need your help!" << endl;
			cout << "\nYou: Stop crawling and look at Nick okay fine I will help you I got nothing better to do plus if this is true then I can get big faster." << endl;
		}
		//else statement for if 1 or 2 arent input
		else
		{
			cout << "You are doing it wrong! Press either '1' or '2', nothing else!" << endl;
			goto retry;
		}
		cout << "\n----------------------Press any key to continue----------------------" << endl;
		_getch();
		//choice two in game
		system("cls");
		int choiceTwo_Path;
		cout << "\n!!----------------------Story continues--------------------------------!!" << endl;
		cout << "Now that you and Nick are a group Nick wants to get ready for the quest.";
		cout << "\n >> Enter '1' Help Nick get ready and pack food. " << endl;
		cout << " >> Enter '2' Tell Nick he can stick it where the sun dont shine and that you will not help because that will make you loose the weight you have packed on. " << endl;
		//players choice input
		cin >> choiceTwo_Path;
		////if stament player input 1
		if (choiceTwo_Path == 1)
		{
			cout << "\n!!!----------------------Page 2: Helping Nick----------------------!!!" << endl;
			cout << "Nick: Thanks you helping me " << name << "  why didnt you call me crazy or anything when I first told you about this place." << endl;
			cout << "You: I mean you had no reason for me not to beleive you plus I have nothing to loose and everything to gain." << endl;
			cout << "Nick: I wish there were people like you back where I came from." << endl;
			cout << "You: You know if this place could have helped your people why didn't you go there?" << endl;
			cout << "Nick: I didnt go because I couldnt handle the amount of food provided I wasnt worthy." << endl;
			cout << "You: Well lucky for you I am one of the bigger worms in this area so I can promise you I will eat everything if this place is true." << endl;
		}
		//else if statement player input 2
		else if (choiceTwo_Path == 2)
		{
			cout << "\n!!!----------------------Page 2: Not helping Nick----------------------!!!" << endl;
			cout << "\nYou: Man I cant do that I will loose the weight I have gained go stick it where the sun dont shine bud." << endl;
			cout << "Nick: The hell you say to me?" << endl;
			cout << "You: You heard me Dick......." << endl;
			cout << "Nick: The NAME IS NICK!!! "<< name <<"  AND YOU ARE GONNA HELP ME PACK YOU LAZY ASS!!!" << endl;
			cout << "Nick slaps you with his tail sits ontop of you." << endl;
			cout << "You: 'I never noticed how big this guy is how did he get so big'>" << endl;
			cout << "Nick: You gonna help now?" << endl;
			cout << "You: Fine!!" << endl;
			cout << "You begin to help Nick pack" << endl;
			cout << "You: You know if this place could have helped your people why didnt you go there?" << endl;
			cout << "Nick: I didnt go because I couldnt handle the amount of food provided I wasnt worthy." << endl;
			cout << "You: Well lucky for you I am one of the bigger worms in this area so I can promise you I will eat everything if this place is true." << endl;
		}
		//else statement for if 1 or 2 arent input
		else
		{
			cout << "You are doing it wrong! Press either '1' or '2', nothing else!" << endl;
			goto retry;
		}
		cout << "\n----------------------Press any key to continue----------------------" << endl;
		_getch();
		system("cls");
		//Game continues no more choices 
		int choiceThree_Path;
		cout << "\n!!----------------------Story continues--------------------------------!!" << endl;
		cout << "You and Nick have traveled far and wide and are now at the front door of the area with unlimited food." << endl;
		cout << "You: so Nick how do we get in these doors?" << endl;
		cout << "Nick: The door has diffrent kinds of systems to get in we will find out once we touch the part here" << endl;
		cout << "Door Keeper: Who dares touch me!!!!!" << endl;
		cout << "Nick: We want to go in so we can have unlimited food and become the biggest worms in the world!!!!" << endl;
		cout << "Door Keeper: Getting in wont be so easy you dumb worms now you are going to have to play a little game to be able to enter my domain." << endl;
		cout << "You: Wait really developer this is the way we get in couldnt it have been a cool battle or some............" << endl;
		cout << "Door Keeper: Quiet!!!!! You think a little worm like you has a say now Play THE GAMEEEE!" << endl;
		
		
		
		cout << "\n----------------------Press any key to continue----------------------" << endl;
		_getch();

		int rightanswers = 0;//intiger for rightanswer
		int wronganswers = 0;//intiger for wronganser
		int totalanswers = 0;//intiger for total attempts
		string wordArray[3];

		{
			//amount of words used
			enum fields { WORD, HINT, NUM_FIELDS };
			const int NUM_WORDS = 10;
			const string WORDS[NUM_WORDS][NUM_FIELDS] =
			{   //words that will be guess and their hints
				{"tiny", "known as smaller than small."},
				{"leaf", "A worms favorite food."},
				{"shades", "The Sun is to bright cover your eyes!"},
				{"birdbrain", "Another way of calling somone a dumbass!."},
				{"nick", "The Crazy worm that brough you here in the first place."},
				{"cacoon", "Hard shell worms build because of worm puberty."},
				{"butterfly", "Biggest glow up in the animal kingdom."},
				{"big", "What this mission is all about."},
				{"garden", "An area that worms love to feast upon."},
				{"silk", "Used to make a cacoon by some worms."},

			};


			for (int i = 0; i < 3; ++i)
			{
				srand(time(0));
				int words = (rand() % NUM_WORDS);
				for (int c = 0; c < 3; ++c)
				{
					while (WORDS[words][WORD] == wordArray[c])
					{
						words = (rand() % NUM_WORDS);
					}
				}
				wordArray[i] = WORDS[words][WORD];

				srand(static_cast<unsigned int>(time(0)));
				int choice = (rand() % NUM_WORDS);
				string theWord = WORDS[choice][WORD];  // word to guess
				string theHint = WORDS[choice][HINT];  // hint for word

				string jumble = theWord;  // jumbled version of word
				int length = jumble.size();

				for (int j = 0; j < length; ++j)
				{

					int index1 = (rand() % length);
					int index2 = (rand() % length);
					char temp = jumble[index1];
					jumble[index1] = jumble[index2];
					jumble[index2] = temp;
				}


				//text that will show in the start
				cout << "\t\t\Door Keeper:Welcome to MY GAME!\n\n";
				cout << "Unscramble the letters to make a word you will have 3 tries.\n";
				cout << "Enter hint if you need help.\n";
				cout << "Enter 'pass' to pass the word.\n\n";
				cout << "Keyword is: " << jumble;

				string guess;
				cout << "\n\nYour guess: ";
				cin >> guess;
				//game loop
				while ((guess != theWord) && (guess != "pass"))
				{
					if (guess == "hint")
					{
						cout << theHint;


					}
					else
					{
						cout << "Sorry, that's not it.";
						wronganswers++;
						totalanswers++;

					}

					cout << "\n\nYour guess: ";
					cin >> guess;
				}

				if (guess == theWord)
				{
					cout << "\nThat's it!  You guessed it!\n";
					totalanswers++;
					rightanswers++;

				}
			}

			//counter for right, wrong and amount of tries
			cout << "\n\t\tYou have made it though" << endl;
			cout << "Door Keeper: Alright squirt you passed my test now be ready to eat as much as you like. But I warn you people who get in never leave." << endl;
			cout << "You:Ya right HAHA!! You just dont want me to become more powerful then you!! " << endl;
			cout << "Door Keeper: Sigh I have warned you now here is what you have to do when you get in" << endl;
			cout << "when you are in the Keys 'W' 'A' 'S' 'D' will be what control you and the letter 0 will be you." << endl;
			cout << "You: The hell you talking about?" << endl;
			cout << "Door Keeper: This is a place to feed the hunger of boredom all around the world your a sacrafice you will enter an endless eating frenzy" << endl; 
			cout << "You: Nick you tricked me??" << endl;
			cout << "Nick: I am sorry but this was the only way I could live." << endl;
			cout << "Nick kicks you in the door the eternal game has begun." << endl;
			cout << "\n----------------------Press any key to continue----------------------" << endl;
			_getch();
		}
	
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(10); //sleep(10);
	}
	return 0;
}
