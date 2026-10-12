/* Ghidra analysis pseudocode, not original source.
 * ev_101b67aa7badcd34fc3aca69d932f1af6fd7c0870f1a0aed34e591760076c155
 * Entry: 0x504eb0; label: FUN_00504eb0
 */

undefined4 FUN_00504eb0(int param_1,int param_2,float *param_3,float param_4)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  undefined1 local_58 [12];
  undefined1 local_4c [12];
  undefined1 local_40 [48];
  undefined1 local_10 [16];
  
  local_7c = *param_3 - *(float *)(param_2 + 0x30);
  local_78 = param_3[1] - *(float *)(param_2 + 0x34);
  local_74 = param_3[2] - *(float *)(param_2 + 0x38);
  fVar2 = *(float *)(param_1 + 0x10) + param_4;
  if (fVar2 * fVar2 < local_74 * local_74 + local_7c * local_7c + local_78 * local_78) {
    return 0;
  }
  if ((*(byte *)(param_1 + 0xc) & 1) != 0) {
    FUN_005b5e90(local_40,param_2);
    FUN_005b30a0(local_58,param_3,local_40);
    local_8c = param_4;
    local_90 = param_4;
    local_94 = param_4;
    FUN_005b30a0(&local_94,&local_94,local_40);
    FUN_005b3800(&local_94,&local_94,local_10);
    local_94 = ABS(local_94);
    local_90 = ABS(local_90);
    local_8c = ABS(local_8c);
  }
  iVar4 = 0;
  if (0 < *(short *)(param_1 + 0x2c)) {
    do {
      iVar3 = *(int *)(*(int *)(param_1 + 0x30) + iVar4 * 8);
      iVar1 = *(int *)(param_1 + 0x30) + iVar4 * 8;
      if (iVar3 == 1) {
        iVar1 = *(int *)(iVar1 + 4);
        FUN_005b30a0(local_4c,iVar1,param_2);
        fVar5 = (float10)FUN_005b3c50(param_3,local_4c,&local_7c);
        local_98 = (float)fVar5;
        fVar2 = *(float *)(iVar1 + 0xc);
LAB_00505074:
        if (local_98 < (fVar2 + param_4) * (fVar2 + param_4)) {
          return 1;
        }
      }
      else if (iVar3 == 2) {
        iVar1 = *(int *)(iVar1 + 4);
        FUN_005b30a0(&local_64,local_58,iVar1);
        FUN_005b30a0(&local_88,&local_94,iVar1);
        FUN_005b3800(&local_88,&local_88,iVar1 + 0x30);
        local_88 = ABS(local_88);
        local_84 = ABS(local_84);
        local_80 = ABS(local_80);
        if (((((local_64 - local_88 <= *(float *)(iVar1 + 0x4c)) &&
              (*(float *)(iVar1 + 0x40) <= local_88 + local_64)) &&
             (local_60 - local_84 <= *(float *)(iVar1 + 0x50))) &&
            ((*(float *)(iVar1 + 0x44) <= local_84 + local_60 &&
             (local_5c - local_80 <= *(float *)(iVar1 + 0x54))))) &&
           (*(float *)(iVar1 + 0x48) <= local_80 + local_5c)) {
          return 1;
        }
      }
      else if (iVar3 == 3) {
        iVar1 = *(int *)(iVar1 + 4);
        FUN_005b30a0(&local_70,iVar1,param_2);
        if ((local_6c - param_4 <= param_3[1]) &&
           (param_3[1] <= param_4 + *(float *)(iVar1 + 0xc) + local_6c)) {
          fVar2 = *(float *)(iVar1 + 0x10);
          local_98 = (*param_3 - local_70) * (*param_3 - local_70) +
                     (param_3[2] - local_68) * (param_3[2] - local_68);
          goto LAB_00505074;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(short *)(param_1 + 0x2c));
  }
  return 0;
}

