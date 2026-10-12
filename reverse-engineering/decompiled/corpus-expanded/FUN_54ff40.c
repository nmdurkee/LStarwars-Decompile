/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x54ff40; label: FUN_0054ff40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

