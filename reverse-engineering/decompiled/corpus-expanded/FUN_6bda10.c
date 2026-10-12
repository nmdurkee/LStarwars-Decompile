/* Ghidra pseudocode, not original source.
 * ev_ec6de10755bbe4e6e32c4c75cfe39a8ef4339c5a6ad10c9ef5357c0f43b1bab3
 * Entry: 0x6bda10; label: FUN_006bda10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bda10(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = (int *)0x0;
  DAT_02973b04 = 0;
  if (0 < DAT_02973b00) {
    while ((DAT_02973b04 < DAT_02973b00 &&
           (piVar1 = (int *)(**(code **)(*(int *)(&DAT_02973b0c)[DAT_02973b04 * 2] + 0x14))(0),
           piVar1 == (int *)0x0))) {
      DAT_02973b04 = DAT_02973b04 + 1;
    }
  }
  if (piVar1 != (int *)0x0) {
    while( true ) {
      uVar2 = (**(code **)(*piVar1 + 0xc))();
      iVar3 = FUN_004f8b10(*(undefined4 *)(param_2 + 100),uVar2);
      if (iVar3 == 0) break;
      piVar4 = (int *)0x0;
      if (DAT_02973b04 < DAT_02973b00) {
        while ((DAT_02973b04 < DAT_02973b00 &&
               (piVar4 = (int *)(**(code **)(*(int *)(&DAT_02973b0c)[DAT_02973b04 * 2] + 0x14))
                                          (piVar1), piVar4 == (int *)0x0))) {
          DAT_02973b04 = DAT_02973b04 + 1;
          piVar1 = (int *)0x0;
        }
      }
      piVar1 = piVar4;
      if (piVar4 == (int *)0x0) {
        return;
      }
    }
    uVar2 = (**(code **)(*piVar1 + 0xc))();
    FUN_0061e530(param_2,uVar2);
    uVar2 = (**(code **)(*piVar1 + 0xc))();
    FUN_006ba280(uVar2);
  }
  return;
}

