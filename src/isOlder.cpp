/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isValid(char *db){
	int len = 0,i=0;
	char *ptr = db;
	while (*ptr++ != '\0')
		len++;
	if (len != 10)
		return 0;
	if ((db[2] == '-') && (db[5] == '-')){
		while (db[i] != '\0'){
			if ((db[i] == '-') || (db[i] >= 48 && db[i] <= 57))
				i++;
			else
				return 0;
		}
	}
	else
		return 1;
	
}



int Compare(char *db1, char *db2){
	int year1=0, year2=0, mnt1=0, mnt2=0, day1=0, day2=0;
	int i = 0;
	while (i <= 1){
		day1 = (day1 * 10) + (db1[i] - 48);
		day2 = (day2 * 10) + (db2[i] - 48);
		i += 1;
	}
	i = 3;
	while (i <= 4){
		mnt1 = (mnt1 * 10) + (db1[i] - 48);
		mnt2 = (mnt2 * 10) + (db2[i] - 48);
		i += 1;
	}
	i = 6;
	while (i <= 9){
		year1 = (year1 * 10) + (db1[i] - 48);
		year2 = (year2 * 10) + (db2[i] - 48);
		i += 1;
	}

	if (((mnt1 == 2) && (day1 == 29) && (year1 % 4 != 0||(year1 % 100 == 0 && year1%400 != 0)))|| (day1 > 31)||(mnt1 > 12))
		return -1;

	if (((mnt2 == 2) && (day2 == 29) && (year2 % 4 != 0|| (year2 % 100 == 0 && year2 % 400 != 0))) || (day2 > 31) || (mnt2 > 12))
		return -1;

	if (year1 == year2){
		if (mnt1 == mnt2){
			if (day1 == day2)
				return 0;
			else{
				if (day1 < day2)
					return 1;
				else
					return 2;
			}
		}
		else{
			if (mnt1 < mnt2)
				return 1;
			else
				return 2;
		}

		}
	else{
		if (year1 < year2)
			return 1;
		else
			return 2;
	}
	
}


int isOlder(char *dob1, char *dob2) {
	int person;
	if (isValid(dob1) && isValid(dob2)){
		person = Compare(dob1, dob2);
			return person;
	}

	return -1;
}
