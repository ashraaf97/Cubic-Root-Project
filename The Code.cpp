#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

void Intro();
void Credit();
double Calculate1(double,double,double,double);
double Calculate2(double,double,double,double,double,double);
void Calculate3(double,double,double,double,double,double,double &,double &,double &);
void Subintervalfive(double &,double &,double &,double &,double,double,int);
void Subintervalten(double &,double &,double &,double &,double &,double &,double &,double &,double &,double,double,int);
void Showinterval1(double,double,int,double);
void Showinterval2(double,double,int,double,double,double);
void Showsubintervalfive(double,double,double,double,double,double,double);
void Showsubintervalten(double,double,double,double,double,double,double,double,double,double,double,double);

int main()
{
	system("title The Cubic Polynomial Root Finder Ver 1.0");
	
	int size;
	double a,b,c,d,f,g,h,x1, x2, x3,startpoint,endpoint;
	char ans;
	
	Intro();
	system("cls");
	system("color 80");
	cout << "This program will calculate the real root of your cubic polynomial in within a range of your x values" <<endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	//Telling the user the general equation of the program
	do{
	cout << "The general formula of a cubic equations is like below: \n\n";
	cout << "a(x^3) + b(x^2) + cx + d = 0" <<endl << endl;
	cout << "Please input the coefficient a, b, c and d and I will show you the real root of the equation\n";
	//Taking input from users for the coefficent
	cout << "Please input 'a' coefficient: ";
	cin >> a;
	while(a==0)
	{
		cout << "This coefficient cannot be zero.Please re-enter the value:";
		cin >> a;
	}
	system("color 20");
	cout << "Please input 'b' coefficient: ";
	cin >> b;
	system("color 30");
	cout << "Please input 'c' coefficient: ";
	cin >> c;
	system("color F0");
	cout << "Please input 'd' coefficient: ";
	cin >> d;
	system("color 70");
	system("cls");
	cout << "CUBIC EQUATION : " << a << "x^3 + " << b << "x^2 + " << c <<"x + " << d << " = 0" << endl;
	cout <<"\nPlease input your interval for the root you want to check (Put starting x point and ending x point and space between them)"<< endl;
	cout << "Please note that this interval works just like your starting point of graph and ending point of graph." << endl;
	cout <<"For example: 1 2 (which means startpoint x = 1 and endpoint x = 2 )"<< endl;
	cin >> startpoint >> endpoint;
	system("color 80");
	//Validating endpoint value
	while(endpoint<=startpoint)
	{
		cout << "Endpoint must be greater than startpoint. Please reenter value of endpoint:";
		cin >> endpoint;
	}
	//Getting user input for  number of subinterval class
	cout << "This step size subinterval class vlaue is works just like how many part of graph you want to be divided." << endl;
	cout << "Note: This program will not show the step size of subinterval class if the root does not appear in between your starting point and ending point." << endl;
	cout << "This program will show the location root in one class only if your root value exist for two class of subinterval" << endl;
	cout << "Enter the the steps size of subinterval class (Please choose between 5 or 10 only): ";
	cin >> size;
	//Validating user input
	while((size!=5)&&(size!=10))
	{
	cout << "\nInvalid input. Please reenter: ";
	cin >> size;
	}
	//Introducing new variable f,g and h to check type of root
	f = ((3*c/a)-((b*b)/(a*a)))/3;
    g = ((2*(b*b*b)/(a*a*a))-(9*b*c/(a*a))+(27*d/a))/27;   
    h = ((g*g)/4)+((f*f*f)/27);
	//Check the type of root and show the interval if exist
	if(f==0 && g==0 && h==0)// all roots are real and equal
	{     
	x1 = Calculate1(a,b,c,d); 
	Showinterval1(startpoint,endpoint,size,x1);
	}
	else if(h<=0)// all 3 roots are real
	{         
	Calculate3(a,b,c,d,g,h,x1,x2,x3);
	Showinterval2(startpoint,endpoint,size,x1,x2,x3);
    }
	else if(h>0) // only 1 root is real
    {
   	x1 = Calculate2(a,b,c,d,g,h);
   	Showinterval1(startpoint,endpoint,size,x1);
	}
	cout <<"\nDo you want to continue? ('y'for yes):";
	cin >> ans;
	system("cls");
}while((ans=='y')||(ans=='Y'));//This program will run again if the user press 'y' or 'Y'

	Credit();
	
	system("pause");
	return 0;
}
//This function is for intro of the program
void Intro()
{
	
	system("color 70");
	cout << "Welcome to The Polynomial Root Finder Ver 1.0" << endl;
	
	Sleep(3000);
}
//This function is for credit of the program
void Credit()
{
	cout << "\nThank you for using this program. Developed by: "<< endl;
	cout << "\nAzrul Haniffah Aadil Bohara\nMohamad Zarif Ramzan\nMuhammad Ashraaf Omar\nNur Amalina Mohd Yusof" << endl;
	
	Sleep(2000);
}

