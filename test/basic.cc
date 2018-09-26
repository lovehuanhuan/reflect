#include "reflection.h"


using namespace std;

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
        std::cout << str.Cast<string>() << std::endl;
    }
    catch (const Exception& ex){
        std::cout << "error: " << ex.What() << "  at: " << ex.Where() << std::endl;
    }
    return 0;
}
