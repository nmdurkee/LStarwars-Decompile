/* Ghidra pseudocode, not original source.
 * ev_a84f6211ef148f15ea828e3da9a2e76ee785c1544a3c74f6da418557eb34fa98
 * Entry: 0x638b50; label: FUN_00638b50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00638b50(undefined4 param_1,int param_2)

{
  if (DAT_02913824 != 0) {
    *(undefined1 *)(DAT_02913824 + 0x7b) = *(undefined1 *)(param_2 + 0xc);
    FUN_006382a0();
    return;
  }
  return;
}

