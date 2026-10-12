/* Ghidra analysis pseudocode, not original source.
 * ev_280130a43e77cd6b8822caba528fd01ad8a7c5be61051c42bd6bb5c51ef00c77
 * Entry: 0x6677f0; label: FUN_006677f0
 */

void FUN_006677f0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar2 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    DAT_02924b3c = FUN_00619250(0x46,0x46,0xb4,300,DAT_02912e80,&LAB_006677d0,"Emitter Variation");
    if (DAT_02924b3c != 0) {
      cVar1 = *(char *)(iVar2 + 0x2c);
      if ((((cVar1 == '\0') || (cVar1 == '\b')) || (cVar1 == '\t')) || (cVar1 == '\n')) {
        uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662b20,0,(float)DAT_00810ae8 * 5.0,
                             *(undefined4 *)(iVar2 + 0x4c),"Rand Emit X");
        FUN_00618e10(DAT_02924b3c,uVar3);
        uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662ba0,0,(float)DAT_00810ae8 * 5.0,
                             *(undefined4 *)(iVar2 + 0x50),"Rand Emit Y");
        FUN_00618e10(DAT_02924b3c,uVar3);
        uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662cf0,0,(float)DAT_00810ae8 * 5.0,
                             *(undefined4 *)(iVar2 + 0x54),"Rand Emit Z");
        FUN_00618e10(DAT_02924b3c,uVar3);
      }
      else if ((cVar1 == '\x06') || (cVar1 == '\f')) {
        uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662b20,0,(float)DAT_00810ae8 * 5.0,
                             *(undefined4 *)(iVar2 + 0x4c),"Rand Mag X");
        FUN_00618e10(DAT_02924b3c,uVar3);
        uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662ba0,0,0x43340000,
                             *(float *)(iVar2 + 0x50) * 0.005493164,"Rand Rot Y");
        FUN_00618e10(DAT_02924b3c,uVar3);
        FUN_0061d880(DAT_02900c84,"(%1.01f)");
        FUN_0061d900(DAT_02900c84,0x3dcccccd);
        uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662cf0,0,0x43340000,
                             *(float *)(iVar2 + 0x54) * 0.005493164,"Rand Rot Z");
        FUN_00618e10(DAT_02924b3c,uVar3);
        FUN_0061d880(DAT_02900c84,"(%1.01f)");
        FUN_0061d900(DAT_02900c84,0x3dcccccd);
      }
      else if (cVar1 == '\a') {
        uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662b20,0,(float)DAT_00810ae8 * 5.0,
                             *(undefined4 *)(iVar2 + 0x4c),"Rand Mag");
        FUN_00618e10(DAT_02924b3c,uVar3);
        uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662ba0,0xc2b40000,0x43340000,
                             *(float *)(iVar2 + 0x50) * 0.005493164,"Step Rot Y");
        FUN_00618e10(DAT_02924b3c,uVar3);
        FUN_0061d880(DAT_02900c84,"(%1.01f)");
        FUN_0061d900(DAT_02900c84,0x3dcccccd);
        uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662cf0,0xc2b40000,0x43340000,
                             *(float *)(iVar2 + 0x54) * 0.005493164,"Step Rot Z");
        FUN_00618e10(DAT_02924b3c,uVar3);
        FUN_0061d880(DAT_02900c84,"(%1.01f)");
        FUN_0061d900(DAT_02900c84,0x3dcccccd);
      }
      else if (cVar1 == '\v') {
        uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662b20,0,(float)DAT_00810ae8 * 5.0,
                             *(undefined4 *)(iVar2 + 0x4c),"Rand Mag X");
        FUN_00618e10(DAT_02924b3c,uVar3);
        uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662ba0,0,0x43340000,
                             *(float *)(iVar2 + 0x50) * 0.005493164,"Rand Rot Y");
        FUN_00618e10(DAT_02924b3c,uVar3);
        FUN_0061d880(DAT_02900c84,"(%1.01f)");
        FUN_0061d900(DAT_02900c84,0x3dcccccd);
        uVar3 = FUN_00625150(0,&local_10,0,&LAB_00662cf0,0,0x42b40000,
                             *(float *)(iVar2 + 0x54) * 0.005493164,"Rand Rot Z");
        FUN_00618e10(DAT_02924b3c,uVar3);
        FUN_0061d880(DAT_02900c84,"(%1.01f)");
        FUN_0061d900(DAT_02900c84,0x3dcccccd);
      }
      FUN_006279b0(param_1,DAT_02924b3c);
      *(int *)(DAT_02924b3c + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02924b3c + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

