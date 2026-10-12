/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e27f0; label: FUN_006e27f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_006e27f0(void)

{
  int in_ECX;
  
  return (*(byte *)(in_ECX + 0x654) & 0x20) != 0;
}

