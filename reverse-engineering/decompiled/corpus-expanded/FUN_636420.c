/* Ghidra pseudocode, not original source.
 * ev_3cc3478cfa8c26bd4fafca5bd3c3e065fb7e5c3537b7c6265584e6b0ffbf613e
 * Entry: 0x636420; label: FUN_00636420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00636420(int param_1)

{
  undefined4 *puVar1;
  
  if (0.0 < *(float *)(param_1 + 0x140)) {
    puVar1 = (undefined4 *)(param_1 + 0x134);
    if (puVar1 != (undefined4 *)0x0) {
      _DAT_0097173c = *puVar1;
      _DAT_00971740 = *(undefined4 *)(param_1 + 0x138);
      _DAT_00971744 = *(undefined4 *)(param_1 + 0x13c);
      _DAT_00971748 = 0;
      _DAT_0097175c = 0;
      FUN_005ff840(puVar1,0);
      return;
    }
    _DAT_00971748 = 1;
    _DAT_0097175c = 0;
    FUN_005ff840(0,0);
  }
  return;
}

