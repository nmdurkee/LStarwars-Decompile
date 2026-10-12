/* Ghidra pseudocode, not original source.
 * ev_97f4a3b699bb455f9f6d61621fe82dddba0f62005898969e9454d063fd653c3d
 * Entry: 0x5869e0; label: FUN_005869e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005869e0(undefined1 *param_1)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = FUN_004f7fb0();
  if (iVar1 != 0) {
    iVar1 = FUN_004f29a0(*(undefined4 *)(unaff_ESI + 0x510));
    if (-1 < iVar1) {
      *param_1 = (char)iVar1;
    }
  }
  return;
}

