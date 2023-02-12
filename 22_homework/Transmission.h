#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Transmission
{
	enum class TransmissionType { Mechanics, Automaton, Robot, Variator };
	TransmissionType transmissionType;
public:
	Transmission(TransmissionType transmissionType = TransmissionType::Mechanics)
		: transmissionType(transmissionType) {}
	string GetType() const
	{
		switch (transmissionType)
		{
		case Transmission::TransmissionType::Mechanics:
			return "Mechanics";
		case Transmission::TransmissionType::Automaton:
			return "Automaton";
		case Transmission::TransmissionType::Robot:
			return "Robot";
		case Transmission::TransmissionType::Variator:
			return "Variator";
		default:
			return "";
		}
	}
	void Show() const
	{
		cout << GetType() << endl;
	}
};