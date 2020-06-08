// CardCheck.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string checkHand(string z)
{
	int currentMax = 0;
	int max = 0;
	int pairnumber[2];
	bool pairAppear = false;
	bool doublePair = false;
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			if (i != j)
			{
				if (z[i] == z[j])
				{
					//  cout<< "equal";
					currentMax++;
					//cout<<"cmax=" <<currentMax <<endl;
					if (!pairAppear)
					{
						pairnumber[0] = z[i];
						pairAppear = true;
					}
					else {
						if (z[i] != pairnumber[0]) {
							pairnumber[1] = z[i];
							doublePair = true;
						}
					}


				}
			}

		}
		if (max <= currentMax) {
			max = currentMax;
		}
		currentMax = 0;
	}
	if (max == 1) {
		if (doublePair)
		{
			return "Two Pair";
		}
		else {
			return "One Pair";

		}
	}
	else if (max == 2)
	{
		return "Three Card";
	}
	else if (max == 3) { return "Four Card"; }
	else {
		return "No Pair";
	}
}
int main(void) {
	// 自分の得意な言語で
	// Let's チャレンジ！！

	int n;
	cin >> n;
	string x[400];
	for (int i = 0; i<n; i++)
	{
		cin >> x[i];
		cout << checkHand(x[i]) << endl;
	}

	return 0;
}