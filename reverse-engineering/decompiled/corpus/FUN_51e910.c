/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x51e910; label: FUN_0051e910
 */

void FUN_0051e910(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  byte *pbVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  int in_EAX;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int local_10;
  undefined4 local_c [2];
  undefined4 local_4;
  
  if (((*(int *)(in_EAX + 0x15c) != 0) && (iVar12 = *(int *)(in_EAX + 0x1d0), iVar12 != 0)) &&
     (iVar4 = *(int *)(in_EAX + 0x158), iVar4 == *(int *)(in_EAX + 0x1cc))) {
    if (*(int *)(in_EAX + 0x15c) != iVar12) {
      if (*(char *)(in_EAX + 0x13c) != -1) {
        __allshl();
      }
      if ((*(uint *)(*(int *)(in_EAX + 0x15c) + 4) & 0x40000000) == 0) {
        FUN_0051a890(iVar4,*(undefined1 *)(*(int *)(in_EAX + 0x15c) + 0x10),
                     *(undefined1 *)(iVar12 + 0x10),*(undefined1 *)(in_EAX + 0x13c),0);
        FUN_0051a890(*(undefined4 *)(in_EAX + 0x158),
                     *(undefined1 *)(*(int *)(in_EAX + 0x15c) + 0x10),
                     *(undefined1 *)(*(int *)(in_EAX + 0x1d0) + 0x11),
                     *(undefined1 *)(in_EAX + 0x13c),0);
      }
      if ((**(uint **)(in_EAX + 0x15c) & 0x40000000) == 0) {
        FUN_0051a890(*(undefined4 *)(in_EAX + 0x158),
                     *(undefined1 *)((int)*(uint **)(in_EAX + 0x15c) + 0x11),
                     *(undefined1 *)(*(int *)(in_EAX + 0x1d0) + 0x10),
                     *(undefined1 *)(in_EAX + 0x13c),0);
        FUN_0051a890(*(undefined4 *)(in_EAX + 0x158),
                     *(undefined1 *)(*(int *)(in_EAX + 0x15c) + 0x11),
                     *(undefined1 *)(*(int *)(in_EAX + 0x1d0) + 0x11),
                     *(undefined1 *)(in_EAX + 0x13c),0);
      }
    }
    iVar7 = param_2 + 0x5c;
    FUN_0051b890();
    pbVar2 = (byte *)((*(char *)(in_EAX + 0x160) == '\0') + 0x10 + *(int *)(in_EAX + 0x15c));
    *(uint *)(in_EAX + 0x17c) = (uint)*pbVar2 * 0x5c + *(int *)(iVar4 + 0x7c);
    iVar12 = *(int *)(in_EAX + 0x188);
    if (((iVar12 != 0) && (*(byte *)(iVar12 + 0x10) != *pbVar2)) &&
       (*(byte *)(iVar12 + 0x11) != *pbVar2)) {
      *(undefined4 *)(in_EAX + 0x188) = 0;
    }
    if (*(int *)(in_EAX + 0x188) == 0) {
      bVar3 = *pbVar2;
      iVar12 = (uint)bVar3 * 0x5c + *(int *)(*(int *)(in_EAX + 0x158) + 0x7c);
      uVar11 = (uint)*(byte *)(iVar12 + 0x28);
      uVar8 = FUN_005b9e30();
      uVar8 = uVar8 % uVar11;
      local_10 = 0;
      if (uVar11 != 0) {
        do {
          iVar13 = *(int *)(*(int *)(iVar12 + 0x34) + ((int)(local_10 + uVar8) % (int)uVar11) * 4);
          *(int *)(in_EAX + 0x188) = iVar13;
          if ((iVar13 != *(int *)(in_EAX + 0x15c)) &&
             ((((*(char *)(in_EAX + 0x13c) == -1 ||
                (uVar6 = __allshl(), (*(ushort *)(iVar13 + 0x14) & uVar6) != 0)) ||
               ((*(ushort *)(iVar12 + 0x5a) & uVar6) != 0)) &&
              (*(int *)(iVar13 + (uint)((uint)*(byte *)(iVar13 + 0x10) != (uint)bVar3) * 4) == 0))))
          break;
          *(undefined4 *)(in_EAX + 0x188) = 0;
          uVar11 = (uint)*(byte *)(iVar12 + 0x28);
          local_10 = local_10 + 1;
        } while (local_10 < (int)uVar11);
      }
      if (*(int *)(in_EAX + 0x188) == 0) {
        uVar8 = (uint)*(byte *)(*(byte *)(in_EAX + 0x160) + 0x10 + *(int *)(in_EAX + 0x15c));
        iVar12 = uVar8 * 0x5c + *(int *)(iVar4 + 0x7c);
        iVar13 = 0;
        if (*(char *)(iVar12 + 0x28) != '\0') {
          do {
            iVar5 = *(int *)(*(int *)(iVar12 + 0x34) + iVar13 * 4);
            *(int *)(in_EAX + 0x188) = iVar5;
            if ((iVar5 != *(int *)(in_EAX + 0x15c)) &&
               (*(int *)(iVar5 + (uint)(*(byte *)(iVar5 + 0x10) != uVar8) * 4) == 0)) {
              FUN_0051b890();
              *(uint *)(in_EAX + 0x17c) =
                   (uint)*(byte *)((*(char *)(in_EAX + 0x160) == '\0') + 0x10 +
                                  *(int *)(in_EAX + 0x15c)) * 0x5c + *(int *)(iVar4 + 0x7c);
              break;
            }
            *(undefined4 *)(in_EAX + 0x188) = 0;
            iVar13 = iVar13 + 1;
          } while (iVar13 < (int)(uint)*(byte *)(iVar12 + 0x28));
        }
      }
    }
    if (*(int *)(in_EAX + 0x188) == 0) {
      iVar12 = *(int *)(in_EAX + 0x17c);
      *(undefined4 *)(in_EAX + 0x104) = *(undefined4 *)(iVar12 + 4);
      *(undefined4 *)(in_EAX + 0x108) = *(undefined4 *)(iVar12 + 8);
      uVar9 = *(undefined4 *)(iVar12 + 0xc);
    }
    else {
      iVar12 = FUN_0051b1f0(param_1,in_EAX + 0x14c,*(undefined4 *)(in_EAX + 0x158),
                            *(int *)(in_EAX + 0x188),param_3,*(undefined4 *)(in_EAX + 0x15c),
                            *(undefined1 *)(in_EAX + 0x13c),*(undefined1 *)(param_2 + 0x28d),0,
                            *(undefined4 *)(param_2 + 0xac),0);
      if (iVar12 == 0) {
        puVar1 = (undefined4 *)(in_EAX + 0x104);
        iVar13 = (uint)*(byte *)((*(char *)(in_EAX + 0x14b) == '\0') + 0x10 +
                                *(int *)(in_EAX + 0x188)) * 0x5c;
        iVar4 = *(int *)(*(int *)(in_EAX + 0x158) + 0x7c);
        iVar12 = iVar13 + 4 + iVar4;
        *puVar1 = *(undefined4 *)(iVar13 + 4 + iVar4);
        *(undefined4 *)(in_EAX + 0x108) = *(undefined4 *)(iVar12 + 4);
        uVar9 = *(undefined4 *)(iVar12 + 8);
        *(undefined4 *)(in_EAX + 0x110) = 0;
        *(undefined4 *)(in_EAX + 0x10c) = uVar9;
        iVar12 = FUN_0051c430(param_1);
        if (iVar12 == 0) {
          return;
        }
        if ((*(byte *)(in_EAX + 0x1e8) & 0x40) != 0) {
          FUN_005b3800(local_c,(undefined4 *)(in_EAX + 0x1a4),iVar7);
          uVar9 = FUN_005be2d0(local_c[0],local_4);
          FUN_005b3800(local_c,puVar1,iVar7);
          uVar10 = FUN_005be2d0(local_c[0],local_4);
          iVar12 = FUN_005be5b0(uVar10,uVar9);
          if (iVar12 < 0) {
            *puVar1 = *(undefined4 *)(in_EAX + 0x1a4);
            *(undefined4 *)(in_EAX + 0x108) = *(undefined4 *)(in_EAX + 0x1a8);
            *(undefined4 *)(in_EAX + 0x10c) = *(undefined4 *)(in_EAX + 0x1ac);
            return;
          }
        }
        if ((*(byte *)(in_EAX + 0x1e8) & 0x20) == 0) {
          return;
        }
        FUN_005b3800(local_c,(undefined4 *)(in_EAX + 0x198),iVar7);
        uVar9 = FUN_005be2d0(local_c[0],local_4);
        FUN_005b3800(local_c,puVar1,iVar7);
        uVar10 = FUN_005be2d0(local_c[0],local_4);
        iVar12 = FUN_005be5b0(uVar10,uVar9);
        if (iVar12 < 1) {
          return;
        }
        *puVar1 = *(undefined4 *)(in_EAX + 0x198);
        *(undefined4 *)(in_EAX + 0x108) = *(undefined4 *)(in_EAX + 0x19c);
        *(undefined4 *)(in_EAX + 0x10c) = *(undefined4 *)(in_EAX + 0x1a0);
        return;
      }
      FUN_0051b890();
      iVar12 = (uint)*(byte *)((*(char *)(in_EAX + 0x160) == '\0') + 0x10 + *(int *)(in_EAX + 0x15c)
                              ) * 0x5c + *(int *)(iVar4 + 0x7c);
      *(int *)(in_EAX + 0x17c) = iVar12;
      *(undefined4 *)(in_EAX + 0x104) = *(undefined4 *)(iVar12 + 4);
      *(undefined4 *)(in_EAX + 0x108) = *(undefined4 *)(iVar12 + 8);
      uVar9 = *(undefined4 *)(iVar12 + 0xc);
      *(undefined4 *)(in_EAX + 0x188) = 0;
    }
    *(undefined4 *)(in_EAX + 0x10c) = uVar9;
    *(undefined4 *)(in_EAX + 0x110) = 0;
  }
  return;
}

