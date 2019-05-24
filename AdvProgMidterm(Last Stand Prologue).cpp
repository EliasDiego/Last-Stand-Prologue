
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

const int green = 10;
const int lightBlue = 11;
const int red = 12;
const int pink = 13;
const int yellow = 14;
const int white = 15;

//User Preference
string input;
bool userWantSlowText = true;
int textSpeed = 2;

int numberSleeps = 0;

bool fellAsleep = false;
bool discovered = false;
bool openPackage = false;
bool LEXDestroyed = false;

bool dadIdentity = false;
bool EmilySeparated = false;

bool warnFamily = false;

bool fromFarmToTown = false;
bool fromFarmToTownInvasion = false;
bool comingFromTown = false;
bool toFarm = false;

//Temporary Variables
string tempLocation[5];
string tempAction[5];
int tempResult;

//Settings Related Arrays
string userTextSlow[] = {"True", "False"};
string userTextSpeed[] = {"1", "2", "3", "4", "5"};

string titleMenu[] = {"Start", "Settings", "Exit"};
string titleSettings[] = {"Slow Text", "Text Speed", "Back"};

//Choices Available for Route Exploration
string choicesPrologue[] = {"Sleep", "Wake Up"};
string choicesLocations[] = {"Go to Outskirts", "Go to Eastern Forest", "Go to Town", "Go to Farm", "Go to Escape Tunnel"};	
string choicesActions[] = {"Open", "Not Open", "Shoot", "Hide"};
string choicesDirections[] = {"North", "South", "East", "West"};

//Sizes of Arrays
int uTextSpeed = sizeof(userTextSpeed)/sizeof(*userTextSpeed);
int uTextSlow = sizeof(userTextSlow)/sizeof(*userTextSlow);
int menu = sizeof(titleMenu)/sizeof(*titleMenu);
int settings = sizeof(titleSettings)/sizeof(*titleSettings);

int cPrologueSize = sizeof(choicesPrologue)/sizeof(*choicesPrologue);
int cLocationsSize = sizeof(choicesLocations)/sizeof(*choicesLocations);
int cActionsSize = sizeof(choicesActions)/sizeof(*choicesActions);
int cDirectionsSize = sizeof(choicesDirections)/sizeof(*choicesDirections);

void printDialogue(string dialogue, int color, bool ifNextLine)
{
	if(userWantSlowText == true)//If user wants slowly printed text
	{
		for (int i = 0; dialogue[i] != '\0'; i++)//Prints out the dialogue until the dialogue element is Null
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//Sets desired color for dialogue
			
 			if(kbhit())//Instantly prints dialogue
			cout << dialogue[i];

			else//Slowly prints dialogue
			{
				Sleep(textSpeed);
				cout << dialogue[i];
			}
		}	
	}
	else//Prints everything if user sets Slow Text to false
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		cout << dialogue;
	}
	
	if(ifNextLine == true)//For moving to the next line
	{
		cin.get();
		cin.get();
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);//Resets console color to white
}

void displayChoices(string choices[], int capacity)
{
	cout << "[ ";
	for (string *p = choices; p <= &choices[capacity] - 1; ++p)//Displays choices
	{
		cout << *p;
		if (p <= &choices[capacity] - 2)//Adds " || " in between choices
		cout << " || ";
	}
	cout << " ]\n>";
}

int choiceChecker(string userInput, string choices[], int capacity, int counter)
{
	int temp = counter;//Assigns value of counter to temp 
	while(true)
	{
		counter = temp;//Resets value of counter
		for (string *p = choices; p <= &choices[capacity] - 1; p++, ++counter)//Checks if player chose matches with given choices
		{
			if(userInput == *p)
				return (counter);
		}
		cout << "I cannot do that.\n>";
		getline(cin, userInput);
	}
}

void tempChoices(string choices[], string temp[], int capacity, int indexChoice, int counter)
{
	for(string *p = temp; p <= &temp[capacity - 1]; p++)//transfers specific elements to temp array
	{
		*p = choices[indexChoice];
		indexChoice += counter;
	}
}

void errorResponse(int scenes, string variable, int choice)//For Debugging
{
	printDialogue("\n\nERROR CHOICES.", red, false);
	printDialogue("\n\nPLEASE REPORT DEVELOPER ABOUT THIS.", red, false);
	
	while(true)//To not accidentally miss Error Log and for fun
	cout << "\n\nERROR SCENE: " << scenes << " ERROR VARIABLE: " << variable << " ERROR CHOICE: " << choice;
	
}

void debug(int factors, bool trueOrFalse)
{

	
}

void emilyStreamFeed()//Post Prologue Content
{
printDialogue("\n//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNWXd;;'.......       ..,:o0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXOkl'.....   ..          .,cxKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKo;.....    ............   ..':kXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0c........   ...............   .'cdkXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNo.......           ................';oOXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXc......     .          ...............';lONMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMO,....      .             ...........'',,,:OWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd'...      ..      ...... ............';ok0NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKc...       .      .''...................'cx0NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk,...     ...     .',,,,,'.. ..............';lONMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXc...       .    ..,,,,,,,,,.. ...............,c0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK;...           .,,,,,,,,,,,,.. .............ckKNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO'...          .,,,,,,,,,,,,,,...............oNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXd'...    ......',,,,,,,,,,,,,,,'.............,xWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKo'..     .   .',,,,,,,,,,,,,,.................'dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXo...        ..,,,,,,,,,,,,,,,..................'oXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXl..         .',,,,,,,,,,,,,,,,...................;xNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKd,. ..    ...,,,,,,,,,,,,,,,,,'....................:OWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXo. ..   .'...',,,,,,,,,,,,',,,,,.......      ......;OWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWx...    .... ..',,,,,,,,''',,,,,,''..........'''...'cx0XWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWd...   .... .....',,,,''',,,,,,,,,,''',,,,,,,,,,,''',;:lOWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNl..    ... ......',,''',,,,,,,,,,',,,,,,,,,,,,,,,,,'''',ckNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0;.    .... ......,,'',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,''',lONMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXx,.   ...  ..   ..,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,'',ckXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWOo,......     ...',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,',:dKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNOc. .........'',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,:xXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK:.......,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,;ckNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNo.......',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,;dXMMMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd'..''..',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,;l0WMMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKl..''..',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,:xXMMMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0c..'...,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,;l0WMMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXd;.'...,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,cOWMMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKo,''...,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,:kNMMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0o:'. .,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,:OWMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWOl,....,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,oXMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNkl'...,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,;;;;;;;;,,,,,,,,,,,,,,,,,,,,,,,,,,,c0MMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWOc,..,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,;;;;;;;;;;,,,,,,,,,,,,,,,,,,,,,,,;;c0MMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\nMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0:,'',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,;;;;;;;;;;,,,,,,,,,,,,,,,,,,,,,;;::dXMMMMMMMMMMMMMMMMMMMMM", white, false);
printDialogue("\n//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////", white, true);
}

void settlement71Text()
{
	printDialogue("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&", white, false);
	printDialogue("\n _______  _______  _______  _______  ___      _______  __   __  _______  __    _  _______    _______  ____  ", white, false);
	printDialogue("\n|       ||       ||       ||       ||   |    |       ||  |_|  ||       ||  |  | ||       |  |       ||    | ", white, false);
	printDialogue("\n|  _____||    ___||_     _||_     _||   |    |    ___||       ||    ___||   |_| ||_     _|  |___    | |   | ", white, false);
	printDialogue("\n| |_____ |   |___   |   |    |   |  |   |    |   |___ |       ||   |___ |       |  |   |        |   | |   | ", white, false);
	printDialogue("\n|_____  ||    ___|  |   |    |   |  |   |___ |    ___||       ||    ___||  _    |  |   |        |   | |   | ", white, false);
	printDialogue("\n _____| ||   |___   |   |    |   |  |       ||   |___ | ||_|| ||   |___ | | |   |  |   |        |   | |   | ", white, false);
	printDialogue("\n|_______||_______|  |___|    |___|  |_______||_______||_|   |_||_______||_|  |__|  |___|        |___| |___| ", white, false);
	printDialogue("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&", white, true);
}

void outskirtsText()
{
	printDialogue("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&", white, false);
	printDialogue("\n _______  __   __  _______  _______  ___   _  ___   ______    _______  _______ ", white, false);
	printDialogue("\n|       ||  | |  ||       ||       ||   | | ||   | |    _ |  |       ||       |", white, false);
	printDialogue("\n|   _   ||  | |  ||_     _||  _____||   |_| ||   | |   | ||  |_     _||  _____|", white, false);
	printDialogue("\n|  | |  ||  |_|  |  |   |  | |_____ |      _||   | |   |_||_   |   |  | |_____ ", white, false);
	printDialogue("\n|  |_|  ||       |  |   |  |_____  ||     |_ |   | |    __  |  |   |  |_____  |", white, false);
	printDialogue("\n|       ||       |  |   |   _____| ||    _  ||   | |   |  | |  |   |   _____| |", white, false);
	printDialogue("\n|_______||_______|  |___|  |_______||___| |_||___| |___|  |_|  |___|  |_______|", white, false);
	printDialogue("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&", white, true);
}

void easternForestText()
{
	printDialogue("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&", white, false);
	printDialogue("\n _______  _______  _______  _______  _______  ______    __    _    _______  _______  ______    _______  _______  _______ ", white, false);
	printDialogue("\n|       ||   _   ||       ||       ||       ||    _ |  |  |  | |  |       ||       ||    _ |  |       ||       ||       |", white, false);
	printDialogue("\n|    ___||  |_|  ||  _____||_     _||    ___||   | ||  |   |_| |  |    ___||   _   ||   | ||  |    ___||  _____||_     _|", white, false);
	printDialogue("\n|   |___ |       || |_____   |   |  |   |___ |   |_||_ |       |  |   |___ |  | |  ||   |_||_ |   |___ | |_____   |   |  ", white, false);
	printDialogue("\n|    ___||       ||_____  |  |   |  |    ___||    __  ||  _    |  |    ___||  |_|  ||    __  ||    ___||_____  |  |   |  ", white, false);
	printDialogue("\n|   |___ |   _   | _____| |  |   |  |   |___ |   |  | || | |   |  |   |    |       ||   |  | ||   |___  _____| |  |   |  ", white, false);
	printDialogue("\n|_______||__| |__||_______|  |___|  |_______||___|  |_||_|  |__|  |___|    |_______||___|  |_||_______||_______|  |___|  ", white, false);
	printDialogue("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&", white, true);
}

void townText()
{
	printDialogue("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&", white, false);
	printDialogue("\n _______  _______  _     _  __    _ ", white, false);
	printDialogue("\n|       ||       || | _ | ||  |  | |", white, false);
	printDialogue("\n|_     _||   _   || || || ||   |_| |", white, false);
	printDialogue("\n  |   |  |  | |  ||       ||       |", white, false);
	printDialogue("\n  |   |  |  |_|  ||       ||  _    |", white, false);
	printDialogue("\n  |   |  |       ||   _   || | |   |", white, false);
	printDialogue("\n  |___|  |_______||__| |__||_|  |__|", white, false);
	printDialogue("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&", white, true);
}

void farmText()
{
	printDialogue("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&", white, false);
	printDialogue("\n _______  _______  ______    __   __ ", white, false);
	printDialogue("\n|       ||   _   ||    _ |  |  |_|  |", white, false);
	printDialogue("\n|    ___||  |_|  ||   | ||  |       |", white, false);
	printDialogue("\n|   |___ |       ||   |_||_ |       |", white, false);
	printDialogue("\n|    ___||       ||    __  ||       |", white, false);
	printDialogue("\n|   |    |   _   ||   |  | || ||_|| |", white, false);
	printDialogue("\n|___|    |__| |__||___|  |_||_|   |_|", white, false);
	printDialogue("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&", white, true);
}

