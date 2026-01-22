int astrlen(char *str);
int astrcmp(char *str1, char *str2);
char* astrcat(char *s, char *t);
char* astrncat(char *s, char *t, int n);
char* astrcpy(char *s,char *t);
char* astrncpy(char *des,char *source, int n);
char* astrncmp(char *s1, char *s2, int n);
int astrcasecmp(const char *str1, const char *str2);
int astrncasecmp(const char *str1, const char *str2, int n);
char* astrchr(const char *s, int c);
char* astrrchr(const char *s, char c);

