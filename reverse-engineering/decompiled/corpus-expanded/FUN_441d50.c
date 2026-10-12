/* Ghidra pseudocode, not original source.
 * ev_dff4057492b6a6aa6b557fdc6c810dc815e99554675c623c5eaef56b669992ab
 * Entry: 0x441d50; label: FUN_00441d50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00441d50(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  
  if ((param_2 != 0) && (DAT_00923904 != (code *)0x0)) {
    puVar1 = (undefined4 *)(*DAT_00923904)(param_1,param_2);
    if (puVar1 != (undefined4 *)0x0) {
      return *puVar1;
    }
  }
  return 0;
}

