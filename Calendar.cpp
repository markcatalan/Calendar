#include <iostream>
#include <string>
#include <iomanip>
#include <cassert> //#define NDEBUG --> place before the #cassert to disable assert function

using namespace std;

	int calendarProcess(int year, int restart, int counter, int weekday);

int main()
{
	int year;
	int counter = 0;
	int weekday = 0;
	int restart = 1;
	int totalDay = 1;
	int newStart = 1;
	int set = 5;
	int var = 0;
	int indexCheck = 0;
		
	string months[] = {"January", "February", "March", "April", "May", "June",
					   "July", "August", "September", "October", "November", "December"};
					   
	string daysOfWeek[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	
	int totalNumOfDays[] = {' ', 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	cout << "Enter year: ";
	cin >> year;
	
	assert(year > 0); // Terminates if year is less than 0
	
	weekday = calendarProcess(year, restart, counter, weekday); //Determine the day 1 of january
						   
	for(int start = 0; start < 12; start++)
	{
		cout << endl << "\t     " << months[start] << endl << endl; //Prints month 
		
		for(int count = 0; count < 7; count++){ //Prints days
			cout <<  daysOfWeek[count] << "  "; 
		}
			cout << endl;
			
			if((year % 400 == 0 | year % 100 != 0) & year % 4 == 0){ //Determine if leap year
			
				totalNumOfDays[2] = 29;
			}
			else{
				totalNumOfDays[2] = 28;
			}
		
			for(int count = 0; count <= totalNumOfDays[totalDay]; count++) //Displays calendar for specific month
			{
				if(var < weekday)	//Alignment
				{
					cout << setw(set) << " ";
				}
				else  
				{
					count = newStart; //Sets value of count to 1
					
						if(var % 7 == 0){ //Prints new line to start the week of the calendar
							cout << endl;
							cout << setw(2) << count << "   ";
						
							indexCheck = 0; //Renew the value of the cheker
						}
						else{
							cout << setw(2) << count << "   ";
							indexCheck++; //Counts the remaining days of the final week
						}
							newStart++; 
				}
				var++;
			}
				totalDay++;
				newStart = 1; //Restart the value 
				var = 0;	  //Restart the value 

				weekday = indexCheck + 1; //The starting day of the month
				
				cout << endl;
	}	 	 	    
	
	return 0;
}
	//Pinpoint the starting day of January
	//of the specified year
	
	int calendarProcess(int year, int restart, int counter, int weekday)
	{	 	 
		for(int start = 1; start <= year; start++)
		{
			if(start == restart)
			{
				restart += 400; //Restarts every after 400 years
				counter = 1; //Restart Jan 1 as monday
			}
			else
			{
				if(((start - 1) % 400 == 0 | (start - 1) % 100 != 0) & (start - 1) % 4 == 0) //Identify if prev year is a leap year
				{
					counter += 2; // Can also be += 366
				}
				else
				{
					counter += 1; // Can also be += 365
				}
			}
		}		//Identify the day of the week
				weekday = counter % 7;
				
				return weekday;	   
	}

	

