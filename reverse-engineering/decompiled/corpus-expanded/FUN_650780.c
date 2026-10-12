/* Ghidra pseudocode, not original source.
 * ev_f26efce709548f397f112d14bef56d8f0f3486015c16e671b302622d1d4cb319
 * Entry: 0x650780; label: FUN_00650780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00650780(int param_1,int param_2)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  
  if (-1 < param_2) {
    iVar2 = *(int *)(param_2 * 0x40 + 4 + DAT_02947b74) << 0x11;
    uVar3 = iVar2 >> 0x11;
    if ((uVar3 < 0x640) && (iVar2 = (int)(uVar3 + (iVar2 >> 0x1f & 0xfU)) >> 4, iVar2 < 100)) {
      puVar1 = (ushort *)(param_1 + iVar2 * 2);
      *puVar1 = *puVar1 & -(short)(1 << ((byte)uVar3 & 0xf)) - 1U;
    }
  }
  return;
}

