/* Ghidra pseudocode, not original source.
 * ev_feeb0d300fc0a1ec823458f778250bd56b5f3fc24779efc17b7484c96bfb9aef
 * Entry: 0x5d32c0; label: FUN_005d32c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d32c0(uint param_1)

{
  DAT_0096d8f4 = (DAT_0095fbbc ^ param_1) & param_1;
  DAT_0096e534 = ~param_1 & (DAT_0095fbbc ^ param_1);
  DAT_0095fbbc = param_1;
  return;
}

