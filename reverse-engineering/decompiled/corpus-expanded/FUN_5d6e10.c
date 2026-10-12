/* Ghidra pseudocode, not original source.
 * ev_2b55f789f1446a783af549e987f50963f158fc34aa4a0a7d53ec4780e4e01d82
 * Entry: 0x5d6e10; label: FUN_005d6e10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d6e10(float param_1,float param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5)

{
  int iVar1;
  float local_18;
  float local_14;
  undefined4 local_10;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  if (param_5 == (undefined4 *)0x0) {
    param_5 = &DAT_009736e8;
  }
  iVar1 = FUN_006e6b90();
  local_c = (((float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] /
             (float)(&DAT_029899a0)[iVar1 + 0x4000 >> 1 & 0x7fff]) * (param_1 * 2.0 - 1.0)) /
            (float)param_5[0x11];
  local_8 = (1.0 - param_2 * 2.0) *
            ((float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] /
            (float)(&DAT_029899a0)[iVar1 + 0x4000 >> 1 & 0x7fff]);
  local_18 = local_c * (float)param_5[0x12];
  local_14 = local_8 * (float)param_5[0x12];
  local_10 = param_5[0x12];
  local_c = (float)param_5[0x13] * local_c;
  local_8 = local_8 * (float)param_5[0x13];
  local_4 = param_5[0x13];
  FUN_005b30a0(param_3,&local_18,param_5);
  FUN_005b30a0(param_4,&local_c,param_5);
  return;
}

