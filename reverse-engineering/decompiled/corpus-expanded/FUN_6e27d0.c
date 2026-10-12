/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e27d0; label: FUN_006e27d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006e27d0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = 0;
  if ((*(byte *)(in_ECX + 0x654) & 0x20) != 0) {
    uVar1 = 0x10;
  }
  return uVar1;
}

