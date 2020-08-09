//
//  main.cpp
//  SparseArrayInt
//
//  Created by Артём Никитин on 09.08.2020.
//  Copyright © 2020 Артём Никитин. All rights reserved.
//

#include "../SparseArrayInt/SparseArrayInt.h"
#include <iostream>

int SparseArrayInt::Interm::operator=(int x)
{
    if (x == 0)
        Remove();
    else
        Provide() = x;
    return x;
}

int SparseArrayInt::Interm::operator+=(int x)
{
    int &location = Provide();
    location += x;
    int res = location;
    if (res == 0)
        Remove();
    return res;
}

int SparseArrayInt::Interm::operator++()
{
    int &location = Provide();
    int res = ++location;
    if (location == 0)
        Remove();
    return res;
}

int SparseArrayInt::Interm::operator++(int)
{
    int &location = Provide();
    int res = ++location;
    if (location == 0)
        Remove();
    return res;
}

SparseArrayInt::Interm::operator int()
{
    Item *tmp;
    for (tmp = master -> first; tmp; tmp -> next)
    {
        if (tmp -> index == index)
            return tmp->value;
    }
    return 0;
}

SparseArrayInt::~SparseArrayInt()
{
    while(first)
    {
        Item *tmp = first;
        first = first -> next;
        delete tmp;
    }
}

int &SparseArrayInt::Interm::Provide()
{
    Item *tmp;
    for (tmp = master->first; tmp; tmp = tmp->next)
    {
        if (tmp->index == index)
            return tmp->value;
    }
    tmp = new Item;
    tmp -> index = index;
    tmp -> next = master->first;
    master -> first = tmp;
    return tmp -> value;
}

void SparseArrayInt::Interm::Remove()
{
    Item **tmp;
    for (tmp = &(master -> first); *tmp; tmp = &(*tmp) -> next)
    {
        if ((*tmp)->index == index)
        {
            Item *to_delete = *tmp;
            *tmp = (*tmp)->next;
            delete to_delete;
            return;
        }
    }
}

int main(int argc, const char * argv[])
{
    SparseArrayInt arr;
    int x;
    x = arr[500];
    arr[300] = 50;
    arr[200] = 0;
    std::cout << arr[300] << "\n";
    std::cout << arr[300] << "\n";
    return 0;
}
