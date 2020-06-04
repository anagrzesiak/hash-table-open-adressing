#include<iostream>
#include<string>
#define SIZE 26;

using namespace std;

void CHOINKA() {
	int maxSize = 37;
	int x = 1, k = 1, z = 2;
	int r = maxSize / 2;
	for (int j = r; j >= 0; j--){
		for (int i = 1; i <= j; i++){
			x = k * 2; cout << " ";
			if (i == j) { while (x) { cout << "@"; x--; }break; }
		}
		if (j != 0) { 
			cout << endl; 
		}k++;
	}
	while (z) {
		while (r){
			cout << " "; r--;
		}
		cout << "##" << endl; z--; r = maxSize / 2;
	}
}


struct node {
	string val;
	node *next;
};

void add(string x, node *&h) {
	node *p = new node;
	p->val = x;
	p->next = h;
	h = p;
}

int stringtoint(string a) {
	/*int b = atoi(a.c_str());
	return b;*/
	int sum=NULL;
	for (int i = 0; i<a.length(); i++){
		char x = a.at(i);
		int y = int(x);
		sum = sum + y;
	}
	return sum;
}

void tabzero(node **tb) {
	int size = SIZE;
	for (int i = 0; i < size; i++) {
		tb[i] = nullptr;
	}
}

int hashing(int c) {
	int size = SIZE;
	c = c % (size / 2);
	return c;
}

void addtotab(string name, node **tb) {
	int hashed = hashing(stringtoint(name));
	add(name, tb[hashed]);

}

void show(node **tb) {
	int size = SIZE;
	for (int i = 0; i < size; i++) {
		cout << "tab[" << i << "]";
		while (!tb[i]){
			cout << tb[i]->val << "->";
		}
		cout << "NULL";
	}
}

void addopen(string name, node **tb) {
	int size = SIZE;
	int hashed = hashing(stringtoint(name));
	cout << "string: " << name << "      and int: " << hashed << endl;
	if (tb[hashed]){
		for (int i = hashed; i < size; i++) {
			if (!tb[i]) {
				add(name, tb[hashed]);
				if (tb[hashed]->next) {
					node *temp;
					temp = tb[hashed]->next;
					while (temp->next) {
						temp = temp->next;
					}
					temp->next = tb[i];
				}
				else {
					tb[hashed]->next = tb[i];
				}
				break;
			}
		}
	}
	else {
		add(name, tb[hashed]);
	}
}

void emptypl(node **temptb, node *tempdel, int _size) {
	int size = SIZE;
	for (int i=0; i<size; i++){
		if (temptb[i] == tempdel){
			temptb[i] = nullptr;
			break;
		}
	}
}

void delopen(string name, node **tb) {
	int size = SIZE;
	int find;
	for (int i = 0; i < size; i++) {
		if (tb[i] && (tb[i]->val == name)) {
			find = hashing(stringtoint(name));
			if (find == i && tb[i]->next) { //z nastepnikami
				node *temp = tb[i]->next;
				tb[i]->val = tb[i]->next->val;
				tb[i]->next = tb[i]->next->next;

				emptypl(tb, temp, size); //tak jakby nast zamiana miejscami 
			}
			else if ((find != i) && tb[i]->next) {
				node *temp = tb[find];
				while (temp->next->val != name) {
					temp = temp->next;
				}
				if (temp->next->next) {
					node *temp1 = temp->next->next;
					emptypl(tb, temp->next, size);
					temp->next = temp1;
				}
				else {
					emptypl(tb, temp->next, size);
					temp->next = nullptr;
				}
			}
			else if (find == i && tb[i]->next == nullptr) { //bez
				node *temp = tb[i];
				emptypl(tb, temp, size);
				temp->next = nullptr;
			}
			else if ((find != i) && (tb[i]->next == nullptr)) {
				node *temp = tb[find];
				while (temp->next->val != name) {
					temp = temp->next;
				}
			}
		}
	}
}

void showopen(node **tb) {
	int size = SIZE;
	for (int i=0; i<size; i++){
		if (tb[i]){
			cout<<"["<<i<<"] "<<tb[i]->val<<endl;
		}
		else {
			cout<<"["<<i<<"] = NULL"<<endl;
		}
	}
}

int main() {
	int ssize = SIZE;
	node **tb = new node *[ssize];
	tabzero(tb);
	addopen("bardzo", tb);
	addopen("chce", tb);
	addopen("mi", tb);
	addopen("sie", tb);
	addopen("spac", tb);
	addopen("pzdr", tb);
	showopen(tb);
	CHOINKA();
	delopen("pzdr", tb);
	showopen(tb);


	system("PAUSE");
	return 0;
}


