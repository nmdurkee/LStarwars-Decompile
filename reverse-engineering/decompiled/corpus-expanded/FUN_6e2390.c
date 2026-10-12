/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e2390; label: FUN_006e2390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e2390(char param_1)

{
  int in_ECX;
  
  FUN_006e56c0(*(undefined4 *)(in_ECX + 0x684));
  FUN_006e5590(0,*(undefined4 *)(in_ECX + 0x688),0,0x10);
  if (param_1 != '\0') {
    FUN_006e5290(0);
  }
  FUN_006e4980(4,0,1);
  return;
}

