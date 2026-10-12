/* Ghidra pseudocode, not original source.
 * ev_573fcacabc8e68ea03635b0f8aa232ed45a87b6cc51fa6af4ed20e3c9ee5dc27
 * Entry: 0x5d1950; label: FUN_005d1950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d1950(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_1 != 0) {
    puVar1 = (undefined4 *)(param_1 + 0x28);
    iVar2 = 0x20;
    do {
      puVar1[0x20] = 0xffffffff;
      *puVar1 = 0xffffffff;
      puVar1 = puVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(ushort *)(param_1 + 0x1b6) = *(ushort *)(param_1 + 0x1b6) & 0xfffe;
    *(undefined2 *)(param_1 + 0x1b4) = 0;
    *(undefined4 *)(param_1 + 0x128) = 0;
    *(undefined4 *)(param_1 + 300) = 0;
    *(undefined1 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x1b0) = 0;
    *(undefined2 *)(param_1 + 0x1b8) = 1;
  }
  return;
}

