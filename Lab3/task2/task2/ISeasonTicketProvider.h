#pragma once
class ISeasonTicketProvider
{
public:
	~ISeasonTicketProvider() {}
	virtual void ticket() const = 0;
};