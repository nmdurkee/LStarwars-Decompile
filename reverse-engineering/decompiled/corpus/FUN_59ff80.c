/* Ghidra analysis pseudocode, not original source.
 * ev_619d50b6392102a54c9e38c540a3f8930ee6fdfe94aeb342acdefb90820d232e
 * Entry: 0x59ff80; label: FUN_0059ff80
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059ff80(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  float local_20;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar5 = 0;
  pfVar7 = (float *)&DAT_009565cc;
  do {
    if ((&DAT_0093d7f0)[iVar5] == 0) {
      *pfVar7 = 0.5;
    }
    else if (*pfVar7 < 0.5) {
      local_20 = *pfVar7 + _DAT_00925018;
      *pfVar7 = local_20;
      if (local_20 <= 0.5) {
        iVar6 = 0;
        local_20 = local_20 + local_20;
        do {
          fVar2 = pfVar7[-0xd];
          local_c = *(float *)((int)fVar2 + 0x80);
          local_4 = *(float *)((int)fVar2 + 0x88);
          iVar3 = (&DAT_0093d7f0)[iVar5];
          local_8 = *(float *)((int)fVar2 + 0x17c) +
                    pfVar7[iVar6 + -3] *
                    (*(float *)((int)fVar2 + 0x188) - *(float *)((int)fVar2 + 0x17c));
          local_18 = *(float *)(iVar3 + 0x80);
          local_10 = *(float *)(iVar3 + 0x88);
          local_14 = *(float *)(iVar3 + 0x17c) +
                     pfVar7[iVar6 + -3] * (*(float *)(iVar3 + 0x188) - *(float *)(iVar3 + 0x17c));
          if (iVar6 == 1) {
            iVar3 = FUN_006e6b90();
            local_20 = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff];
          }
          else if (iVar6 == 2) {
            iVar3 = FUN_006e6b90();
            local_20 = 1.0 - (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff];
          }
          local_18 = local_c + local_20 * (local_18 - local_c);
          local_14 = local_8 + local_20 * (local_14 - local_8);
          local_10 = local_4 + local_20 * (local_10 - local_4);
          if (iVar6 == 1) {
            iVar3 = FUN_006e6b90();
            local_14 = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * 0.005 + local_14;
          }
          else if (iVar6 == 2) {
            iVar3 = FUN_006e6b90();
            local_14 = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * 0.01 + local_14;
          }
          uVar4 = param_1;
          if (iVar5 != 0) {
            uVar4 = param_2;
          }
          FUN_00684be0(uVar4,&local_18,param_3,_DAT_00925018,0,0,0);
          pfVar1 = pfVar7 + iVar6 * 3 + -0xc;
          *pfVar1 = local_18;
          iVar6 = iVar6 + 1;
          pfVar1[1] = local_14;
          pfVar1[2] = local_10;
        } while (iVar6 < 3);
      }
      else {
        *pfVar7 = 0.5;
      }
    }
    iVar5 = iVar5 + 1;
    pfVar7 = pfVar7 + 0xe;
  } while (iVar5 < 2);
  return;
}

