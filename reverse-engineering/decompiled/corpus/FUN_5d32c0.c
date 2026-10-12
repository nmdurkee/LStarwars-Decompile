/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d32c0; label: FUN_005d32c0
 */

void FUN_005d32c0(uint param_1)

{
  DAT_0096d8f4 = (DAT_0095fbbc ^ param_1) & param_1;
  DAT_0096e534 = ~param_1 & (DAT_0095fbbc ^ param_1);
  DAT_0095fbbc = param_1;
  return;
}

