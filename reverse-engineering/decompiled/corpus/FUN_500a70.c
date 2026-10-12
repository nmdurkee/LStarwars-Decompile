/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x500a70; label: FUN_00500a70
 */

void FUN_00500a70(void)

{
  int in_ECX;
  
  *(float *)(in_ECX + 0x90) = *(float *)(*(int *)(in_ECX + 0x58) + 8) - 1.0;
  FUN_004fff10(*(undefined4 *)(*(int *)(in_ECX + 0x58) + 0x2c));
  return;
}

