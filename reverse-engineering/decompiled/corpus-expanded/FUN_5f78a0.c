/* Ghidra pseudocode, not original source.
 * ev_051ca52d2d0f5927e6fa186b1b96c133d3b61d010079a76ac2917bb13fe5eb00
 * Entry: 0x5f78a0; label: FUN_005f78a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005f78a0(void)

{
  int in_ECX;
  
  if (((*(uint *)(in_ECX + 0x44) & 2) == 0) && ((*(uint *)(in_ECX + 0x44) & 0x100) == 0)) {
    return 1;
  }
  return 0;
}