void escapeTunnelText()
{
	printDialogue("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&", white, false);
	printDialogue("\n _______  _______  _______  _______  _______  _______    _______  __   __  __    _  __    _  _______  ___     ", white, false);
	printDialogue("\n|       ||       ||       ||   _   ||       ||       |  |       ||  | |  ||  |  | ||  |  | ||       ||   |    ", white, false);
	printDialogue("\n|    ___||  _____||       ||  |_|  ||    _  ||    ___|  |_     _||  | |  ||   |_| ||   |_| ||    ___||   |    ", white, false);
	printDialogue("\n|   |___ | |_____ |       ||       ||   |_| ||   |___     |   |  |  |_|  ||       ||       ||   |___ |   |    ", white, false);
	printDialogue("\n|    ___||_____  ||      _||       ||    ___||    ___|    |   |  |       ||  _    ||  _    ||    ___||   |___ ", white, false);
	printDialogue("\n|   |___  _____| ||     |_ |   _   ||   |    |   |___     |   |  |       || | |   || | |   ||   |___ |       |", white, false);
	printDialogue("\n|_______||_______||_______||__| |__||___|    |_______|    |___|  |_______||_|  |__||_|  |__||_______||_______|", white, false);
	printDialogue("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&", white, true);
}

void scene_9(int *scenes)//Escape Tunnel
{
	if(dadIdentity == true)//if Dad's identity was discovered if coming from Town invasion to Farm
	{
		printDialogue("Emily: Is Dad going to be okay?", pink, true);
		printDialogue("Mom: Yes, he is going to return to us after we exit the tunnel.", pink, true);
		printDialogue("Emily: He is up against a whole army. I want to make sure he's alright. William don't you feel the same?", pink, true);
		printDialogue("William: Yeah... but...", green, true);
		printDialogue("Emily: Then let's go, we still might reach him if we-", pink, true);

		printDialogue("Mom: EMILY!!! Just... stop... I know this is hard but we should trust in him. If he finds out his family is still inside the battlefield", pink, false);
		printDialogue("\n   we would be a hindrance to him. I don't want to him to make him worry so let's just go, okay?", pink, true);
	}	
	
	escapeTunnelText();//Displays Escape Tunnel Text
	
	printDialogue("The tunnel connected the settlement and the surface as a means of escape. The surface is full of deserts however was still", white, false);
	printDialogue("\ntraversable even in high temperature conditions. It's said that above ground, there are still ruins of buildings and infrastructure", white, false);
	printDialogue("\nprior to the Global Warming that cause almost all of life to be deminished.\n", white, true);
	
	printDialogue("As we walked further, I keep smelling iron. Normally, I wouldn't notice it as everywhere we go there was iron. In this case, it was more", lightBlue, false);
	printDialogue("\npotent the closer we get to the exit.", lightBlue, true);
	
	printDialogue("\nIn a brief flash, we were surrounded. The soldiers already captured the tunnel. Looking closely, we noticed the pile of bodies in the background.", lightBlue, true);
	
	printDialogue("\nIt was a massacre. Blood still flowing from their bodies. Tens or hundreds of people stacked up upon each other. It was a gruesome sight to see.", white, true);
	
	printDialogue("\nA figure slowly came up in front. His appearance suggests of higher ranking compared to the other soldiers in the vicinity.", white, true);
	
	if(discovered == true)//If William was discovered in Outskirts, or Eastern Forest
	{
		printDialogue("\nOfficer: Haha... what a coincidence. Aren't you the one who we spotted in the forest? Maybe it's fate that we would meet here or its just ironic that you", red, false);
		printDialogue("\n   die in the place where you would've hope to escape.", red, true);

		printDialogue("\nSilence envelopes the tunnel~\n", white, true);
		
		printDialogue("\nThe one who stands before us is the officer who William encountered in the forest.\n", white, true);
		
		printDialogue("Officer: Well at least answer, you're probably the last people here to escape, so at least can you help entertain us in your final moments.", red, true);
		
		printDialogue("Mom: Please spare us... I have 2 children with me\n", pink, true);
		
		printDialogue("Officer: 2 children, or 10 doesn't really make a difference. It's my job to make sure none of you survives. Your settlement could've been untouched", red, false);
		printDialogue("\n     if only you gave your resources to my client. I know this world is harsh but that's how it is.", red, true);
		
		printDialogue("\nThe officer went back behind the line of soldiers.", white, true);
		
		if(LEXDestroyed == true)//If LEX is destroyed during Town Invasion
		{			
			printDialogue("\nOfficer: Kill them.\n", red, true);
		
			printDialogue("Mom: No! Wait!", pink, true);

			printDialogue("\nMom held us tighter than ever before. The world suddenly felt like its going in slow motion. Memories are flashing before my eyes. Is this it?\n", white, true);
	
			printDialogue("\nI could feel my world turning upsidedown. The feeling doesn't feel right as if I'm falling down back to the earth.\n", white, true);

			printDialogue("\nTHUD!~\n", yellow, true);
	
			printDialogue("\nMom: GET DOWN!\n", pink, true);
	
			printDialogue("Mom is holding a pistol... Where did that come from?", lightBlue, true);

			printDialogue("\nIn an instant, she shot all the lights making the tunnel completely dark. We felt bullets zipping above us as we were lying in the ground.", white, true);

			printDialogue("\nOne by one, beams of light started disappearing as well as the bullets richocheting across the tunnel. Screams and panic starting escalating", white, false);
			printDialogue("\nas groups of soldiers slowly disappearing. When the last soldier dropped, flares started popping. The light revealed the positions of everyone", white, false);
			printDialogue("\nand corpses that has scattered in the tunnel. As well as the officer, taking Emily hostage.", white, true);

			printDialogue("\n*Whistle~\n", yellow, true);
			
			printDialogue("\nOfficer: How about a deal? You let me go and I let your daughter go.", red, true);

			
			printDialogue("\nMom: I prefer to get rid of you just to be safe.\n", pink, true);
	
			
			printDialogue("\nMom points her gun at him.", white, true);
			
			printDialogue("\nOfficer:You sure did a number to my soldiers. I think you took all of my squads out.", red, true);
	
			
			printDialogue("William: You bastard! Let her go!", green, true);
			
			printDialogue("\nOfficer: You should be thanking me that I haven't killed this little angel.", red, true);
			printDialogue("Officer: It be unfortunate if something were to happen.\n", red, true);

			printDialogue("Mom: All right, just don't kill her\n.", pink, true);
			
			printDialogue("\nOfficer: Put down your gun and I'll just back off a bit then she will return to you.", red, true);
			
			printDialogue("The officer slowly walks backwards... ", white, true);
			
			printDialogue("Behind his back, he activated a switch...", white, true);
			
			printDialogue("*BOOM~ BOOM~ BOOM~", yellow, true);
			
			printDialogue("The whole tunnel shakes as the infrastructure slowly collapes from the inside out.", white, false);
			printDialogue("Steel creaks. Concrete turns to dust. Debris start falling from the ceiling. ", white, true);
			
			printDialogue("\nMom: EMILY!!! LET HER GO!!!.", pink, true);
			
			printDialogue("\nOfficer: She will return to you, if you make it out alive!", red, true);
			
			printDialogue("\n[EMILY SEPARATED]\n", lightBlue, true);
			EmilySeparated = true;
			
			printDialogue("\nLarge debris fell from the ceiling, blocking the path between us and Emily.\n.", white, true);
			
			printDialogue("Mom: WILLIAM RUN!\n.", pink, true);
			printDialogue("William: What about Emily?!\n.", green, true);
			printDialogue("Mom: I'll save her! You need to get of here!\n.", pink, true);
			printDialogue("William: But!\n.", green, true);
			printDialogue("Mom: GO!!!\n.", pink, true);
			
			printDialogue("I rush towards the gate. Cracks keep appearing as I slowly get closer.", lightBlue, false);
			printDialogue("As soon as I reached the gate...", lightBlue, true);
			
			printDialogue("BOOM~", yellow, true);
			
			printDialogue("Silence...", yellow, true);
			
			printDialogue("...", white, true);
			printDialogue("...", white, true);
			printDialogue("...", white, true);
			
			printDialogue("William: Ahh... that was close...", green, true);
			printDialogue("William: Ah hot!", green, true);
			
			printDialogue("William was greeted by the scorching sun as it radiates the desert all around him.", white, true);
			printDialogue("William: So this is the sun...", green, true);
			printDialogue("William: Where's Mom... Where's Emily...", green, true);
			printDialogue("William: MOM!!! EMILY!!!", green, true);
			printDialogue("William: They might be stuck in the tunnel!", green, true);
			printDialogue("William: MOM!!! EMILY!!!", green, true);
			
			printDialogue("William tries to dig the entrance blocked with concrete and steel. His hands, started bleeding.", white, true);
			printDialogue("His stamina slowly fading. His hope slowly fading. His will breaking.", white, true);
			
			printDialogue("The night sky blooming to the east. The cold winds blowing the deserts. A bright moon shines", white, false);
			printDialogue("\nupon a lone broken boy.", white, true);

			printDialogue("William: Mom... Emily... Mom... Emily...", green, true);
			printDialogue("WIlliam: ... Dad... everyone...", green, true);
			
			printDialogue("Thud...", yellow, true);
			
			printDialogue("William collapses. He looks into the night sky. The stars shining. The moon soothing his loneliness.", white, true);
			
			printDialogue("William: This is a dream isn't... yeah this is a dream...", green, true);
			printDialogue("William: yeah... this is a dream...", green, true);
			
			printDialogue("His conscious slowly fading to sleep.", white, true);
			
			printDialogue("William: yes... a dream...", green, true);
		}
		
		else if(LEXDestroyed == false)//If LEX is not destroyed during Town Invasion
		{
		
			printDialogue("\nOfficer: Ready!.\n", red, true);
			
			printDialogue("Mom: No! Wait!", pink, true);

			printDialogue("\nMom held us tighter than ever before. The world suddenly felt like its going in slow motion. Memories are flashing before my eyes. Is this it?\n", white, true);

			printDialogue("Mom whispered to us.", white, true);
			
			printDialogue("\nMom: William can you take out those guards on the right?\n", pink, true);
		
			printDialogue("William: Wha- why?", white, true);
			printDialogue("Mom: Can you take out those soldiers?", pink, true);
		
			printDialogue("We are about to die and you're asking me if I could take out those soldiers.", white, true);
		
			printDialogue("William: Yeah I guess...", green, true);
			printDialogue("Mom: Good. Emily duck as soon as the lights go out okay?", pink, true);
			printDialogue("Emily: Okay... Mom... what's about to happen?", pink, true);
			printDialogue("Mom: Trust me.", pink, true);
		
			printDialogue("\nOfficer: I hope you've said your good byes.\n", red, true);
		
			printDialogue("Mom: NOW!", pink, true);
			printDialogue("William: Mom is holding a pistol... Where did that come from?", green, true);
		
			printDialogue("\nIn an instant, she shot all the lights making the tunnel completely dark. I rushed towards the soldiers knocking them out.", lightBlue, true);

			printDialogue("\nOne by one, beams of light started disappearing as well as the bullets richocheting across the tunnel. Screams and panic starting escalating", white, false);
			printDialogue("\nas groups of soldiers slowly disappearing. When the last soldier dropped, flares started popping. The light revealed the positions of everyone", white, false);
			printDialogue("\nand corpses that has scattered in the tunnel. As well as the officer, taking Emily hostage.", white, true);
		
			printDialogue("\n*Whistle~\n", yellow, true);
		
			printDialogue("?: How about a deal? You let me go and I let your daughter go.\n", red, true);
		
			printDialogue("Mom: I prefer to get rid of you just to be safe.", pink, true);
			
			printDialogue("\nMom points her gun at him.\n", white, true);
		
			printDialogue("Officer: You sure did a number to my soldiers. I think you took all of my squads out.", red, true);
		
			printDialogue("William: You bastard! Let her go!", green, true);
		
			printDialogue("\nOfficer: You should be thanking me that I haven't killed this little angel.", red, true);
			printDialogue("Officer: It be unfortunate if something were to happen.\n", red, true);
		
			printDialogue("Mom: All right, just don't kill her. William don't move.", pink, true);
			printDialogue("Officer: Put down your gun and you boy stay there. I'll jut back off a bit then she will return to you.", red, true);
			
			printDialogue("The officer slowly walks backwards... ", white, true);
			
			printDialogue("Behind his back, he activated a switch...", white, true);
			
			printDialogue("*BOOM~ BOOM~ BOOM~", yellow, true);
			
			printDialogue("The whole tunnel shakes as the infrastructure slowly collapes from the inside out.", white, false);
			printDialogue("Steel creaks. Concrete turns to dust. Debris start falling from the ceiling. ", white, true);
			
			printDialogue("\nThe officer kicked Emily towards us as he quickly escaped.", pink, true);
			
			printDialogue("\nMom: EMILY! Let's go!", red, true);
			
			printDialogue("\nLarge debris fell from the ceiling, blocking the path towards the entrace. There was only one path left.\n", white, true);
			
			printDialogue("Mom: RUN TOWARDS THE GATE!\n", pink, true);
			printDialogue("William: Let's go Emily!\n", green, true);
			printDialogue("Emily: ah... my leg!\n", pink, true);
			printDialogue("William: I'll carry you!\n", green, true);
			printDialogue("Mom: GO!!!\n", pink, true);
			
			printDialogue("We rush towards the gate. Cracks keep appearing as we slowly get closer.", white, true);
			printDialogue("As soon as we reached the gate...", white, true);
			
			printDialogue("BOOM~", yellow, true);
			
			printDialogue("Silence...", yellow, true);
			
			printDialogue("...", white, true);
			printDialogue("...", white, true);
			printDialogue("...", white, true);
			
			printDialogue("William: Ahh... we're trapped...", green, true);
			
			printDialogue("William's LEX held the debris from falling towards them. The tunnel settled in as they were trapped underneath.", white, true);
			
			printDialogue("William: Emily are you okay?", green, true);
			printDialogue("Emily: Yeah, where's Mom?", pink, true);
			
			printDialogue("\n*Cough~ Cough~\n", pink, true);
			
			printDialogue("Emily: Mom! Are you okay?!", pink, true);
			printDialogue("Mom: I'm trapped... I can't move", pink, true);
			printDialogue("Emily: Will lift up this debris!", pink, true);
			printDialogue("William: I can't, my LEX is holding the ceiling. If I move, we will get crushed.", green, true);
			printDialogue("Mom: Leave me... We don't know how long until this space collapse.", pink, true);
			printDialogue("William: Mom... We can't just leave you here to die.", green, true);
			printDialogue("Emily: Just wait... we'll lift this debris.", pink, true);
			printDialogue("Mom: Go! Me and your Dad would rather see you two live...", pink, true);
			printDialogue("Emily: Mom... *Sob *Sob", pink, true);
			printDialogue("Mom: You take care of each other... now go!", pink, true);
			
			printDialogue("\nEmily slowly but surely crawled her way out. Light instantly entered this small space.\n", white, true);
			
			printDialogue("William: Mom... We can't just leave you...", green, true);
			printDialogue("Mom: You have to... Leave your LEX... It can hold up this weight on its own.", pink, true);
			
			printDialogue("William crawled out of his LEX. He's slowly crawling his way out until...", white, true);
			printDialogue("Boom~", yellow, true);
		
			printDialogue("The debris starting falling bring down William's LEX with it.", white, true);
			
			printDialogue("William: MOM! are you okay?!", green, true);
			printDialogue("Mom: Go! This won't hold for long!", pink, true);
			
			printDialogue("The collapsed tunnel started shaking more. Smoke dusts slowly appearing all around.", white, true);
			
			printDialogue("Mom: Go! Ru-", pink, true);
			
			printDialogue("William: Mom!... *Sob *Sob", green, true);
		
			printDialogue("I need to get out of here...", lightBlue, true);
			printDialogue("... maybe this is a dream...", lightBlue, true);
			
			printDialogue("Light slowly filled William's vision as he crawled his way out.", white, true);
			
			printDialogue("Emily: WILL!", pink, true);
			
			printDialogue("Yeah... Emily is starting to wake me up...", lightBlue, true);
			
			printDialogue("Emily: COME ON! WILL!", pink, true);
			
			printDialogue("William: yes... a dream...", green, true);
		}
		
	}
	
	else if(discovered == false)//If William was discovered in Outskirts, or Eastern Forest
	{
		if(LEXDestroyed == false)//If LEX is not destroyed during Town Invasion
		{			
			printDialogue("\nOfficer: Kill them.\n", red, true);
		
			printDialogue("Mom: No! Wait!", pink, true);

			printDialogue("\nMom held us tighter than ever before. The world suddenly felt like its going in slow motion. Memories are flashing before my eyes. Is this it?\n", white, true);
	
			printDialogue("\nI could feel my world turning upsidedown. The feeling doesn't feel right as if I'm falling down back to the earth.\n", white, true);

			printDialogue("\nTHUD!~\n", yellow, true);
	
			printDialogue("\nMom: GET DOWN!\n", pink, true);
	
			printDialogue("Mom is holding a pistol... Where did that come from?", lightBlue, true);

			printDialogue("\nIn an instant, she shot all the lights making the tunnel completely dark. We felt bullets zipping above us as we were lying in the ground.", white, true);

			printDialogue("\nOne by one, beams of light started disappearing as well as the bullets richocheting across the tunnel. Screams and panic starting escalating", white, false);
			printDialogue("\nas groups of soldiers slowly disappearing. When the last soldier dropped, flares started popping. The light revealed the positions of everyone", white, false);
			printDialogue("\nand corpses that has scattered in the tunnel. As well as the officer, taking Emily hostage.", white, true);

			
			printDialogue("\n*Whistle~\n", yellow, true);
			
			printDialogue("\nOfficer: How about a deal? You let me go and I let your daughter go.", red, true);

			
			printDialogue("\nMom: I prefer to get rid of you just to be safe.\n", pink, true);
	
			
			printDialogue("\nMom points her gun at him.", white, true);
			
			printDialogue("\nOfficer:You sure did a number to my soldiers. I think you took all of my squads out.", red, true);
	
			
			printDialogue("William: You bastard! Let her go!", green, true);
			
			printDialogue("\nOfficer: You should be thanking me that I haven't killed this little angel.", red, true);
			printDialogue("Officer: It be unfortunate if something were to happen.\n", red, true);

			printDialogue("Mom: All right, just don't kill her\n.", pink, true);
			
			printDialogue("\nOfficer: Put down your gun and I'll just back off a bit then she will return to you.", red, true);
			
			printDialogue("The officer slowly walks backwards... ", white, true);
			
			printDialogue("Behind his back, he activated a switch...", white, true);
			
			printDialogue("*BOOM~ BOOM~ BOOM~", yellow, true);
			
			printDialogue("The whole tunnel shakes as the infrastructure slowly collapes from the inside out.", white, false);
			printDialogue("Steel creaks. Concrete turns to dust. Debris start falling from the ceiling. ", white, true);
			
			printDialogue("\nMom: EMILY!!! LET HER GO!!!.", pink, true);
			
			printDialogue("\nOfficer: She will return to you, if you make it out alive!", red, true);
			
			printDialogue("\n[EMILY SEPARATED]\n", lightBlue, true);
			EmilySeparated = true;
			
			printDialogue("\nLarge debris fell from the ceiling, blocking the path between us and Emily.\n", white, true);
			
			printDialogue("Mom: WILLIAM RUN!\n", pink, true);
			printDialogue("William: What about Emily?!\n", green, true);
			printDialogue("Mom: I'll save her! You need to get of here!\n", pink, true);
			printDialogue("William: But!\n", green, true);
			printDialogue("Mom: GO!!!\n", pink, true);
			
			printDialogue("I rush towards the gate. Cracks keep appearing as I slowly get closer.", lightBlue, false);
			printDialogue("As soon as I reached the gate...", lightBlue, true);
			
			printDialogue("BOOM~", yellow, true);
			
			printDialogue("Silence...", yellow, true);
			
			printDialogue("...", white, true);
			printDialogue("...", white, true);
			printDialogue("...", white, true);
			
			printDialogue("William: Ahh... that was close...", green, true);
			printDialogue("William: Ah hot!", green, true);
			
			printDialogue("William was greeted by the scorching sun as it radiates the desert all around him.", white, true);
			printDialogue("William: So this is the sun...", green, true);
			printDialogue("William: Where's Mom... Where's Emily...", green, true);
			printDialogue("William: MOM!!! EMILY!!!", green, true);
			printDialogue("William: They might be stuck in the tunnel!", green, true);
			printDialogue("William: MOM!!! EMILY!!!", green, true);
			
			printDialogue("William tries to dig the entrance blocked with concrete and steel. His hands, started bleeding.", white, true);
			printDialogue("His stamina slowly fading. His hope slowly fading. His will breaking.", white, true);
			
			printDialogue("The night sky blooming to the east. The cold winds blowing the deserts. A bright moon shines", white, false);
			printDialogue("\nupon a lone broken boy.", white, true);

			printDialogue("William: Mom... Emily... Mom... Emily...", green, true);
			printDialogue("WIlliam: ... Dad... everyone...", green, true);
			
			printDialogue("Thud...", yellow, true);
			
			printDialogue("William collapses. He looks into the night sky. The stars shining. The moon soothing his loneliness.", white, true);
			
			printDialogue("William: This is a dream isn't... yeah this is a dream...", green, true);
			printDialogue("William: yeah... this is a dream...", green, true);
			
			printDialogue("His conscious slowly fading to sleep.", white, true);
			
			printDialogue("William: yes... a dream...", green, true);
		}
		
		else if(LEXDestroyed == true)//If LEX is destroyed during Town Invasion
		{
			printDialogue("\nOfficer: Ready!.\n", red, true);
			
			printDialogue("Mom: No! Wait!", pink, true);

			printDialogue("\nMom held us tighter than ever before. The world suddenly felt like its going in slow motion. Memories are flashing before my eyes. Is this it?\n", white, true);

			printDialogue("Mom whispered to us.", white, true);
			
			printDialogue("\nMom: William can you take out those guards on the right?\n", pink, true);
		
			printDialogue("William: Wha- why?", white, true);
			printDialogue("Mom: Can you take out those soldiers?", pink, true);
		
			printDialogue("We are about to die and you're asking me if I could take out those soldiers.", white, true);
		
			printDialogue("William: Yeah I guess...", green, true);
			printDialogue("Mom: Good. Emily duck as soon as the lights go out okay?", pink, true);
			printDialogue("Emily: Okay... Mom... what's about to happen?", pink, true);
			printDialogue("Mom: Trust me.", pink, true);
		
			printDialogue("\nOfficer: I hope you've said your good byes.\n", red, true);
		
			printDialogue("Mom: NOW!", pink, true);
			printDialogue("William: Mom is holding a pistol... Where did that come from?", green, true);
		
			printDialogue("\nIn an instant, she shot all the lights making the tunnel completely dark. I rushed towards the soldiers knocking them out.", lightBlue, true);

			printDialogue("\nOne by one, beams of light started disappearing as well as the bullets richocheting across the tunnel. Screams and panic starting escalating", white, false);
			printDialogue("\nas groups of soldiers slowly disappearing. When the last soldier dropped, flares started popping. The light revealed the positions of everyone", white, false);
			printDialogue("\nand corpses that has scattered in the tunnel. As well as the officer, taking Emily hostage.", white, true);
		
			printDialogue("\n*Whistle~\n", yellow, true);
		
			printDialogue("\n?: How about a deal? You let me go and I let your daughter go.\n", red, true);
		
			printDialogue("Mom: I prefer to get rid of you just to be safe.\n", pink, true);
			
			printDialogue("\nMom points her gun at him.\n", white, true);
		
			printDialogue("\nOfficer: You sure did a number to my soldiers. I think you took all of my squads out.", red, true);
		
			printDialogue("William: You bastard! Let her go!", green, true);
		
			printDialogue("\nOfficer: You should be thanking me that I haven't killed this little angel.", green, true);
			printDialogue("Officer: It be unfortunate if something were to happen.\n", red, true);
		
			printDialogue("Mom: All right, just don't kill her. William don't move.\n.", pink, true);
			printDialogue("\nOfficer: Put down your gun and you boy stay there. I'll jut back off a bit then she will return to you.\n", red, true);
			
			printDialogue("The officer slowly walks backwards... ", white, true);
			
			printDialogue("Behind his back, he activated a switch...", white, true);
			
			printDialogue("*BOOM~ BOOM~ BOOM~", yellow, true);
			
			printDialogue("The whole tunnel shakes as the infrastructure slowly collapes from the inside out.", white, false);
			printDialogue("Steel creaks. Concrete turns to dust. Debris start falling from the ceiling. ", white, true);
			
			printDialogue("\nThe officer kicked Emily towards us as he quickly escaped.", pink, true);
			
			printDialogue("\nMom: EMILY! Let's go!", red, true);
			
			printDialogue("\nLarge debris fell from the ceiling, blocking the path towards the entrace. There was only one path left\n.", white, true);
			
			printDialogue("Mom: RUN TOWARDS THE GATE!\n.", pink, true);
			printDialogue("William: Let's go Emily!\n", green, true);
			printDialogue("Emily: ah... my leg!\n", pink, true);
			printDialogue("William: I'll carry you!\n", green, true);
			printDialogue("Mom: GO!!!\n", pink, true);
			
			printDialogue("We rush towards the gate. Cracks keep appearing as we slowly get closer.", white, true);
			printDialogue("As soon as we reached the gate...", white, true);
			
			printDialogue("BOOM~", yellow, true);
			
			printDialogue("Silence...", yellow, true);
			
			printDialogue("...", white, true);
			printDialogue("...", white, true);
			printDialogue("...", white, true);
			
			printDialogue("William: Ahh... we're trapped...", green, true);
			
			printDialogue("William's LEX held the debris from falling towards them. The tunnel settled in as they were trapped underneath.", white, true);
			
			printDialogue("William: Emily are you okay?", green, true);
			printDialogue("Emily: Yeah, where's Mom?", pink, true);
			
			printDialogue("\n*Cough~ Cough~\n", pink, true);
			
			printDialogue("Emily: Mom! Are you okay?!", pink, true);
			printDialogue("Mom: I'm trapped... I can't move", pink, true);
			printDialogue("Emily: Will lift up this debris!", pink, true);
			printDialogue("William: I can't, my LEX is holding the ceiling. If I move, we will get crushed.", green, true);
			printDialogue("Mom: Leave me... We don't know how long until this space collapse.", pink, true);
			printDialogue("William: Mom... We can't just leave you here to die.", green, true);
			printDialogue("Emily: Just wait... we'll lift this debris.", pink, true);
			printDialogue("Mom: Go! Me and your Dad would rather see you two live...", pink, true);
			printDialogue("Emily: Mom... *Sob *Sob", pink, true);
			printDialogue("Mom: You take care of each other... now go!", pink, true);
			
			printDialogue("\nEmily slowly but surely crawled her way out. Light instantly entered this small space.\n", white, true);
			
			printDialogue("William: Mom... We can't just leave you...", green, true);
			printDialogue("Mom: You have to... Leave your LEX... It can hold up this weight on its own.", pink, true);
			
			printDialogue("William crawled out of his LEX. He's slowly crawling his way out until...", white, true);
			printDialogue("Boom~", yellow, true);
		
			printDialogue("The debris starting falling bring down William's LEX with it.", white, true);
			
			printDialogue("William: MOM! are you okay?!", green, true);
			printDialogue("Mom: Go! This won't hold for long!", pink, true);
			
			printDialogue("The collapsed tunnel started shaking more. Smoke dusts slowly appearing all around.", white, true);
			
			printDialogue("Mom: Go! Ru-", pink, true);
			
			printDialogue("William: Mom!... *Sob *Sob", green, true);
		
			printDialogue("I need to get out of here...", lightBlue, true);
			printDialogue("... maybe this is a dream...", lightBlue, true);
			
			printDialogue("Light slowly filled William's vision as he crawled his way out.", white, true);
			
			printDialogue("Emily: WILL!", pink, true);
			
			printDialogue("Yeah... Emily is starting to wake me up...", lightBlue, true);
			
			printDialogue("Emily: COME ON! WILL!", pink, true);
			
			printDialogue("William: yes... a dream...", green, true);
		}
		
	}
	*scenes += 1;

}

