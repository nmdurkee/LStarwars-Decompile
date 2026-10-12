/* Ghidra pseudocode, not original source.
 * ev_160b6ff83e8d01b08d86e74350d491f9e4ae154e83c7564abce91853a1b29784
 * Entry: 0x587300; label: FUN_00587300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00587300(int param_1)

{
  int iVar1;
  
  *(uint *)(DAT_00954404 + 0x90) = *(uint *)(DAT_00954404 + 0x90) | 0x40;
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(uint *)(DAT_00954404 + 0x90) = *(uint *)(DAT_00954404 + 0x90) & 0xffffffbf;
    }
  }
  return;
}

