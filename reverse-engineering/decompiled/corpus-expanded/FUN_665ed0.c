/* Ghidra pseudocode, not original source.
 * ev_1085323f9a3cb798a23dfec0c4468a06f744be49385e8c8d18d4e2ca61b2546b
 * Entry: 0x665ed0; label: FUN_00665ed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00665ed0(int param_1)

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
    DAT_02947d74 = FUN_00619250(0x46,0x46,0xb4,300,DAT_02912e80,FUN_00665eb0,"Collision Spheres");
    if (DAT_02947d74 != 0) {
      uVar3 = FUN_00629da0(0,&local_10,FUN_00665320,"Collision Envelope");
      FUN_00618e10(DAT_02947d74,uVar3);
      DAT_02962b10 = DAT_02900c84;
      iVar4 = 0;
      pfVar5 = (float *)(iVar1 + 0x2b0);
      do {
        fVar2 = 1.0;
        if (*(float *)(iVar1 + 0x14c) != *(float *)(iVar1 + 0x148)) {
          fVar2 = (pfVar5[1] - *(float *)(iVar1 + 0x148) / 10000.0) /
                  ((*(float *)(iVar1 + 0x14c) - *(float *)(iVar1 + 0x148)) / 10000.0);
        }
        FUN_0061a810(DAT_02962b10,*pfVar5,fVar2,fVar2,fVar2);
        if (*pfVar5 == 1.0) break;
        iVar4 = iVar4 + 1;
        pfVar5 = pfVar5 + 2;
      } while (iVar4 < 8);
      uVar3 = FUN_00625240(0,&local_10,0,FUN_00665190,0,8,(int)*(char *)(iVar1 + 0x2f0),
                           "Num Spheres");
      FUN_00618e10(DAT_02947d74,uVar3);
      uVar3 = FUN_00627a80(1,&local_10,0,0,FUN_006651e0,"Default Envelope");
      FUN_00618e10(DAT_02947d74,uVar3);
      FUN_006279b0(param_1,DAT_02947d74);
      *(int *)(DAT_02947d74 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02947d74 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

