#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
                                    ///////////////////////////////////////////////
char Operator[1000];                //                                           //
long double Equation[1000];         //   Declaration of some global variables.   //
long double result=0;               //                                           //
const double Pi=3.142857143;        ///////////////////////////////////////////////
int const  size=100;


void Binary_To_Hex (char  binary[size])
{
    long long   result=0,base=1,remainder,i=0;
                                                    ////////////////////////////////////////////////
                                                    //                                            //
    while(binary[i])                                //        Convert binary to hexadecimal.      //
    {                                               //                                            //
        remainder=binary[i]-48;                     ///////////////////////////////////////////////

        result+=remainder*base;

        base=base*2;
        i++;
    }
    cout<<hex<<result<<endl;


}
void Hex_To_Binary (char hex[size])
{
    int i=0;

    while(hex[i])                                   ///////////////////////////////////////////////
    {                                               //                                           //
        switch(hex[i])                              //      Convert Hexadecimal to binary.       //
        {                                           //                                           //
                                                    ///////////////////////////////////////////////
        case '0':
            cout<<"0000";
            break;

        case '1':
            cout<<"0001";
            break;

        case '2':
            cout<<"0010";
            break;

        case '3':
            cout<<"0011";
            break;

        case '4':
            cout<<"0100";
            break;

        case '5':
            cout<<"0101";
            break;

        case '6':
            cout<<"0110";
            break;

        case '7':
            cout<<"0111";
            break;

        case '8':
            cout<<"1000";
            break;

        case '9':
            cout<<"1001";
            break;

        case 'a':
            cout<<"1010";
            break;

        case 'b':
            cout<<"1011";
            break;

        case 'c':
            cout<<"1100";
            break;

        case 'd':
            cout<<"1101";
            break;

        case 'e':
            cout<<"1110";
            break;

        case 'f':
            cout<< "1111";
            break;
        }
        i++;
    }
    cout<<endl;
}

void Dec_To_Binary(double number)
{
    long double decnum;
    long long s[6] ;
    long long temp,intpart;

    intpart = number;                       ///////////////////////////////////////////////
    decnum= number-intpart;                 //                                           //
    long long  result=0,remender,base=1;    //         Convert decimal to binary.        //
    while ( intpart!=0)                     //                                           //
    {                                       ///////////////////////////////////////////////
        remender= intpart%2;
        result=result+remender*base;
        base=base*10;
        intpart= intpart/2;
    }
    cout <<result;
    if (decnum!=0)
    {
        for (int i=0; i<6; i++)
        {
            decnum=decnum*2;
            temp=decnum;
            s[i]=temp;
            decnum=decnum-temp;
        }
        cout <<".";
        for (int i=0; i<6; i++)
        {
            cout << s[i];
        }
    }
    cout <<endl;
}

void Bin_To_Decimal(char fraBinary[ size])
{
    long double fraDecimal=0.0/*final result*/,dFractional=0.0/*fraction part of input*/
                           ,power=0.5;
    long  long intres = 0/*integer part of result*/,intbinary=0,fractionalbinary[ size];
    long  long base=1,remainder,k=0,temp=0, i=0;

    while(fraBinary[i])
    {

        if(fraBinary[i] == '.')                     ///////////////////////////////////////////////
        {                                           //                                           //
            temp = 1; // test case for point        //        Convert from binary to decimal.    //
        }                                           //                                           //
                                                    ///////////////////////////////////////////////
        else if(temp==0)
        {
            // separate int part from fraction part
            intbinary = intbinary * 10 + (fraBinary[i] -48);
        }

        else if (temp==1)
        {
            // fraction part of number
            fractionalbinary[k] = fraBinary[i] -48;
            k++;
        }
        i++;
    }

    while(intbinary!=0)
    {
        remainder=intbinary%10;
        intres=intres+remainder*base;
        base=base*2;
        intbinary=intbinary/10;
    }

    for(i=0; i<k; i++)
    {
        dFractional  = dFractional  + fractionalbinary[i] *power;
        power = power / 2;
    }

    fraDecimal = intres+ dFractional ;
    cout <<fraDecimal<<endl;
}

