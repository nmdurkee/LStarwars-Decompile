/* Ghidra pseudocode, not original source.
 * ev_649900f3c82336bf94a875d1c19b8123e0c4482fbb0765088d6a26c91e5b98b7
 * Entry: 0x668f70; label: FUN_00668f70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00668f70(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar1 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    DAT_029211f0 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_00668f50,"Emitter Vel");
    if (DAT_029211f0 != 0) {
      uVar2 = FUN_00625150(0,&local_10,0,FUN_00662ae0,-((float)DAT_00810ae8 * 10.0),
                           (float)DAT_00810ae8 * 20.0,*(undefined4 *)(iVar1 + 0x48),"Emitter Vel");
      FUN_00618e10(DAT_029211f0,uVar2);
      FUN_006279b0(param_1,DAT_029211f0);
      *(int *)(DAT_029211f0 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_029211f0 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

