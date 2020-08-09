//
//  SparseArrayInt.h
//  SparceArrayInt
//
//  Created by Артём Никитин on 09.08.2020.
//  Copyright © 2020 Артём Никитин. All rights reserved.
//

#ifndef SparseArrayInt_h
#define SparseArrayInt_h
class SparseArrayInt
{
    struct Item
    {
        int index;
        int value;
        Item *next;
    };
    Item *first;
public:
    SparseArrayInt() : first(0) {}
    ~SparseArrayInt();
    class Interm
    {
        friend class SparseArrayInt;
        SparseArrayInt *master;
        int index;
        Interm(SparseArrayInt *a_master, int ind) : master(a_master), index(ind) {}
        int& Provide();
        void Remove();
    public:
        operator int();
        int operator=(int x);
        int operator+=(int x);
        int operator++();
        int operator++(int);
        SparseArrayInt GetMaster() const
        {
            return *master;
        }
    };
    friend class Interm;
    Interm operator[](int idx)
    {
        return Interm(this, idx);
    }
    
private:
    SparseArrayInt(const SparseArrayInt&){}
    void operator=(const SparseArrayInt&){}
};


#endif /* SparseArrayInt_h */
