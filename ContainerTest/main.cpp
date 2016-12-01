#include <iostream>
#include <vector>
#include <memory>

#include <list>

#include "StrBlob.h"

using namespace std;

int main() {
	
	struct Q {
		string a[100];
		~Q() {
			cout << "D____________________________________________________" << endl;
		}
	};

	while (1) {
		StrBlob a;
		string s = "a";
		
		for (int i = 0; i < 1000; ++i) {
			s.push_back('a');
			a.push_back(s);
			auto k = new Q;
		}

		a.push_back("12312");
		a.push_back("fasdfdsafas");

		


		StrBlobPtr b(a, 0);

		for (int i = 0; i < 1000; ++i) {
			cout << b.deref() << endl;
			b.incr();
		}
	}
}