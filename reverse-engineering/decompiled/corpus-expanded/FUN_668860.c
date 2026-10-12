/* Ghidra pseudocode, not original source.
 * ev_649900f3c82336bf94a875d1c19b8123e0c4482fbb0765088d6a26c91e5b98b7
 * Entry: 0x668860; label: FUN_00668860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00668860(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    FUN_006580e0((int)*(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4
                                ),_DAT_00810ae0);
  }
  iVar1 = *(int *)(param_1 + 0x40);
  iVar2 = 0;
  if (iVar1 != 0) {
    FUN_006279f0(param_1);
    iVar2 = iVar1;
  }
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
    (**(code **)(param_1 + 0x30))(param_1,iVar2);
  }
  return;
}

