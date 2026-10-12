/* Ghidra pseudocode, not original source.
 * ev_e0447f8e73d2150c5385a8aa294440164da99c01f5f62ba5bd70b4e5b4546b39
 * Entry: 0x74aa40; label: FUN_0074aa40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_0074aa40(int param_1)

{
  void *_Dst;
  undefined4 *in_ECX;
  
  _Dst = *(void **)(param_1 + 4);
  *(int *)(param_1 + 4) = in_ECX[1] + 1 + (int)_Dst;
  _memcpy(_Dst,(void *)*in_ECX,in_ECX[1]);
  *(undefined1 *)((int)_Dst + in_ECX[1]) = 0;
  return _Dst;
}

