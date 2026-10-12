/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4edbb0; label: FUN_004edbb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004edbb0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = **(int **)(param_1 + 0x50b8);
  DAT_0088a6cc = 0;
  DAT_0088a56f = 0;
  DAT_0088a56e = 0;
  DAT_0088a6cd = 0;
  for (iVar2 = 0; (iVar1 != 0 && (iVar2 < *(int *)(*(int *)(param_1 + 0x50b8) + 8)));
      iVar2 = iVar2 + 1) {
    if (((*(byte *)(iVar1 + 0x17) & 8) == 0) && ((byte)(*(char *)(iVar1 + 0x18) - 3U) < 4)) {
      *(undefined1 *)(iVar1 + 0x24) = 0;
    }
    iVar1 = iVar1 + 0x2c;
  }
  return;
}

