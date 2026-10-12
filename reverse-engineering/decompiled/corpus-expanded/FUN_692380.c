/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x692380; label: FUN_00692380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00692380(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar1 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    DAT_02962a78 = FUN_00619250(0x46,0x46,0xb4,300,DAT_02912e80,FUN_00664160,"Draw Flag");
    if (DAT_02962a78 != 0) {
      uVar2 = FUN_00627b80(1,&DAT_008109d8,*(char *)(iVar1 + 0x2f1) == '\x01',1,FUN_00692310,
                           "Before Fog");
      FUN_00618e10(DAT_02962a78,uVar2);
      uVar2 = FUN_00627b80(0,&DAT_008109d8,*(char *)(iVar1 + 0x2f1) == '\0',1,FUN_00692310,
                           "After Fog");
      FUN_00618e10(DAT_02962a78,uVar2);
      uVar2 = FUN_00627b80(3,&DAT_008109d8,*(char *)(iVar1 + 0x2f1) == '\x03',1,FUN_00692310,
                           "Super Early");
      FUN_00618e10(DAT_02962a78,uVar2);
      uVar2 = FUN_00627b80(4,&DAT_008109d8,*(char *)(iVar1 + 0x2f1) == '\x04',1,FUN_00692310,
                           "Panel Mode");
      FUN_00618e10(DAT_02962a78,uVar2);
      FUN_006279b0(param_1,DAT_02962a78);
      *(int *)(DAT_02962a78 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02962a78 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

