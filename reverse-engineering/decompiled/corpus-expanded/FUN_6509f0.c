/* Ghidra pseudocode, not original source.
 * ev_f26efce709548f397f112d14bef56d8f0f3486015c16e671b302622d1d4cb319
 * Entry: 0x6509f0; label: FUN_006509f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006509f0(int param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = DAT_02962020;
  sVar2 = *(short *)(&DAT_02920d8a + param_1 * 8);
  iVar4 = (int)(short)(&DAT_02920d88)[param_1 * 4];
  iVar1 = iVar4 + sVar2;
  if (iVar1 != DAT_02962020) {
    (&DAT_02920d88)[param_1 * 4] = (short)DAT_02962020;
    FUN_004ef660(&DAT_02921260 + iVar3 * 2,&DAT_02921260 + iVar4 * 2,sVar2 * 2);
    FUN_004ef660(&DAT_02921260 + iVar4 * 2,&DAT_02921260 + iVar1 * 2,(DAT_02962020 - iVar4) * 2);
    iVar1 = DAT_02962024;
    iVar3 = 0;
    if (0 < DAT_02962024) {
      do {
        if (iVar4 < (short)(&DAT_02920d88)[iVar3 * 4]) {
          (&DAT_02920d88)[iVar3 * 4] = (&DAT_02920d88)[iVar3 * 4] - sVar2;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
    }
  }
  return;
}

