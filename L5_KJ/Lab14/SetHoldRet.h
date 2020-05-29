#pragma once

class SetHoldRet
{
public:
    template<typename T> 
    void base(T value)                  // sets static variable of type T
                                        // in variableHolder
    {
        variableHolder<T>() = value;
    }
    
    
    template<typename T>
    T& product()                        // returns static variable of type T
                                        // which is being hold in variableHolder
    {
        return variableHolder<T>();
    }
    
    
private:
    template<typename T>                 
    T& variableHolder()                 // stores static variable of type T
    {
        static T toHold;
        return toHold;
    }
};