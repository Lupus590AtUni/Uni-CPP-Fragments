#pragma once
class NA_Timer
{
private:
	int duration;
	int start;
public:
	NA_Timer(void);
	NA_Timer(int d);
	~NA_Timer(void);
	void setDuration(int d);
	bool hasElapsed();
	void restart();
};

