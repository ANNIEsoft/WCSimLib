


all: WCSimRootDict.cc 
	g++ -fPIC --shared --std=c++1y src/*.cc WCSimRootDict.cc -I include `root-config --libs --cflags` -o libWCSimRoot.so

WCSimRootDict.cc:
	rootcint -f WCSimRootDict.cc -c -p include/*.hh include/WCSimRootLinkDef.h

clean:
	rm WCSimRootDict.cc
	rm libWCSimRoot.so