//This function will calculate the value of real roots that are all equal and real
double Calculate1(double a, double b,double c, double d)
{
	double x1,x2,x3;
	
	if((d/a)>0) 
    x1 = x2 = x3 =-1*pow((d/a),0.33333333333333333333333333333333);
    else if((d/a)<0)
    {
    	d=d*-1;
		x1 = x2 = x3 =pow((d/a),0.33333333333333333333333333333333);		
	}
    
    cout << "These coeffiecents of the equation has all roots that are real and equal" <<endl;
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;
    
	return x1;
}

//This function will calculate the root for one roots that are real
double Calculate2(double a, double b,double c, double d,double g,double h)
{
	double x1,x2,x3,r,s,t,u;
	
	 //calculationg r	
	r = (-1*(g/2))+pow(h,0.5);
	//calculationg s    
    if(r>0) 
    s = pow(r,0.33333333333333333333333333333333);
    else if(r<0)
    {
    	r=r*-1;
		s = pow(r,0.33333333333333333333333333333333);
		s=s*-1;
	}
    //calculationg t
    t = (-1*(g/2))-pow(h,0.5);
    //calculationg u
    if(t>0) 
    u = pow(t,0.33333333333333333333333333333333);
    else if(t<0)
    {
    	t=t*-1;
		u = pow(t,0.33333333333333333333333333333333);
		u=u*-1;
	}
	
    x1 = (s+u) - (b/(3*a));
    cout << "\nThese coeffiecents of the equation has one root that are real" <<endl;
    cout << "x1 = " << x1 << endl;
    
    return x1;   
}

//This function will calculate the real root for all roots that different
void Calculate3(double a,double b,double c,double d,double g,double h,double &x1,double &x2,double &x3)
{
	
	double i, j, k, l, m, n, p;
	
	i = pow((((g*g)/4)-h),0.5);
    
    //calculating j    
    if(i>0) 
    j = pow(i,0.33333333333333333333333333333333);
    else if(i<0)
    {
    	i=i*-1;
		j = pow(i,0.33333333333333333333333333333333);
		j=j*-1;
	}
    
    k = acos((g/(2*i))*-1);
    l = j * -1;
    m = cos(k/3);
    n = sqrt(3) * sin(k/3);
    p = (b/(3*a))*-1;
    x1 = (2*j)*m-(b/(3*a));
    x2 = l * (m+n) + p;
    x3 = l * (m-n) + p;
    
    cout << "\nThese coeffiecents of the equation has all roots that are real" <<endl;
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;
}

