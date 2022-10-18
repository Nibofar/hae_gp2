#pragma once
class Lib {
public:
	static void Memcpy(char* dest, const char* src, int size) {
		for (int i = 0; i < size; i++) {
			dest[i] = src[i];
		}
	}
	static const char* StrChr(const char* src, char c) {
		while (*src && (*src != c)) {
			src++;
			if (!*src) return nullptr;
			return src;
		}
	}
	static const char* StrStr(const char* src, const char* substr) {
		while (*src && !Verif(*src, src, substr)) {
			src++;
			if (!*src) return nullptr;
			return src;
		}
	}
	static bool Verif(int ptr,  const char* src, const char* substr) {
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
};