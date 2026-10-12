/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x461720; label: FUN_00461720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00461720(int param_1,int param_2,float param_3)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float local_18;
  float local_14;
  float local_c;
  float local_8;
  float local_4;
  
  puVar4 = &DAT_00855ed0;
  if ((*(byte *)(param_2 + 0xb0) & 0x80) == 0) {
    puVar4 = &DAT_00855ea4;
  }
  if (param_3 != 0.0) {
    if (*(int *)(param_1 + 0x14) == 0) {
      local_4 = -((1.0 - ABS(_DAT_00804fb8)) + 1.0);
      iVar5 = FUN_006e6b90(puVar4[4],0,0x3f800000,0);
      FUN_00594c30(puVar4,(float)extraout_ST0_00,
                   (float)((float10)local_4 +
                          (float10)(float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff] *
                          (extraout_ST1 - (float10)local_4)));
      return;
    }
    iVar5 = (int)*(short *)((int)&DAT_0087a18c + *(int *)(param_1 + 0x14) * 2 + 2);
    if (iVar5 != -1) {
      FUN_00594c30(puVar4,0,_DAT_00804fb8,puVar4[4],0,0x3f800000,0);
      local_14 = _DAT_007f8604;
      local_8 = 0.0;
      param_3 = 0.4;
      if (0.5 <= *(float *)(param_1 + 0x18)) {
        if (2.0 <= *(float *)(param_1 + 0x18)) {
          local_18 = 1.0;
          FUN_006e6b90();
          if (DAT_00876de8 == 0) {
            FUN_00681f40("Char_Icon_Slide",0);
            DAT_00876de8 = 1;
          }
          iVar2 = FUN_006e6b90();
          fVar1 = (float)(extraout_ST0 -
                         ((float10)(float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] + extraout_ST0) *
                         (float10)0.5);
          iVar2 = FUN_00594250(iVar5,*puVar4,*(undefined2 *)((int)puVar4 + 6));
          if (iVar2 != -1) {
            FUN_00594810(puVar4,iVar5,&local_c,&local_4);
            param_3 = (float)puVar4[4] * _DAT_007fc318;
            if ((DAT_0093b0d8 != 0) && (*(char *)(DAT_0093b0d8 + 0xb) != '\0')) {
              param_3 = param_3 * 0.875;
            }
            local_8 = fVar1 * (local_c - 0.0) + 0.0;
            local_14 = local_14 + fVar1 * (local_4 - local_14);
            param_3 = (param_3 - 0.4) * fVar1 + 0.4;
          }
        }
        else {
          DAT_00876de4 = 0;
          DAT_00876de8 = 0;
          local_18 = 1.0;
        }
      }
      else {
        if ((0.25 < *(float *)(param_1 + 0x18)) && (DAT_00876de4 == 0)) {
          FUN_00681f40("Char_Icon_App",0);
          DAT_00876de4 = 1;
        }
        local_c = 0.0;
        local_18 = *(float *)(param_1 + 0x18) + *(float *)(param_1 + 0x18);
        FUN_006e6b90();
      }
      FUN_0055b830(iVar5,local_8,local_14,0,param_3,0xa7,local_18,local_18,1,0);
      uVar3 = FUN_006e6b90();
      FUN_0050d910(*(undefined4 *)(DAT_00926c20 + *(int *)(iVar5 * 0x4c + DAT_0093b274) * 4),0,
                   _DAT_007f8608,0x3f800000,_DAT_007f860c,_DAT_007f860c,_DAT_007f860c,0,DAT_007fa4c8
                   ,DAT_007fa4cc,DAT_0087a774,0x3fd9999a,1,0,0,uVar3);
    }
  }
  return;
}