void Dec_To_Hex (double num)
{
    int intpart=num;
    double decpart=num-intpart;
    cout <<"The result is "<<endl;
    cout<<hex<<intpart;                 ////////////////////////////////////////////////
    int point = 0;                      //                                            //
    if (decpart!=0)                     //     Convert from decimal to hexadecimal.   //
    {                                   //                                            //
        for (int i=0; i<6; i++)         ////////////////////////////////////////////////
        {
            if (point == 0)
            {
                cout <<".";
                point++;
            }
            decpart=decpart*16;
            int temp=decpart;
            if (temp==10)
                cout << 'a';
            else if (temp==11)
                cout << 'b';
            else if (temp==12)
                cout << 'c';
            else if (temp==13)
                cout << 'd';
            else if (temp==14)
                cout << 'e';
            else if (temp==15)
                cout << 'f';
            else
                cout <<temp;
            decpart=decpart-temp;
        }
    }
    cout <<endl;
}

void Hex_To_Dec (char hexnum[ size])
{
    int i=0,temp=0;
    long double finalresult=0.0;

    string intpart,fracpart;
    while (hexnum[i])                       ///////////////////////////////////////////////
    {                                       //                                           //
        if (hexnum[i]=='.')                 //      Convert hexadecimal to decimal.      //
        {                                   //                                           //
            temp=1;                         ///////////////////////////////////////////////
        }
        if (temp==0)
        {
            intpart+=hexnum[i];
        }

        else if (temp==1)
        {
            fracpart+=hexnum[i];
        }
        i++;
    }
    long long  int_part=0,base=1,result1=0;

    for(int j=intpart.size()-1; j>=0; j--)
    {
        if (intpart[j]>='0'&&intpart[j]<='9')
        {
            int_part=intpart[j]-48;
        }

        else if(intpart[j]>='a'&&intpart[j]<='f')
        {
            int_part=intpart[j]-87;
        }
        result1=result1+int_part*base;
        base*=16;
    }

    long double power=0.0625,result2=0.0,dec_part;
    for (int j=1; j<=fracpart.size(); j++ )
    {
        if (fracpart[j]>='0'&&fracpart[j]<='9')
        {
            dec_part=fracpart[j]-48;
        }

        else if(fracpart[j]>='a'&&fracpart[j]<='f')
        {
            dec_part=fracpart[j]-87;
        }
        result2=result2+dec_part*power;
        power= power/16;
    }
    finalresult= result1+result2;
    cout <<"The result is "<<endl;
    cout <<finalresult<<endl;
}

double Factorial(double n )
{
    double result =1 ;              //////////////////////////////////////////////
                                    //                                          //
    for(int i=1 ; i <=n ; i++)      //    Function calculates the factorial     //
    {                               //                                          //
        result=result *i ;          //////////////////////////////////////////////
    }
    return result ;
}
double Power(double base , double power)
{
    double result=1 , counter=0;
    if(power<0)
                                      //////////////////////////////////////////////
    {                                 //                                          //
        power=power*-1;               //     Function calculates the power        //
        counter++ ;                   //                                          //
    }                                 //////////////////////////////////////////////
    for(int i =1 ; i <=power ; i++)
    {
        result=result*base ;
    }
    if(counter>0)
    {
        return 1/result;
    }
    else
    return result ;
}
void Calculate(long double Equation[] ,char Operator[] , int n)
{
    int counter=0 ;
    for (int i=0 ; i<n ; i++)
    {                                                           /////////////////////////////////////////////////////////
        if(Operator[i]=='+')                                    //                                                     //
        {                                                       //   After calculating all the mathematical operations //
            if(i==0)                                            //   with priorities ,, now remains an equation of "+" //
            {                                                   //   and "-" to be easily calculated.                  //
                result=result+(Equation[i]+Equation[i+1]);      //                                                     //
            }                                                   /////////////////////////////////////////////////////////
            else
            {
                result=result+Equation[i+1];
            }
            counter++ ;
        }
        else if(Operator[i]=='-')
        {
            if(i==0)
            {
                result=result+(Equation[i]-Equation[i+1]);
            }
            else
            {
                result=result-Equation[i+1];
            }
            counter++;
        }
    }
    if (counter==0)
    {
        result=Equation[0];
    }
}
void Priority1(long double Equation[] , char Operator [] , int& n )
{
    int counter=0 ;

    double Temp1 ;
    for (int i =0 ; i<n ; i++)
    {
        if(Operator[i]=='!')                       ///////////////////////////////////////////////
        {                                          //                                           //
            Temp1 = Equation[i];                   //      Searching for the factorial and      //
            Equation[i]=Factorial(Temp1);          //      calculates it.                       //
            for (int z=i ; z<n ; z++)              //                                           //
            {                                      ///////////////////////////////////////////////
                Operator[z]=Operator[z+1] ;
            }
            n--;
            counter++;
        }
        if(counter>0)
        {
            i--;
            counter=0;
        }
    }
}

