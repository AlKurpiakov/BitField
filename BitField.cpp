#include "BitField.hpp"


BitField::BitField(size_t sizeBit) {
    _sizeBit = sizeBit;
    _sizeMem = (_sizeBit / (8*(sizeof(uint16_t)) + (sizeBit % (8*sizeof(uint16_t)) != 0);
    _mem = new uint16_t[_sizeMem];
    for (size_t i = 0; i<_sizeMem; ++i)
        _mem[i] = 0;
}

BitField::~BitField() {
    _sizeMem = 0;
    _sizeBit = 0;
    delete[] _mem;
    _mem = nullptr;
}

BitField::BitField(const BitField &tmp) {
    _sizeBit = tmp._sizeBit;
    _sizeMem = tmp._sizeMem;
    _mem = new uint16_t[_sizeMem];
    for (int i = 0; i < _sizeBit; i++)
        _mem[i] = tmp._mem[i];
}

size_t BitField::GetMemIndex(size_t n) {
    return n / 16 + (sizeBit % (8*sizeof(uint16_t)) != 0);
}

uint16_t BitField::GetMask(size_t n) {
    return n & 15;
}

void BitField::SetBit(size_t n) {
    _mem[GetMemIndex(n)] += GetMask(n);
}

void BitField::ClrBit(size_t n) {
    _mem[GetMemIndex(n)] ^= GetMask(n);
}

uint8_t BitField::GetBit(size_t n) {
    uint8_t tmp = _mem[GetMemIndex(n)];
    tmp &= GetMask(n);
    tmp >> n & 15;
    return tmp;
}

size_t BitField::GetLenght() const {
    return _sizeBit; 
}

BitField& BitField::operator=(const BitField &tmp) {
    if (_sizeMem != tmp._sizeMem){
        _sizeMem = tmp._sizeMem;
        _sizeMem = tmp._sizeMem;
        delete [] _mem;
        _mem = new uint16_t[_sizeMem];
    }
    for (size_t i = 0; i<_sizeMem; ++i)
        _mem[i] = tmp._mem;
    
}

bool BitField::operator==(const BitField &tmp) const {
    for (int i = 0; i < _sizeMem; i++)
        if (_mem[i] != tmp._mem[i])
            return false;
    return true;
}

void BitField::operator~() {
    for (int i = 0; i < _sizeMem; i++)
        ~_mem[i];
}

BitField& BitField::operator&(const BitField &tmp) const {
    BitField result(_sizeBit);
    for (int i = 0; i < _sizeMem; i++)
        result._mem[i] = _mem[i] & tmp._mem[i];
    return result;
}


BitField& BitField::operator|(const BitField &tmp) const {
    BitField result(_sizeBit);
    for (int i = 0; i < _sizeMem; i++)
        result._mem[i] = _mem[i] | tmp._mem[i];
    return result;
}

BitField& BitField::operator^(const BitField &tmp) const {
    BitField result(_sizeBit);
    for (int i = 0; i < _sizeMem; i++)
        result._mem[i] = _mem[i] ^ tmp._mem[i];
    return result;
}

BitField& BitField::Universe() {
    BitField result(_sizeBit);
    for (int i = 0; i < _sizeMem; i++)
        result._mem[i] = 65535;
    return result;

}
