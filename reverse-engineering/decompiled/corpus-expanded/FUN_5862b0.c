/* Ghidra pseudocode, not original source.
 * ev_f4a8ff6582840101146b6beddb128c7f08992de8be10658b05520190150ad97a
 * Entry: 0x5862b0; label: FUN_005862b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005862b0(undefined1 *param_1)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = FUN_004f7fb0();
  if (iVar1 != 0) {
    iVar1 = FUN_004f29a0(*(undefined4 *)(unaff_ESI + 0x510));
    if (iVar1 + 1U < 0x11) {
      *param_1 = (char)iVar1;
    }
  }
  return;
}

