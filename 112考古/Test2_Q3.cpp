#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ParameciumSpeed 10

int main() {
	int timestamp = 0;	/*		input - timestamp of the record						*/
	int action;			/*		input - action of the record						*/
	int x = 0;			/*		output - where the Paramecium stopped at x-axis		*/
	int y = 0;			/*		output - where the Paramecium stopped at y-axis		*/
	int direction = 0;	/*		facing direction of the Paramecium					*/
	int preActionTime;	/*		timestamp of the previous record					*/

	/*	read records until the action of record is "stop"	*/
	do {
		preActionTime = timestamp;

		/*	read timestamp and action of a record	*/
		scanf("%d%d", &timestamp, &action);

		/*	timestamp must be greater than or equal to 0 and less than 100000000
			action must be 0, 1 or 2												*/
		if (!(timestamp >= 0 && timestamp < 100000000) || !(action == 0 || action == 1 || action == 2)) {
			printf("Input invalid!!\n");
			system("pause");
			exit(1);
		}

		/*	calculate the position and determine facing direction of the Paramecium after a record	*/
		switch (direction)
		{
		case 0:
			y += (timestamp - preActionTime) * ParameciumSpeed;
			switch (action)
			{
			case 0:
				direction = 1;
				break;
			case 1:
				direction = 3;
				break;
			}
			break;
		case 1:
			x += (timestamp - preActionTime) * ParameciumSpeed;
			switch (action)
			{
			case 0:
				direction = 2;
				break;
			case 1:
				direction = 0;
				break;
			}
			break;
		case 2:
			y -= (timestamp - preActionTime) * ParameciumSpeed;
			switch (action)
			{
			case 0:
				direction = 3;
				break;
			case 1:
				direction = 1;
				break;
			}
			break;
		case 3:
			x -= (timestamp - preActionTime) * ParameciumSpeed;
			switch (action)
			{
			case 0:
				direction = 0;
				break;
			case 1:
				direction = 2;
				break;
			}
			break;
		}
	} while (action != 2);

	/*	print the position where the Paramecium stopped		*/
	printf("%d %d\n", x, y);

	system("pause");
	return 0;
}