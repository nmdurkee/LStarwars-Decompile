/* Ghidra analysis pseudocode, not original source.
 * ev_ec07135468de31ab5fb92b99d3a0e31a017920018520f35a1e7400fac21801d6
 * Entry: 0x54ff40; label: FUN_0054ff40
 */

void FUN_0054ff40(float *param_1,undefined2 *param_2,undefined2 *param_3)

{
  int iVar1;
  float10 fVar2;
  
  DAT_0093b0c8 = FUN_005be2d0(*param_1,param_1[2]);
  if (param_3 != (undefined2 *)0x0) {
    *param_3 = DAT_0093b0c8;
  }
  fVar2 = (float10)FUN_005c0240(*param_1 * *param_1 + param_1[2] * param_1[2]);
  iVar1 = FUN_005be2d0(param_1[1],(float)fVar2);
  DAT_0092b0bc = -iVar1;
  DAT_0092b0c4 = (undefined2)DAT_0092b0bc;
  if (param_2 != (undefined2 *)0x0) {
    *param_2 = DAT_0092b0c4;
  }
  return;
}

