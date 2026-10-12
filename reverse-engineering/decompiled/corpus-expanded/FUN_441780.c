/* Ghidra pseudocode, not original source.
 * ev_52b1dbacad98807a86fda1d7285f00f4b35f02131457f245004edfced337e57f
 * Entry: 0x441780; label: FUN_00441780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00441780(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 != 0) && (DAT_00923904 != (code *)0x0)) {
    uVar1 = (*DAT_00923904)(param_1,param_2);
    return uVar1;
  }
  return 0;
}

