/* Ghidra analysis pseudocode, not original source.
 * ev_0d221f2c9357ed308f9b597510bd130964f67481868d3ff45e1443ef5eb3d7b9
 * Entry: 0x624220; label: FUN_00624220
 */

void FUN_00624220(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    if ((DAT_02912e8c != 0) && (*(int *)(DAT_02912e8c + 0x10) == param_1)) {
      DAT_02912e8c = 0;
    }
    if (param_1 == DAT_02912eb0) {
      DAT_02912eb0 = 0;
    }
    iVar1 = *(int *)(param_1 + 0x40);
    if (iVar1 != 0) {
      if (param_1 == DAT_02912eac) {
        DAT_02912eac = iVar1;
      }
      *(undefined4 *)(iVar1 + 0x3c) = 0;
    }
    if (param_1 == DAT_02912eb4) {
      DAT_02912eb4 = 0;
    }
    if (param_1 == DAT_02912eac) {
      DAT_02912eac = 0;
    }
    if (*(int *)(param_1 + 0x3c) != 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x40) = 0;
    }
    FUN_006241d0(param_1);
    FUN_004ef280(param_1,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0x3d0);
  }
  return;
}

