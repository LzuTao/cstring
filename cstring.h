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
	CString(const char* m_str, int m_length = 0);
	CString(const CString& copy);

	int getLength() const;

	CString& operator = (const CString& m_str);
	CString operator + (const CString& m_str) const;

	bool operator < (const CString& m_str) const;
	bool operator > (const CString& m_str) const;
	bool operator <= (const CString& m_str) const;
	bool operator >= (const CString& m_str) const;
	bool operator == (const CString& m_str) const;
	bool operator != (const CString& m_str) const;
	
	CString& expand(char c);
	CString& expand(const char* m_str);
	CString& expand(const CString& m_str);

	CString& remove(char c);

	friend std::istream& operator >> (std::istream& is, CString& s);
	friend std::ostream& operator << (std::ostream& os, CString& s);

	~CString();
	
};

#endif // CSTRING_H
