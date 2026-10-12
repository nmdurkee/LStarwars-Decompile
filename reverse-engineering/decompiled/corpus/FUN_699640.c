/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x699640; label: FUN_00699640
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

