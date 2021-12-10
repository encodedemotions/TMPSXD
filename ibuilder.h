#pragma once

#include "iobject.h"

struct IBuilder {
	virtual IObject *build() = 0;
};
