/* Ghidra pseudocode, not original source.
 * ev_f9aef5a40e02ce8ca7a9836408264f920f991102075b72e653cbe4eaab14c8b7
 * Entry: 0x5849c0; label: FUN_005849c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005849c0(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = FUN_004f7fb0(param_1);
  if (iVar2 != 0) {
    uVar1 = FUN_004f29a0(*(undefined4 *)(param_1 + 0x510));
    *(undefined1 *)(DAT_00954404 + 0x11c) = uVar1;
  }
  return;
}