//This function is to check one root value within the interval and subinterval
void Showinterval1(double startpoint,double endpoint,int size,double x1)
{
	double s2,s3,s4,s5,s6,s7,s8,s9,s10;
	
	if((x1>=startpoint) && (endpoint>=x1))
	{	cout << "\nThe root "<< x1 <<" present in your interval of starting point x = " << startpoint << " and endpoint x = " << endpoint << endl;
	
			
	switch(size)
	{
		case 5 : Subintervalfive(s2,s3,s4,s5,startpoint,endpoint,size);
				 Showsubintervalfive(s2,s3,s4,s5,startpoint,endpoint,x1);
					
				break;
		case 10 : Subintervalten(s2,s3,s4,s5,s6,s7,s8,s9,s10,startpoint,endpoint,size);
				Showsubintervalten(s2,s3,s4,s5,s6,s7,s8,s9,s10,startpoint,endpoint,x1);
				break;
				
	}
	}
	else 
		cout << "\nThe root "<< x1 <<" does not present in your interval of starting point x = " << startpoint << " and endpoint x = " << endpoint << endl;
}

//This function is to check three root value within the interval and subinterval
void Showinterval2(double startpoint,double endpoint,int size,double x1,double x2,double x3)
{
	double s2,s3,s4,s5,s6,s7,s8,s9,s10;
	
	if(((x1>=startpoint) && (endpoint>=x1))||((x2>=startpoint) && (endpoint>=x2))||((x3>=startpoint) && (endpoint>=x3)))
{
		if((x1>=startpoint) && (endpoint>=x1))
	{
		cout << "\nThe root "<< x1 <<" present in your interval of starting point x = " << startpoint << " and endpoint x = " << endpoint << endl;
		switch(size)
	{
		case 5 : Subintervalfive(s2,s3,s4,s5,startpoint,endpoint,size);
				Showsubintervalfive(s2,s3,s4,s5,startpoint,endpoint,x1);
					
				break;
		case 10 : Subintervalten(s2,s3,s4,s5,s6,s7,s8,s9,s10,startpoint,endpoint,size);
				Showsubintervalten(s2,s3,s4,s5,s6,s7,s8,s9,s10,startpoint,endpoint,x1);
				break;
	}
	}
		if((x2>=startpoint) && (endpoint>=x2))
	{
		
		cout << "\nThe root "<< x2 <<" present in your interval of starting point x = " << startpoint << " and endpoint x = " << endpoint << endl;
		switch(size)
	{
		case 5 : Subintervalfive(s2,s3,s4,s5,startpoint,endpoint,size);
				Showsubintervalfive(s2,s3,s4,s5,startpoint,endpoint,x2);	
				break;
		case 10 : Subintervalten(s2,s3,s4,s5,s6,s7,s8,s9,s10,startpoint,endpoint,size);
				Showsubintervalten(s2,s3,s4,s5,s6,s7,s8,s9,s10,startpoint,endpoint,x2);
				break;
	}
	}
		if((x3>=startpoint) && (endpoint>=x3))
	{
		
		cout << "\nThe root "<< x3 <<" present in your interval of starting point x = " << startpoint << " and endpoint x = " << endpoint << endl;
		switch(size)
	{
		case 5 : Subintervalfive(s2,s3,s4,s5,startpoint,endpoint,size);
				Showsubintervalfive(s2,s3,s4,s5,startpoint,endpoint,x3);
					
				break;
		case 10 : Subintervalten(s2,s3,s4,s5,s6,s7,s8,s9,s10,startpoint,endpoint,size);
				Showsubintervalten(s2,s3,s4,s5,s6,s7,s8,s9,s10,startpoint,endpoint,x3);
				break;
	}
	}
}
	
		
else 
cout << "\nThere is no root present in your interval of starting point x = " << startpoint << " and endpoint x = " << endpoint << endl;
}

//This function is to produce classes for subinterval of 10
void Subintervalten(double &s2,double &s3,double &s4,double &s5,double &s6,double &s7,double &s8,double &s9,double &s10,double startpoint,double endpoint,int size)
{
	double classrange = (endpoint - startpoint)/size;
	
	s2 = startpoint + classrange;
	s3 = s2 + classrange;
	s4 = s3 + classrange;
	s5 = s4 + classrange;
	s6 = s5 + classrange;
	s7 = s6 + classrange;
	s8 = s7 + classrange;
	s9 = s8 + classrange;
	s10 = s9 + classrange;	
}

