//
// Created by user on 12.04.2020.
//
#include <iostream>

using namespace std;

class RegisterPile {
private:
    unsigned int _ax;
    unsigned int _bx;
    unsigned int _ay;
    unsigned int _by;
public:
    typedef unsigned int RegisterPile::*Register;
    typedef const unsigned int RegisterPile::*ConstRegister;

    explicit RegisterPile(unsigned int ax = 0xFFFFFF01,
                          unsigned int bx = 0xEEEEEE01,
                          unsigned int ay = 0xDDDDDD01,
                          unsigned int by = 0xCCCCCC01) : _ax(ax), _bx(bx), _ay(ay), _by(by) {}

    ConstRegister reg_ax() const;

    Register reg_ax();

    ConstRegister reg_bx() const;

    Register reg_bx();

    ConstRegister reg_ay() const;

    Register reg_ay();

    ConstRegister reg_by() const;

    Register reg_by();

    double get(ConstRegister reg) const;

    void set(Register reg, unsigned int value);

    void swap(Register first, Register second);

    unsigned int operator&(const unsigned int& b);

    ostream &show(ostream &os) const {
        return os << '(' << _ax << ',' << _bx << ',' << _ay << ',' << _by << ')' << endl;
    }

};


//typedef RegisterPile& (*CalculatorOperation) (RegisterPile &, RegisterPile::ConstRegister &);
