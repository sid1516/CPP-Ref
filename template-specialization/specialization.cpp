#include <iostream>

/* The compiler prefers specialization in this order (most preferred to least): 
        fully specialized, partially specialized, primary template
*/
//Primary Template: must be declared first
template <typename T, int Line, int Column> class Matrix;

//Partial Specialization: only supported for class templates
template <typename T>
class Matrix<T, 3, 3>{};

//Full Specialization
template <>class Matrix<int, 3, 3>{};

/*
    Rules for the correct specialization:
        1. If only one specialization is found, then it is used.
        2. If the compiler finds more than one specialization, it uses the most specialized one.
        3. If no specialization is found, then the primary template is used.
*/