/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x699690; label: FUN_00699690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00699690(undefined4 param_1)

{
  undefined4 uVar1;
  int *in_ECX;
  
  if ((in_ECX != (int *)0x0) && (*in_ECX != 0)) {
    uVar1 = FUN_00699180(2,param_1);
    return uVar1;
  }
  return 0;
}

