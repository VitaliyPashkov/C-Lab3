#pragma once
#include "ISeasonTicketProvider.h"
#include "Stadion.h"
class SportInventory : public Stadion {
public:
	SportInventory();
	
	
protected:
	int abonement_count_;
};