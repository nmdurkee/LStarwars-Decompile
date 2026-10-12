/* Ghidra pseudocode, not original source.
 * ev_fbd0714d29abf1967b7a59c1140afabe8eda1c53d580ba604e59c833adf58051
 * Entry: 0x619300; label: FUN_00619300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00619300(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  do {
    for (puVar1 = (undefined4 *)*param_1; puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      puVar1[10] = *param_2;
      puVar1[0xb] = param_2[1];
      puVar1[0xc] = param_2[2];
      puVar1[0xd] = param_2[3];
    }
    param_1 = (undefined4 *)param_1[0xf];
  } while (param_1 != (undefined4 *)0x0);
  return;
}