void scene_8(int *scenes)//Farm
{
	farmText();//Displays Farm Text
	
	if(toFarm == true)//If player chose to go straight back to the farm
	{
		printDialogue("\nWilliam arrived back in the farm. The sight of home untouched gave him a sense of relief as the town was set ablazed seen from afar.", white, true);
		printDialogue("He continued forth rushing to warn his family of the impending doom happening all around.", white, true);
		printDialogue("Explosions can be seen in the distance. Guns can be heard being fired. The smoke from the fire slowly rises to the ceiling.\n", white, true);

		if(fromFarmToTown == true)//If player came from Outskirts or Eastern Forest and chose to go to the Farm
		{
			printDialogue("William: Mom! Emily!", green, true);
			printDialogue("Mom: William! Thank goodness you're safe...", pink, true);
			printDialogue("William: Mom we need to leave now! It's an invasion!'", green, true);
		
			printDialogue("\n[FAMILY WARNED]\n", lightBlue, true);
			warnFamily = true;//Activates dialogue for Town Invasion Route
			
			printDialogue("Mom: Emily! Pack your bag!", pink, true);
			printDialogue("Emily: Okay!", pink, true);
			printDialogue("Mom: Where's your Dad?", pink, true);
			printDialogue("William: He's in town, I'm coming back for him.", green, true);
			printDialogue("Mom: and what? Get caught between the fight? Your father can manage but right now we need to leave now!", pink, true);
			printDialogue("William: and what if he isn't? What if he is in danger!", green, true);
			printDialogue("Mom: Trust in your father! If we come to town, he will worry about us and then he wil be in real danger!", pink, true);
			printDialogue("William: We can't just leave him...", green, true);

			printDialogue("William: Should I go to town and save Dad or leave with my family?", green, true);
		}
		
		else
		{
			printDialogue("William: Mom! Dad! Emily!", green, true);
			printDialogue("Mom: William! Thank goodness you're safe...", pink, true);
			printDialogue("William: Mom we need to leave now! It's an invasion!'", green, true);
		
			printDialogue("\n[FAMILY WARNED]\n", lightBlue, true);
			warnFamily = true;
			
			printDialogue("Emily: Mom! I finished packing my stuff!", pink, true);
			printDialogue("William: Where's Dad?", green, true);
			printDialogue("Mom: You also need to pack your belongings. We might never return here.", pink, true);
			printDialogue("William: Mom wher-", green, true);
			printDialogue("Mom: Also you carry our this. You still have your LEX so have to bring all the heavy ones.", pink, true);
			printDialogue("William: Where's D-", green, true);
			printDialogue("Mom: Make sure you bring everything important. Leave everything that isn't important.", pink, true);
			printDialogue("William: MOM! WHERE'S DAD?!", green, true);
			printDialogue("Mom: ...", pink, true);
			printDialogue("William: MOM!", green, true);
			printDialogue("Emily: He's in town.", pink, true);
			printDialogue("William: Wha- Why?", green, true);
			printDialogue("Mom: He was called by the council after you left.", pink, true);
			printDialogue("William: He might be in danger! I'll go to town an-", green, true);
			printDialogue("Mom: and what? Get caught between the fight? Your father can manage but right now we need to leave now!", pink, true);
			printDialogue("William: and what if he isn't? What if he is in danger!", green, true);
			printDialogue("Mom: Trust in your father! If we come to town, he will worry about us and then he wil be in real danger!", pink, true);
			printDialogue("Emily: Please William, don't let us make us worry anymore than what is happening...", pink, true);
			printDialogue("William: Should I go to town and save Dad or leave with my family?", green, true);
		}
		
		//Asks player to either choose to go to Town or to go to the Escape Tunnel
		tempChoices(choicesLocations, tempLocation, 2, 2, 2);
		displayChoices(tempLocation, cLocationsSize - 3);
		getline(cin, input);
		tempResult = choiceChecker(input, tempLocation, cLocationsSize - 3, 1);
		
		if(tempResult == 1)//If player chose to go to town and save Dad
		{
			printDialogue("\nWilliam: I'm not leaving Dad while there's an invasion happening!", green, true);
			printDialogue("Mom: No don't! You'll get killed!", pink, true);
			printDialogue("William: I'll take my chances.", green, true);
			
			*scenes -= 1;
			
			fromFarmToTown = false;//Deactivates Town No Invasion dialogue
			fromFarmToTownInvasion = true;//Activates Town Invasion Dialogue
		}
		
		else if(tempResult == 2)//If player chose to go to the Escape Tunnel
		{
			printDialogue("William: Fine... I'll get my stuff.", green, true);
			
			printDialogue("Silence engulfs the entire house as the guilt and sorrow fills the heart for the head of the house.", white, true);
			
			printDialogue("We packed our belongings and the memories of this house, the smell of the field, and the radiant light that shone life into", lightBlue, false);
			printDialogue("\nthe most boring place on earth. No... The one place we all return to at one point in our lives.", lightBlue, true);
		
			printDialogue("\nHome.\n", lightBlue, true);

			*scenes += 1;
		}
		
		else//Error
		errorResponse(*scenes, "tempResult", tempResult);
		
	}
	
	else if(comingFromTown == true)//If coming from Town Invasion
	{
		if(LEXDestroyed == true)//if William's LEX is destroyed during Town Invasion
		{
			printDialogue("\n?: Wake up William...", pink, true);
			printDialogue("?: Come on wake up!", pink, true);
			
			printDialogue("William: No... 5 more minutes", green, true);
			printDialogue("Emily: WAKE UP YOU STUPID BROTHER OF MINE!!!", pink, true);
			
			printDialogue("\nA powerful slap came across william's injured face of which brought him back to reality confused and in pain. Too much pain.\n", white, true);
			
			printDialogue("William: I really hate mornings...", green, true);
			printDialogue("Mom: Oh William, you can hate it all day long as long as you're alive... *Sob *Sob", pink, true);
			printDialogue("Emily: *Sob *Sob, We were scarred that you might've died during the invasion.", pink, true);
			
			printDialogue("\nMom grabbed us and hugged as if were becoming due to the pressure of her hug. Looking closer into the environment, I think I was brought", white, false);
			printDialogue("\nback to the house. Wait where's that allied LEX?\n", white, true);
			
			printDialogue("Dad: Ehm! Sooo no one was worried about me?\n", green, true);
			
			printDialogue("\n[DAD'S TRUE IDENTITY]\n", white, true);
			dadIdentity = true;//Activates dialogue in Escape Tunnel
			
			printDialogue("\nThe LEX that was defending the town is sitted in the field where Dad came out introducing himself as the pilot of that LEX.", white, true);
			
			printDialogue("Mom: We were but as you can tell your safe but William wasn't this whole time.", pink, true);
			printDialogue("William: Wait... Dad you're the pilot of that LEX? How come you didn't tell me about this?", green, true);
			
			printDialogue("Dad: I was already retired. There's not point in telling something that I wasn't anymore or so I would like to think. Nevertheless anyways", green, false);
			printDialogue("\n   time for you 3 to go. I still have to defend the tunnel", green, true);
			
			printDialogue("Emily: Wait Dad, you're not coming with us? It's already too late, the others are already outside of the settlement.", pink, true);
			printDialogue("Dad: Well someone has to defend the tunnel otherwise they might just blow it up and besides someone might still be trying to reach it.", green, true);
			printDialogue("Mom: I thought I would never experience something like this again. You better catch up once everyone is out, okay?", pink, true);
			printDialogue("Dad: Since when did I ever not return.", green, true);
			
			printDialogue("\nHe was lying. Everyone of us knows Dad won't comeback as his smile wasn't the same as before. It has pain and sadness written all over it", white, false);
			printDialogue("\nbut we have to leave so that Dad's sacrifice won't be in vain.\n", white, true);
			
			printDialogue("We packed our belongings and the memories of this house, the smell of the field, and the radiant light that shone life into", lightBlue, false);
			printDialogue("\nthe most boring place on earth. No... The one place we all return to at one point in our lives.", lightBlue, true);
		
			printDialogue("\nHome.\n", lightBlue, true);

			printDialogue("As we left the farm, Dad made sure first that we were safe on the way to the tunnel. As we slowly went farther away from each", lightBlue, false);
			printDialogue("\nother. I could almost recognize the sadness that envelopes Dad but as he turns his back towards us. We could feel the hope that", lightBlue, false);
			printDialogue("\nwas radiating even with the distance. His hopes, his dreams. He entrusts us with it as we slowly enter the tunnel.", lightBlue, true);
			
			*scenes += 1;
		}
	
		else if(LEXDestroyed == false)//if William's LEX is not destroyed during Town Invasion
		{
			printDialogue("\nAs danger was slowly left behind in the ruined town, the sight of home was slowly coming to view. There are 2 people that are insight as we slowly", white, false);
			printDialogue("\narriving into the farm. There was Mom who was crying as well as Emily who was supporting Mom as she left strength in the sight of me.\n", white, true);	

			printDialogue("William: Mom... Emily... I...", green, true);
			printDialogue("Mom: Oh William, thank goodness you're safe... *Sob *Sob", pink, true);
			printDialogue("Emily: *Sob *Sob, We were scarred that you might've died during the invasion.", pink, true);
		
			printDialogue("\nMom grabbed us and hugged as if were becoming due to the pressure of her hug. Looking closer into the environment, I think I was brought", white, false);
			printDialogue("\nback to the house. Wait where's that allied LEX?\n", white, true);
			
			printDialogue("Dad: Ehm! Sooo no one was worried about me?", green, true);
			
			printDialogue("\n[DAD'S TRUE IDENTITY]\n", white, true);
			dadIdentity = true;//Activates Escape Tunnel Dialogue
			
			printDialogue("\nThe LEX that was defending the town is sitted in the field where Dad came out introducing himself as the pilot of that LEX.", white, true);
			
			printDialogue("Mom: We were but as you can tell your safe but William wasn't this whole time.", pink, true);
			printDialogue("William: Wait... Dad you're the pilot of that LEX? How come you didn't tell me about this?", green, true);
			printDialogue("Dad: I was already retired. There's not point in telling something that I wasn't anymore or so I would like to think. Nevertheless anyways", green, false);
			printDialogue("\n   time for you 3 to go. I still have to defend the tunnel", green, true);
			
			printDialogue("Emily: Wait Dad, you're not coming with us? It's already too late, the others are already outside of the settlement.", pink, true);
			printDialogue("Dad: Well someone has to defend the tunnel otherwise they might just blow it up and besides someone might still be trying to reach it.", green, true);
			printDialogue("Mom: I thought I would never experience something like this again. You better catch up once everyone is out, okay?", pink, true);
			printDialogue("Dad: Since when did I ever not return.", green, true);
			printDialogue("William: Wait... Dad I can help. I still have my LEX intact and I can help you defend the tunnel.", green, true);
			printDialogue("Dad: William, you're the only one who has a LEX still operational. You go with the others and protect them. You're the one who is gonna", green, false);
			printDialogue("\n   hold the infantry in the situation that they managed to reach the tunnel while I hold off those LEXs. Even at my age, I can still do well", green, true);
			
			printDialogue("\nHe was lying. Everyone of us knows Dad won't comeback as his smile wasn't the same as before. It has pain and sadness written all over it", lightBlue, true);
			printDialogue("\nbut we have to leave so that Dad's sacrifice won't be in vain.\n", lightBlue, true);
			
			printDialogue("We packed our belongings and the memories of this house, the smell of the field, and the radiant light that shone life into", lightBlue, false);
			printDialogue("\nthe most boring place on earth. No... The one place we all return to at one point in our lives.", lightBlue, true);
		
			printDialogue("\nHome.\n", lightBlue, true);

			printDialogue("As we left the farm, Dad made sure first that we were safe on the way to the tunnel. As we slowly went farther away from each", lightBlue, false);
			printDialogue("\nother. I could almost recognize the sadness that envelopes Dad but as he turns his back towards us. We could feel the hope that", lightBlue, false);
			printDialogue("\nwas radiating even with the distance. His hopes, his dreams. He entrusts us with it as we slowly enter the tunnel.", lightBlue, true);
			*scenes += 1;
		}	
	}	
}

