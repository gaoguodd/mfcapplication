#pragma once
#include"afxtempl.h"
#include"book.h"

typedef CArray<book>books;

class Booklist :public books
{
public:
	Booklist() {};
	~Booklist() {};
	void Serialize(CArchive& ar);
};

