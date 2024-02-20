#include <stdio.h> 
#include <stdlib.h> 
#include <windows.h> 
#include <math.h> 
#include<string.h> 
#include<conio.h> 
#define PI 3.14159 // pi
#define e 2.71828 // constant e

// Variables
int global_choice=10,i,choice,hold=1,set=0;
float return_Value=0,exponent=0;
float given,givenIn;
float temp[3]={0,0,0},conv[6];
float weight,volume,time;
char global_string[10],choice_string;

// functions 		
void gotoxy(short x, short y); // puts the mouse cursor to a specific coordinates
void coords(short x,short y); // gets the coordinates
void short_Title(); // shows coleen screen
void screen(); // screen size
float basic_cal(float basic_proc); // BASIC 
float sci_cal(); // SCI 
float lifeStyle_cal(int global_choice=0); // unit converter , compound and average calculator
int stat_Screen(); // shows temporary values stored
int restart_proc(); // asks the user to restart or do another computation
int conv_cal(); // stores converted values to return_Value
int aboutScreen(); // displays our aBout screen
int data_Checker(); // checks if theres an temporary answer stored
int print_Ans(); // Prints answer

//Files

FILE *ptr=fopen("history.log","a+");
void read();

int main(){
	
	screen();
	short_Title();
	stat_Screen();
	printf("\n %33s%50s%54s%55s%39s%38s%40s","Menu:\n","[1] Basic Calculator\n","[2] Lifestyle Calculator\n","[3] Scientific Calculator\n","[4] About\n","[5] Exit\n","Type Here: ");
	scanf("%d",&choice);
	system("cls");
	switch(choice) /*main menu switch*/{
		
		case 1: // basic calculator
		short_Title();
		printf("\n%54s","How Many Numbers to compute?: ");
		scanf("%f",&given);
			if(hold==0){
		data_Checker();
				system("cls");
		}
		system("cls");
		short_Title();
		printf("\n %32s %42s %45s %48s %42s %38s %40s","Menu:\n","[A] Addition\n","[S] Subtraction\n","[M] Multiplication\n","[D] Division\n","[B] Back\n","Type Here: ");
		scanf("%s",&choice_string);
		switch(choice_string)
		{
			case 'a':
			case 'A': // Basic For Loop Add
			global_choice=1;
			break;
			case 'b': 
			case 'B':
				main();
			case 's':
			case 'S': // Basic For Minus
			global_choice=2;
			break;
			
			case 'm':
			case 'M': // Basic while multiply
			global_choice=3;
			break;
			
			case 'd':
			case 'D': // Basic For Division
			global_choice=4;
			break;
		} // end switch basic calculator 
			basic_cal(given);
		break; // end case 1
		
	case 2: // lifestyle calculator
			short_Title();
			printf("\n %34s %52s %54s %42s %38s %39s","Menu:\n","[1] Average Calculator\n","[2] Compound Calculator\n ","[3] Converter\n","[4] Back\n","Type Here: ");
			scanf("%d",&choice);
			switch(choice){
				case 1: // Average 
				lifeStyle_cal(global_choice=1);
				break;
				case 2: // Compound
				lifeStyle_cal(global_choice=2);
				break;
				case 3: // converter
				lifeStyle_cal(global_choice=3);
				break;
				case 4: // back
				main();
				break;
			}
		break; // end case 2
	case 3: // scientific cal
			short_Title();
			printf("\n %50s %44s %37s","Scientific Calculator:\n\n","Type [BEGIN/BACK]\n"," Type here: ");
			scanf("%s",global_string);	
			if(strcmp(global_string,"BEGIN")==0||strcmp(global_string,"begin")==0){
			sci_cal();
		   }	
		 	if(strcmp(global_string,"back")==0||strcmp(global_string,"BACK")==0){
			main();
		   }
			else{restart_proc();}
			break; // end case 3
			
	case 4: //about
			aboutScreen();
	case 5:
			exit(0);
			break;
	case 6:
			printf("\n [L] Long Screen [S] Short Screen [H] History");
			scanf("%s",choice_string);
			switch(choice_string) {
				case 'h' :
				case 'H':
							printf("\n History Of Final Answers:\n");
							read();
							fclose(ptr);
							system("pause");
							system("cls");
							main();
				case 'l' :
				case 'L' :
							screen();
							system("pause");
							main();
				case 's' :
				case 'S' :
							screen();
							system("pause");
							main();
				default:
							restart_proc();
				} 
	restart_proc();
	}// end main menu switch
	return 0;
	}