void scene_7(int *scenes)//Town
{
	if(fromFarmToTown == true)//If player chose to go to town
	{
		printDialogue("\nWilliam cautiously avoided his home because of Emily just to escape from embarassmentas as he traveled towards town.\n", white, true);
		
		townText();//Displays Town Text
		
		printDialogue("The town in the settlement is sentimental to a world before the earth was scorched of life. Bunker buildings are scattered and in between them are plain buildings.", white, false);
		printDialogue("\nThe people are gathered here as general trade and market happens in the town center. The main export of our settlement is Iron and other minerals. The town also produces", white, false);
		printDialogue("\nmachineries that are essential to the production of LEXs. Many surviving corporations partner with us as a means to obtain our exports and resources.", white, true);
		
		printDialogue("LEXs can be seen everywhere. Each one carries a different purpose. There are ones that carry packages while other do construction work however we do not own military LEXs.", white, false);
		printDialogue("\nDue to agreements, we were banned from producing them in exchange for agriculture goods. Our land is not rich in nutrients as such we could only make do with certain crops.", white, false);
		printDialogue("\nWith this arrangement, we managed to avoid starvation.\n", white, true);
		
		printDialogue("Wiliam: Excuse me...", green, true);
		printDialogue("Wiliam: coming through...", green, true);
		printDialogue("?: Ah... William", green, true);
		printDialogue("Wiliam: Oh Dad, what are you doing here? I thought you were doing the harvest?", green, true);
		printDialogue("Dad: The council called me. Wait... let me ride with you...", green, true);
		printDialogue("Dad: How come I managed to get here first before you?", green, true);
		printDialogue("Wiliam: I wanted to go elsewhere first but the package was heavy. What's in this thing anyway?", green, true);
		printDialogue("Dad: Something important. You better don't drop it.", green, true);
		printDialogue("Wiliam: Okay...", green, true);
		printDialogue("Wiliam: Why is there so much people here today...", green, true);
		
		printDialogue("\nThe town center is full of people. There seems to be an announcement of sorts today.\n", lightBlue, true);
		
		printDialogue("Wiliam: Ah... Almost there at the town hall...", green, true);
		printDialogue("Dad: Oh! Drop me off near the door of the townhall.", green, true);
		printDialogue("Wiliam: Okay... Yes... Finally out of the crowd...", green, true);
		printDialogue("Dad: Thanks William, You can drop the package here. I'll get someone to carry it for me later.\n", green, true);
		
		printDialogue("\n[PACKAGE DELIVERED]\n", lightBlue, true);
		
		printDialogue("\nThe crowds started whispering. It would seem the mayor of the town finally appeared on stage.", lightBlue, true);
		
		printDialogue("Town Mayor: Everyone I would like to first apologize for this sudden announcement.", green, true);
		printDialogue("?: Is it true that we rejected th-", green, true);
		printDialogue("?: Why did other communities start blocking our expor-", pink, true);
		printDialogue("?: Who can we account for this mishap?", green, true);
		printDialogue("?: Are we hiding a military LEX?", pink, true);
		
		printDialogue("Town Mayor: Settle down people...", green, true);
		printDialogue("Town Mayor: First, our exports are temporarily halted due to influxes in demand in other settlements.", green, true);
		printDialogue("Town Mayor: The trade will resume in a few days.", green, true);
		
		printDialogue("Town Mayor: Second, our deal with the Sivinus Corporation is rejected. They ask for a majority of our iron however", green, false);
		printDialogue("\n     the return is not beneficial to our community.", green, true);
		
		printDialogue("Town Mayor: Last, no. We do not own or are hiding any military LEXs.", green, true);
		printDialogue("Town Mayor: Thank you.", green, true);
		
		printDialogue("\nThe Mayor walked out off to the side of the stage. He then proceeded to come to us.\n", white, true);
				
		printDialogue("Town Mayor: John, sorry for the sudden call.", green, true);
		printDialogue("Dad: Its alright, I take that this matter is very important.", green, true);
		printDialogue("Town Mayor: Yes... actually the Sivinus Corporation is going to launch an attack.", green, true);
		printDialogue("Dad: Huhh... What deal did they propose to you?", green, true);
		
		printDialogue("Town Mayor: We had no choice. It was either we sell our iron and be directly be managed by them or", green, false);
		printDialogue("\n     they take us and our iron.", green, true);
		
		printDialogue("Dad: Slavery... Did the demand for iron suddenly peak?", green, true);
		printDialogue("Town Mayor: Yes, some rumors are circulating that there's going to be war.", green, true);
		printDialogue("Town Mayor: Anyways, we need you to think a defense plan", green, true);
		
		printDialogue("Dad: Defense? Michael... we need an evacuation plan.", green, false);
		printDialogue("\n     We can't stand against them even with my- ", green, true);
		
		printDialogue("\nDad looked at me with sad eyes.\n", white, true);
		
		printDialogue("Dad: Anyways, we need to run. Anywhere. If not then we're don-", green, true);
		
		printDialogue("\nThe light coming from the yellow orb suddenly went out. Explosions suddenly erupted around the houses. Everyone panicked.\n", white, true);
		
		printDialogue("Dad: They're here...", green, true);
		printDialogue("Town Mayor: EVERYONE TO THE ESCAPE TUNNEL!", green, true);
		printDialogue("William: Dad, what's happening?!", green, true);
		printDialogue("Dad: It's an invasion... you need to go home!", green, true);
		printDialogue("William: But Dad-", green, true);
		printDialogue("Dad: NOW! You need to escape with your Mother and Emily before its too late!", green, true);
		printDialogue("William: What about you Dad?", green, true);
		printDialogue("Dad: I have to take of soemthing. GO!", green, true);
		
		toFarm = true;//Variable activates the next scene
		//fromFarmToTown = false;//Disables Dialogue from coming to Outskirts or Eastern Forest
	}
	
	else if(fromFarmToTownInvasion = true)//If player chose to go to Town during Invasion
	{
		townText();//Display Town Text
		
		if(warnFamily == true)//If player go to farm and warned family
		{
			printDialogue("\nWilliam speeded his way into town. If this was a race he would've won the gold medal however it wasn't", white, false);
			printDialogue("\nthe medal that would be rewarding in his endeavor but the sight of safety as danger slowly crawled behind his back.", white, true);
			printDialogue("\nThe closer William got into the village the more he noticed that the light isn't coming from houses", white, false);
			printDialogue("\nbut fire spread across the whole town.\n", white, true);

			printDialogue("William: Oh no... oh no... I'm too late. Why is this happening?", green, true);
	
			printDialogue("\nIn a distance, could be seen a military LEX fighting but was not like the ones in the outskirts. It was", white, false);
			printDialogue("\nholding back the squads of infantry as the citizens slowly evacuated. It looks like its in our side.\n", white, true);
		
			printDialogue("William: I need to find Dad... Where is he?", green, true);

			printDialogue("\nThe ally LEX came into William's view as it tries to fend off the invaders however suddenly another", white, false);
			printDialogue("\nmilitary LEX came out of nowhere and ambushed it caughting it off guard.", white, true);

			printDialogue("\nWilliam: Wa! I need to take cover.", green, true);

			printDialogue("\nThe two LEXs started fighting inside the ruined town. The Allied LEXs suppressed the enemy LEX with its assault rifle", white, false);
			printDialogue("\nhowever the enemy LEX repositioned itself and hide among the buildings looking for a chance to counter attack.", white, true);

			printDialogue("\nThe battle was intense. Going from cover to cover in matter of seconds. The allied LEX managed to accurately", white, false);
			printDialogue("\nhit the enemy LEX however couldn't continously damage him as he was kept suppressed most of the time.", white, true);

			printDialogue("\nThe two tried to outsmart each other. Figuring out each other's movement in a tense sitation. As the battle went", white, false);
			printDialogue("\non, the allied LEX ran out of ammo. It resorted to using its pistol. The battle was continued on however the infantry slowly", white, false);
			printDialogue("\ncrept into position to ambush the allied LEX. They launched rocket launchers into its blind side hower it caught wind of this", white, false);
			printDialogue("\nand dodged at the last second.", white, true);
			
			printDialogue("\nIn the background, William continiously searched for his father. He shouts for him every chance he gets.\n", white, true);
			
			printDialogue("William: DAD! DAD! WHERE ARE YOU DAD?!", green, true);
	
			printDialogue("\nThe enemy LEX finally lost all its ammo. It threw its assault rifle at the allied LEX however using that chance he threw it back", white, false);
			printDialogue("\nto him causing him to break his guard. He came close to him and gave the final shot at the pilot's compartment effectively", white, false);
			printDialogue("\nkilling the enemy LEX.\n", white, true);
			
			printDialogue("William: DAD! COME ON DAD WHERE ARE YOU!", green, true);
						
			printDialogue("\nAs the enemy LEX slowly collapsing, the infantry slowly moves into position to corner the allied LEX.", white, true);
	
			printDialogue("\nIn the proces, William was being chased as he was spotted by the infantry.\n", white, true);
			
			printDialogue("William: DAD HELP! ANYBODY HELP ME!", green, true);
			
			printDialogue("\nThe allied LEX heard of his cries spontaneously sprinting towards him.\n", white, true);
			
			printDialogue("Enemy Soldier: OPEN FIRE AT THAT LEX!", red, true);
			printDialogue("Enemy Soldier: IT'S GETTING CLOSER! MOVE!", red, true);
			
			printDialogue("\nThe infantry moved away from William's position as the allied LEX came rushing in. It grabbed William then rushed to escape town\n", white, true);
			
			printDialogue("William: LET GO OF ME! I NEED TO FIND MY DAD!", green, true);
			printDialogue("Allied LEX: ...", green, true);
			printDialogue("William: DAD! DAD!!!", green, true);
			
			printDialogue("\nWilliam screamed for his Dad until they were outside of the vicinity of town and would seem to head for the farm.\n", white, true);
			
			toFarm = false;
			comingFromTown = true;//Triggers the After LEX Town battle dialogues
		}
		
		else if(warnFamily == false)//If player didn't go to farm and warn family
		{
			printDialogue("\nWilliam speeded his way into town. If this was a race he would've won the gold medal however it wasn't", white, false);
			printDialogue("\nthe medal that would be rewarding in his endeavor but the sight of safety as danger slowly crawled behind his back.", white, true);
			printDialogue("\nThe closer William got into the village the more he noticed that the light isn't coming from houses", white, false);
			printDialogue("\nbut fire spread across the whole town.\n", white, true);	

			printDialogue("William: Oh no... oh no... I'm too late. Why is this happening?", green, true);
	
			printDialogue("\nIn a distance, could be seen a military LEX fighting but was not like the ones in the outskirts. It was", white, false);
			printDialogue("\nholding back the squads of infantry as the citizens slowly evacuated. It looks like its in our side.\n", white, true);
		
			printDialogue("William: I should join the evacuation... But how do I get to the to the other side of town.", green, true);
		
			printDialogue("\nThe ally LEX came into William's view as it tries to fend off the invaders however suddenly another", white, false);
			printDialogue("\nmilitary LEX came out of nowhere and ambushed it caughting it off guard.", white, true);

			printDialogue("\nWilliam: Wa! HE CAME OUT OF NOWHERE! YOU CAN BEAT HIM!", green, true);

			printDialogue("\nThe two LEXs started fighting inside the ruined town however the allied LEX only have a pistol while the", white, false);
			printDialogue("\nenemy LEX have an Assault Rifle at hand.", white, true);
	
			printDialogue("\nThe battle was intense. Going from cover to cover in matter of seconds. The allied LEX managed to accurately", white, false);
			printDialogue("\nhit the enemy LEX however couldn't continously damage him as he was kept suppressed most of the time.", white, true);

			printDialogue("\nThe two tried to outsmart each other. Figuring out each other's movement in a tense sitation. As the battle went", white, false);
			printDialogue("\non, the allied LEX ran out of ammo. It resorted to Close Quarter Combat. The two were even however the infantry slowly", white, false);
			printDialogue("\ncrept into position to ambush the allied LEX. They launched rocket launchers into its blind side of which caught it off guard.", white, true);
	
			printDialogue("\nThe enemy LEX grabbed him and both flung into a building where William was hiding. It smashed the allied LEX's cockpit cover", white, false);
			printDialogue("\nbarely revealing the pilot inside.\n", white, true);
	
			printDialogue("William: Oh no... I should help but what can I do...", green, true);
			
			if(openPackage == true)//If player opened package
			{
				printDialogue("William: I could use the assault rifle in the package or I could hide and hope for the best in this hopeless situation", green, true);
				
				//Choices for Shooting LEX or hiding from LEX
				tempChoices(choicesActions, tempAction, 4, 2, 1);
				displayChoices(tempAction, cActionsSize - 2);
				getline(cin, input);
				tempResult = choiceChecker(input, tempAction, cActionsSize, 0);
		
				if(tempResult == 0)//If player chose to shoot enemy LEX
				{
					printDialogue("William: I should use the assault rifle! That's the right thing to do!", green, true);
	
					printDialogue("\n*RATATAT!!\n", yellow, true);

					printDialogue("William caught the enemy LEX off guard however due to the size of the assault rifle it quickly recoiled out of control and", white, false);
					printDialogue("\nthe enemy LEX simuultaneously grabbed William.", white, true);

					printDialogue("William: LET GO! You stupid giant LEX!", green, true);

					printDialogue("\nThe overwhelming strength of its hand slowly crushed William's LEX even in its desperate attempt to escape. It struggled", white, true);
					printDialogue("\nuntil the enemy LEX destroyed its inner circuitry rendering William's LEX useless.", white, true);
			
					printDialogue("\n[LEX DESTROYED]\n", lightBlue, true);
					LEXDestroyed = true;
				
					printDialogue("\nIn a spontaneous move, the allied LEX overhelmed the enemy LEX knocking it over and rescuing William. While raversing the landscape,", white, false);
					printDialogue("\nthe allied LEX was showered with bullets. It kept running away from the town whilst carrying William in its hands who was uncouncious.", white, true);
		
					comingFromTown = true;//Activates dialogue when coming from Town Invasion
				}
			
				else if(tempResult == 1)//If player chose to hide
				{
					printDialogue("William: I'm sorry... I'm sorry... I'm sorry... I can't beat that thing, I don't anything to beat it with... I'm sorry...", green, true);
	
					printDialogue("\n*William's LEX slowly sat down while hearing the thumps of the enemy LEX destroying the allied LEX's hull.", yellow, true);

					printDialogue("As he sat down, the weight of the LEX caused a bit of a thud that capture the enemy LEX's attention. There was a huge pause", white, false);
					printDialogue("\nin its attacked, its attention was shifted to the building they're inside.", white, true);
			
					printDialogue("The allied LEX knew it has its chance so in a spontaneous move, the allied LEX overhelmed the enemy LEX knocking it over and grabbing", white, false);
					printDialogue("\nWilliam who was surprised and shocked at the same time. While traversing the landscape, the allied LEX was showered with bullets", white, false);
					printDialogue("\nbut it managed to take cover while avoid other LEXs in the area who was converging into town.", white, true);
				
					comingFromTown = true;//Activates dialogue when coming from Town Invasion
					toFarm = false;
				}
				
				else//Error Log
				errorResponse(*scenes, "tempResult", tempResult);
			}
	
			else if(openPackage == false)//If player did not open package
			{
				printDialogue("\n[PACKAGE NOT OPENED]\n", lightBlue, true);
			
				printDialogue("William: I'm sorry... I'm sorry... I'm sorry... I can't beat that thing, I don't anything to beat it with... I'm sorry...", green, true);
		
				printDialogue("\n*William's LEX slowly sat down while hearing the thumps of the enemy LEX destroying the allied LEX's hull.\n", yellow, true);

				printDialogue("\nAs he sat down, the weight of the LEX caused a bit of a thud that capture the enemy LEX's attention. There was a huge pause", white, false);
				printDialogue("\nin its attacked, its attention was shifted to the building they're inside. The allied LEX knew it has its chance so in a", white, false);
				printDialogue("\nspontaneous move, the allied LEX overhelmed the enemy LEX knocking it over and grabbing William who was urprised and shocked at the same time.", white, false);
				printDialogue("\nat the same time. While traversing the landscape, the allied LEX was showered with bullets but it managed to take cover while", white, false);
				printDialogue("\navoid other LEXs in the area who was converging into town.", white, true);
				
				comingFromTown = true;//Activates dialogue when coming from Town Invasion
				toFarm = false;
			}
		}
	}
	*scenes += 1;
	
}

