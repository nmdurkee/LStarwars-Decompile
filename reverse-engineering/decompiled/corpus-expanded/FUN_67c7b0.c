/* Ghidra pseudocode, not original source.
 * ev_32eeff13403f2b0416c64559eab438b182c65995ce85fb3a27dd5c4451fc4fee
 * Entry: 0x67c7b0; label: FUN_0067c7b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0067c7b0(int param_1,uint param_2)

{
  uint *puVar1;
  
  if ((-1 < param_1) && (param_1 < *(int *)(DAT_0292fc68 + 0xa48c))) {
    puVar1 = (uint *)(*(int *)(DAT_0292fc68 + 0x68) + 0x4c + param_1 * 0x6c);
    *puVar1 = *puVar1 ^ (*(uint *)(*(int *)(DAT_0292fc68 + 0x68) + 0x4c + param_1 * 0x6c) ^ param_2)
                        & 1;
  }
  return;
}

