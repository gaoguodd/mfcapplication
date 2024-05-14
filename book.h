#pragma once
#include <string>
using namespace std;
class book
{
protected:
	CString name;
	CString publish;
	CString writer;
	int total;
	int num_now;
public:
	book();
	book(CString strname, CString strpub, CString strwri, int total);
	~book();
	CString Getname();
	CString Getpub();
	CString Getwriter(); 
	CString Gettotal();
	int Getnow();

	void Setname(CString);
	void Setpub(CString);
	void Setwriter(CString);
	void Settotal(int );
	void Setnow(int );

	void Serialize(CArchive& ar);
};

