/* Ghidra pseudocode, not original source.
 * ev_4979805bbb21a8904736e4a261aef1b5206e58d1861917e5f468ac2db6a4df52
 * Entry: 0x611a70; label: FUN_00611a70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00611a70(void)

{
  undefined4 *in_ECX;
  
  FUN_006c0780();
  in_ECX[2] = 1;
  *in_ECX = &PTR_FUN_0076abe8;
  in_ECX[8] = 0;
  return;
}

