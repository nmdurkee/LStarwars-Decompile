/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67af00; label: FUN_0067af00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0067af00(int param_1,undefined4 param_2,float *param_3,float param_4,float *param_5)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  float local_108;
  int local_104;
  float local_fc [55];
  float local_20;
  float local_1c;
  float local_18;
  
  local_fc[0] = -1.0;
  local_fc[1] = -1.0;
  iVar3 = 0;
  local_fc[2] = 1.0;
  local_fc[5] = 1.0;
  local_104 = 0;
  local_fc[6] = 1.0;
  pfVar4 = local_fc + 0x17;
  local_fc[9] = 1.0;
  pfVar2 = local_fc;
  local_fc[0xd] = 1.0;
  local_fc[0xe] = 1.0;
  local_fc[0x10] = 1.0;
  local_fc[0x11] = 1.0;
  local_fc[0x12] = 1.0;
  local_fc[0x13] = 1.0;
  local_fc[0x15] = 1.0;
  local_fc[0x16] = 1.0;
  local_fc[3] = -1.0;
  local_fc[4] = -1.0;
  local_fc[7] = -1.0;
  local_fc[8] = -1.0;
  local_fc[10] = -1.0;
  local_fc[0xb] = -1.0;
  local_fc[0xc] = -1.0;
  local_fc[0xf] = -1.0;
  local_fc[0x14] = -1.0;
  local_108 = 10000.0;
  do {
    *pfVar4 = pfVar2[-1];
    pfVar4[1] = *pfVar2;
    pfVar4[2] = pfVar2[1];
    pfVar4[3] = 0.0;
    FUN_005c03e0(&local_20,pfVar4,param_2);
    FUN_005c03e0(pfVar4,pfVar4,param_1);
    fVar1 = pfVar4[2] * param_3[2] + *pfVar4 * *param_3 + param_3[1] * pfVar4[1];
    if ((local_18 * param_3[2] + *param_3 * local_20 + param_3[1] * local_1c < fVar1) &&
       (fVar1 < local_108)) {
      local_108 = fVar1;
      local_104 = iVar3;
    }
    iVar3 = iVar3 + 1;
    pfVar2 = pfVar2 + 3;
    pfVar4 = pfVar4 + 4;
  } while (iVar3 < 8);
  *param_5 = *(float *)(param_1 + 0x30) + param_4 * local_fc[local_104 * 4 + 0x17];
  param_5[1] = local_fc[local_104 * 4 + 0x18] * param_4 + *(float *)(param_1 + 0x34);
  param_5[2] = param_4 * local_fc[local_104 * 4 + 0x19] + *(float *)(param_1 + 0x38);
  return;
}

