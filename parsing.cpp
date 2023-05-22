/* /$$$$$$             /$$     /$$      /$$                       */
/*|_  $$_/            | $$    | $$$    /$$$                       */
/*  | $$   /$$$$$$$  /$$$$$$  | $$$$  /$$$$  /$$$$$$  /$$   /$$   */
/*  | $$  | $$__  $$|_  $$_/  | $$ $$/$$ $$ |____  $$|  $$ /$$/   */
/*  | $$  | $$  \ $$  | $$    | $$  $$$| $$  /$$$$$$$ \  $$$$/    */
/*  | $$  | $$  | $$  | $$ /$$| $$\  $ | $$ /$$__  $$  >$$  $$    */
/* /$$$$$$| $$  | $$  |  $$$$/| $$ \/  | $$|  $$$$$$$ /$$/\  $$   */
/*|______/|__/  |__/   \___/  |__/     |__/ \_______/|__/  \__/   */
//
// @file: parsing.cpp                  @author: IntMaxOddity       

#include "checker.hpp"

#include <sys/types.h>
#include <dirent.h>

void	parsingHandler(int argc, char **argv)
{
	if (access(PATH, X_OK) != 0)
	{
		cout << "philo binary not found" << endl;
		exit(12);
	}
	if (opendir(PATH) != NULL)
	{
		cout << "PATH philo is a directory" << endl;
		exit(12);
	}
	if (argc > 6 || argc < 5)
	{
		cout << "Wrong number of argument" << endl;
		exit(12); 
	}
}