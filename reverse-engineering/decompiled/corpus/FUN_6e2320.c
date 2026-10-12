/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e2320; label: FUN_006e2320
 */

void FUN_006e2320(int param_1,undefined4 param_2)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x88))
            (*(int **)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x6e8),0,*(undefined4 *)(param_1 + 8),0,
             param_2);
  return;
}

