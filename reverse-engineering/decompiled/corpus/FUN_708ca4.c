/* Ghidra analysis pseudocode, not original source.
 * ev_67f98f38a95887d623f2b825230000473143cb3f5ba4a0d09463374d55adf1d2
 * Entry: 0x708ca4; label: __NLG_Notify1
 */

/* Library Function - Single Match
    __NLG_Notify1
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

undefined4 __NLG_Notify1(void)

{
  undefined4 in_EAX;
  undefined4 in_ECX;
  undefined4 unaff_EBP;
  
  DAT_0082a7d0 = in_ECX;
  DAT_0082a7cc = in_EAX;
  DAT_0082a7d4 = unaff_EBP;
  return in_EAX;
}

