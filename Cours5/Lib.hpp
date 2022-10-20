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
};