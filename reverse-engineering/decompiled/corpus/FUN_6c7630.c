/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c7630; label: FUN_006c7630
 */

void FUN_006c7630(int param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x50) != 0) {
    *(float *)(param_1 + 4) = *(float *)(param_1 + 4) - 10.0;
  }
  return;
}

