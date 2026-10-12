/* Ghidra pseudocode, not original source.
 * ev_8d7f18048ef2880fb529f575b466097bafe0da5dbea7c232731940988e33188f
 * Entry: 0x59a140; label: FUN_0059a140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059a140(int param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  
  if ((param_1 != 0) && (iVar4 = 0, 0 < DAT_00951360)) {
    iVar3 = 0;
    puVar2 = (undefined1 *)(param_1 + 4);
    do {
      bVar1 = *(byte *)(iVar3 + 0x7a + DAT_00951354);
      *puVar2 = 1;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x9c;
      puVar2[1] = -((bVar1 & 0x10) != 0) & 10;
      puVar2 = puVar2 + 0xc;
    } while (iVar4 < DAT_00951360);
  }
  return;
}

