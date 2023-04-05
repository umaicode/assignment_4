#include <iostream>
//���Ҽ��� ���� ��Ģ������ �����ϵ��� �����Ѵ�. main() �Լ��� �����ϸ� �ȵȴ�
// 
// ���� �� ������ ���� ����
// 
// �����ڸ� �������Ѵ�.
// ���Ҽ� a, b, c, d ������
//
// ���� �� ������ ���� ��

using namespace std;
class ComplexNumber {
private:
	float real;
	float imaginary;
public:
	// ���� �� ������ ���� �ڵ� ����

	// 1. ù��° ���
	//ComplexNumber(float real, float imaginary) {
	//	this->real = real;
	//	this->imaginary = imaginary;
	//}

	// 2. �ι�° ���
	ComplexNumber(float real, float imaginary) : real(real), imaginary(imaginary) {

	}
	// operator ���� ���(1)
	// ComplexNumber operator+(const ComplexNumber&);
	// operator ���� ���(2)
	friend ComplexNumber& operator+(const ComplexNumber&, const ComplexNumber&);
	// ���� �� ������ �����ڵ� ��
	ComplexNumber add(const ComplexNumber &);
	ComplexNumber subtract(const ComplexNumber &);
	ComplexNumber multiply(const ComplexNumber &);
	ComplexNumber divide(const ComplexNumber &);

	friend ostream& operator<<(ostream& stream, const ComplexNumber& p);
	
};

// ���� �� ������ ���� �ڵ� ����
ComplexNumber& operator+(const ComplexNumber& a, const ComplexNumber& b) {
	return ComplexNumber(a.real + b.real, a.imaginary + b.imaginary);
	// a.real += b.real;
	// a.imaginary += b.imaginary;
	// return a;	// �̰� �´� ������ ���ָ� Ǯ�鼭 Ȯ��
	// return *a;
	// return &a;
}

// 1. ù��° ��� �³�?
// ComplexNumber add(const ComplexNumber b) {
// }

// 2. �ι�° ��� �³�?
ComplexNumber ComplexNumber::add(const ComplexNumber& b) {
	ComplexNumber cn(0, 0);
	cn.real = this->real + b.real;
	cn.imaginary = this->imaginary + b.imaginary;

	return cn;
	}
// ���� �� ������ ���� �ڵ� ��

ComplexNumber ComplexNumber::subtract(const ComplexNumber& b) {
	ComplexNumber cn(0,0);
	cn.real = this->real - b.real;
	cn.imaginary = this->imaginary - b.imaginary;

	return cn;
}

ComplexNumber ComplexNumber::multiply(const ComplexNumber& b) {
	ComplexNumber cn(0, 0);
	cn.real = (this->real * b.real) - (this->imaginary * b.imaginary);
	cn.imaginary = (this->real * b.imaginary) + (this->imaginary * b.real);

	return cn;
}

ComplexNumber ComplexNumber::divide(const ComplexNumber& b) {
	ComplexNumber cn(0, 0);
	cn.real = (this->real * b.real + this->imaginary * b.imaginary) / ((b.real * b.real) + (b.imaginary * b.imaginary));
	cn.imaginary = (this->imaginary * b.real - this->real * b.imaginary) / ((b.real * b.real) + (b.imaginary * b.imaginary));

	return cn;
}


ostream& operator<<(ostream& stream, const ComplexNumber& p) {
	stream << p.real << " + " << p.imaginary << "i";
	return stream;
}

int main(void) {
	while (1)
	{
		ComplexNumber a(1, 1), b(2, 2), c(3, 3), d(4, 4);
		int select;	
		cout << "\nSelect command 1: ����, 2: ����, 3. ����, 4: ������, 5. ���ⵡ��, 6. quit => ";
		cin >> select;
		switch (select) {
		case 1:
			cout << endl << "���� d = a + b + c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.add(b.add(c));
			cout << "d = " << d << endl;
			break;
		case 2:
			cout << endl << "���� d = a - b - c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.subtract(b.subtract(c));
			cout << "d = " << d << endl;
			break;

		case 3:
			cout << endl << "���� d = a * b * c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.multiply(b.multiply(c));
			cout << "d = " << d << endl;
			//e = a - b - c - d;
			break;
		case 4:
			cout << endl << "������ d = a / b / c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.divide(b.divide(c));
			cout << "d = " << d << endl;
			cout << a;
			break;
		case 5:
			cout << endl << "cascading ���� d = a + b + c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a + b + c;
			cout << "d = " << d << endl;
			break;
		default:
			exit(0);
			break;
		}
	}
	system("pause");
	return 1;
}