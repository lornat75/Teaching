
#include <stdio.h>
#include <yarp/os/Time.h>

int main()
{
	while(true)
	{
		printf("hello yarp\n");
		yarp::os::Time::delay(0.1);
	}
	
	return 0;
}