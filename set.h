#pragma once
#include "BitField.hpp"

class Set : public BitField{
private:
    BitField _bitfield;
    size_t _maxPower;
public:
    Set(size_t maxPower);
    Set(const Set& tmp);
    Set(const BitField& tmp);

    operator BitField();
    void InsElem (uint64_t elem);
    void DelElem(uint64_t elem);
    size_t GetMaxPow() const;
    bool IsMember(uint64_t elem);

    bool operator==(const Set& tmp);
    Set operator+(const Set& tmp);
    Set operator+(uint64_t elem);
    Set operator-(uint64_t elem);
    Set operator*(const Set& elem);
    Set operator~();
    friend istream& operator>>(istream& is, Set& tmp);
    friend ostream& operator<<(ostream& is, const Set& tmp);
};
