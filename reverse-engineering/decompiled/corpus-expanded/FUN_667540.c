/* Ghidra pseudocode, not original source.
 * ev_649900f3c82336bf94a875d1c19b8123e0c4482fbb0765088d6a26c91e5b98b7
 * Entry: 0x667540; label: FUN_00667540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00667540(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar1 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    DAT_02924b38 = FUN_00619250(0x46,0x46,0xfa,200,DAT_02912e80,FUN_00667520,"Repeat / Radii");
    if (DAT_02924b38 != 0) {
      uVar2 = FUN_00627bc0(0,&DAT_008109d8,*(char *)(iVar1 + 0x2f3) != '\0',1,FUN_00667160,"Repeat")
      ;
      FUN_00618e10(DAT_02924b38,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,&LAB_00667330,"Repeat Box...");
      FUN_00618e10(DAT_02924b38,uVar2);
      uVar2 = FUN_00625150(0,&DAT_008109d8,0,FUN_00662f50,0,(float)DAT_00810ae8 * 25.0,
                           *(undefined4 *)(iVar1 + 0x38),"CutOff Rad");
      FUN_00618e10(DAT_02924b38,uVar2);
      uVar2 = FUN_00625150(0,&DAT_008109d8,0,FUN_00662fb0,0,(float)DAT_00810ae8 * 25.0,
                           *(undefined4 *)(iVar1 + 0x34),"CutOn Rad");
      FUN_00618e10(DAT_02924b38,uVar2);
      uVar2 = FUN_00625150(0,&DAT_008109d8,0,FUN_00663010,0,(float)DAT_00810ae8 * 25.0,
                           *(undefined4 *)(iVar1 + 0x3c),"DrawCutOff Rad");
      FUN_00618e10(DAT_02924b38,uVar2);
      uVar2 = FUN_00625150(0,&DAT_008109d8,0,&LAB_00663050,0,(float)DAT_00810ae8 * 25.0,
                           *(undefined4 *)(iVar1 + 0x40),"SoundCutOff Rad");
      FUN_00618e10(DAT_02924b38,uVar2);
      uVar2 = FUN_00625150(0,&DAT_008109d8,0,&LAB_00663090,0,(float)DAT_00810ae8 * 5.0,
                           *(undefined4 *)(iVar1 + 0x44),"CameraCutOff Rad");
      FUN_00618e10(DAT_02924b38,uVar2);
      FUN_006279b0(param_1,DAT_02924b38);
      *(int *)(DAT_02924b38 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02924b38 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

