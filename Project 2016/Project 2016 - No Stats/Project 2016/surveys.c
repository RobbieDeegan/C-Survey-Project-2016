// Robert Deegan - G00320583
// Year 2 Semester 2 Project - March/April 2016
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// Global Variables	
int totalSurveys;
int totalSmokers, totalExercise, totalAlcohol;
int totalNonSmokers, totalNoExercise, totalNoAlcohol;
int ageBracketOneCount, ageBracketTwoCount, ageBracketThreeCount, ageBracketFourCount, ageBracketFiveCount;
int incomeBracketOneCount, incomeBracketTwoCount, incomeBracketThreeCount, incomeBracketFourCount, incomeBracketFiveCount, incomeBracketSixCount, incomeBracketSevenCount;
int exerciseBracketOneCount, exerciseBracketTwoCount, exerciseBracketThreeCount, exerciseBracketFourCount;
int alcoholBracketOneCount, alcoholBracketTwoCount, alcoholBracketThreeCount, alcoholBracketFourCount;
int cigarettesBracketOneCount, cigarettesBracketTwoCount, cigarettesBracketThreeCount, cigarettesBracketFourCount;

// Intialising Struct to hold the survey details
typedef struct survey {
	int ppsNo;
	char firstName[20];
	char secondName[20];
	char address[50];
	char email[50];
	int ageBracket;
	int incomeBracket;
	int exerciseBracket;
	int alcoholBracket;
	int cigarettesBracket;
}survey_t;

// Declaring Functions to add a survey, display a survey, display all surveys, update a survey
// delete a survey or tp generate statistics from all surveys
void addSurvey(survey_t* database, int size);
void displaySurveys(survey_t* database, int size);
void search(survey_t* database, int size);
void updateSurvey(survey_t* database, int size);
void deleteSurvey(survey_t* database, int size);
void generateStats(survey_t* database, int size);
void printFile(survey_t* database, int size);

void main() {

	// Declaring and Intialising Variables
	int numberOfSurveys;
	int i = 0;
	int choice;
	survey_t* database;
	char userEntered[20];
	char passwordEntered[20];

	char c = "";

	// Usernames and Passwords
	char user1[30] = "robert";
	char password1[30] = "united";
	char user2[30] = "martin";
	char password2[30] = "hynes1";
	char user3[30] = "peter";
	char password3[30] = "golf10";

	// Prompt to enter username and password
	printf("Please Enter User Name: ");
	scanf("%s", userEntered);
	printf("Please Enter Password (Six Characters): ");
	
	// Code to display stars as password
	for (i = 0; i < 6; i++) // loop six times for a six character password
	{
		c = getch(); // c is the character entered
		passwordEntered[i] = c; // set letter i in the char passwordEntered to be c
		c = '*'; // c is now equal to a star
		printf("%c", c); // display the star on the command prompt
	}

	passwordEntered[i] = '\0';
	
	// Prompt for user name and password and check if they are valid
	if ((strcmp(user1, userEntered) == 0 && (strcmp(password1, passwordEntered) == 0)) ||
		(strcmp(user2, userEntered) == 0 && (strcmp(password2, passwordEntered) == 0)) ||
		(strcmp(user3, userEntered) == 0 && (strcmp(password3, passwordEntered) == 0)))
	{

		printf("\n\nPlease Enter Amount of Surveys you want to store: ");
		scanf("%d", &numberOfSurveys);

		// Dynamically Allocating the Array 
		database = (survey_t*)malloc(sizeof(survey_t)*numberOfSurveys);

		// Set All the PPS Numbers to 0
		for (i = 0; i < numberOfSurveys; i++)
		{
			(database + i)->ppsNo = 0;
		}

		// Get the Users Choice
		do
		{
			printf("\nPlease Enter 1 to Add a Survey");
			printf("\nPlease Enter 2 to Display all Surveys to Screen");
			printf("\nPlease Enter 3 Display a Surveys Details");
			printf("\nPlease Enter 4 to Update a Survey");
			printf("\nPlease Enter 5 to Delete a Survey");
			printf("\nPlease Enter 6 to Generate Statsistics from a Surveys");
			printf("\nPlease Enter 7 to Print Surveys to a Report File");
			printf("\nEnter -1 to Exit: ");

			scanf("%d", &choice);

			if (choice == 1)
				addSurvey(database, numberOfSurveys);
			else if (choice == 2)
				displaySurveys(database, numberOfSurveys);
			else if (choice == 3)
				search(database, numberOfSurveys);
			else if (choice == 4)
				updateSurvey(database, numberOfSurveys);
			else if (choice == 5)
				deleteSurvey(database, numberOfSurveys);
			else if (choice == 6)
				generateStats(database, numberOfSurveys);
			else if (choice == 7)
				printFile(database, numberOfSurveys);

		} while (choice != -1);
	}

	// Free the Dynamic Memory Allocated
	free(database);

} // End Main

