/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e2260; label: FUN_006e2260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

