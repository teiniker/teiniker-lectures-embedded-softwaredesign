#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>


TEST_GROUP(PointersAndReferencesGroup)
{
};


TEST(PointersAndReferencesGroup, BasicsTest)
{
    // Setup
    int i = 7;
    
    int* ptr = &i;  // pointer to variable i: ptr -> i
    
    int& ref = i;   // reference (or alias) for i: ref -> i
    
    // Verify
    CHECK_EQUAL(7, i);
    CHECK_EQUAL(7, *ptr);
    CHECK_EQUAL(7, ref);    
}


TEST(PointersAndReferencesGroup, InitializationTest)
{
    // Setup
    int i = 7;
    
    // We can declare and initialize pointers in two steps.
    int* ptr;   // declaration
    ptr= &i;    // initialization
        
    // We cannot do that with references.
    // References must be initialized at declatation time.
    // int& ref;  // error: ‘ref’ declared as reference but not initialized
    // ref = i;     
    int& ref = i;

    // Verify
    CHECK_EQUAL(7, *ptr);
    CHECK_EQUAL(7, ref);
}


TEST(PointersAndReferencesGroup, Reassignment)
{
    // Setup
    int i = 7;
    int j = 13;
    
    int* ptr = &i;  
    ptr = &j;   // A pointer can be re-assigned.
                // This is useful for implementation of data structures like linked list.
    
    // A reference cannot be re-assigned, and must be assigned at initialization.
    int& ref = i;   
    ref = j;    // reassign the value of i (instead of re-assigning the reference)
    
    // Verify
    CHECK_EQUAL(13, *ptr);
    CHECK_EQUAL(13, ref);
    CHECK_EQUAL(13, i);
}

TEST(PointersAndReferencesGroup, NullPointerTest)
{
    // Setup    
    int* ptr = NULL;  // A pointer can be assigned NULL
    
    // int& ref = NULL;  // A reference cannot be assigned NULL
    
    // Verify
    POINTERS_EQUAL(NULL, ptr);
}


TEST(PointersAndReferencesGroup, IndirectionTest)
{
    // Setup  
    int i = 7;
    
    //  We can have pointers to pointers offering extra levels of indirection.  
    int* ptr = &i;  // A pointer to i (ptr -> i)
    int** ptrptr = &ptr; // A pointer to a pointer to i (ptrptr -> ptr -> i)

    // References only offer one level of indirection.
    int& ref = i; 
    // int&& refref = ref;
     
    
    // Verify
    POINTERS_EQUAL(ptr, *ptrptr);
    POINTERS_EQUAL(7, *(*ptrptr));
    CHECK_EQUAL(7, ref);
}


TEST(PointersAndReferencesGroup, ArithmeticOperationsTest)
{
    // Setup    
    int array[] = {11,22,33}; 
    
    int* ptr = array;  
    
    int& ref = array[0];  
    
    // Verify
    // Various arithmetic operations can be performed on pointers.
    CHECK_EQUAL(11, *ptr);
    CHECK_EQUAL(22, *(ptr+1));
    CHECK_EQUAL(33, *(ptr+2));
    
    // There is no Reference Arithmetic
    CHECK_EQUAL(11, ref);
    CHECK_EQUAL(12, ref+1); // array[0]+1
    CHECK_EQUAL(13, ref+2); // array[0]+2
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
