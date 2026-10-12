/* Ghidra analysis pseudocode, not original source.
 * ev_df5ebe5055aa55c8d4ffbc3d42601afd4ff508e5ed8fd93234c5a96c9c8b7e66
 * Entry: 0x4f6000; label: FUN_004f6000
 */

void FUN_004f6000(uint param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  short sVar8;
  uint uVar9;
  short sVar10;
  byte bVar11;
  undefined4 *puVar12;
  uint local_64;
  int local_60;
  int local_5c;
  ushort *local_58;
  int local_54;
  undefined4 local_50;
  ushort auStack_4c [36];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_64;
  local_60 = param_4;
  uVar1 = 0;
  local_54 = param_2;
  auStack_4c[1] = 0;
  auStack_4c[2] = 0;
  auStack_4c[3] = 0;
  auStack_4c[4] = 0;
  auStack_4c[5] = 0;
  auStack_4c[6] = 0;
  auStack_4c[7] = 0;
  auStack_4c[8] = 0;
  auStack_4c[9] = 0;
  auStack_4c[10] = 0;
  auStack_4c[0xb] = 0;
  auStack_4c[0xc] = 0;
  auStack_4c[0xd] = 0;
  auStack_4c[0xe] = 0;
  auStack_4c[0xf] = 0;
  auStack_4c[0x10] = 0;
  if (param_1 != 0) {
    do {
      auStack_4c[*(byte *)(param_2 + uVar1)] = auStack_4c[*(byte *)(param_2 + uVar1)] + 1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_1);
  }
  auStack_4c[0x13] = 0;
  bVar11 = 0xe;
  uVar1 = 2;
  do {
    bVar3 = bVar11 - 1;
    sVar8 = (*(short *)((int)auStack_4c + uVar1) << (bVar11 + 1 & 0x1f)) +
            *(short *)((int)auStack_4c + uVar1 + 0x24);
    uVar2 = uVar1 + 8;
    sVar10 = (*(short *)((int)auStack_4c + uVar1 + 2) << (bVar11 & 0x1f)) + sVar8;
    *(short *)((int)auStack_4c + uVar1 + 0x26) = sVar8;
    *(short *)((int)auStack_4c + uVar1 + 0x28) = sVar10;
    bVar4 = bVar11 - 2;
    bVar11 = bVar11 - 4;
    sVar10 = (*(short *)((int)auStack_4c + uVar1 + 4) << (bVar3 & 0x1f)) + sVar10;
    *(short *)((int)auStack_4c + uVar1 + 0x2a) = sVar10;
    *(short *)((int)auStack_4c + uVar1 + 0x2c) =
         (*(short *)((int)auStack_4c + uVar1 + 6) << (bVar4 & 0x1f)) + sVar10;
    uVar1 = uVar2;
  } while (uVar2 < 0x21);
  if (auStack_4c[0x23] != 0) {
    FUN_004f5c10("Bad table");
  }
  local_5c = 0x10 - param_3;
  uVar2 = 1;
  bVar11 = (byte)local_5c;
  uVar1 = param_3;
  if (param_3 != 0) {
    do {
      auStack_4c[uVar2 + 0x12] = auStack_4c[uVar2 + 0x12] >> (bVar11 & 0x1f);
      uVar2 = uVar2 + 1;
      *(short *)((int)&local_50 + uVar2 * 2 + 2) = (short)(1 << ((byte)(uVar1 - 1) & 0x1f));
      uVar1 = uVar1 - 1;
    } while (uVar2 <= param_3);
    if (0x10 < uVar2) goto LAB_004f6157;
  }
  iVar5 = 0x10 - uVar2;
  do {
    bVar3 = (byte)iVar5;
    uVar2 = uVar2 + 1;
    iVar5 = iVar5 + -1;
    *(short *)((int)&local_50 + uVar2 * 2 + 2) = (short)(1 << (bVar3 & 0x1f));
  } while (uVar2 < 0x11);
LAB_004f6157:
  uVar1 = (uint)(auStack_4c[param_3 + 0x13] >> (bVar11 & 0x1f));
  if ((uVar1 != 0) && (uVar2 = 1 << ((byte)param_3 & 0x1f), uVar1 != uVar2)) {
    uVar2 = uVar2 - uVar1;
    puVar12 = (undefined4 *)(local_60 + uVar1 * 2);
    for (uVar6 = uVar2 >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
    for (uVar1 = (uint)((uVar2 & 1) != 0); uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined2 *)puVar12 = 0;
      puVar12 = (undefined4 *)((int)puVar12 + 2);
    }
  }
  local_50 = 1 << (0xf - (byte)param_3 & 0x1f);
  local_64 = 0;
  uVar1 = param_1;
  if (param_1 != 0) {
    do {
      uVar2 = (uint)*(byte *)(local_54 + local_64);
      if (uVar2 != 0) {
        uVar6 = (uint)auStack_4c[uVar2 + 0x12];
        local_58 = auStack_4c + uVar2 + 0x12;
        uVar9 = auStack_4c[uVar2] + uVar6;
        if (param_3 < uVar2) {
          puVar7 = (ushort *)(local_60 + (uint)(auStack_4c[uVar2 + 0x12] >> (bVar11 & 0x1f)) * 2);
          for (iVar5 = uVar2 - param_3; iVar5 != 0; iVar5 = iVar5 + -1) {
            if (*puVar7 == 0) {
              *(undefined2 *)(&DAT_02982740 + uVar1 * 2) = 0;
              *(undefined2 *)(&DAT_02982f40 + uVar1 * 2) = 0;
              *puVar7 = (ushort)uVar1;
              uVar1 = uVar1 + 1;
            }
            if ((local_50 & uVar6) == 0) {
              puVar7 = (ushort *)(&DAT_02982740 + (uint)*puVar7 * 2);
            }
            else {
              puVar7 = (ushort *)(&DAT_02982f40 + (uint)*puVar7 * 2);
            }
            uVar6 = uVar6 * 2;
          }
          *puVar7 = (ushort)local_64;
        }
        else if (uVar6 < uVar9) {
          puVar7 = (ushort *)(local_60 + uVar6 * 2);
          for (uVar2 = uVar9 - uVar6 >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
            *(uint *)puVar7 = CONCAT22((ushort)local_64,(ushort)local_64);
            puVar7 = puVar7 + 2;
          }
          for (uVar2 = (uint)((uVar9 - uVar6 & 1) != 0); uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar7 = (ushort)local_64;
            puVar7 = puVar7 + 1;
          }
        }
        *local_58 = (ushort)uVar9;
      }
      local_64 = local_64 + 1;
    } while (local_64 < param_1);
  }
  __security_check_cookie(local_4 ^ (uint)&local_64);
  return;
}

