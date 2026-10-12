/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e1dd0; label: FUN_006e1dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e1dd0(uint param_1)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x618) <= param_1) {
    param_1 = *(uint *)(in_ECX + 0x620);
  }
  *(uint *)(in_ECX + 0x660) = param_1;
  return;
}

