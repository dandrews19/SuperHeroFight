#pragma once
#include <string>

enum POWER_ID
{
	POWER_STRENGTH,
	POWER_FLIGHT,
	POWER_LASER,
	POWER_INTEL,
	POWER_GADGETS,
	POWER_NATIONAL
};

class Power
{
public:

	// Class:
	//		Power
	// Name: 
	//		getID
	// Input:
	//		None
	// Output: 
	//		The POWER_ID of the power
	// Side effects: 
	//		None
	// Summary:
	//		The constructor of the appropriate child classes sets mPowerID
	//		This function returns that value
	POWER_ID getID();

	// Class:
	//		Power
	// Name: 
	//		use
	// Input:
	//		None
	// Output: 
	//		A string with the text when using the power
	// Side effects: 
	//		None
	// Summary:
	//		To be used during the fight sequence
	virtual std::string use() = 0;

	// Name: 
	//		Stream operator <<
	// Input:
	//		Standard for stream operator overload (stream and object)
	// Output: 
	//		Standard for stream overload (modified stream)
	// Side effects: 
	//		Displays the power's mDescription to the stream
	// Summary:
	//		Used when listing powers
	friend std::ostream& operator<<(std::ostream& out, const Power& p);

	// Class:
	//		Power
	// Name: 
	//		Fight
	// Input:
	//		A pointer to another power
	// Output: 
	//		An integer with the results of the fight...
	//		-1 = other power wins
	//		0 = tie
	//		1 = this power wins
	// Side effects: 
	//		Displays flavor text with COUT
	// Summary:
	//		Check the power grid on the assignment for the combinations
	virtual int fight(Power* otherPower) = 0;

	// Class:
	//		Power
	// Name: 
	//		destructor
	// Input:
	//		None
	// Output: 
	//		None
	// Side effects: 
	//		None
	// Summary:
	//		DO NOT CHANGE THIS FUNCTION
	//		NOTHING TO IMPLEMENT IN .CPP
	virtual ~Power() = default;

protected:
	// The description to be used in the << function
	std::string mDescription;
	// The POWER_ID to be used with fight (to check what the other power is)
	POWER_ID mPowerID;
};

class StrengthPower : public Power
{
public:
	// Class:
	//		StrengthPower
	// Name: 
	//		Constructor
	// Input:
	//		None
	// Output: 
	//		None
	// Side effects: 
	//		None
	// Summary:
	//		Set the member variables (defined in the parent class)
	StrengthPower();

	// See parent class for details
	virtual std::string use();
	virtual int fight(Power* other);
};


class FlightPower : public Power
{
public:
	// Class:
	//		FlightPower
	// Name: 
	//		Constructor
	// Input:
	//		None
	// Output: 
	//		None
	// Side effects: 
	//		None
	// Summary:
	//		Set the member variables (defined in the parent class)
	FlightPower();

	// See parent class for details
	virtual std::string use();
	virtual int fight(Power* other);
};

class LaserPower : public Power
{
public:
	// Class:
	//		LaserPower
	// Name: 
	//		Constructor
	// Input:
	//		None
	// Output: 
	//		None
	// Side effects: 
	//		None
	// Summary:
	//		Set the member variables (defined in the parent class)
	LaserPower();

	// See parent class for details
	virtual std::string use();
	virtual int fight(Power* other);
};

class IntelPower : public Power
{
public:
	// Class:
	//		IntelPower
	// Name: 
	//		Constructor
	// Input:
	//		None
	// Output: 
	//		None
	// Side effects: 
	//		None
	// Summary:
	//		Set the member variables (defined in the parent class)
	IntelPower();

	// See parent class for details
	virtual std::string use();
	virtual int fight(Power* other);
};

class GadgetPower : public Power
{
public:
	// Class:
	//		GadgetPower
	// Name: 
	//		Constructor
	// Input:
	//		None
	// Output: 
	//		None
	// Side effects: 
	//		None
	// Summary:
	//		Set the member variables (defined in the parent class)
	GadgetPower();

	// See parent class for details
	virtual std::string use();
	virtual int fight(Power* other);
};

class NationalPower : public Power
{
public:
	// Class:
	//		NationalPower
	// Name: 
	//		Constructor
	// Input:
	//		None
	// Output: 
	//		None
	// Side effects: 
	//		None
	// Summary:
	//		Set the member variables (defined in the parent class)
	NationalPower();

	// See parent class for details
	virtual std::string use();
	virtual int fight(Power* other);
};

// Name: 
//		powerFactory
// Input:
//		A string of the appropriate power name
// Output: 
//		A pointer to a newly created power (on the heap)
// Side effects: 
//		None
// Summary:
//		See the writeup for the expected power names
Power* powerFactory(const std::string& powerName);