void scene_6(int *scenes)//Eastern Forest
{
	easternForestText();//Display Eastern Forest Text
	
	printDialogue("\nThe Eastern Forest is located near the Outskirts of Town but is more secluded. Legends say there are ghosts that haunt", white, false);
	printDialogue("\nthose who venture inside the forest. Some say once you enter, you never come back.\n", white, true);
	
	printDialogue("Wiliam: I say I bet they never experienced haunting a person wearing a LEX in that forest. This is the perfect", green, false);
	printDialogue("\n     opportunity to test its mobility in rough terrain.", green, true);
	printDialogue("William: I bet I could find a treasure there left behind by people who got scarred because of these legends.", green, true);
	printDialogue("William: When there is treasure, there is MONEY!. Maybe I can finally take steps towards that girl in town.", green, true);
	printDialogue("William: No one can resists the allure of money...", green, true);
	
	printDialogue("\nAs William continously fantasized about the possibility of money, he began travelling toward the said forest. In his", white, false);
	printDialogue("\nabsent mindedness, he unintentionally entered the forest and went deep as well as his immersion in his immagination\n", white, true);
	
	printDialogue("William: Hehe maybe I can buy some upgrade parts for this LEX will at it... Wha- oh I'm already here.", green, true);
	printDialogue("William: I didn't expect the travel to be this short but okay. Now... WHERE IS THAT TREASURE!?", green, true);
	
	printDialogue("\nWilliam started maneuvering in and out of places to look for clues of deserted properties that he, himself, imagined.", white, true);
	
	printDialogue("It took a couple of minutes before he finally realized that there's nothing here but leaves and trees.\n", white, true);
	
	printDialogue("William: I'm already dizzy just looking around in this place. Now that I think about it, how do I get out?", green, true);
	printDialogue("William: I think I went in circles... Which direction should I go?", green, true);
	
	while(true)//Player is lost in the forest
	{
		displayChoices(choicesDirections, cDirectionsSize);
		getline(cin, input);
		tempResult = choiceChecker(input, choicesDirections, cDirectionsSize, 1);
		
		if(tempResult == 1)//North
		{
			printDialogue("William: I guess I go here", green, true);
			
			printDialogue("The forest started whispering. William could hear voices as if crowds of people were present in the vicinity", white, false);
			printDialogue("near him. The more he walked, the louder the voices became.", white, true);
			
			printDialogue("William: I'm not liking this... What is that?", green, true);
			
			printDialogue("Shadowy figures started appearing around the area. They can be seen in a distance but the trees block the view.", white, true);
			
			printDialogue("William: Maybe the rumors are true... I shouldn't have come here... I need to get out of here...", green, true);
			
			printDialogue("William tucked himself behind a tree hoping that this would only be a dream however...", white, true);
			
			printDialogue("*Thud *Thud", yellow, true);
			
			printDialogue("William: Now earthquakes... what have I gotten myself into?", green, true);
			
			printDialogue("\n?: Sir we everyone is acconted for and waiting for orders.", red, true);
			printDialogue("?: Good, now we wait for the signal.\n", red, true);
			
			printDialogue("William: Wait... these are soldiers. There's even military LEXs here. ", green, true);
			printDialogue("William: What are they doing here?", green, true);
			
			printDialogue("\n?: Our main objective is to secure the town. There are also reports of a LEX stationed here.", red, true);
			printDialogue("?: Its current location is unknown but report of any sightings immediately.\n", red, true);
			
			printDialogue("William: They might be talking about me... I should run...", green, true);
			printDialogue("William: Okay... I just need to first slowly get away from here...", green, true);
			
			printDialogue("\nAs William slowly moved away, the officer caught sight of him. His LEX was like a rock in a pile of leaves.", white, false);
			printDialogue("\nThe officer pointed at William and with a loud voice.", white, true);
			
			printDialogue("\n?: AN ONLOOKER!!! KILL HIM!!!", red, true);

			printDialogue("\n[DISCOVERED]\n", lightBlue, true);
			discovered = true;
		
			printDialogue("William: Wha- I need to run into the forest!", green, true);
		
			printDialogue("\n?: THERE HE IS! TAKE HIM OUT BEFORE HE ESCAPES!", red, true);
			
			printDialogue("\n*Gunshots and bullets screeching as it hits William LEX's metal frame and nearby trees~", yellow, true);
			
			printDialogue("William: Oh I'm so dead! I'm so dead! What do I do? What d-", green, true);
			printDialogue("\nThe light suddenly went out in the whole settlement. The volley of bullets suddenly stopped. The only lights", white, false);
			printDialogue("\nseen are from the town and the farm\n", white, true);
			
			printDialogue("?: HOLD YOUR FIRE!!!", red, true);
			printDialogue("?: But sir! He might tell about our advance.", red, true);
			printDialogue("?: Whether he makes it or not, it is already too late. ADVANCE!!!", red, true);
			
			printDialogue("\nIn the midst of darkness, a short but brief thumping could be heard as William's LEX ran into the field", white, false);
			printDialogue("\nhoping he would not get shot~\n", white, true);
	
			printDialogue("\nWilliam: Ah... I somehow managed to escape that situation. I should tell everyone about this.", green, true);
			printDialogue("William: I could go to town and warn everybody or go back to the farm and warn my family.\n", green, false);
			
			//Asks player to go to Town or to Farm
			tempChoices(choicesLocations, tempLocation, 2, 2, 1);
			displayChoices(tempLocation, cLocationsSize - 3);
			getline(cin, input);
			tempResult = choiceChecker(input, tempLocation, cLocationsSize - 3, 1);
			
			if(tempResult == 1)//Scene to Town
			*scenes += tempResult;
			
			else if(tempResult == 2)//Scene to Farm
			{
				*scenes += tempResult;
				toFarm = true;//Activates dialogue if coming from Outskirts, or Eastern Forest
			}
			
			else//Error Log
			errorResponse(*scenes, "tempResult", tempResult);
			
			break;
		}
		
		else if(tempResult == 4)//West
		{
			printDialogue("William: Ahhh... finally got out of that forest. I'm never gonna go there again.", green, true);
			printDialogue("\nThe vast openness of the field gives a sense of freedom. The winds blow towards you though you", white, false);
			printDialogue("were missed and the sweet warmth of light coming from the Yellow Orb is so well missed.\n", white, true);
			
			printDialogue("William: Ahh I thought I would never esc-", green, true);
			
			printDialogue("\nThe light suddenly went out in the whole settlement. The vast fields were instantly absorbed in darkenss.", white, true);
			
			printDialogue("William: What happened? Wait... why's there an earthquake?", green, true);
			
			printDialogue("?: ADVANCE!!!", red, true);
			
			printDialogue("\nAn attack force suddenly came out of the forest. Groups of soldiers slowly appearing and military LEXs", white, false);
			printDialogue("\nstanding above the trees.\n", white, true);
			
			printDialogue("William: Oh no... an invasion! I have to run!", green, true);
			printDialogue("\nIn the midst of darkness, a short but brief thumping could be heard as William's LEX ran into the field", white, false);
			printDialogue("\nhoping he would not be seen.\n", white, true);
	
			printDialogue("William: Ah... I somehow managed to escape that situation. I should tell everyone about this.", green, true);
			printDialogue("William: I could go to town and warn everybody or go back to the farm and warn my family.\n", green, false);
			
			//Scene is based on what the user chooses
			tempChoices(choicesLocations, tempLocation, 2, 2, 1);
			displayChoices(tempLocation, cLocationsSize - 3);
			getline(cin, input);
			*scenes += choiceChecker(input, tempLocation, cLocationsSize - 3, 1);
			
			if(*scenes == 8)
			toFarm = true;//Activates if going to Farm
			
			break;
		}
		
		else if(tempResult == 2 || tempResult == 3)//Uf player chose to go East or South
		{
			printDialogue("William: I guess I go here.", green, true);
			printDialogue("\n5 minutes have passed...\n", white, true);
			printDialogue("William: Nope I think I still went around in circles.", green, true);
		}
		
		else//Error log
		errorResponse(*scenes, "tempResult", tempResult);
	}
}

