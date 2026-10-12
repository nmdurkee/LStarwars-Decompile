/* Ghidra analysis pseudocode, not original source.
 * ev_b1d683d72d7bcdb306124a83b006db4b41bf581671bc5ef620d768a8a4b84d3d
 * Entry: 0x668320; label: FUN_00668320
 */

void FUN_00668320(int param_1)

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
    pcVar4 = "Start Velocity";
  }
  else {
    if (((cVar1 != '\x06') && (cVar1 != '\a')) && ((cVar1 != '\v' && (cVar1 != '\f'))))
    goto LAB_006683e2;
    pcVar4 = "Emit Point Velocity";
  }
  DAT_029211a4 = FUN_00619250(0x46,0x46,0xfa,300,DAT_02912e80,&LAB_00668300,pcVar4);
LAB_006683e2:
  if (DAT_029211a4 != 0) {
    cVar1 = *(char *)(iVar2 + 0x2c);
    if (((cVar1 == '\0') || (cVar1 == '\b')) || ((cVar1 == '\t' || (cVar1 == '\n')))) {
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662b20,0xc0a00000,(float)DAT_00810ae8 * 10.0,
                           *(undefined4 *)(iVar2 + 100),"Start Vel X");
      FUN_00618e10(DAT_029211a4,uVar3);
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662ba0,0xc0a00000,(float)DAT_00810ae8 * 10.0,
                           *(undefined4 *)(iVar2 + 0x68),"Start Vel Y");
      FUN_00618e10(DAT_029211a4,uVar3);
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662cf0,0xc0a00000,(float)DAT_00810ae8 * 10.0,
                           *(undefined4 *)(iVar2 + 0x6c),"Start Vel Z");
      FUN_00618e10(DAT_029211a4,uVar3);
    }
    else if (((cVar1 == '\x06') || (cVar1 == '\a')) || (cVar1 == '\f')) {
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662b20,0,(float)DAT_00810ae8 * 5.0,
                           *(undefined4 *)(iVar2 + 100),"Mag Velocity");
      FUN_00618e10(DAT_029211a4,uVar3);
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662ba0,0xc3340000,0x43b40000,
                           *(float *)(iVar2 + 0x68) * 0.005493164,"Rot Y Vel");
      FUN_00618e10(DAT_029211a4,uVar3);
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662cf0,0xc3340000,0x43340000,
                           *(float *)(iVar2 + 0x6c) * 0.005493164,"Rot Z Vel");
      FUN_00618e10(DAT_029211a4,uVar3);
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
    }
    else if (cVar1 == '\v') {
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662b20,0,(float)DAT_00810ae8 * 5.0,
                           *(undefined4 *)(iVar2 + 100),"Mag Velocity");
      FUN_00618e10(DAT_029211a4,uVar3);
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662ba0,0xc3340000,0x43b40000,
                           *(float *)(iVar2 + 0x68) * 0.005493164,"Rot Y Vel");
      FUN_00618e10(DAT_029211a4,uVar3);
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662cf0,0xc2b40000,0x43340000,
                           *(float *)(iVar2 + 0x6c) * 0.005493164,"Rot Z Vel");
      FUN_00618e10(DAT_029211a4,uVar3);
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
    }
    if ((*(char *)(iVar2 + 0x2c) == '\x06') || (*(char *)(iVar2 + 0x2c) == '\f')) {
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662a90,0,(float)DAT_00810ae8,
                           *(undefined4 *)(iVar2 + 0x418),"Ramp Time");
      FUN_00618e10(DAT_029211a4,uVar3);
    }
    FUN_006279b0(param_1,DAT_029211a4);
    *(int *)(DAT_029211a4 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029211a4 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

