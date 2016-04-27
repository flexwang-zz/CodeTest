/*
 ﻿A Digital Library contains millions of books, stored according to their titles, authors, key words of their abstracts, publishers, and published years. Each book is assigned an unique 7-digit number as its ID. Given any query from a reader, you are supposed to output the resulting books, sorted in increasing order of their ID's.
 Input Specification:
 Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the total number of books. Then N blocks follow, each contains the information of a book in 6 lines:
 * Line #1: the 7-digit ID number;
 * Line #2: the book title -- a string of no more than 80 characters;
 * Line #3: the author -- a string of no more than 80 characters;
 * Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space;
 * Line #5: the publisher -- a string of no more than 80 characters;
 * Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].
 It is assumed that each book belongs to one author only, and contains no more than 5 key words; there are no more than 1000 distinct key words in total; and there are no more than 1000 distinct publishers.
 After the book information, there is a line containing a positive integer M (<=1000) which is the number of user's search queries. Then M lines follow, each in one of the formats shown below:
 * 1: a book title
 * 2: name of an author
 * 3: a key word
 * 4: name of a publisher
 * 5: a 4-digit number representing the year
 Output Specification:
 For each query, first print the original query in a line, then output the resulting book ID's in increasing order, each occupying a line. If no book is found, print "Not Found" instead.
 Sample Input:
 3
 1111111
 The Testing Book
 Yue Chen
 test code debug sort keywords
 ZUCS Print
 2011
 3333333
 Another Testing Book
 Yue Chen
 test code sort keywords
 ZUCS Print2
 2012
 2222222
 The Testing Book
 CYLL
 keywords debug book
 ZUCS Print2
 2011
 6
 1: The Testing Book
 2: Yue Chen
 3: keywords
 4: ZUCS Print
 5: 2011
 3: blablabla

 Sample Output:
 1: The Testing Book
 1111111
 2222222
 2: Yue Chen
 1111111
 3333333
 3: keywords
 1111111
 2222222
 3333333
 4: ZUCS Print
 1111111
 5: 2011
 1111111
 2222222
 3: blablabla
 Not Found
 */

#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string.h>
#include<iostream>
#include<sstream>
#include<algorithm>

using namespace std;

struct Book {
	string ID;
	string title;
	string author;
	int publishyear;
	string inputstr;

	bool operator<(const Book &another) const {
		return (ID < another.ID);
	}
};

class Keyword {
public:
	string keyword;
	vector<string> books;
	void Sort() {
		sort(books.begin(), books.end());
	}
};

class Publisher {
public:
	string publisher;
	vector<string> books;
	void Sort() {
		sort(books.begin(), books.end());
	}
};

void getkeywords(vector<Keyword>&, string, string);

int main() {
	int nbook, nquery;
	vector<Book> books;
	vector<Keyword> keywords;
	vector<Publisher> publishers;
	string inputstr;

	getline(cin, inputstr);
	istringstream stream(inputstr);
	stream >> nbook;
//  printf("%d\n", nbook);
	for (int i = 0; i < nbook; i++) {
		Book book;
		string ID, title, author;
		//getline(cin, ID);
		getline(cin, ID);
		getline(cin, title);
		getline(cin, author);

		book.ID = ID;
		book.title = title;
		book.author = author;

		string keyword;
		getline(cin, keyword);
//    cout<<"title:"<<title<<endl;
		getkeywords(keywords, keyword, book.ID);

		string publisher;
		getline(cin, publisher);
		bool found = false;
		for (int j = 0; j < publishers.size(); j++) {
			if (publishers[j].publisher == publisher) {
				found = true;
				publishers[j].books.push_back(book.ID);
				break;
			}
		}
		if (!found) {
			Publisher p;
			p.publisher = publisher;
			p.books.push_back(book.ID);
			publishers.push_back(p);
		}

		getline(cin, inputstr);
		istringstream stream(inputstr);
		stream >> book.publishyear;
		//scanf("%d", &(book.publishyear));
		books.push_back(book);
//    printf("%d\n", i);
	}

	sort(books.begin(), books.end());

	for (int i = 0; i < keywords.size(); i++) {
		keywords[i].Sort();
	}

	for (int i = 0; i < publishers.size(); i++) {
		publishers[i].Sort();
	}

	getline(cin, inputstr);
	istringstream stream2(inputstr);
	stream2 >> nquery;

	vector < string > queries;
	for (int iquery = 0; iquery < nquery; iquery++) {
		string querystr;
		getline(cin, querystr);
		queries.push_back(querystr);
	}

	for (int iquery = 0; iquery < queries.size(); iquery++) {
		string querystr = queries[iquery];
		cout << querystr << endl;

		bool found = false;
		int type = querystr.c_str()[0] - '0';
		string content = querystr.substr(3);
		//int type = 1;
		//int len = querystr.size();
		//string content = "The Testing Book";

		if (type == 1)   //title
				{
			for (int i = 0; i < books.size(); i++) {
				if (books[i].title == content) {
					cout << books[i].ID << endl;
					found = true;
				}
			}

		} else if (type == 2) {
			for (int i = 0; i < books.size(); i++) {
				if (books[i].author == content) {
					cout << books[i].ID << endl;
					found = true;
				}
			}
		} else if (type == 5) {
			for (int i = 0; i < books.size(); i++) {
				if (books[i].publishyear == atoi(content.c_str())) {
					cout << books[i].ID << endl;
					found = true;
				}
			}
		} else if (type == 3) {
			for (int i = 0; i < keywords.size(); i++) {
				if (keywords[i].keyword == content) {
					for (int j = 0; j < keywords[i].books.size(); j++) {
						cout << keywords[i].books[j] << endl;
						found = true;
					}
					break;
				}
			}
		} else if (type == 4) {
			for (int i = 0; i < publishers.size(); i++) {
				if (publishers[i].publisher == content) {
					for (int j = 0; j < publishers[i].books.size(); j++) {
						cout << publishers[i].books[j] << endl;
						found = true;
					}
					break;
				}
			}
		}

		if (!found) {
			cout << "Not Found" << endl;
		}
	}
//  while(1);
	return 0;
}
;

void getkeywords(vector<Keyword>& keywords, string keyword, string bookID) {
	string oneword;
	istringstream stream(keyword);
	while (stream >> oneword) {
		bool found = false;
		for (int i = 0; i < keywords.size(); i++) {
			if (keywords[i].keyword == oneword) {
				keywords[i].books.push_back(bookID);
				found = true;
				break;
			}
		}
		if (!found) {
			Keyword key;
			key.keyword = oneword;
			key.books.push_back(bookID);
			keywords.push_back(key);
		}
	}
}

