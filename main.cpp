#include <iostream>
#include <fstream>
#include<string>


using namespace std;

string special(int n) { /*tabe adad khas chon baham mani midan*/
	switch (n)
	{
	case 10:
		return "ده";
	case 11:
		return "یازده";
	case 12:
		return "دوازده";
	case 13:
		return "سیزده";
	case 14:
		return "چهارده";
	case 15:
		return "پانزده";
	case 16:
		return "شانزده";
	case 17:
		return "هفده";
	case 18:
		return "هجده";
	case 19:
		return "نوزده";
	default:
		return "not found!";
	}
}

void writeInFile(string data, string fName) {
	ofstream f("results/" + fName + ".txt");
	f << data;
	f.close();
}

string convertToString(int value)  /*dictionary adad*/
{
	string a[9] = { "یکصد", "دویست", "سیصد", "چهارصد", "پانصد", "ششصد", "هفتصد", "هشتصد", "نهصد" };
	string b[9] = { "یکصد", "بیست", "سی", "چهل", "پنجاه", "شصت", "هفتاد", "هشتاد", "نود" };
	string c[9] = { "یک", "دو", "سه", "چهار", "پنج", "شش", "هفت", "هشت", "نه" };

	int first = value / 100;        /*adad ro teke teke mikone va ragham har ba ashar taghsim mikone ta 1 ragham bemone */
	int second = (value / 10) % 10;
	int third = value % 10;


	string numberInString = "";

	if (first != 0) {
		numberInString = a[first - 1];

		if (second != 0 || third != 0) {
			numberInString += " و ";
		}
	}

	if (second != 0) {
		if (second == 1) {
			numberInString += special((second * 10) + third);
		}
		else {
			numberInString += b[second - 1];
			if (third != 0) {
				numberInString += " و ";
			}
		}
	}

	if (second != 1 && third != 0) {
		numberInString += c[third - 1];
	}


	if (first == 0 && second == 0 && third == 0) {
		numberInString = "صفر";
	}


	return numberInString;
}



int main() {
	int number;
	cout << "Enter number : ";
	cin >> number;
	string s = convertToString(number);
	writeInFile(s, to_string(number));
	cout << "file generated!";

	cout << "\n";

	return 0;
}