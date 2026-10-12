/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5c9ab0; label: FUN_005c9ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005c9ab0(int param_1)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = *(ushort *)(param_1 + 0x14);
  iVar2 = param_1;
  while (uVar1 != 0) {
    iVar2 = iVar2 + (uint)uVar1;
    uVar1 = *(ushort *)(iVar2 + 0x14);
  }
  if (*(int *)(iVar2 + 0x34) != 0) {
    return ((uint)*(ushort *)(iVar2 + 4) - param_1) + *(int *)(iVar2 + 0x34);
  }
  return 0;
}

