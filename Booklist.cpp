#include "pch.h"
#include "Booklist.h"
void Booklist::Serialize(CArchive& ar)
{
	int iSize = GetSize();
	if (ar.IsStoring())
	{
		ar << iSize;
	}
	else {
		ar >> iSize;
		SetSize(iSize);
	}
	for (int i = 0; i < iSize; i++)
	{
		(*this)[i].Serialize(ar);
	}
}