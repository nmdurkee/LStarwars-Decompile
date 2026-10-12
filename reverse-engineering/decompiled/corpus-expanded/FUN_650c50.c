/* Ghidra pseudocode, not original source.
 * ev_73d54611eb9c539f60191f4cc2589103d1525e4e98579cab30a489e0835b3840
 * Entry: 0x650c50; label: FUN_00650c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00650c50(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_02962024;
  if ((DAT_02962024 != 0x80) && (DAT_02962020 != 0x200)) {
    (&DAT_02920d88)[DAT_02962024 * 4] = (short)DAT_02962020;
    *(undefined2 *)(&DAT_02920d8a + iVar2 * 8) = 1;
    iVar1 = DAT_02947b74;
    *(undefined2 *)(&DAT_02920d8c + iVar2 * 8) = 0;
    *(short *)(param_1 * 0x40 + 0x14 + iVar1) = (short)iVar2;
    *(short *)(&DAT_02921260 + DAT_02962020 * 2) = (short)param_1;
    DAT_02962020 = DAT_02962020 + 1;
    iVar2 = DAT_02962024;
    DAT_02962024 = DAT_02962024 + 1;
    return iVar2;
  }
  return -1;
}

