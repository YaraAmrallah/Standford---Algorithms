/*
 * multiplication.cpp
 *
 *  Created on: Apr 21, 2020
 *      Author: yaraa
 */

#include <bits/stdc++.h>
#include "multiplication.h"

std :: vector<int> stringToVector(std::string &number)
{
	std::vector <int> numberVector;
	int stringLength = number.length();

	for(int i = 0; i < stringLength; i++)
	{
		numberVector.push_back(std::stoi(number.substr(i,1)));
	}
	return numberVector;
}

std :: vector<int> gradeMultiplication(std::string &number1, std:: string &number2)
{
	int number1Length = number1.length();
	int number2Length = number2.length();
	std::vector <int> resultVector;
	int vectorSize = number1Length+number2Length+1;
	resultVector.resize(vectorSize,0);


	int result = 0;
	int carry = 0;
	for(int i = 0; i < number1Length; i++)
	{
		for(int j = 0; j < number2Length; j++)
		{
			result = (std::stoi(number1.substr((number1Length-i-1),1)))*(std::stoi(number2.substr((number2Length-j-1),1)));
			resultVector[vectorSize - (i+j) - 1] += (result-(result/10)*10);
			if(resultVector[vectorSize - (i+j) - 1]>= 10)
			{
				carry = result/10 + resultVector[vectorSize - (i+j) - 1]/10;
				resultVector[vectorSize - (i+j) - 1] = resultVector[vectorSize - (i+j) - 1] - (resultVector[vectorSize - (i+j) - 1]/10)*10;
			}
			else
				carry = result/10;
			resultVector[vectorSize - (i+j+1) - 1] += carry;
		}
	}
	return resultVector;
}

long double power (long double base, long double p)
{
	long double result = 1;
	for (int i = 0; i < p; i++)
	{
		result = result*base;
	}

	return result;
}

std :: string stringAddition(std::string number1, std::string number2)
{
	int length1 = number1.length();
	int length2 = number2.length();

	int numberOfZeros = 0;
	int maxLength = length1;
	if (length1 > length2)
	{
		numberOfZeros = length1 - length2;
		for(int i = 0; i < numberOfZeros; i++) number2.insert(0,"0");
		maxLength = length1;
	}
	else if (length1 < length2)
	{
		numberOfZeros = length2 - length1;
		for(int i = 0; i < numberOfZeros; i++) number1.insert(0,"0");
		maxLength = length2;
	}

	int carry = 0;
	int sum = 0;
	std:: string result = "";
	std:: string stringResult;
	for(int i = (maxLength-1); i >= 0; i--)
	{
		sum = std::stoi(number1.substr(i,1)) + std::stoi(number2.substr(i,1)) + carry;
		stringResult = std::to_string(sum);
		stringResult = stringResult[stringResult.length() - 1];
		carry = sum/10;
		result.insert(0, stringResult);
		if(i == (maxLength - 1)) result.insert(0, std::to_string(carry));
	}

	return result;
}


long double multiply (long double number1, long double number2, int numberOfDigits)
{
	if(numberOfDigits == 1) return number1*number2;

	long double divisor = power(10, numberOfDigits/2);
	long double a = number1/divisor;
	long double b = number1 - a*divisor;

	long double c = number2/divisor;
	long double d = number2 - c*divisor;

	long double ac = multiply(a, c, numberOfDigits/2);
	long double ad = multiply(a, d, numberOfDigits/2);
	long double bc = multiply(b, c, numberOfDigits/2);
	long double bd = multiply(b, d, numberOfDigits/2);


	long double result = bd + (ad + bc)*divisor + ac*power(10, numberOfDigits);

	return result;
}



/*void bigNumberMultDisplay(std::string number1, std::string number2, int size)
{
	if (size <= 16) return;
	std :: stringstream stream1A(number1.substr(0, size/2));
	long double number1A;
	stream1A >> number1A;

	std :: stringstream stream1B(number1.substr(size/2, size/2));
	long double number1B;
	stream1B >> number1B;

	std :: stringstream stream2A(number2.substr(0, size/2));
	long double number2A;
	stream2A >> number2A;

	std :: stringstream stream2B(number2.substr(size/2, size/2));
	long double number2B;
	stream2B >> number2B;

	bigNumberMultDisplay(stream2B.str(0), );

}*/
