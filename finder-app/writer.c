#include <unistd.h>
#include <errno.h>
#include<stdio.h>
#include <fcntl.h>
#include <syslog.h>
#include <string.h>

int main(int argc, char *argv[])
{
	openlog ("Writer_Example_Program", LOG_CONS | LOG_PID | LOG_NDELAY | LOG_DEBUG, LOG_LOCAL1 | LOG_ERR );
	if (argc != 3)
	{
        	syslog(LOG_ERR, "Usage: %s <filePath> <stringToFillWith>\n", argv[0]);
        	return 1;
    	}
	else
	{
		syslog(LOG_DEBUG, "Writing %s to %s\n", argv[2] , argv[1]);
		int file_handler;
		ssize_t file_size;
		file_handler = open(argv[1], O_RDWR | O_CREAT | O_TRUNC);
		if (file_handler == -1)
		{
			syslog (LOG_ERR, "Can not open file %s", argv[1]);
               	 	return 1;
		} 
		else 
		{
			syslog (LOG_INFO, "Writing %s to %s", argv[2], argv[1]);
			file_size = write (file_handler, argv[2], strlen (argv[2]));
			if (file_size == -1) 
			{
				syslog (LOG_INFO, "Can not write string");
                        	return 1;
			}
		}
		closelog ();
	}
}
