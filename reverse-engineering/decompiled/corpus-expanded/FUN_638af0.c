/* Ghidra pseudocode, not original source.
 * ev_a84f6211ef148f15ea828e3da9a2e76ee785c1544a3c74f6da418557eb34fa98
 * Entry: 0x638af0; label: FUN_00638af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00638af0(undefined4 param_1,int param_2)

{
  if (DAT_02913824 != 0) {
    *(undefined4 *)(DAT_02913824 + 0x6c) = *(undefined4 *)(param_2 + 0x54);
  }
  return;
}

