#pragma once
#include <iostream>
#include <stdexcept>
#include <regex>

namespace LAB7 {

	using namespace System;
	using namespace System::Text::RegularExpressions;

	public ref class PhoneNumber
	{
	private:
		String^ number;

	public:
		PhoneNumber(String^ phoneNumber);

		bool isValidFormat(String^ phoneNumber);

		bool operator==(const PhoneNumber^ other);

		virtual String^ ToString() override;

		bool isIncluded(const PhoneNumber^ target);

		bool isValidCountry(String^ phoneNumber);

	};

}
