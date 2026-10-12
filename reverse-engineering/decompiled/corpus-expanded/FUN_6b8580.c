/* Ghidra pseudocode, not original source.
 * ev_6e4df963812b3a1824100f136853f234100848169b29b7b6e42d47a7916e68c6
 * Entry: 0x6b8580; label: FUN_006b8580
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b8580(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*DAT_02854d10;
  *puVar1 = param_1;
  puVar1[1] = param_2;
  *(undefined4 *)(*DAT_02854d10 + 8) = param_3;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  return;
}

