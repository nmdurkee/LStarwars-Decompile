/* Ghidra analysis pseudocode, not original source.
 * ev_6dd3c36930770dc91587d8e9f0315de295532c3384b93e99878ade04445159cc
 * Entry: 0x50f740; label: FUN_0050f740
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050f740(int param_1,undefined4 param_2,uint param_3)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  undefined4 local_c;
  byte local_8;
  
  uVar8 = param_3;
  bVar6 = (byte)param_3;
  param_3 = 0x80;
  if (bVar6 < 0x81) {
    param_3 = uVar8;
  }
  fVar3 = _DAT_0080098c;
  if (*(float *)(param_1 + 0xd0) != 0.0) {
    fVar3 = *(float *)(param_1 + 0xd0);
  }
  fVar3 = _DAT_008009a8 * fVar3;
  fVar4 = _DAT_00800994;
  if (*(float *)(param_1 + 0xd4) != 0.0) {
    fVar4 = *(float *)(param_1 + 0xd4);
  }
  pfVar1 = *(float **)(param_1 + 0xc4);
  fVar4 = _DAT_008009a8 * fVar4;
  if (pfVar1 != (float *)0x0) {
    FUN_0050d1c0(param_2,*pfVar1 * *(float *)(param_1 + 200) + *(float *)(param_1 + 0x94),
                 pfVar1[1] * *(float *)(param_1 + 200) + *(float *)(param_1 + 0x98),
                 *(undefined4 *)(param_1 + 0x9c),fVar3 * _DAT_008009a4,fVar3,fVar3,DAT_00921db4,0,0,
                 0,param_3 >> 2 & 0x3f);
  }
  iVar2 = *(int *)(param_1 + 0x8c);
  if ((*(short *)(param_1 + 0xe) <= iVar2) && (iVar2 <= *(short *)(param_1 + 0x12))) {
    local_c._1_3_ = (undefined3)((uint)fVar3 >> 8);
    if (iVar2 == *(short *)(param_1 + 10)) {
      local_8 = DAT_008009a2;
      bVar6 = DAT_00921dae;
      bVar7 = DAT_008009a1;
      if (DAT_009213e4 != 0) {
        local_8 = DAT_008009a0;
        bVar6 = DAT_0080099f;
        bVar7 = DAT_00921dad;
      }
      local_c = CONCAT31(local_c._1_3_,bVar7);
      if (0.0 < _DAT_00921d70) {
        fVar5 = 1.0 - _DAT_00921d70;
        local_8 = (byte)(int)ROUND((float)DAT_008009a1 * fVar5 + (float)DAT_00921dad * _DAT_00921d70
                                  );
        local_c = CONCAT31(local_c._1_3_,local_8);
        local_8 = (byte)(int)ROUND((float)DAT_00921dae * fVar5 + (float)DAT_0080099f * _DAT_00921d70
                                  );
        bVar6 = local_8;
        local_8 = (byte)(int)ROUND((float)DAT_008009a2 * fVar5 + (float)DAT_008009a0 * _DAT_00921d70
                                  );
      }
    }
    else if (DAT_00921db0 == 0) {
      local_c = CONCAT31(local_c._1_3_,DAT_00921da9);
      bVar6 = DAT_0080099a;
      local_8 = DAT_0080099b;
    }
    else {
      local_c = CONCAT31(local_c._1_3_,DAT_009213e1);
      bVar6 = DAT_009213e2;
      local_8 = DAT_009213e0;
    }
    if (*(int *)(param_1 + 0xc4) == 0) {
      FUN_0050f3b0(param_2,*(undefined4 *)(param_1 + 0x94),*(undefined4 *)(param_1 + 0x98),
                   *(undefined4 *)(param_1 + 0x9c),fVar3 * _DAT_008009a4,fVar3,fVar3,DAT_00921db4,
                   local_c,bVar6,local_8,_DAT_008009ac,1,0,0,param_3 & 0xff);
    }
    else {
      FUN_0050c780(param_2,*(undefined4 *)(param_1 + 0x94),*(undefined4 *)(param_1 + 0x98),
                   *(undefined4 *)(param_1 + 0x9c),fVar3 * _DAT_008009a4,fVar3,fVar3,DAT_00921db4,
                   local_c,bVar6,local_8,param_3);
    }
  }
  *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + 1;
  *(float *)(param_1 + 0x98) = fVar4 + *(float *)(param_1 + 0x98);
  DAT_00921db0 = 0;
  DAT_00921db4 = 0;
  _DAT_008009a4 = 1.0;
  _DAT_008009a8 = 1.0;
  return;
}