void Priority2(long double Equation[] , char Operator[] ,int& n)
{
    long double Temp1 , Temp2 ,counter=0 ;

    for (int i =0 ; i<n ; i++)
    {                                                  ///////////////////////////////////////////////
        if (Operator[i]=='q')                         //                                           //
        {                                             //   Searching for roots and calculating it.  //
            Temp1=Equation[i];                        //                                           //
            Equation[i]=sqrt(Temp1);                  ///////////////////////////////////////////////

            for (int z=i ; z<n ; z++)
            {
                Operator[z]=Operator[z+1] ;
            }
            n--;
            counter++;
        }
        if (Operator[i]=='b')
        {
            Temp2=Equation[i];
            Equation[i]=cbrt(Temp2);

            for (int z=i ; z<n ; z++)
            {
                Operator[z]=Operator[z+1] ;
            }
            n--;
            counter++;
        }
        if(counter>0)
        {
            i--;
            counter=0;
        }
    }
}
void Priority3(long double Equation[] , char Operator [] , int& n )
{
    double counter=0 , Temp1 , Temp2 , Temp3;
    for (int i =0 ; i<n ; i++)
    {
        if(Operator[i]=='s')
        {                                       ///////////////////////////////////////////////
            Temp1=Equation[i];                  //                                           //
            Equation[i]=sin(Temp1*Pi/180);      //  Searching for Trigonometric functions and//
            for (int z=i ; z<n ; z++)           //  calculating it.                          //
            {                                   //                                           //
                Operator[z]=Operator[z+1] ;     ///////////////////////////////////////////////
            }
            n--;
            counter++;
        }
        if(Operator[i]=='c')
        {
            Temp2=Equation[i];
            Equation[i]=cos(Temp2*Pi/180);
            for (int z=i ; z<n ; z++)
            {
                Operator[z]=Operator[z+1] ;
            }
            n--;
            counter++;
        }
        if(Operator[i]=='t')
        {
            Temp3=Equation[i];
            Equation[i]=tan(Temp3*Pi/180);
            for (int z=i ; z<n ; z++)
            {
                Operator[z]=Operator[z+1] ;
            }
            n--;
            counter++;
        }

        if(counter>0)
        {
            i--;
            counter=0;
        }
    }
}
void Priority4(long double Equation[] , char Operator [] , int& n )
{
    int counter=0 ;

    double Temp1 , Temp2 , Temp3;
    for (int i =0 ; i<n ; i++)
    {                                           ///////////////////////////////////////////////
        if(Operator[i]=='^')                    //                                           //
        {                                       //   Searching for power and calculating it. //
            Temp1=Equation[i];                  //                                           //
            Temp2=Equation[i+1] ;               ///////////////////////////////////////////////

            Equation[i]=Power(Temp1 ,Temp2);

            for (int j=i+1 ; j<=n+1 ; j++)
            {
                Equation[j]=Equation[j+1] ;

            }
            for (int z=i ; z<n ; z++)
            {
                Operator[z]=Operator[z+1] ;
            }
            n--;
            counter++;
        }

        if(counter>0)
        {
            i--;
            counter=0;
        }
    }
}
void Priority5(long double Equation[] , char Operator[] ,int& n)
{
    int counter=0 ;
    for (int i =0 ; i<n ; i++)
    {
        if(Operator[i]=='*')                            ///////////////////////////////////////////////
        {                                               //                                           //
            Equation[i]=Equation[i]*Equation[i+1];      // Searching for Multiplication and division //
                                                        //  and calculating them.                    //
            for (int j=i+1 ; j<=n+1 ; j++)              //                                           //
            {                                           ///////////////////////////////////////////////
                Equation[j]=Equation[j+1] ;

            }
            for (int z=i ; z<n ; z++)
            {
                Operator[z]=Operator[z+1] ;
            }
            n--;
            counter++;
        }
        if(Operator[i]=='/')
        {
            Equation[i]=Equation[i]/Equation[i+1];
            for (int j=i+1 ; j<=n+1 ; j++)
            {
                Equation[j]=Equation[j+1] ;
            }
            for (int z=i ; z<=n ; z++)
            {
                Operator[z]=Operator[z+1] ;
            }
            n--;
            counter++ ;
        }
        if(counter>0)
        {
            i--;
            counter=0;
        }
    }
}

