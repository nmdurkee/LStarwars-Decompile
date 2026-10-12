/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e22e0; label: FUN_006e22e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e22e0(int param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x6c4);
  if ((*(int *)(in_ECX + 0x638) != 0) || (iVar1 == 0)) {
    iVar1 = *(int *)(in_ECX + 0x6b0);
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x88))
            (*(int **)(in_ECX + 4),iVar1,0,*(undefined4 *)(param_1 + 8),0,param_2);
  return;
}

