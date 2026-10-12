/* Ghidra pseudocode, not original source.
 * ev_a84f6211ef148f15ea828e3da9a2e76ee785c1544a3c74f6da418557eb34fa98
 * Entry: 0x638b10; label: FUN_00638b10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00638b10(undefined4 param_1,int param_2)

{
  undefined1 local_4;
  
  if (DAT_02913824 != 0) {
    local_4 = (undefined1)(int)ROUND(*(float *)(param_2 + 0x54));
    *(undefined1 *)(DAT_02913824 + 0x78) = local_4;
  }
  return;
}

