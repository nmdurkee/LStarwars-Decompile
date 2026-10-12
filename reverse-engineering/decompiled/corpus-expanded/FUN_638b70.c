/* Ghidra pseudocode, not original source.
 * ev_a84f6211ef148f15ea828e3da9a2e76ee785c1544a3c74f6da418557eb34fa98
 * Entry: 0x638b70; label: FUN_00638b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00638b70(undefined4 param_1,int param_2)

{
  *(undefined4 *)(PTR_DAT_0080fe0c + *(int *)(param_2 + 0xc) * 4) = *(undefined4 *)(param_2 + 0x54);
  return;
}

