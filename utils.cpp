/* /$$$$$$             /$$     /$$      /$$                       */
/*|_  $$_/            | $$    | $$$    /$$$                       */
/*  | $$   /$$$$$$$  /$$$$$$  | $$$$  /$$$$  /$$$$$$  /$$   /$$   */
/*  | $$  | $$__  $$|_  $$_/  | $$ $$/$$ $$ |____  $$|  $$ /$$/   */
/*  | $$  | $$  \ $$  | $$    | $$  $$$| $$  /$$$$$$$ \  $$$$/    */
/*  | $$  | $$  | $$  | $$ /$$| $$\  $ | $$ /$$__  $$  >$$  $$    */
/* /$$$$$$| $$  | $$  |  $$$$/| $$ \/  | $$|  $$$$$$$ /$$/\  $$   */
/*|______/|__/  |__/   \___/  |__/     |__/ \_______/|__/  \__/   */
//
// @file: utils.cpp                  @author: IntMaxOddity       

#include "checker.hpp"

Speak	findSpeak(string speak)
{
	if (speak.find("fork") != string::npos)
		return (FORK);
	if (speak.find("eating") != string::npos)
		return (EAT);
	if (speak.find("sleeping") != string::npos)
		return (SLEEP);
	if (speak.find("think") != string::npos)
		return (THINK);
	if (speak.find("died") != string::npos)
		return (DEAD);
	return (NO);
}

Philo	initStruct(int id, long long time, string speak)
{
	Philo	unit;

	unit.id = id;
	unit.fork = 0;
	unit.eat = 0;
	unit.sleep = 0;
	unit.think = 0;
	unit.dead = false;
	unit.last_time = 0;
	unit.error_time = false;
	unit.error_timeEat = false;

	if (findSpeak(speak) == FORK)
		unit.fork++;
	else if (findSpeak(speak) == SLEEP)
		unit.sleep++;
	else if (findSpeak(speak) == THINK)
		unit.think++;
	else if (findSpeak(speak) == DEAD)
		unit.dead = true;
	else if (findSpeak(speak) == EAT)
	{
		unit.eat++;
		unit.last_time = time;
	}
	return (unit);
}

int	findIdVector(vector<Philo> philo, int id)
{
	int	i = 0;

	while (i < philo.size())
	{
		if (philo[i].id == id)
			return (i);
		i++;
	}
	return (-1);
}
