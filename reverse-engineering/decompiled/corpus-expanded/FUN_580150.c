/* Ghidra pseudocode, not original source.
 * ev_148a09dc694c3f4e6090ec8593a8f5c40e6398f75b0d17d245a3886ccb65c6ec
 * Entry: 0x580150; label: FUN_00580150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00580150(int param_1)

{
  undefined4 *in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (in_EAX != (undefined4 *)0x0) {
    iVar3 = 0;
    iVar2 = param_1 + 0x4b14;
    while (iVar1 = FUN_004f1ff0(iVar2), iVar1 != 0) {
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xa4;
      if (7 < iVar3) {
        return;
      }
    }
    puVar4 = (undefined4 *)(iVar3 * 0xa4 + 0x4b14 + param_1);
    for (iVar2 = 0x29; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *in_EAX;
      in_EAX = in_EAX + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}