void scene_5(int *scenes)//Outskirts
{
	outskirtsText();//Displays Outskirts Text
	
	printDialogue("\nWilliam: The outskirts is a flat land where I can run at full speed. The best part no one", green, false);
	printDialogue("\n     is there to complain about me trying out this new LEX.", green, true);

	printDialogue("William: For now, I'm just gonna race towards that hill. Maybe 1 kilometers or so... Alright gonna", green, false);
	printDialogue("\n     secure Dad's package first.", green, true);

	printDialogue("\n*Click!, *Click!", yellow, true);

	printDialogue("\nWilliam: Alright then... OFF WE GO!!!", green, true);
	printDialogue("William: 50...", green, true);
	printDialogue("William: 60...", green, true);
	printDialogue("William: 80...", green, true);
	printDialogue("William: 100!!!", green, true);
	printDialogue("William: Wow this is fast!!! ...oh that is a huge drop... ahhhhhh...", green, true);
	
	if(fellAsleep == true)//If player chose to sleep more
	{
		printDialogue("\n*Crashing into the ground then into the trees~", yellow, true);

		printDialogue("\nIn a usual day, a normal bystander would see a huge field of grass that was surrounded by trees", white, false);
		printDialogue("\nand a hill however that all changed as William's LEX was launched into the sky with a considerable", white, false);
		printDialogue("\namount of height. As it landed, it left a thin line of crushed grass and a bit of dirt that was", white, false);
		printDialogue("\nscattered that could be seen from a distance.", white, true);

		printDialogue("\nWilliam: ... ohhhh... maybe I should've slept more... Dad's gonna kill me... how's the package?", green, true);
		printDialogue("William: ah... shoot, its not here. Is my LEX Functional?", green, true);

		printDialogue("*Engine rumbling...", yellow, true);

		printDialogue("William: Okay... that's something, now if I could just stand...", green, true);

		printDialogue("*The metal frame slowly creakes as it stands up~", yellow, true);

		printDialogue("William: Ah thank goodness, it would've been terrible if I just wrecked this at the first day.", green, true);
		printDialogue("William: Now... ah there it is. Just landed in the field near where I am. Okay... gotcha.", green, true);
		printDialogue("William: Ah... great, the casing's busted. What the-", green, true);
		
		printDialogue("\n[PACKAGE OPENED]\n", lightBlue, true);
		openPackage = true;
		
		printDialogue("William: Why is there an assault rifle in here...", green, true);
		printDialogue("William: Forget the rifle... Dad will really kill me once he finds out about this...", green, true);
		
		printDialogue("\n*Gunshots and bullets screeching in the midst of darkenss as it hits William LEX's metal frame~", yellow, true);

		printDialogue("\n[DISCOVERED]\n", lightBlue, true);
		discovered = true;
		
		printDialogue("William: What the- gotta take cover!", green, true);
		
		printDialogue("?: THERE HE IS! TAKE HIM OUT BEFORE HE ESCAPES!", red, true);
		
		printDialogue("William: This looks bad... Who are these soldiers? I'm surrounded by them in the forest and I could see", green, false);
		printDialogue("\n     military LEXs that were much larger than mine in a distance. What should I do...", green, true);
		
		printDialogue("\nThe light suddenly went out in the whole settlement. The volley of bullets suddenly stopped. The only lights", white, false);
		printDialogue("\nseen are from the town and the farm~\n", white, true);
		
		printDialogue("William: This is my chance! I could go warn everyone but should I go to town and warn everyone or go to the farm and", green, false);
		printDialogue("\n     tell my family of this situation.\n", green,false);
	}
	
	else if(fellAsleep == false)//If player chose to wake up
	{
		printDialogue("\n*A tree slowly falling from its roots~", yellow, true);
		
		printDialogue("\nIn a usual day, a normal bystander would see a huge field of grass that was surrounded by trees", white, false);
		printDialogue("\nand a hill that had a single tree however that all changed as William's LEX managed to grab that", white, false);
		printDialogue("\ntree and divert its trajectory away from the drop.", white, true);
		
		printDialogue("\nWilliam: ... ohhhh... barely managed to survive that... good thing I was fully awake... how's the package?", green, true);
		printDialogue("William: Good its here. What about my LEX?", green, true);
		
		printDialogue("*Checking for any damages~", yellow, true);
		
		printDialogue("William: Okay... great, no damage... now I'll just sit for a while.", green, true);

		printDialogue("*The metal frame slowly creakes as it sits down~", yellow, true);
		
		printDialogue("William: Haha... Dad would've killed me if something happen to the package or if I just wrecked the LEX at the first day.", green, true);
		printDialogue("William: I wonder what's inside this thing. I almost flung away because of this weight. Should I open it?\n", green, false);
		
		//Scene is based on what the user chooses
		
		tempChoices(choicesActions, tempAction, 2, 0, 1);
		displayChoices(tempAction, cActionsSize - 2);
		getline(cin, input);
		tempResult = choiceChecker(input, tempAction, cActionsSize-2, 0);
		
		if(tempResult == 0)//If player chose to open
		{
			printDialogue("\nWilliam: Wow its sealed tight...*POP* What the-", green, true);
		
			printDialogue("\n[PACKAGE OPENED]\n", lightBlue, true);
			openPackage = true;
			
			printDialogue("William: Why is there an assault rifle in here...", green, true);
			printDialogue("William: Eh... don't care, just gonna reseal this so that Dad doesn't not-", green, true);
		}
		
		else if(tempResult == 1)//If player chose to open
		{
			printDialogue("\nWilliam: Nah, I shouldn't mess with other people's stuff.", green, true);
			printDialogue("William: At least it's safe, I would be in huge trouble if I lost this.", green, true);
			printDialogue("William: I think I should start going now...", green, true);
		}
		
		else//Error Log
		errorResponse(*scenes, "tempResult", tempResult);
		
		printDialogue("\nThe light suddenly went out in the whole settlement.\n", white, true);
		
		printDialogue("William: This looks bad... These hasn't happened before... wait...Who are these soldiers? They're coming from the forest.", green, false);
		printDialogue("\n     There's military LEXs that were much larger than mine in a distance. Is this an invasion?", green, true);
		printDialogue("William: What should I do...? At least there's light in the Town and the farm.", green, true);
		printDialogue("William: I could go warn everyone but should I go to town and warn everyone or go to the farm and", green, false);
		printDialogue("\n     tell my family of this situation.\n", green, true);
	}
	
	else//Error Log
	errorResponse(*scenes, "fellAsleep", fellAsleep);
	
	tempChoices(choicesLocations, tempLocation, 2, 2, 1);
	displayChoices(tempLocation, cLocationsSize - 3);
	getline(cin, input);
	*scenes += choiceChecker(input, tempLocation, cLocationsSize - 3, 2);
	
	if(*scenes == 8)//If player chose to go to farm
	toFarm = true;
	
	if(discovered == true)//If player is discovered in the Outskirts, or Eastern Forest
	{
		printDialogue("\nWilliam: I should go to town and warn everybody. They need to know about this.", green, true);

		printDialogue("\nIn the midst of darkness, a short but brief thumping could be heard as William's LEX ran into the field", white, true);
		printDialogue("\nhoping he would not get shot~\n", white, true);

		printDialogue("?: HOLD YOUR FIRE!!!", red, true);
		printDialogue("?: But sir! He might tell about our advance.", red, true);
		printDialogue("?: Whether he makes it or not, it is already too late. ADVANCE!!!", red, true);
	
		printDialogue("\nWilliam: Ah... I somehow managed to escape that situation. I should tell everyone about this.", green, true);
	}
}

