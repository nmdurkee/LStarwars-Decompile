/* Ghidra analysis pseudocode, not original source.
 * ev_5fe54c2a55e5805f81bff5ddaf4fd9cf0184cfdba0adc5a7ca08f803c24de38d
 * Entry: 0x6ede0b; label: __EH_prolog3
 */

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* Library Function - Single Match
    __EH_prolog3
   
   Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012 */

void __EH_prolog3(int param_1)

{
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  int *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  uint auStack_1c [5];
  undefined1 local_8 [8];
  
  param_1 = -param_1;
  *(undefined4 *)((int)auStack_1c + param_1 + 0x10) = unaff_EBX;
  *(undefined4 *)((int)auStack_1c + param_1 + 0xc) = unaff_ESI;
  *(undefined4 *)((int)auStack_1c + param_1 + 8) = unaff_EDI;
  *(uint *)((int)auStack_1c + param_1 + 4) = DAT_00829570 ^ (uint)&stack0x00000004;
  *(undefined4 *)((int)auStack_1c + param_1) = unaff_retaddr;
  *unaff_FS_OFFSET = (int)local_8;
  return;
}

