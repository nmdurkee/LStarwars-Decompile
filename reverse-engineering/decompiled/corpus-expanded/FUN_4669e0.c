/* Ghidra pseudocode, not original source.
 * ev_8b33ce688355ba097f8d2f702831fda396d81ac3370e92e38da24fe76235d9ff
 * Entry: 0x4669e0; label: FUN_004669e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004669e0(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if ((((DAT_007f8cc8 < 0x10) && (param_1 != 0)) && (*(int *)(param_1 + 0x46ac) != 0)) &&
     (*(short *)(*(int *)(param_1 + 0x46ac) + 0xe) != 0)) {
    DAT_00877ad8 = 0;
    DAT_00877adc = param_1;
    iVar2 = FUN_004fc900("ForceSFX",param_2,0xffff);
    if (iVar2 != 0) {
      FUN_004f10e0(iVar2,&PTR_s_forcename_007f8ccc);
      bVar1 = false;
      iVar3 = FUN_004fc5b0(iVar2);
      while (iVar3 != 0) {
        iVar3 = FUN_004f7fb0(iVar2);
        while (iVar3 != 0) {
          if (bVar1) {
            iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"forcesfx_end");
            if (iVar3 == 0) {
              bVar1 = false;
            }
            else {
              FUN_004fa020(iVar2);
            }
          }
          else {
            iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"forcesfx_start");
            if (iVar3 == 0) {
              bVar1 = true;
            }
          }
          iVar3 = FUN_004f7fb0(iVar2);
        }
        iVar3 = FUN_004fc5b0(iVar2);
      }
      FUN_004f11e0(iVar2);
      FUN_004fa300(iVar2);
    }
  }
  return;
}

