/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x699640; label: FUN_00699640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00699640(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int *in_ECX;
  
  if ((in_ECX != (int *)0x0) && (*in_ECX != 0)) {
    FUN_004f1f40(in_ECX + 0x78,param_1,0x104);
    in_ECX[0xfb] = param_2;
    uVar1 = FUN_00699180(1,0);
    return uVar1;
  }
  return 0;
}

