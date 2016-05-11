#include <cstring>
#include <cstdio>
#include <iostream>
#include "CString.h"

CString::CString(): str(NULL), length(0) {}

CString::CString(char c): length(1) {
    str = new char[1];
    str[0] = c;
}

CString::CString(const char* m_Str, int m_length): length(m_length) {
	int len = strlen(m_Str);
	if (m_length <= 0 || length < m_length)
		length = len;
	
    str = new char[length];
    memcpy(str, m_Str, length);
}

CString::CString(const CString& copy) {
    length = copy.length;
    str = new char[length];

    memcpy(str, copy.str, length);
}

int CString::getLength() const {
    return length;
}

CString& CString::operator = (const CString& copy) {
    if (this != &copy) {
        this->length = copy.length;

        delete[] this->str;
        this->str = new char[copy.length];
        memcpy(this->str, copy.str, this->length);
    }

    return *this;
}

CString CString::operator + (const CString& m_Str) const {
    CString Str2;
    Str2.length = this->length + m_Str.length;
    Str2.str = new char[Str2.length];

    memcpy(Str2.str, this->str, this->length);
    memcpy(Str2.str + this->length, m_Str.str, m_Str.length);

    return Str2;
}

bool CString::operator < (const CString& m_Str) const {
    int min;
    min = (length < m_Str.length) ? length: m_Str.length;
    return (strncmp(str, m_Str.str, min) < 0);
}

bool CString::operator > (const CString& m_Str) const {
    int min;
    min = (length > m_Str.length) ? length: m_Str.length;
    return (strncmp(str, m_Str.str, min) > 0);
}

bool CString::operator <= (const CString& m_Str) const {
    int min;
    min = (length > m_Str.length) ? length: m_Str.length;
    return (strncmp(str, m_Str.str, min) <= 0);
}

bool CString::operator >= (const CString& m_Str) const {
    int min;
    min = (length > m_Str.length) ? length: m_Str.length;
    return (strncmp(str, m_Str.str, min) >= 0);
}

bool CString::operator == (const CString& m_Str) const {
    int min;
    min = (length > m_Str.length) ? length: m_Str.length;
    return strncmp(str, m_Str.str, min) == 0;
}

bool CString::operator != (const CString& m_Str) const {
    int min;
    min = (length > m_Str.length) ? length: m_Str.length;
    return strncmp(str, m_Str.str, min) != 0;
}

CString& CString::expand(char c) {
    *this = *this + CString(c);

    return *this;
}

CString& CString::expand(const char* m_Str) {
    *this = *this + CString(m_Str);

    return *this;
}

CString& CString::expand(const CString& m_Str) {
    *this = *this + m_Str;

    return *this;
}

CString& CString::remove(char c) {
    char* m_str = new char[length];
    int count = 0;

    for (int i = 0; i < length; ++i) {
         if (str[i] != c) {
             m_str[count] = str[i];
             ++count;
         }
     }

    delete[] str;
    str = new char[count];
    memcpy(str, m_str, count);

    delete[] m_str;

    return *this;
}

std::istream& operator >> (std::istream& is, CString& s) {
    delete[] s.str;
    
    const short LEN = 100;
    int i = 0;
    s.length = 0;

    char* m_Str1 = NULL;
    char* m_Str2 = NULL;

    m_Str1 = new char[LEN];

    char c;

    while ((c = getchar()) != '\n') {

        m_Str1[s.length] = c;
        ++s.length;
        ++i;

        if (i == LEN) {
            m_Str2 = new char[s.length];
            memcpy(m_Str2, m_Str1, s.length);

            delete[] m_Str1;

            m_Str1 = new char[s.length + LEN];
            memcpy(m_Str1, m_Str2, s.length);

            delete[] m_Str2;

            i = 0;
        }

    }

    s.str = new char[s.length];
    memcpy(s.str, m_Str1, s.length);

    delete[] m_Str1;
    return is;
}

std::ostream& operator << (std::ostream& os, CString& s) {
    char* newStr = new char[s.length + 1];
    memcpy(newStr, s.str, s.length);

    newStr[s.length] = '\0';
    os << newStr;

    delete[] newStr;
    return os;
}

CString::~CString() {
    delete[] this->str;
}

