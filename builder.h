#pragma once
#include "object.h"
struct IBuilder {
	virtual IObject* build() = 0;
};
