#pragma once

#include <ostream>

namespace VPL {

class PtrAdress{
public:
    PtrAdress(const void * ptr) : m_ptr{ptr} {}
    friend std::ostream & operator <<(std::ostream & oss, const PtrAdress adr) {
        return oss << "[ptr_adr=" << adr.m_ptr << "]";
    }
private:
    const void * m_ptr;
};

} // namespace VPL