// BASIC CALCULATOR

float basic_cal(float basic_proc){
	if(global_choice==1){ //start if 1
		for(i=1;i<=basic_proc;i++){
		printf("\n\t\t\tPlease Input #%d Value to add\n\t\t\tType here: ",i);
		scanf("%f",&givenIn);
		return_Value=return_Value+givenIn;}
		
		} //end if 1
	if(global_choice==2){ //start if 2
		for(i=1;i<=basic_proc;i++){
			printf("\n\t\t\tPlease input #%d Value to Subtract\n\t\t\tFormat: Answer= 1st Given - 2nd Given\n\t\t\tType Here: ",i);
			scanf("%f",&givenIn);
			//	if(return_Value!=0){
				return_Value=givenIn-return_Value; //}
			//	else{
				/*return_Value=givenIn-return_Value;}*/
				}}
		if(global_choice==3){
			for (i=1;i<=basic_proc;i++){
				printf("\n\t\t\tPlease input #%d value to Multiply\n\t\t\tType Here: ",i);
				scanf("%f",&givenIn);
				if(return_Value==0){
					return_Value=givenIn*1; }
					else{ return_Value=return_Value*givenIn; }
			}}
			if(global_choice==4){ //  global 4
				for(i=1;i<=basic_proc;i++){
					printf("\n\t\t\tPlease input #%d value to divide: ",i);
					scanf("%f",&givenIn);
					if(return_Value==0){
						return_Value=givenIn/1;
						}
					else{return_Value=return_Value/givenIn;}
					}
			}// end for global choice 4
	print_Ans();
	restart_proc();	
	}
	
// life style cal
	
