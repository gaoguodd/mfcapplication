#include "pch.h"
#include "book.h"
#include<fstream>
#include<iostream>
book::book(){}

book::book(CString strname, CString strpub, CString strwri, int strtotal):name(strname),publish(strpub),writer(strwri),total(strtotal){}
book::~book(){}
CString book::Getname()
{
	return name;
}
CString book::Getpub()
{
	return publish;
}
CString book::Getwriter()
{
	return writer;
}
int book::Getnow()
{
	return num_now;
}
CString book::Gettotal()
{
	CString Total;
	Total.Format(_T("%d"), total);
	return Total;
}
void book::Setname(CString a)
{
	name = a;
}
void book::Setpub(CString a)
{
	publish = a;
}
void book::Setwriter(CString a)
{
	writer = a;
}
void book::Setnow(int a)
{
	num_now = a;
}

void book::Settotal(int a)
{
	total = a;
}

void book::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << name;
		ar << publish; 
		ar << writer;
		ar << total;
	}
	else {
		ar >> name;
		ar >> publish;
		ar >> writer;
		ar >> total;
	}
}
