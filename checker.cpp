/* /$$$$$$             /$$     /$$      /$$                       */
/*|_  $$_/            | $$    | $$$    /$$$                       */
/*  | $$   /$$$$$$$  /$$$$$$  | $$$$  /$$$$  /$$$$$$  /$$   /$$   */
/*  | $$  | $$__  $$|_  $$_/  | $$ $$/$$ $$ |____  $$|  $$ /$$/   */
/*  | $$  | $$  \ $$  | $$    | $$  $$$| $$  /$$$$$$$ \  $$$$/    */
/*  | $$  | $$  | $$  | $$ /$$| $$\  $ | $$ /$$__  $$  >$$  $$    */
/* /$$$$$$| $$  | $$  |  $$$$/| $$ \/  | $$|  $$$$$$$ /$$/\  $$   */
/*|______/|__/  |__/   \___/  |__/     |__/ \_______/|__/  \__/   */
//
// @file: visu.cpp                  @author: IntMaxOddity       

#include "checker.hpp"

vector<Philo>	addInVector(vector<Philo> philo,  string speak, Philo unit, int id, long long time, char **argv)
{
	int	i;

	i = findIdVector(philo, id);
	if (i != -1)
	{
		switch (findSpeak(speak))
		{
		case EAT:
			philo[i].eat++;
			if (time - philo[i].last_time > atoi(argv[2]) && philo[i].last_time != 0)
				philo[i].error_time = true;
			philo[i].last_time = time;
			break;
		case FORK:
			philo[i].fork++;
			break;
		case SLEEP:
			if (time - philo[i].last_time > atoi(argv[3]) && philo[i].last_time != 0)
				philo[i].error_timeEat = true;
			philo[i].sleep++;
			break;
		case THINK:
			philo[i].think++;
			break;
		case DEAD:
			philo[i].dead = true;
			break;
		default:
			break;
		}
	}
	else
		philo.push_back(unit);
	return (philo);
}

int main(int argc, char **argv)
{
	int		output_fd;
	pid_t	child;

	parsingHandler(argc, argv);

	launchPhilo(argv);
	ifstream	file(FILE);
    long long	time;
	int			id;
	string		speak;
	vector <Philo> philo;
	if (file.is_open())
	{
		string	line;
		while (std::getline(file, line))
		{
			for (int i=0; i < 4; i++)
			{
				if (line.find("m") != string::npos)
					line.erase(0, line.find("m") + 1);
			}
			if (line.empty())
				break;
			time = stoll(line.substr(0, line.find(' ')));
			line.erase(0, line.find(' ') + 1);
			id = stoi(line.substr(0, line.find(' ')));
			line.erase(0, line.find(' ') + 1);
			speak = line.substr(0, line.find('\n'));


			Philo	unit;
			unit = initStruct(id, time, speak);


			if (philo.empty())
				philo.push_back(unit);
			else
				philo = addInVector(philo, speak, unit, id, time, argv);
		}
		for (int i=0; i < philo.size(); i++)
		{
			if (time - philo[i].last_time > atoi(argv[2]) && philo[i].last_time != 0)
				philo[i].error_time = true;
		}
		printResult(philo);
		printResult2(philo, argc, argv);
	}
	file.close();
	remove(FILE);

	cout << endl;

	launchPhiloValgrind(argc, argv);
	ifstream files(FILE);
	bool dataRace = false;
	if (files.is_open())
	{
		string	line;
		while (std::getline(files, line))
		{
			if (line.find("data race") != string::npos)
				dataRace = true;
		}
	}
	if (dataRace)
		cout << "(possible) data race : \e[1;31mYes\e[0m" << endl;
	else
		cout << "(possible) data race : \e[1;32mNo\e[0m" << endl;
	files.close();
	remove("tmp_test");
	return 0;
}
