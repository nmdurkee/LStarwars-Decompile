/* Ghidra pseudocode, not original source.
 * ev_d8823ef952be36302cd5edf235953b54dcac69dadf5f46e66206c8601523987b
 * Entry: 0x5c2000; label: FUN_005c2000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c2000(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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

