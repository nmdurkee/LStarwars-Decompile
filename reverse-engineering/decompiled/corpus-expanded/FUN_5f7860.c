/* Ghidra pseudocode, not original source.
 * ev_051ca52d2d0f5927e6fa186b1b96c133d3b61d010079a76ac2917bb13fe5eb00
 * Entry: 0x5f7860; label: FUN_005f7860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005f7860(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x640 + *(int *)(in_ECX + 0x638) * 4);
}

