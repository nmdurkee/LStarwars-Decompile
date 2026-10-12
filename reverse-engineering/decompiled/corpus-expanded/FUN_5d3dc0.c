/* Ghidra pseudocode, not original source.
 * ev_feeb0d300fc0a1ec823458f778250bd56b5f3fc24779efc17b7484c96bfb9aef
 * Entry: 0x5d3dc0; label: FUN_005d3dc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_005d3dc0(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                   undefined4 param_6,float param_7)

{
  void *_Dst;
  int iVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  char *pcVar6;
  float10 fVar7;
  float10 fVar8;
  undefined8 uVar9;
  float *local_6c;
  char *local_68;
  int local_64;
  int local_60;
  int local_50;
  int local_48;
  int local_44;
  undefined1 local_30 [24];
  undefined1 local_18 [24];
  
  _Dst = (void *)0x0;
  local_48 = 0;
  local_6c = (float *)0x0;
  local_44 = 0;
  local_68 = (char *)0x0;
  if (((param_3 != 0) || (param_5 != 0)) && (param_1 != 0)) {
    if (param_3 != 0) {
      FUN_005c9c40(param_3,param_4,local_30);
    }
    if (param_5 != 0) {
      FUN_005c9c40(param_5,param_6,local_18);
    }
    if (param_2 == 0) {
      param_1 = 1;
    }
    _Dst = (void *)FUN_005fe5e0(param_1);
    _memset(_Dst,0,param_1 * 4 + 0xfU >> 4);
    if ((_Dst != (void *)0x0) && (local_50 = 0, 0 < param_1)) {
      do {
        if ((param_2 == 0) || (-1 < *(short *)(param_2 + local_50 * 2))) {
          if (param_3 == 0) {
LAB_005d3eee:
            local_64 = 0;
          }
          else {
            uVar9 = FUN_005ca450(param_3);
            iVar1 = (int)((ulonglong)uVar9 >> 0x20);
            if ((int)uVar9 <= iVar1) goto LAB_005d3eee;
            local_64 = (int)*(short *)(param_3 + 6);
            iVar1 = local_64 * iVar1;
            local_48 = *(int *)(param_3 + 0xc) + iVar1 * 4;
            local_44 = *(int *)(param_3 + 0x10) + iVar1;
          }
          if (param_5 == 0) {
LAB_005d3f27:
            local_60 = 0;
          }
          else {
            uVar9 = FUN_005ca450(param_5);
            iVar1 = (int)((ulonglong)uVar9 >> 0x20);
            if ((int)uVar9 <= iVar1) goto LAB_005d3f27;
            local_60 = (int)*(short *)(param_5 + 6);
            iVar1 = local_60 * iVar1;
            local_6c = (float *)(*(int *)(param_5 + 0xc) + iVar1 * 4);
            local_68 = (char *)(*(int *)(param_5 + 0x10) + iVar1);
          }
          iVar1 = local_60;
          if (local_60 < local_64) {
            iVar1 = local_64;
          }
          iVar2 = FUN_005fe5a0(iVar1);
          *(int *)((int)_Dst + local_50 * 4) = iVar2;
          if ((iVar2 != 0) && (iVar3 = 0, 0 < iVar1)) {
            pfVar4 = (float *)(iVar2 + 8);
            pfVar5 = local_6c;
            pcVar6 = local_68;
            do {
              if (iVar3 < local_64) {
                if (pcVar6[local_44 - (int)local_68] == '\0') {
                  fVar7 = (float10)*(float *)((local_48 - (int)local_6c) + (int)pfVar5);
                }
                else {
                  fVar7 = (float10)FUN_005c9520((local_48 - (int)local_6c) + (int)pfVar5,local_30,
                                                (int)pcVar6[local_44 - (int)local_68]);
                }
              }
              else {
                fVar7 = (float10)0;
              }
              if (iVar3 < local_60) {
                if (*pcVar6 == '\0') {
                  fVar8 = (float10)*pfVar5;
                }
                else {
                  fVar8 = (float10)FUN_005c9520(pfVar5,local_18,(int)*pcVar6);
                }
              }
              else {
                fVar8 = (float10)0;
              }
              iVar3 = iVar3 + 1;
              pcVar6 = pcVar6 + 1;
              pfVar5 = pfVar5 + 1;
              *pfVar4 = (float)fVar7 * (1.0 - param_7) + (float)fVar8 * param_7;
              pfVar4 = pfVar4 + 1;
            } while (iVar3 < iVar1);
          }
        }
        local_50 = local_50 + 1;
        if (param_1 <= local_50) {
          return _Dst;
        }
      } while( true );
    }
  }
  return _Dst;
}

