/* Ghidra pseudocode, not original source.
 * ev_32eeff13403f2b0416c64559eab438b182c65995ce85fb3a27dd5c4451fc4fee
 * Entry: 0x67c4f0; label: FUN_0067c4f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0067c4f0(int param_1,int param_2)

{
  undefined4 *puVar1;
  uint *puVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  if (((DAT_0292fc68 == (int *)0x0) || (DAT_0292fc68[0x2921] <= DAT_0292fc68[0x54])) ||
     (DAT_0292fc68[0x2922] <= (int)(short)DAT_0292fc68[0x53])) {
    return -1;
  }
  if (param_1 == 0) {
    return -1;
  }
  sVar3 = *(short *)((int)DAT_02924af4 + param_2 * 2 + 0xc);
  if (sVar3 == -1) {
    return -1;
  }
  iVar4 = 0;
  if (0 < DAT_0292fc68[0x2923]) {
    piVar6 = (int *)(DAT_0292fc68[0x1a] + 0x40);
    while (*piVar6 != 0) {
      iVar4 = iVar4 + 1;
      piVar6 = piVar6 + 0x1b;
      if (DAT_0292fc68[0x2923] <= iVar4) {
        return -1;
      }
    }
    if (iVar4 != -1) {
      puVar1 = (undefined4 *)(*DAT_0292fc68 + (short)DAT_0292fc68[0x53] * 0x38);
      puVar7 = (undefined4 *)(*DAT_02924af4 + sVar3 * 0x38);
      puVar8 = puVar1;
      for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      puVar1[0xb] = 1;
      *(short *)(puVar1 + 0xc) = (short)iVar4;
      iVar5 = iVar4 * 0x6c;
      *(int *)(DAT_0292fc68[0x1a] + 0x40 + iVar5) = param_1;
      puVar2 = (uint *)(DAT_0292fc68[0x1a] + 0x4c + iVar5);
      *puVar2 = *puVar2 & 0xfffffffe;
      *puVar1 = *(undefined4 *)(param_1 + 0x30);
      puVar1[1] = *(undefined4 *)(param_1 + 0x34);
      puVar1[2] = *(undefined4 *)(param_1 + 0x38);
      *(short *)(DAT_0292fc68[0x1a] + 0x48 + iVar5) = (short)DAT_0292fc68[0x53];
      *(undefined2 *)(DAT_0292fc68[0x1a] + 0x4a + iVar5) = 0;
      *(undefined4 *)(DAT_0292fc68[0x1a] + 0x68 + iVar5) = 0;
      *(short *)(DAT_0292fc68[0x6ed] + DAT_0292fc68[0x54] * 2) = (short)DAT_0292fc68[0x53];
      DAT_0292fc68[0x54] = DAT_0292fc68[0x54] + 1;
      *(undefined4 *)(DAT_0292fc68[0x1a] + 0x54 + iVar5) = 0;
      *(undefined4 *)(DAT_0292fc68[0x1a] + 0x58 + iVar5) = 0;
      *(undefined4 *)(DAT_0292fc68[0x1a] + 0x5c + iVar5) = 0;
      *(undefined4 *)(DAT_0292fc68[0x1a] + 100 + iVar5) = 0;
      *(undefined4 *)(DAT_0292fc68[0x1a] + 0x60 + iVar5) = 0;
      puVar2 = (uint *)(DAT_0292fc68[0x1a] + 0x4c + iVar5);
      *puVar2 = *puVar2 & 0xfffffffd;
      *(short *)(DAT_0292fc68 + 0x53) = (short)DAT_0292fc68[0x53] + 1;
      *(short *)((int)DAT_0292fc68 + 0x1b9a) = *(short *)((int)DAT_0292fc68 + 0x1b9a) + 1;
      return iVar4;
    }
  }
  return -1;
}

