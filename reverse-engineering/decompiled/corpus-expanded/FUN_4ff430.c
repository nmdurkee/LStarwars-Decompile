/* Ghidra pseudocode, not original source.
 * ev_40a85160eaccd151253910192404d8aba277d39ac9ab2a88fc5c5de06172d047
 * Entry: 0x4ff430; label: FUN_004ff430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

