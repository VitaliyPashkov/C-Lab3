#pragma once

class IShuffle
{
protected:
	~IShuffle() = default;

public:
	virtual void shuffle() = 0;
	virtual void shuffle(size_t i, size_t j) = 0;
};