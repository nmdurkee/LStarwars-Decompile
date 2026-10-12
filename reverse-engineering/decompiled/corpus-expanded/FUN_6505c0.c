/* Ghidra pseudocode, not original source.
 * ev_f26efce709548f397f112d14bef56d8f0f3486015c16e671b302622d1d4cb319
 * Entry: 0x6505c0; label: FUN_006505c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006505c0(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (-1 < param_1) {
    iVar1 = *(int *)(param_1 * 0x40 + 4 + DAT_02947b74) << 0x11;
    uVar2 = iVar1 >> 0x11;
    if ((uVar2 < 0x640) && (iVar1 = (int)(uVar2 + (iVar1 >> 0x1f & 0xfU)) >> 4, iVar1 < 100)) {
      (&DAT_02921760)[iVar1] = (&DAT_02921760)[iVar1] & -(short)(1 << ((byte)uVar2 & 0xf)) - 1U;
    }
  }
  return;
}