void addSurvey(survey_t* database, int size)
{
	int i;
	int ageChoice = 0;
	int incomeChoice = 0;
	int exerciseChoice = 0;
	int alcoholChoice = 0;
	int cigerettesChoice = 0;

	// Loop Through to Find an Empty Element
	for (i = 0; i < size; i++)
	{
		// If an Empty Element is Found
		if ((database + i)->ppsNo == 0)
		{
			// Ask for Survey Details and Store
			printf("\nPlease Enter Your PPS Number: ");
			scanf("%d", &(database + i)->ppsNo);
			printf("Please Enter the First Name: ");
			scanf("%s", (database + i)->firstName);
			printf("Please Enter the Second Name: ");
			scanf("%s", (database + i)->secondName);
			printf("Please Enter Your Address: ");
			scanf("%s", (database + i)->address);
			printf("Please Enter Your Email Address: ");
			scanf("%s", (database + i)->email);
			
			printf("Please Enter the Age Bracket Your in:");
			printf("\n1: 18-20	2: 20-30	 3: 30-50	4: 50-65	 5: 65+\n");
			scanf("%d", &ageChoice);

			if (ageChoice == 1) {
				(database + i)->ageBracket = ageChoice;
				ageBracketOneCount++;
			}
			else if (ageChoice == 2) {
				(database + i)->ageBracket = ageChoice;
				ageBracketTwoCount++;
			}
			else if (ageChoice == 3) {
				(database + i)->ageBracket = ageChoice;
				ageBracketThreeCount++;
			}
			else if (ageChoice == 4) {
				(database + i)->ageBracket = ageChoice;
				ageBracketFourCount++;
			}
			else if (ageChoice == 5) {
				(database + i)->ageBracket = ageChoice;
				ageBracketFiveCount++;
			}

			printf("Please Enter the Income Bracket Your in:");
			printf("\n1: No Income	2: <20,000	3: <40,000	4: <60,000	5: <80,000	6: <100,000	7: >100,000\n");
			scanf("%d", &incomeChoice);

			if (incomeChoice == 1) {
				(database + i)->incomeBracket = incomeChoice;
				incomeBracketOneCount++;
			}
			else if (incomeChoice == 2) {

				(database + i)->incomeBracket = incomeChoice;
				incomeBracketTwoCount++;
			}
			else if (incomeChoice == 3)
				(database + i)->incomeBracket = incomeChoice;
			else if (incomeChoice == 4)
				(database + i)->incomeBracket = incomeChoice;
			else if (incomeChoice == 5)
				(database + i)->incomeBracket = incomeChoice;
			else if (incomeChoice == 6)
				(database + i)->incomeBracket = incomeChoice;
			else if (incomeChoice == 7)
				(database + i)->incomeBracket = incomeChoice;

			printf("How Often Do You Exercise per Week?:");
			printf("\n1: Never 2: <3 3: <5 4: >5\n");
			scanf("%d", &exerciseChoice);

			if (exerciseChoice == 1)
				(database + i)->exerciseBracket = exerciseChoice;
			else if (exerciseChoice == 2)
				(database + i)->exerciseBracket = exerciseChoice;
			else if (exerciseChoice == 3)
				(database + i)->exerciseBracket = exerciseChoice;
			else if (exerciseChoice == 4)
				(database + i)->exerciseBracket = exerciseChoice;

			printf("How Many Units of Alcohol do You Consume per Week");
			printf("\n1: 0	2:	<2	3: <4	4: >4\n");
			scanf("%d", &alcoholChoice);

			if (alcoholChoice == 1)
				(database + i)->alcoholBracket = alcoholChoice;
			else if (alcoholChoice == 2)
				(database + i)->alcoholBracket = alcoholChoice;
			else if (alcoholChoice == 3)
				(database + i)->alcoholBracket = alcoholChoice;
			else if (alcoholChoice == 4)
				(database + i)->alcoholBracket = alcoholChoice;

			printf("How Many Cigerettes do you Smoke per Week?:");
			printf("\n1: 0 2: <20	3: <40	4: >40\n");
			scanf("%d", &cigerettesChoice);

			if (cigerettesChoice == 1) {
				(database + i)->cigarettesBracket = cigerettesChoice;
				cigarettesBracketOneCount++;
			}
			else if (cigerettesChoice == 2) {
				(database + i)->cigarettesBracket = cigerettesChoice;
				cigarettesBracketTwoCount++;
				totalSmokers++;
			}
			else if (cigerettesChoice == 3) {
				(database + i)->cigarettesBracket = cigerettesChoice;
				cigarettesBracketThreeCount++;
				totalSmokers++;
			}
			else if (cigerettesChoice == 4) {
				(database + i)->cigarettesBracket = cigerettesChoice;
				cigarettesBracketFourCount++;
				totalSmokers++;
			}

			// Set i = 1 to Show Loop is Finsished
			totalSurveys++;
			i = size;

		} // End if

		  // If no Empty Element is Found the Array is Full
		else if (i == size - 1)
		{
			printf("\nTHE ARRAY IS FULL!!\n");
		}
	}

}// End addSurvey()