float lifeStyle_cal(int global_choice){
	
	float principal,rate,time,year,amount;
	if(global_choice==1){
		float nos[100];
		printf("\n\t\t\tEnter How Many Values?: ");
		scanf("%d",&choice);
		while(choice>9999||choice<=0){
			printf("\n\t\t\tRange must be from 0 to 9999!\n\t\t\Enter new value: ");
			scanf("%d",&choice); }
		for(i=1;i<=choice;++i){
			printf("\n\t\t\tEnter #%d Value: ",i);
			scanf("%f",&nos[i]);
			return_Value += nos[i]; }
		return_Value= return_Value / choice;
	}
	
	if(global_choice==2){
		printf("\n\t\t\tWhich value you would like to find?");
		printf("\n%40s\n%43s\n%38s\n%39s","[A] Amount","[P] Principal","[R] Rate","Type Here:" );
		scanf("%s",&choice_string);
		switch(choice_string){
			case 'a':
			case 'A':
				printf("Enter value for principal, rate, and time respectively: \n");
				scanf("%f %f %f",&principal,&rate,&time);
				printf("How many compounds a year do you want?: ");
				scanf("%f", &year);
				return_Value=1+(rate/year);
				return_Value=principal*pow(return_Value,year*time);
				break;
			case 'p':
			case 'P':
				printf("Enter value for amount, rate, and time respectively: \n");
				scanf("%f %f %f", &amount,&rate,&time);
				printf("How many compounds a year do you want?: ");
				scanf("%2f", &year);
				return_Value=1+(rate/year);
				return_Value=amount/(pow(return_Value,year*time));
				break;
			case 'r':
			case 'R':
				printf("Enter value for principal, amount, and time respectively: \n");
				scanf("%f %f %f",&principal,&amount,&time);
				printf("How many compounds a year do you want?: ");
				scanf("%2f",&year);
				return_Value=amount/principal;
				return_Value=year*(pow(return_Value,1/year*time)-1);
				break;
			default:
				restart_proc(); } // end switch
	}
	
	if(global_choice==3){
			printf("\nEnter value to be converted: ");
				if(hold==0){
				data_Checker();}
				if(choice==7||hold!=0){
				scanf("%f",&return_Value);
				}
				printf("\nWhich units you wanted to convert to?: ");
				printf("\n[WEIGHT] [VOLUME] [TIME]: ");
				scanf("%s",global_string);
				if(strcmp(global_string,"WEIGHT")==0||strcmp(global_string,"weight")==0){
					printf("\nWhat Unit did you inputted? Mg/g/Kg: "); scanf("%s",global_string);
					if(strcmp(global_string,"MG")==0||strcmp(global_string,"mg")==0){
					printf("\nValue Equivalence:\n[0]Mg: %.2f\n[1]Grams: %.2f\n[2]Kg: %.2f\nWhich Value you would like to use?: ",conv[0]=return_Value,conv[1]=return_Value/1000,conv[2]=conv[1]*1000);
					conv_cal();
				}// MG
					if(strcmp(global_string,"G")==0||strcmp(global_string,"g")==0){
					printf("\nValue Equivalence:\n[0]Mg: %.2f\n[1]Grams: %.2f\n[2]Kg: %.2f\nWhich Value you would like to use?: ",conv[0]=return_Value*1000,conv[1]=return_Value,conv[2]=return_Value/1000);
					conv_cal();
				}// G
				if(strcmp(global_string,"KG")==0||strcmp(global_string,"kg")==0){
					printf("\nValue Equivalence:\n[0]Mg: %.8f\n[1]Grams: %.2f\n[2]Kg: %.8f\nWhich Value you would like to use?: ",conv[0]=return_Value/1000000,conv[1]=return_Value*1000,conv[2]=return_Value);
					conv_cal();
				}// KG
				} // END WEIGHT
				if(strcmp(global_string,"VOLUME")==0||strcmp(global_string,"volume")==0){
						printf("\nWhat Unit did you inputted? ML/L: "); scanf("%s",global_string);
					if(strcmp(global_string,"ML")==0||strcmp(global_string,"ml")==0){
					printf("\nValue Equivalence:\n[0]ML: %.2f\n[1]Liters: %.2f\nWhich Value you would like to use?: ",conv[0]=return_Value,conv[1]=return_Value/1000);
					conv_cal();
				}// ML
					if(strcmp(global_string,"L")==0||strcmp(global_string,"l")==0){
					printf("\nValue Equivalence:\n[0]ML: %.2f\n[1]Liters: %.2f\nWhich Value you would like to use?: ",conv[0]=return_Value*1000,conv[1]=return_Value);
					conv_cal();
				}// L
				} // END VOLUME
				if(strcmp(global_string,"TIME")==0||strcmp(global_string,"time")==0){
						printf("\nWhat Unit did you inputted? MS/S/HR: "); scanf("%s",global_string);
					if(strcmp(global_string,"MS")==0||strcmp(global_string,"ms")==0){
					printf("\nValue Equivalence:\n[0]Ms: %.2f\n[1]Seconds: %.2f\n[2]Hour: %.28f\nWhich Value you would like to use?: ",conv[0]=return_Value,time=conv[1]=return_Value/1000,conv[2]=time*0.000000277778);
					conv_cal();
				}// Ms
					if(strcmp(global_string,"S")==0||strcmp(global_string,"s")==0){
					printf("\nValue Equivalence:\n[0]Ms: %.2f\n[1]Seconds: %.2f\n[2]Hour: %.2f\nWhich Value you would like to use?: ",conv[0]=return_Value*1000,conv[1]=return_Value,conv[2]=return_Value/3600);
					conv_cal();
				}// Seconds
				if(strcmp(global_string,"HR")==0||strcmp(global_string,"hr")==0){
					printf("\nValue Equivalence:\n[0]Ms: %.2f\n[1]Seconds: %.2f\n[2]Hour: %.2f\nWhich Value you would like to use?: ",conv[0]=return_Value*3600000,conv[1]=return_Value*3600,conv[2]=return_Value);
					scanf("%d",&choice);
					conv_cal();
					
				}// hr
				} // END TIME
				
	} // END CONVERTER
	print_Ans();
	restart_proc();
	}

