/* Ghidra pseudocode, not original source.
 * ev_8c08cb58b3e2eca2ce3b645626710873c7692325f2a23ef4bde2c2500b41a2fb
 * Entry: 0x4431d0; label: FUN_004431d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004431d0(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if ((((param_2 != 0) && (param_1 != 0)) && (DAT_00923904 != (code *)0x0)) &&
     (puVar1 = (undefined4 *)(*DAT_00923904)(param_1,param_2), puVar1 != (undefined4 *)0x0)) {
    return *puVar1;
  }
  return 0;
}

