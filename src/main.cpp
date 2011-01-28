/* 
 * File:   main.cpp
 * Author: sbidny
 *
 * Created on January 25, 2011, 10:40 AM
 */

#include <cstdlib>
#include <iostream>

#include "Namespace.hpp"
#include "Object.h"
#include "Objectify.hpp"
#include "Class.hpp"
#include "Convert.hpp"
#include "Number.hpp"
#include "Pointer.hpp"
#include "Integer.hpp"

using namespace std;

int main(int argc, char** argv)
{
    Integer i(5);
    cout << i.toString() << endl;
    return EXIT_SUCCESS;
}