void search(survey_t* database, int size)
{
	int i;
	int choice = 0;
	int searchPPS = 0;
	char searchFirst[20];
	char searchSecond[20];

	// Get Users Search Deatails... Either by PPS Number or by name
	printf("\nDo you want to Search by 1.PPS Number or 2.Name?\n");
	scanf("%d", &choice);

	if (choice == 1) 
	{
		printf("\nPlease Enter PPS Number of Survey You Want to View: ");
		scanf("%d", &searchPPS);

		for (i = 0; i < size; i++)
		{
			// If Found, Display the Survey Details
			if ((database + i)->ppsNo == searchPPS)
			{
				printf("\nPPS Number: %d\n", (database + i)->ppsNo);
				printf("First Name: %s\n", (database + i)->firstName);
				printf("Second Name: %s\n", (database + i)->secondName);
				printf("Address: %s\n", (database + i)->address);
				printf("E-mail Address: %s\n", (database + i)->email);

				switch ((database + i)->ageBracket) {
					case 1:
						printf("Age Bracket: 18-20\n");
						break;
					case 2:
						printf("Age Bracket: 20-30\n");
						break;
					case 3:
						printf("Age Bracket: 30-50\n");
						break;
					case 4:
						printf("Age Bracket: 50-65\n");
						break;
					case 5:
						printf("Age Bracket: 65+\n");
						break;
				}

				switch ((database + i)->incomeBracket) {
				case 1:
					printf("Income Bracket: No Income\n");
					break;
				case 2:
					printf("Income Bracket: <20,000\n");
					break;
				case 3:
					printf("Income Bracket: <40,000\n");
					break;
				case 4:
					printf("Income Bracket: <60,000\n");
					break;
				case 5:
					printf("Income Bracket: <80,000\n");
					break;
				case 6:
					printf("Income Bracket: <100,000\n");
					break;
				case 7:
					printf("Income Bracket: >100,000\n");
					break;
				}

				switch ((database + i)->exerciseBracket) {
				case 1:
					printf("Exercise Bracket: Never\n");
					break;
				case 2:
					printf("Exercise Bracket: <3 Times per Week\n");
					break;
				case 3:
					printf("Exercise Bracket: <5 Times per Week\n");
					break;
				case 4:
					printf("Exercise Bracket: >5 Times per Week\n");
					break;
				}

				switch ((database + i)->alcoholBracket) {
				case 1:
					printf("Alcohol Bracket: 0 Units\n");
					break;
				case 2:
					printf("Alcohol Bracket: <2 Units\n");
					break;
				case 3:
					printf("Alcohol Bracket: <4 Units\n");
					break;
				case 4:
					printf("Alcohol Bracket: >4 Units\n");
					break;
				}

				switch ((database + i)->cigarettesBracket) {
				case 1:
					printf("Cigerettes Bracket: 0\n");
					break;
				case 2:
					printf("Cigerettes Bracket: <20\n");
					break;
				case 3:
					printf("Cigerettes Bracket: <40\n");
					break;
				case 4:
					printf("Cigerettes Bracket: >40n");
					break;
				}

				// Set i = 1 to Show Loop is Finsished
				i = size;
			}

			// If Not Found the Survey is Not in the Array
			else if (i == size - 1)
			{
				printf("\nThis Survey is NOT in the Database!!\n");
			}
		} // for
	} // if

	else if (choice == 2)
	{
		printf("\nPlease Enter First Name of Survey You Want to View: ");
		scanf("%s", searchFirst);
		printf("Please Enter Second Name of Survey You Want to View: ");
		scanf("%s", searchSecond);

		// Loop Thorugh Array to Find Survey Details
		for (i = 0; i < size; i++)
		{
			// If Found, Display the Survey Details
			if (strcmp((database + i)->firstName, searchFirst) == 0 && (strcmp((database + i)->secondName, searchSecond) == 0))
			{
				printf("\nPPS Number: %d\n", (database + i)->ppsNo);
				printf("First Name: %s\n", (database + i)->firstName);
				printf("Second Name: %s\n", (database + i)->secondName);
				printf("Address: %s\n", (database + i)->address);
				printf("E-mail Address: %s\n", (database + i)->email);

				switch ((database + i)->ageBracket) {
					case 1:
						printf("Age Bracket: 18-20\n");
						break;
					case 2:
						printf("Age Bracket: 20-30\n");
						break;
					case 3:
						printf("Age Bracket: 30-50\n");
						break;
					case 4:
						printf("Age Bracket: 50-65\n");
						break;
					case 5:
						printf("Age Bracket: 65+\n");
						break;
				} // switch

				switch ((database + i)->incomeBracket) {
				case 1:
					printf("Income Bracket: No Income\n");
					break;
				case 2:
					printf("Income Bracket: <20,000\n");
					break;
				case 3:
					printf("Income Bracket: <40,000\n");
					break;
				case 4:
					printf("Income Bracket: <60,000\n");
					break;
				case 5:
					printf("Income Bracket: <80,000\n");
					break;
				case 6:
					printf("Income Bracket: <100,000\n");
					break;
				case 7:
					printf("Income Bracket: >100,000\n");
					break;
				}

				switch ((database + i)->exerciseBracket) {
				case 1:
					printf("Exercise Bracket: Never\n");
					break;
				case 2:
					printf("Exercise Bracket: <3 Times per Week\n");
					break;
				case 3:
					printf("Exercise Bracket: <5 Times per Week\n");
					break;
				case 4:
					printf("Exercise Bracket: >5 Times per Week\n");
					break;
				}

				switch ((database + i)->alcoholBracket) {
				case 1:
					printf("Alcohol Bracket: 0 Units\n");
					break;
				case 2:
					printf("Alcohol Bracket: <2 Units\n");
					break;
				case 3:
					printf("Alcohol Bracket: <4 Units\n");
					break;
				case 4:
					printf("Alcohol Bracket: >4 Units\n");
					break;
				}

				switch ((database + i)->cigarettesBracket) {
				case 1:
					printf("Cigerettes Bracket: 0\n");
					break;
				case 2:
					printf("Cigerettes Bracket: <20\n");
					break;
				case 3:
					printf("Cigerettes Bracket: <40\n");
					break;
				case 4:
					printf("Cigerettes Bracket: >40\n");
					break;
				}

				// Set i = 1 to Show Loop is Finsished
				i = size;
			} // if

			// If Not Found the Survey is Not in the Array
			else if (i == size - 1)
			{
				printf("\nThis Survey is NOT in the Database!!\n");
			} //else if

		} // for
	}

} // End search()

