/* Ghidra pseudocode, not original source.
 * ev_3cc3478cfa8c26bd4fafca5bd3c3e065fb7e5c3537b7c6265584e6b0ffbf613e
 * Entry: 0x638240; label: FUN_00638240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00638240(undefined4 param_1,int param_2)

{
  if (DAT_02913824 != 0) {
    FUN_006378f0();
    FUN_00637e50(DAT_02913824);
    DAT_029139bc = 0;
  }
  DAT_029139a4 = 0;
  *(byte *)(param_2 + 0x11) = *(byte *)(param_2 + 0x11) & 0xfe;
  return;
}

