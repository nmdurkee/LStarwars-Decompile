/* Ghidra pseudocode, not original source.
 * ev_2c08301f859172184cf112c2b2791d688bc6316a9907cd3ed4418d6c565e9413
 * Entry: 0x5be790; label: FUN_005be790
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005be790(float param_1)

{
  int iVar1;
  int iVar2;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float local_8;
  
  iVar1 = DAT_0095e540;
  if (DAT_00806acc != 0) {
    iVar1 = FUN_004eef40(36000,"d:\\projects\\legosagapc\\nu2api.saga\\numath\\nutrig.c",0x325);
    DAT_0095e540 = iVar1;
    if (iVar1 == 0) {
      return (float10)0;
    }
    do {
      FUN_006e9190();
      iVar2 = FUN_006e6b90();
      *(float *)(iVar1 + -4000 + iVar2 * 4) = (float)extraout_ST1;
    } while ((float)(extraout_ST0 + (float10)1) < 9999.0 !=
             ((float)(extraout_ST0 + (float10)1) == 9999.0));
    DAT_00806acc = 0;
  }
  if (param_1 < 0.0 == (param_1 == 0.0)) {
    local_8 = 3.0;
    if (NAN(param_1) || 10000.0 < param_1 == (param_1 == 10000.0)) {
      if (param_1 < 1000.0) {
        for (; param_1 < 1000.0; param_1 = param_1 * 10.0) {
          local_8 = local_8 - 1.0;
        }
      }
    }
    else {
      for (; 10000.0 < param_1; param_1 = param_1 * 0.1) {
        local_8 = local_8 + 1.0;
      }
    }
    iVar2 = FUN_006e6b90();
    if (0x2326 < iVar2) {
      return (float10)(*(float *)(iVar1 + iVar2 * 4) + local_8);
    }
    return (float10)(float)((float10)(float)(extraout_ST0_00 - (float10)iVar2) *
                            (float10)*(float *)(iVar1 + 4 + iVar2 * 4) +
                            (float10)*(float *)(iVar1 + iVar2 * 4) *
                            (extraout_ST1_00 - (float10)(float)(extraout_ST0_00 - (float10)iVar2)) +
                           (float10)local_8);
  }
  return (float10)3.4028235e+38;
}

