/*
*****************************************************************************
*  Name:            AvgSpeed()                                              *
*  Return:          It returns the Average Speed to the calling function(s) *
*  Parameter:       input values for distances, speeds, and time            *     
*  Description:     This function is defined to calculate the average speed * 
*                   of a complete journey which is in three parts, we get   *
*					some inputs from users and calculate the average speed  *
*					after some conversions and operations                   *
****************************************************************************/


#include <iostream>
#include <iomanip>

using namespace std;

/*
 *************************************************************
 *     DEFINING FUNCTION FOR AVERAGE SPEED CALCULUATION      *
 *************************************************************
*/
int AvgSpeed(float x_km,float y_km,float z_km,float x_hours,float y_hours,float z_hours){
	float Avg_Speed;
	
	Avg_Speed=((x_km+y_km+z_km)/(x_hours+y_hours+z_hours));
	
	return Avg_Speed;
}

int main(){
	
//DECLARING VARIABLES X,Y,Z For Distances | x_Hours,y_Hours,Z_Hours For Time IN HOURS | x_Speed,y_Speed,z_Speed for Average Speeds|
	float X,Y,Z,x_Hours,y_Hours,x_Speed,y_Speed,z_Speed,z_Minutes,z_Hours;

/*
   **********************************
   * GETTING INPUT VALUES FROM USER *
   **********************************
*/	
	cout<<"Enter the First Km distance travelled by car : ";
	cin>>X; //Enter the Distance in km
	cout<<"Enter the Average Speed at First distance in m/s : ";
	cin>>x_Speed; //Enter the Speed in m/s
	cout<<"Enter the Second Km distance travelled by the car : ";
	cin>>Y; // Enter the distance in km
	cout<<"Enter the Average Speed at Second distance in km/h : ";
	cin>>y_Speed; // Enter the Speed in km/hr
	cout<<"Enter the time in minutes for the Last part travelled by car : ";
	cin>>z_Minutes; // Enter the time in minutes for last part
	cout<<"Enter the Average speed in Km/hr for last part travelled by the car :";
	cin>>z_Speed;  // Enter the speed for last part in km/hr
	/*
	
	                  ***************************
	                  *      *CONVERSIONS*      *
	                  ***************************  
	
	***************************************************************	
	*     In the follow two lines we do following operations;     *
	*       FIRST: Convert the Given Minute Time into Hours       * 
	*    SECOND: Calculated the Distance in KM for the Last Part  * 	
	***************************************************************
    */
	
	z_Hours=z_Minutes/60; // To get the time in Hours
	Z=z_Speed*z_Hours; //Last distance in Km
	
	/*
	***************************************************************	
	*     In the follow two lines we do following operations;     *
	*  FIRST: converted the Given First Speed from M/S to KM/H    * 
	* SECOND: Calculated the Time in Hours for the First Distance * 	
	***************************************************************
	*/
	
	x_Speed=x_Speed*3.6; //The previous Speed in M/S --> Speed in Km/hr
	x_Hours=X/x_Speed; //The Time for first distance in Hours
	
    /*
	***************************************************************	
	*       In the follow line we do following operation;         *
	*  FIRST: Calculated the Time in Hours for the 2nd Distance   * 	
	***************************************************************
	*/
	
	y_Hours=Y/y_Speed; //The time for second distance in hours
	
	//***********DISPLAYING THE FINALLY CALCULATED AVERAGE DISTANCE TRAVELLED DURING WHOLE JOURNEY*************************
	
	cout<<"The Average Speed of the car during the whole journey is : "<<AvgSpeed(X,Y,Z,x_Hours,y_Hours,z_Hours)<<" km/hr"<<endl;

   return 0;
}

