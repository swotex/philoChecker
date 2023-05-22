/* /$$$$$$             /$$     /$$      /$$                       */
/*|_  $$_/            | $$    | $$$    /$$$                       */
/*  | $$   /$$$$$$$  /$$$$$$  | $$$$  /$$$$  /$$$$$$  /$$   /$$   */
/*  | $$  | $$__  $$|_  $$_/  | $$ $$/$$ $$ |____  $$|  $$ /$$/   */
/*  | $$  | $$  \ $$  | $$    | $$  $$$| $$  /$$$$$$$ \  $$$$/    */
/*  | $$  | $$  | $$  | $$ /$$| $$\  $ | $$ /$$__  $$  >$$  $$    */
/* /$$$$$$| $$  | $$  |  $$$$/| $$ \/  | $$|  $$$$$$$ /$$/\  $$   */
/*|______/|__/  |__/   \___/  |__/     |__/ \_______/|__/  \__/   */
//
// @file: execPhilo.cpp                  @author: IntMaxOddity       

#include "checker.hpp"

void	launchPhilo(char **argv)
{
	int		fd = -1;
	pid_t	child;
	pid_t	waiting = 0;

	fd = open(FILE, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (fd == -1)
		exit (1);
	child = fork();
	if (child == 0)
	{
		dup2(fd, 1);
		close(fd);
		execvp(PATH, argv);
	}
	else
	{
		for (int i=0; waiting == 0 && i < 20; i++)
		{
			cout << "\rtime out : [" << flush;
			waiting = waitpid(child, NULL, WNOHANG);
			for (int j=0; j < 20; j++)
			{
				if (j<=i)
					cout << "=" << flush;
				else
					cout << " " << flush;
			}
			cout << "] " << (i * 100) / 20 << "%" << flush;
			usleep(500000);
		}
		cout << "\e[?25h";
		cout << endl;
		if (waiting == 0)
			kill(child, 15);
	}
	close(fd);
}

void	launchPhiloValgrind(int argc, char **argv)
{
	int		fd = -1;
	pid_t	child;
	pid_t	waiting = 0;

	char	*cmd[10];
	cmd[0] = strdup("valgrind");
	cmd[1] = strdup("--tool=helgrind");
	cmd[2] = strdup("--track-lockorders=no");
	cmd[3] = strdup(PATH);
	cmd[4] = strdup(argv[1]);
	cmd[5] = strdup(argv[2]);
	cmd[6] = strdup(argv[3]);
	cmd[7] = strdup(argv[4]);
	cmd[8] = 0;
	cmd[9] = 0;
	if (argc == 6)
		cmd[8] = strdup(argv[5]);
	fd = open(FILE, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (fd == -1)
		exit (1);
	child = fork();
	if (child == 0)
	{
		dup2(fd, 2);
		close(fd);
		close(1);
		execvp(cmd[0], cmd);
	}
	else
	{
		for (int i=0; waiting == 0 && i < 20; i++)
		{
			cout << "\rtime out : [" << flush;
			waiting = waitpid(child, NULL, WNOHANG);
			for (int j=0; j < 20; j++)
			{
				if (j<=i)
					cout << "=" << flush;
				else
					cout << " " << flush;
			}
			cout << "] " << (i * 100) / 20 << "%" << flush;
			usleep(500000);
		}
		cout << "\e[?25h";
		cout << endl;
		if (waiting == 0)
			kill(child, 15);
	}
	for (int i=0; cmd[i]; i++)
		free(cmd[i]);
	close(fd);
}
