/* Ghidra pseudocode, not original source.
 * ev_8c08cb58b3e2eca2ce3b645626710873c7692325f2a23ef4bde2c2500b41a2fb
 * Entry: 0x443020; label: FUN_00443020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00443020(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if ((((param_2 != 0) && (param_1 != 0)) && (DAT_00923904 != (code *)0x0)) &&
     (puVar1 = (undefined4 *)(*DAT_00923904)(param_1,param_2), puVar1 != (undefined4 *)0x0)) {
    return *puVar1;
  }
  return 0;
}

