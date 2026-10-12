/* Ghidra analysis pseudocode, not original source.
 * ev_11d21a68175a6094cc049e5bf26b7ff6a5a52d03a1d985acdd25f24f4e0bcb10
 * Entry: 0x613180; label: FUN_00613180
 */

void FUN_00613180(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_004ef660(param_1,*(int *)(in_ECX + 8) + *(int *)(in_ECX + 4),1);
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 1;
  }
  return;
}

