/* Ghidra pseudocode, not original source.
 * ev_a84f6211ef148f15ea828e3da9a2e76ee785c1544a3c74f6da418557eb34fa98
 * Entry: 0x6390e0; label: FUN_006390e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006390e0(undefined4 param_1,int param_2)

{
  undefined1 local_4;
  
  if (DAT_02913814 != 0) {
    local_4 = (undefined1)(int)ROUND(*(float *)(param_2 + 0x54) * 10.0);
    *(undefined1 *)(DAT_02913814 + 0x18) = local_4;
  }
  return;
}

