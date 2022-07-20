//Irfaan Mia
//Binary Calculator
#include <iostream>
#include <string> 
#include <cmath> 
#include <iomanip>
#include <vector>

using namespace std;


string decimaltobinary(int result);
string binarydivision(int num1, int num2);
int binarytodecimal(string binary);

int main()
{
    //Unsigned binary conversion
    cout << "Welcome to Binary calculator" << endl;
    cout << "* for multiplication, + for addition, - for substraction, / for division(Max fractional bits is 10)" << endl;
    
    //User inputs choice
    char choice; 
    cout << "Enter your operation: ";
    cin >> choice;

    //User inputs binary numbers
    string binary;
    cout << "Enter first binary number: ";
    cin >> binary;
    int num1 = binarytodecimal(binary);
    cout << "Second binary number: ";
    cin >> binary; 
    int num2 = binarytodecimal(binary);
    
    //Check which operation needs to be done
    switch (choice)
    {
    //Multiplication
    case '*':
    cout << "Result of multiplication: " << decimaltobinary(num1 * num2) << " = " << num1*num2 << endl;
    break;
    //Addition
    case '+':
    cout << "Result of addition: " << decimaltobinary(num1 + num2) << " = " << num1+num2 << endl;
    break; 
    //Subtraction
    case '-':
    if(num1 - num2 < 0)
    {
    cout << "Negative binary numbers cannot be represented yet. You need to buy the expansion" << endl;
    }
    else if(num1 - num2 > 0)
    {
    cout << "Result of subtraction: " << decimaltobinary(num1 - num2) << " = " << num1 - num2 << endl;
    }
    else if (num1 - num2 == 0)
    {
    cout << "Result of subtraction: " << 0 << endl;
    }
    break;
    //Division
    case '/':
    cout <<  "Result of divisionc: " << binarydivision(num1,num2) << endl;
    break;
    //If an operation out of range is choosen
    default:
    cout << "Invalid Expression" << endl;
    break;
    }

    return 0;

};

string binarydivision(int num1, int num2)
{
    double number1 = num1; 
    double number2 = num2; 

    double result = number1/number2; 
    string binarynumber;
    vector <char> remainderpart;

    //Get integer part
    int num = int(result);
    //Get fractional part
    double fraction = result - int(result);

    //Converions of decimal number to binary fixed point 
    binarynumber = decimaltobinary(num);
    if(fraction != 0)
    {
        binarynumber += '.'; 
        bool done = false;
        int counter = 0;
        while(done == false)
        {
            fraction = fraction*2;
            if((fraction == 1.00) or (counter == 10))
            {
             remainderpart.push_back('1');
             done = true;
             break;
            }
            else
            {
            if((fraction < 1))
            {
             remainderpart.push_back('0');
            }
            else if ((fraction > 1))
            {
             remainderpart.push_back('1');
             fraction--;
            }
            }
            counter++;
        }

        for(int i = 0 ; i < remainderpart.size(); i++)
        {
          binarynumber += remainderpart[i]; 
        }
    }
    //Complete Unsigned fixed point binary number
    return binarynumber;
}

int binarytodecimal(string binary)
{
    int result = 0;
    int index = binary.length() - 1;  
    for(int i = 0 ; i < binary.length() ; i++)
    {
        result += (int(binary[index]) - int('0'))*pow(2,i);
        index--; 
    }
    return result;
}

string decimaltobinary(int result)
{
    //Convert decimal to binary
    int remainder;
    vector <char> binarynumber; 
    bool done = false; 
    while(done == false)
    {
        if(result == 0)
        {
            done = true; 
        }
        else
        {
            remainder = result%2;
            result = result/2; 
            if(remainder == 1)
            {
                binarynumber.push_back('1');
            } 
            else
            {
                binarynumber.push_back('0');
            }
        }
    }
    string fullnumber;
    for(int i = binarynumber.size() - 1; i >= 0; i--)
    {
        fullnumber += binarynumber[i];
    }
    return fullnumber;
}