//
// Created by user on 14.04.2020.
//

#include "Register.h"


RegisterPile::ConstRegister RegisterPile::reg_ax() const {
    return &RegisterPile::_ax;
}

RegisterPile::Register RegisterPile::reg_ax() {
    return &RegisterPile::_ax;
}

RegisterPile::ConstRegister RegisterPile::reg_bx() const {
    return &RegisterPile::_bx;
}

RegisterPile::Register RegisterPile::reg_bx() {
    return &RegisterPile::_bx;
}

RegisterPile::ConstRegister RegisterPile::reg_ay() const {
    return &RegisterPile::_ay;
}

RegisterPile::Register RegisterPile::reg_ay() {
    return &RegisterPile::_ay;
}

RegisterPile::ConstRegister RegisterPile::reg_by() const {
    return &RegisterPile::_by;
}

RegisterPile::Register RegisterPile::reg_by() {
    return &RegisterPile::_by;
}

double RegisterPile::get(RegisterPile::ConstRegister reg) const {
    return this->*reg;

}

void RegisterPile::set(RegisterPile::Register reg, unsigned int value) {
    this->*reg = value;
}

void RegisterPile::swap(RegisterPile::Register first, RegisterPile::Register second) {
    unsigned int temp = this->*first;
    this->*first = this->*second;
    this->*second = temp;
}


unsigned int RegisterPile::operator&(const unsigned int &b) {
    return (_ax&_bx);
}
