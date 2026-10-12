/* Ghidra analysis pseudocode, not original source.
 * ev_b1d683d72d7bcdb306124a83b006db4b41bf581671bc5ef620d768a8a4b84d3d
 * Entry: 0x66da90; label: FUN_0066da90
 */

void FUN_0066da90(int param_1,short param_2)

{
  uint *puVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  int local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  iVar2 = param_2 * 0x38;
  iVar7 = *(short *)(iVar2 + 0x30 + *DAT_0292fc68) * 0x6c + DAT_0292fc68[0x1a];
  puVar1 = *(uint **)(iVar7 + 0x68);
  if (puVar1 != (uint *)0x0) {
    if ((*(byte *)(iVar7 + 0x4c) & 4) == 0) {
      if ((*puVar1 & 1) == 0) {
        return;
      }
    }
    else if ((*puVar1 & 2) == 0) {
      return;
    }
  }
  local_50 = *(float *)(param_1 + 0x18);
  local_4c = *(float *)(param_1 + 0x1c);
  local_48 = *(float *)(param_1 + 0x20);
  local_44 = 0;
  local_40 = *(float *)(param_1 + 0x24);
  local_3c = *(float *)(param_1 + 0x28);
  iVar8 = (-(uint)((*(byte *)(param_1 + 0x62) & 0x80) != 0) & 0xff01ffff) + 0xff0000;
  local_38 = *(float *)(param_1 + 0x2c);
  local_34 = 0;
  local_30 = *(float *)(param_1 + 0x30);
  local_2c = *(float *)(param_1 + 0x34);
  local_28 = *(float *)(param_1 + 0x38);
  local_24 = 0;
  local_20 = *(float *)(param_1 + 0x3c);
  local_1c = *(float *)(param_1 + 0x40);
  local_18 = *(float *)(param_1 + 0x44);
  local_14 = 0;
  local_10 = *(float *)(param_1 + 0x48) * 0.4;
  local_c = *(float *)(param_1 + 0x4c) * 0.4;
  local_8 = *(float *)(param_1 + 0x50) * 0.4;
  local_4 = 0;
  iVar7 = DAT_0292fc68[0x1a] + *(short *)(iVar2 + 0x30 + *DAT_0292fc68) * 0x6c;
  if ((*(byte *)(iVar7 + 0x4c) & 1) != 0) {
    FUN_005c03e0(&local_50,&local_50,*(undefined4 *)(iVar7 + 0x40));
    FUN_005c03e0(&local_40,&local_40,
                 *(undefined4 *)
                  (*(short *)(iVar2 + 0x30 + *DAT_0292fc68) * 0x6c + 0x40 + DAT_0292fc68[0x1a]));
    FUN_005c03e0(&local_30,&local_30,
                 *(undefined4 *)
                  (*(short *)(iVar2 + 0x30 + *DAT_0292fc68) * 0x6c + 0x40 + DAT_0292fc68[0x1a]));
    FUN_005c03e0(&local_20,&local_20,
                 *(undefined4 *)
                  (*(short *)(iVar2 + 0x30 + *DAT_0292fc68) * 0x6c + 0x40 + DAT_0292fc68[0x1a]));
    FUN_005c03e0(&local_10,&local_10,
                 *(undefined4 *)
                  (*(short *)(iVar2 + 0x30 + *DAT_0292fc68) * 0x6c + 0x40 + DAT_0292fc68[0x1a]));
  }
  local_54 = 0;
  if (*(float *)(param_1 + 0x58) <= 65535.0) {
    do {
      fVar3 = (float)local_54;
      pfVar6 = (float *)(iVar2 + *DAT_0292fc68);
      FUN_005dc050(local_50 + *pfVar6 + (local_40 - local_50) * fVar3,
                   local_4c + pfVar6[1] + fVar3 * (local_3c - local_4c),
                   local_48 + pfVar6[2] + fVar3 * (local_38 - local_48),
                   local_30 + *pfVar6 + fVar3 * (local_20 - local_30),
                   local_2c + pfVar6[1] + fVar3 * (local_1c - local_2c),
                   fVar3 * (local_18 - local_28) + pfVar6[2] + local_28,iVar8);
      local_54 = local_54 + 1;
    } while (local_54 < 2);
    local_54 = 0;
    do {
      fVar3 = (float)local_54;
      pfVar6 = (float *)(*DAT_0292fc68 + iVar2);
      FUN_005dc050(local_50 + *pfVar6 + (local_30 - local_50) * fVar3,
                   local_4c + pfVar6[1] + fVar3 * (local_2c - local_4c),
                   local_48 + pfVar6[2] + fVar3 * (local_28 - local_48),
                   local_40 + *pfVar6 + fVar3 * (local_20 - local_40),
                   local_3c + pfVar6[1] + fVar3 * (local_1c - local_3c),
                   fVar3 * (local_18 - local_38) + pfVar6[2] + local_38,iVar8);
      local_54 = local_54 + 1;
    } while (local_54 < 2);
  }
  else {
    do {
      fVar3 = (float)local_54;
      pfVar6 = (float *)(iVar2 + *DAT_0292fc68);
      FUN_005dc050(*pfVar6 + local_50,pfVar6[1] + local_4c,pfVar6[2] + local_48,
                   local_40 + *pfVar6 + (local_30 - local_40) * fVar3,
                   local_3c + pfVar6[1] + fVar3 * (local_2c - local_3c),
                   fVar3 * (local_28 - local_38) + pfVar6[2] + local_38,iVar8);
      local_54 = local_54 + 1;
    } while (local_54 < 2);
    local_54 = 0;
    do {
      fVar3 = (float)local_54;
      pfVar6 = (float *)(*DAT_0292fc68 + iVar2);
      FUN_005dc050(*pfVar6 + local_40,pfVar6[1] + local_3c,pfVar6[2] + local_38,
                   local_50 + *pfVar6 + (local_30 - local_50) * fVar3,
                   local_4c + pfVar6[1] + fVar3 * (local_2c - local_4c),
                   fVar3 * (local_28 - local_48) + pfVar6[2] + local_48,iVar8);
      local_54 = local_54 + 1;
    } while (local_54 < 2);
  }
  pfVar6 = (float *)(iVar2 + *DAT_0292fc68);
  fVar3 = *(float *)(iVar2 + 8 + *DAT_0292fc68) + local_48;
  fVar4 = pfVar6[1] + local_4c;
  fVar5 = *pfVar6 + local_50;
  FUN_005dc050(fVar5,fVar4,fVar3,local_10 + fVar5,local_c + fVar4,local_8 + fVar3,
               (char)((byte)param_2 << 4) * 0x100 + (int)(char)((byte)param_2 & 0xf0));
  return;
}

