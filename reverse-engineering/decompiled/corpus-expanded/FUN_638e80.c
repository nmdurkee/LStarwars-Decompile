/* Ghidra pseudocode, not original source.
 * ev_a84f6211ef148f15ea828e3da9a2e76ee785c1544a3c74f6da418557eb34fa98
 * Entry: 0x638e80; label: FUN_00638e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00638e80(undefined4 param_1,int param_2)

{
  undefined4 local_8;
  
  if (DAT_02913814 != 0) {
    *(undefined1 *)(DAT_02913814 + 0x13) = 0;
    local_8 = (int)(longlong)ROUND(*(float *)(param_2 + 0x54));
    *(uint *)(DAT_02913814 + 0x10) = *(uint *)(DAT_02913814 + 0x10) | local_8 << 0x18;
  }
  return;
}

