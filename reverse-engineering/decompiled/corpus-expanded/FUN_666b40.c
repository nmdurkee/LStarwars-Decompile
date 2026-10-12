/* Ghidra pseudocode, not original source.
 * ev_1085323f9a3cb798a23dfec0c4468a06f744be49385e8c8d18d4e2ca61b2546b
 * Entry: 0x666b40; label: FUN_00666b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00666b40(int param_1)

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
    DAT_0292183c = FUN_00619250(0x46,0x46,0xdc,300,DAT_02912e80,FUN_00666b10,"Particle Size");
    if (DAT_0292183c != 0) {
      uVar3 = FUN_00629da0(0,&local_10,FUN_00663490,"Width Envelope");
      FUN_00618e10(DAT_0292183c,uVar3);
      DAT_02962ae4 = DAT_02900c84;
      iVar4 = 0;
      pfVar5 = (float *)(iVar1 + 0x150);
      do {
        fVar2 = 1.0;
        if (*(float *)(iVar1 + 0x14c) != *(float *)(iVar1 + 0x148)) {
          fVar2 = (pfVar5[1] - *(float *)(iVar1 + 0x148)) /
                  (*(float *)(iVar1 + 0x14c) - *(float *)(iVar1 + 0x148));
        }
        FUN_0061a810(DAT_02962ae4,*pfVar5,fVar2,fVar2,fVar2);
        if (*pfVar5 == 1.0) break;
        iVar4 = iVar4 + 1;
        pfVar5 = pfVar5 + 2;
      } while (iVar4 < 8);
      uVar3 = FUN_00629da0(0,&local_10,FUN_00663490,"Height Envelope");
      FUN_00618e10(DAT_0292183c,uVar3);
      DAT_02962ae8 = DAT_02900c84;
      iVar4 = 0;
      pfVar5 = (float *)(iVar1 + 400);
      do {
        fVar2 = 1.0;
        if (*(float *)(iVar1 + 0x14c) != *(float *)(iVar1 + 0x148)) {
          fVar2 = (pfVar5[1] - *(float *)(iVar1 + 0x148)) /
                  (*(float *)(iVar1 + 0x14c) - *(float *)(iVar1 + 0x148));
        }
        FUN_0061a810(DAT_02962ae8,*pfVar5,fVar2,fVar2,fVar2);
        if (*pfVar5 == 1.0) break;
        iVar4 = iVar4 + 1;
        pfVar5 = pfVar5 + 2;
      } while (iVar4 < 8);
      uVar3 = FUN_00625150(0,&local_10,0,FUN_00663490,0,(float)DAT_00810ae8 * 5000.0,
                           *(undefined4 *)(iVar1 + 0x148),"Min Size");
      FUN_00618e10(DAT_0292183c,uVar3);
      DAT_02962aec = DAT_02900c84;
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
      uVar3 = FUN_00625150(0,&local_10,0,FUN_00663490,0,(float)DAT_00810ae8 * 5000.0,
                           *(undefined4 *)(iVar1 + 0x14c),"Max Size");
      FUN_00618e10(DAT_0292183c,uVar3);
      DAT_02962af0 = DAT_02900c84;
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
      uVar3 = FUN_00627a80(1,&local_10,0,0,FUN_006631a0,"Copy Width to Height");
      FUN_00618e10(DAT_0292183c,uVar3);
      uVar3 = FUN_00627a80(2,&local_10,0,0,FUN_006631a0,"Copy Height to Width");
      FUN_00618e10(DAT_0292183c,uVar3);
      FUN_006279b0(param_1,DAT_0292183c);
      *(int *)(DAT_0292183c + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_0292183c + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

