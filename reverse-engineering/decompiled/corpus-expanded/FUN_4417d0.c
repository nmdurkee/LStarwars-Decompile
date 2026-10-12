/* Ghidra pseudocode, not original source.
 * ev_52b1dbacad98807a86fda1d7285f00f4b35f02131457f245004edfced337e57f
 * Entry: 0x4417d0; label: FUN_004417d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004417d0(undefined4 param_1,int param_2)

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

