#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
		string ans;

		int place = 4;
		while (place > 0) {
			int digit = (num / (int) pow(10, place - 1)) % 10;
			switch (place) {
				case 1:
					if (digit == 4) {
						ans += "IV";
					} else if (digit == 9) {
						ans += "IX";
					} else {
						if (digit >= 5) {
							ans += "V";
						}
						for (int i = 0; i < digit % 5; i++) {
							ans += "I";
						}
					}
					break;
				case 2:
					if (digit == 4) {
						ans += "XL";
					} else if (digit == 9) {
						ans += "XC";
					} else {
						if (digit >= 5) {
							ans += "L";
						}
						for (int i = 0; i < digit % 5; i++) {
							ans += "X";
						}
					}
					break;
				case 3:
					if (digit == 4) {
						ans += "CD";
					} else if (digit == 9) {
						ans += "CM";
					} else {
						if (digit >= 5) {
							ans += "D";
						}
						for (int i = 0; i < digit % 5; i++) {
							ans += "C";
						}
					}
					break;
				case 4:
					for (int i = 0; i < digit; i++) {
						ans += "M";
					}
					break;
			}
			place--;
		}
		return ans;
    }
};
