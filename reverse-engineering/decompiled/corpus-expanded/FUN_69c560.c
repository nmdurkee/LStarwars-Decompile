/* Ghidra pseudocode, not original source.
 * ev_c022dfa5fb113afde7d6c0963a448fd7ba6a7635c8c31d639ad2eb654bc3de65
 * Entry: 0x69c560; label: FUN_0069c560
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069c560(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x48) == 0) {
    return 0xffffff7d;
  }
  uVar1 = FUN_006a14a0();
  return uVar1;
}

