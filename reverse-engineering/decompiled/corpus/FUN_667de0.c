/* Ghidra analysis pseudocode, not original source.
 * ev_b1d683d72d7bcdb306124a83b006db4b41bf581671bc5ef620d768a8a4b84d3d
 * Entry: 0x667de0; label: FUN_00667de0
 */

void FUN_00667de0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  if (DAT_029231a8 == -1) {
    return;
  }
  if ((&DAT_02924b60)[DAT_029231a8 * 0x16] == -1) {
    return;
  }
  iVar2 = *(int *)(DAT_0296209c +
                  *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4) *
                  4);
  cVar1 = *(char *)(iVar2 + 0x2c);
  if ((((cVar1 == '\0') || (cVar1 == '\b')) || (cVar1 == '\t')) || (cVar1 == '\n')) {
    pcVar4 = "Random Start";
  }
  else {
    if (((cVar1 != '\x06') && (cVar1 != '\a')) && ((cVar1 != '\v' && (cVar1 != '\f'))))
    goto LAB_00667ea2;
    pcVar4 = "Base Emit Vector";
  }
  DAT_0292fe10 = FUN_00619250(0x46,0x46,0xb4,300,DAT_02912e80,&LAB_00667dc0,pcVar4);
LAB_00667ea2:
  if (DAT_0292fe10 != 0) {
    cVar1 = *(char *)(iVar2 + 0x2c);
    if (((cVar1 == '\0') || (cVar1 == '\b')) || ((cVar1 == '\t' || (cVar1 == '\n')))) {
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662b20,0,(float)DAT_00810ae8 * 5.0,
                           *(undefined4 *)(iVar2 + 0x58),"Rand Start X");
      FUN_00618e10(DAT_0292fe10,uVar3);
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662ba0,0,(float)DAT_00810ae8 * 5.0,
                           *(undefined4 *)(iVar2 + 0x5c),"Rand Start Y");
      FUN_00618e10(DAT_0292fe10,uVar3);
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662cf0,0,(float)DAT_00810ae8 * 5.0,
                           *(undefined4 *)(iVar2 + 0x60),"Rand Start Z");
      FUN_00618e10(DAT_0292fe10,uVar3);
    }
    else if (((cVar1 == '\x06') || (cVar1 == '\a')) || (cVar1 == '\f')) {
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662b20,0,(float)DAT_00810ae8 * 5.0,
                           *(undefined4 *)(iVar2 + 0x58),"Base Mag");
      FUN_00618e10(DAT_0292fe10,uVar3);
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662ba0,0xc3340000,0x43b40000,
                           *(float *)(iVar2 + 0x5c) * 0.005493164,"Base Rot Y");
      FUN_00618e10(DAT_0292fe10,uVar3);
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662cf0,0xc3340000,0x43340000,
                           *(float *)(iVar2 + 0x60) * 0.005493164,"Base Rot Z");
      FUN_00618e10(DAT_0292fe10,uVar3);
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
    }
    else if (cVar1 == '\v') {
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662b20,0,(float)DAT_00810ae8 * 5.0,
                           *(undefined4 *)(iVar2 + 0x58),"Base Mag");
      FUN_00618e10(DAT_0292fe10,uVar3);
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662ba0,0xc3340000,0x43b40000,
                           *(float *)(iVar2 + 0x5c) * 0.005493164,"Base Rot Y");
      FUN_00618e10(DAT_0292fe10,uVar3);
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662cf0,0xc2b40000,0x43340000,
                           *(float *)(iVar2 + 0x60) * 0.005493164,"Base Rot Z");
      FUN_00618e10(DAT_0292fe10,uVar3);
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
    }
    if ((*(char *)(iVar2 + 0x2c) == '\x06') || (*(char *)(iVar2 + 0x2c) == '\f')) {
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662a90,0,(float)DAT_00810ae8,
                           *(undefined4 *)(iVar2 + 0x418),"Ramp Time");
      FUN_00618e10(DAT_0292fe10,uVar3);
    }
    FUN_006279b0(param_1,DAT_0292fe10);
    *(int *)(DAT_0292fe10 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_0292fe10 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

