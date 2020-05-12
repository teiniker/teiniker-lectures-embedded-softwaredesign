# Shared Pointer

Shared pointer implement a **reference counting ownership model**.

Objects of **shared_ptr** types have the ability of taking ownership of 
a pointer and share that ownership: once they take ownership, the group 
of owners of a pointer become responsible for its deletion when the last 
one of them releases that ownership.

Shared_ptr objects release ownership on the object they co-own as soon 
as they themselves are destroyed, or as soon as their value changes either 
by an assignment operation or by an explicit call to shared_ptr::reset. 

Once all shared_ptr objects that share ownership over a pointer have 
released this ownership, the managed object is deleted (normally by 
calling ::delete, but a different deleter may be specified on construction).


## Example

```C++
TEST(MailTestGroup, SharedPointerTest)
{
    shared_ptr<Mail> mail(new Mail("homer.simpson@springfield.com"));  
    
    {
        shared_ptr<Mail> copy = mail;  
        cout << "#counts(copy)=" << copy.use_count() << endl;    
	// copy goes out of scope (use_count = 1)        
    }
    
    cout << "#counts(mail)=" << mail.use_count() << endl;     
    
    // Verify
    CHECK_EQUAL("homer.simpson@springfield.com", mail->address());
    
    // mail goes out of scope (use_count = 0 => delete)
}
```

## References
Bjarne Stroustrup. **The C++ Programming Language.** Pearson 4th Edition 2017
* Chapter 34.3: Resource Management Pointers

[std::shared_ptr](http://www.cplusplus.com/reference/memory/shared_ptr/)

*Egon Teiniker, 2020, GPL v3.0*
