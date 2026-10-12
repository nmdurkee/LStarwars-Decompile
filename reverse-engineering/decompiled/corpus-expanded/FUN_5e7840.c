/* Ghidra pseudocode, not original source.
 * ev_a2aea1d641189bbcca45d714e231c7fbe07e1298025184ba29836f60d860e436
 * Entry: 0x5e7840; label: FUN_005e7840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e7840(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *in_ECX;
  float *pfVar5;
  int iVar6;
  float local_a0;
  float local_98;
  float local_90;
  float local_8c;
  float local_88;
  undefined1 local_80 [8];
  float local_78;
  float local_70 [4];
  undefined1 local_60 [16];
  undefined1 local_50 [16];
  undefined1 local_40 [16];
  undefined1 local_30 [16];
  undefined1 local_20 [28];
  
  if (((*in_ECX == '\0') || (in_ECX[1] == '\0')) ||
     (*(uint *)(*(int *)(in_ECX + 0x150) + 8) <= *(uint *)(*(int *)(in_ECX + 0x150) + 0xc))) {
    return;
  }
  if ((0.0 < *(float *)(in_ECX + 0x158)) || (0.0 < *(float *)(in_ECX + 0x15c))) {
    FUN_005b3ec0(local_70,param_1,&DAT_0080b808);
    FUN_005b3ec0(local_60,param_2,&DAT_0080b808);
    FUN_005b3ec0(local_50,param_3,&DAT_0080b808);
    if (0.0 < *(float *)(in_ECX + 0x158)) {
      uVar3 = FUN_005c1e50(local_30,local_70);
      uVar4 = FUN_005c1e50(local_20,local_70);
      FUN_005b3920(local_80,uVar4,uVar3);
      FUN_005b3b30(local_80,local_80);
      if (ABS(local_78) < *(float *)(in_ECX + 0x158)) {
        return;
      }
    }
    FUN_005b3ec0(local_40,param_4,&DAT_0080b808);
    local_8c = 1e+06;
    local_98 = 1e+06;
    iVar6 = 0;
    pfVar5 = local_70 + 3;
    local_88 = -1e+06;
    local_90 = -1e+06;
    local_a0 = 1e+06;
    do {
      if (*pfVar5 < 0.001) {
        return;
      }
      fVar1 = pfVar5[-3] / *pfVar5;
      pfVar5[-3] = fVar1;
      fVar2 = pfVar5[-2] / *pfVar5;
      pfVar5[-2] = fVar2;
      pfVar5[-1] = pfVar5[-1] / *pfVar5;
      if (fVar1 < local_8c) {
        local_8c = fVar1;
      }
      if (fVar2 < local_98) {
        local_98 = fVar2;
      }
      if (local_88 < fVar1) {
        local_88 = fVar1;
      }
      if (local_90 < fVar2) {
        local_90 = fVar2;
      }
      if (*pfVar5 < local_a0) {
        local_a0 = *pfVar5;
      }
      iVar6 = iVar6 + 1;
      pfVar5 = pfVar5 + 4;
    } while (iVar6 != 4);
    if ((0.0 < *(float *)(in_ECX + 0x15c)) &&
       ((local_88 - local_8c) * (local_90 - local_98) * 0.25 < *(float *)(in_ECX + 0x15c))) {
      return;
    }
  }
  FUN_005c5330(param_1,param_2,param_3,param_4);
  return;
}

