/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e2260; label: FUN_006e2260
 */

void FUN_006e2260(int param_1)

{
  int in_ECX;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 8) != 0)) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x9c))(*(int **)(in_ECX + 4),*(int *)(param_1 + 8));
    return;
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x9c))
            (*(int **)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x6ec));
  return;
}

