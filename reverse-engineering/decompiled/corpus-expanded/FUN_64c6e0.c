/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64c6e0; label: FUN_0064c6e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0064c6e0(char param_1)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  (*(code *)PTR_FUN_00800820)();
  iVar3 = (int)param_1;
  if (*(int *)(&DAT_02913a2c + iVar3 * 4) != 0) {
    *(undefined4 *)(&DAT_02913a2c + iVar3 * 4) = 0;
  }
  pcVar1 = &DAT_02913a58;
  do {
    if ((pcVar1[0xb2] == param_1) && (*pcVar1 != '\0')) {
      *pcVar1 = '\0';
      pcVar1[0x90] = -1;
      pcVar1[0x91] = -1;
      DAT_02920a94 = DAT_02920a94 + -1;
    }
    pcVar1 = pcVar1 + 0x178;
  } while ((int)pcVar1 < 0x291f658);
  piVar2 = &DAT_0291f7b4;
  do {
    if ((*(char *)((int)piVar2 + 0x26) == param_1) && (*piVar2 != -1)) {
      *piVar2 = -1;
      DAT_02920a98 = DAT_02920a98 + -1;
    }
    piVar2 = piVar2 + 0x1b;
  } while ((int)piVar2 < 0x2920894);
  iVar4 = 0;
  do {
    if (*(int *)((int)&DAT_0291f688 + iVar4) == iVar3) {
      FUN_0064b7f0(*(undefined4 *)((int)&DAT_029208d0 + iVar4));
      *(undefined4 *)((int)&DAT_029208d0 + iVar4) = 0;
      *(undefined4 *)((int)&DAT_0291f688 + iVar4) = 0xffffffff;
    }
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x80);
  (*(code *)PTR_FUN_00800824)();
  *(undefined4 *)(&DAT_0292089c + iVar3 * 4) = 0;
  return;
}

