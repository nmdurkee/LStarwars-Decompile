/* Ghidra pseudocode, not original source.
 * ev_f4a8ff6582840101146b6beddb128c7f08992de8be10658b05520190150ad97a
 * Entry: 0x586690; label: FUN_00586690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00586690(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)(DAT_00954404 + 0x113);
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f29a0(*(undefined4 *)(param_1 + 0x510));
    if (iVar1 + 1U < 0x11) {
      *puVar2 = (char)iVar1;
    }
  }
  return;
}

