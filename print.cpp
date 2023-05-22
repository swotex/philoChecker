/* /$$$$$$             /$$     /$$      /$$                       */
/*|_  $$_/            | $$    | $$$    /$$$                       */
/*  | $$   /$$$$$$$  /$$$$$$  | $$$$  /$$$$  /$$$$$$  /$$   /$$   */
/*  | $$  | $$__  $$|_  $$_/  | $$ $$/$$ $$ |____  $$|  $$ /$$/   */
/*  | $$  | $$  \ $$  | $$    | $$  $$$| $$  /$$$$$$$ \  $$$$/    */
/*  | $$  | $$  | $$  | $$ /$$| $$\  $ | $$ /$$__  $$  >$$  $$    */
/* /$$$$$$| $$  | $$  |  $$$$/| $$ \/  | $$|  $$$$$$$ /$$/\  $$   */
/*|______/|__/  |__/   \___/  |__/     |__/ \_______/|__/  \__/   */
//
// @file: print.cpp                  @author: IntMaxOddity       

#include "checker.hpp"

void	printResult(vector<Philo> vec_id)
{
	cout << setw(5) << "id" << setw(5) << "|" << setw(5) << flush;
	cout << "fork" << setw(5) << "|" << setw(5) << flush;
	cout << "eat" << setw(5) << "|" << setw(5) << flush;
	cout << "sleep" << setw(5) << "|" << setw(5) << flush;
	cout << "think" << setw(5) << "|" << setw(5) << endl;
	cout << "--------------------------------------------------" << setw(5) << endl;

	for (int i=0; i < vec_id.size(); i++)
	{
		for (int j=0; j < vec_id.size(); j++)
		{
			if (vec_id[j].id == i+1)
			{
				cout << vec_id[j].id << setw(5) << "|" << setw(5) << flush;
				cout << vec_id[j].fork << setw(5) << "|" << setw(5) << flush;
				cout << vec_id[j].eat << setw(5) << "|" << setw(5) << flush;
				cout << vec_id[j].sleep << setw(5) << "|" << setw(5) << flush;
				cout << vec_id[j].think << setw(5) << "|" << setw(5) << endl;
			}
		}
	}
}

void	printResult2(vector<Philo> vec_id, int argc, char **argv)
{
	bool ok_fork = true;
	bool ok_eat = true;
	int dead = 0;
	bool ok_timel = true;
	bool ok_timeEat = true;

	for (int i=0; i < vec_id.size(); i++)
	{
		if (vec_id[i].fork / 2 < vec_id[i].eat)
			ok_fork = false;
		if (vec_id[i].dead == true)
			dead = vec_id[i].id;
		if (vec_id[i].error_time == true)
			ok_timel = false;
		if (vec_id[i].error_timeEat == true)
			ok_timeEat = false;
		if (argc >= 6)
		{
			if (vec_id[i].eat < atoi(argv[5]))
			{
				ok_eat = false;
			}
		}
	}
	if (ok_fork)
		cout << "fork : \e[1;32mOK\e[0m  -  " << setw(5);
	else
		cout << "fork : \e[1;31mKO\e[0m  -  "<< setw(5);
	if (ok_eat)
		cout << "eat : \e[1;32mOK\e[0m  -  " << setw(5);
	else
		cout << "eat : \e[1;31mKO\e[0m  -  " << setw(5);
	if (ok_timel)
		cout << "time live : \e[1;32mOK\e[0m  -  " << setw(5);
	else
		cout << "time live : \e[1;31mKO\e[0m  -  " << setw(5);
	if (ok_timeEat)
		cout << "time eat : \e[1;32mOK\e[0m  -  " << setw(5);
	else
		cout << "time eat : \e[1;31mKO\e[0m  -  " << setw(5);
	if (ok_timel == false || ok_timeEat == false)
		cout << "died : \e[1;31mKO\e[0m";
	else if (dead)
		cout << "died : \e[1;34mYes\e[0m (" << dead << ")";
	else
		cout << "died : \e[1;34mNo\e[0m";
	cout << endl;
}