void displaySurveys(survey_t* database, int size)
{
	int i;

	for (i = 0; i < size; i++) // Loop Through Array
	{
		if ((database + i)->ppsNo != 0) // Only Print Elements with Details Entered (ppsNo not = 0)
		{
			printf("\nSurvey %d Details: \n", i + 1);
			printf("PPS Number: %d\n", (database + i)->ppsNo);
			printf("First Name: %s\n", (database + i)->firstName);
			printf("Second Name: %s\n", (database + i)->secondName);
			printf("Address: %s\n", (database + i)->address);
			printf("E-mail Address: %s\n", (database + i)->email);

			switch ((database + i)->ageBracket) {
				case 1:
					printf("Age Bracket: 18-20\n");
					break;
				case 2:
					printf("Age Bracket: 20-30\n");
					break;
				case 3:
					printf("Age Bracket: 30-50\n");
					break;
				case 4:
					printf("Age Bracket: 50-65\n");
					break;
				case 5:
					printf("Age Bracket: 65+\n");
					break;
			} // switch

			switch ((database + i)->incomeBracket) {
			case 1:
				printf("Income Bracket: No Income\n");
				break;
			case 2:
				printf("Income Bracket: <20,000\n");
				break;
			case 3:
				printf("Income Bracket: <40,000\n");
				break;
			case 4:
				printf("Income Bracket: <60,000\n");
				break;
			case 5:
				printf("Income Bracket: <80,000\n");
				break;
			case 6:
				printf("Income Bracket: <100,000\n");
				break;
			case 7:
				printf("Income Bracket: >100,000\n");
				break;
			}

			switch ((database + i)->exerciseBracket) {
			case 1:
				printf("Exercise Bracket: Never\n");
				break;
			case 2:
				printf("Exercise Bracket: <3 Times per Week\n");
				break;
			case 3:
				printf("Exercise Bracket: <5 Times per Week\n");
				break;
			case 4:
				printf("Exercise Bracket: >5 Times per Week\n");
				break;
			}

			switch ((database + i)->alcoholBracket) {
			case 1:
				printf("Alcohol Bracket: 0 Units\n");
				break;
			case 2:
				printf("Alcohol Bracket: <2 Units\n");
				break;
			case 3:
				printf("Alcohol Bracket: <4 Units\n");
				break;
			case 4:
				printf("Alcohol Bracket: >4 Units\n");
				break;
			}

			switch ((database + i)->cigarettesBracket) {
			case 1:
				printf("Cigerettes Bracket: 0\n");
				break;
			case 2:
				printf("Cigerettes Bracket: <20\n");
				break;
			case 3:
				printf("Cigerettes Bracket: <40\n");
				break;
			case 4:
				printf("Cigerettes Bracket: >40\n");
				break;
			}
		}
	}

} // End displayCar()

