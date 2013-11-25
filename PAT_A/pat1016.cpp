/*
 A long-distance telephone company charges its customers by the following rules:
 Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.
 Input Specification:
 Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.
 The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.
 The next line contains a positive number N (<= 1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word "on-line" or "off-line".
 For each test case, all dates will be within a single month. Each "on-line" record is paired with the chronologically next record for the same customer provided it is an "off-line" record. Any "on-line" records that are not paired with an "off-line" record are ignored, as are "off-line" records not paired with an "on-line" record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.
 Output Specification:
 For each test case, you must print a phone bill for each customer.
 Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.
 Sample Input:
 10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
 10
 CYLL 01:01:06:01 on-line
 CYLL 01:28:16:05 off-line
 CYJJ 01:01:07:00 off-line
 CYLL 01:01:08:03 off-line
 CYJJ 01:01:05:59 on-line
 aaa 01:01:01:03 on-line
 aaa 01:02:00:01 on-line
 CYLL 01:28:15:41 on-line
 aaa 01:05:02:24 on-line
 aaa 01:04:23:59 off-line

 Sample Output:
 CYJJ 01
 01:05:59 01:07:00 61 $12.10
 Total amount: $12.10
 CYLL 01
 01:06:01 01:08:03 122 $24.40
 28:15:41 28:16:05 24 $3.85
 Total amount: $28.25
 aaa 01
 02:00:01 04:23:59 4318 $638.80
 Total amount: $638.80
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>

using namespace std;

int toll[24];
int onedayfee;

struct Record {
	int month;
	int day;
	int hour;
	int minute;

	int state;  //0 for online 1 for offline

	void print() const {
		printf("%02d:%02d:%02d", day, hour, minute);
	}

	Record(char date[], char ss[])  //mm:dd:hh:mm
			{
		char tmp[3];
		//month
		tmp[0] = date[0];
		tmp[1] = date[1];
		month = atoi(tmp);

		//day
		tmp[0] = date[3];
		tmp[1] = date[4];
		day = atoi(tmp);

		//hour
		tmp[0] = date[6];
		tmp[1] = date[7];
		hour = atoi(tmp);

		//minute
		tmp[0] = date[9];
		tmp[1] = date[10];
		minute = atoi(tmp);

		state = (strcmp(ss, "on-line") == 0) ? 0 : 1;
	}

	bool earlierthan(const Record &r) {
		int dif = (r.month - month) * 31 * 24 * 60 + (r.day - day) * 24 * 60
				+ (r.hour - hour) * 60 + (r.minute - minute);
		if (dif >= 0) {
			return true;
		}

		return false;
	}
};

class person {
public:
	char ID[22];
	vector<struct Record> records;
	void insert(Record record) {
		records.push_back(record);

		int size = records.size();

		Record tmp = records[size - 1];
		int i;
		for (i = size - 1; i > 0 && tmp.earlierthan(records[i - 1]); i--) {
			records[i] = records[i - 1];
		}
		records[i] = tmp;

	}

	void print() {
		float totalfee = 0.f;

		bool valid = false;
		int state = records[0].state;
		for (int i = 1; i < records.size(); i++) {
			if (state == 0 && records[i].state == 1) {
				valid = true;
				break;
			}
			state = records[i].state;
		}

		if (!valid) {
			return;
		}

		printf("%s %02d\n", ID, records[0].month);
		state = records[0].state;
		for (int i = 1; i < records.size(); i++) {
			if (state == 0 && records[i].state == 1) {
				//print
				records[i - 1].print();
				printf(" ");
				records[i].print();
				printf(" ");
				// calculate
				float thisfee = 0.f;
				int lastminute = 0;
				int hour1 = records[i - 1].hour;
				int hour2 = (records[i].day - records[i - 1].day) * 24
						+ (records[i].hour - hour1) + hour1;
//        printf("%d %d\n", hour1, hour2);
				for (int h = hour1; h < hour2; h++) {
					thisfee += toll[h % 24] * 60;
					lastminute += 60;
				}
				//
				thisfee -= records[i - 1].minute * toll[records[i - 1].hour];
				lastminute -= records[i - 1].minute;
				thisfee += records[i].minute * toll[records[i].hour];
				lastminute += records[i].minute;
				thisfee /= 100.f;

				totalfee += thisfee;
				printf("%d ", lastminute);
				printf("$%.2f\n", thisfee);
			}
			state = records[i].state;
		}

		if (totalfee == 0.f) {
			return;
		}

		printf("Total amount: $%.2f\n", totalfee);
	}
};

int main() {
	onedayfee = 0;
	for (int i = 0; i < 24; i++) {
		scanf("%d", &toll[i]);
		onedayfee += toll[i];
	}

	int n;
	scanf("%d", &n);

	vector<person> persons;

	for (int i = 0; i < n; i++) {
		char ID[22], date[30], state[10];
		scanf("%s %s %s", ID, date, state);
		bool found = false;
		int j;
		for (j = 0; j < persons.size(); j++) {
			if (strcmp(ID, persons[j].ID) == 0) {
				found = true;
				break;
			}
		}

		if (found) {
			persons[j].insert(Record(date, state));
		} else {
			person another;
			strcpy(another.ID, ID);
			another.insert(Record(date, state));
			persons.push_back(another);
			int size = persons.size();
			int k;
			for (k = size - 1;
					k > 0 && strcmp(persons[k - 1].ID, another.ID) >= 0; k--) {
				persons[k] = persons[k - 1];
			}
			persons[k] = another;
		}
	}

	for (int j = 0; j < persons.size(); j++) {
		persons[j].print();
	}

	return 0;
}

