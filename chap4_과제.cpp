#include <iostream>
//복소수에 대한 사칙연산이 가능하도록 구현한다. main() 함수는 수정하면 안된다
// 
// 수업 중 교수님 설명 시작
// 
// 생성자를 만들어야한다.
// 복소수 a, b, c, d 생성자
//
// 수업 중 교수님 설명 끝

using namespace std;
class ComplexNumber {
private:
	float real;
	float imaginary;
public:
	// 수업 중 교수님 설명 코드 시작

	// 1. 첫번째 방식
	//ComplexNumber(float real, float imaginary) {
	//	this->real = real;
	//	this->imaginary = imaginary;
	//}

	// 2. 두번째 방식
	ComplexNumber(float real, float imaginary) : real(real), imaginary(imaginary) {

	}
	// operator 구현 방법(1)
	// ComplexNumber operator+(const ComplexNumber&);
	// operator 구현 방법(2)
	friend ComplexNumber& operator+(const ComplexNumber&, const ComplexNumber&);
	// 수업 중 교수님 설명코드 끝
	ComplexNumber add(const ComplexNumber &);
	ComplexNumber subtract(const ComplexNumber &);
	ComplexNumber multiply(const ComplexNumber &);
	ComplexNumber divide(const ComplexNumber &);

	friend ostream& operator<<(ostream& stream, const ComplexNumber& p);
	
};

// 수업 중 교수님 설명 코드 시작
ComplexNumber& operator+(const ComplexNumber& a, const ComplexNumber& b) {
	return ComplexNumber(a.real + b.real, a.imaginary + b.imaginary);
	// a.real += b.real;
	// a.imaginary += b.imaginary;
	// return a;	// 이게 맞는 이유를 각주를 풀면서 확인
	// return *a;
	// return &a;
}

// 1. 첫번째 방법 맞나?
// ComplexNumber add(const ComplexNumber b) {
// }

// 2. 두번째 방식 맞나?
ComplexNumber ComplexNumber::add(const ComplexNumber& b) {
	ComplexNumber cn(0, 0);
	cn.real = this->real + b.real;
	cn.imaginary = this->imaginary + b.imaginary;

	return cn;
	}
// 수업 중 교수님 설명 코드 끝

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
		cout << "\nSelect command 1: 덧셈, 2: 뺄셈, 3. 곱셈, 4: 나눗셈, 5. 연쇄덧셈, 6. quit => ";
		cin >> select;
		switch (select) {
		case 1:
			cout << endl << "덧셈 d = a + b + c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.add(b.add(c));
			cout << "d = " << d << endl;
			break;
		case 2:
			cout << endl << "뺄셈 d = a - b - c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.subtract(b.subtract(c));
			cout << "d = " << d << endl;
			break;

		case 3:
			cout << endl << "곱셈 d = a * b * c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.multiply(b.multiply(c));
			cout << "d = " << d << endl;
			//e = a - b - c - d;
			break;
		case 4:
			cout << endl << "나눗셈 d = a / b / c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.divide(b.divide(c));
			cout << "d = " << d << endl;
			cout << a;
			break;
		case 5:
			cout << endl << "cascading 덧셈 d = a + b + c" << endl;
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