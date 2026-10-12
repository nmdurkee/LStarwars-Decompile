/* Ghidra analysis pseudocode, not original source.
 * ev_280130a43e77cd6b8822caba528fd01ad8a7c5be61051c42bd6bb5c51ef00c77
 * Entry: 0x666510; label: FUN_00666510
 */

void FUN_00666510(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  float *pfVar5;
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
    DAT_02920aec = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,&LAB_006664e0,"Collision Torus");
    if (DAT_02920aec != 0) {
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_006660c0,0,(float)DAT_00810ae8 * 5.0,
                           *(undefined4 *)(iVar2 + 0x30c),"Torus Life");
      FUN_00618e10(DAT_02920aec,uVar3);
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00666110,0x3c23d70a,(float)DAT_00810ae8 * 5.0,
                           *(undefined4 *)(iVar2 + 0x304),"Base Major Radius");
      FUN_00618e10(DAT_02920aec,uVar3);
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00666160,0x3c23d70a,(float)DAT_00810ae8 * 5.0,
                           *(undefined4 *)(iVar2 + 0x308),"Base Minor Radius");
      FUN_00618e10(DAT_02920aec,uVar3);
      uVar3 = FUN_00629da0(0,&local_10,&LAB_006661b0,"Major Radius Envelope");
      FUN_00618e10(DAT_02920aec,uVar3);
      DAT_02962b14 = DAT_02900c84;
      iVar4 = 0;
      pfVar5 = (float *)(iVar2 + 0x310);
      do {
        fVar1 = pfVar5[1];
        FUN_0061a810(DAT_02962b14,*pfVar5,fVar1,fVar1,fVar1);
        if (*pfVar5 == 1.0) break;
        iVar4 = iVar4 + 1;
        pfVar5 = pfVar5 + 2;
      } while (iVar4 < 8);
      uVar3 = FUN_00629da0(0,&local_10,&LAB_006662c0,"Minor Radius Envelope 1");
      FUN_00618e10(DAT_02920aec,uVar3);
      DAT_02962b18 = DAT_02900c84;
      iVar4 = 0;
      pfVar5 = (float *)(iVar2 + 0x350);
      do {
        fVar1 = pfVar5[1];
        FUN_0061a810(DAT_02962b18,*pfVar5,fVar1,fVar1,fVar1);
        if (*pfVar5 == 1.0) break;
        iVar4 = iVar4 + 1;
        pfVar5 = pfVar5 + 2;
      } while (iVar4 < 8);
      uVar3 = FUN_00629da0(0,&local_10,&LAB_006663d0,"Minor Radius Envelope 2");
      FUN_00618e10(DAT_02920aec,uVar3);
      DAT_02962b1c = DAT_02900c84;
      iVar4 = 0;
      pfVar5 = (float *)(iVar2 + 0x390);
      do {
        fVar1 = pfVar5[1];
        FUN_0061a810(DAT_02962b1c,*pfVar5,fVar1,fVar1,fVar1);
        if (*pfVar5 == 1.0) break;
        iVar4 = iVar4 + 1;
        pfVar5 = pfVar5 + 2;
      } while (iVar4 < 8);
      FUN_006279b0(param_1,DAT_02920aec);
      *(int *)(DAT_02920aec + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02920aec + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

