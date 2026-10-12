/* Ghidra pseudocode, not original source.
 * ev_a2aea1d641189bbcca45d714e231c7fbe07e1298025184ba29836f60d860e436
 * Entry: 0x5e9300; label: FUN_005e9300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float * FUN_005e9300(undefined4 param_1)

{
  size_t _Size;
  int iVar1;
  char cVar2;
  int iVar3;
  float fVar4;
  float *_Dst;
  int *piVar5;
  void *_Dst_00;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  float10 fVar9;
  float local_10;
  int local_4;
  
  if (DAT_00973868 == 0) {
    FUN_005c9140();
  }
  iVar3 = FUN_004fb750(param_1);
  if (iVar3 == 0) {
    local_10 = 0.0;
  }
  else {
    local_10 = (float)FUN_004eef40(iVar3,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",
                                   0x43f);
    FUN_004fb550(param_1,local_10,iVar3);
  }
  fVar9 = (float10)FUN_004fb730(param_1);
  fVar4 = (float)FUN_004fb750(param_1);
  _Size = (int)fVar4 * 4 + 0x10;
  _Dst = (float *)FUN_004eef40(_Size,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",0x4bb);
  _memset(_Dst,0,_Size);
  *_Dst = (float)fVar9;
  _Dst[3] = (float)(_Dst + 4);
  _Dst[2] = fVar4;
  _Dst[1] = local_10;
  local_10 = 0.0;
  if ((int)fVar4 < 1) {
    return _Dst;
  }
  do {
    iVar3 = FUN_004fb750(param_1);
    piVar5 = (int *)FUN_004eef40(0x14,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",0x4a8)
    ;
    piVar5[1] = 0;
    piVar5[2] = 0;
    piVar5[3] = 0;
    piVar5[4] = 0;
    *piVar5 = iVar3;
    _Dst_00 = (void *)FUN_004eef40(iVar3 * 4,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c"
                                   ,0x4ac);
    piVar5[2] = (int)_Dst_00;
    _memset(_Dst_00,0,iVar3 * 4);
    *(int **)((int)_Dst[3] + (int)local_10 * 4) = piVar5;
    piVar5 = *(int **)((int)_Dst[3] + (int)local_10 * 4);
    *piVar5 = iVar3;
    iVar6 = FUN_004fb750(param_1);
    if (iVar6 == 0) {
      piVar5[3] = 0;
    }
    else {
      iVar7 = FUN_004eef40(iVar6 << 4,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",0x459)
      ;
      piVar5[3] = iVar7;
      FUN_004fb550(param_1,iVar7,iVar6 << 4);
    }
    local_4 = piVar5[3];
    iVar6 = FUN_004fb750(param_1);
    if (iVar6 == 0) {
      piVar5[4] = 0;
    }
    else {
      iVar7 = FUN_004eef40(iVar6 << 4,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",0x466)
      ;
      piVar5[4] = iVar7;
      FUN_004fb550(param_1,iVar7,iVar6 << 4);
    }
    iVar6 = 0;
    if (0 < iVar3) {
      do {
        cVar2 = FUN_004fb7f0(param_1);
        if (cVar2 != 0) {
          uVar8 = FUN_005c9e70((int)cVar2);
          *(undefined4 *)(piVar5[2] + iVar6 * 4) = uVar8;
          uVar8 = FUN_004fb750(param_1);
          **(undefined4 **)(piVar5[2] + iVar6 * 4) = uVar8;
          iVar7 = 0;
          if ('\0' < *(char *)(*(int *)(piVar5[2] + iVar6 * 4) + 0xc)) {
            do {
              fVar9 = (float10)FUN_004fb730(param_1);
              *(float *)(*(int *)(*(int *)(piVar5[2] + iVar6 * 4) + 4) + iVar7 * 4) = (float)fVar9;
              iVar7 = iVar7 + 1;
            } while (iVar7 < *(char *)(*(int *)(piVar5[2] + iVar6 * 4) + 0xc));
          }
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar3);
    }
    iVar3 = piVar5[4];
    iVar6 = 0;
    if (0 < *piVar5) {
      do {
        if ((*(int *)(piVar5[2] + iVar6 * 4) != 0) &&
           (iVar7 = 0, '\0' < *(char *)(*(int *)(piVar5[2] + iVar6 * 4) + 0xc))) {
          do {
            iVar1 = *(int *)(piVar5[2] + iVar6 * 4);
            if (*(float *)(*(int *)(iVar1 + 4) + iVar7 * 4) == 3.4028235e+38) {
              *(int *)(*(int *)(iVar1 + 8) + iVar7 * 4) = iVar3;
              piVar5[1] = piVar5[1] + 1;
              *(int *)(iVar3 + 4) = local_4;
              local_4 = local_4 + *(int *)(iVar3 + 8) * 0x10;
              iVar3 = iVar3 + 0x10;
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < *(char *)(*(int *)(piVar5[2] + iVar6 * 4) + 0xc));
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < *piVar5);
    }
    local_10 = (float)((int)local_10 + 1);
  } while ((int)local_10 < (int)_Dst[2]);
  return _Dst;
}