double Toarr(string s)
{
    int y=0 ,c=0  , m=0 ,  Opcounter=0 , temp=0;
    double var=10 ;
    bool Negative=false ;
    for (int i =0 ; i<s.size() ; i++)
    {
         if(s[i]=='-' &&i==0)
        {
            Negative=true ;

        }
        else if( ( (s[i]=='-' && s[i-1]<'0') || (s[i]=='-' && s[i-1]>'9') ) && ( s[i-1]!= '!') )
        {
            Negative=true;

        }
        else if(s[i]=='*')
        {
            Operator[Opcounter]='*' ;
            Opcounter++;
        }

        else if(s[i]=='/')
        {
            Operator[Opcounter]='/' ;                           ////////////////////////////////////////////////////
            Opcounter++;                                        //                                                //
        }                                                       //  Passing the input in 2 arrays and calculating //
        else if(s[i]=='+')                                      //  negative numbers.                             //
        {                                                       //                                                //
            Operator[Opcounter]='+' ;                           ///////////////////////////////////////////////////
            Opcounter++;
        }
        else if(s[i]=='-')
        {
            Operator[Opcounter]='-' ;
            Opcounter++;
        }
        else if(s[i]=='^')
        {
            Operator[Opcounter]='^' ;
            Opcounter++;
        }
        else if(s[i]=='!')
        {
            Operator[Opcounter]='!' ;
            Opcounter++;
        }

        else if(s[i]=='s'&& s[i+1]=='i')
        {
            Operator[Opcounter]='s' ;
            Opcounter++;
            s.erase(i+1,2);
        }
        else if(s[i]=='c'&& s[i+1]=='o')
        {
            Operator[Opcounter]='c' ;
            Opcounter++;
            s.erase(i+1,2);
        }
        else if(s[i]=='t')
        {
            Operator[Opcounter]='t' ;
            Opcounter++;
            s.erase(i+1,2);
        }
        else if(s[i]=='s'&&s[i+1]=='q')
        {
            Operator[Opcounter]='q' ;
            Opcounter++;
            s.erase(i+1,3);
        }
        else if(s[i]=='c'&& s[i+1]=='b')
        {
            Operator[Opcounter]='b' ;
            Opcounter++;
            s.erase(i+1,3);
        }

        if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/'&& s[i]!='^'&& s[i]!='!' && s[i]!='s'&& s[i]!='c'&& s[i]!='t')
        {
            if(s[i]=='.')
            {
                m++;
                continue;
            }
            else if (m>0)
            {
                if(Negative==true)
                {
                    Equation[y]=Equation[y]-((s[i]-48)/var);
                }
                else
                {
                Equation[y]=Equation[y]+((s[i]-48)/var);
                }
                c++;
                var=var*10 ;
            }
            else
            {
                if(Negative==true)
                {
                Equation[y]=Equation[y]*10 -(s[i]-48);
                }
                else
                {
                    Equation[y]=Equation[y]*10 +(s[i]-48);
                }
                c++ ;
            }
        }
        else
        {
            if(c>0)
            {
                Negative=false ;
                y++ ;
                c=0;
                m=0 ;
                var=10;
            }
        }
    }
    return Opcounter ;
}

