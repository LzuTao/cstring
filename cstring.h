#ifndef CSTRING_H
#define CSTRING_H

#include <iostream>

class CString {
private:
	char* str;
	int length;

public:
	CString();
	CString(char c);
	CString(const char* m_newStr, int m_length = 0);
	CString(const CString& copy);

	int getLength() const;

	CString& operator = (const CString& m_newStr);
	CString operator + (const CString& m_newStr) const;

	bool operator < (const CString& m_newStr) const;
	bool operator > (const CString& m_newStr) const;
	bool operator <= (const CString& m_newStr) const;
	bool operator >= (const CString& m_newStr) const;
	bool operator == (const CString& m_newStr) const;
	bool operator != (const CString& m_newStr) const;
	
	CString& expand(char c);
	CString& expand(const char* m_newStr);
	CString& expand(const CString& m_newStr);

	CString& remove(char c);

	friend std::istream& operator >> (std::istream& is, CString& s);
	friend std::ostream& operator << (std::ostream& os, CString& s);

	~CString();
	
};



#endif // CSTRINGm_H
