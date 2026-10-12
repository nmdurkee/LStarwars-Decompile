/* Ghidra analysis pseudocode, not original source.
 * ev_7afb5199773593ea980580d1c3e319946e9fb0192a7e36f1658c723ed800643d
 * Entry: 0x746710; label: FUN_00746710
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

