/* Ghidra analysis pseudocode, not original source.
 * ev_6696c20a63c48b02c48d5a5db7e1958972e2427aa057f5485eee4f348cd6e250
 * Entry: 0x5c22b0; label: FUN_005c22b0
 */

void FUN_005c22b0(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x10))();
                    /* WARNING: Could not recover jumptable at 0x005c22c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 8))();
  return;
}

