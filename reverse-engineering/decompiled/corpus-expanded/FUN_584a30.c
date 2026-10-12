/* Ghidra pseudocode, not original source.
 * ev_f4a8ff6582840101146b6beddb128c7f08992de8be10658b05520190150ad97a
 * Entry: 0x584a30; label: FUN_00584a30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00584a30(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = FUN_004f7fb0(param_1);
  if (iVar2 != 0) {
    uVar1 = FUN_0055bac0(DAT_00954404,*(undefined4 *)(param_1 + 0x510));
    *(undefined1 *)(DAT_00954404 + 0x11c) = uVar1;
  }
  return;
}

