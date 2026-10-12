/* Ghidra analysis pseudocode, not original source.
 * ev_63802f60b4285c5edf6c429a3d1e3220ec0e39d2563d3bbc7dd58661d8af5682
 * Entry: 0x5be970; label: FUN_005be970
 */

float10 FUN_005be970(float param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 fVar4;
  float10 fVar5;
  float local_8;
  
  iVar1 = DAT_0095e544;
  if (DAT_00806ad0 != 0) {
    iVar1 = FUN_004eef40(40000,"d:\\projects\\legosagapc\\nu2api.saga\\numath\\nutrig.c",0x362);
    DAT_0095e544 = iVar1;
    if (iVar1 == 0) {
      return (float10)0;
    }
    do {
      FUN_006e92e0();
      iVar2 = FUN_006e6b90();
      *(float *)(iVar1 + iVar2 * 4) = (float)extraout_ST1;
    } while ((float)(extraout_ST0 + (float10)1) < 9999.0 !=
             ((float)(extraout_ST0 + (float10)1) == 9999.0));
    DAT_00806ad0 = 0;
  }
  if (param_1 != 3.4028235e+38) {
    iVar2 = FUN_006e6b90();
    if ((float)(extraout_ST0_00 - (float10)iVar2) < 0.0) {
      iVar2 = iVar2 + -1;
    }
    fVar5 = extraout_ST1_00;
    iVar3 = FUN_006e6b90();
    if (iVar3 < 9999) {
      fVar4 = (float10)(float)(extraout_ST0_01 - (float10)iVar3) *
              (float10)*(float *)(iVar1 + 4 + iVar3 * 4) +
              (float10)*(float *)(iVar1 + iVar3 * 4) *
              (extraout_ST1_01 - (float10)(float)(extraout_ST0_01 - (float10)iVar3));
    }
    else {
      fVar4 = (float10)*(float *)(iVar1 + iVar3 * 4);
    }
    local_8 = (float)fVar4;
    if (iVar2 < 1) {
      if (iVar2 < 0) {
        if (7 < -iVar2) {
          iVar1 = (-iVar2 - 8U >> 3) + 1;
          iVar2 = iVar2 + iVar1 * 8;
          do {
            iVar1 = iVar1 + -1;
            local_8 = local_8 * 0.1 * 0.1 * 0.1 * 0.1 * 0.1 * 0.1 * 0.1 * 0.1;
          } while (iVar1 != 0);
        }
        if (iVar2 < 0) {
          iVar2 = -iVar2;
          do {
            iVar2 = iVar2 + -1;
            local_8 = local_8 * 0.1;
          } while (iVar2 != 0);
        }
      }
    }
    else {
      if (7 < iVar2) {
        iVar1 = (iVar2 - 8U >> 3) + 1;
        iVar2 = iVar2 + iVar1 * -8;
        do {
          iVar1 = iVar1 + -1;
          local_8 = (float)((float10)(float)((float10)(float)((float10)(float)((float10)(float)((
                                                  float10)(float)((float10)(float)((float10)(float)(
                                                  (float10)local_8 * fVar5) * fVar5) * fVar5) *
                                                  fVar5) * fVar5) * fVar5) * fVar5) * fVar5);
        } while (iVar1 != 0);
      }
      if (0 < iVar2) {
        do {
          iVar2 = iVar2 + -1;
          local_8 = (float)((float10)local_8 * fVar5);
        } while (0 < iVar2);
        return (float10)local_8;
      }
    }
    return (float10)local_8;
  }
  return (float10)3.4028235e+38;
}

