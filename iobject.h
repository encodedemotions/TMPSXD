#pragma once

#include "data.h"


struct IObject {
	virtual Data on_send() = 0;

	virtual void on_receive(Data) = 0;

	virtual IObject *clone() = 0;
};