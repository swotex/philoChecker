/* /$$$$$$             /$$     /$$      /$$                       */
/*|_  $$_/            | $$    | $$$    /$$$                       */
/*  | $$   /$$$$$$$  /$$$$$$  | $$$$  /$$$$  /$$$$$$  /$$   /$$   */
/*  | $$  | $$__  $$|_  $$_/  | $$ $$/$$ $$ |____  $$|  $$ /$$/   */
/*  | $$  | $$  \ $$  | $$    | $$  $$$| $$  /$$$$$$$ \  $$$$/    */
/*  | $$  | $$  | $$  | $$ /$$| $$\  $ | $$ /$$__  $$  >$$  $$    */
/* /$$$$$$| $$  | $$  |  $$$$/| $$ \/  | $$|  $$$$$$$ /$$/\  $$   */
/*|______/|__/  |__/   \___/  |__/     |__/ \_______/|__/  \__/   */
//
// @file: checker.hpp                  @author: IntMaxOddity       

#ifndef CHECKER_HPP
# define CHECKER_HPP
# include <iostream>
# include <sys/wait.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <fstream>
# include <vector>
# include <iomanip>
# include <stdio.h>
# include <string.h>
# include <experimental/filesystem>

# define PATH "../philo"
# define FILE "tmp_checker"

using namespace std;

enum Speak
{
	FORK = 12,
	EAT = 13,
	SLEEP = 14,
	THINK = 15,
	DEAD = 16,
	NO = -1
};

struct Philo
{
  int		id;
  int		fork;
  int		eat;
  int		sleep;
  int		think;
  bool		dead;
  long long	last_time;
  bool		error_time;
  bool		error_timeEat;
};

//parsing
void	parsingHandler(int argc, char **argv);
//print
void	printResult(vector<Philo> vec_id);
void	printResult2(vector<Philo> vec_id, int argc, char **argv);
//exec
void	launchPhilo(char **argv);
void	launchPhiloValgrind(int argc, char **argv);
//utils
Speak	findSpeak(string speak);
Philo	initStruct(int id, long long time, string speak);
int		findIdVector(vector<Philo> philo, int id);

#endif