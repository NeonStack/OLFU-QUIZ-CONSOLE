
	/*                                                                                                                                                                                                                                         
	ooooooooooooo oooooooooooo   .oooooo.   ooooo   ooooo ooooo      ooo   .oooooo.     .oooooo.   ooooooooo.   oooooooooooo oooooo   oooooo     oooo 
	8'   888   `8 `888'     `8  d8P'  `Y8b  `888'   `888' `888b.     `8'  d8P'  `Y8b   d8P'  `Y8b  `888   `Y88. `888'     `8  `888.    `888.     .8'  
	     888       888         888           888     888   8 `88b.    8  888      888 888           888   .d88'  888           `888.   .8888.   .8'   
	     888       888oooo8    888           888ooooo888   8   `88b.  8  888      888 888           888ooo88P'   888oooo8       `888  .8'`888. .8'    
	     888       888    "    888           888     888   8     `88b.8  888      888 888           888`88b.     888    "        `888.8'  `888.8'     
	     888       888       o `88b    ooo   888     888   8       `888  `88b    d88' `88b    ooo   888  `88b.   888       o      `888'    `888'      
	    o888o     o888ooooood8  `Y8bood8P'  o888o   o888o o8o        `8   `Y8bood8P'   `Y8bood8P'  o888o  o888o o888ooooood8       `8'      `8'  
		

		 TEAM LEADER: 
        • RICARDO LANCE VIDALLON
        - Coordinated the project, managed team meetings, and facilitated communication among team members.
        ------------------------
        TECHNICAL LEADER: 
        • PRINCESS HANE POLLEROS
        - Screen recorded meetings and development coding sessions, ensuring that the meetings were stable and free from technical issues.
        ------------------------
        LEAD DEVELOPER:
        • JOHN LLOYD UMANI
        - Developed the entire application, implemented all features and functionalities, including animations, transitions, and dynamic responses.
        ------------------------
        OTHER DEVELOPER:
        • KARL JUSTINE ESPEDIDO
        - Assisted with development tasks, contributed to code review, and provided support throughout the development process.
        ------------------------
        UX DESIGNER: 
        • DARWIN MARTIZANO
        - Provided initial user experience design concepts.
        ------------------------
        UI DESIGNER: 
        • PATRICIA AVILA
        - Contributed to the visual design elements.
        ------------------------
        QA LEAD: 
        • DENNIS JUSTINE TABOR
        - Ensured quality and testing of the application
	*/

	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	#include <unistd.h>
	#include <string.h>
	#include <windows.h>
	#include <conio.h>
		
	void loadingbar();
	void title_transition();
	void display_easy();
	void display_medium();
	void display_hard();
	void accounts_reader();
	void number_of_accounts_reader();	//reads the number of accounts in the file and stores it inside int account_count
	void number_of_accounts_add();	//adds int account_count if registered successfully
	void account_login_checker();	//checks if the login is correct
	void account_typer();		//types the current username and pin inside the file
	
	void ranks_data_reader();	//reads the data from a file and stores it in their respective variables
	void ranks_setter();		//sets the rank after the quiz
	void ranks_typer();			//it helps the function rank_setter to type the ranks inside the file
	
	void INPR_easy();
	void INPR_medium();
	void INPR_hard();
	
	void DLOG_easy();
	void DLOG_medium();
	void DLOG_hard();
	
	void WEBDEV_easy();
	void WEBDEV_medium();
	void WEBDEV_hard();
	
	FILE *fp;
	HANDLE TechnocrewConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int current_score = 0;		//stores the current score
	char orders[10];			//stores the variable "random_number" in array
	int random_number;			//stores random number
	char users_answer[100];		//stores the answer of the current user
	char linereader [1024];		//for fgets to read a line and discard afterwards
	char username [15];				//username of the current player
	int current_pin;			//stores the current pin entered by the users
	int length;					//length of the username
	char choice_subject [10];			//stores the subject choice
	int choice_log_reg;			//stores the number if the user chose login 1 or register 2
	int account_count;			//stores the number of accounts registered
	char special_choice_tryagain [4];	//stores the choice if the user wants to try again to login
	int tryagain = 1;	//1 means yes, 0 means no
	
	struct account_infos{
		char account_username [15];
		int account_pin;
	};
	
		//stores personal information including username and pin
		struct account_infos account_info[30];
	
	struct inpr_ranks{
		char inpr_username[15];
		int inpr_score;
	};
	
	struct dlog_ranks{
		char dlog_username[15];
		int dlog_score;
	};
	
	struct webdev_ranks{
		char webdev_username[15];
		int webdev_score;
	};
		
		//stores information about top players on INPR
		struct inpr_ranks inpr_top1;
		struct inpr_ranks inpr_top2;
		struct inpr_ranks inpr_top3;
		struct inpr_ranks inpr_top4;
		struct inpr_ranks inpr_top5;
		
		//stores information about top players on DLOG
		struct dlog_ranks dlog_top1;
		struct dlog_ranks dlog_top2;
		struct dlog_ranks dlog_top3;
		struct dlog_ranks dlog_top4;
		struct dlog_ranks dlog_top5;
		
		//stores information about top players on WEBDEV
		struct webdev_ranks webdev_top1;
		struct webdev_ranks webdev_top2;
		struct webdev_ranks webdev_top3;
		struct webdev_ranks webdev_top4;
		struct webdev_ranks webdev_top5;
	
	int main (){
		
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO OUR LADY OF FATIMA UNIVERSITY QUIZ | Powered by: TECHNOCREW\n\n");
		printf ("\t\t\t\t\t\t\t\t   Please enter any key to continue...\n\n\n");
    	SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	 	printf("\t     .d88888b.  888      8888888888 888     888      .d88888b.  888     888 8888888 8888888888P      .d8888b.         d8888 888b     d888 8888888888 \n");
	    printf("\t    d88Y\" \"Y88b 888      888        888     888     d88P\" \"Y88b 888     888   888         d88P      d88P  Y88b       d88888 8888b   d8888 888        \n");
	    printf("\t    888     888 888      888        888     888     888     888 888     888   888        d88P       888    888      d88P888 88888b.d88888 888        \n");
	    printf("\t    888     888 888      8888888    888     888     888     888 888     888   888       d88P        888            d88P 888 888Y88888P888 8888888    \n");
	    printf("\t    888     888 888      888        888     888     888     888 888     888   888      d88P         888  88888    d88P  888 888 Y888P 888 888        \n");
	    printf("\t    888     888 888      888        888     888     888     888 888     888   888     d88P          888    888   d88P   888 888  Y8P  888 888        \n");
	    printf("\t    Y88b. .d88P 888      888        Y88b. .d88P     Y88b.Y8b88P Y88b. .d88P   888    d88P           Y88b  d88P  d8888888888 888   \"   888 888        \n");
	    printf("\t     \"Y88888P\"  88888888 888         \"Y88888P\"       \"Y888888\"   \"Y88888P\"  8888888 d8888888888      \"Y8888P8  d88P     888 888       888 8888888888 \n");
	    printf("\t                                                         Y8b                                                                                        ");
		SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		_getch();
		title_transition();
		
		while (tryagain == 1){
			beginning:
			tryagain = 1;	
			int choice_menu = 0;	//stores the menu number
			system ("color 2f");
			//READS DATA IN THE FILE AND PUTS INSIDE THEIR RESPECTIVE VARIABLES-------------------------------------------
			number_of_accounts_reader();
			ranks_data_reader();
			accounts_reader();
			//END OF READING THE DATA-------------------------------------------------------------------------------------
			
			//MENU
			system ("cls");
			printf (" \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t======================");
			printf ("\n     \t\t\t\t\t\t\t\t\t    OLFU QUIZ MENU: ");
			printf ("\n \t\t\t\t\t\t\t\t\t======================");
			printf ("\n\n \t\t\t\t\t\t\t\t\t1. Start the Game");
			printf ("\n \t\t\t\t\t\t\t\t\t2. See the Rankings");
			printf ("\n \t\t\t\t\t\t\t\t\t3. Quit");
			printf ("\n\n\t\t\t\t\t\t\t\t\t______________________");
			printf ("\n\n \t\t\t\t\t\t\t\t\tChoice: ");
			scanf ("%d", &choice_menu);
			fflush (stdin);
		
			if (choice_menu == 1){
					//NEWwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
				while (tryagain == 1){
						system ("cls");
						system ("color 2f");
						tryagain = 0;
						choice_log_reg = 0;
						system ("cls");
						printf (" \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t=====================================\n");
						printf (" \t\t\t\t\t\t\t\t  ACCOUNT LOGIN & REGISTRATION MENU\n");
						printf (" \t\t\t\t\t\t\t\t=====================================\n\n");
						printf (" \t\t\t\t\t\t\t\t      1. Log in to your account\n");
						printf (" \t\t\t\t\t\t\t\t      2. Register a new account\n");
						printf (" \t\t\t\t\t\t\t\t      3. Go back\n\n");
						printf (" \t\t\t\t\t\t\t\t      _________________________\n\n");
						printf (" \t\t\t\t\t\t\t\t      Enter: ");
						scanf ("%d", &choice_log_reg);
						fflush (stdin);
						
						//LOG IN
						if (choice_log_reg == 1){
							tryagain = 1;
							while (tryagain == 1){
								system ("cls");
								system ("color 2f");
								//resets the username and pin----------------------------------
								memset (username, '\0', sizeof(username));
								current_pin = 0;
								fflush (stdin);
								printf (" \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t=====================================\n");							
								printf ("\t\t\t\t\t\t\t\t         LOG IN TO YOUR ACCOUNT\n");
								printf (" \t\t\t\t\t\t\t\t=====================================\n\n");
								printf ("\n\t\t\t\t\t\t\t\tEnter your username: ");
								scanf ("%15[^\n]", username);
								fflush (stdin);
								username[strcspn(username, "\n")]='\0';
								
								printf ("\n\t\t\t\t\t\t\t\tEnter your PIN: ");
								scanf ("%d", &current_pin);
								account_login_checker();
								
								if (tryagain == 1) {
									while (tryagain == 1){
										system ("cls");
										system ("color 4f");
										printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tThe provided username or PIN is incorrect.\n\n");
										printf ("\t\t\t\t\t\t\t\t___________________________________________\n\n");
										printf ("\t\t\t\t\t\t\t\tDo you want to try again? (YES or NO)\n\n");
										fflush (stdin);
										printf ("\t\t\t\t\t\t\t\tEnter: ");
										scanf ("%4[^\n]", special_choice_tryagain);
										fflush (stdin);
										special_choice_tryagain[strcspn(special_choice_tryagain, "\n")]='\0';
										
										if (strcasecmp(special_choice_tryagain, "yes")==0){
											tryagain = 1;
											break;
										}
										
										else if (strcasecmp(special_choice_tryagain, "no")==0){
											goto beginning;
										}
										
										else {
											printf ("\n\t\t\t\t\t\t\t\tPlease put a valid choice");
											sleep (3);
											system ("cls");
											tryagain = 1;
										}
									}
								}
							}
						}
						
						//REGISTER
						else if (choice_log_reg == 2){
							if (account_count < 30){
								tryagain = 1;
								while (tryagain == 1){
									while (tryagain == 1){
										system ("cls");
										system ("color 2f");
										printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t=====================================\n");
										printf ("\t\t\t\t\t\t\t\t\t ACCOUNT REGISTRATION\n");
										printf ("\t\t\t\t\t\t\t\t=====================================\n\n");
										printf ("\t\t\t\t\t\t\t\t NOTE: Maximum of 10 Characters only!\n");
										memset (username, '\0', sizeof(username));
										printf ("\n\n\t\t\t\t\t\t\t\t    CREATE A USERNAME: ");
										scanf ("%15[^\n]", username);
										fflush (stdin);
										username[strcspn(username, "\n")]='\0';
										length = strlen(username);
										
										for (int i=0; i<30; i++){
											if (strcmp(username, account_info[i].account_username)==0){
												system ("color 4f");
												printf ("\n\t\t\t\t\t\t\tUsername entered is already taken. Please try again...");
												tryagain = 1;
												sleep (4);
												break;
											}
											else {
												tryagain = 0;
											}
										}
									}
									
									if (length > 10){
										tryagain = 1;
										system ("color 4f");
										printf ("\n\t\t\t\t\t\t\tYour username is above 10 characters. Please try again...");
										memset (username, '\0', sizeof(username));
										sleep (3);
									}
									
									else if (length <= 10 && length >= 1){
										tryagain = 1;
										while (tryagain == 1){
											fflush(stdin);
											current_pin = 0;
											system ("cls");
											system ("color 2f");
											printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t=====================================\n");
											printf ("\t\t\t\t\t\t\t\t\t ACCOUNT REGISTRATION\n");
											printf ("\t\t\t\t\t\t\t\t=====================================\n\n");
											printf ("\t\t\t\t\t\t\t\t    NOTE: It must not start with 0\n\n");
											printf ("\t\t\t\t\t\t\t\t     CREATE A 4-DIGIT PIN: ");
											scanf ("%d", &current_pin);
											
											if (current_pin >= 1000 && current_pin <= 9999){
												break;
											}
											else {
												system ("color 4f");
											printf ("\n\n\t\t\t\t\t\t\t\t       Please enter a valid PIN");
												current_pin = 0;
												tryagain = 1;
												sleep (3);
											}
											
										}
										account_typer();
										number_of_accounts_add();
										tryagain=0;
										system ("cls");
										printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t=====================================\n");
										printf ("\t\t\t\t\t\t\t\t       SUCCESSFUL REGISTRATION\n");
										printf ("\t\t\t\t\t\t\t\t=====================================\n\n");
										printf ("\n\n\t\t\t\t\t        Hello %s! You have successfully registered your account. Good Luck!", username);
										sleep (5);
									}
								}
							}
							else{
								system ("color 4f");
								printf ("\n\t\t\t\t\t\t\t\tUnfortunately, account registration is full");
								tryagain = 0;
								sleep (3);
								goto beginning;
							}
						}
						
						else if (choice_log_reg == 3){
							goto beginning;
						}
						
						//WRONG CHOICE
						else{
							system ("color 4f");
							printf ("\n\t\t\t\t\t\t\t\t  Invalid choice! Please try again...");
							tryagain = 1;
							sleep (3);
						}
					}
					//END NEWwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
				
				tryagain=1;
				while (tryagain == 1){
					fflush (stdin);
					current_score = 0;
					system ("cls");
					system ("color 2f");
					memset (choice_subject, '\0', sizeof(choice_subject));
					printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t=====================================\n");
					printf ("\t\t\t\t\t\t\t\t            SUBJECT MENU\n");
					printf ("\t\t\t\t\t\t\t\t=====================================\n\n");
					printf ("\n\t\t\t\t\t\t\t Please enter the subject code you want to answer: \n\n");
					printf ("\t\t\t\t\t\t\t 1. Intermediate Programming (Code: INPR)\n\n");
					printf ("\t\t\t\t\t\t\t 2. Digital Logic and Design (Code: DLOG)\n\n");
					printf ("\t\t\t\t\t\t\t 3. Web Development (Code: WEBDEV)\n");
					printf ("\t\t\t\t\t\t\t _________________________________________________\n");
					printf ("\n\t\t\t\t\t\t\t Enter the Code: ");
					fgets (choice_subject, sizeof(choice_subject), stdin);
					fflush (stdin);
					choice_subject[strcspn(choice_subject, "\n")]='\0';
					
					//INPR QUIZ----------------------------------------------------------------------------------------
					if (strcasecmp("INPR", choice_subject)==0){
						system ("cls");
						printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tBE READY FOR THE INPR QUIZ! YOU CAN DO IT %s!\n\n", username);
						printf ("\t\t\t\t\t\t\t\t               PLEASE WAIT...");
						sleep (5);
						system ("cls");
						system("color F1");
						printf ("\n\n");
						display_easy();
						printf ("\n");
						loadingbar();
						system ("cls");
						system("color 1F");
						printf ("\n\t Directions: Enter the letter of the correct answer.\n");
						printf ("\n\n\t EASY DIFFICULTY\n");
						INPR_easy();
						
						system("color F6");
						system ("cls");
						printf ("\n\n");
						display_medium();
						printf ("\n");
						loadingbar();
						system ("cls");
						system("color 6F");
						printf ("\n\t Directions: Enter the letter of the correct answer.\n");
						printf ("\n\n\t MEDIUM DIFFICULTY\n");
						INPR_medium();
						
						system("color F4");
						system ("cls");
						printf ("\n\n");
						display_hard();
						printf ("\n");
						loadingbar();
						system ("cls");
						system("color 4F");
						printf ("\n\t Directions: Enter the letter of the correct answer.\n");
						printf ("\n\n\t HARD DIFFICULTY\n");
						INPR_hard();
						
						system ("cls");
						system ("color 2f");
						printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t You scored %d out of 250\n\n", current_score);
						ranks_setter();
						printf ("\n\n\t\t\t\t\t\t\t ***** INPR QUIZ - TOP 5 PLAYERS OF ALL TIME *****\n\n");
						printf ("\t\t\t\t\t\t\t TOP 1: %s\n\t\t\t\t\t\t\t Score: %d\n\n", inpr_top1.inpr_username, inpr_top1.inpr_score);
						printf ("\t\t\t\t\t\t\t TOP 2: %s\n\t\t\t\t\t\t\t Score: %d\n\n", inpr_top2.inpr_username, inpr_top2.inpr_score);
						printf ("\t\t\t\t\t\t\t TOP 3: %s\n\t\t\t\t\t\t\t Score: %d\n\n", inpr_top3.inpr_username, inpr_top3.inpr_score);
						printf ("\t\t\t\t\t\t\t TOP 4: %s\n\t\t\t\t\t\t\t Score: %d\n\n", inpr_top4.inpr_username, inpr_top4.inpr_score);
						printf ("\t\t\t\t\t\t\t TOP 5: %s\n\t\t\t\t\t\t\t Score: %d\n\n", inpr_top5.inpr_username, inpr_top5.inpr_score);
						printf ("\t\t\t\t\t\t\t ---------------------------------------------------\n\n");
						printf ("\t\t\t\t\t\t\t Enter any key to continue: ");
						scanf ("%*s");
						
						while (tryagain == 1){
							system ("cls");
							system ("color 2f");
							choice_menu = 0;
							printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t=====================================\n");
							printf ("\t\t\t\t\t\t\t\t          CHOOSE AN OPTION:\n");
							printf ("\t\t\t\t\t\t\t\t=====================================\n\n");
							printf ("\t\t\t\t\t\t\t\t 1. Go to Menu\n");
							printf ("\t\t\t\t\t\t\t\t 2. Exit\n\n");
							printf ("\t\t\t\t\t\t\t\t_____________________________________\n\n");
							printf ("\t\t\t\t\t\t\t\t Enter: ");
							scanf ("%d", &choice_menu);
							fflush (stdin);
							
							if (choice_menu == 1){
								tryagain = 0;	
							}
							else if (choice_menu == 2){
								system ("cls");
								system ("color 0b");
								printf ("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tThank you for using our program! Have a nice day!....\n\n\n\n\n\n\n\n\n\n\n");
								printf ("\t  ---------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
								printf("\t   ooooooooooooo oooooooooooo   .oooooo.   ooooo   ooooo ooooo      ooo   .oooooo.     .oooooo.   ooooooooo.   oooooooooooo oooooo   oooooo     oooo\n");
							    printf("\t   8'   888   `8 `888'     `8  d8P'  `Y8b  `888'   `888' `888b.     `8'  d8P'  `Y8b   d8P'  `Y8b  `888   `Y88. `888'     `8  `888.    `888.     .8'  \n");
							    printf("\t        888       888         888           888     888   8 `88b.    8  888      888 888           888   .d88'  888           `888.   .8888.   .8'   \n");
							    printf("\t        888       888oooo8    888           888ooooo888   8   `88b.  8  888      888 888           888ooo88P'   888oooo8       `888  .8'`888. .8'    \n");
							    printf("\t        888       888    \"    888           888     888   8     `88b.8  888      888 888           888`88b.     888    \"        `888.8'  `888.8'     \n");
							    printf("\t        888       888       o `88b    ooo   888     888   8       `888  `88b    d88' `88b    ooo   888  `88b.   888       o      `888'    `888'      \n");
							    printf("\t       o888o     o888ooooood8  `Y8bood8P'  o888o   o888o o8o        `8   `Y8bood8P'   `Y8bood8P'  o888o  o888o o888ooooood8       `8'      `8'        \n\n");
								printf ("\t  ---------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				
								return 0;
							}
							else {
								system ("color 4f");
								printf ("\n\t\t\t\t\t\t\t\t   Invalid choice! Please try again");
								tryagain = 1;
								sleep (3);
							}
						}
					}
					
					//DLOG QUIZ----------------------------------------------------------------------------------------
					else if (strcasecmp("DLOG", choice_subject)==0){
						system ("cls");
						printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tBE READY FOR THE DLOG QUIZ! YOU CAN DO IT %s!\n\n", username);
						printf ("\t\t\t\t\t\t\t\t               PLEASE WAIT...");
						sleep (5);
						system ("cls");
						system("color F1");
						printf ("\n\n");
						display_easy();
						printf ("\n");
						loadingbar();
						system ("cls");
						system("color 1F");
						printf ("\n\t Directions: Enter the letter of the correct answer.\n");
						printf ("\n\t EASY DIFFICULTY\n");
						DLOG_easy();
						
						system("color F6");
						system ("cls");
						printf ("\n\n");
						display_medium();
						printf ("\n");
						loadingbar();
						system ("cls");
						system("color 6F");
						printf ("\n\t Directions: Enter the letter of the correct answer.\n");
						printf ("\n\n\t MEDIUM DIFFICULTY\n");
						DLOG_medium();
						
						system("color F4");
						system ("cls");
						printf ("\n\n");
						display_hard();
						printf ("\n");
						loadingbar();
						system ("cls");
						system("color 4F");
						printf ("\n\t Directions: Enter the correct EXACT answer.\n");
						printf ("\n\n\t HARD DIFFICULTY\n");
						DLOG_hard();
						
						system ("cls");
						system ("color 2f");
						printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t You scored %d out of 250\n\n", current_score);
						ranks_setter();
						printf ("\n\n\t\t\t\t\t\t\t ***** DLOG QUIZ - TOP 5 PLAYERS OF ALL TIME *****\n\n");
						printf ("\t\t\t\t\t\t\t TOP 1: %s\n\t\t\t\t\t\t\t Score: %d\n\n", dlog_top1.dlog_username, dlog_top1.dlog_score);
						printf ("\t\t\t\t\t\t\t TOP 2: %s\n\t\t\t\t\t\t\t Score: %d\n\n", dlog_top2.dlog_username, dlog_top2.dlog_score);
						printf ("\t\t\t\t\t\t\t TOP 3: %s\n\t\t\t\t\t\t\t Score: %d\n\n", dlog_top3.dlog_username, dlog_top3.dlog_score);
						printf ("\t\t\t\t\t\t\t TOP 4: %s\n\t\t\t\t\t\t\t Score: %d\n\n", dlog_top4.dlog_username, dlog_top4.dlog_score);
						printf ("\t\t\t\t\t\t\t TOP 5: %s\n\t\t\t\t\t\t\t Score: %d\n\n", dlog_top5.dlog_username, dlog_top5.dlog_score);
						printf ("\t\t\t\t\t\t\t ---------------------------------------------------\n\n");
						printf ("\t\t\t\t\t\t\t Enter any key to continue: ");
						scanf ("%*s");
						
						while (tryagain == 1){
							system ("cls");
							system ("color 2f");
							choice_menu = 0;
							printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t=====================================\n");
							printf ("\t\t\t\t\t\t\t\t          CHOOSE AN OPTION:\n");
							printf ("\t\t\t\t\t\t\t\t=====================================\n\n");
							printf ("\t\t\t\t\t\t\t\t 1. Go to Menu\n");
							printf ("\t\t\t\t\t\t\t\t 2. Exit\n\n");
							printf ("\t\t\t\t\t\t\t\t_____________________________________\n\n");
							printf ("\t\t\t\t\t\t\t\t Enter: ");
							scanf ("%d", &choice_menu);
							fflush (stdin);
							
							if (choice_menu == 1){
								tryagain = 0;	
							}
							else if (choice_menu == 2){
								system ("cls");
								system ("color 0b");
								printf ("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tThank you for using our program! Have a nice day!....\n\n\n\n\n\n\n\n\n\n\n");
								printf ("\t  ---------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
								printf("\t   ooooooooooooo oooooooooooo   .oooooo.   ooooo   ooooo ooooo      ooo   .oooooo.     .oooooo.   ooooooooo.   oooooooooooo oooooo   oooooo     oooo\n");
							    printf("\t   8'   888   `8 `888'     `8  d8P'  `Y8b  `888'   `888' `888b.     `8'  d8P'  `Y8b   d8P'  `Y8b  `888   `Y88. `888'     `8  `888.    `888.     .8'  \n");
							    printf("\t        888       888         888           888     888   8 `88b.    8  888      888 888           888   .d88'  888           `888.   .8888.   .8'   \n");
							    printf("\t        888       888oooo8    888           888ooooo888   8   `88b.  8  888      888 888           888ooo88P'   888oooo8       `888  .8'`888. .8'    \n");
							    printf("\t        888       888    \"    888           888     888   8     `88b.8  888      888 888           888`88b.     888    \"        `888.8'  `888.8'     \n");
							    printf("\t        888       888       o `88b    ooo   888     888   8       `888  `88b    d88' `88b    ooo   888  `88b.   888       o      `888'    `888'      \n");
							    printf("\t       o888o     o888ooooood8  `Y8bood8P'  o888o   o888o o8o        `8   `Y8bood8P'   `Y8bood8P'  o888o  o888o o888ooooood8       `8'      `8'        \n\n");
								printf ("\t  ---------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				
								return 0;
							}
							else {
								system ("color 4f");
								printf ("\n\t\t\t\t\t\t\t\t   Invalid choice! Please try again");
								tryagain = 1;
								sleep (3);
							}
						}
					}
					
					//WEBDEV QUIZ----------------------------------------------------------------------------------------
					else if (strcasecmp("WEBDEV", choice_subject)==0){
						system ("cls");
						printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tBE READY FOR THE WEBDEV QUIZ! YOU CAN DO IT %s!\n\n", username);
						printf ("\t\t\t\t\t\t\t\t               PLEASE WAIT...");
						sleep (5);
						system ("cls");
						system("color F1");
						printf ("\n\n");
						display_easy();
						printf ("\n");
						loadingbar();
						system ("cls");
						system("color 1F");
						printf ("\n\t Directions: Enter the letter of the correct answer.\n");
						printf ("\n\n\t EASY DIFFICULTY\n");
						WEBDEV_easy();
						
						system("color F6");
						system ("cls");
						printf ("\n\n");
						display_medium();
						printf ("\n");
						loadingbar();
						system ("cls");
						system("color 6F");
						printf ("\n\t Directions: Enter the letter of the correct answer.\n");
						printf ("\n\n\t MEDIUM DIFFICULTY\n");
						WEBDEV_medium();
						
						system("color F4");
						system ("cls");
						printf ("\n\n");
						display_hard();
						printf ("\n");
						loadingbar();
						system ("cls");
						system("color 4F");
						printf ("\n\t Directions: Enter the letter of the correct answer.\n");
						printf ("\n\n\t HARD DIFFICULTY\n");
						WEBDEV_hard();
						
						system ("cls");
						system ("color 2f");
						printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t You scored %d out of 250\n\n", current_score);
						ranks_setter();
						printf ("\n\n\t\t\t\t\t\t\t ***** WEBDEV QUIZ - TOP 5 PLAYERS OF ALL TIME *****\n\n");
						printf ("\t\t\t\t\t\t\t TOP 1: %s\n\t\t\t\t\t\t\t Score: %d\n\n", webdev_top1.webdev_username, webdev_top1.webdev_score);
						printf ("\t\t\t\t\t\t\t TOP 2: %s\n\t\t\t\t\t\t\t Score: %d\n\n", webdev_top2.webdev_username, webdev_top2.webdev_score);
						printf ("\t\t\t\t\t\t\t TOP 3: %s\n\t\t\t\t\t\t\t Score: %d\n\n", webdev_top3.webdev_username, webdev_top3.webdev_score);
						printf ("\t\t\t\t\t\t\t TOP 4: %s\n\t\t\t\t\t\t\t Score: %d\n\n", webdev_top4.webdev_username, webdev_top4.webdev_score);							
						printf ("\t\t\t\t\t\t\t TOP 5: %s\n\t\t\t\t\t\t\t Score: %d\n\n", webdev_top5.webdev_username, webdev_top5.webdev_score);
						printf ("\t\t\t\t\t\t\t ---------------------------------------------------\n\n");
						printf ("\t\t\t\t\t\t\t Enter any key to continue: ");
						scanf ("%*s");
						
						while (tryagain == 1){
							system ("cls");
							system ("color 2f");
							choice_menu = 0;
							printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t=====================================\n");
							printf ("\t\t\t\t\t\t\t\t          CHOOSE AN OPTION:\n");
							printf ("\t\t\t\t\t\t\t\t=====================================\n\n");
							printf ("\t\t\t\t\t\t\t\t 1. Go to Menu\n");
							printf ("\t\t\t\t\t\t\t\t 2. Exit\n\n");
							printf ("\t\t\t\t\t\t\t\t_____________________________________\n\n");
							printf ("\t\t\t\t\t\t\t\t Enter: ");
							scanf ("%d", &choice_menu);
							fflush (stdin);
							
							if (choice_menu == 1){
								tryagain = 0;	
							}
							else if (choice_menu == 2){
								system ("cls");
								system ("color 0b");
								printf ("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tThank you for using our program! Have a nice day!....\n\n\n\n\n\n\n\n\n\n\n");
								printf ("\t  ---------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
								printf("\t   ooooooooooooo oooooooooooo   .oooooo.   ooooo   ooooo ooooo      ooo   .oooooo.     .oooooo.   ooooooooo.   oooooooooooo oooooo   oooooo     oooo\n");
							    printf("\t   8'   888   `8 `888'     `8  d8P'  `Y8b  `888'   `888' `888b.     `8'  d8P'  `Y8b   d8P'  `Y8b  `888   `Y88. `888'     `8  `888.    `888.     .8'  \n");
							    printf("\t        888       888         888           888     888   8 `88b.    8  888      888 888           888   .d88'  888           `888.   .8888.   .8'   \n");
							    printf("\t        888       888oooo8    888           888ooooo888   8   `88b.  8  888      888 888           888ooo88P'   888oooo8       `888  .8'`888. .8'    \n");
							    printf("\t        888       888    \"    888           888     888   8     `88b.8  888      888 888           888`88b.     888    \"        `888.8'  `888.8'     \n");
							    printf("\t        888       888       o `88b    ooo   888     888   8       `888  `88b    d88' `88b    ooo   888  `88b.   888       o      `888'    `888'      \n");
							    printf("\t       o888o     o888ooooood8  `Y8bood8P'  o888o   o888o o8o        `8   `Y8bood8P'   `Y8bood8P'  o888o  o888o o888ooooood8       `8'      `8'        \n\n");
								printf ("\t  ---------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				
								return 0;
							}
							else {
								system ("color 4f");
								printf ("\n\t\t\t\t\t\t\t\t   Invalid choice! Please try again");
								tryagain = 1;
								sleep (3);
							}
						}
					}
					
					else {
						system ("color 4f");
						tryagain = 1;
						printf ("\n\t\t\t\t\t\t\t     You entered a wrong code! Please Try Again");
						sleep (3);
					}
				}
				tryagain = 1;
			}
			
			else if (choice_menu == 2){
				system ("cls");
				ranks_data_reader();
				system ("color 2f");
				printf ("\n\t\t\t\t\t\t\t ***** INPR QUIZ - TOP 5 PLAYERS OF ALL TIME *****\n\n");
				printf ("\t\t\t\t\t\t\t TOP 1: %s\n\t\t\t\t\t\t\t Score: %d\n\n", inpr_top1.inpr_username, inpr_top1.inpr_score);
				printf ("\t\t\t\t\t\t\t TOP 2: %s\n\t\t\t\t\t\t\t Score: %d\n\n", inpr_top2.inpr_username, inpr_top2.inpr_score);
				printf ("\t\t\t\t\t\t\t TOP 3: %s\n\t\t\t\t\t\t\t Score: %d\n\n", inpr_top3.inpr_username, inpr_top3.inpr_score);
				printf ("\t\t\t\t\t\t\t TOP 4: %s\n\t\t\t\t\t\t\t Score: %d\n\n", inpr_top4.inpr_username, inpr_top4.inpr_score);
				printf ("\t\t\t\t\t\t\t TOP 5: %s\n\t\t\t\t\t\t\t Score: %d\n\n", inpr_top5.inpr_username, inpr_top5.inpr_score);
				printf ("\t\t\t\t\t\t\t ---------------------------------------------------\n");
				printf ("\t\t\t\t\t\t\t ***** DLOG QUIZ - TOP 5 PLAYERS OF ALL TIME *****\n\n");
				printf ("\t\t\t\t\t\t\t TOP 1: %s\n\t\t\t\t\t\t\t Score: %d\n\n", dlog_top1.dlog_username, dlog_top1.dlog_score);
				printf ("\t\t\t\t\t\t\t TOP 2: %s\n\t\t\t\t\t\t\t Score: %d\n\n", dlog_top2.dlog_username, dlog_top2.dlog_score);
				printf ("\t\t\t\t\t\t\t TOP 3: %s\n\t\t\t\t\t\t\t Score: %d\n\n", dlog_top3.dlog_username, dlog_top3.dlog_score);
				printf ("\t\t\t\t\t\t\t TOP 4: %s\n\t\t\t\t\t\t\t Score: %d\n\n", dlog_top4.dlog_username, dlog_top4.dlog_score);
				printf ("\t\t\t\t\t\t\t TOP 5: %s\n\t\t\t\t\t\t\t Score: %d\n\n", dlog_top5.dlog_username, dlog_top5.dlog_score);
				printf ("\t\t\t\t\t\t\t ---------------------------------------------------\n");
				printf ("\t\t\t\t\t\t\t ***** WEBDEV QUIZ - TOP 5 PLAYERS OF ALL TIME *****\n\n");
				printf ("\t\t\t\t\t\t\t TOP 1: %s\n\t\t\t\t\t\t\t Score: %d\n\n", webdev_top1.webdev_username, webdev_top1.webdev_score);
				printf ("\t\t\t\t\t\t\t TOP 2: %s\n\t\t\t\t\t\t\t Score: %d\n\n", webdev_top2.webdev_username, webdev_top2.webdev_score);
				printf ("\t\t\t\t\t\t\t TOP 3: %s\n\t\t\t\t\t\t\t Score: %d\n\n", webdev_top3.webdev_username, webdev_top3.webdev_score);
				printf ("\t\t\t\t\t\t\t TOP 4: %s\n\t\t\t\t\t\t\t Score: %d\n\n", webdev_top4.webdev_username, webdev_top4.webdev_score);
				printf ("\t\t\t\t\t\t\t TOP 5: %s\n\t\t\t\t\t\t\t Score: %d\n\n", webdev_top5.webdev_username, webdev_top5.webdev_score);
				
				printf ("\t\t\t\t\t\t\t Press any key to go back...");
				_getch();
				tryagain = 1;
			}
			
			else if (choice_menu == 3){
				system ("cls");
				system ("color 0b");
				printf ("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tThank you for using our program! Have a nice day!....\n\n\n\n\n\n\n\n\n\n\n");
				printf ("\t  ---------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
				printf("\t   ooooooooooooo oooooooooooo   .oooooo.   ooooo   ooooo ooooo      ooo   .oooooo.     .oooooo.   ooooooooo.   oooooooooooo oooooo   oooooo     oooo\n");
			    printf("\t   8'   888   `8 `888'     `8  d8P'  `Y8b  `888'   `888' `888b.     `8'  d8P'  `Y8b   d8P'  `Y8b  `888   `Y88. `888'     `8  `888.    `888.     .8'  \n");
			    printf("\t        888       888         888           888     888   8 `88b.    8  888      888 888           888   .d88'  888           `888.   .8888.   .8'   \n");
			    printf("\t        888       888oooo8    888           888ooooo888   8   `88b.  8  888      888 888           888ooo88P'   888oooo8       `888  .8'`888. .8'    \n");
			    printf("\t        888       888    \"    888           888     888   8     `88b.8  888      888 888           888`88b.     888    \"        `888.8'  `888.8'     \n");
			    printf("\t        888       888       o `88b    ooo   888     888   8       `888  `88b    d88' `88b    ooo   888  `88b.   888       o      `888'    `888'      \n");
			    printf("\t       o888o     o888ooooood8  `Y8bood8P'  o888o   o888o o8o        `8   `Y8bood8P'   `Y8bood8P'  o888o  o888o o888ooooood8       `8'      `8'        \n\n");
				printf ("\t  ---------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

				return 0;
			}
			
			else {
				system ("color 4f");
				printf ("\n\t\t\t\t\t\t\t\t       Please Enter a Valid Choice");
				choice_menu = 0;
				sleep (3);
			}
		}
	}
	
	
	
	//QUESTIONSSSSSSSSSSSSSSS
	
	
	
	//INPR QUESTIONS----------------------------------------------------------------------------------------------
	void INPR_easy(){
		srand(time(0));
		for (int i = 0; i < 10; i++){
			random_number = rand() % 10 + 1;
			while (
			orders[0] == random_number ||
			orders[1] == random_number ||
			orders[2] == random_number ||
			orders[3] == random_number ||
			orders[4] == random_number ||
			orders[5] == random_number ||
			orders[6] == random_number ||
			orders[7] == random_number ||
			orders[8] == random_number ||
			orders[9] == random_number ||
			orders[10] == random_number
			){
				random_number = rand() % 10 + 1;
			}
			orders [i] = random_number;
		}
		
		for (int i = 0; i < 10; i++){
			printf ("\n\t %d. ", i+1);
			if (orders [i] == 1){
				printf (" Who Invented C Language?\n");
				printf ("\t\tA. Ronald D. Chamberlin\n\t\tB. James Gosling\n\t\tC. Guido Van Rossum\n\t\tD. Dennis M. Ritchie");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("D", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 2){
				printf ("The Header file stdio.h stands for?\n");
				printf ("\t\tA. Standard input and output\n\t\tB. main ()\n\t\tC. scanf\n\t\tD. return 0");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 3){
				printf ("What is the name of one of the main C output functions that stands for \"print formatted\"?\n");
				printf ("\t\tA. scanf\n\t\tB. fputw()\n\t\tC. printf\n\t\tD. fputc()");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("C", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 4){
				printf ("It allows you to read input from the user or from a file and store that input in variables of different data types\n");
				printf ("\t\tA. scanf\n\t\tB. printf\n\t\tC. pointer\n\t\tD. fputc()");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 5){
				printf ("The keyword used to transfer control from a function back to the calling function is?\n");
				printf ("\t\tA. arrays\n\t\tB. conio.h\n\t\tC. stdio.h\n\t\tD. return");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("D", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 6){
				printf ("Is the entry point for execution in C program\n");
				printf ("\t\tA. start()\n\t\tB. array()\n\t\tC. main()\n\t\tD. return()");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("C", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 7){
				printf ("It is a variable that stores the memory address of another variable as its value\n");
				printf ("\t\tA. file handling\n\t\tB. void\n\t\tC. arrays\n\t\tD. pointer");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("D", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 8){
				printf ("A 2D array is also known as?\n");
				printf ("\t\tA. void\n\t\tB. matrix\n\t\tC. open a file\n\t\tD. string");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("B", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 9){
				printf ("It is used to include the console input output library functions\n");
				printf ("\t\tA. string.h\n\t\tB. include.h\n\t\tC. math.h\n\t\tD. conio.h");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("D", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 10){
				printf ("It is a variable that can store multiple values\n");
				printf ("\t\tA. arrays\n\t\tB. file handling\n\t\tC. data\n\t\tD. pointer");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
		}
		memset (orders, '\0', sizeof(orders));
	}
	
	void INPR_medium(){
		srand(time(0));
		for (int i = 0; i < 10; i++){
			random_number = rand() % 10 + 1;
			while (
			orders[0] == random_number ||
			orders[1] == random_number ||
			orders[2] == random_number ||
			orders[3] == random_number ||
			orders[4] == random_number ||
			orders[5] == random_number ||
			orders[6] == random_number ||
			orders[7] == random_number ||
			orders[8] == random_number ||
			orders[9] == random_number ||
			orders[10] == random_number
			){
				random_number = rand() % 10 + 1;
			}
			orders [i] = random_number;
		}
		
		for (int i = 0; i < 10; i++){
			printf ("\n\t %d. ", i+1);
			if (orders [i] == 1){
				printf ("The library function used to find the last occurrence of a character in a string is?\n");
				printf ("\t\tA. strrchr()\n\t\tB. fputc()\n\t\tC. fopen()\n\t\tD. fclose()");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 2){
				printf ("Reads a character from a file\n");
				printf ("\t\tA. fgetch()\n\t\tB. fopen()\n\t\tC. nested\n\t\tD. fclose()");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 3){
				printf ("Writes an integer to a file\n");
				printf ("\t\tA. fseek()\n\t\tB. fopen()\n\t\tC. nested\n\t\tD. fputw()");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("D", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 4){
				printf ("It creates a new file or open an existing file\n");
				printf ("\t\tA. fopen()\n\t\tB. fclose()\n\t\tC. fseek()\n\t\tD. fgets()");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 5){
				printf ("It is the method of storing data in the C program in the form of an output or input that might have been generated while running a C program in a data file\n");
				printf ("\t\tA. fputc()\n\t\tB. fseek()\n\t\tC. file handling\n\t\tD. none of the above");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("C", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 6){
				printf ("What is a structure in C language?\n");
				printf ("\t\tA. A structure is a composite data type in C language that groups together variables of different data types under a single name.\n\t\tB. A structure use to read character from another file\n\t\tC. A structure is use to open new or existing file\n\t\tD. none of the above");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 7){
				printf ("Can you pass a structure to a function in C language?\n");
				printf ("\t\tA. Yes\n\t\tB. No\n\t\tC. Maybe\n\t\tD. none of the above");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 8){
				printf ("What is the keyword used to access a member of a structure in C?\n");
				printf ("\t\tA. dot (.) operator\n\t\tB. a+\n\t\tC. ab+\n\t\tD. wb+");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 9){
				printf ("What is the size of a structure in C?\n");
				printf ("\t\tA. The sum of the sizes of its members\n\t\tB. nested structure in C is a function \n\t\tC. nested structure in C is a void\n\t\tD. none of the above");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 10){
				printf ("Can we pass a structure as an argument to a function in C?\n");
				printf ("\t\tA. Yes\n\t\tB. No\n\t\tC. Maybe\n\t\tD. none of the above");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
		}
		memset (orders, '\0', sizeof(orders));
	}
	
	void INPR_hard(){
		srand(time(0));
		for (int i = 0; i < 5; i++){
			random_number = rand() % 5 + 1;
			while (
			orders[0] == random_number ||
			orders[1] == random_number ||
			orders[2] == random_number ||
			orders[3] == random_number ||
			orders[4] == random_number ||
			orders[5] == random_number
			){
				random_number = rand() % 5 + 1;
			}
			orders [i] = random_number;
		}
		
		for (int i = 0; i < 10; i++){
			printf ("\n\t %d. ", i+1);
			if (orders [i] == 1){
				printf ("What is a nested structure in C?\n");
				printf ("\t\tA. nested structure in C is a structure that is a member of another structure\n\t\tB. nested structure in C is use to close a file\n\t\tC. nested structure in C is a function\n\t\tD. nested structure in C is a void");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=20;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 2){
				printf ("How can we declare a pointer to a structure in C?\n");
				printf ("\t\tA. struct structure_name **ptr;\n\t\tB. struct structurename_ *ptr;\n\t\tC. struct structure_name *ptr;\n\t\tD. struct structurename ptr");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("C", users_answer)==0){
					current_score +=20;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 3){
				printf ("How can we dynamically allocate memory for a structure in C?\n");
				printf ("\t\tA. malloc()\n\t\tB. main()\n\t\tC. function\n\t\tD. void");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=20;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 4){
				printf ("What is a typedef in C?\n");
				printf ("\t\tA. A typedef in C is use to return\n\t\tB. A typedef in C is to close a file\n\t\tC. A typedef in C is a keyword used to create a new data type alias for an existing data type, including structures\n\t\tD. A typedef in C is use to open a data file");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("C", users_answer)==0){
					current_score +=20;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 5){
				printf ("Can we have an array of structures in C?\n");
				printf ("\t\tA. Yes\n\t\tB. No\n\t\tC. Maybe\n\t\tD. none of the above");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=20;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
		}
		memset (orders, '\0', sizeof(orders));
	}
	
	
	
	
	//DLOG QUESTIONS------------------------------------------------------------------------------
	
	void DLOG_easy(){
		srand(time(0));
		for (int i = 0; i < 10; i++){
			random_number = rand() % 10 + 1;
			while (
			orders[0] == random_number ||
			orders[1] == random_number ||
			orders[2] == random_number ||
			orders[3] == random_number ||
			orders[4] == random_number ||
			orders[5] == random_number ||
			orders[6] == random_number ||
			orders[7] == random_number ||
			orders[8] == random_number ||
			orders[9] == random_number ||
			orders[10] == random_number
			){
				random_number = rand() % 10 + 1;
			}
			orders [i] = random_number;
		}
		
		for (int i = 0; i < 10; i++){
			printf ("\n\t %d. ", i+1);
			if (orders [i] == 1){
				printf ("Solves problem by using continuously changing data such as temperature pressure voltage.\n");
				printf ("\t\tA. Digital\n\t\tB. Computer\n\t\tC. Analog\n\t\tD. Cellphone");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("C", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 2){
				printf ("Any of the symbols or images utilized in an arrangement of numerical representation dependent on the old Roman system.\n");
				printf ("\t\tA. Roman Numeral\n\t\tB. Indian Numeral\n\t\tC. Arabic Numeral\n\t\tD. Egyptian Numeral");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 3){
				printf ("A system that has the ten as its base.\n");
				printf ("\t\tA. Decimal\n\t\tB. Binary\n\t\tC. Octal\n\t\tD. Hexadecimal");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 4){
				printf ("A system that has the two as its base.\n");
				printf ("\t\tA. Decimal\n\t\tB. Binary\n\t\tC. Octal\n\t\tD. Hexadecimal");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("B", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 5){
				printf ("A system that has the sixteen as its base.\n");
				printf ("\t\tA. Decimal\n\t\tB. Binary\n\t\tC. Octal\n\t\tD. Hexadecimal");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("D", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 6){
				printf ("A system that has the eight as its base.\n");
				printf ("\t\tA. Decimal\n\t\tB. Binary\n\t\tC. Octal\n\t\tD. Hexadecimal");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("C", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 7){
				printf ("Is a standard way of representing the input/output relationships of a gate circuit.\n");
				printf ("\t\tA. NAND Gate\n\t\tB. Truth Table\n\t\tC. AND Gate\n\t\tD. OR Gate");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("B", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 8){
				printf ("It is an electronic circuit that produces an inverted version of the input at its output. It is also known as an Inverter.\n");
				printf ("\t\tA. NOT Gate\n\t\tB. NOR Gate\n\t\tC. AND Gate\n\t\tD. OR Gate");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 9){
				printf ("A gate that is an OR gate with its output inverted.\n");
				printf ("\t\tA. NOT Gate\n\t\tB. OR Gate\n\t\tC. AND Gate\n\t\tD. NOR Gate");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("D", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 10){
				printf ("A gate that is an AND gate with its output inverted.\n");
				printf ("\t\tA. NOT Gate\n\t\tB. OR Gate\n\t\tC. NAND Gate\n\t\tD. NOR Gate");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("C", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
		}
		memset (orders, '\0', sizeof(orders));
	}
	
	void DLOG_medium(){
		srand(time(0));
		for (int i = 0; i < 10; i++){
			random_number = rand() % 10 + 1;
			while (
			orders[0] == random_number ||
			orders[1] == random_number ||
			orders[2] == random_number ||
			orders[3] == random_number ||
			orders[4] == random_number ||
			orders[5] == random_number ||
			orders[6] == random_number ||
			orders[7] == random_number ||
			orders[8] == random_number ||
			orders[9] == random_number ||
			orders[10] == random_number
			){
				random_number = rand() % 10 + 1;
			}
			orders [i] = random_number;
		}
		
		for (int i = 0; i < 10; i++){
			printf ("\n\t %d. ", i+1);
			if (orders [i] == 1){
				printf ("If we were to connect two inverter, the two inversion functions would \"cancel\" each other out.\n");
				printf ("\t\tA. Buffer Gate\n\t\tB. Truth Table\n\t\tC. AND Gate\n\t\tD. OR Gate");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 2){
				printf ("This law allows the removal of brackets from an expression and regrouping of the variables.\n");
				printf ("\t\tA. Associative Law\n\t\tB. Idempotent Law\n\t\tC. Identity Law\n\t\tD. Commutative Law");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 3){
				printf ("An input that is AND´ed or OR´ed with itself is equal to that input expression.\n");
				printf ("\t\tA. Associative Law\n\t\tB. Idempotent Law\n\t\tC. Identity Law\n\t\tD. Commutative Law");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("B", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 4){
				printf ("Allowing a change in position for addition and multiplication.\n");
				printf ("\t\tA. Associative Law\n\t\tB. Idempotent Law\n\t\tC. Identity Law\n\t\tD. Commutative Law");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("D", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 5){
				printf ("States that each thing is identical with self.\n");
				printf ("\t\tA. Associative Law\n\t\tB. Idempotent Law\n\t\tC. Identity Law\n\t\tD. Commutative Law");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("C", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 6){
				printf ("A term that is inverted twice is equal to the original term.\n");
				printf ("\t\tA. Complementary Law\n\t\tB. Law of Intersection\n\t\tC. Double Negative or Double Negation\n\t\tD. Commutative Law");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("C", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 7){
				printf ("This law permits the multiplying or factoring out of an expression.\n");
				printf ("\t\tA. Complementary Law\n\t\tB. Law of Intersection\n\t\tC. Double Negative or Double Negation\n\t\tD. Absorption");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("D", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 8){
				printf ("Convert 1101 based 2 to decimal system.\n");
				printf ("\t\tA. 10\n\t\tB. 13\n\t\tC. 12\n\t\tD. 11");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("B", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 9){
				printf ("Convert 11001101 based 2 to decimal system.\n");
				printf ("\t\tA. 203\n\t\tB. 201\n\t\tC. 210\n\t\tD. 205");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("D", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 10){
				printf ("Convert 11111111 based 2 to decimal system.\n");
				printf ("\t\tA. 245\n\t\tB. 250\n\t\tC. 260\n\t\tD. 255");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("D", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
		}
		memset (orders, '\0', sizeof(orders));
	}
	
	void DLOG_hard(){
		srand(time(0));
		for (int i = 0; i < 5; i++){
			random_number = rand() % 5 + 1;
			while (
			orders[0] == random_number ||
			orders[1] == random_number ||
			orders[2] == random_number ||
			orders[3] == random_number ||
			orders[4] == random_number ||
			orders[5] == random_number
			){
				random_number = rand() % 5 + 1;
			}
			orders [i] = random_number;
		}
		
		for (int i = 0; i < 10; i++){
			printf ("\n\t %d. ", i+1);
			if (orders [i] == 1){
				printf ("Convert 105 based 10 to octal system.\n");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("151", users_answer)==0){
					current_score +=20;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 2){
				printf ("Convert 142 based 10 to octal system.\n");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("216", users_answer)==0){
					current_score +=20;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 3){
				printf ("Convert A428 based 16 to decimal system.\n");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("42024", users_answer)==0){
					current_score +=20;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 4){
				printf ("Convert 47 based 16 to decimal system.\n");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("71", users_answer)==0){
					current_score +=20;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 5){
				printf ("Convert AE8 based 16 to decimal system.\n");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("2792", users_answer)==0){
					current_score +=20;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
		}
		memset (orders, '\0', sizeof(orders));
	}
	
	
	
	
	//WEBDEV QUESTIONS------------------------------------------------------------------------------
	
	void WEBDEV_easy(){
		srand(time(0));
		for (int i = 0; i < 10; i++){
			random_number = rand() % 10 + 1;
			while (
			orders[0] == random_number ||
			orders[1] == random_number ||
			orders[2] == random_number ||
			orders[3] == random_number ||
			orders[4] == random_number ||
			orders[5] == random_number ||
			orders[6] == random_number ||
			orders[7] == random_number ||
			orders[8] == random_number ||
			orders[9] == random_number ||
			orders[10] == random_number
			){
				random_number = rand() % 10 + 1;
			}
			orders [i] = random_number;
		}
		
		for (int i = 0; i < 10; i++){
			printf ("\n\t %d. ", i+1);
			if (orders [i] == 1){
				printf ("HTML stands for?\n");
				printf ("\t\tA. Hypertext Markup Language\n\t\tB. Hypertext Markup Link\n\t\tC. Hypertexter Markup Languages\n\t\tD. Hypertexter Markup Links");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 2){
				printf ("Not technically a tag but it tells the browser which version or standard of HTML it will use to render the page.\n");
				printf ("\t\tA. <DOCTYPE!>\n\t\tB. <DOCTYPE>\n\t\tC. <!DOCTYPE>\n\t\tD. <!DOCTYPE!>");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("C", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 3){
				printf ("HTML tag that contains the meta data or additional information about the document.\n");
				printf ("\t\tA. <header>\n\t\tB. <head>\n\t\tC. <h>\n\t\tD. <headers>");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("B", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 4){
				printf ("HTML tag that defines the title of the document.\n");
				printf ("\t\tA. <title>\n\t\tB. <body>\n\t\tC. <html>\n\t\tD. <meta>");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 5){
				printf ("HTML tag that contains all the content elements of the document that may be displayed on the browser.\n");
				printf ("\t\tA. <title>\n\t\tB. <body>\n\t\tC. <html>\n\t\tD. <meta>");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("B", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 6){
				printf ("HTML tag that defines the paragraph text.\n");
				printf ("\t\tA. <p>\n\t\tB. <paragraph>\n\t\tC. <paragraph text>\n\t\tD. <format_paragraph>");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 7){
				printf ("It is a sketch or blueprint of a Web page that shows the structure of basic page elements.\n");
				printf ("\t\tA. draft\n\t\tB. sketch\n\t\tC. wireframe\n\t\tD. color wheel");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("C", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 8){
				printf ("It graphically represents the relationships between colors.\n");
				printf ("\t\tA. Saturation\n\t\tB. Value\n\t\tC. Color wheel\n\t\tD. Sketch");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("C", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 9){
				printf ("Computer monitors are made up of thousands of tiny squares called?\n");
				printf ("\t\tA. pixels\n\t\tB. bytes\n\t\tC. megabytes\n\t\tD. None of the above");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 10){
				printf ("It is the thinking and planning that goes into a site before you so much as choose a color scheme or code a single line of HTML.\n");
				printf ("\t\tA. site analysis\n\t\tB. site-wide analysis\n\t\tC. system development\n\t\tD. system site-analysis");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=5;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
		}
		memset (orders, '\0', sizeof(orders));
	}
	
	void WEBDEV_medium(){
		srand(time(0));
		for (int i = 0; i < 10; i++){
			random_number = rand() % 10 + 1;
			while (
			orders[0] == random_number ||
			orders[1] == random_number ||
			orders[2] == random_number ||
			orders[3] == random_number ||
			orders[4] == random_number ||
			orders[5] == random_number ||
			orders[6] == random_number ||
			orders[7] == random_number ||
			orders[8] == random_number ||
			orders[9] == random_number ||
			orders[10] == random_number
			){
				random_number = rand() % 10 + 1;
			}
			orders [i] = random_number;
		}
		
		for (int i = 0; i < 10; i++){
			printf ("\n\t %d. ", i+1);
			if (orders [i] == 1){
				printf ("It consists of the thinking and planning that goes into a site before a single page is designed or constructed.\n");
				printf ("\t\tA. site analysis\n\t\tB. site-wide analysis\n\t\tC. system development life cycle (SDLC)\n\t\tD. system site-analysis");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("B", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 2){
				printf ("It is a process that has been used for several decades to build large-scale information systems.\n");
				printf ("\t\tA. site analysis\n\t\tB. site-wide analysis\n\t\tC. system development life cycle (SDLC)\n\t\tD. system site-analysis");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("C", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 3){
				printf ("Which CSS property configures the font typeface?\n");
				printf ("\t\tA. font-family\n\t\tB. font-style\n\t\tC. font-color\n\t\tD. font-size");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 4){
				printf ("Which CSS property configures the italic text?\n");
				printf ("\t\tA. font-family\n\t\tB. font-style\n\t\tC. font-color\n\t\tD. font-size");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("B", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 5){
				printf ("CSS rules are comprised of:\n");
				printf ("\t\tA. Selectors\n\t\tB. Declarations\n\t\tC. None of the choices\n\t\tD. Both A and B");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("D", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 6){
				printf ("What is the default Value for border property?\n");
				printf ("\t\tA. 2 pixels\n\t\tB. 1.5 pixels\n\t\tC. 1 pixel\n\t\tD. 0 pixel");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("D", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 7){
				printf ("The area between the content and the border.\n");
				printf ("\t\tA. Padding\n\t\tB. Space-between\n\t\tC. Margin\n\t\tD. All of the choices");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 8){
				printf ("How many color names are used by the browsers?\n");
				printf ("\t\tA. 16\n\t\tB. 14\n\t\tC. 12\n\t\tD. 10");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 9){
				printf ("Which are used with a tag to modify its function?\n");
				printf ("\t\tA. Files\n\t\tB. Functions\n\t\tC. Attributes\n\t\tD. Documents");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("C", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 10){
				printf ("Check boxes are used to _____ ?\n");
				printf ("\t\tA. Create lists and enable option\n\t\tB. Disable option and no lists\n\t\tC. Create lists and disable option\n\t\tD. Enable option and disable option ");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("D", users_answer)==0){
					current_score +=10;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
		}
		memset (orders, '\0', sizeof(orders));
	}
	
	void WEBDEV_hard(){
		srand(time(0));
		for (int i = 0; i < 5; i++){
			random_number = rand() % 5 + 1;
			while (
			orders[0] == random_number ||
			orders[1] == random_number ||
			orders[2] == random_number ||
			orders[3] == random_number ||
			orders[4] == random_number ||
			orders[5] == random_number
			){
				random_number = rand() % 5 + 1;
			}
			orders [i] = random_number;
		}
		
		for (int i = 0; i < 10; i++){
			printf ("\n\t %d. ", i+1);
			if (orders [i] == 1){
				printf ("Which of the following programs are likely to become very popular?\n");
				printf ("\t\tA. HTML, XML\n\t\tB. OBJECT, Applet\n\t\tC. DHTML, XML\n\t\tD. DHTML, HTML");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("C", users_answer)==0){
					current_score +=20;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 2){
				printf ("GIF and PNG stands for?\n");
				printf ("\t\tA. Graphics Interchange Format and Photograph Network Graphics\n\t\tB. Graphics Interchange Format and Portable Network Graphics\n\t\tC. Graphics Interchange Format and Portable Network Group\n\t\tD. Graphics Intercharge Format and Portable Network Graphics");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("B", users_answer)==0){
					current_score +=20;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 3){
				printf ("Which statement is CORRECT about the web design?\n");
				printf ("\t\tA. Cellspacing is used to specify the space between cells\n\t\tB. Cellspacing is used to specify the space between the text and border\n\t\tC. Cellpadding is used to specify the space between cells\n\t\tD. All of the above");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("A", users_answer)==0){
					current_score +=20;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 4){
				printf ("Which statement is INCORRECT about the web design?\n");
				printf ("\t\tA. CGI stands for Common Gateway Interface\n\t\tB. Form is a collection of controls in HTML\n\t\tC. HTML allows us to use 4 levels of headings\n\t\tD. Content is the attribute for meta tag");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("C", users_answer)==0){
					current_score +=20;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
			
			else if (orders [i] == 5){
				printf ("1ST STATEMENT: The ALIGN attribute is used to display an alternate message | 2ND STATEMENT: Change font icon displays lost of fonts that can be used\n");
				printf ("\t\tA. Both statements are true\n\t\tB. Both statements are false\n\t\tC. Only the first statement is correct\n\t\tD. Only the second statement is correct");
				printf ("\n\n\t Answer: ");
				scanf (" %s", users_answer);
				if (strcasecmp("D", users_answer)==0){
					current_score +=20;
				}
				memset (users_answer, '\0', sizeof(users_answer));
			}
		}
		memset (orders, '\0', sizeof(orders));
	}
	
	
	//RANKS DATA READER FUNCTION
	void ranks_data_reader (){
		//FOR INPR RANK READER***************************************************************************
		fp = fopen("RANKINGS/INPR_RANKINGS.txt", "r");	
		
		
		    //READING TOP 1 INPR PLAYER'S NAME & SCORE---------------------------------------------------
		    for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		   	sscanf (linereader, "Name: %[^\n]", inpr_top1.inpr_username);
		    
		    for (int i=1; i<=1; i++){
		    	fgets (linereader, 1024, fp);
			}
		   	sscanf (linereader, "Score: %d", &inpr_top1.inpr_score);
		    
		    
		    //READING TOP 2 INPR PLAYER'S NAME & SCORE---------------------------------------------------
		    for (int i=1; i<=3; i++){
		    	fgets (linereader, 1024, fp);
			}
		   	sscanf (linereader, "Name: %[^\n]", inpr_top2.inpr_username);
		    
		    for (int i=1; i<=1; i++){
		    	fgets (linereader, 1024, fp);
			}
		    sscanf(linereader, "Score: %d", &inpr_top2.inpr_score);	
				    
		    
		    //READING TOP 3 INPR PLAYER'S NAME & SCORE---------------------------------------------------
		    for (int i=1; i<=3; i++){
		    	fgets (linereader, 1024, fp);
			}
		   	sscanf (linereader, "Name: %[^\n]", inpr_top3.inpr_username);		
			       
		    for (int i=1; i<=1; i++){
		    	fgets (linereader, 1024, fp);
			}
		    sscanf(linereader, "Score: %d", &inpr_top3.inpr_score);
		    
		    
		    //READING TOP 4 INPR PLAYER'S NAME & SCORE---------------------------------------------------
		    for (int i=1; i<=3; i++){
		    	fgets (linereader, 1024, fp);
			}
		   	sscanf (linereader, "Name: %[^\n]", inpr_top4.inpr_username);
		    
		    for (int i=1; i<=1; i++){
		    	fgets (linereader, 1024, fp);
			}
		    sscanf(linereader, "Score: %d", &inpr_top4.inpr_score);
		    
		    
		    //READING TOP 5 INPR PLAYER'S NAME & SCORE----------------------------------------------------
		    for (int i=1; i<=3; i++){
		    	fgets (linereader, 1024, fp);
			}
		   	sscanf (linereader, "Name: %[^\n]", inpr_top5.inpr_username);
		    
		    for (int i=1; i<=1; i++){
		    	fgets (linereader, 1024, fp);
			}
		    sscanf(linereader, "Score: %d", &inpr_top5.inpr_score);		    
		    fclose(fp);

		//FOR DLOG RANK READER******************************************************************************
		fp = fopen("RANKINGS/DLOG_RANKINGS.txt", "r");	
		
		
		    //READING TOP 1 DLOG PLAYER'S NAME & SCORE---------------------------------------------------
		    for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		   	sscanf (linereader, "Name: %[^\n]", dlog_top1.dlog_username);
		    
		    for (int i=1; i<=1; i++){
		    	fgets (linereader, 1024, fp);
			}
		   	sscanf (linereader, "Score: %d", &dlog_top1.dlog_score);
		    
		    
		    //READING TOP 2 DLOG PLAYER'S NAME & SCORE---------------------------------------------------
		    for (int i=1; i<=3; i++){
		    	fgets (linereader, 1024, fp);
			}
		   	sscanf (linereader, "Name: %[^\n]", dlog_top2.dlog_username);
		    
		    for (int i=1; i<=1; i++){
		    	fgets (linereader, 1024, fp);
			}
		    sscanf(linereader, "Score: %d", &dlog_top2.dlog_score);	
				    
		    
		    //READING TOP 3 DLOG PLAYER'S NAME & SCORE---------------------------------------------------
		    for (int i=1; i<=3; i++){
		    	fgets (linereader, 1024, fp);
			}
		   	sscanf (linereader, "Name: %[^\n]", dlog_top3.dlog_username);		
			       
		    for (int i=1; i<=1; i++){
		    	fgets (linereader, 1024, fp);
			}
		    sscanf(linereader, "Score: %d", &dlog_top3.dlog_score);
		    
		    
		    //READING TOP 4 DLOG PLAYER'S NAME & SCORE---------------------------------------------------
		    for (int i=1; i<=3; i++){
		    	fgets (linereader, 1024, fp);
			}
		   	sscanf (linereader, "Name: %[^\n]", dlog_top4.dlog_username);
		    
		    for (int i=1; i<=1; i++){
		    	fgets (linereader, 1024, fp);
			}
		    sscanf(linereader, "Score: %d", &dlog_top4.dlog_score);
		    
		    
		    //READING TOP 5 DLOG PLAYER'S NAME & SCORE----------------------------------------------------
		    for (int i=1; i<=3; i++){
		    	fgets (linereader, 1024, fp);
			}
		   	sscanf (linereader, "Name: %[^\n]", dlog_top5.dlog_username);
		    
		    for (int i=1; i<=1; i++){
		    	fgets (linereader, 1024, fp);
			}
		    sscanf(linereader, "Score: %d", &dlog_top5.dlog_score);		    
		    fclose(fp);
		    

		//FOR WEBDEV RANK READER******************************************************************************
		fp = fopen("RANKINGS/WEBDEV_RANKINGS.txt", "r");	
		
		
		    //READING TOP 1 WEBDEV PLAYER'S NAME & SCORE---------------------------------------------------
		    for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		   	sscanf (linereader, "Name: %[^\n]", webdev_top1.webdev_username);
		    
		    for (int i=1; i<=1; i++){
		    	fgets (linereader, 1024, fp);
			}
		   	sscanf (linereader, "Score: %d", &webdev_top1.webdev_score);
		    
		    
		    //READING TOP 2 WEBDEV PLAYER'S NAME & SCORE---------------------------------------------------
		    for (int i=1; i<=3; i++){
		    	fgets (linereader, 1024, fp);
			}
		   	sscanf (linereader, "Name: %[^\n]", webdev_top2.webdev_username);
		    
		    for (int i=1; i<=1; i++){
		    	fgets (linereader, 1024, fp);
			}
		    sscanf(linereader, "Score: %d", &webdev_top2.webdev_score);	
				    
		    
		    //READING TOP 3 WEBDEV PLAYER'S NAME & SCORE---------------------------------------------------
		    for (int i=1; i<=3; i++){
		    	fgets (linereader, 1024, fp);
			}
		   	sscanf (linereader, "Name: %[^\n]", webdev_top3.webdev_username);		
			       
		    for (int i=1; i<=1; i++){
		    	fgets (linereader, 1024, fp);
			}
		    sscanf(linereader, "Score: %d", &webdev_top3.webdev_score);
		    
		    
		    //READING TOP 4 WEBDEV PLAYER'S NAME & SCORE---------------------------------------------------
		    for (int i=1; i<=3; i++){
		    	fgets (linereader, 1024, fp);
			}
		   	sscanf (linereader, "Name: %[^\n]", webdev_top4.webdev_username);
		    
		    for (int i=1; i<=1; i++){
		    	fgets (linereader, 1024, fp);
			}
		    sscanf(linereader, "Score: %d", &webdev_top4.webdev_score);
		    
		    
		    //READING TOP 5 WEBDEV PLAYER'S NAME & SCORE----------------------------------------------------
		    for (int i=1; i<=3; i++){
		    	fgets (linereader, 1024, fp);
			}
		   	sscanf (linereader, "Name: %[^\n]", webdev_top5.webdev_username);
		    
		    for (int i=1; i<=1; i++){
		    	fgets (linereader, 1024, fp);
			}
		    sscanf(linereader, "Score: %d", &webdev_top5.webdev_score);		    
		    fclose(fp);
		    
	}
	
	//MODIFIES THE DATA INSIDE THE FILE IF CURRENT_PLAYER IS ATLEAST TOP 5
	void ranks_setter() {
		if (strcasecmp("INPR", choice_subject)==0){
			if (current_score >= inpr_top1.inpr_score) {
				printf ("\t\t\t\t\t\t\t Great job! You are now the top 1 scorer in the INPR quiz!");
				
			    strcpy(inpr_top5.inpr_username, inpr_top4.inpr_username);
			    inpr_top5.inpr_score = inpr_top4.inpr_score;
			
			    strcpy(inpr_top4.inpr_username, inpr_top3.inpr_username);
			    inpr_top4.inpr_score = inpr_top3.inpr_score;
			
			    strcpy(inpr_top3.inpr_username, inpr_top2.inpr_username);
			    inpr_top3.inpr_score = inpr_top2.inpr_score;
			
			    strcpy(inpr_top2.inpr_username, inpr_top1.inpr_username);
			    inpr_top2.inpr_score = inpr_top1.inpr_score;
			
			    strcpy(inpr_top1.inpr_username, username);
			    inpr_top1.inpr_score = current_score;
			    
			    ranks_typer();
			} 
			  
			else if (current_score >= inpr_top2.inpr_score) {
				printf ("\t\t\t\t\t\t\t Congratulations on making it to the 2nd spot in the INPR quiz!");
				
			    strcpy(inpr_top5.inpr_username, inpr_top4.inpr_username);
			    inpr_top5.inpr_score = inpr_top4.inpr_score;
			
			    strcpy(inpr_top4.inpr_username, inpr_top3.inpr_username);
			    inpr_top4.inpr_score = inpr_top3.inpr_score;
			
			    strcpy(inpr_top3.inpr_username, inpr_top2.inpr_username);
			    inpr_top3.inpr_score = inpr_top2.inpr_score;
			
			    strcpy(inpr_top2.inpr_username, username);
			    inpr_top2.inpr_score = current_score;
			    
			    ranks_typer();
			} 
			  
			else if (current_score >= inpr_top3.inpr_score) {
				printf ("\t\t\t\t\t\t\t Well done on reaching the 3rd spot in the INPR quiz!");
				
			    strcpy(inpr_top5.inpr_username, inpr_top4.inpr_username);
			    inpr_top5.inpr_score = inpr_top4.inpr_score;
			
			    strcpy(inpr_top4.inpr_username, inpr_top3.inpr_username);
			    inpr_top4.inpr_score = inpr_top3.inpr_score;
			
			    strcpy(inpr_top3.inpr_username, username);
			    inpr_top3.inpr_score = current_score;
			    
			    ranks_typer();
			} 
			  
			else if (current_score >= inpr_top4.inpr_score) {
				printf ("\t\t\t\t\t\t\t Excellent work on securing the 4th spot in the INPR quiz!");
				
			    strcpy(inpr_top5.inpr_username, inpr_top4.inpr_username);
			    inpr_top5.inpr_score = inpr_top4.inpr_score;
			
			    strcpy(inpr_top4.inpr_username, username);
			    inpr_top4.inpr_score =current_score;
			    
			    ranks_typer();
			} 
			  
			else if (current_score >= inpr_top5.inpr_score) {
				printf ("\t\t\t\t\t\t\t Nice job on making it to the top 5 in the INPR quiz!");
				
				strcpy(inpr_top5.inpr_username, username);
			    inpr_top5.inpr_score = current_score;
			    
			    ranks_typer();
			} 
			  
			else {
			    printf("\n\t\t\t\t\t\t\t Unfortunately, you did not make it to the top 5.\n\t\t\t\t\t\t\t Keep working hard %s and you'll get there.", username);
			}
		}

		else if (strcasecmp("DLOG", choice_subject)==0){
			if (current_score >= dlog_top1.dlog_score) {
				
				printf ("\t\t\t\t\t\t\t Congratulations! You've achieved the 1st spot in the DLOG quiz!");
				
			    strcpy(dlog_top5.dlog_username, dlog_top4.dlog_username);
			    dlog_top5.dlog_score = dlog_top4.dlog_score;
			
			    strcpy(dlog_top4.dlog_username, dlog_top3.dlog_username);
			    dlog_top4.dlog_score = dlog_top3.dlog_score;
			
			    strcpy(dlog_top3.dlog_username, dlog_top2.dlog_username);
			    dlog_top3.dlog_score = dlog_top2.dlog_score;
			
			    strcpy(dlog_top2.dlog_username, dlog_top1.dlog_username);
			    dlog_top2.dlog_score = dlog_top1.dlog_score;
			
			    strcpy(dlog_top1.dlog_username, username);
			    dlog_top1.dlog_score = current_score;
			    
			    ranks_typer();
			} 
			  
			else if (current_score >= dlog_top2.dlog_score) {
				
				printf ("\t\t\t\t\t\t\t Great job! You've earned the 2nd spot in the DLOG quiz!");
				
			    strcpy(dlog_top5.dlog_username, dlog_top4.dlog_username);
			    dlog_top5.dlog_score = dlog_top4.dlog_score;
			
			    strcpy(dlog_top4.dlog_username, dlog_top3.dlog_username);
			    dlog_top4.dlog_score = dlog_top3.dlog_score;
			
			    strcpy(dlog_top3.dlog_username, dlog_top2.dlog_username);
			    dlog_top3.dlog_score = dlog_top2.dlog_score;
			
			    strcpy(dlog_top2.dlog_username, username);
			    dlog_top2.dlog_score = current_score;
			    
			    ranks_typer();
			} 
			  
			else if (current_score >= dlog_top3.dlog_score) {
				
				printf ("\t\t\t\t\t\t\t Well done! You've secured the 3rd spot in the DLOG quiz!");
				
			    strcpy(dlog_top5.dlog_username, dlog_top4.dlog_username);
			    dlog_top5.dlog_score = dlog_top4.dlog_score;
			
			    strcpy(dlog_top4.dlog_username, dlog_top3.dlog_username);
			    dlog_top4.dlog_score = dlog_top3.dlog_score;
			
			    strcpy(dlog_top3.dlog_username, username);
			    dlog_top3.dlog_score = current_score;
			    
			    ranks_typer();
			} 
			  
			else if (current_score >= dlog_top4.dlog_score) {
				
				printf ("\t\t\t\t\t\t\t Good work! You've made it to the 4th spot in the DLOG quiz!");
				
			    strcpy(dlog_top5.dlog_username, dlog_top4.dlog_username);
			    dlog_top5.dlog_score = dlog_top4.dlog_score;
			
			    strcpy(dlog_top4.dlog_username, username);
			    dlog_top4.dlog_score =current_score;
			    
			    ranks_typer();
			} 
			  
			else if (current_score >= dlog_top5.dlog_score) {
				
				printf ("\t\t\t\t\t\t\t Nice effort! You've claimed the 5th spot in the DLOG quiz!");
				
				strcpy(dlog_top5.dlog_username, username);
			    dlog_top5.dlog_score = current_score;
			    
			    ranks_typer();
			} 
			  
			else {
			    printf("\n\t\t\t\t\t\t\t Unfortunately, you did not make it to the top 5.\n\t\t\t\t\t\t\t Keep working hard %s and you'll get there.", username);
			}
		}
		
		else if (strcasecmp("WEBDEV", choice_subject)==0){
			if (current_score >= webdev_top1.webdev_score) {
				
				printf ("\t\t\t\t\t\t\t Fantastic job! You're the top 1 performer in the WEBDEV quiz.");
				
			    strcpy(webdev_top5.webdev_username, webdev_top4.webdev_username);
			    webdev_top5.webdev_score = webdev_top4.webdev_score;
			
			    strcpy(webdev_top4.webdev_username, webdev_top3.webdev_username);
			    webdev_top4.webdev_score = webdev_top3.webdev_score;
			
			    strcpy(webdev_top3.webdev_username, webdev_top2.webdev_username);
			    webdev_top3.webdev_score = webdev_top2.webdev_score;
			
			    strcpy(webdev_top2.webdev_username, webdev_top1.webdev_username);
			    webdev_top2.webdev_score = webdev_top1.webdev_score;
			
			    strcpy(webdev_top1.webdev_username, username);
			    webdev_top1.webdev_score = current_score;
			    
			    ranks_typer();
			} 
			  
			else if (current_score >= webdev_top2.webdev_score) {
				
				printf ("\t\t\t\t\t\t\t Amazing effort! You've made it to the 2nd spot in the WEBDEV quiz.");
				
			    strcpy(webdev_top5.webdev_username, webdev_top4.webdev_username);
			    webdev_top5.webdev_score = webdev_top4.webdev_score;
			
			    strcpy(webdev_top4.webdev_username, webdev_top3.webdev_username);
			    webdev_top4.webdev_score = webdev_top3.webdev_score;
			
			    strcpy(webdev_top3.webdev_username, webdev_top2.webdev_username);
			    webdev_top3.webdev_score = webdev_top2.webdev_score;
			
			    strcpy(webdev_top2.webdev_username, username);
			    webdev_top2.webdev_score = current_score;
			    
			    ranks_typer();
			} 
			  
			else if (current_score >= webdev_top3.webdev_score) {
				
				printf ("\t\t\t\t\t\t\t Impressive performance! You've secured the 3rd spot in the WEBDEV quiz.");
				
			    strcpy(webdev_top5.webdev_username, webdev_top4.webdev_username);
			    webdev_top5.webdev_score = webdev_top4.webdev_score;
			
			    strcpy(webdev_top4.webdev_username, webdev_top3.webdev_username);
			    webdev_top4.webdev_score = webdev_top3.webdev_score;
			
			    strcpy(webdev_top3.webdev_username, username);
			    webdev_top3.webdev_score = current_score;
			    
			    ranks_typer();
			} 
			  
			else if (current_score >= webdev_top4.webdev_score) {
				
				printf ("\t\t\t\t\t\t\t Great job! You're now the 4th place in the WEBDEV quiz.");
				
			    strcpy(webdev_top5.webdev_username, webdev_top4.webdev_username);
			    webdev_top5.webdev_score = webdev_top4.webdev_score;
			
			    strcpy(webdev_top4.webdev_username, username);
			    webdev_top4.webdev_score =current_score;
			    
			    ranks_typer();
			} 
			  
			else if (current_score >= webdev_top5.webdev_score) {
				
				printf ("\t\t\t\t\t\t\t Good work! You've earned the 5th spot in the WEBDEV quiz.");
				
				strcpy(webdev_top5.webdev_username, username);
			    webdev_top5.webdev_score = current_score;
			    
			    ranks_typer();
			} 
			  
			else {
			    printf("\n\t\t\t\t\t\t\t Unfortunately, you did not make it to the top 5.\n Keep working hard %s and you'll get there.", username);
			}
		}
	}
	
	//HELPS ranks_setter to type data into the file
	void ranks_typer() {
		
		if (strcasecmp("INPR", choice_subject)==0){
			fp = fopen ("RANKINGS/INPR_RANKINGS.txt", "w");
					fprintf (fp, "***INPR RANKINGS LIST***\n");
					fprintf (fp, "\n");
					fprintf (fp, "--TOP 1 PLAYER IN INPR--\n");
					fprintf (fp, "Name: %s\n", inpr_top1.inpr_username);
					fprintf (fp, "Score: %d\n", inpr_top1.inpr_score);
					fprintf (fp, "\n");
					fprintf (fp, "--TOP 2 PLAYER IN INPR--\n");
					fprintf (fp, "Name: %s\n", inpr_top2.inpr_username);
					fprintf (fp, "Score: %d\n", inpr_top2.inpr_score);
					fprintf (fp, "\n");
					fprintf (fp, "--TOP 3 PLAYER IN INPR--\n");
					fprintf (fp, "Name: %s\n", inpr_top3.inpr_username);
					fprintf (fp, "Score: %d\n", inpr_top3.inpr_score);
					fprintf (fp, "\n");
					fprintf (fp, "--TOP 4 PLAYER IN INPR--\n");
					fprintf (fp, "Name: %s\n", inpr_top4.inpr_username);
					fprintf (fp, "Score: %d\n", inpr_top4.inpr_score);
					fprintf (fp, "\n");
					fprintf (fp, "--TOP 5 PLAYER IN INPR--\n");
					fprintf (fp, "Name: %s\n", inpr_top5.inpr_username);
					fprintf (fp, "Score: %d", inpr_top5.inpr_score);
			fclose (fp);
		}
		
		else if (strcasecmp("DLOG", choice_subject)==0){
			fp = fopen ("RANKINGS/DLOG_RANKINGS.txt", "w");
					fprintf (fp, "***DLOG RANKINGS LIST***\n");
					fprintf (fp, "\n");
					fprintf (fp, "--TOP 1 PLAYER IN DLOG--\n");
					fprintf (fp, "Name: %s\n", dlog_top1.dlog_username);
					fprintf (fp, "Score: %d\n", dlog_top1.dlog_score);
					fprintf (fp, "\n");
					fprintf (fp, "--TOP 2 PLAYER IN DLOG--\n");
					fprintf (fp, "Name: %s\n", dlog_top2.dlog_username);
					fprintf (fp, "Score: %d\n", dlog_top2.dlog_score);
					fprintf (fp, "\n");
					fprintf (fp, "--TOP 3 PLAYER IN DLOG--\n");
					fprintf (fp, "Name: %s\n", dlog_top3.dlog_username);
					fprintf (fp, "Score: %d\n", dlog_top3.dlog_score);
					fprintf (fp, "\n");
					fprintf (fp, "--TOP 4 PLAYER IN DLOG--\n");
					fprintf (fp, "Name: %s\n", dlog_top4.dlog_username);
					fprintf (fp, "Score: %d\n", dlog_top4.dlog_score);
					fprintf (fp, "\n");
					fprintf (fp, "--TOP 5 PLAYER IN DLOG--\n");
					fprintf (fp, "Name: %s\n", dlog_top5.dlog_username);
					fprintf (fp, "Score: %d", dlog_top5.dlog_score);
			fclose (fp);
		}
		
		else if (strcasecmp("WEBDEV", choice_subject)==0){
			fp = fopen ("RANKINGS/WEBDEV_RANKINGS.txt", "w");
					fprintf (fp, "***WEBDEV RANKINGS LIST***\n");
					fprintf (fp, "\n");
					fprintf (fp, "--TOP 1 PLAYER IN WEBDEV--\n");
					fprintf (fp, "Name: %s\n", webdev_top1.webdev_username);
					fprintf (fp, "Score: %d\n", webdev_top1.webdev_score);
					fprintf (fp, "\n");
					fprintf (fp, "--TOP 2 PLAYER IN WEBDEV--\n");
					fprintf (fp, "Name: %s\n", webdev_top2.webdev_username);
					fprintf (fp, "Score: %d\n", webdev_top2.webdev_score);
					fprintf (fp, "\n");
					fprintf (fp, "--TOP 3 PLAYER IN WEBDEV--\n");
					fprintf (fp, "Name: %s\n", webdev_top3.webdev_username);
					fprintf (fp, "Score: %d\n", webdev_top3.webdev_score);
					fprintf (fp, "\n");
					fprintf (fp, "--TOP 4 PLAYER IN WEBDEV--\n");
					fprintf (fp, "Name: %s\n", webdev_top4.webdev_username);
					fprintf (fp, "Score: %d\n", webdev_top4.webdev_score);
					fprintf (fp, "\n");
					fprintf (fp, "--TOP 5 PLAYER IN WEBDEV--\n");
					fprintf (fp, "Name: %s\n", webdev_top5.webdev_username);
					fprintf (fp, "Score: %d", webdev_top5.webdev_score);
			fclose (fp);
		}
	}
	
	//READS THE NAME AND PINS OF ALL OF THE ACCOUNTS
	void accounts_reader() {
		
		//READS THE ACCOUNT NAMESSSSSSSSSSSSSSSSSSS----------------------------------------------------------
		
		fp = fopen("ACCOUNTS/Personal_Information.txt", "r");
		
		//read acc 1
		for (int i=1; i<=7; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[0].account_username);
		
		// Read account 2
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[1].account_username);
		
		// Read account 3
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[2].account_username);		
		
		// Read account 4
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[3].account_username);		
		
		// Read account 5
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[4].account_username);		
		
		// Read account 6
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[5].account_username);		
		
		// Read account 7
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[6].account_username);
		
		// Read account 8
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[7].account_username);
		
		// Read account 9
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[8].account_username);
		
		// Read account 10
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[9].account_username);
		
		// Read account 11
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[10].account_username);
				
		// Read account 12
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[11].account_username);
				
		// Read account 13
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[12].account_username);
				
		// Read account 14
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[13].account_username);
				
		// Read account 15
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[14].account_username);
				
		// Read account 16
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[15].account_username);
				
		// Read account 17
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[16].account_username);
				
		// Read account 18
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[17].account_username);
				
		// Read account 19
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[18].account_username);
				
		// Read account 20
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[19].account_username);
				
		// Read account 21
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[20].account_username);
				
		// Read account 22
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[21].account_username);
				
		// Read account 23
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[22].account_username);
				
		// Read account 24
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[23].account_username);
				
		// Read account 25
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[24].account_username);
				
		// Read account 26
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[25].account_username);
				
		// Read account 27
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[26].account_username);
				
		// Read account 28
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[27].account_username);
				
		// Read account 29
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[28].account_username);
				
		// Read account 30
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "USERNAME: %[^\n]", account_info[29].account_username);
				
		fclose(fp);
		
		//READS THE PINNSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS------------------------------------
		fp = fopen("ACCOUNTS/Personal_Information.txt", "r");
		
		// Read PIN 1
		for (int i=1; i<=8; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[0].account_pin);
		
		// Read PIN 2
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[1].account_pin);
		
		// Read PIN 3
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[2].account_pin);
		
		// Read PIN 4
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[3].account_pin);
		
		// Read PIN 5
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[4].account_pin);
		
		// Read PIN 6
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[5].account_pin);
		
		// Read PIN 7
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[6].account_pin);
		
		// Read PIN 8
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[7].account_pin);
		
		// Read PIN 9
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[8].account_pin);
		
		// Read PIN 10
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[9].account_pin);
		
		// Read PIN 11
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[10].account_pin);
		
		// Read PIN 12
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[11].account_pin);
		
		// Read PIN 13
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[12].account_pin);
		
		// Read PIN 14
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[13].account_pin);
		
		// Read PIN 15
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[14].account_pin);
		
		// Read PIN 16
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[15].account_pin);
		
		// Read PIN 17
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[16].account_pin);
		
		// Read PIN 18
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[17].account_pin);
		
		// Read PIN 19
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[18].account_pin);
		
		// Read PIN 20
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[19].account_pin);
		
		// Read PIN 21
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[20].account_pin);
		
		// Read PIN 22
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[21].account_pin);
		
		// Read PIN 23
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[22].account_pin);
		
		// Read PIN 24
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[23].account_pin);
		
		// Read PIN 25
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[24].account_pin);
		
		// Read PIN 26
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[25].account_pin);
		
		// Read PIN 27
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[26].account_pin);
		
		// Read PIN 28
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[27].account_pin);
		
		// Read PIN 29
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[28].account_pin);
		
		// Read PIN 30
		for (int i=1; i<=4; i++){
		    	fgets (linereader, 1024, fp);
			}
		sscanf (linereader, "PIN: %d", &account_info[29].account_pin);


	}
	
	void number_of_accounts_reader() {
		fp = fopen ("ACCOUNTS/Personal_Information.txt", "r");
		
		for (int i=1; i<=3; i++){
			fgets (linereader, 1024, fp);
		}
		sscanf (linereader, "NUMBER OF REGISTERED ACCOUNTS: %d", &account_count);
		
		fclose (fp);
	}
	
	void number_of_accounts_add() {
		fp = fopen ("ACCOUNTS/Personal_Information.txt", "w");
		account_count++;
		
		fprintf (fp, "In consideration of privacy, we kindly request that you not disclose any information below that may compromise personal security of the OLFU quiz game users.\n");
		fprintf (fp, "\n");
		fprintf (fp, "NUMBER OF REGISTERED ACCOUNTS: %d\n", account_count);
		fprintf (fp, "OLFU QUIZ GAME ACCOUNTS:\n");
		fprintf (fp, "\n");
		
		for (int i=0; i<30; i++){
			fprintf (fp, "%d\n", i+1);
			fprintf (fp, "USERNAME: %s\n", account_info[i].account_username);
			fprintf (fp, "PIN: %d\n", account_info[i].account_pin);
			fprintf (fp, "\n");
		}
		fclose (fp);
	}
	
	void account_login_checker() {
		for (int i=0; i<30; i++){
			if (strcmp(username, account_info[i].account_username) == 0 && current_pin == account_info[i].account_pin){
				strcpy (username, account_info[i].account_username);
				system ("cls");
				printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t   ---------- LOGIN SUCCESSFUL ----------\n\n");
				printf ("\t\t\t\t\t\t\t\tWelcome Back %s! Please wait for a moment...", username);
				tryagain = 0;
				sleep (4);
				break;
			}
		}
	}
	
	//TYPES THE CURRENT REGISTERED USERNAME AND PIN TO A FILE (ORDERED) 
	void account_typer(){
		fp = fopen ("ACCOUNTS/Personal_Information.txt", "w");
		for (int i=0; i<30; i++){
			if (account_count == i){
			strcpy (account_info[i].account_username, username);
			account_info[i].account_pin = current_pin;
			}	
		} 
	}
		//DIY LOADING BAR
	void loadingbar() {
	    printf("\r\n\n\n\t\t\t\t\t\t\t\t   PLEASE WAIT [=                ] 0%%");
	    sleep (5);
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [===              ] 5%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [====             ] 10%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [======           ] 15%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [======           ] 20%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [=======          ] 25%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [=======          ] 30%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [========         ] 35%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [========         ] 40%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [=========        ] 45%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [=========        ] 50%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [==========       ] 55%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [==========       ] 60%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [============     ] 65%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [============     ] 70%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [=============    ] 75%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [=============    ] 80%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [===============  ] 85%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [===============  ] 90%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [================ ] 95%%");
	    usleep(150000);
	    printf("\r\t\t\t\t\t\t\t\t   PLEASE WAIT [=================] 100%%");
	    usleep(500000);
		}

	void display_easy(){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t8888888888        d8888  .d8888b. Y88b   d88P\n");
	    printf("\t\t\t\t\t\t\t\t888              d88888 d88P  Y88b Y88b d88P\n");
	    printf("\t\t\t\t\t\t\t\t888             d88P888 Y88b.       Y88o88P\n");
	    printf("\t\t\t\t\t\t\t\t8888888        d88P 888  \"Y888b.     Y888P\n");
	    printf("\t\t\t\t\t\t\t\t888           d88P  888     \"Y88b.    888\n");
	    printf("\t\t\t\t\t\t\t\t888          d88P   888       \"888    888\n");
	    printf("\t\t\t\t\t\t\t\t888         d8888888888 Y88b  d88P    888\n");
	    printf("\t\t\t\t\t\t\t\t8888888888 d88P     888  \"Y8888P\"     888\n");
	}
	
	void display_medium(){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t     888b     d888 8888888888 8888888b. 8888888 888     888 888b     d888\n");
	    printf("\t\t\t\t\t\t     8888b   d8888 888        888  \"Y88b  888   888     888 8888b   d8888\n");
	    printf("\t\t\t\t\t\t     88888b.d88888 888        888    888  888   888     888 88888b.d88888\n");
	    printf("\t\t\t\t\t\t     888Y88888P888 8888888    888    888  888   888     888 888Y88888P888\n");
	    printf("\t\t\t\t\t\t     888 Y888P 888 888        888    888  888   888     888 888 Y888P 888\n");
	    printf("\t\t\t\t\t\t     888  Y8P  888 888        888    888  888   888     888 888  Y8P  888\n");
	    printf("\t\t\t\t\t\t     888   \"   888 888        888  .d88P  888   Y88b. .d88P 888   \"   888\n");
	    printf("\t\t\t\t\t\t     888       888 8888888888 8888888P\" 8888888  \"Y88888P\"  888       888\n");
	}
	
	void display_hard(){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t888    888        d8888 8888888b.  8888888b.  \n");
	    printf("\t\t\t\t\t\t\t\t888    888       d88888 888   Y88b 888  \"Y88b \n");
	    printf("\t\t\t\t\t\t\t\t888    888      d88P888 888    888 888    888 \n");
	    printf("\t\t\t\t\t\t\t\t8888888888     d88P 888 888   d88P 888    888 \n");
	    printf("\t\t\t\t\t\t\t\t888    888    d88P  888 8888888P\"  888    888 \n");
	    printf("\t\t\t\t\t\t\t\t888    888   d88P   888 888 T88b   888    888 \n");
	    printf("\t\t\t\t\t\t\t\t888    888  d8888888888 888  T88b  888  .d88P \n");
	    printf("\t\t\t\t\t\t\t\t888    888 d88P     888 888   T88b 8888888P\"  \n");
	}
	
	void title_transition(){
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO OUR LADY OF FATIMA UNIVERSITY QUIZ | Powered by: TECHNOCREW\n\n");
		printf ("\t\t\t\t\t\t\t\t   Please enter any key to continue...\n\n\n");
    	SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	 	printf("\t     .d88888b.  888      8888888888 888     888      .d88888b.  888     888 8888888 8888888888P      .d8888b.         d8888 888b     d888 8888888888 \n");
	    printf("\t    d88Y\" \"Y88b 888      888        888     888     d88P\" \"Y88b 888     888   888         d88P      d88P  Y88b       d88888 8888b   d8888 888        \n");
	    printf("\t    888     888 888      888        888     888     888     888 888     888   888        d88P       888    888      d88P888 88888b.d88888 888        \n");
	    printf("\t    888     888 888      8888888    888     888     888     888 888     888   888       d88P        888            d88P 888 888Y88888P888 8888888    \n");
	    printf("\t    888     888 888      888        888     888     888     888 888     888   888      d88P         888  88888    d88P  888 888 Y888P 888 888        \n");
	    printf("\t    888     888 888      888        888     888     888     888 888     888   888     d88P          888    888   d88P   888 888  Y8P  888 888        \n");
	    printf("\t    Y88b. .d88P 888      888        Y88b. .d88P     Y88b.Y8b88P Y88b. .d88P   888    d88P           Y88b  d88P  d8888888888 888   \"   888 888        \n");
	    printf("\t     \"Y88888P\"  88888888 888         \"Y88888P\"       \"Y888888\"   \"Y88888P\"  8888888 d8888888888      \"Y8888P8  d88P     888 888       888 8888888888 \n");
		SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		
		usleep(150000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO OUR LADY OF FATIMA UNIVERSITY QUIZ | Powered by: TECHNOCREW\n\n");
		printf ("\t\t\t\t\t\t\t\t   Please enter any key to continue...\n\n\n");
    	SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	 	printf("\t     .d88888b.  888      8888888888 888     888      .d88888b.  888     888 8888888 8888888888P      .d8888b.         d8888 888b     d888 8888888888 \n");
	    printf("\t    d88Y\" \"Y88b 888      888        888     888     d88P\" \"Y88b 888     888   888         d88P      d88P  Y88b       d88888 8888b   d8888 888        \n");
	    printf("\t    888     888 888      888        888     888     888     888 888     888   888        d88P       888    888      d88P888 88888b.d88888 888        \n");
	    printf("\t    888     888 888      8888888    888     888     888     888 888     888   888       d88P        888            d88P 888 888Y88888P888 8888888    \n");
	    printf("\t    888     888 888      888        888     888     888     888 888     888   888      d88P         888  88888    d88P  888 888 Y888P 888 888        \n");
	    printf("\t    888     888 888      888        888     888     888     888 888     888   888     d88P          888    888   d88P   888 888  Y8P  888 888        \n");
	    printf("\t    Y88b. .d88P 888      888        Y88b. .d88P     Y88b.Y8b88P Y88b. .d88P   888    d88P           Y88b  d88P  d8888888888 888   \"   888 888        \n");
		SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		
		usleep(150000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO OUR LADY OF FATIMA UNIVERSITY QUIZ | Powered by: TECHNOCREW\n\n");
		printf ("\t\t\t\t\t\t\t\t   Please enter any key to continue...\n\n\n");
    	SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	 	printf("\t     .d88888b.  888      8888888888 888     888      .d88888b.  888     888 8888888 8888888888P      .d8888b.         d8888 888b     d888 8888888888 \n");
	    printf("\t    d88Y\" \"Y88b 888      888        888     888     d88P\" \"Y88b 888     888   888         d88P      d88P  Y88b       d88888 8888b   d8888 888        \n");
	    printf("\t    888     888 888      888        888     888     888     888 888     888   888        d88P       888    888      d88P888 88888b.d88888 888        \n");
	    printf("\t    888     888 888      8888888    888     888     888     888 888     888   888       d88P        888            d88P 888 888Y88888P888 8888888    \n");
	    printf("\t    888     888 888      888        888     888     888     888 888     888   888      d88P         888  88888    d88P  888 888 Y888P 888 888        \n");
	    printf("\t    888     888 888      888        888     888     888     888 888     888   888     d88P          888    888   d88P   888 888  Y8P  888 888        \n");
		SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		
		usleep(150000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO OUR LADY OF FATIMA UNIVERSITY QUIZ | Powered by: TECHNOCREW\n\n");
		printf ("\t\t\t\t\t\t\t\t   Please enter any key to continue...\n\n\n");
    	SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	 	printf("\t     .d88888b.  888      8888888888 888     888      .d88888b.  888     888 8888888 8888888888P      .d8888b.         d8888 888b     d888 8888888888 \n");
	    printf("\t    d88Y\" \"Y88b 888      888        888     888     d88P\" \"Y88b 888     888   888         d88P      d88P  Y88b       d88888 8888b   d8888 888        \n");
	    printf("\t    888     888 888      888        888     888     888     888 888     888   888        d88P       888    888      d88P888 88888b.d88888 888        \n");
	    printf("\t    888     888 888      8888888    888     888     888     888 888     888   888       d88P        888            d88P 888 888Y88888P888 8888888    \n");
	    printf("\t    888     888 888      888        888     888     888     888 888     888   888      d88P         888  88888    d88P  888 888 Y888P 888 888        \n");
		SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		
		usleep(150000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO OUR LADY OF FATIMA UNIVERSITY QUIZ | Powered by: TECHNOCREW\n\n");
		printf ("\t\t\t\t\t\t\t\t   Please enter any key to continue...\n\n\n");
    	SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	 	printf("\t     .d88888b.  888      8888888888 888     888      .d88888b.  888     888 8888888 8888888888P      .d8888b.         d8888 888b     d888 8888888888 \n");
	    printf("\t    d88Y\" \"Y88b 888      888        888     888     d88P\" \"Y88b 888     888   888         d88P      d88P  Y88b       d88888 8888b   d8888 888        \n");
	    printf("\t    888     888 888      888        888     888     888     888 888     888   888        d88P       888    888      d88P888 88888b.d88888 888        \n");
	    printf("\t    888     888 888      8888888    888     888     888     888 888     888   888       d88P        888            d88P 888 888Y88888P888 8888888    \n");
		SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		
		usleep(150000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO OUR LADY OF FATIMA UNIVERSITY QUIZ | Powered by: TECHNOCREW\n\n");
		printf ("\t\t\t\t\t\t\t\t   Please enter any key to continue...\n\n\n");
    	SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	 	printf("\t     .d88888b.  888      8888888888 888     888      .d88888b.  888     888 8888888 8888888888P      .d8888b.         d8888 888b     d888 8888888888 \n");
	    printf("\t    d88Y\" \"Y88b 888      888        888     888     d88P\" \"Y88b 888     888   888         d88P      d88P  Y88b       d88888 8888b   d8888 888        \n");
	    printf("\t    888     888 888      888        888     888     888     888 888     888   888        d88P       888    888      d88P888 88888b.d88888 888        \n");
		SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		
		usleep(150000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO OUR LADY OF FATIMA UNIVERSITY QUIZ | Powered by: TECHNOCREW\n\n");
		printf ("\t\t\t\t\t\t\t\t   Please enter any key to continue...\n\n\n");
    	SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	 	printf("\t     .d88888b.  888      8888888888 888     888      .d88888b.  888     888 8888888 8888888888P      .d8888b.         d8888 888b     d888 8888888888 \n");
	    printf("\t    d88Y\" \"Y88b 888      888        888     888     d88P\" \"Y88b 888     888   888         d88P      d88P  Y88b       d88888 8888b   d8888 888        \n");
		SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		
		usleep(150000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO OUR LADY OF FATIMA UNIVERSITY QUIZ | Powered by: TECHNOCREW\n\n");
		printf ("\t\t\t\t\t\t\t\t   Please enter any key to continue...\n\n\n");
    	SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	 	printf("\t     .d88888b.  888      8888888888 888     888      .d88888b.  888     888 8888888 8888888888P      .d8888b.         d8888 888b     d888 8888888888 \n");
		SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		
		usleep(150000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO OUR LADY OF FATIMA UNIVERSITY QUIZ | Powered by: TECHNOCREW\n\n");
		printf ("\t\t\t\t\t\t\t\t   Please enter any key to continue...\n\n\n");
    	SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		
		usleep(150000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO OUR LADY OF FATIMA UNIVERSITY QUIZ | Powered by: TECHNOCREW\n\n");
    	SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		
		usleep(150000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO OUR LADY OF FATIMA UNIVERSITY QUIZ | Powered by: TECHNOCREW\n\n");
    	SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		
		usleep(150000);
		
		system ("cls");
		system ("color 0F");
    	SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		
		//NEXTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT------------------------------------------------------BATCH
		usleep(150000);
		
		system ("cls");
		system ("color 0F");
		printf ("");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\t\t\t888       d88P   888     888       888   888  Y8P  888   d88P   888 888  Y88888   888     d88P   888 888  Y88888       \"888 Y8P\n");
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\t\t\t888        d88P  888     888       888   888 Y888P 888    d88P  888 888 Y88b888   888      d88P  888 888 Y88b888     \"Y88b. 888\n");
	    printf("\t\t\t888       d88P   888     888       888   888  Y8P  888   d88P   888 888  Y88888   888     d88P   888 888  Y88888       \"888 Y8P\n");
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\t\t\t8888888     d88P 888     888       888   888Y88888P888     d88P 888 888Y88b 888   888       d88P 888 888Y88b 888  \"Y888b.   888\n");
	    printf("\t\t\t888        d88P  888     888       888   888 Y888P 888    d88P  888 888 Y88b888   888      d88P  888 888 Y88b888     \"Y88b. 888\n");
	    printf("\t\t\t888       d88P   888     888       888   888  Y8P  888   d88P   888 888  Y88888   888     d88P   888 888  Y88888       \"888 Y8P\n");
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\t\t\t888          d88P888     888       888   88888b.d88888      d88P888 88888b  888   888        d88P888 88888b  888 Y88b.      888\n");
	    printf("\t\t\t8888888     d88P 888     888       888   888Y88888P888     d88P 888 888Y88b 888   888       d88P 888 888Y88b 888  \"Y888b.   888\n");
	    printf("\t\t\t888        d88P  888     888       888   888 Y888P 888    d88P  888 888 Y88b888   888      d88P  888 888 Y88b888     \"Y88b. 888\n");
	    printf("\t\t\t888       d88P   888     888       888   888  Y8P  888   d88P   888 888  Y88888   888     d88P   888 888  Y88888       \"888 Y8P\n");
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\t\t\t888           d88888     888       888   8888b   d8888       d88888 8888b   888   888         d88888 8888b   888 d88P  Y88b 888\n");
	    printf("\t\t\t888          d88P888     888       888   88888b.d88888      d88P888 88888b  888   888        d88P888 88888b  888 Y88b.      888\n");
	    printf("\t\t\t8888888     d88P 888     888       888   888Y88888P888     d88P 888 888Y88b 888   888       d88P 888 888Y88b 888  \"Y888b.   888\n");
	    printf("\t\t\t888        d88P  888     888       888   888 Y888P 888    d88P  888 888 Y88b888   888      d88P  888 888 Y88b888     \"Y88b. 888\n");
	    printf("\t\t\t888       d88P   888     888       888   888  Y8P  888   d88P   888 888  Y88888   888     d88P   888 888  Y88888       \"888 Y8P\n");
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\t\t\t8888888888     d8888 88888888888 8888888 888b     d888        d8888 888b    888 8888888        d8888 888b    888  .d8888b.  888\n");
	    printf("\t\t\t888           d88888     888       888   8888b   d8888       d88888 8888b   888   888         d88888 8888b   888 d88P  Y88b 888\n");
	    printf("\t\t\t888          d88P888     888       888   88888b.d88888      d88P888 88888b  888   888        d88P888 88888b  888 Y88b.      888\n");
	    printf("\t\t\t8888888     d88P 888     888       888   888Y88888P888     d88P 888 888Y88b 888   888       d88P 888 888Y88b 888  \"Y888b.   888\n");
	    printf("\t\t\t888        d88P  888     888       888   888 Y888P 888    d88P  888 888 Y88b888   888      d88P  888 888 Y88b888     \"Y88b. 888\n");
	    printf("\t\t\t888       d88P   888     888       888   888  Y8P  888   d88P   888 888  Y88888   888     d88P   888 888  Y88888       \"888 Y8P\n");
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
	    
	    system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\n\t\t\t8888888888     d8888 88888888888 8888888 888b     d888        d8888 888b    888 8888888        d8888 888b    888  .d8888b.  888\n");
	    printf("\t\t\t888           d88888     888       888   8888b   d8888       d88888 8888b   888   888         d88888 8888b   888 d88P  Y88b 888\n");
	    printf("\t\t\t888          d88P888     888       888   88888b.d88888      d88P888 88888b  888   888        d88P888 88888b  888 Y88b.      888\n");
	    printf("\t\t\t8888888     d88P 888     888       888   888Y88888P888     d88P 888 888Y88b 888   888       d88P 888 888Y88b 888  \"Y888b.   888\n");
	    printf("\t\t\t888        d88P  888     888       888   888 Y888P 888    d88P  888 888 Y88b888   888      d88P  888 888 Y88b888     \"Y88b. 888\n");
	    printf("\t\t\t888       d88P   888     888       888   888  Y8P  888   d88P   888 888  Y88888   888     d88P   888 888  Y88888       \"888 Y8P\n");
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
	    
	    system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\n\n\t\t\t8888888888     d8888 88888888888 8888888 888b     d888        d8888 888b    888 8888888        d8888 888b    888  .d8888b.  888\n");
	    printf("\t\t\t888           d88888     888       888   8888b   d8888       d88888 8888b   888   888         d88888 8888b   888 d88P  Y88b 888\n");
	    printf("\t\t\t888          d88P888     888       888   88888b.d88888      d88P888 88888b  888   888        d88P888 88888b  888 Y88b.      888\n");
	    printf("\t\t\t8888888     d88P 888     888       888   888Y88888P888     d88P 888 888Y88b 888   888       d88P 888 888Y88b 888  \"Y888b.   888\n");
	    printf("\t\t\t888        d88P  888     888       888   888 Y888P 888    d88P  888 888 Y88b888   888      d88P  888 888 Y88b888     \"Y88b. 888\n");
	    printf("\t\t\t888       d88P   888     888       888   888  Y8P  888   d88P   888 888  Y88888   888     d88P   888 888  Y88888       \"888 Y8P\n");
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
	    
	    system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\n\n\n\t\t\t8888888888     d8888 88888888888 8888888 888b     d888        d8888 888b    888 8888888        d8888 888b    888  .d8888b.  888\n");
	    printf("\t\t\t888           d88888     888       888   8888b   d8888       d88888 8888b   888   888         d88888 8888b   888 d88P  Y88b 888\n");
	    printf("\t\t\t888          d88P888     888       888   88888b.d88888      d88P888 88888b  888   888        d88P888 88888b  888 Y88b.      888\n");
	    printf("\t\t\t8888888     d88P 888     888       888   888Y88888P888     d88P 888 888Y88b 888   888       d88P 888 888Y88b 888  \"Y888b.   888\n");
	    printf("\t\t\t888        d88P  888     888       888   888 Y888P 888    d88P  888 888 Y88b888   888      d88P  888 888 Y88b888     \"Y88b. 888\n");
	    printf("\t\t\t888       d88P   888     888       888   888  Y8P  888   d88P   888 888  Y88888   888     d88P   888 888  Y88888       \"888 Y8P\n");
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
	    
	    system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\n\n\n\n\t\t\t8888888888     d8888 88888888888 8888888 888b     d888        d8888 888b    888 8888888        d8888 888b    888  .d8888b.  888\n");
	    printf("\t\t\t888           d88888     888       888   8888b   d8888       d88888 8888b   888   888         d88888 8888b   888 d88P  Y88b 888\n");
	    printf("\t\t\t888          d88P888     888       888   88888b.d88888      d88P888 88888b  888   888        d88P888 88888b  888 Y88b.      888\n");
	    printf("\t\t\t8888888     d88P 888     888       888   888Y88888P888     d88P 888 888Y88b 888   888       d88P 888 888Y88b 888  \"Y888b.   888\n");
	    printf("\t\t\t888        d88P  888     888       888   888 Y888P 888    d88P  888 888 Y88b888   888      d88P  888 888 Y88b888     \"Y88b. 888\n");
	    printf("\t\t\t888       d88P   888     888       888   888  Y8P  888   d88P   888 888  Y88888   888     d88P   888 888  Y88888       \"888 Y8P\n");
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    printf("\t\t\t\t\t    888P     Y888 8888888888 88888888 \"Y8888P\"   \"Y88888P\"  888       888 8888888888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\n\n\n\n\t\t\t8888888888     d8888 88888888888 8888888 888b     d888        d8888 888b    888 8888888        d8888 888b    888  .d8888b.  888\n");
	    printf("\t\t\t888           d88888     888       888   8888b   d8888       d88888 8888b   888   888         d88888 8888b   888 d88P  Y88b 888\n");
	    printf("\t\t\t888          d88P888     888       888   88888b.d88888      d88P888 88888b  888   888        d88P888 88888b  888 Y88b.      888\n");
	    printf("\t\t\t8888888     d88P 888     888       888   888Y88888P888     d88P 888 888Y88b 888   888       d88P 888 888Y88b 888  \"Y888b.   888\n");
	    printf("\t\t\t888        d88P  888     888       888   888 Y888P 888    d88P  888 888 Y88b888   888      d88P  888 888 Y88b888     \"Y88b. 888\n");
	    printf("\t\t\t888       d88P   888     888       888   888  Y8P  888   d88P   888 888  Y88888   888     d88P   888 888  Y88888       \"888 Y8P\n");
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    printf("\t\t\t\t\t    8888P   Y8888 888        888     Y88b  d88P Y88b. .d88P 888   \"   888 888\n");
	    printf("\t\t\t\t\t    888P     Y888 8888888888 88888888 \"Y8888P\"   \"Y88888P\"  888       888 8888888888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\n\n\n\n\t\t\t8888888888     d8888 88888888888 8888888 888b     d888        d8888 888b    888 8888888        d8888 888b    888  .d8888b.  888\n");
	    printf("\t\t\t888           d88888     888       888   8888b   d8888       d88888 8888b   888   888         d88888 8888b   888 d88P  Y88b 888\n");
	    printf("\t\t\t888          d88P888     888       888   88888b.d88888      d88P888 88888b  888   888        d88P888 88888b  888 Y88b.      888\n");
	    printf("\t\t\t8888888     d88P 888     888       888   888Y88888P888     d88P 888 888Y88b 888   888       d88P 888 888Y88b 888  \"Y888b.   888\n");
	    printf("\t\t\t888        d88P  888     888       888   888 Y888P 888    d88P  888 888 Y88b888   888      d88P  888 888 Y88b888     \"Y88b. 888\n");
	    printf("\t\t\t888       d88P   888     888       888   888  Y8P  888   d88P   888 888  Y88888   888     d88P   888 888  Y88888       \"888 Y8P\n");
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    printf("\t\t\t\t\t    88888P Y88888 888        888     888    888 888     888 888  Y8P  888 888\n");
	    printf("\t\t\t\t\t    8888P   Y8888 888        888     Y88b  d88P Y88b. .d88P 888   \"   888 888\n");
	    printf("\t\t\t\t\t    888P     Y888 8888888888 88888888 \"Y8888P\"   \"Y88888P\"  888       888 8888888888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\n\n\n\n\t\t\t8888888888     d8888 88888888888 8888888 888b     d888        d8888 888b    888 8888888        d8888 888b    888  .d8888b.  888\n");
	    printf("\t\t\t888           d88888     888       888   8888b   d8888       d88888 8888b   888   888         d88888 8888b   888 d88P  Y88b 888\n");
	    printf("\t\t\t888          d88P888     888       888   88888b.d88888      d88P888 88888b  888   888        d88P888 88888b  888 Y88b.      888\n");
	    printf("\t\t\t8888888     d88P 888     888       888   888Y88888P888     d88P 888 888Y88b 888   888       d88P 888 888Y88b 888  \"Y888b.   888\n");
	    printf("\t\t\t888        d88P  888     888       888   888 Y888P 888    d88P  888 888 Y88b888   888      d88P  888 888 Y88b888     \"Y88b. 888\n");
	    printf("\t\t\t888       d88P   888     888       888   888  Y8P  888   d88P   888 888  Y88888   888     d88P   888 888  Y88888       \"888 Y8P\n");
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    printf("\t\t\t\t\t    888d88888b888 888        888     888        888     888 888 Y888P 888 888\n");
	    printf("\t\t\t\t\t    88888P Y88888 888        888     888    888 888     888 888  Y8P  888 888\n");
	    printf("\t\t\t\t\t    8888P   Y8888 888        888     Y88b  d88P Y88b. .d88P 888   \"   888 888\n");
	    printf("\t\t\t\t\t    888P     Y888 8888888888 88888888 \"Y8888P\"   \"Y88888P\"  888       888 8888888888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\n\n\n\n\t\t\t8888888888     d8888 88888888888 8888888 888b     d888        d8888 888b    888 8888888        d8888 888b    888  .d8888b.  888\n");
	    printf("\t\t\t888           d88888     888       888   8888b   d8888       d88888 8888b   888   888         d88888 8888b   888 d88P  Y88b 888\n");
	    printf("\t\t\t888          d88P888     888       888   88888b.d88888      d88P888 88888b  888   888        d88P888 88888b  888 Y88b.      888\n");
	    printf("\t\t\t8888888     d88P 888     888       888   888Y88888P888     d88P 888 888Y88b 888   888       d88P 888 888Y88b 888  \"Y888b.   888\n");
	    printf("\t\t\t888        d88P  888     888       888   888 Y888P 888    d88P  888 888 Y88b888   888      d88P  888 888 Y88b888     \"Y88b. 888\n");
	    printf("\t\t\t888       d88P   888     888       888   888  Y8P  888   d88P   888 888  Y88888   888     d88P   888 888  Y88888       \"888 Y8P\n");
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    printf("\t\t\t\t\t    888 d888b 888 8888888    888     888        888     888 888Y88888P888 8888888\n");
	    printf("\t\t\t\t\t    888d88888b888 888        888     888        888     888 888 Y888P 888 888\n");
	    printf("\t\t\t\t\t    88888P Y88888 888        888     888    888 888     888 888  Y8P  888 888\n");
	    printf("\t\t\t\t\t    8888P   Y8888 888        888     Y88b  d88P Y88b. .d88P 888   \"   888 888\n");
	    printf("\t\t\t\t\t    888P     Y888 8888888888 88888888 \"Y8888P\"   \"Y88888P\"  888       888 8888888888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\n\n\n\n\t\t\t8888888888     d8888 88888888888 8888888 888b     d888        d8888 888b    888 8888888        d8888 888b    888  .d8888b.  888\n");
	    printf("\t\t\t888           d88888     888       888   8888b   d8888       d88888 8888b   888   888         d88888 8888b   888 d88P  Y88b 888\n");
	    printf("\t\t\t888          d88P888     888       888   88888b.d88888      d88P888 88888b  888   888        d88P888 88888b  888 Y88b.      888\n");
	    printf("\t\t\t8888888     d88P 888     888       888   888Y88888P888     d88P 888 888Y88b 888   888       d88P 888 888Y88b 888  \"Y888b.   888\n");
	    printf("\t\t\t888        d88P  888     888       888   888 Y888P 888    d88P  888 888 Y88b888   888      d88P  888 888 Y88b888     \"Y88b. 888\n");
	    printf("\t\t\t888       d88P   888     888       888   888  Y8P  888   d88P   888 888  Y88888   888     d88P   888 888  Y88888       \"888 Y8P\n");
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    printf("\t\t\t\t\t    888  d8b  888 888        888     888    888 888     888 88888b.d88888 888\n");
	    printf("\t\t\t\t\t    888 d888b 888 8888888    888     888        888     888 888Y88888P888 8888888\n");
	    printf("\t\t\t\t\t    888d88888b888 888        888     888        888     888 888 Y888P 888 888\n");
	    printf("\t\t\t\t\t    88888P Y88888 888        888     888    888 888     888 888  Y8P  888 888\n");
	    printf("\t\t\t\t\t    8888P   Y8888 888        888     Y88b  d88P Y88b. .d88P 888   \"   888 888\n");
	    printf("\t\t\t\t\t    888P     Y888 8888888888 88888888 \"Y8888P\"   \"Y88888P\"  888       888 8888888888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\n\n\n\n\t\t\t8888888888     d8888 88888888888 8888888 888b     d888        d8888 888b    888 8888888        d8888 888b    888  .d8888b.  888\n");
	    printf("\t\t\t888           d88888     888       888   8888b   d8888       d88888 8888b   888   888         d88888 8888b   888 d88P  Y88b 888\n");
	    printf("\t\t\t888          d88P888     888       888   88888b.d88888      d88P888 88888b  888   888        d88P888 88888b  888 Y88b.      888\n");
	    printf("\t\t\t8888888     d88P 888     888       888   888Y88888P888     d88P 888 888Y88b 888   888       d88P 888 888Y88b 888  \"Y888b.   888\n");
	    printf("\t\t\t888        d88P  888     888       888   888 Y888P 888    d88P  888 888 Y88b888   888      d88P  888 888 Y88b888     \"Y88b. 888\n");
	    printf("\t\t\t888       d88P   888     888       888   888  Y8P  888   d88P   888 888  Y88888   888     d88P   888 888  Y88888       \"888 Y8P\n");
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    printf("\t\t\t\t\t    888   o   888 888        888     d88P  Y88b d88P\" \"Y88b 8888b   d8888 888\n");
	    printf("\t\t\t\t\t    888  d8b  888 888        888     888    888 888     888 88888b.d88888 888\n");
	    printf("\t\t\t\t\t    888 d888b 888 8888888    888     888        888     888 888Y88888P888 8888888\n");
	    printf("\t\t\t\t\t    888d88888b888 888        888     888        888     888 888 Y888P 888 888\n");
	    printf("\t\t\t\t\t    88888P Y88888 888        888     888    888 888     888 888  Y8P  888 888\n");
	    printf("\t\t\t\t\t    8888P   Y8888 888        888     Y88b  d88P Y88b. .d88P 888   \"   888 888\n");
	    printf("\t\t\t\t\t    888P     Y888 8888888888 88888888 \"Y8888P\"   \"Y88888P\"  888       888 8888888888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\n\n\n\n\t\t\t8888888888     d8888 88888888888 8888888 888b     d888        d8888 888b    888 8888888        d8888 888b    888  .d8888b.  888\n");
	    printf("\t\t\t888           d88888     888       888   8888b   d8888       d88888 8888b   888   888         d88888 8888b   888 d88P  Y88b 888\n");
	    printf("\t\t\t888          d88P888     888       888   88888b.d88888      d88P888 88888b  888   888        d88P888 88888b  888 Y88b.      888\n");
	    printf("\t\t\t8888888     d88P 888     888       888   888Y88888P888     d88P 888 888Y88b 888   888       d88P 888 888Y88b 888  \"Y888b.   888\n");
	    printf("\t\t\t888        d88P  888     888       888   888 Y888P 888    d88P  888 888 Y88b888   888      d88P  888 888 Y88b888     \"Y88b. 888\n");
	    printf("\t\t\t888       d88P   888     888       888   888  Y8P  888   d88P   888 888  Y88888   888     d88P   888 888  Y88888       \"888 Y8P\n");
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    usleep(110000);
		
		system ("cls");
		system ("color 0F");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t    888       888 8888888888 888      .d8888b.   .d88888b.  888b     d888 8888888888\n");
	    printf("\t\t\t\t\t    888   o   888 888        888     d88P  Y88b d88P\" \"Y88b 8888b   d8888 888\n");
	    printf("\t\t\t\t\t    888  d8b  888 888        888     888    888 888     888 88888b.d88888 888\n");
	    printf("\t\t\t\t\t    888 d888b 888 8888888    888     888        888     888 888Y88888P888 8888888\n");
	    printf("\t\t\t\t\t    888d88888b888 888        888     888        888     888 888 Y888P 888 888\n");
	    printf("\t\t\t\t\t    88888P Y88888 888        888     888    888 888     888 888  Y8P  888 888\n");
	    printf("\t\t\t\t\t    8888P   Y8888 888        888     Y88b  d88P Y88b. .d88P 888   \"   888 888\n");
	    printf("\t\t\t\t\t    888P     Y888 8888888888 88888888 \"Y8888P\"   \"Y88888P\"  888       888 8888888888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("\n\n\n\n\t\t\t8888888888     d8888 88888888888 8888888 888b     d888        d8888 888b    888 8888888        d8888 888b    888  .d8888b.  888\n");
	    printf("\t\t\t888           d88888     888       888   8888b   d8888       d88888 8888b   888   888         d88888 8888b   888 d88P  Y88b 888\n");
	    printf("\t\t\t888          d88P888     888       888   88888b.d88888      d88P888 88888b  888   888        d88P888 88888b  888 Y88b.      888\n");
	    printf("\t\t\t8888888     d88P 888     888       888   888Y88888P888     d88P 888 888Y88b 888   888       d88P 888 888Y88b 888  \"Y888b.   888\n");
	    printf("\t\t\t888        d88P  888     888       888   888 Y888P 888    d88P  888 888 Y88b888   888      d88P  888 888 Y88b888     \"Y88b. 888\n");
	    printf("\t\t\t888       d88P   888     888       888   888  Y8P  888   d88P   888 888  Y88888   888     d88P   888 888  Y88888       \"888 Y8P\n");
	    printf("\t\t\t888      d8888888888     888       888   888   \"   888  d8888888888 888   Y8888   888    d8888888888 888   Y8888 Y88b  d88P  \"\n");
	    printf("\t\t\t888     d88P     888     888     8888888 888       888 d88P     888 888    Y888 8888888 d88P     888 888    Y888  \"Y8888P\"  888\n");
	    SetConsoleTextAttribute(TechnocrewConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    
	    sleep(5);
	}
	
	/* 
		printf (" \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t=====================================\n");							
		printf ("\t\t\t\t\t\t\t\t         LOG IN TO YOUR ACCOUNT\n");
		printf (" \t\t\t\t\t\t\t\t=====================================\n\n");
		
		1_____Blue                                     A______Light Green
		2_____Green                                    B______Light Aqua
		3_____Aqua                                     C______Light Red
		4_____Red                                      D______Light Purple
		5_____Purple                                   E______Light Yellow
		6_____Yellow                                   F______Bright White 
		7_____White
		8_____Gray
		9_____Light Blue
		0_____Black		
	*/
	