void scene_4(int *scenes)//Main Branching Point, Farm
{
	printDialogue("\nAs you walk out of bed, the light shimmers through your eyes as you face another day. The", white, false);
	printDialogue("\nbright green fields in the front, the smell of iron and rocks as you look into the window,", white, false);
	printDialogue("\nand the bright yellow orb that hovers above the settlement.", white, true);
	
	printDialogue("Welcome back to life in the settlement as part of humanity that survived Global Warming and hide", white, false);
	printDialogue("\nunderground where resources are scarce as people's enjoyment and deep as  my boredom gets everyday", white, true);
	
	printDialogue("\nDad: William can you use the LEX to bring this ... to the townhall... oh for the love of...\n", green, true);
	
	printDialogue("*The land is rumbling as something is getting closer... with a distinctive sound of an engine~", yellow, true);
	
	printDialogue("\nApart from LEXs where they're just so fun to pilot. LEXs are short for Large Exo-suits. They're", white, false);
	printDialogue("\nprimarily used for labor intensive work. They were manufactured as a means to help in Humanity's survival.", white, true);
	
	printDialogue("\nBut I use them as means to escape bordem. I mean this is a mech that was inspired by decades old Sci-FI fiction.\n", white, true);
	
	printDialogue("William: Already on it Dad, thanks for the gift!", green, true);
	printDialogue("Dad: WILLIAM!! You better take care of that package! TOWNHALL!", green, true);
	
	printDialogue("\nA distant William and his LEX slowly disappearing from sight~\n", white, true);
	
	printDialogue("Dad: Where is he even going?", green, true);
	printDialogue("Mom: Don't worry about him. He's just testing out his new LEX", pink, true);
	printDialogue("Dad: Maybe it was a bad idea to give him a LEX for his birthday.", green, true);
	printDialogue("Mom: Well at least he's happy and besides at least you don't have to worry about your back.", pink, true);
	printDialogue("Dad: I'm more worried about Will's back breaking at that speed.", green, true);
	printDialogue("Mom: Wow, I wonder who he inherited that sense of thrill.", pink, true);
	printDialogue("Dad: At least I don't go near people when travelling at that speed.", green, true);
	printDialogue("Mom: Yeah... right, anyways take care of the har-", pink, true);
	printDialogue("Emily: DAD! Someone from the council's calling for you in town.", pink, true);
	printDialogue("Dad: Great... maybe I should've been the one to bring the package.", green, true);
	printDialogue("Mom: Huh... must be important since they last called for you around 10 years ago.", pink, true);
	
	printDialogue("Dad: Uhh... don't remind of those times. I'll just harvest the field later when I get back.", green, false);
	printDialogue("\n     Emily don't let your brother touch the field when he gets back.", green, true);
	
	printDialogue("Emily: okay, Where is he even going? The town is in the other direction.", green, true);
	printDialogue("\nWhile in a distance...", white, true);
	printDialogue("\nWilliam: THIS IS THE BEST BIRTHDAY GIFT EVER!!!", green, true);
	
	printDialogue("William: hmm... What is this package anyways, it feels heavy. Well no matter, I'm pretty sure", green, false);
	printDialogue("\n     I still have time so where should I drive this around for now?", green, true);
	
	printDialogue("William: I could travel to the outskirts where I can test this LEX's speed, or go to the eastern", green, false);
	printDialogue("\n     forest and explore, or just go to town and do what Dad told me to do.\n", green, false);
	
	//Scene is based on what the user chooses
	tempChoices(choicesLocations, tempLocation, 3, 0, 1);
	displayChoices(tempLocation, cLocationsSize - 2);
	getline(cin, input);
	*scenes += choiceChecker(input, tempLocation, cLocationsSize - 2, 1);
	
	if(*scenes == 7)//To Town
	{
		fromFarmToTown = true;//If player chose to go to Town
		
		printDialogue("\nWilliam: I guess I'll first go to town. I'll be killed if something happens to this package.", green, true);
		printDialogue("William: I should avoid my house for now...", green, true);
		printDialogue("William: Emily might see and just laugh.", green, true);
		printDialogue("William: Its embarassing that I went the opposite direction where the town is and just come back around.", green, true);
	}

}

