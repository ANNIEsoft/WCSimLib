#include "WCSimRootEvent_wrapper.hh"
#include "WCSimRootTrigger_wrapper.hh"

inline WCSimRootTrigger_wrapper WCSimRootEvent_wrapper::GetTrigger(int number) {
  return WCSimRootTrigger_wrapper(evt->GetTrigger(number));
}
