/* Ghidra pseudocode, not original source.
 * ev_e99a99ac40850efc4319cfa1070f50eca7ba45fd57a73000da90cd7b4a6a9b3b
 * Entry: 0x6454c0; label: FUN_006454c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006454c0(int param_1)

{
  char *pcVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  
  if (DAT_02920a94 < 0x80) {
    iVar5 = 0;
    pcVar1 = &DAT_02913a58;
    do {
      if (*pcVar1 == '\0') {
        iVar4 = iVar5 * 0x178;
        _sprintf(&DAT_02913a58 + iVar4,"New%d",iVar5);
        FUN_006444e0(iVar5);
        DAT_02920a94 = DAT_02920a94 + 1;
        DAT_029208d4 = DAT_02962114;
        iVar2 = 0;
        (&DAT_02913b0b)[iVar4] = 1;
        (&DAT_02913b0a)[iVar4] = 1;
        DAT_02913a30 = 1;
        DAT_029208a0 = 1;
        DAT_0291f68c = 1;
        puVar3 = &DAT_02913ae8 + iVar5 * 0xbc;
        DAT_00810194 = iVar5;
        do {
          *puVar3 = 0xffff;
          (&DAT_02913af8)[iVar2 + iVar4] = 0xff;
          iVar2 = iVar2 + 1;
          puVar3 = puVar3 + 1;
        } while (iVar2 < 8);
        (&DAT_02913bb8)[iVar5 * 0x5e] = 0x3f800000;
        (&DAT_02913bbc)[iVar5 * 0x5e] = 0x3f800000;
        (&DAT_02913bc0)[iVar5 * 0x5e] = 0x3f800000;
        break;
      }
      pcVar1 = pcVar1 + 0x178;
      iVar5 = iVar5 + 1;
    } while ((int)pcVar1 < 0x291f658);
  }
  iVar5 = *(int *)(param_1 + 0x40);
  iVar2 = 0;
  if (iVar5 != 0) {
    FUN_006279f0(param_1);
    iVar2 = iVar5;
  }
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
    (**(code **)(param_1 + 0x30))(param_1,iVar2);
  }
  return;
}

