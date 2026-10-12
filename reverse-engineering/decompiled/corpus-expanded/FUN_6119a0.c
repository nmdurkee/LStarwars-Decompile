/* Ghidra pseudocode, not original source.
 * ev_4979805bbb21a8904736e4a261aef1b5206e58d1861917e5f468ac2db6a4df52
 * Entry: 0x6119a0; label: FUN_006119a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_006119a0(uint param_1)

{
  int in_ECX;
  
  return (*(uint *)(in_ECX + 0x1c) & param_1) != 0;
}