int conv_cal(){
	
	scanf("%d",&choice);
	switch(choice){
		case 0:
			return_Value=conv[0];
			break;
		case 1:
			return_Value=conv[1];
			break;
		case 2:
			return_Value=conv[2];
			break;
		default:
			restart_proc();
			}
}
	
float sci_cal(){
	/* processes and computations involving non-math.h codes, specifically average calculator,compound interest and other
	loopable conoutations */
	float fact = 1; 
	printf("\n%54s","Type the value you wish to compute: ");
	if(hold!=0){
	scanf("%f",&return_Value);}
	if(hold==0){
	data_Checker();
	short_Title();
	}
	printf("\n*Dev Note: Please Refer to the commands for available computations!*\nType the corresponding variable: ");
	scanf("%s",global_string);
		if(strcmp(global_string,"e")==0||strcmp(global_string,"E")==0){
			printf("\nWhere does the constant 'e' will be? [1]Numerator or [1]Denaminator?: ");
					scanf("%d",&choice);
					switch(choice){
						case 1:
						return_Value=e/return_Value;
						break;
						case 2:
						return_Value=return_Value/e;
						break;
						default:
						restart_proc(); } // end division switch
		}
		if(strcmp(global_string,"PI")==0||strcmp(global_string,"pi")==0){
			printf("\nWhat Operation? [1]Add [2]Sub [3]Multiply [4]Division: ");
			scanf("%d",&choice);
			switch(choice){
				case 1:
					return_Value=return_Value+PI;
					break;
				case 2:
					return_Value=return_Value-PI;
					break;
				case 3:
					return_Value=return_Value*PI;
					break;
				case 4:
					printf("\nWhere does the PI will be? [1]Numerator or [2]Denaminator?: ");
					scanf("%d",&choice);
					if(choice==1){
						return_Value=PI/return_Value;}
					if(choice==2){
						return_Value=return_Value/PI;}
					break;
				default:
					restart_proc();}
						} // end PI
		if(strcmp(global_string,"LOG")==0||strcmp(global_string,"log")==0){
			return_Value=log(return_Value);}
		if(strcmp(global_string,"LOG10")==0||strcmp(global_string,"log10")==0){
			return_Value=log10(return_Value);}
		if(strcmp(global_string,"SQRT")==0||strcmp(global_string,"sqrt")==0){
			return_Value=sqrt(return_Value);}
		if(strcmp(global_string,"CBRT")==0||strcmp(global_string,"cbrt")==0){
			return_Value=cbrt(return_Value);}
		if(strcmp(global_string,"SIN")==0||strcmp(global_string,"sin")==0){
		return_Value=sin(return_Value);}
		if(strcmp(global_string,"SINH")==0||strcmp(global_string,"sinh")==0){
		return_Value=sinh(return_Value);}
		if(strcmp(global_string,"COS")==0||strcmp(global_string,"cos")==0){
		return_Value=cos(return_Value);}
		if(strcmp(global_string,"COSH")==0||strcmp(global_string,"cosh")==0){
		return_Value=cos(return_Value);}
		if(strcmp(global_string,"TAN")==0||strcmp(global_string,"tan")==0){
		return_Value=tan(return_Value);}
		if(strcmp(global_string,"TANH")==0||strcmp(global_string,"tanh")==0){
		return_Value=tan(return_Value);}
		if(strcmp(global_string,"POWER")==0||strcmp(global_string,"power")==0){
		printf("\n\t\t\t\t   %f raise to? ",return_Value);
		scanf("%f",&exponent);
		return_Value=pow(return_Value,exponent);}
		if(strcmp(global_string,"FACTOR")==0||strcmp(global_string,"factor")==0){
			if(return_Value<0){
				printf("%46s","Negative Number not allowed!"); }
			else{ for(i=1;i<=return_Value;i++){
				fact=fact*i; } } return_Value=fact;}
		
	print_Ans();
	restart_proc();
	 }
	 
