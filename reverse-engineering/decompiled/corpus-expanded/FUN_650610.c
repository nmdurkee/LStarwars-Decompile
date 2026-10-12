/* Ghidra pseudocode, not original source.
 * ev_f26efce709548f397f112d14bef56d8f0f3486015c16e671b302622d1d4cb319
 * Entry: 0x650610; label: FUN_00650610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00650610(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 < 0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 * 0x40 + 4 + DAT_02947b74) << 0x11;
  uVar2 = iVar1 >> 0x11;
  if ((uVar2 < 0x640) && (iVar1 = (int)((iVar1 >> 0x1f & 0xfU) + uVar2) >> 4, iVar1 < 100)) {
    return (uint)((1 << ((byte)uVar2 & 0xf) & (&DAT_02921760)[iVar1]) != 0);
  }
  return 0xffffffff;
}

