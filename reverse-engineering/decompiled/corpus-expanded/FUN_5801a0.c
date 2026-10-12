/* Ghidra pseudocode, not original source.
 * ev_148a09dc694c3f4e6090ec8593a8f5c40e6398f75b0d17d245a3886ccb65c6ec
 * Entry: 0x5801a0; label: FUN_005801a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005801a0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f1ff0(*(undefined4 *)(param_1 + 0x510));
    if (iVar1 < 0xf) {
      FUN_004f1f10(DAT_00951cc0,*(undefined4 *)(param_1 + 0x510));
    }
  }
  return;
}