// SYSTEM PROCESS/TRANSACTIONS

// RESTART CHOICE / RESTART USER DESICION

int restart_proc(){
	printf("\n\t\t   Do Another Computation? YES/NO/HOLD: ");
	scanf("%s",global_string);
	if(strcmp(global_string,"YES")==0||strcmp(global_string,"yes")==0)
	{
		system("cls");
		return_Value=0;
		main();} // END YES
	if(strcmp(global_string,"HOLD")==0||strcmp(global_string,"hold")==0){
		
			printf("\n\t\tStore the value?\n\t\t\tCurrent Values stored:\n\t\t\t");
			for(i=0;i<3;i++){
				printf("[%d] %.2f ",i,temp[i]);}
			printf("\n\t\t\tYES/NO?: ");
			scanf("%s",global_string);
			if(strcmp(global_string,"YES")==0||strcmp(global_string,"yes")==0){
				
				if(return_Value!=0){
					printf("\n\t\t\tStore on 1?: ");
					scanf("%s",global_string);
					 if(strcmp(global_string,"yes")==0||strcmp(global_string,"YES")==0){
					temp[0]=return_Value;}
				
					}// temp 0
					
				if(return_Value!=0){
					printf("\n\t\t\tStore on 2?: ");
					scanf("%s",global_string);
					 if(strcmp(global_string,"yes")==0||strcmp(global_string,"YES")==0){
					temp[1]=return_Value;}
					}// temp 1
					
				if(return_Value!=0){
					printf("\n\t\t\tStore on 3?: ");
					scanf("%s",global_string);
					 if(strcmp(global_string,"yes")==0||strcmp(global_string,"YES")==0){
					temp[2]=return_Value;}
					}// temp 2
						return_Value=0;
						main();
								}// choice yes
					} // END HOLD
	if(strcmp(global_string,"NO")==0||strcmp(global_string,"no")==0){
			  exit(0);	
			  }
}

// ANSWER HOLDER CHECKER / DATA CHECKER

int data_Checker(){
	
	if(temp[0]!=0||temp[1]!=0||temp[2]!=0){
		printf("\n\t\tUse Previous Answers? YES/NO: ");
		scanf("%s",global_string);
		if(strcmp(global_string,"yes")==0||strcmp(global_string,"YES")==0){
		printf("\n\t\t\tWhich Value?:\n");
			for(i=0;i<3;i++){
				printf(" [%d]:%.2f ",i,temp[i]);
				} // for print
				printf(": ");
				scanf("%d",&choice);
				switch(choice)
				{
					case 0:
						return_Value=temp[0];
						break;
					case 1:
						return_Value=temp[1];
						break;
					case 2:
						return_Value=temp[2];
						break;
					default:
						exit(0);
						break;
				}//end case

			}// if yes
	else {
			choice=7;
		}
		}// if temp
		system("cls");
	}// end checker
	
// ABOUT SCREEN

