/* Ghidra pseudocode, not original source.
 * ev_649900f3c82336bf94a875d1c19b8123e0c4482fbb0765088d6a26c91e5b98b7
 * Entry: 0x6688f0; label: FUN_006688f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006688f0(int param_1)

{
  undefined4 uVar1;
  
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    DAT_02962a7c = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_006688d0,"Scale Effect");
    if (DAT_02962a7c != 0) {
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00668850,0x3dcccccd,0x411e6666,_DAT_00810ae0,
                           "Scale Factor");
      FUN_00618e10(DAT_02962a7c,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00668860,"Scale Effect");
      FUN_00618e10(DAT_02962a7c,uVar1);
      FUN_006279b0(param_1,DAT_02962a7c);
      *(int *)(DAT_02962a7c + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02962a7c + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

