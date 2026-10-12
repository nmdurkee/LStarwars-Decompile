/* Ghidra pseudocode, not original source.
 * ev_fbd0714d29abf1967b7a59c1140afabe8eda1c53d580ba604e59c833adf58051
 * Entry: 0x618de0; label: FUN_00618de0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00618de0(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_02900c70;
  do {
    FUN_006017a0(*puVar1,param_1);
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x2900c80);
  return;
}

