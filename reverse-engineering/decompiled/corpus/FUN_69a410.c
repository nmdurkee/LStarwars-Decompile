/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x69a410; label: FUN_0069a410
 */

bool FUN_0069a410(HANDLE param_1,int param_2)

{
  LARGE_INTEGER liDistanceToMove;
  BOOL BVar1;
  int in_ECX;
  DWORD unaff_EDI;
  undefined1 local_8 [8];
  
  liDistanceToMove.s.HighPart = (LONG)local_8;
  liDistanceToMove.s.LowPart =
       (uint)CARRY4(*(uint *)(param_2 + 8),*(uint *)(param_2 + 4)) + *(int *)(in_ECX + 0x14) +
       (uint)CARRY4(*(uint *)(param_2 + 8) + *(uint *)(param_2 + 4),*(uint *)(in_ECX + 0x10));
  BVar1 = SetFilePointerEx(param_1,liDistanceToMove,(PLARGE_INTEGER)0x0,unaff_EDI);
  return BVar1 != -1;
}