//This function is to produce classes for subinterval of 5
void Subintervalfive(double &s2,double &s3,double &s4,double &s5,double startpoint,double endpoint,int size)
{
	double classrange = (endpoint - startpoint)/size;
	
	s2 = startpoint + classrange;
	s3 = s2 + classrange;
	s4 = s3 + classrange;
	s5 = s4 + classrange;
}

//This function is to show the value of root in the subinterval of 5 if exist
void Showsubintervalfive(double s2,double s3,double s4,double s5,double startpoint,double endpoint,double x1)
{
	if((x1>=startpoint) && (s2>=x1))
	cout << "\nThe root "<< x1 <<" present in your subinterval of starting point x = " << startpoint << " and endpoint x = " << s2 << endl;
	else if((x1>=s2) && (s3>=x1))
	cout << "\nThe root "<< x1 <<" present in your subinterval of starting point x = " << s2 << " and endpoint x = " << s3 << endl;
	else if((x1>=s3) && (s4>=x1))
	cout << "\nThe root "<< x1 <<" present in your subinterval of starting point x = " << s3 << " and endpoint x = " << s4 << endl;
	else if((x1>=s4) && (s5>=x1))
	cout << "\nThe root "<< x1 <<" present in your subinterval of starting point x = " << s4 << " and endpoint x = " << s5 << endl;
	else if((x1>=s5) && (endpoint>=x1))
	cout << "\nThe root "<< x1 <<" present in your subinterval of starting point x = " << s5 << " and endpoint x = " << endpoint << endl;
	
}

//This function is to show the value of root in the subinterval of 10 if exist
void Showsubintervalten(double s2,double s3,double s4,double s5,double s6,double s7,double s8,double s9,double s10,double startpoint,double endpoint,double x1)
{
	if((x1>=startpoint) && (s2>=x1))
	cout << "\nThe root "<< x1 <<" present in your subinterval of starting point x = " << startpoint << " and endpoint x = " << s2 << endl;
	else if((x1>=s2) && (s3>=x1))
	cout << "\nThe root "<< x1 <<" present in your subinterval of starting point x = " << s2 << " and endpoint x = " << s3 << endl;
	else if((x1>=s3) && (s4>=x1))
	cout << "\nThe root "<< x1 <<" present in your subinterval of starting point x = " << s3 << " and endpoint x = " << s4 << endl;
	else if((x1>=s4) && (s5>=x1))
	cout << "\nThe root "<< x1 <<" present in your subinterval of starting point x = " << s4 << " and endpoint x = " << s5 << endl;
	else if((x1>=s5) && (s6>=x1))
	cout << "\nThe root "<< x1 <<" present in your subinterval of starting point x = " << s5 << " and endpoint x = " << s6 << endl;
	else if((x1>=s6) && (s7>=x1))
	cout << "\nThe root "<< x1 <<" present in your subinterval of starting point x = " << s6 << " and endpoint x = " << s7 << endl;
	else if((x1>=s7) && (s8>=x1))
	cout << "\nThe root "<< x1 <<" present in your subinterval of starting point x = " << s7 << " and endpoint x = " << s8 << endl;
	else if((x1>=s8) && (s9>=x1))
	cout << "\nThe root "<< x1 <<" present in your subinterval of starting point x = " << s8 << " and endpoint x = " << s9 << endl;
	else if((x1>=s9) && (s10>=x1))
	cout << "\nThe root "<< x1 <<" present in your subinterval of starting point x = " << s9 << " and endpoint x = " << s10 << endl;
	else if((x1>=s10) && (endpoint>=x1))
	cout << "\nThe root "<< x1 <<" present in your subinterval of starting point x = " << s10 << " and endpoint x = " << endpoint << endl;
}
