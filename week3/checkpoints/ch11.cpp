//chapter 11 checkpoints
//11.14
//class named Pet. Write a prototype for a member function of pet that
//overloads the = operator
Pet& operator=(const Pet &right);

//textbook sol
Pet Pet :: operator=(const Pet);

//11.15
//dog and cat are Pet instances with overloaded =. rewrite dog = cat;
dog.operator=(cat);

//11.16
//disadvatange of an overloaded = operator returning void is that it cannot
//be used in multiple assignments (cascade). Better to have a return value that is a reference to the LHS

//11.17
//this pointer is the address to the object instance. Its a built in pointer
//available to a classes instance's member functions, that always points
//to the instance of the class making the function call

//11.18
//this pointer is automatically passed to instance member functions

//11.26
list1.operator[](25);
