/* Ghidra pseudocode, not original source.
 * ev_feeb0d300fc0a1ec823458f778250bd56b5f3fc24779efc17b7484c96bfb9aef
 * Entry: 0x5d3a20; label: FUN_005d3a20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_005d3a20(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  void *_Dst;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  int local_24;
  undefined1 local_18 [24];
  
  _Dst = (void *)0x0;
  if ((param_3 != 0) && (param_1 != 0)) {
    FUN_005c9c40(param_3,param_4,local_18);
    if (param_2 == 0) {
      param_1 = 1;
    }
    _Dst = (void *)FUN_005fe5e0(param_1);
    _memset(_Dst,0,param_1 * 4 + 0xfU >> 4);
    if ((_Dst != (void *)0x0) && (local_24 = 0, 0 < param_1)) {
      do {
        if (param_2 == 0) {
          iVar7 = 0;
LAB_005d3adc:
          iVar9 = (int)*(short *)(param_3 + 6);
          iVar4 = FUN_005fe5a0(iVar9);
          *(int *)((int)_Dst + local_24 * 4) = iVar4;
          iVar2 = *(int *)(param_3 + 0x10);
          iVar7 = *(short *)(param_3 + 6) * iVar7;
          pfVar5 = (float *)(*(int *)(param_3 + 0xc) + iVar7 * 4);
          if ((iVar4 != 0) && (iVar8 = 0, 0 < iVar9)) {
            pfVar6 = (float *)(iVar4 + 8);
            do {
              cVar1 = *(char *)(iVar8 + iVar2 + iVar7);
              if (cVar1 == '\0') {
                fVar10 = (float10)*pfVar5;
              }
              else {
                fVar10 = (float10)FUN_005c9520(pfVar5,local_18,(int)cVar1);
              }
              iVar8 = iVar8 + 1;
              pfVar5 = pfVar5 + 1;
              *pfVar6 = (float)fVar10;
              pfVar6 = pfVar6 + 1;
            } while (iVar8 < iVar9);
          }
        }
        else {
          iVar7 = (int)*(short *)(param_2 + local_24 * 2);
          if (-1 < iVar7) {
            iVar2 = FUN_005ca450(param_3);
            if (iVar7 < iVar2) goto LAB_005d3adc;
            uVar3 = FUN_005fe5a0(0);
            *(undefined4 *)((int)_Dst + local_24 * 4) = uVar3;
          }
        }
        local_24 = local_24 + 1;
      } while (local_24 < param_1);
    }
  }
  return _Dst;
}

