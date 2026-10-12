/* Ghidra pseudocode, not original source.
 * ev_feeb0d300fc0a1ec823458f778250bd56b5f3fc24779efc17b7484c96bfb9aef
 * Entry: 0x5d3b80; label: FUN_005d3b80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_005d3b80(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                   undefined4 param_6,float param_7)

{
  int *piVar1;
  int iVar2;
  void *_Dst;
  int iVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  int local_50;
  int local_4c;
  int local_40;
  undefined1 local_30 [8];
  int local_28;
  undefined1 local_18 [8];
  int local_10;
  
  _Dst = (void *)0x0;
  if (((param_3 != 0) || (param_5 != 0)) && (param_1 != 0)) {
    if (param_3 != 0) {
      FUN_005c9b60(param_3,param_4,local_30);
    }
    if (param_5 != 0) {
      FUN_005c9b60(param_5,param_6,local_18);
    }
    if (param_2 == 0) {
      param_1 = 1;
    }
    _Dst = (void *)FUN_005fe5e0(param_1);
    _memset(_Dst,0,param_1 * 4 + 0xfU >> 4);
    if ((_Dst != (void *)0x0) && (local_40 = 0, 0 < param_1)) {
      do {
        iVar6 = 0;
        if (param_2 == 0) {
          iVar7 = 0;
LAB_005d3c40:
          if (((param_3 == 0) ||
              (piVar1 = *(int **)(*(int *)(param_3 + 0xc) + local_28 * 4), *piVar1 <= iVar7)) ||
             (iVar5 = piVar1[2], *(int *)(iVar5 + iVar7 * 4) == 0)) {
            local_50 = 0;
          }
          else {
            local_50 = (int)*(char *)(*(int *)(iVar5 + iVar7 * 4) + 0xc);
          }
          if (((param_5 == 0) ||
              (piVar1 = *(int **)(*(int *)(param_5 + 0xc) + local_10 * 4), *piVar1 <= iVar7)) ||
             (iVar5 = piVar1[2], *(int *)(iVar5 + iVar7 * 4) == 0)) {
            local_4c = 0;
          }
          else {
            local_4c = (int)*(char *)(*(int *)(iVar5 + iVar7 * 4) + 0xc);
          }
          iVar5 = local_50;
          if (local_50 <= local_4c) {
            iVar5 = local_4c;
          }
          iVar3 = FUN_005fe5a0(iVar5);
          *(int *)((int)_Dst + local_40 * 4) = iVar3;
          if ((iVar3 != 0) && (0 < iVar5)) {
            pfVar4 = (float *)(iVar3 + 8);
            do {
              if (iVar6 < local_50) {
                iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_3 + 0xc) + local_28 * 4) + 8) +
                                iVar7 * 4);
                iVar2 = *(int *)(iVar3 + 8);
                if (*(int *)(iVar2 + iVar6 * 4) == 0) {
                  fVar8 = (float10)*(float *)(*(int *)(iVar3 + 4) + iVar6 * 4);
                }
                else {
                  fVar8 = (float10)FUN_005c91c0(*(undefined4 *)(iVar2 + iVar6 * 4),local_30);
                }
              }
              else {
                fVar8 = (float10)0;
              }
              if (iVar6 < local_4c) {
                iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_5 + 0xc) + local_10 * 4) + 8) +
                                iVar7 * 4);
                iVar2 = *(int *)(iVar3 + 8);
                if (*(int *)(iVar2 + iVar6 * 4) == 0) {
                  fVar9 = (float10)*(float *)(*(int *)(iVar3 + 4) + iVar6 * 4);
                }
                else {
                  fVar9 = (float10)FUN_005c91c0(*(undefined4 *)(iVar2 + iVar6 * 4),local_18);
                }
              }
              else {
                fVar9 = (float10)0;
              }
              iVar6 = iVar6 + 1;
              *pfVar4 = (float)fVar8 * (1.0 - param_7) + (float)fVar9 * param_7;
              pfVar4 = pfVar4 + 1;
            } while (iVar6 < iVar5);
          }
        }
        else {
          iVar7 = (int)*(short *)(param_2 + local_40 * 2);
          if (-1 < iVar7) goto LAB_005d3c40;
        }
        local_40 = local_40 + 1;
        if (param_1 <= local_40) {
          return _Dst;
        }
      } while( true );
    }
  }
  return _Dst;
}

