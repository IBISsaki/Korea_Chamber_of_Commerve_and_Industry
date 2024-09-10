#ifndef STRING_REP_H
#define STRING_REP_H

class StringRep {
friend class String;

private:                            // 아무것도 안쓰면 기본적으로 private, 구조체는 public
    char *str_;
    int len_;
    int rc_;                        // 래퍼런스 카운터

    StringRep();
    StringRep(const char *s);
    StringRep(const StringRep& rhs);
    ~StringRep();
};

#endif