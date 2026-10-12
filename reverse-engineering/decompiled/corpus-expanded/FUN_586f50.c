/* Ghidra pseudocode, not original source.
 * ev_160b6ff83e8d01b08d86e74350d491f9e4ae154e83c7564abce91853a1b29784
 * Entry: 0x586f50; label: FUN_00586f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00586f50(void)

{
  uint in_EAX;
  int iVar1;
  int unaff_EDI;
  
  *(uint *)(DAT_00954404 + 0x90) = *(uint *)(DAT_00954404 + 0x90) | in_EAX;
  iVar1 = FUN_004f7fb0();
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(uint *)(DAT_00954404 + 0x90) = *(uint *)(DAT_00954404 + 0x90) & ~in_EAX;
    }
  }
  return;
}

