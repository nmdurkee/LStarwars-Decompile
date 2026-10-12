/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x69a410; label: FUN_0069a410
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