int aboutScreen(){
	int i,j;
	//FIRST C
   for(i=15,j=2;i>=10;i--){
   coords(i,j);
   }

   for(i=10,j=2;j<=6;j++){
   	coords(i,j);
  }

   for(i=10,j=6;i<=15;i++){
   	coords(i,j);
   }
   
   // LETTER O
   
   for(i=25,j=2;i>=20;i--){
   coords(i,j);}
   
    for(i=20,j=2;j<=6;j++){
   	coords(i,j);
   }
   
   for(i=20,j=6;i<=25;i++){
   coords(i,j);}
   
   for(i=25,j=6;j>=2;j--){
   	coords(i,j);
   }
   
   // LETTER L
   for(i=30,j=2;j<=6;j++){
   	coords(i,j);
   }
   
   for(i=30,j=6;i<=35;i++){
   coords(i,j);}
   
   // LETTER E
     for(i=43,j=2;i>=38;i--){
   coords(i,j);}
   
    for(i=43,j=4;i>=38;i--){
   coords(i,j);}
   
   for(i=43,j=6;i>=38;i--){
   coords(i,j);}
   
   for(i=38,j=2;j<=6;j++){
   	coords(i,j);}
   
   // LETTER 2nd E
     for(i=52,j=2;i>=47;i--){
   coords(i,j);}
   
    for(i=52,j=4;i>=47;i--){
   coords(i,j);}
   
   for(i=52,j=6;i>=47;i--){
   coords(i,j);}
   
   for(i=47,j=2;j<=6;j++){
   	coords(i,j);}
   
   // LETTER N
   for(i=63,j=2;j<=6;j++){
   coords(i,j);}
   
   for(i=57,j=6;j>=2;j--){
   coords(i,j);}
   
   for(i=57,j=2;j<=6,i<=61;j++,i++){
   coords(i,j);
   }
   
   //finishing touches
    for(i=7,j=7;j>=0;j--)
  {
   Sleep(30);
   gotoxy(i,j);
   printf("\xDB");
  }
   for(i=7,j=0;i<=66;i++)
  {
   Sleep(30);
   gotoxy(i,j);
   printf("\xDB");
  }
   for(i=66,j=0;j<=8;j++)
  {
   Sleep(30);
   gotoxy(i,j);
   printf("\xDB");
  }
   for(j=8,i=66;i>=7;i--)
  {
  	Sleep(30);
   gotoxy(i,j);
   printf("\xDB");
  } 
	printf("\n%56s","CPE007 - Programming Logic and Design ");
	Sleep(20);
	printf("\n\n%54s","COLEEN - Calculator Ol Een One! ");
	Sleep(20);
	printf("\n%43s\n%46s\n%48s\n%46s\n%52s","Members:","Betita, Eugene","Gappi,Jeric Marcel","Ignacio,Carlo","Ronquillo,Josephino Lance\n");
	Sleep(20);
	system("pause");
	main();
}

// THIS SECTION APPEARS WHEN A AN ANSWER IS TEMPORARY HOLDED

int stat_Screen(){
	if(temp[0]!=0||temp[1]!=0||temp[2]!=0){
		printf("ANSWER TEMPORARY HOLDED :\n");
		hold=0;
		for(i=0;i<3;i++){
		printf(" %.2f",temp[i]);}
			}//end tempo stat
}
	
//  COORDINATES FINDER

void gotoxy(short x, short y)           //definition of gotoxy function//                                               
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void coords(short x,short y){
	Sleep(10);
   gotoxy(x,y);
   printf("\xDB");
}

// functions to lessen lines

void short_Title(){
	for(int i=1;i<=75;++i){
		printf("\xC2");	}
	printf("%46s", "C-O-L-EEN ONE\n");
	for(int i=1;i<=75;++i){
		printf("\xC1");	}
}

int print_Ans(){
	printf("\n");
	for(int i=1;i<=75;++i){
		printf("\xC2");	}
	printf("\nAnswer is: %.8f\n",return_Value);
	for(int i=1;i<=75;++i){
		printf("\xC1");	}
}

void read(){
	fprintf(ptr,"%.6f\n",return_Value);
	fclose(ptr);
	ptr = fopen("history.log","r");
	char read[9999];
	while(fgets(read,sizeof(read),ptr)!=NULL){
		printf("%s",read);
		}
	fclose(ptr);
	}
	
void screen(){
	system("cls");
	system("title=COLEEN ONE");
	system("color F0");
	if(set==0){
	system("mode con: cols=75 lines=20");}
	if(set==1){
	system("mode con: cols=75 lines=40");}
	} 
