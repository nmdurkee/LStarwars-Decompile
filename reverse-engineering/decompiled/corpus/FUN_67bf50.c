/* Ghidra analysis pseudocode, not original source.
 * ev_6fbd3af984a39447bc9fe9dd191dc75e4e15fa1d77defc2a7b40b22f43e8d294
 * Entry: 0x67bf50; label: FUN_0067bf50
 */

int FUN_0067bf50(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  short *psVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  if ((DAT_0292fc68 == (int *)0x0) || (DAT_0292fc68[0x2921] <= DAT_0292fc68[0x54])) {
    return -1;
  }
  if (((int)(short)DAT_0292fc68[0x53] < DAT_0292fc68[0x2922]) && (param_1 != 0)) {
    iVar3 = DAT_0292fc68[0x2923];
    iVar2 = 0;
    if (0 < iVar3) {
      iVar4 = DAT_0292fc68[0x1a];
      piVar5 = (int *)(iVar4 + 0x40);
      while (*piVar5 != 0) {
        iVar2 = iVar2 + 1;
        piVar5 = piVar5 + 0x1b;
        if (iVar3 <= iVar2) {
          return -1;
        }
      }
      if (iVar2 != -1) {
        iVar6 = 0;
        if (0 < iVar3) {
          psVar7 = (short *)(iVar4 + 0x4a);
          while ((*(int *)(psVar7 + -5) == 0 || (*psVar7 != param_2))) {
            iVar6 = iVar6 + 1;
            psVar7 = psVar7 + 0x36;
            if (iVar3 <= iVar6) {
              return -1;
            }
          }
          if (iVar6 != -1) {
            puVar8 = (undefined4 *)(*DAT_0292fc68 + *(short *)(iVar4 + 0x48 + iVar6 * 0x6c) * 0x38);
            puVar9 = (undefined4 *)(*DAT_0292fc68 + (short)DAT_0292fc68[0x53] * 0x38);
            for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar9 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar9 = puVar9 + 1;
            }
            *(short *)(*DAT_0292fc68 + 0x30 + (short)DAT_0292fc68[0x53] * 0x38) = (short)iVar2;
            *(undefined4 *)(*DAT_0292fc68 + 0x2c + (short)DAT_0292fc68[0x53] * 0x38) = 1;
            iVar4 = iVar2 * 0x6c;
            *(int *)(DAT_0292fc68[0x1a] + 0x40 + iVar4) = param_1;
            *(short *)(DAT_0292fc68[0x1a] + 0x48 + iVar4) = (short)DAT_0292fc68[0x53];
            *(undefined2 *)(DAT_0292fc68[0x1a] + 0x4a + iVar4) = (undefined2)param_2;
            *(undefined4 *)(DAT_0292fc68[0x1a] + 0x68 + iVar4) = 0;
            iVar3 = DAT_0292fc68[0x1a];
            puVar1 = (uint *)(iVar3 + 0x4c + iVar4);
            *puVar1 = *puVar1 ^ (*(uint *)(iVar3 + 0x4c + iVar6 * 0x6c) ^
                                *(uint *)(iVar3 + 0x4c + iVar4)) & 1;
            *(short *)(DAT_0292fc68[0x6ed] + DAT_0292fc68[0x54] * 2) = (short)DAT_0292fc68[0x53];
            DAT_0292fc68[0x54] = DAT_0292fc68[0x54] + 1;
            *(undefined4 *)(DAT_0292fc68[0x1a] + 0x54 + iVar4) = 0;
            *(undefined4 *)(DAT_0292fc68[0x1a] + 0x58 + iVar4) = 0;
            *(undefined4 *)(DAT_0292fc68[0x1a] + 0x5c + iVar4) = 0;
            *(undefined4 *)(DAT_0292fc68[0x1a] + 100 + iVar4) = 0;
            *(undefined4 *)(DAT_0292fc68[0x1a] + 0x60 + iVar4) = 0;
            *(short *)(DAT_0292fc68 + 0x53) = (short)DAT_0292fc68[0x53] + 1;
            *(short *)((int)DAT_0292fc68 + 0x1b9a) = *(short *)((int)DAT_0292fc68 + 0x1b9a) + 1;
            return iVar2;
          }
        }
        return -1;
      }
    }
    return -1;
  }
  return -1;
}

