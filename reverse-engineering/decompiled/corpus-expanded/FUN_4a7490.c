/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a7490; label: FUN_004a7490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004a7490(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *(char *)(param_1 + 0x285);
  if (((cVar1 < '\0') || ('\x1f' < cVar1)) ||
     ((*(uint *)(&DAT_008034cc + cVar1 * 0xc) & 0x400) == 0)) {
    return 0;
  }
  if (((cVar1 == '\x05') && (DAT_00950c4c != (code *)0x0)) &&
     (iVar2 = (*DAT_00950c4c)(param_1), iVar2 != 0)) {
    return 0;
  }
  return 1;
}

