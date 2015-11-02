#pragma once
class NA_Timer
{
private:
  static const bool DEBUG = false;
	unsigned int duration;
	unsigned int start;
public:
	NA_Timer(void);
	NA_Timer(int d);
	~NA_Timer(void);
	void setDuration(int d);
	bool hasElapsed();
	void restart();
};

