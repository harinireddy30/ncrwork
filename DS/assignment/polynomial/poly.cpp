#include<iostream>
using namespace std;
struct node
{
	int coeff, exp;
	struct node *next;
};
class poly
{
	struct node *start;
public:
	poly()
	{
		start = NULL;
	}
	void add_ele(int ele, int exp)
	{
		struct node *temp;
		temp = new node;
		temp->coeff = ele;
		temp->exp = exp;
		temp->next = NULL;
		if (start != NULL)
		{
			struct node *p;
			p= start;
			while (p->next != NULL)
				p = p->next;
			p->next = temp;
		}
		else
			start = temp;
	}
	poly add_poly(poly p1, poly p2)
	{
		struct node *n1, *n2;
		n1 = p1.start;
		n2 = p2.start;
		while (n1 != NULL && n2 != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->next = NULL;
			if (n1->exp == n2->exp)
			{
				temp->coeff = n1->coeff +n2->coeff;
				temp->exp = n1->exp;
				cout <<"coefficient:"<< temp->coeff << " exponent:" << temp->exp<< endl;
				if (start == NULL)
					start = temp;
				else
				{
					struct node *p = start;
					while (p->next != NULL)
						p = p->next;
					p->next = temp;
				}
				n1 = n1->next;
				n2 = n2->next;
			}
			else if (n1->exp > n2->exp)
			{
				temp->coeff = n1->coeff;
				temp->exp = n1->exp;
				cout <<"coefficient:"<< temp->coeff << " exponent:" << temp->exp << endl;
				if (start == NULL)
					start = temp;
				else
				{
					struct node *p = start;
					while (p->next != NULL)
						p = p->next;
					p->next = temp;
				}
				n1 = n1->next;
			}
			else
			{
				temp->coeff = n2->coeff;
				temp->exp = n2->exp;
				cout <<"coefficient:"<< temp->coeff << " exponent:" << temp->exp << endl;
				if (start == NULL)
					start = temp;
				else
				{
					struct node *p = start;
					while (p->next != NULL)
						p = p->next;
					p->next = temp;
				}
				n2 = n2->next;
			}
		}
		while (n1 != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->coeff = n1->coeff;
			temp->exp = n1->exp;
			temp->next = NULL;
			struct node *t = start;
			while (t->next != NULL)
				t = t->next;
			t->next = temp;
			n1 = n1->next;
		}
		while (n2 != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->next = NULL;
			temp->coeff = n2->coeff;
			temp->exp = n2->exp;
			struct node *t = start;
			while (t->next != NULL)
				t = t->next;
			t->next = temp;
			n2 = n2->next;
		}


		return (*this);
	}
	void display()
	{
		struct node *p = start;
		while (p != NULL)
		{
			cout <<"("<< p->coeff << "x^" << p->exp<<")";
			if (p->next != NULL)
				cout << "+";
			p = p->next;
		}
		cout << endl;
	}

};
int main()
{
	poly p1, p2, p3;
	cout << "Enter the 1st ploynomial:\n";
	int coeff, exp;
	int cont;
	do
	{
		cout << "Enter coefficient & power:";
		cin >> coeff >> exp;
		p1.add_ele(coeff, exp);
		cout << "Add more elements to the polynomial? Enter 1 if yes;else enter 0\n";
		cin >> cont;
	} while (cont == 1);
	cout << "Enter the 2nd ploynomial:\n";
	do
	{
		cout << "Enter coefficient & power:";
		cin >> coeff >> exp;
		p2.add_ele(coeff, exp);
		cout << "Add more elements to the polynomial? Enter 1 if yes;else enter 0\n";
		cin >> cont;
	} while (cont == 1);
	cout << "The first polynomial is:<<";
	p1.display();
	cout<<endl<<"The second polynomial is:";
	p2.display();
	p3.add_poly(p1, p2);
	cout<<endl<<"The resultant polynomial is:";
	p3.display();
	system("pause");
	return 0;
}