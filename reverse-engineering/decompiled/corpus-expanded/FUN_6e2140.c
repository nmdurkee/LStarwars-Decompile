/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e2140; label: FUN_006e2140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined2 FUN_006e2140(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x638) == 0) && (1 < DAT_02974d1c)) {
    return *(undefined2 *)(in_ECX + 0xf8);
  }
  return 1;
}

