#include "stdafx.h"
#include "NA_Timer.h"
#include <time.h>


NA_Timer::NA_Timer(void)
{
	duration = 0;
	start = time(NULL);
}

NA_Timer::NA_Timer(int d)
{
	duration = d;
	start = time(NULL);
}

NA_Timer::~NA_Timer(void)
{
}

void NA_Timer::setDuration(int d)
{
	duration = d;
}

bool NA_Timer::elapsed()
{
	if(duration < difftime(time(NULL),start))
		return true;
	//else
	return false;
}