double Priority(int n)
{
    Priority1(Equation, Operator ,n) ;  /////////////////////////////////////////////////////////
    Priority2(Equation, Operator, n) ;  //                                                     //
    Priority3(Equation, Operator, n) ;  //      This function calls all the functions by order //
    Priority4(Equation, Operator ,n) ;  //      to calculate the mathematical equation with    //
    Priority5(Equation, Operator ,n) ;  //      priorities and returns result.                 //
    Calculate(Equation , Operator ,n);  //                                                     //
                                        /////////////////////////////////////////////////////////

    return result ;
}

int main()
{

    char ask ;
    cout << "\t\t\tWelcome to The Scientific Calculator" << endl ;
    do
    {   result=0 ;                                                  /////////////////////////////////////////////////
        for(int i=0 ; i<1000; i++)                                  //                                             //
        Equation[i]=0;                                              //  Fundamental loop which run the program by  //
        int const  size=100;                                        //  calling the functions according to the user//
        double num; // number to convert                            //  selection.                                 //
        int choice; // choice of user                               //                                             //
        char save ;// ask user to repeat                            /////////////////////////////////////////////////
        char arr[ size]; // to convert  fraction binary or fraction hex  to decimal
        string s ;
        int op,conv ;
        long double res=0 ;
        cout << "Choose an operation :\n1)Normal calculations\n2)Numbers conversion\n" ;
        cin >> op ;
        if (op==1)
        {
            int n;
            cout <<"Enter the equation :\n"  ;

            cin >> s ;
            n=Toarr(s);
            res=Priority(n) ;
            cout << "The result = " << res ;




            cout << "\nDo you want to save equation and result ? (Y/N)" << endl ;
            cin >> save ;
            if (save=='y' || save=='Y')
            {
                ofstream out_file ;
                out_file.open("Saved equation") ;
                out_file << "Equation : " << s << "\nResult : " << res ;
                out_file.close() ;
                res=0;
            }                                                                                                                               /////////////////////////////////////////////////
        }
        else if (op==2)
        {
            cout << "Convert from :\n\n1)Decimal to Binary\n2)Binary to Decimal\n" ;
            cout << "3)Decimal to Hexadecimal\n4)Hexadecimal To Decimal\n" ;
            cout << "5)Binary to Hexadecimal\n6)Hexadecimal to Binary\n" ;
            cin >> conv ;
            if (conv==1)
            {
                cout << "Enter number :\n" ;
                cin >> num;
                Dec_To_Binary(num);
            }
            else if (conv==2)
            {
                cout << "Enter number :\n" ;
                cin>>arr;
                Bin_To_Decimal(arr);
            }
            else if (conv==3)
            {
                cout << "Enter number :\n" ;
                cin>>num;
                Dec_To_Hex ( num);
            }

            else if (conv ==4)
            {
                cout << "Enter number :\n" ;
                cin>>arr;
                Hex_To_Dec (arr);
            }
            else if (conv ==5)
            {
                cout << "Enter number :\n" ;
                cin>>arr;
                Binary_To_Hex (arr);
            }
            else if (conv ==6)
            {
                cout << "Enter number :\n" ;
                cin>>arr;
                Hex_To_Binary (arr);
            }
        }
        cout << "Do you want to do another operation ? (Y/N)" << endl ;
        cin >> ask ;
        cout << "\x1b[2J\x1b[1;1H" << flush;
    }
    while (ask=='y' || ask=='Y');
        return 0;
}
