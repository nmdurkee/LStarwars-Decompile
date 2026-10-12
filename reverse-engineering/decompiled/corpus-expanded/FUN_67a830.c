/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67a830; label: FUN_0067a830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0067a830(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  uint *puVar2;
  short sVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  if (DAT_0292fc68 != (int *)0x0) {
    if ((param_3 == (undefined4 *)0x0) && (param_4 == 0)) {
      FUN_0067a790(param_1,param_2 + 0x30);
    }
    else if (DAT_0292fc68[0x54] < DAT_0292fc68[0x2921]) {
      if (DAT_0292fc68[0x2922] <= (int)(short)DAT_0292fc68[0x53]) {
        return -1;
      }
      if ((param_2 != 0) && ((param_3 != (undefined4 *)0x0 || (param_4 == 0)))) {
        sVar3 = *(short *)((int)DAT_02924af4 + param_1 * 2 + 0xc);
        if ((sVar3 != -1) && (DAT_0292fc68[0x55] < 0x20)) {
          iVar4 = 0;
          if (0 < DAT_0292fc68[0x2923]) {
            piVar5 = (int *)(DAT_0292fc68[0x1a] + 0x40);
            while (*piVar5 != 0) {
              iVar4 = iVar4 + 1;
              piVar5 = piVar5 + 0x1b;
              if (DAT_0292fc68[0x2923] <= iVar4) {
                return -1;
              }
            }
            if (iVar4 != -1) {
              puVar1 = (undefined4 *)(*DAT_0292fc68 + (short)DAT_0292fc68[0x53] * 0x38);
              iVar7 = iVar4 * 0x6c;
              puVar8 = (undefined4 *)(*DAT_02924af4 + sVar3 * 0x38);
              puVar9 = puVar1;
              for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {
                *puVar9 = *puVar8;
                puVar8 = puVar8 + 1;
                puVar9 = puVar9 + 1;
              }
              *(short *)(puVar1 + 0xc) = (short)iVar4;
              puVar1[0xb] = 1;
              *(int *)(DAT_0292fc68[0x1a] + 0x40 + iVar7) = param_2;
              if (param_4 == 0) {
                if (param_3 == (undefined4 *)0x0) {
                  *(undefined4 *)(DAT_0292fc68[0x1a] + 0x30 + iVar7) =
                       *(undefined4 *)(param_2 + 0x30);
                  *(undefined4 *)(DAT_0292fc68[0x1a] + 0x34 + iVar7) =
                       *(undefined4 *)(param_2 + 0x34);
                  *(undefined4 *)(DAT_0292fc68[0x1a] + 0x38 + iVar7) =
                       *(undefined4 *)(param_2 + 0x38);
                }
                else {
                  *(undefined4 *)(DAT_0292fc68[0x1a] + 0x30 + iVar7) = param_3[0xc];
                  *(undefined4 *)(DAT_0292fc68[0x1a] + 0x34 + iVar7) = param_3[0xd];
                  *(undefined4 *)(DAT_0292fc68[0x1a] + 0x38 + iVar7) = param_3[0xe];
                }
                puVar2 = (uint *)(DAT_0292fc68[0x1a] + 0x4c + iVar7);
                *puVar2 = *puVar2 & 0xfffffffe;
              }
              else {
                puVar8 = (undefined4 *)(DAT_0292fc68[0x1a] + iVar7);
                for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
                  *puVar8 = *param_3;
                  param_3 = param_3 + 1;
                  puVar8 = puVar8 + 1;
                }
                puVar2 = (uint *)(DAT_0292fc68[0x1a] + 0x4c + iVar7);
                *puVar2 = *puVar2 | 1;
              }
              *puVar1 = *(undefined4 *)(param_2 + 0x30);
              puVar1[1] = *(undefined4 *)(param_2 + 0x34);
              puVar1[2] = *(undefined4 *)(param_2 + 0x38);
              *(short *)(DAT_0292fc68[0x1a] + 0x48 + iVar7) = (short)DAT_0292fc68[0x53];
              *(undefined2 *)(DAT_0292fc68[0x1a] + 0x4a + iVar7) = 0;
              *(undefined4 *)(DAT_0292fc68[0x1a] + 0x68 + iVar7) = 0;
              *(short *)(DAT_0292fc68[0x6ed] + DAT_0292fc68[0x54] * 2) = (short)DAT_0292fc68[0x53];
              DAT_0292fc68[0x54] = DAT_0292fc68[0x54] + 1;
              *(undefined4 *)(DAT_0292fc68[0x1a] + 0x54 + iVar7) = 0;
              *(undefined4 *)(DAT_0292fc68[0x1a] + 0x58 + iVar7) = 0;
              *(undefined4 *)(DAT_0292fc68[0x1a] + 0x5c + iVar7) = 0;
              *(undefined4 *)(DAT_0292fc68[0x1a] + 100 + iVar7) = 0;
              *(undefined4 *)(DAT_0292fc68[0x1a] + 0x60 + iVar7) = 0;
              puVar2 = (uint *)(DAT_0292fc68[0x1a] + 0x4c + iVar7);
              *puVar2 = *puVar2 & 0xfffffffd;
              if (DAT_0292fc68[0x4b] < 0x60) {
                *(short *)((int)DAT_0292fc68 + DAT_0292fc68[0x4b] * 2 + 0x6c) =
                     (short)DAT_0292fc68[0x53];
                DAT_0292fc68[0x4b] = DAT_0292fc68[0x4b] + 1;
              }
              *(short *)(DAT_0292fc68 + 0x53) = (short)DAT_0292fc68[0x53] + 1;
              *(short *)((int)DAT_0292fc68 + 0x1b9a) = *(short *)((int)DAT_0292fc68 + 0x1b9a) + 1;
              *(short *)((int)DAT_0292fc68 + DAT_0292fc68[0x55] * 2 + 0x158) = (short)iVar4;
              DAT_0292fc68[0x55] = DAT_0292fc68[0x55] + 1;
              return iVar4;
            }
          }
        }
        return -1;
      }
      return -1;
    }
  }
  return -1;
}

