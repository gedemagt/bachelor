
#pragma once
class TString;
class Selector;

class Analyzer {
public:
	Analyzer(void) {};
	virtual ~Analyzer(void) {};
	virtual void analyze(Selector *s) = 0;
	virtual void terminate() = 0;
	virtual const char* getDestination() = 0;
};