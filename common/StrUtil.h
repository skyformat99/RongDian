#pragma once

enum UTF8_TYPE
{
	UTF8_INVALID = 0,
	UTF8_NOBOM,
	UTF8_BOM,
	UTF8_ACSII
};

namespace StrUtil
{
// Ansic To Unicode 
unsigned int a2w(const char * astr, wchar_t *wstr);
// Unicode To Ansic
unsigned int w2a(const wchar_t *wstr, char *astr);
// Ansic To UTF8(no Bom)
unsigned int a2u8(const char *astr, char *utf8);
// UTF8 To Ansic(no Bom)
unsigned int u82a(const char *utf8, char *astr);
// Unicode To UTF8(no Bom)
unsigned int u2u8(const wchar_t *wstr, char *utf8);
// UTF8 To Unicode(no Bom)
unsigned int u82u(const char *utf8, wchar_t *wstr);

wchar_t* a2w(const char *astr);

char* w2a(const wchar_t *wstr);

char* a2u8(const char *astr);

char* u82a(const char *utf8);

wchar_t* u82u(const char *utf8);

int is_special_utf8(unsigned char c);

int is_utf8(const char *str);

int is_gb2312(const char *str);

int is_big5(const char *str);

int is_gbk(const char *str);

int get_coder(const char *str);

int wcstrim(wchar_t *str, int len);

int strtrim(char *str, int len);
}

