#pragma once
class Lib {
public:
	static void Memcpy(char* dest, const char* src, int size) {
		for (int i = 0; i < size; i++) {
			dest[i] = src[i];
		}
	}
	static void MemcpyRec(char* dest, const char* src, int size) {
		if (size <= 0) return;
		*dest = *src;
		MemcpyRec(dest + 1, src + 1, size - 1);
		return;
	}
	static const char* StrChr(const char* src, char c) {
		while (*src && (*src != c)) {
			src++;
			if (!*src) return nullptr;
			return src;
		}
	}
	static const char* StrChrRec(const char* src, char c) {
		if (!*src) return nullptr;
		if (*src == c) return src;
		return StrChrRec(src + 1, c);
	}
	static const char* StrStr(const char* src, const char* substr) {
		while (*src && !Verif(*src, src, substr)) {
			src++;
			if (!*src) return nullptr;
			return src;
		}
	}
	static bool Verif(int ptr, const char* src, const char* substr) {
		int idx = sizeof(substr);
		for (int i = 0; i < sizeof(substr); i++) {
			if (src[ptr + i] != substr[i]) idx--;
		}
		if (idx == sizeof(substr)) return true;
		else return false;
	}
	static bool StrPrefix(const char* src, const char* substr) {
		int i = 0;
		while (substr[i]) {
			if (substr[i] != src[i])return false;
			else i++;
		}
		return true;
	}
	static const char* StrStrRec(const char* src, const char* substr) {
		if (!*src) return nullptr;
		if (*src == 0) {
			if (*src == *substr) return src;
			return nullptr;
		}
		if (StrPrefixRec(src, substr)) return src;
		const char* subRequest = StrStrRec(src++, substr);
		return subRequest;
	}
	static bool StrPrefixRec(const char* src, const char* c) {
		if (src == nullptr) return false;
		if (*src == 0) return true;
		if (*src != *c) return false;
		return StrPrefixRec(src++, c++);
	}
	static int add(int a, int b) {
		if (b == 0) return a;
		if (a == 0) return b;
		if (b < 0)return add(a--, b++);
		return add(a++, b--);
	}
	static int sub(int a, int b) {
		return add(a, -b);
	}
	static int mul(int a, int b) {
		if (b == 0 || a == 0) return 0;
		if (a == 1) return b;
		if (b == 1) return a;
		if (b > 0) return add(a, mul(a, b - 1));
		else return -mul(a, -b);
	}
	static int div(int a, int b) {
		if (a == 0) return 0;
		if (b == 0) throw "assert";
		if (b == 1) return a;
		if (a == b) return 1;
		if (b < 0) return -div(a, -b);
		if (a < 0) return -div(-a, b);
		if (a < b) return 0;
		return 1 + div(sub(a, b), b);
	}
	static int strlenRec(const char* str) {
		if (!*str) return 0;
		return 1 + strlenRec(str + 1);
	}
	static void strcpyRec(char* dst, const char* src) {
		if (!src) return;
		if (!*src) {
			*dst = 0;
			return;
		}
		*dst = *src;
		return strcpyRec(dst++, src++);
	}
	static void strncpyRec(char* dst, const char* src, int charMaxToCopy) {
		if (charMaxToCopy <= 0) return;
		if (!src) return;
		if (!*src) {
			*dst = 0;
			return;
		}
		*dst = *src;
		return strncpyRec(dst + 1, src + 1,charMaxToCopy - 1);
	}
	static void zeroMemoryRec(char* mem, int nbBytes) {
		if (!mem) return;
		if (nbBytes <= 0) return;
		*mem = 0;
		zeroMemoryRec(mem - 1, nbBytes - 1);
	}
	static int strcmpRec(const char* a, const char* b) {
		if (!*a && !*b) return 0;
		if (!*b || (*a > *b)) return 1;
		if (!*a || (*a < *b)) return -1;
		return strcmpRec(a + 1, b + 1);
	}
	static int mulTerminalRecursion(int a, int b, int res = 0) {
		if (a == 0 || b == 0) return res;
		if (a == 1) return b + res;
		if (b == 1) return a + res;
		if (b > 0) {
			return mulTerminalRecursion(a, b - 1, a + res);
		}else {
			return mulTerminalRecursion(a, -b, -res);
		}
	}
	static int divTerminalRecursion(int a, int b, int res = 0) {
		if (a == 0) return res;
		if (b == 0) throw "assert";
		if (b == 1) return a + res;
		if (a == b) return 1 + res;
		if (b < 0) return -divTerminalRecursion(a, -b, -res);
		if (a < 0) return -divTerminalRecursion(-a, b, res);
		if (a < b) return res;
		return 1 + divTerminalRecursion(sub(a, b), b, res);
	}
	static void testLib() {
		/*const char stock[] = "lapin";
		 char nuCopy[5];
		MemcpyRec(nuCopy, stock, 6);
		printf("ok");
		int div = div(6, 3);
		int size = strlenRec("lapin");
		int cmp = strcmpRec("lapin", "lapine");*/
		int res = divTerminalRecursion(10, 3);
		int here = 0;
	}
};