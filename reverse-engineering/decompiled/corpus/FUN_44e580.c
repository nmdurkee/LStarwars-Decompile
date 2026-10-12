/* Ghidra analysis pseudocode, not original source.
 * ev_92d4a724e69b6a04034eabfeaec94ac3aa2e75ce908c67016b571f650bed7677
 * Entry: 0x44e580; label: FUN_0044e580
 */

undefined4 FUN_0044e580(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float local_c [2];
  float fStack_4;
  
  if (((param_3 == 0) || (piVar2 = *(int **)(param_3 + 0xd0), piVar2 == (int *)0x0)) ||
     (*piVar2 == 0)) {
    return 1;
  }
  if (((param_1 != 0) && (*(int *)(param_1 + 0x10) != 0)) &&
     (((*(uint *)(*piVar2 + 0x1f8) & 0x400) != 0 && (*(char *)(*piVar2 + 0x400) != -1)))) {
    iVar3 = *(int *)((uint)*(byte *)(param_3 + 0x138) * 0xa4 + 0x30 + *(int *)(param_1 + 0x18));
    if (param_6 == 0) {
      iVar6 = *(int *)(param_2 + 0x6c);
      if (iVar6 == 0) {
        return 0;
      }
      fVar7 = (float10)FUN_005b3cf0(piVar2 + 0x17,iVar6 + 4,local_c);
      if (*(float *)(iVar6 + 0x14) <= (float)fVar7) {
        FUN_0052fcb0(param_3,iVar6 + 4,0,param_2 + 0x84,1,*(undefined4 *)(param_3 + 0x180));
        return 0;
      }
      *(undefined4 *)(param_3 + 0x158) = 0;
      *(undefined4 *)(param_3 + 0x15c) = 0;
      *(undefined4 *)(param_3 + 0x160) = 0;
      *(undefined4 *)(param_3 + 0x164) = 0;
      *(undefined4 *)(param_3 + 0x168) = 0;
      *(undefined4 *)(param_3 + 0x16c) = 0;
      FUN_0051a7c0(param_3,iVar3);
      FUN_0051b890(param_3,*(int *)(param_3 + 0xd0) + 0x5c,*(undefined4 *)(param_3 + 0x1d0),0);
    }
    else if (*(int *)(param_3 + 0x158) != iVar3) {
      iVar6 = 0;
      pcVar4 = DAT_009238b0;
      if (0 < param_5) {
        do {
          if (pcVar4 != (code *)0x0) {
            (*pcVar4)(*(undefined4 *)(param_4 + iVar6 * 4),param_3 + 0x13f);
            pcVar4 = DAT_009238b0;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < param_5);
      }
      *(undefined4 *)(param_3 + 0x17c) = 0;
      if (((*(int *)(param_3 + 0x158) != 0) &&
          (*(int *)(param_3 + 0x158) == *(int *)(*(int *)(param_1 + 0x10) + 8))) &&
         ((*(int *)(param_3 + 0x15c) != 0 && ((*(byte *)(iVar3 + 0x11) & 2) != 0)))) {
        iVar6 = 0;
        if (*(byte *)(iVar3 + 0x10) == 0) {
          return 1;
        }
        iVar5 = *(int *)(iVar3 + 0x7c);
        while ((*(byte *)(iVar5 + 0x2b) & 1) == 0) {
          iVar6 = iVar6 + 1;
          iVar5 = iVar5 + 0x5c;
          if ((int)(uint)*(byte *)(iVar3 + 0x10) <= iVar6) {
            return 1;
          }
        }
        *(int *)(param_2 + 0x6c) = iVar5;
        FUN_0051a7c0(param_3,*(undefined4 *)(param_3 + 0x158));
        uVar1 = *(ushort *)(iVar5 + 0x2c);
        iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + 8) + 0x80);
        *(ushort *)(param_2 + 0x92) = *(ushort *)(param_2 + 0x92) | 1;
        iVar3 = iVar3 + (uint)uVar1 * 0x24;
        *(int *)(param_2 + 0x88) = iVar3;
        *(undefined1 *)(param_2 + 0x8c) = 0;
        iVar6 = (uint)*(byte *)(iVar3 + 0x10) * 0x5c + *(int *)(*(int *)(param_2 + 0x84) + 0x7c);
        local_c[0] = *(float *)(iVar5 + 4) - *(float *)(iVar6 + 4);
        fStack_4 = *(float *)(iVar5 + 0xc) - *(float *)(iVar6 + 0xc);
        FUN_005b3620(local_c,local_c,-(int)*(short *)(iVar3 + 0x12));
        *(float *)(param_2 + 0x94) = fStack_4 / *(float *)(*(int *)(param_2 + 0x88) + 0x1c);
        *(float *)(param_2 + 0x98) = local_c[0];
        FUN_0052fcb0(param_3,iVar5 + 4,0,param_2 + 0x84,1,*(undefined4 *)(param_3 + 0x180));
      }
      return 0;
    }
    return 1;
  }
  return 0;
}

