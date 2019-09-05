//
//  Header.h
//  LabWork23
//
//  Created by Julian Tiu on 3/30/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#pragma once
#include "Shape.h"

class Triangle : public Shape {

private:
    
    Point v1();
    Point v2();
    Point v3();
    
public:
    
    Triangle();
    
    void draw();
    void print_parameters();
    
};