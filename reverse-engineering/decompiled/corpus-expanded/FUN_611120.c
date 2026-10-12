/* Ghidra pseudocode, not original source.
 * ev_4979805bbb21a8904736e4a261aef1b5206e58d1861917e5f468ac2db6a4df52
 * Entry: 0x611120; label: FUN_00611120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00611120(byte param_1)

{
  int in_ECX;
  
  FUN_006334d0(*(undefined4 *)(in_ECX + 0xc),3000);
  if ((param_1 & 1) != 0) {
    FUN_006334d0(in_ECX,0x24);
  }
  return;
}

