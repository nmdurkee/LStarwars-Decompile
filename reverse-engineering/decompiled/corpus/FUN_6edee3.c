/* Ghidra analysis pseudocode, not original source.
 * ev_5fe54c2a55e5805f81bff5ddaf4fd9cf0184cfdba0adc5a7ca08f803c24de38d
 * Entry: 0x6edee3; label: __EH_epilog3
 */

/* WARNING: This is an inlined function */
/* Library Function - Single Match
    __EH_epilog3
   
   Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012 */

void __EH_epilog3(void)

{
  undefined4 *unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  
  *unaff_FS_OFFSET = unaff_EBP[-3];
  *unaff_EBP = unaff_retaddr;
  return;
}

