/* Ghidra analysis pseudocode, not original source.
 * ev_988aedce7a102035a37775149c4794654cf73d0aa98e786da352e425eaa98523
 * Entry: 0x433df0; label: FUN_00433df0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00433df0(int param_1,float *param_2,undefined4 *param_3,float param_4,float param_5,
                uint param_6,int param_7,int param_8,undefined4 param_9)

{
  float *pfVar1;
  float fVar2;
  char cVar3;
  byte bVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  float10 fVar12;
  undefined8 uVar13;
  float local_54;
  uint local_50;
  float local_4c;
  uint local_48;
  uint local_44;
  int local_40;
  int local_3c;
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
  local_3c = 0;
  iVar7 = FUN_005806a0(param_9,PTR_DAT_00802c54);
  local_54 = _DAT_0087a930;
  local_50 = (uint)DAT_0087a958;
  local_4c = _DAT_0087aa54;
  local_48 = (uint)DAT_0087a834;
  local_44 = (uint)DAT_0087a838;
  if (((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) &&
     ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b24c ||
      (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b210)))) {
    local_50 = 0x2aaa;
    local_54 = 6.25;
    local_48 = 0x1c71;
    local_44 = 0xe38;
    local_4c = 100.0;
  }
  local_40 = 0;
  local_18 = *param_2 - param_4;
  local_10 = param_2[2] - param_4;
  local_c = param_4 + *param_2;
  local_4 = param_4 + param_2[2];
  if (param_7 != 0) {
    local_30 = *param_3;
    local_2c = param_3[1];
    local_28 = param_3[2];
    if ((iVar7 != 0) && ((*(uint *)(iVar7 + 0x60) & 0x20000) != 0)) {
      local_2c = 0;
      FUN_005b3b30(&local_30,&local_30);
    }
  }
  iVar8 = FUN_00475850(0);
  param_4 = 0.0;
  iVar11 = DAT_0093d504;
  if (DAT_0093d500 < 1) {
    local_40 = 0;
  }
  else {
    do {
      fVar5 = param_5;
      iVar6 = local_40;
      if ((((((iVar11 != param_1) && ((*(uint *)(iVar11 + 0x1fc) & 0x1000) != 0)) &&
            (*(char *)(iVar11 + 0x28b) == '\0')) &&
           ((param_8 == 0 || (*(char *)(iVar11 + 0x288) != '\0')))) &&
          ((*(uint *)(iVar11 + 0xef4) & 1) == 0)) &&
         (((cVar3 = *(char *)(iVar11 + 0x7b5), cVar3 != ';' && (cVar3 != '9')) &&
          ((cVar3 != '<' && ((*(uint *)(PTR_PTR_007fb0e4 + cVar3 * 0x10 + 8) & 0x8000) == 0)))))) {
        if (param_6 == 0) {
          if (iVar8 != 0) {
            uVar10 = (*(uint *)(iVar11 + 0x1f8) ^ *(uint *)(param_1 + 0x1f8)) & 0x10001;
            goto LAB_00434012;
          }
        }
        else {
          uVar10 = *(uint *)(*(int *)(iVar11 + 0x54) + 4) & param_6;
LAB_00434012:
          if (uVar10 == 0) goto LAB_0043423e;
        }
        if ((((cVar3 != '_') && (cVar3 != '`')) &&
            ((((iVar8 == 0 ||
               ((((*(byte *)(param_1 + 0x1fc) & 0x80) == 0 ||
                 ((*(uint *)(iVar11 + 0xef4) & 0x800000) != 0)) ||
                (bVar4 = *(byte *)(param_1 + 0x28d), uVar13 = __allshl(),
                ((uint)uVar13 & *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 8 + (uint)bVar4 * 8)
                ) != 0 || ((uint)((ulonglong)uVar13 >> 0x20) &
                          *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0xc + (uint)bVar4 * 8)) !=
                          0)))) &&
              (((pfVar1 = (float *)(iVar11 + 0x80), local_18 <= *(float *)(iVar11 + 0x80) &&
                (*pfVar1 <= local_c)) && (local_10 <= *(float *)(iVar11 + 0x88))))) &&
             (*(float *)(iVar11 + 0x88) <= local_4)))) &&
           (((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b1a4 ||
             (*(char *)(iVar11 + 0x280) != -1)) ||
            ((-1.5 <= *(float *)(iVar11 + 0x60) || (PTR_DAT_008021b4[1] != '\x02')))))) {
          fVar12 = (float10)FUN_005b3c50(pfVar1,param_2,local_24);
          fVar2 = (float)fVar12;
          if (fVar2 < param_5) {
            if (param_7 == 0) {
              uVar9 = FUN_005be2d0(*pfVar1 - *param_2,*(float *)(iVar11 + 0x88) - param_2[2]);
              FUN_005b3620(&local_30,&DAT_0080250c,uVar9);
            }
            if ((iVar7 != 0) && ((*(uint *)(iVar7 + 0x60) & 0x20000) != 0)) {
              local_20 = 0;
            }
            FUN_005b3b30(local_24,local_24);
            fVar12 = (float10)FUN_005b39e0(local_24,&local_30);
            if (((local_54 <= fVar2) || (uVar10 = local_50, param_7 == 0)) &&
               (uVar10 = local_48, local_4c <= fVar2)) {
              uVar10 = local_44;
            }
            if (((float)(&DAT_029899a0)[(int)(uVar10 + 0x4000) >> 1 & 0x7fff] < (float)fVar12) &&
               (fVar5 = fVar2, iVar6 = iVar11, iVar11 == *(int *)(param_1 + 0xcc8))) {
              fVar5 = param_5;
              iVar6 = local_40;
              local_3c = iVar11;
            }
          }
        }
      }
LAB_0043423e:
      local_40 = iVar6;
      param_5 = fVar5;
      param_4 = (float)((int)param_4 + 1);
      iVar11 = iVar11 + 0x10d8;
    } while ((int)param_4 < DAT_0093d500);
    if ((local_40 == 0) && (local_3c != 0)) {
      return local_3c;
    }
  }
  return local_40;
}

