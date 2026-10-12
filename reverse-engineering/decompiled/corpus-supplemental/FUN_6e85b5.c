/* Ghidra pseudocode, not original source.
 * ev_659eea1dc00a859f9d32b97d98369d0a367714cfb07a93b4448bfffc51247c8f
 * Entry: 0x6e85b5; label: __purecall
 * Boundary hypotheses: reports/native-supplemental-entry-inspection.json.
 */

/* Library Function - Single Match
    __purecall
   
   Library: Visual Studio 2005 Release */

void __purecall(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)FUN_006f01bc(DAT_0297caec);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)();
  }
  FUN_006f09f8(0x19);
  __set_abort_behavior(0,1);
  FUN_006f4c48();
  return;
}

