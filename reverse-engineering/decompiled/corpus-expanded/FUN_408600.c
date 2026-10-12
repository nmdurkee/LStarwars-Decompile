/* Ghidra pseudocode, not original source.
 * ev_c99ba83a21253fbea00a1b2af974464e548d813850fcca855330552d9e62c3cd
 * Entry: 0x408600; label: FUN_00408600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00408600(undefined4 param_1,int param_2)

{
  if (((*(char *)(param_2 + 0x206) != '\x01') || (2.0 <= *(float *)(param_2 + 0xfc))) &&
     ((*(char *)(param_2 + 0x206) != '\x02' || (1.0 <= *(float *)(param_2 + 0xfc))))) {
    return 0;
  }
  return 1;
}

