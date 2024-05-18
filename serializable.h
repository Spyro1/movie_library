#ifndef SERIALIZABLE_H_INCLUDED
#define SERIALIZABLE_H_INCLUDED

#include "memtrace.h"

class Serializable {
public:
    virtual void write(std::ostream& os) const {}
    virtual void read_from_file(std::ifstream& ifs, char s) = 0;
    virtual void write_to_file(std::ofstream& ofs, char s) const {}
    virtual ~Serializable() {}
};

#endif //SERIALIZABLE_H_INCLUDED
