/* Ghidra pseudocode, not original source.
 * ev_649900f3c82336bf94a875d1c19b8123e0c4482fbb0765088d6a26c91e5b98b7
 * Entry: 0x666ef0; label: FUN_00666ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00666ef0(int param_1)

{
  int iVar1;
  float fVar2;
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
    iVar1 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    DAT_029211a0 = FUN_00619250(0x46,0x46,0xb4,300,DAT_02912e80,FUN_00666ec0,"Particle Rotation");
    if (DAT_029211a0 != 0) {
      uVar3 = FUN_00629da0(0,&local_10,&LAB_00663750,"Rotation Envelope");
      FUN_00618e10(DAT_029211a0,uVar3);
      DAT_02962af4 = DAT_02900c84;
      iVar4 = 0;
      pfVar5 = (float *)(iVar1 + 0x1d8);
      do {
        fVar2 = 1.0;
        if (*(float *)(iVar1 + 0x1d4) != *(float *)(iVar1 + 0x1d0)) {
          fVar2 = (pfVar5[1] * 0.005493164 - *(float *)(iVar1 + 0x1d0)) /
                  (*(float *)(iVar1 + 0x1d4) - *(float *)(iVar1 + 0x1d0));
        }
        FUN_0061a810(DAT_02962af4,*pfVar5,fVar2,fVar2,fVar2);
        if (*pfVar5 == 1.0) break;
        iVar4 = iVar4 + 1;
        pfVar5 = pfVar5 + 2;
      } while (iVar4 < 8);
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00663750,0xc4340000,0x44b40000,
                           *(undefined4 *)(iVar1 + 0x1d0),"Min Rotation");
      FUN_00618e10(DAT_029211a0,uVar3);
      DAT_02962af8 = DAT_02900c84;
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
      uVar3 = FUN_00625150(0,&local_10,0,&LAB_00663750,0xc4340000,0x44b40000,
                           *(undefined4 *)(iVar1 + 0x1d4),"Max Rotation");
      FUN_00618e10(DAT_029211a0,uVar3);
      DAT_02962afc = DAT_02900c84;
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
      FUN_006279b0(param_1,DAT_029211a0);
      *(int *)(DAT_029211a0 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_029211a0 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

