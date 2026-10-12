/* Ghidra pseudocode, not original source.
 * ev_4979805bbb21a8904736e4a261aef1b5206e58d1861917e5f468ac2db6a4df52
 * Entry: 0x611a30; label: FUN_00611a30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00611a30(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 4) != 4) && (*(int *)(in_ECX + 4) != 3)) {
    return 0;
  }
  return 1;
}

