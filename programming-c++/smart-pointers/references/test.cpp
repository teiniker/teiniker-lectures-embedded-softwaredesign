#include <gtest/gtest.h>

// BasicsTest for Pointers and References
TEST(PointersAndReferencesGroup, BasicsTest) 
{
    // Setup
    int i = 7;
    
    int* ptr = &i;  // pointer to variable i: ptr -> i
    int& ref = i;   // reference (or alias) for i: ref -> i
    
    // Verify
    EXPECT_EQ(7, i);
    EXPECT_EQ(7, *ptr);
    EXPECT_EQ(7, ref);
}

// InitializationTest for Pointers and References
TEST(PointersAndReferencesGroup, InitializationTest) 
{
    // Setup
    int i = 7;
    
    // We can declare and initialize pointers in two steps.
    int* ptr;   // declaration
    ptr = &i;   // initialization
        
    // References must be initialized at declaration time.
    int& ref = i;

    // Verify
    EXPECT_EQ(7, *ptr);
    EXPECT_EQ(7, ref);
}

// Reassignment Test for Pointers and References
TEST(PointersAndReferencesGroup, Reassignment) 
{
    // Setup
    int i = 7;
    int j = 13;
    
    int* ptr = &i;  
    ptr = &j;  // A pointer can be re-assigned.
    
    // A reference cannot be re-assigned, but its referred value can change.
    int& ref = i;   
    ref = j;    // Reassign the value of i (instead of re-assigning the reference)
    
    // Verify
    EXPECT_EQ(13, *ptr);
    EXPECT_EQ(13, ref);
    EXPECT_EQ(13, i);
}

// NullPointerTest for Pointers
TEST(PointersAndReferencesGroup, NullPointerTest) 
{
    // Setup    
    int* ptr = nullptr;  // A pointer can be assigned nullptr
    
    // Verify
    EXPECT_EQ(nullptr, ptr);
}

// Indirection Test for Pointers and References
TEST(PointersAndReferencesGroup, IndirectionTest) 
{
    // Setup  
    int i = 7;
    
    // We can have pointers to pointers offering extra levels of indirection.  
    int* ptr = &i;      // A pointer to i (ptr -> i)
    int** ptrptr = &ptr; // A pointer to a pointer to i (ptrptr -> ptr -> i)

    // References only offer one level of indirection.
    int& ref = i; 
     
    // Verify
    EXPECT_EQ(ptr, *ptrptr);
    EXPECT_EQ(7, *(*ptrptr));
    EXPECT_EQ(7, ref);
}

// ArithmeticOperationsTest for Pointers and References
TEST(PointersAndReferencesGroup, ArithmeticOperationsTest) 
{
    // Setup    
    int array[] = {11, 22, 33}; 
    
    int* ptr = array;  
    int& ref = array[0];  
    
    // Verify
    // Various arithmetic operations can be performed on pointers.
    EXPECT_EQ(11, *ptr);
    EXPECT_EQ(22, *(ptr + 1));
    EXPECT_EQ(33, *(ptr + 2));
    
    // There is no Reference Arithmetic, but ref+1 is array[0]+1 and ref+2 is array[0]+2
    EXPECT_EQ(11, ref);
    EXPECT_EQ(12, ref + 1); // array[0] + 1
    EXPECT_EQ(13, ref + 2); // array[0] + 2
}
