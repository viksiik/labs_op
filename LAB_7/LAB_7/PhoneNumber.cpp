#include "PhoneNumber.h"

namespace LAB7 {

    PhoneNumber::PhoneNumber(System::String^ phoneNumber) {
        if (!isValidCountry(phoneNumber)) {
            throw gcnew System::Exception("Невідповідність країни");
        }
        if (!isValidFormat(phoneNumber)) {
            throw gcnew System::Exception("Невідповідність формату");
        }
        number = phoneNumber;
    }

    bool PhoneNumber::isValidFormat(System::String^ phoneNumber) {
        System::Text::RegularExpressions::Regex^ pattern = gcnew System::Text::RegularExpressions::Regex("^(\\+38\\(0\\d{2}\\)\\d{3}-\\d{2}-\\d{2})$");
        return pattern->IsMatch(phoneNumber);
    }

    bool PhoneNumber::operator==(const PhoneNumber^ other) {
        return number->Equals(other->number);
    }

    bool PhoneNumber::isIncluded(const PhoneNumber^ target) {
        return number->Contains(target->number);
    }

    System::String^ PhoneNumber::ToString() {
        return number;
    }

    bool PhoneNumber::isValidCountry(System::String^ phoneNumber) {
        System::Text::RegularExpressions::Regex^ pattern = gcnew System::Text::RegularExpressions::Regex("^\\+38");
        return pattern->IsMatch(phoneNumber);
    }


}