/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x426bb0; label: FUN_00426bb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined * FUN_00426bb0(undefined4 param_1,float param_2,int param_3)

{
  int iVar1;
  undefined *puVar2;
  float10 fVar3;
  undefined *local_8;
  
  puVar2 = &DAT_008569b8;
  local_8 = (undefined *)0x0;
  if (param_2 == 0.0) {
    param_2 = 1e+09;
  }
  else {
    param_2 = param_2 * param_2;
  }
  iVar1 = 10;
  do {
    if ((puVar2[0x28] != '\0') && ((param_3 == 0 || (*(int *)(puVar2 + 0x24) == param_3)))) {
      fVar3 = (float10)FUN_005b3c50(param_1,puVar2,0);
      if ((float)fVar3 < param_2) {
        param_2 = (float)fVar3;
        local_8 = puVar2;
      }
    }
    puVar2 = puVar2 + 0x38;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return local_8;
}

