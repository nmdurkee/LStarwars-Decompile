/* Ghidra pseudocode, not original source.
 * ev_c80330773f662e8a33570a4ca58388b0b4349f11aa110fb6d722955620f1df5d
 * Entry: 0x6324e0; label: FUN_006324e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006324e0(float param_1,float param_2,float param_3,float param_4,int param_5,int param_6)

{
  int iVar1;
  int *unaff_EBX;
  float *pfVar2;
  float *pfVar3;
  float local_180 [16];
  float local_140 [8];
  float local_120 [8];
  float local_100 [8];
  float local_e0 [8];
  float local_c0 [8];
  float local_a0 [8];
  float local_80 [4];
  undefined4 local_70;
  undefined4 local_6c;
  float local_60 [4];
  undefined4 local_50;
  undefined4 local_4c;
  float local_40 [4];
  undefined4 local_30;
  undefined4 local_2c;
  float local_20 [4];
  undefined4 local_10;
  undefined4 local_c;
  
  local_180[0] = param_1;
  local_180[1] = param_2;
  local_180[4] = -NAN;
  local_180[5] = -NAN;
  local_180[2] = 0.0;
  local_180[3] = 1.0;
  local_180[6] = 0.0;
  local_180[7] = 0.0;
  pfVar2 = local_180;
  pfVar3 = local_180 + 8;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  local_180[8] = (float)param_5 * param_3 + param_1;
  local_180[9] = param_2;
  pfVar2 = local_180 + 8;
  pfVar3 = local_140;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  pfVar2 = local_180 + 8;
  pfVar3 = local_120;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  local_120[1] = (float)param_6 * param_4 + param_2;
  pfVar2 = local_120;
  pfVar3 = local_100;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  pfVar2 = local_120;
  pfVar3 = local_e0;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  local_e0[0] = param_1;
  pfVar2 = local_e0;
  pfVar3 = local_c0;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  pfVar2 = local_180;
  pfVar3 = local_a0;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  pfVar2 = local_180;
  pfVar3 = local_80;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  pfVar2 = local_120;
  pfVar3 = local_60;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  pfVar2 = local_180 + 8;
  pfVar3 = local_40;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  pfVar2 = local_e0;
  pfVar3 = local_20;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  local_70 = 0xffff0000;
  local_6c = 0xffff0000;
  local_50 = 0xffff0000;
  local_4c = 0xffff0000;
  local_30 = 0xffff0000;
  local_2c = 0xffff0000;
  local_10 = 0xffff0000;
  local_c = 0xffff0000;
  (**(code **)(*unaff_EBX + 0x10c))();
  (**(code **)(*unaff_EBX + 0x10c))();
  (**(code **)(*unaff_EBX + 0x170))();
  (**(code **)(*unaff_EBX + 0x164))();
  (**(code **)(*unaff_EBX + 0x14c))();
  return;
}