void scene_3(int *scenes)//Still Sleepy Route
{
	printDialogue("\n[STILL SLEEPY]\n", lightBlue, true);
	fellAsleep = true;//Route depended variable correlated to outskirt route
	
	printDialogue("\n?:You little piece of ...", pink, true);
	printDialogue("?:WAKE UP!!!", pink, true);
	printDialogue("?:WAKE UP WILL!!!!", pink, true);
	printDialogue("William: wha? Emily?", green, true);
	
	printDialogue("William: 5 more minutes...", green, true);
	printDialogue("Emily: DAD IS CALLING YOU IN THE FARM!", pink, true);
	printDialogue("William: Then 5 more minutes it is...", green, true);
	
	printDialogue("\nThe morning's warmth radiates to you as Emily's anger reaches boiling point. As you close", white, false);
	printDialogue("\nyour eyes, you gracefully receive the most brutle wake up call you have ever received your", white, false);
	printDialogue("\nentire life.", white, true);
	
	printDialogue("William: Oh how I hate mornings...", green, true);
	
	*scenes += 1;//Next scene
}

void scene_2(int *scenes)//Fully Awake Route
{
	printDialogue("\n[FULLY AWAKE]\n", lightBlue, true);
	
	printDialogue("?:Oh good, you're awake. I was about to wake you up.", pink, true);
	printDialogue("William: Good morning Emily, thank goodness I managed to wake up before you coming.", green, true);
	printDialogue("Emily: It's really a miracle since you usually take hours before you wake up.", pink, true);
	printDialogue("William: Tell that to my sore arm that you did yesterday.", green, true);
	printDialogue("Emily: It's not that bad, anyways Dad is calling you in the farm.", pink, true);
	printDialogue("William: Oh how I hate mornings...", green, true);
	
	*scenes += 2;
}

void scene_1(int *scenes)//Alarm Clock
{
	if(numberSleeps == 0)
	{
		printDialogue("\nBeep Beep!!!\n", yellow, false);
		displayChoices(choicesPrologue, cPrologueSize);//To sleep or not to sleep
		getline(cin, input);
		
		*scenes = choiceChecker(input, choicesPrologue, cPrologueSize, 1);

		++numberSleeps;//If player chose to sleep, add to number of sleeps
	}
	
	else if(numberSleeps >= 3)//If player sleeps too much
	*scenes += 2;//Skip to Still sleepy route
	
	else if(numberSleeps < 3)
	{
		printDialogue("\n15 minutes have passed...\n", white, false);
		printDialogue("\nBeep Beep!!!\n", yellow, false);
		displayChoices(choicesPrologue, cPrologueSize);//To sleep or not to sleep
		getline(cin, input);
		
		*scenes = choiceChecker(input, choicesPrologue, cPrologueSize, 1);

		++numberSleeps;//If player chose to sleep, add to number of sleeps
	}
	
	else//Error log
	errorResponse(*scenes, "numberSleeps", numberSleeps);
}

void title(int *scenes)//Title Screen
{
	int indexMenu, indexSettings, indexSlowText;
		
	printDialogue(  " ___      _______  _______  _______    _______  _______  _______  __    _  ______              _______  ______    _______  ___      _______  _______  __   __  _______ ", white, false);
    printDialogue("\n|   |    |   _   ||       ||       |  |       ||       ||   _   ||  |  | ||      |            |       ||    _ |  |       ||   |    |       ||       ||  | |  ||       |", white, false);
    printDialogue("\n|   |    |  |_|  ||  _____||_     _|  |  _____||_     _||  |_|  ||   |_| ||  _    |   ____    |    _  ||   | ||  |   _   ||   |    |   _   ||    ___||  | |  ||    ___|", white, false);
	printDialogue("\n|   |    |       || |_____   |   |    | |_____   |   |  |       ||       || | |   |  |____|   |   |_| ||   |_||_ |  | |  ||   |    |  | |  ||   | __ |  |_|  ||   |___ ", white, false);
	printDialogue("\n|   |___ |       ||_____  |  |   |    |_____  |  |   |  |       ||  _    || |_|   |           |    ___||    __  ||  |_|  ||   |___ |  |_|  ||   ||  ||       ||    ___|", white, false);
	printDialogue("\n|       ||   _   | _____| |  |   |     _____| |  |   |  |   _   || | |   ||       |           |   |    |   |  | ||       ||       ||       ||   |_| ||       ||   |___ ", white, false);
	printDialogue("\n|_______||__| |__||_______|  |___|    |_______|  |___|  |__| |__||_|  |__||______|            |___|    |___|  |_||_______||_______||_______||_______||_______||_______|\n", white, false);

	printDialogue("\n***NOTE: THIS GAME'S CHOICES ARE CASE SENSITIVE***", green, true);
	while(true)
	{
		displayChoices(titleMenu, menu);
		getline(cin, input);
		
		//\if(input == "debug")
		
		
		indexMenu = choiceChecker(input, titleMenu, menu, 0);
		
		if(indexMenu == 0)//Start
		{
			*scenes += 1;
			break;
		}
		else if(indexMenu == 1)//Settings
		{
			while(true)
			{
				displayChoices(titleSettings, settings);
				getline(cin, input);
				indexSettings = choiceChecker(input, titleSettings, settings, 1);

				if(indexSettings == 1)//Slow Text
				{
					printDialogue("\nTrue for slowly rendered text, False for instant dialogue.\n", white, false);
					displayChoices(userTextSlow, uTextSlow);
					getline(cin, input);
					indexSlowText = choiceChecker(input, userTextSlow, uTextSlow, 1);
					
					if(indexSlowText == 1)
					userWantSlowText = true;
					
					else if(indexSlowText == 2)
					userWantSlowText = false;
					
					else
					errorResponse(*scenes, "indexSettings", indexSettings);
				}
				else if(indexSettings == 2)//TextSpeed
				{
					printDialogue("\n1 is the fastest and 5 is the slowest\n", white, false);
					displayChoices(userTextSpeed, uTextSpeed);
					getline(cin, input);
					textSpeed = choiceChecker(input, userTextSpeed, uTextSpeed, 0);
					
					if(textSpeed > 5)
					errorResponse(*scenes, "textSpeed", textSpeed);
				}
				else if(indexSettings == 3)//Back
				break;
				
				else
				errorResponse(*scenes, "indexSettings", indexSettings);
			}
		}
		else if(indexMenu == 2)//Exit
		exit(0);
		
		else
		errorResponse(*scenes, "indexMenu", indexMenu);
	}
}

void introduction()
{
	int indexMenu, indexSettings, indexSlowText;
	printDialogue("\n---------------------PRESS ENTER TO ENTER GAME---------------------", green, true);
	
	printDialogue("...", green, true);
	printDialogue("...", green, true);
	printDialogue("...", green, true);
	
	printDialogue("\n\n***FOR BEST EXPERIENCE, GO FULL SCREEN AND EXPERIENCE THE STORY IN A WALL OF TEXT**", white, true);
	
	printDialogue("Made By ", white, true);
	
	printDialogue(  " __   __  _______  ______    _______  _______ ", white, false);
    printDialogue("\n|  | |  ||       ||    _ |  |       ||       |", white, false);
    printDialogue("\n|  |_|  ||    ___||   | ||  |    ___||   _   |", white, false);
	printDialogue("\n|       ||   |___ |   |_||_ |   | __ |  | |  |", white, false);	
	printDialogue("\n|_     _||    ___||    __  ||   ||  ||  |_|  |", white, false);
	printDialogue("\n  |   |  |   |___ |   |  | ||   |_| ||       |", white, false);
	printDialogue("\n  |___|  |_______||___|  |_||_______||_______|", white, true);
	
	printDialogue("\n( Datu Elias N. Diego GD - 11 )", red, true);
	
	printDialogue("When in doubt, cout.", white, false);
	printDialogue("\n(GD- 11, 2018)", white, true);
	
	printDialogue("REQUIREMENTS FOR	", white, true);
	
	printDialogue(  " __   __  ___   ______   _______  _______  ______    __   __  _______ ", white, false);
    printDialogue("\n|  |_|  ||   | |      | |       ||       ||    _ |  |  |_|  ||       |", white, false);
    printDialogue("\n|       ||   | |  _    ||_     _||    ___||   | ||  |       ||  _____|", white, false);
	printDialogue("\n|       ||   | | | |   |  |   |  |   |___ |   |_||_ |       || |_____ ", white, false);	
	printDialogue("\n|       ||   | | |_|   |  |   |  |    ___||    __  ||       ||_____  |", white, false);
	printDialogue("\n| ||_|| ||   | |       |  |   |  |   |___ |   |  | || ||_|| | _____| |", white, false);
	printDialogue("\n|_|   |_||___| |______|   |___|  |_______||___|  |_||_|   |_||_______|", white, true);
	
}

main()
{
		
	introduction();
	int scenes = 0;
	
	while(true)
	{
		switch(scenes)
		{
			case 0:
				title(&scenes);
				break;
			case 1:
				scene_1(&scenes);
				break;
			case 2:
				scene_2(&scenes);
				break;
			case 3:
				scene_3(&scenes);
				break;
			case 4:
				scene_4(&scenes);
				break;
			case 5:
				scene_5(&scenes);
				break;
			case 6:
				scene_6(&scenes);
				break;
			case 7:
				scene_7(&scenes);
				break;
			case 8:
				scene_8(&scenes);
				break;
			case 9:
				scene_9(&scenes);
				break;
			case 10:
				printDialogue("-----END OF PROLOGUE-----", green, true);
				printDialogue("Message from developer:", red, true);
				printDialogue("I wanted to do a present scene where William wakes up in a wreck LEX while Emily is trying to contact him.", white, true);
				printDialogue("\nDue to bugs and confused story elements caused me to delay my progress in the development phase.", white, true);
				printDialogue("\nI genuinely want to finish this prologue completely and cleanly. I hope you enjoy playing this game.", white, true);
				
				printDialogue("\n\nRETURNING TO MAIN TITLE.\n", white, true);

				scenes = 0;
				break;
			default:
				cout << "SCENE: " << scenes << " NOT FOUND.\n";
				cin.get();
				break;
		}
	}
	return (0);
}