void updateSurvey(survey_t* database, int size)
{
	int i;
	int choice = 0;
	int searchPPS = 0;
	char searchFirst[20];
	char searchSecond[20];

	int ageChoice = 0;
	int incomeChoice = 0;
	int exerciseChoice = 0;
	int alcoholChoice = 0;
	int cigerettesChoice = 0;

	// Get Users Search Deatails... Either by PPS Number or by name
	printf("\nDo you want to Search by 1.PPS Number or 2.Name?\n");
	scanf("%d", &choice);

	if (choice == 1)
	{
		// Get the users search criteria
		printf("\nPlease enter the PPS number: ");
		scanf("%d", &searchPPS);

		// Loop through the array
		for (i = 0; i < size; i++)
		{
			// if found the search criteria - then display the survey details
			if ((database + i)->ppsNo == searchPPS)
			{
				// Ask for and store the new details
				printf("\nPlease Enter Your Updated PPS Number: ");
				scanf("%d", &(database + i)->ppsNo);
				printf("Please Enter the Updated First Name: ");
				scanf("%s", (database + i)->firstName);
				printf("Please Enter the Updated Second Name: ");
				scanf("%s", (database + i)->secondName);
				printf("Please Enter Your Updated Address: ");
				scanf("%s", (database + i)->address);
				printf("Please Enter Your Updated Email Address: ");
				scanf("%s", (database + i)->email);

				printf("Please Enter the Age Bracket Your in:");
				printf("\n1: 18-20	2: 20-30	3: 30-50	4: 50-65	5: 65+\n");
				scanf("%d", &ageChoice);

				if (ageChoice == 1)
					(database + i)->ageBracket = ageChoice;
				else if (ageChoice == 2)
					(database + i)->ageBracket = ageChoice;
				else if (ageChoice == 3)
					(database + i)->ageBracket = ageChoice;
				else if (ageChoice == 4)
					(database + i)->ageBracket = ageChoice;
				else if (ageChoice == 5)
					(database + i)->ageBracket = ageChoice;

				printf("Please Enter the Income Bracket Your in:");
				printf("\n1: No Income	2: <20,000	3: <40,000	4: <60,000	5: <80,000	6: <100,000	7: >100,000\n");
				scanf("%d", &incomeChoice);

				if (incomeChoice == 1)
					(database + i)->incomeBracket = incomeChoice;
				else if (incomeChoice == 2)
					(database + i)->incomeBracket = incomeChoice;
				else if (incomeChoice == 3)
					(database + i)->incomeBracket = incomeChoice;
				else if (incomeChoice == 4)
					(database + i)->incomeBracket = incomeChoice;
				else if (incomeChoice == 5)
					(database + i)->incomeBracket = incomeChoice;
				else if (incomeChoice == 6)
					(database + i)->incomeBracket = incomeChoice;
				else if (incomeChoice == 7)
					(database + i)->incomeBracket = incomeChoice;

				printf("How Often Do You Exercise per Week?:");
				printf("\n1: Never 2: <3 3: <5 4: >5\n");
				scanf("%d", &exerciseChoice);

				if (exerciseChoice == 1)
					(database + i)->exerciseBracket = exerciseChoice;
				else if (exerciseChoice == 2)
					(database + i)->exerciseBracket = exerciseChoice;
				else if (exerciseChoice == 3)
					(database + i)->exerciseBracket = exerciseChoice;
				else if (exerciseChoice == 4)
					(database + i)->exerciseBracket = exerciseChoice;

				printf("How Many Units of Alcohol do You Consume per Week");
				printf("\n1: 0	2:	<2	3: <4	4: >4\n");
				scanf("%d", &alcoholChoice);

				if (alcoholChoice == 1)
					(database + i)->alcoholBracket = alcoholChoice;
				else if (alcoholChoice == 2)
					(database + i)->alcoholBracket = alcoholChoice;
				else if (alcoholChoice == 3)
					(database + i)->alcoholBracket = alcoholChoice;
				else if (alcoholChoice == 4)
					(database + i)->alcoholBracket = alcoholChoice;

				printf("How Many Cigerettes do you Smoke per Week?:");
				printf("\n1: 0 2: <20	3: <40	4: >40\n");
				scanf("%d", &cigerettesChoice);

				if (cigerettesChoice == 1)
					(database + i)->cigarettesBracket = cigerettesChoice;
				else if (cigerettesChoice == 2)
					(database + i)->cigarettesBracket = cigerettesChoice;
				else if (cigerettesChoice == 3)
					(database + i)->cigarettesBracket = cigerettesChoice;
				else if (cigerettesChoice == 4)
					(database + i)->cigarettesBracket = cigerettesChoice;

				// Set i to size so that the loop finished
				i = size;
			}

			// If no empty element found and at the last element of the array 
			//  then the survey is not in the database
			else if (i == size - 1)
			{
				printf("This survey is not in the database\n");
			}
		}
	} // if

	else if (choice == 2)
	{
		printf("\nPlease Enter First Name of Survey You Want to View: ");
		scanf("%s", searchFirst);
		printf("Please Enter Second Name of Survey You Want to View: ");
		scanf("%s", searchSecond);

		// Loop Thorugh Array to Find Survey Details
		for (i = 0; i < size; i++)
		{
			// If Found, Display the Survey Details
			if (strcmp((database + i)->firstName, searchFirst) == 0 && (strcmp((database + i)->secondName, searchSecond) == 0))
			{
				// Ask for and store the new details
				printf("\nPlease Enter Your Updated PPS Number: ");
				scanf("%d", &(database + i)->ppsNo);
				printf("Please Enter the Updated First Name: ");
				scanf("%s", (database + i)->firstName);
				printf("Please Enter the Updated Second Name: ");
				scanf("%s", (database + i)->secondName);
				printf("Please Enter Your Updated Address: ");
				scanf("%s", (database + i)->address);
				printf("Please Enter Your Updated Email Address: ");
				scanf("%s", (database + i)->email);

				printf("Please Enter the Age Bracket Your in:");
				printf("\n1: 18-20	2: 20-30	3: 30-50	4: 50-65	5: 65+\n");
				scanf("%d", &ageChoice);

				if (ageChoice == 1)
					(database + i)->ageBracket = ageChoice;
				else if (ageChoice == 2)
					(database + i)->ageBracket = ageChoice;
				else if (ageChoice == 3)
					(database + i)->ageBracket = ageChoice;
				else if (ageChoice == 4)
					(database + i)->ageBracket = ageChoice;
				else if (ageChoice == 5)
					(database + i)->ageBracket = ageChoice;

				printf("Please Enter the Income Bracket Your in:");
				printf("\n1: No Income	2: <20,000	3: <40,000	4: <60,000	5: <80,000	6: <100,000	7: >100,000\n");
				scanf("%d", &incomeChoice);

				if (incomeChoice == 1)
					(database + i)->incomeBracket = incomeChoice;
				else if (incomeChoice == 2)
					(database + i)->incomeBracket = incomeChoice;
				else if (incomeChoice == 3)
					(database + i)->incomeBracket = incomeChoice;
				else if (incomeChoice == 4)
					(database + i)->incomeBracket = incomeChoice;
				else if (incomeChoice == 5)
					(database + i)->incomeBracket = incomeChoice;
				else if (incomeChoice == 6)
					(database + i)->incomeBracket = incomeChoice;
				else if (incomeChoice == 7)
					(database + i)->incomeBracket = incomeChoice;

				printf("How Often Do You Exercise per Week?:");
				printf("\n1: Never 2: <3 3: <5 4: >5\n");
				scanf("%d", &exerciseChoice);

				if (exerciseChoice == 1)
					(database + i)->exerciseBracket = exerciseChoice;
				else if (exerciseChoice == 2)
					(database + i)->exerciseBracket = exerciseChoice;
				else if (exerciseChoice == 3)
					(database + i)->exerciseBracket = exerciseChoice;
				else if (exerciseChoice == 4)
					(database + i)->exerciseBracket = exerciseChoice;

				printf("How Many Units of Alcohol do You Consume per Week");
				printf("\n1: 0	2:	<2	3: <4	4: >4\n");
				scanf("%d", &alcoholChoice);

				if (alcoholChoice == 1)
					(database + i)->alcoholBracket = alcoholChoice;
				else if (alcoholChoice == 2)
					(database + i)->alcoholBracket = alcoholChoice;
				else if (alcoholChoice == 3)
					(database + i)->alcoholBracket = alcoholChoice;
				else if (alcoholChoice == 4)
					(database + i)->alcoholBracket = alcoholChoice;

				printf("How Many Cigerettes do you Smoke per Week?:");
				printf("\n1: 0 2: <20	3: <40	4: >40\n");
				scanf("%d", &cigerettesChoice);

				if (cigerettesChoice == 1)
					(database + i)->cigarettesBracket = cigerettesChoice;
				else if (cigerettesChoice == 2)
					(database + i)->cigarettesBracket = cigerettesChoice;
				else if (cigerettesChoice == 3)
					(database + i)->cigarettesBracket = cigerettesChoice;
				else if (cigerettesChoice == 4)
					(database + i)->cigarettesBracket = cigerettesChoice;

				// Set i = 1 to Show Loop is Finsished
				i = size;
			} // if

			  // If Not Found the Survey is Not in the Array
			else if (i == size - 1)
			{
				printf("\nThis Survey is NOT in the Database!!\n");
			} //else if

		} // for
	}
}// End updateSurvey


