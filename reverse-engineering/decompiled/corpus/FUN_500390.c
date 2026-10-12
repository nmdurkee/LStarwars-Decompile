/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x500390; label: FUN_00500390
 */

void FUN_00500390(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x88) =
       *(uint *)(param_1 + 0x88) ^ (param_2 * 4 ^ *(uint *)(param_1 + 0x88)) & 4;
  return;
}

