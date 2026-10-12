/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x528af0; label: FUN_00528af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00528af0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((((DAT_00921f50 & 0x400) != 0) && (*(int *)(DAT_009238e4 + 0x371b0) != 0)) &&
     (*(char *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x5a) != *(char *)(param_1 + 0x5a))) {
    uVar1 = 0;
  }
  return uVar1;
}