void deleteSurvey(survey_t* database, int size) {

	int search, i;
	int location;
	int found;

	printf("\nEnter PSS Number of the Survey you want to delete: ");
	scanf("%d", &search);

	for (i = 0; i <= size; i++)
	{
		if ((database + i)->ppsNo == search) // looking through the array for the PPS
		{
			location = i;
			found = 1;
			i = size;
		}
		else if (i == size - 1)
			printf("/nThis Survey is not in the Database\n");

	} // end for

	if (found == 1)
	{
		for (i = location; i < size - 1; i++)
		{
			(database + i)->ppsNo = (database + i + 1)->ppsNo; // move all survey numbers back one place in the array
		}

		(database + size - 1)->ppsNo = 0; // make last place in array = 0
		printf("The Survey was Deleted\n");
	}

} // deleteSurvey


void generateStats(survey_t* database, int size) {

	
} // generateSurvey

void printFile(survey_t* database, int size) {

	FILE* out;

	// Open the file
	out = fopen("Survey Details File.txt", "a+"); // open file

	int i;

	for (i = 0; i < size; i++) // Loop Through Array
	{
		if (out != NULL)
		{
			if ((database + i)->ppsNo != 0) // Only Print Elements with Details Entered (ppsNo not = 0)
			{
				fprintf(out, "PPS Number: %d\n", (database + i)->ppsNo); // fprintf to print line to the out file
				fprintf(out, "First Name: %s\n", (database + i)->firstName);
				fprintf(out, "Second Name: %s\n", (database + i)->secondName);
				fprintf(out, "Address: %s\n", (database + i)->address);
				fprintf(out, "E-mail Address: %s\n", (database + i)->email);
			}

			switch ((database + i)->ageBracket) {
			case 1:
				fprintf(out, "Age Bracket: 18-20\n");
				break;
			case 2:
				fprintf(out, "Age Bracket: 20-30\n");
				break;
			case 3:
				fprintf(out, "Age Bracket: 30-50\n");
				break;
			case 4:
				fprintf(out, "Age Bracket: 50-65\n");
				break;
			case 5:
				fprintf(out, "Age Bracket: 65+\n");
				break;
			}

			switch ((database + i)->incomeBracket) {
			case 1:
				fprintf(out, "Income Bracket: No Income\n");
				break;
			case 2:
				fprintf(out, "Income Bracket: <20,000\n");
				break;
			case 3:
				fprintf(out, "Income Bracket: <40,000\n");
				break;
			case 4:
				fprintf(out, "Income Bracket: <60,000\n");
				break;
			case 5:
				fprintf(out, "Income Bracket: <80,000\n");
				break;
			case 6:
				fprintf(out, "Income Bracket: <100,000\n");
				break;
			case 7:
				fprintf(out, "Income Bracket: >100,000\n");
				break;
			}

			switch ((database + i)->exerciseBracket) {
			case 1:
				fprintf(out, "Exercise Bracket: Never\n");
				break;
			case 2:
				fprintf(out, "Exercise Bracket: <3 Times per Week\n");
				break;
			case 3:
				fprintf(out, "Exercise Bracket: <5 Times per Week\n");
				break;
			case 4:
				fprintf(out, "Exercise Bracket: >5 Times per Week\n");
				break;
			}

			switch ((database + i)->alcoholBracket) {
			case 1:
				fprintf(out, "Alcohol Bracket: 0 Units\n");
				break;
			case 2:
				fprintf(out, "Alcohol Bracket: <2 Units\n");
				break;
			case 3:
				fprintf(out, "Alcohol Bracket: <4 Units\n");
				break; 
			case 4:
				fprintf(out, "Alcohol Bracket: >4 Units\n");
				break;
			}

			switch ((database + i)->cigarettesBracket) {
			case 1:
				fprintf(out, "Cigerettes Bracket: 0\n");
				break;
			case 2:
				fprintf(out, "Cigerettes Bracket: <20\n");
				break;
			case 3:
				fprintf(out, "Cigerettes Bracket: <40\n");
				break;
			case 4:
				fprintf(out, "Cigerettes Bracket: >40\n");
				break;
			}

			fprintf(out, "\n");
		}
	}

	printf("\nSurveys Printed to Survey Details File\n");

	// If file is open then close it
	if (out != NULL)
		fclose(out);

} // printFile
