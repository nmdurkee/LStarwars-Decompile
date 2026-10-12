/* Ghidra pseudocode, not original source.
 * ev_cdce1c1a74417fce840dfa63a2c32577050f1657d9e1cb9f16f7031f05578a24
 * Entry: 0x42a880; label: FUN_0042a880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0042a880(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  
  if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0a0) &&
     ((((cVar1 = PTR_DAT_008021b4[1], cVar1 == '\n' || (cVar1 == '\v')) || (cVar1 == '\f')) &&
      ((145.0 < *(float *)(PTR_DAT_008021b4 + 0x2c) && (*(float *)(PTR_DAT_008021b4 + 0x2c) < 195.0)
       ))))) {
    FUN_00681f40();
    return;
  }
  if (((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b090) && (PTR_DAT_008021b4[1] == '\0')) &&
     (145.0 < *(float *)(PTR_DAT_008021b4 + 0x2c))) {
    FUN_00681f40();
    return;
  }
  FUN_00547930(0x33,param_2,0,0);
  return;
}

