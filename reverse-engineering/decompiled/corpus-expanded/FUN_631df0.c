/* Ghidra pseudocode, not original source.
 * ev_c80330773f662e8a33570a4ca58388b0b4349f11aa110fb6d722955620f1df5d
 * Entry: 0x631df0; label: FUN_00631df0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00631df0(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)*param_1;
  if (((puVar1 != (undefined4 *)0x0) && (DAT_029131cc != 0)) && (param_1[9] != 0)) {
    if ((param_1[9] & 1U) != 0) {
      iVar2 = FUN_006332f0(DAT_029131cc,*puVar1,puVar1[1],0,0x100);
      param_1[2] = iVar2;
    }
    param_1[9] = 0;
  }
  return;
}

