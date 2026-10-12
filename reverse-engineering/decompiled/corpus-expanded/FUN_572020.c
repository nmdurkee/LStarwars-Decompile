/* Ghidra pseudocode, not original source.
 * ev_f349b1a9efc39563d2f2ebe5dc458b8d9d47a8328d1b609022bb24691faec82f
 * Entry: 0x572020; label: FUN_00572020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00572020(int param_1,float *param_2,undefined4 *param_3,float param_4,float param_5,
                int param_6,undefined4 param_7)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  int local_40;
  float local_3c;
  int local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_24 [4];
  undefined4 local_20;
  float local_18;
  float local_10;
  float local_c;
  float local_4;
  
  local_30 = *param_3;
  local_2c = param_3[1];
  local_28 = param_3[2];
  iVar7 = 0;
  local_38 = 0;
  iVar5 = FUN_005806a0(param_7,PTR_DAT_00802c54);
  iVar8 = DAT_0291f664;
  local_3c = param_5;
  local_18 = *param_2 - param_4;
  local_40 = 0;
  local_10 = param_2[2] - param_4;
  local_c = *param_2 + param_4;
  local_4 = param_4 + param_2[2];
  if (param_6 != 0) {
    local_30 = *param_3;
    local_2c = param_3[1];
    local_28 = param_3[2];
    if ((*(uint *)(iVar5 + 0x60) & 0x20000) != 0) {
      local_2c = 0;
      FUN_005b3b30(&local_30,&local_30);
    }
  }
  if (DAT_0081020c < 1) {
    local_38 = 0;
  }
  else {
    do {
      iVar3 = local_40;
      fVar4 = local_3c;
      if ((((*(byte *)(iVar8 + 0x144) & 1) != 0) &&
          ((((*(uint *)(iVar8 + 0x108) & 0x8000000) != 0 ||
            (((byte)*(uint *)(iVar8 + 0x108) & 10) == 10)) &&
           (pfVar1 = (float *)(iVar8 + 0x30), local_18 <= *(float *)(iVar8 + 0x30))))) &&
         (((*pfVar1 <= local_c && (local_10 <= *(float *)(iVar8 + 0x38))) &&
          (*(float *)(iVar8 + 0x38) <= local_4)))) {
        fVar9 = (float10)FUN_005b3c50(pfVar1,param_2,local_24);
        fVar2 = (float)fVar9;
        if (fVar2 < param_5) {
          if (param_6 == 0) {
            uVar6 = FUN_005be2d0(*pfVar1 - *param_2,*(float *)(iVar8 + 0x38) - param_2[2]);
            FUN_005b3620(&local_30,&DAT_0080250c,uVar6);
          }
          if ((*(uint *)(iVar5 + 0x60) & 0x20000) != 0) {
            local_20 = 0;
          }
          FUN_005b3b30(local_24,local_24);
          fVar9 = (float10)FUN_005b39e0(local_24,&local_30);
          if ((_DAT_0087a930 <= fVar2) || (param_6 == 0)) {
            if (_DAT_0087aa54 <= fVar2) {
              param_3 = (undefined4 *)CONCAT22(param_3._2_2_,DAT_0087a838);
            }
            else {
              param_3 = (undefined4 *)CONCAT22(param_3._2_2_,DAT_0087a834);
            }
          }
          else {
            param_3 = (undefined4 *)CONCAT22(param_3._2_2_,DAT_0087a958);
          }
          iVar3 = local_38;
          if ((((float)fVar9 <= (float)(&DAT_029899a0)[(int)(param_3 + 0x1000) >> 1 & 0x7fff]) ||
              (local_3c <= fVar2)) ||
             (iVar3 = iVar8, fVar4 = fVar2, iVar8 == *(int *)(param_1 + 0xcc8))) {
            local_38 = iVar3;
            iVar3 = local_40;
            fVar4 = local_3c;
          }
        }
      }
      local_3c = fVar4;
      local_40 = iVar3;
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 0x220;
    } while (iVar7 < DAT_0081020c);
    if ((local_40 != 0) || (local_38 == 0)) {
      return local_40;
    }
  }
  return local_38;
}

