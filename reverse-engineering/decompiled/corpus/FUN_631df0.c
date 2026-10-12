/* Ghidra analysis pseudocode, not original source.
 * ev_e26d15e716f54b37dc9752c5bbece96131eaa1b0064d3ed9476ea38cc0029dc6
 * Entry: 0x631df0; label: FUN_00631df0
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

