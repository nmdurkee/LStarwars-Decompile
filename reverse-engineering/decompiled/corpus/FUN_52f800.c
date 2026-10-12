/* Ghidra analysis pseudocode, not original source.
 * ev_71ff980de6cd2ba2d40ffdcea863fac96239c7d224aa9f068f740db15dbd9919
 * Entry: 0x52f800; label: FUN_0052f800
 */

uint FUN_0052f800(int param_1,int param_2,int param_3,uint param_4,int param_5)

{
  char *pcVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  uint uVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 local_10;
  uint local_c;
  undefined4 local_8;
  uint local_4;
  
  iVar4 = param_3;
  local_10 = 0x7f7fffff;
  uVar6 = (*(ushort *)(param_3 + 0x166) & 1) * 2 | *(ushort *)(param_3 + 0x166) & 0xfff4;
  *(ushort *)(param_3 + 0x166) = uVar6;
  if (((param_1 == 0) || (pcVar1 = *(char **)(param_1 + 0x10), pcVar1 == (char *)0x0)) ||
     (*pcVar1 == '\0')) {
    *(ushort *)(param_3 + 0x166) = uVar6;
    uVar5 = FUN_0051a7c0(param_3,0);
    *(undefined4 *)(param_3 + 0x15c) = 0;
    *(undefined1 *)(param_3 + 0x13d) = 0;
    *(undefined1 *)(param_3 + 0x13c) = 0xff;
    return uVar5;
  }
  if (*(int *)(param_3 + 0x158) == 0) {
    if ((*(byte *)(param_3 + 0x1ec) & 2) == 0) {
      uVar11 = *(undefined4 *)(pcVar1 + 8);
    }
    else {
      uVar11 = **(undefined4 **)(pcVar1 + 4);
    }
    FUN_0051a7c0(param_3,uVar11);
    *(undefined4 *)(param_3 + 0x15c) = 0;
    *(undefined1 *)(param_3 + 0x13c) = 0xff;
    *(undefined1 *)(param_3 + 0x13d) = 0;
    *(undefined2 *)(param_3 + 0x164) = 0;
    *(undefined1 *)(param_3 + 0x161) = 0;
  }
  FUN_0051a760();
  iVar8 = *(int *)(param_3 + 0x15c);
  if (iVar8 != 0) {
    uVar7 = (uint)*(byte *)(param_3 + 0x160);
    uVar5 = FUN_0052e9c0(param_1,param_2,iVar8,uVar7,&local_10);
    if (uVar5 != 0) {
      return uVar5;
    }
    if ((*(byte *)(param_2 + 0x1fc) & 0x80) == 0) {
      if (*(int *)(param_3 + 0x184) != 0) {
        return 0;
      }
      if (*(char *)(param_3 + 0x139) != '\0') {
        return 0;
      }
      if (param_5 == 0) {
        return 0;
      }
    }
    iVar9 = (uint)*(byte *)(uVar7 + 0x10 + iVar8) * 0x5c +
            *(int *)(*(int *)(param_3 + 0x158) + 0x7c);
    param_3 = 0;
    if (*(char *)(iVar9 + 0x28) != '\0') {
      do {
        iVar10 = *(int *)(*(int *)(iVar9 + 0x34) + param_3 * 4);
        if ((iVar10 != iVar8) &&
           (uVar5 = FUN_0052e9c0(param_1,param_2,iVar10,
                                 *(char *)(iVar10 + 0x10) != *(char *)(uVar7 + 0x10 + iVar8),
                                 &local_10), uVar5 != 0)) {
          return uVar5;
        }
        param_3 = param_3 + 1;
      } while (param_3 < (int)(uint)*(byte *)(iVar9 + 0x28));
    }
    iVar9 = (uint)*(byte *)((uVar7 == 0) + 0x10 + iVar8) * 0x5c +
            *(int *)(*(int *)(iVar4 + 0x158) + 0x7c);
    param_3 = 0;
    if (*(char *)(iVar9 + 0x28) != '\0') {
      do {
        iVar10 = *(int *)(*(int *)(iVar9 + 0x34) + param_3 * 4);
        if ((iVar10 != iVar8) &&
           (uVar5 = FUN_0052e9c0(param_1,param_2,iVar10,
                                 *(char *)(iVar10 + 0x10) != *(char *)((uVar7 == 0) + 0x10 + iVar8),
                                 &local_10), uVar5 != 0)) {
          return uVar5;
        }
        param_3 = param_3 + 1;
      } while (param_3 < (int)(uint)*(byte *)(iVar9 + 0x28));
    }
  }
  iVar8 = 0;
  if ((*(byte *)(iVar4 + 0x1ec) & 2) != 0) {
    local_4 = (uint)*(byte *)(iVar4 + 0x160);
    local_8 = *(undefined4 *)(iVar4 + 0x15c);
    local_c = *(uint *)(iVar4 + 0x158);
    if ((*(byte *)(iVar4 + 0x161) == 0xffffffff) || (*(byte *)(iVar4 + 0x161) == 0xff)) {
      *(undefined1 *)(iVar4 + 0x161) = *(undefined1 *)(local_c + 0x15);
    }
    if (**(byte **)(param_1 + 0x10) <= *(byte *)(iVar4 + 0x161)) {
      *(undefined1 *)(iVar4 + 0x161) = 0;
    }
    iVar9 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + 4) + (uint)*(byte *)(iVar4 + 0x161) * 4);
    *(int *)(iVar4 + 0x158) = iVar9;
    if ((ushort)*(byte *)(iVar9 + 0x10) <= *(ushort *)(iVar4 + 0x164)) {
      *(undefined2 *)(iVar4 + 0x164) = 0;
    }
    FUN_0051a760();
    do {
      if ((int)param_4 < 1) {
        *(uint *)(iVar4 + 0x158) = local_c;
        *(undefined4 *)(iVar4 + 0x15c) = local_8;
        *(undefined1 *)(iVar4 + 0x160) = (undefined1)local_4;
        return local_c;
      }
      if ((iVar8 != 0) ||
         (iVar8 = FUN_005173b0(*(undefined4 *)(iVar4 + 0x158),*(int *)(iVar4 + 0xd0) + 0x5c),
         iVar8 != 0)) {
        iVar10 = (uint)*(ushort *)(iVar4 + 0x164) * 0x5c + *(int *)(*(int *)(iVar4 + 0x158) + 0x7c);
        iVar9 = 0;
        if (*(char *)(iVar10 + 0x28) != '\0') {
          do {
            uVar5 = FUN_0052e9c0(param_1,param_2,
                                 *(undefined4 *)(*(int *)(iVar10 + 0x34) + iVar9 * 4),0xffffffff,
                                 &local_10);
            if (uVar5 != 0) {
              return uVar5;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)(uint)*(byte *)(iVar10 + 0x28));
        }
      }
      *(short *)(iVar4 + 0x164) = *(short *)(iVar4 + 0x164) + 1;
      if (((ushort)*(byte *)(*(int *)(iVar4 + 0x158) + 0x10) <= *(ushort *)(iVar4 + 0x164)) ||
         (iVar8 == 0)) {
        *(char *)(iVar4 + 0x161) = *(char *)(iVar4 + 0x161) + '\x01';
        *(undefined2 *)(iVar4 + 0x164) = 0;
        if (**(byte **)(param_1 + 0x10) <= *(byte *)(iVar4 + 0x161)) {
          *(undefined1 *)(iVar4 + 0x161) = 0;
        }
        *(undefined4 *)(iVar4 + 0x158) =
             *(undefined4 *)
              (*(int *)(*(int *)(param_1 + 0x10) + 4) + (uint)*(byte *)(iVar4 + 0x161) * 4);
        *(undefined4 *)(iVar4 + 0x15c) = 0;
        *(undefined1 *)(iVar4 + 0x13c) = 0xff;
        *(undefined1 *)(iVar4 + 0x13d) = 0;
        FUN_0051a760();
        iVar8 = 0;
      }
      param_4 = param_4 - 1;
    } while( true );
  }
  uVar5 = (uint)*(byte *)(*(int *)(iVar4 + 0x158) + 0x10);
  if ((int)uVar5 < (int)param_4) {
    param_4 = uVar5;
  }
  do {
    if ((int)param_4 < 1) {
      return uVar5;
    }
    iVar9 = (uint)*(ushort *)(iVar4 + 0x164) * 0x5c + *(int *)(*(int *)(iVar4 + 0x158) + 0x7c);
    iVar8 = 0;
    if (*(char *)(iVar9 + 0x28) != '\0') {
      do {
        uVar5 = FUN_0052e9c0(param_1,param_2,*(undefined4 *)(*(int *)(iVar9 + 0x34) + iVar8 * 4),
                             0xffffffff,&local_10);
        if (uVar5 != 0) {
          return uVar5;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)(uint)*(byte *)(iVar9 + 0x28));
    }
    uVar2 = (ulonglong)(int)(uint)*(byte *)(*(int *)(iVar4 + 0x158) + 0x10);
    uVar3 = (ulonglong)(*(ushort *)(iVar4 + 0x164) + 1);
    uVar5 = (uint)(uVar3 / uVar2);
    *(short *)(iVar4 + 0x164) = (short)(uVar3 % uVar2);
    param_4 = param_4 - 1;
  } while( true );
}

