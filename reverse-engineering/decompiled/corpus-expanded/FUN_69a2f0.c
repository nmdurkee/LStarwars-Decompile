/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x69a2f0; label: FUN_0069a2f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0069a2f0(HANDLE param_1,undefined4 param_2,DWORD param_3,LONG param_4,
                 PLARGE_INTEGER param_5)

{
  LARGE_INTEGER liDistanceToMove;
  DWORD unaff_retaddr;
  
  liDistanceToMove.s.HighPart = (LONG)&param_2;
  liDistanceToMove.s.LowPart = param_3;
  SetFilePointerEx(param_1,liDistanceToMove,param_5,unaff_retaddr);
  if (param_5 != (PLARGE_INTEGER)0x0) {
    (param_5->s).LowPart = param_3;
    (param_5->s).HighPart = param_4;
  }
  return;
}

