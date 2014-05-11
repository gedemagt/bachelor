
#pragma once
class TString;
class Selector;

class Analyzer {
public:
	Analyzer(const char* dest) {
		this->dest = dest; 
	};

	virtual ~Analyzer(void) {};
	virtual void analyze(Selector *s) = 0;
	virtual void terminate() = 0;

	const char* getDestination(){
		return dest;
	};

private:
	const char* dest;
};