/* Ghidra analysis pseudocode, not original source.
 * ev_fd88e83c03467170e633a7d88452db02a14be58504554e3319fa3a0da483c1d2
 * Entry: 0x4ff430; label: FUN_004ff430
 */

longlong FUN_004ff430(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  LARGE_INTEGER liDistanceToMove;
  PLARGE_INTEGER lpNewFilePointer;
  BOOL BVar1;
  uint unaff_retaddr;
  
  if (param_4 == 0) {
    lpNewFilePointer = (PLARGE_INTEGER)0x0;
  }
  else if (param_4 == 1) {
    lpNewFilePointer = (PLARGE_INTEGER)0x1;
  }
  else {
    lpNewFilePointer = (PLARGE_INTEGER)0x2;
  }
  liDistanceToMove.s.HighPart = (LONG)&stack0xfffffff8;
  liDistanceToMove.s.LowPart = param_3;
  BVar1 = SetFilePointerEx((HANDLE)(&DAT_008007a0)[param_1],liDistanceToMove,lpNewFilePointer,0);
  if (BVar1 != 0) {
    return (ulonglong)unaff_retaddr << 0x20;
  }
  return -1;
}

