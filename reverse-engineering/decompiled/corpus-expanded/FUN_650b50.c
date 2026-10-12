/* Ghidra pseudocode, not original source.
 * ev_73d54611eb9c539f60191f4cc2589103d1525e4e98579cab30a489e0835b3840
 * Entry: 0x650b50; label: FUN_00650b50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00650b50(int param_1)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 != -1) {
    iVar5 = (int)(short)(&DAT_02920d88)[param_1 * 4];
    sVar2 = *(short *)(&DAT_02920d8a + param_1 * 8);
    iVar6 = (int)sVar2;
    FUN_004ef660(&DAT_02921260 + iVar5 * 2,&DAT_02921260 + (iVar6 + iVar5) * 2,
                 ((DAT_02962020 - iVar6) - iVar5) * 2);
    DAT_02962020 = DAT_02962020 - iVar6;
    iVar6 = 0;
    if (0 < DAT_02962024) {
      do {
        if (iVar5 < (short)(&DAT_02920d88)[iVar6 * 4]) {
          (&DAT_02920d88)[iVar6 * 4] = (&DAT_02920d88)[iVar6 * 4] - sVar2;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < DAT_02962024);
    }
    FUN_004ef660(&DAT_02920d88 + param_1 * 4,&DAT_02920d90 + param_1 * 4,DAT_02962024 * 8 + -8);
    DAT_02962024 = DAT_02962024 + -1;
    if (DAT_0296202c < DAT_0296201c) {
      iVar5 = DAT_0296202c << 6;
      iVar3 = DAT_0296201c - DAT_0296202c;
      iVar6 = DAT_02947b74;
      do {
        iVar4 = (int)*(short *)(iVar5 + 0x14 + iVar6);
        if (param_1 < iVar4) {
          psVar1 = (short *)(iVar5 + 0x14 + iVar6);
          *psVar1 = *psVar1 + -1;
          iVar6 = DAT_02947b74;
        }
        else if (iVar4 == param_1) {
          *(undefined2 *)(iVar5 + 0x14 + iVar6) = 0xffff;
          iVar6 = DAT_02947b74;
        }
        iVar5 = iVar5 + 0x40;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  return;
}

