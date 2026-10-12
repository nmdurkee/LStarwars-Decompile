/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x51be90; label: FUN_0051be90
 */

int FUN_0051be90(uint *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  float fVar4;
  ushort uVar5;
  ushort uVar6;
  int in_EAX;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  float10 fVar13;
  float10 fVar14;
  int local_20;
  float local_18;
  uint local_10;
  
  local_20 = 0;
  local_10 = 0;
  if ((*(int *)(in_EAX + 0x17c) == 0) || (*(int *)(in_EAX + 0x15c) == 0)) {
    return 0;
  }
  uVar10 = (uint)*(byte *)((*(char *)(in_EAX + 0x160) == '\0') + 0x10 + *(int *)(in_EAX + 0x15c));
  iVar3 = *(int *)(*(int *)(in_EAX + 0x158) + 0x7c);
  iVar12 = uVar10 * 0x5c + iVar3;
  uVar9 = (*(int *)(in_EAX + 0x17c) - iVar3) / 0x5c;
  if (0xff < uVar9) {
    return 0;
  }
  uVar7 = (uint)*(byte *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x158) + 0x84) + uVar10 * 4) + uVar9);
  if (uVar7 < *(byte *)(iVar12 + 0x28)) {
    local_20 = *(int *)(*(int *)(iVar12 + 0x34) + uVar7 * 4);
    *param_1 = (uint)(*(byte *)(local_20 + 0x10) != uVar10);
  }
  if (*(char *)(in_EAX + 0x13c) != -1) {
    uVar5 = __allshl();
    if ((*(ushort *)(iVar12 + 0x58) & uVar5) == 0) {
      return 0;
    }
    if (((*(ushort *)(iVar12 + 0x5a) & uVar5) == 0) ||
       ((local_20 != 0 && ((*(ushort *)(local_20 + 0x14) & uVar5) != 0)))) {
      iVar3 = *(int *)(*(int *)(in_EAX + 0x158) + 0x88) + (uint)*(byte *)(in_EAX + 0x13c) * 0x28;
      uVar5 = *(ushort *)(*(int *)(*(int *)(in_EAX + 0x158) + 0x7c) + 0x58 + uVar9 * 0x5c);
      local_20 = 0;
      uVar6 = __allshl();
      if ((uVar5 & uVar6) == 0) {
        iVar11 = 0;
        local_18 = 3.4028235e+38;
        if (*(char *)(iVar3 + 0x11) != '\0') {
          do {
            fVar13 = (float10)FUN_0051a890(*(undefined4 *)(in_EAX + 0x158),uVar10,
                                           *(undefined1 *)(*(int *)(iVar3 + 0xc) + iVar11),
                                           *(undefined1 *)(in_EAX + 0x13c),0);
            uVar8 = __allshl();
            fVar14 = (float10)FUN_0051a890(*(undefined4 *)(in_EAX + 0x158),
                                           *(undefined1 *)(*(int *)(iVar3 + 0xc) + iVar11),uVar9,
                                           0xff,uVar8);
            if (((float)fVar13 == 3.4028235e+38) || ((float)fVar14 == 3.4028235e+38)) {
              fVar4 = 3.4028235e+38;
            }
            else {
              fVar4 = (float)fVar14 + (float)fVar13;
            }
            if (fVar4 < local_18) {
              local_10 = (uint)*(byte *)(*(int *)(iVar3 + 0xc) + iVar11);
              local_18 = fVar4;
            }
            iVar11 = iVar11 + 1;
          } while (iVar11 < (int)(uint)*(byte *)(iVar3 + 0x11));
        }
        if (local_18 == 3.4028235e+38) {
          return 0;
        }
        bVar1 = *(byte *)(*(int *)(iVar3 + 4) + uVar10);
        bVar2 = *(byte *)(*(int *)(iVar3 + 4) + local_10);
      }
      else {
        bVar1 = *(byte *)(*(int *)(iVar3 + 4) + uVar10);
        bVar2 = *(byte *)(*(int *)(iVar3 + 4) + uVar9);
      }
      uVar9 = (uint)*(byte *)(*(int *)(*(int *)(iVar3 + 0x14) + (uint)bVar1 * 4) + (uint)bVar2);
      if (uVar9 < *(byte *)(iVar12 + 0x28)) {
        local_20 = *(int *)(*(int *)(iVar12 + 0x34) + uVar9 * 4);
        *param_1 = (uint)(*(byte *)(local_20 + 0x10) != uVar10);
      }
    }
  }
  return local_20;
}

