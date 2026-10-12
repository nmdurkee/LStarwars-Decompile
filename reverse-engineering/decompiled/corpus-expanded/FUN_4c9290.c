/* Ghidra pseudocode, not original source.
 * ev_f6678a28cc19d550655313a6a6f4f7bb8e44fc9612bb24799d4de398af21bc4a
 * Entry: 0x4c9290; label: FUN_004c9290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_004c9290(undefined4 param_1,int param_2,float param_3,undefined4 param_4,undefined4 param_5,
            int param_6,float param_7)

{
  uint *puVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  bool bVar9;
  float10 fVar10;
  float10 fVar11;
  float local_14;
  
  iVar4 = **(int **)(PTR_DAT_00802c54 + 0x2988);
  bVar9 = false;
  if (param_3 == 0.0) {
    return 0;
  }
  piVar5 = *(int **)((int)param_3 + 0xd0);
  if (piVar5 == (int *)0x0) {
    return 0;
  }
  if (*piVar5 == 0) {
    return 0;
  }
  iVar6 = *piVar5;
  if (param_6 != 0) {
    *(undefined4 *)(iVar6 + 0xed4) = *(undefined4 *)(*(int *)(*(int *)(iVar6 + 0x54) + 0x24) + 0x1c)
    ;
    DAT_0088054c = 0;
    *(undefined1 *)(param_2 + 0x68) = 0;
    *(undefined4 *)(param_2 + 0x9c) = 0;
    DAT_00880558 = 0;
    _DAT_00880568 = 0.0;
    *(undefined1 *)(param_2 + 0x69) = *(undefined1 *)(iVar6 + 0x107f);
  }
  if (4 < *(byte *)(param_2 + 0x68)) {
    *(undefined1 *)(param_2 + 0x68) = 0;
  }
  fVar2 = *(float *)(*(int *)(*(int *)(iVar6 + 0x54) + 0x24) + 0x1c);
  if (*(char *)(DAT_0093d810 + 0x671) == '\x01') {
    if (DAT_0093d814 == 0) {
      fVar10 = (float10)FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar6 + 0x670);
      fVar11 = (float10)FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),DAT_0093d810 + 0x670
                                    );
      fVar11 = (float10)(double)fVar10 - fVar11;
    }
    else {
      fVar10 = (float10)FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),DAT_0093d814 + 0x670
                                    );
      fVar11 = (float10)FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),DAT_0093d810 + 0x670
                                    );
      fVar3 = (float)((float10)(double)fVar10 - fVar11);
      if (fVar3 <= *(float *)(iVar4 + 0x1d4) * 0.5) {
        if (fVar3 < *(float *)(iVar4 + 0x1d4) * -0.5) {
          fVar3 = fVar3 + *(float *)(iVar4 + 0x1d4);
        }
      }
      else {
        fVar3 = fVar3 - *(float *)(iVar4 + 0x1d4);
      }
      iVar8 = DAT_0093d814;
      if (0.0 <= *(float *)(&DAT_007fcda0 + (uint)*(byte *)(param_2 + 0x68) * 0x1c)) {
        if (0.0 >= fVar3) goto LAB_004c940e;
      }
      else if (0.0 < fVar3) {
LAB_004c940e:
        iVar8 = DAT_0093d810;
      }
      fVar10 = (float10)FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar6 + 0x670);
      fVar11 = (float10)FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar8 + 0x670);
      fVar11 = (float10)(double)fVar10 - fVar11;
    }
    local_14 = (float)fVar11;
    if (local_14 <= *(float *)(iVar4 + 0x1d4) * 0.5) {
      if (local_14 < *(float *)(iVar4 + 0x1d4) * -0.5) {
        local_14 = local_14 + *(float *)(iVar4 + 0x1d4);
      }
    }
    else {
      local_14 = local_14 - *(float *)(iVar4 + 0x1d4);
    }
    bVar9 = local_14 < _DAT_007fcd9c;
    if (_DAT_007fcd90 < local_14) {
      FUN_004364e0(iVar6,4,0);
      return 1;
    }
    param_3 = local_14 - *(float *)(&DAT_007fcda0 + (uint)*(byte *)(param_2 + 0x68) * 0x1c);
    if (*(byte *)(param_2 + 0x68) == 0) {
      if (*(float *)(param_2 + 0x9c) < _DAT_007fce18) {
        param_3 = param_3 - _DAT_007fce1c *
                            ((_DAT_007fce18 - *(float *)(param_2 + 0x9c)) / _DAT_007fce18);
      }
      if (_DAT_00880568 < 2.0) {
        DAT_00880558 = 0;
      }
    }
    if (param_3 <= 0.0) goto LAB_004c95dc;
    iVar4 = (uint)*(byte *)(param_2 + 0x68) * 0x1c;
    param_3 = param_3 / *(float *)(&DAT_007fcdb0 + iVar4);
    if (1.0 < param_3) {
      param_3 = 1.0;
    }
    param_3 = *(float *)(&DAT_007fcdb4 + iVar4) * param_3 + (1.0 - param_3);
    uVar7 = *(undefined4 *)(&DAT_007fcdb8 + iVar4);
  }
  else {
    local_14 = 0.0;
    param_3 = 0.0;
LAB_004c95dc:
    iVar4 = (uint)*(byte *)(param_2 + 0x68) * 0x1c;
    param_3 = param_3 / *(float *)(&DAT_007fcda4 + iVar4);
    if (1.0 < param_3) {
      param_3 = 1.0;
    }
    param_3 = *(float *)(&DAT_007fcda8 + iVar4) * param_3 + (1.0 - param_3);
    uVar7 = *(undefined4 *)(&DAT_007fcdac + iVar4);
  }
  fVar10 = (float10)FUN_0054fb40(*(undefined4 *)(iVar6 + 0xed4),param_3 * fVar2,uVar7);
  *(float *)(iVar6 + 0xed4) = (float)fVar10;
  if (*(int *)(param_2 + 0x6c) == 0) {
    if (local_14 <= 0.0) {
      *(undefined4 *)(param_2 + 0x9c) = 0;
    }
    else {
      *(undefined4 *)(param_2 + 0x6c) = 1;
    }
  }
  else {
    _DAT_00880568 = _DAT_00880568 + param_7;
  }
  uVar7 = _DAT_007fce10;
  if ((*(char *)(param_2 + 0x68) != '\x01') && (*(int *)(param_2 + 0x6c) != 0)) {
    uVar7 = 0;
  }
  fVar10 = (float10)FUN_0054fb40(*(undefined4 *)(iVar6 + 0xe88),uVar7,_DAT_007fce14);
  *(float *)(iVar6 + 0xe88) = (float)fVar10;
  if ((int)*(char *)(iVar6 + 0x107f) < (int)(uint)*(byte *)(param_2 + 0x69)) {
    DAT_00880558 = DAT_00880558 + 1;
    *(undefined1 *)(param_2 + 0x69) = *(undefined1 *)(iVar6 + 0x107f);
  }
  if (*(char *)(iVar6 + 0x7b5) == -1) {
    if (*(char *)(param_2 + 0x68) != (char)DAT_0088054c) {
      *(char *)(param_2 + 0x68) = (char)DAT_0088054c;
      if (DAT_0088054c == 1) {
        *(undefined4 *)(param_2 + 0x9c) = 0x3e800000;
      }
      else {
        *(undefined4 *)(param_2 + 0x9c) = 0;
      }
    }
    switch(*(undefined1 *)(param_2 + 0x68)) {
    case 0:
      if (DAT_007fcd84 == 0) {
        *(undefined4 *)(param_2 + 0x9c) = 0;
        return 0;
      }
      if (((_DAT_007fcda0 * 0.8 < local_14) || (0.0 < *(float *)(param_2 + 0x9c))) &&
         ((1 < DAT_00880558 ||
          (param_7 = *(float *)(param_2 + 0x9c) + param_7, *(float *)(param_2 + 0x9c) = param_7,
          _DAT_007fcd88 < param_7)))) {
        FUN_004c9260();
        puVar1 = (uint *)(*(int *)(iVar6 + 0xca4) + 8);
        *puVar1 = *puVar1 | DAT_00802278;
        return 0;
      }
      break;
    case 1:
      if (DAT_007fcd84 == 0) {
LAB_004c9930:
        uVar7 = FUN_004c9260();
        return uVar7;
      }
      if (local_14 < 0.0) {
        FUN_004c9260();
        return 0;
      }
      param_7 = *(float *)(param_2 + 0x9c) - param_7;
      *(float *)(param_2 + 0x9c) = param_7;
      if (((param_7 <= 0.0) && (param_7 < -1.0)) && (*(char *)(DAT_0093d810 + 0x7b5) == '6')) {
        FUN_004c9260();
        return 0;
      }
      break;
    case 2:
      if (DAT_007fcd84 == 0) goto LAB_004c9930;
      if (*(char *)(DAT_0093d810 + 0x7b5) == '6') {
        FUN_004c9260();
      }
      if (0.0 < _DAT_007fcd98) {
        param_7 = *(float *)(param_2 + 0x9c) - param_7;
        *(float *)(param_2 + 0x9c) = param_7;
        if (param_7 < 0.0 != (param_7 == 0.0)) {
          fVar10 = (float10)FUN_005b9dd0();
          *(float *)(param_2 + 0x9c) =
               (float)((float10)_DAT_007fcd98 * (float10)0.5 + (float10)_DAT_007fcd98 * fVar10);
          if (bVar9) {
            puVar1 = (uint *)(*(int *)(iVar6 + 0xca4) + 8);
            *puVar1 = *puVar1 | DAT_0080227c;
            return 0;
          }
        }
      }
      break;
    case 3:
      if ((2 < DAT_00880558) ||
         (param_7 = *(float *)(param_2 + 0x9c) + param_7, *(float *)(param_2 + 0x9c) = param_7,
         _DAT_007fcd8c < param_7)) {
        uVar7 = FUN_004c9260();
        return uVar7;
      }
    }
  }
  return 0;
}

