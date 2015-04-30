//TODO: https://www.google.co.uk/search?q=cout+source&ie=utf-8&oe=utf-8&gws_rd=cr&ei=zgNAVbDzBoXcasP8gMgP#q=cout+%3C%3C+chaining+how+to
#pragma once
#include <fstream>
using std::ofstream;
using std::ifstream;

class NA_Debug
{
	
private:
	ofstream logFile;
public:
	NA_Debug(void);
	~NA_Debug(void);
	string operator<<(string);
	string operator<<(int);
	string operator<<(float);
	string operator<<(double);
	string operator<<(unsigned int);

};





NA_Debug::NA_Debug(void)
{

}


NA_Debug::~NA_Debug(void)
{
	logFile.close();
}


string NA_Debug::operator<<(string message)
{
	logFile<<message;
	cout<<message;
	return message;
}

string NA_Debug::operator<<(int message)
{
	logFile<<message;
	cout<<message;
	return message;
}

string NA_Debug::operator<<(float message)
{
	logFile<<message;
	cout<<message;
	return message;
}

string NA_Debug::operator<<(double message)
{
	logFile<<message;
	cout<<message;
	return message;
}

string NA_Debug::operator<<(unsigned int message)
{
	logFile<<message;
	cout<<message;
	return message;
}

