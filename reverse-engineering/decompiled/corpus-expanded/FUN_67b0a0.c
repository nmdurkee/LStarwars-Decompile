/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67b0a0; label: FUN_0067b0a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0067b0a0(float *param_1,int param_2,float param_3,float param_4,undefined4 param_5)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  float local_c [3];
  
  if (DAT_0292fc68 != 0) {
    iVar3 = 0;
    piVar4 = (int *)(DAT_0292fc68 + 0x198);
    do {
      if (*piVar4 == param_2) {
        DAT_02947c74 = DAT_0292fc68 + (iVar3 * 3 + 0x33) * 8;
        goto LAB_0067b0d5;
      }
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 6;
    } while (iVar3 < 0x40);
    DAT_02947c74 = 0;
LAB_0067b0d5:
    if ((DAT_02947c74 != 0) && (*(short *)(DAT_02947c74 + 10) != 0)) {
      if (param_3 != 0.0) {
        local_c[0] = 0.0;
        local_c[1] = 0.0;
        local_c[2] = param_3;
        FUN_005b3620(local_c,local_c,param_5);
        iVar3 = DAT_02947c74;
        pfVar1 = (float *)(DAT_02947c74 + 0xc);
        FUN_00677fb0(pfVar1,local_c,local_c);
        fVar2 = *(float *)(iVar3 + 0x14);
        *param_1 = *param_1 + local_c[0] + param_3 * *pfVar1 * 0.4;
        param_1[2] = fVar2 * param_3 * 0.4 + local_c[2] + param_1[2];
      }
      if (0.0 < param_1[1]) {
        param_1[1] = param_1[1] * param_4;
      }
    }
  }
  return;
}

