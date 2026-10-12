/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x66f790; label: FUN_0066f790
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066f790(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  piVar2 = DAT_0296200c;
  iVar1 = DAT_02947c64;
  if (-1 - *(short *)(param_1 + 0x30) < DAT_02947bfc) {
    DAT_0292fc04 = DAT_0292fc04 + 1;
    if (*(int *)(param_1 + 0xc) != 0) {
      DAT_0296200c[*(short *)(DAT_02947c64 + *(short *)(param_1 + 0x30) * -0x1c + -6) * 2] =
           DAT_0292fc04;
      return;
    }
    iVar5 = 0;
    iVar6 = iVar5;
    if ((short)DAT_0296200c[1] != -1) {
      iVar4 = *DAT_0296200c;
      iVar3 = 1;
      if (1 < DAT_02924b48) {
        do {
          iVar6 = iVar3;
          if ((short)DAT_0296200c[iVar3 * 2 + 1] == -1) break;
          if (DAT_0296200c[iVar3 * 2] < iVar4) {
            iVar4 = DAT_0296200c[iVar3 * 2];
            iVar5 = iVar3;
          }
          iVar3 = iVar3 + 1;
          iVar6 = iVar5;
        } while (iVar3 < DAT_02924b48);
      }
    }
    if (-1 < (short)DAT_0296200c[iVar6 * 2 + 1]) {
      *(undefined4 *)
       (*DAT_0292fc68 + 0xc +
       *(short *)(DAT_02947c64 + 0x14 + (short)DAT_0296200c[iVar6 * 2 + 1] * 0x1c) * 0x38) = 0;
      iVar5 = 0;
      do {
        *(undefined2 *)(iVar5 + 0x1bb8 + (int)DAT_0292fc68) = 0;
        iVar5 = iVar5 + 0x80c;
      } while (iVar5 < 0x80c0);
    }
    iVar5 = iVar1 + *(short *)(param_1 + 0x30) * -0x1c;
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar5 + -0xc);
    *(short *)(iVar5 + -6) = (short)iVar6;
    *(short *)(piVar2 + iVar6 * 2 + 1) = -1 - *(short *)(param_1 + 0x30);
    FUN_0066f170(param_1,DAT_0292fc08 * iVar6 + DAT_02924b4c,
                 iVar1 + (*(short *)(param_1 + 0x30) + 1) * -0x1c);
    DAT_0296200c[iVar6 * 2] = DAT_0292fc04;
  }
  return;
}

