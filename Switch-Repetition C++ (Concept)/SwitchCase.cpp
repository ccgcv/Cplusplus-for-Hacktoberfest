#include<iostream>
using namespace std;

/************************************************************
* Name:			ex1_TernaryOperator							*
* Return:		Nil											*
* Param:		Nil											*
* Description:	Demos basic usage of ternary operator		*
************************************************************/
void ex1_TernaryOperator() {
	double score;
	cout << "Enter your score: ";
	cin >> score;

	char cGrade;
	bool bPassFail;

	// plain simple usage of the ternary operator
	score > 60 ? cGrade = 'P' : cGrade = 'F';					
	cout << cGrade << " is your grade." << endl;

	// using cout inside the 2nd and 3rd expression
	score > 60 ? cout << "You passed"<<endl : cout << "You failed"<<endl;	
	cout << boolalpha; // want to see true/false
	// using multiple statements in all the three expressions
	score > 60 && score <= 100 ?
		(cGrade = 'P', bPassFail = true, cout << "Your passing status is " << bPassFail << " with grade " << cGrade << endl) :
		(cGrade = 'F', bPassFail = false, cout << "Your passing status is " << bPassFail << " with grade " << cGrade << endl);	// using logical operators in the condition

}

/************************************************************
* Name:			ex2_NestedTernaryOperator					*
* Return:		Nil											*
* Param:		Nil											*
* Description:	Demos nested usage of ternary operator		*
************************************************************/
void ex2_NestedTernaryOperator() {
	double score;
	cout << "Enter your score: ";
	cin >> score;

	char cGrade;
	bool bPassFail;
	

	score < 50 ? cGrade = 'F' :
		(score < 62 ? cGrade = 'D' :
			(score < 74 ? cGrade='C' : 
				( score < 86 ? cGrade = 'B': 
					score <= 100 ? cGrade = 'A': cGrade = 'X' // brackets are optional
					)
				)
			);

	cout << "Your grade: " << cGrade << endl;
}

/************************************************************
* Name:			ex3_SwitchCaseCalculator					*
* Return:		Nil											*
* Param:		Nil											*
* Description:	Demos basic usage of switch-case			*
************************************************************/
void ex3_SwitchCaseCalculator() {

	unsigned nOperation;
	int num1;
	int num2;
	cout << "Enter first operand: ";
	cin >> num1;
	cout << "Enter second operand: ";
	cin >> num2;
	cout << "Enter operation (1 for add, 2 for subtract, 3 for multiply, 4 for divide, 5 for remainder): ";
	cin >> nOperation;

	switch (nOperation) // must be an integer (including char) variable or expression
	{
	case 1: // must be an integer literal or constant
		cout << "Sum = " << num1 + num2 << endl;
		break;
	case 2:
		cout << "Difference = " << num1 - num2 << endl;
		break;
	case 3:
		cout << "Product = " << num1 * num2 << endl;
		break;
	case 4:
		cout << "Quotient = " << num1 / num2 << endl;
		break;
	case 5:
		cout << "Remainder = " << num1 % num2 << endl;
		break;
	}	
}

/************************************************************
* Name:			ex4_DefaultCase								*
* Return:		Nil											*
* Param:		Nil											*
* Description:	Default case of switch						*
************************************************************/
void ex4_DefaultCase() {
	int nMonthNo;
	cout << "Enter month: ";
	cin >> nMonthNo;
	//string sMonthName = "";

	switch (nMonthNo) {
	case 1: // will stop after encountering first break statement
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		cout << "Thirty-One days" << endl;
		break;
	case 2:
		cout << "Twenty-Eight or Twenty-Nine days" << endl;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		cout << "Thirty days" << endl;
		break;
	default: // runs for any option other than the above
		cout << "Incorrect month entered" << endl;
	}
	
}

/************************************************************
* Name:			ex5_SwitchExpression						*
* Return:		Nil											*
* Param:		Nil											*
* Description:	Use of variations in switch					*
************************************************************/
void ex5_SwitchExpression() {
	switch (int a = 10) {
	case 10:
		cout << "10" << endl;
	}

	int data1 = 10, data2 = 11, data3 = 12;
	switch (int a = (data1+data2+data3)/2 ) {
	case 17:
		cout << "17" << endl;
		break;
	case 16:
		cout << "16" << endl;
		break;
	default:
		cout << "default" << endl;
	}

	switch ((data1 + data2 + data3) / 2) {
	case 17:
		cout << "17" << endl;
		break;
	case 16:
		cout << "16" << endl;
		break;
	default:
		cout << "default" << endl;
	}

	/*switch ( (data1 + data2 + data3) / 2.0 ) {
	case 17:
		cout << "17" << endl;
		break;
	case 16:
		cout << "16" << endl;
		break;
	default:
		cout << "default" << endl;
	}*/
}

/************************************************************
* Name:			ex6_CaseValues								*
* Return:		Nil											*
* Param:		Nil											*
* Description:	Use of variations in case					*
************************************************************/
void ex6_CaseValues() {
	int test = 2;
	//bool test = true;
	//char test = 'C';
	//double test = 1.0; // this does not work

	switch (test) {
	case true:
		cout << "case true" << endl;
		break;
	case 2:
		cout << "case 2" << endl;
		break;
	case 'A'+2:
		cout << "case A" << endl;
		break;

	//case 1: //Error: already defined as case true
	
	default:
		cout << "default case" << endl;
	}
}

/************************************************************
* Name:			ex7_NestedSwitchCase						*
* Return:		Nil											*
* Param:		Nil											*
* Description:	Nested switch-case							*
************************************************************/
void ex7_NestedSwitchCase() {
	unsigned nConnectionChoice;
	cout << "Press 1 for a new connection,\
		\nPress 2 for a new service on the same connection\
		\nPress 0 to talk to a customer representative" << endl;
	cin >> nConnectionChoice;

	switch (nConnectionChoice) {
	case 0: // customer service
		cout << "All customer service operators are busy at the moment" << endl;
		break;
	case 1: // a new connection
		////////////////////////////////////////////////////////////
		int nServiceChoice;
		cout << "Press 1 for a landline connection\
			\nPress 2 for a wireless device" << endl;
		cin >> nServiceChoice;
		switch (nServiceChoice) {
		case 1: // landline connection
			// taking input etc. and sending network commands
			cout << "Your landline connection is provided" << endl;
			break;
		case 2: // wireless connection
			// taking input etc. and sending network commands
			cout << "Your wireless connection is provided" << endl;
			break;
		default:
			// incorrect choice
			cout << "Incorrect choice" << endl;
		}
		////////////////////////////////////////////////////////////
		break;
	case 2: // a new service
		////////////////////////////////////////////////////////////
		//int nServiceChoice; // already defined variable
		cout << "Press 1 for a broadband connection\
			\nPress 2 for a CLI service" << endl;
		cin >> nServiceChoice;
		switch (nServiceChoice) {
		case 1: // broadband connection
			// taking input etc. and sending network commands
			cout << "Your broadband connection is provided" << endl;
			break;
		case 2: // CLI service
			// taking input etc. and sending network commands
			cout << "Your CLI service is provided" << endl;
			break;
		default:
			// incorrect choice
			cout << "Incorrect choice" << endl;
		}
		////////////////////////////////////////////////////////////
		break;
	default: // incorrect option
		cout << "Incorrect choice" << endl;
	}
	cout << "Thank you for using our services" << endl;
}