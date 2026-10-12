/* Ghidra pseudocode, not original source.
 * ev_d27b225b9633e56be6d9d5c2be7adfa4268b9e50bf259b668c645e1f15e7124d
 * Entry: 0x746710; label: FUN_00746710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00746710(int param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x980) = param_2;
  *(int *)(in_ECX + 0x974) = param_1;
  *(undefined4 *)(in_ECX + 0x984) = param_3;
  if (*(int *)(in_ECX + 0x978) == 0) {
    if (((param_1 != 2) && (param_1 != 3)) && (param_1 != 4)) {
      *(undefined1 **)(in_ECX + 0x988) = &DAT_007516c0;
      return;
    }
    *(char **)(in_ECX + 0x988) = "_centroid";
  }
  return;
}

