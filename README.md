# reflect
A c++ type reflection system  
###Introduction  
**reflect** is a very simple but powerful c++ reflection system, you may find it useful in you projection,espcially in projects which need codegen or serialization(codegen python code from cplusclpus)  
###Build  
Please use cmake for build, just run the flowing cmd  
***mkdir build && cd build && make***  
###Tutorial  
A very simple c++ example is presented.  
```cpp
class PhoneNumber{
BEGIN_TYPE(PhoneNumber)
    FIELDS(FIELD(&PhoneNumber::areaCode), FIELD(&PhoneNumber::number))
    CTORS(DEFAULT_CTOR(PhoneNumber), CTOR(PhoneNumber, const std::string&, const std::string&))
    METHODS(METHOD(&PhoneNumber::ToString))
END_TYPE
public:
    std::string areaCode;
    std::string number;

    PhoneNumber() {}
    PhoneNumber(const std::string& areaCode, const std::string& number) : areaCode(areaCode), number(number) {}
    
    std::string ToString() const{
        return areaCode + " " + number;
    }   
};

#define REGISTER(T) typeof(T); // Just call typeof for type registering


int main() {
    REGISTER(PhoneNumber);
    try {
        auto newPhone = Type::GetType("PhoneNumber", true)->GetConstructor({
                qualified_typeof(const std::string&),
                qualified_typeof(const std::string&)})->
                Invoke(std::string("+86"), std::string("13000000000"));
        auto str = Type::GetType("PhoneNumber")->GetMethod("ToString")->Invoke(newPhone);
        std::cout << str.Cast<std::string>() << std::endl;
    }   
    catch (const Exception& ex){
        std::cout << "error: " << ex.What() << "  at: " << ex.Where() << std::endl;
    }   
    return 0;
}
```


