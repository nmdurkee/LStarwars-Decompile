/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e2320; label: FUN_006e2320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e2320(int param_1,undefined4 param_2)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x88))
            (*(int **)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x6e8),0,*(undefined4 *)(param_1 + 8),0,
             param_2);
  return;
}

