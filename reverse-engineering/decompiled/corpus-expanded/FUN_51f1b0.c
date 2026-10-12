/* Ghidra pseudocode, not original source.
 * ev_fe5af94714569ca149d7ee11beb07ec697c406bef5bd6833183fcd21241d309c
 * Entry: 0x51f1b0; label: FUN_0051f1b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0051f1b0(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  float10 fVar13;
  undefined4 local_c [2];
  undefined4 local_4;
  
  iVar4 = param_2;
  iVar12 = *(int *)(param_2 + 0x188);
  if (((iVar12 != 0) &&
      (cVar2 = *(char *)((*(char *)(param_2 + 0x160) == '\0') + 0x10 + *(int *)(param_2 + 0x15c)),
      *(char *)(iVar12 + 0x10) != cVar2)) && (*(char *)(iVar12 + 0x11) != cVar2)) {
    *(undefined4 *)(param_2 + 0x188) = 0;
  }
  if (*(int *)(param_2 + 0x188) == 0) {
    uVar11 = (uint)*(byte *)((*(char *)(param_2 + 0x160) == '\0') + 0x10 + *(int *)(param_2 + 0x15c)
                            );
    iVar12 = uVar11 * 0x5c + *(int *)(*(int *)(param_2 + 0x158) + 0x7c);
    uVar10 = (uint)*(byte *)(iVar12 + 0x28);
    uVar6 = FUN_005b9e30();
    uVar6 = uVar6 % uVar10;
    param_2 = 0;
    if (uVar10 != 0) {
      do {
        iVar3 = *(int *)(*(int *)(iVar12 + 0x34) + ((int)(param_2 + uVar6) % (int)uVar10) * 4);
        *(int *)(iVar4 + 0x188) = iVar3;
        if ((iVar3 != *(int *)(iVar4 + 0x15c)) &&
           (((*(char *)(iVar4 + 0x13c) == -1 ||
             (uVar5 = __allshl(), (*(ushort *)(iVar3 + 0x14) & uVar5) != 0)) ||
            ((*(ushort *)(iVar12 + 0x5a) & uVar5) != 0)))) {
          if (*(byte *)(iVar3 + 0x10) == uVar11) {
            *(undefined1 *)(iVar4 + 0x14b) = 0;
          }
          else {
            *(undefined1 *)(iVar4 + 0x14b) = 1;
          }
          if (*(int *)(iVar3 + (uint)*(byte *)(iVar4 + 0x14b) * 4) == 0) break;
        }
        *(undefined4 *)(iVar4 + 0x188) = 0;
        uVar10 = (uint)*(byte *)(iVar12 + 0x28);
        param_2 = param_2 + 1;
      } while (param_2 < (int)uVar10);
    }
    if (*(int *)(iVar4 + 0x188) == 0) {
      iVar12 = (uint)*(byte *)((*(char *)(iVar4 + 0x160) == '\0') + 0x10 + *(int *)(iVar4 + 0x15c))
               * 0x5c + *(int *)(*(int *)(iVar4 + 0x158) + 0x7c);
      fVar13 = (float10)FUN_005b3cf0(param_3 + 0x5c,iVar12 + 4,local_c);
      if ((float)fVar13 < *(float *)(iVar12 + 0x14)) {
        FUN_0051b890(iVar4,param_3 + 0x5c,*(undefined4 *)(iVar4 + 0x15c),
                     *(char *)(iVar4 + 0x160) == '\0');
        iVar12 = (uint)*(byte *)((*(char *)(iVar4 + 0x160) == '\0') + 0x10 + *(int *)(iVar4 + 0x15c)
                                ) * 0x5c + *(int *)(*(int *)(iVar4 + 0x158) + 0x7c);
        *(int *)(iVar4 + 0x17c) = iVar12;
      }
      *(undefined4 *)(iVar4 + 0x104) = *(undefined4 *)(iVar12 + 4);
      *(undefined4 *)(iVar4 + 0x108) = *(undefined4 *)(iVar12 + 8);
      uVar8 = *(undefined4 *)(iVar12 + 0xc);
      goto LAB_0051f5ea;
    }
  }
  *(uint *)(iVar4 + 0x1e8) = *(uint *)(iVar4 + 0x1e8) | 0x80000;
  iVar12 = FUN_0051b1f0(param_1,iVar4 + 0x14c,*(undefined4 *)(iVar4 + 0x158),
                        *(undefined4 *)(iVar4 + 0x188),param_4,*(undefined4 *)(iVar4 + 0x15c),
                        *(undefined1 *)(iVar4 + 0x13c),*(undefined1 *)(param_3 + 0x28d),0,
                        *(undefined4 *)(param_3 + 0xac),0);
  if (iVar12 == 0) {
    puVar1 = (undefined4 *)(iVar4 + 0x104);
    iVar7 = (uint)*(byte *)((*(char *)(iVar4 + 0x14b) == '\0') + 0x10 + *(int *)(iVar4 + 0x188)) *
            0x5c;
    iVar3 = *(int *)(*(int *)(iVar4 + 0x158) + 0x7c);
    iVar12 = iVar7 + 4 + iVar3;
    *puVar1 = *(undefined4 *)(iVar7 + 4 + iVar3);
    *(undefined4 *)(iVar4 + 0x108) = *(undefined4 *)(iVar12 + 4);
    uVar8 = *(undefined4 *)(iVar12 + 8);
    *(undefined4 *)(iVar4 + 0x110) = 0;
    *(undefined4 *)(iVar4 + 0x10c) = uVar8;
    iVar12 = FUN_0051c430(param_1,iVar4,param_3,*(undefined4 *)(iVar4 + 0x15c),
                          *(undefined4 *)(iVar4 + 0x188));
    if (iVar12 == 0) {
      return;
    }
    if ((*(byte *)(iVar4 + 0x1e8) & 0x40) != 0) {
      FUN_005b3800(local_c,(undefined4 *)(iVar4 + 0x1a4),param_3 + 0x5c);
      uVar8 = FUN_005be2d0(local_c[0],local_4);
      FUN_005b3800(local_c,puVar1,param_3 + 0x5c);
      uVar9 = FUN_005be2d0(local_c[0],local_4);
      iVar12 = FUN_005be5b0(uVar9,uVar8);
      if (iVar12 < 0) {
        *puVar1 = *(undefined4 *)(iVar4 + 0x1a4);
        *(undefined4 *)(iVar4 + 0x108) = *(undefined4 *)(iVar4 + 0x1a8);
        *(undefined4 *)(iVar4 + 0x10c) = *(undefined4 *)(iVar4 + 0x1ac);
        return;
      }
    }
    if ((*(byte *)(iVar4 + 0x1e8) & 0x20) == 0) {
      return;
    }
    FUN_005b3800(local_c,(undefined4 *)(iVar4 + 0x198),param_3 + 0x5c);
    uVar8 = FUN_005be2d0(local_c[0],local_4);
    FUN_005b3800(local_c,puVar1,param_3 + 0x5c);
    uVar9 = FUN_005be2d0(local_c[0],local_4);
    iVar12 = FUN_005be5b0(uVar9,uVar8);
    if (iVar12 < 1) {
      return;
    }
    *puVar1 = *(undefined4 *)(iVar4 + 0x198);
    *(undefined4 *)(iVar4 + 0x108) = *(undefined4 *)(iVar4 + 0x19c);
    *(undefined4 *)(iVar4 + 0x10c) = *(undefined4 *)(iVar4 + 0x1a0);
    return;
  }
  FUN_0051b890(iVar4,param_3 + 0x5c,*(undefined4 *)(iVar4 + 0x188),*(undefined1 *)(iVar4 + 0x14b));
  iVar12 = (uint)*(byte *)((*(char *)(iVar4 + 0x160) == '\0') + 0x10 + *(int *)(iVar4 + 0x15c)) *
           0x5c + *(int *)(*(int *)(iVar4 + 0x158) + 0x7c);
  *(int *)(iVar4 + 0x17c) = iVar12;
  *(undefined4 *)(iVar4 + 0x104) = *(undefined4 *)(iVar12 + 4);
  *(undefined4 *)(iVar4 + 0x108) = *(undefined4 *)(iVar12 + 8);
  uVar8 = *(undefined4 *)(iVar12 + 0xc);
  *(undefined4 *)(iVar4 + 0x188) = 0;
LAB_0051f5ea:
  *(undefined4 *)(iVar4 + 0x10c) = uVar8;
  *(undefined4 *)(iVar4 + 0x110) = 0;
  return;
}

