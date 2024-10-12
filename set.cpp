 #include "set.h"

Set::operator BitField(){
    return BitField(this -> _bitfield);
}

Set::Set(const BitField& tmp): _maxPower(tmp.GetLenght()), _bitfield(tmp){}

Set::Set(const Set& tmp) { _maxPower = tmp._maxPower; _bitfield = tmp._bitfield; }

Set::Set(const size_t maxPower):_bitfield(maxPower){_maxPower=maxPower;}

