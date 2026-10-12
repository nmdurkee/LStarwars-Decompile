/* Ghidra analysis pseudocode, not original source.
 * ev_ce999f6f93348d1bea0c268e5ec4785c76bf2f100732e1944453dc4f4dda8e73
 * Entry: 0x6d9df0; label: FUN_006d9df0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006d9df0(int param_1)

{
  void *_Dst;
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int *unaff_EDI;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  int local_4c;
  int local_48;
  char *local_44;
  undefined1 local_40 [4];
  undefined4 uStack_3c;
  undefined1 uStack_38;
  char cStack_34;
  undefined1 uStack_30;
  int iStack_14;
  
  iVar6 = DAT_02975144;
  puVar8 = (undefined4 *)(param_1 + 0x14);
  local_48 = DAT_02975144;
  iVar7 = DAT_02975144 + 0x4e34;
  iVar2 = FUN_006d5080(puVar8);
  iVar4 = DAT_029755dc;
  if (iVar2 == 0) {
    if (*(byte *)(param_1 + 0x24) == 0x13) {
      iVar4 = (**(code **)(*DAT_029765b0 + 0xc))(DAT_029765b0,&DAT_00784dfc,&DAT_029765a4,0);
      if (iVar4 == 0) {
        _DAT_02975920 = 0x2c;
        (**(code **)(*DAT_029765a4 + 0x34))(DAT_029765a4,DAT_00924864,0x16);
        (**(code **)(*DAT_029765a4 + 0x2c))(DAT_029765a4,&DAT_007e7b44);
        (**(code **)(*DAT_029765a4 + 0x1c))(DAT_029765a4);
        (**(code **)(*DAT_029765a4 + 0xc))(DAT_029765a4,&DAT_02975920);
        FUN_006d9bd0();
        *(int **)(iVar6 + 0x5d10) = DAT_029765a4;
        *(undefined2 *)(iVar6 + 0x5d24) = DAT_02975930;
        *(int **)(iVar6 + 0x6008) = DAT_029765a4;
        *(undefined2 *)(iVar6 + 0x601c) = DAT_02975930;
        *(int **)(iVar6 + 0x5e8c) = DAT_029765a4;
        *(undefined2 *)(iVar6 + 0x5ea0) = DAT_02975930;
        *(int **)(iVar6 + 0x6184) = DAT_029765a4;
        *(undefined2 *)(iVar6 + 0x6198) = DAT_02975930;
        DAT_029765ac = 0x100;
      }
    }
    else if (*(byte *)(param_1 + 0x24) - 0x14 < 2) {
      piVar10 = &local_4c;
      piVar12 = DAT_029765b0;
      iVar4 = (**(code **)(*DAT_029765b0 + 0xc))(DAT_029765b0,param_1 + 4,piVar10,0);
      if (-1 < iVar4) {
        piVar11 = (int *)(iVar6 + 0x5424);
        iVar6 = 4;
        while (*piVar11 != 0) {
          iVar6 = iVar6 + 1;
          piVar11 = piVar11 + 0x5f;
          if (9 < iVar6) {
            return 1;
          }
        }
        if (DAT_00824f9c == -1) {
          DAT_00824f9c = iVar6;
        }
        puVar9 = (undefined4 *)(iVar7 + iVar6 * 0x17c);
        uStack_3c = 0x2c;
        iVar4 = (**(code **)(*unaff_EDI + 0xc))(unaff_EDI,&uStack_3c);
        *(short *)(puVar9 + 6) = (short)cStack_34;
        *(bool *)((int)puVar9 + 0x2d) = iVar4 == 0;
        *(undefined1 *)((int)puVar9 + 0x1b) = uStack_30;
        puVar9[1] = piVar10;
        *(undefined1 *)((int)puVar9 + 0x1a) = uStack_38;
        *(undefined1 *)(puVar9 + 7) = 0x20;
        *puVar9 = 5;
        *(undefined1 *)((int)puVar9 + 0x2a) = 1;
        puVar9[2] = *puVar8;
        puVar9[3] = *(undefined4 *)(param_1 + 0x18);
        puVar9[4] = *(undefined4 *)(param_1 + 0x1c);
        pcVar3 = (char *)(param_1 + 300);
        puVar9[5] = *(undefined4 *)(param_1 + 0x20);
        pcVar5 = pcVar3;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        iStack_14 = (int)pcVar5 - (param_1 + 0x12d);
        if (0x3f < iStack_14) {
          iStack_14 = 0x3f;
        }
        _memset((void *)((int)puVar9 + 0x2e),0,0x3f);
        FUN_004ef660((void *)((int)puVar9 + 0x2e),pcVar3,iStack_14);
        iVar4 = FUN_004f8a70(pcVar3,"Saitek");
        if (iVar4 != 0) {
          iVar4 = FUN_004f8a70(pcVar3,"P2600");
          if (iVar4 == 0) {
            iVar4 = FUN_004f8a70(pcVar3,"P2900");
            if (iVar4 == 0) goto LAB_006da0a0;
          }
          *(short *)(puVar9 + 6) = *(short *)(puVar9 + 6) + -2;
        }
LAB_006da0a0:
        piVar11 = (int *)&DAT_007e7d4c;
        (**(code **)(*piVar10 + 0x2c))(piVar10);
        (**(code **)(*piVar12 + 0x34))(piVar12,DAT_00924864,9);
        (**(code **)(*piVar11 + 0x1c))(piVar11);
        FUN_006d5390(piVar10);
        FUN_006d9b80(7,iVar6);
        DAT_0297658c = DAT_0297658c + 1;
        return 1;
      }
    }
    return 1;
  }
  DAT_00824f9c = DAT_029755dc;
  iVar6 = DAT_029755dc * 0x17c;
  *(undefined4 *)(iVar6 + 8 + iVar7) = *puVar8;
  *(undefined4 *)(iVar6 + 0xc + iVar7) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(iVar6 + 0x10 + iVar7) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(iVar6 + 0x14 + iVar7) = *(undefined4 *)(param_1 + 0x20);
  local_44 = (char *)(param_1 + 300);
  pcVar3 = local_44;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  param_1 = (int)pcVar3 - (param_1 + 0x12d);
  if (0x3f < param_1) {
    param_1 = 0x3f;
  }
  _Dst = (void *)(iVar6 + 0x2e + iVar7);
  _memset(_Dst,0,0x3f);
  FUN_004ef660(_Dst,local_44,param_1);
  puVar8 = (undefined4 *)(iVar7 + iVar6);
  *puVar8 = 6;
  *(undefined1 *)((int)puVar8 + 0x2d) = 0;
  *(undefined1 *)(puVar8 + 7) = 0x40;
  iVar2 = XInputGetCapabilities(iVar4,1,local_40);
  iVar6 = local_48;
  if (iVar2 == 0) {
    FUN_006d47a0(local_40,puVar8);
    if (((*(short *)(puVar8 + 6) == 10) && (*(char *)((int)puVar8 + 0x1a) == '\x05')) &&
       (*(char *)((int)puVar8 + 0x1b) == '\x01')) {
      puVar8[2] = &DAT_028e045e;
    }
  }
  iVar6 = FUN_006d43e0(7,iVar4,*(undefined4 *)(iVar6 + 0x6604));
  if (iVar6 == 0) {
    iVar6 = FUN_006d43e0(7,iVar4,0xffffffff);
    if (iVar6 == 0) goto LAB_006d9f20;
  }
  FUN_006d45f0(iVar6,iVar4,(int)*(short *)(iVar6 + 0x5e),0,0);
LAB_006d9f20:
  DAT_029755dc = DAT_029755dc + 1;
  return 1;
}

