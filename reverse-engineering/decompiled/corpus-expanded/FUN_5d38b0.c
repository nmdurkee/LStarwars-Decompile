/* Ghidra pseudocode, not original source.
 * ev_feeb0d300fc0a1ec823458f778250bd56b5f3fc24779efc17b7484c96bfb9aef
 * Entry: 0x5d38b0; label: FUN_005d38b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_005d38b0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  void *_Dst;
  undefined4 uVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  int local_1c;
  undefined1 local_18 [8];
  int local_10;
  
  _Dst = (void *)0x0;
  if ((param_3 != 0) && (param_1 != 0)) {
    FUN_005c9b60(param_3,param_4,local_18);
    if (param_2 == 0) {
      param_1 = 1;
    }
    _Dst = (void *)FUN_005fe5e0(param_1);
    _memset(_Dst,0,param_1 * 4 + 0xfU >> 4);
    if (_Dst == (void *)0x0) {
      return (void *)0x0;
    }
    local_1c = 0;
    if (0 < param_1) {
      do {
        if (param_2 == 0) {
          iVar7 = 0;
LAB_005d396d:
          iVar3 = *(int *)(*(int *)(*(int *)(param_3 + 0xc) + local_10 * 4) + 8);
          if (*(int *)(iVar3 + iVar7 * 4) == 0) {
LAB_005d3959:
            uVar2 = FUN_005fe5a0(0);
            *(undefined4 *)((int)_Dst + local_1c * 4) = uVar2;
          }
          else {
            iVar5 = (int)*(char *)(*(int *)(iVar3 + iVar7 * 4) + 0xc);
            iVar3 = FUN_005fe5a0(iVar5);
            *(int *)((int)_Dst + local_1c * 4) = iVar3;
            if ((iVar3 != 0) && (iVar6 = 0, 0 < iVar5)) {
              pfVar4 = (float *)(iVar3 + 8);
              do {
                iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_3 + 0xc) + local_10 * 4) + 8) +
                                iVar7 * 4);
                iVar1 = *(int *)(iVar3 + 8);
                if (*(int *)(iVar1 + iVar6 * 4) == 0) {
                  fVar8 = (float10)*(float *)(*(int *)(iVar3 + 4) + iVar6 * 4);
                }
                else {
                  fVar8 = (float10)FUN_005c91c0(*(undefined4 *)(iVar1 + iVar6 * 4),local_18);
                }
                *pfVar4 = (float)fVar8;
                iVar6 = iVar6 + 1;
                pfVar4 = pfVar4 + 1;
              } while (iVar6 < iVar5);
            }
          }
        }
        else {
          iVar7 = (int)*(short *)(param_2 + local_1c * 2);
          if (-1 < iVar7) {
            if (iVar7 < **(int **)(*(int *)(param_3 + 0xc) + local_10 * 4)) goto LAB_005d396d;
            goto LAB_005d3959;
          }
        }
        local_1c = local_1c + 1;
      } while (local_1c < param_1);
    }
  }
  return _Dst;
}

