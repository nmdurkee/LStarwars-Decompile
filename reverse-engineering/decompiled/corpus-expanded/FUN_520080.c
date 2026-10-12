/* Ghidra pseudocode, not original source.
 * ev_b2a783233b211c47b682189f4533ad6a7c38bd84c0deaf183226d349bdd9b928
 * Entry: 0x520080; label: FUN_00520080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00520080(int param_1,float param_2,int param_3,float param_4,undefined4 param_5,int param_6
                 ,float param_7,int param_8)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float local_14;
  undefined1 local_c [12];
  
  iVar2 = (int)param_2;
  local_14 = 0.0;
  iVar4 = -1;
  if (((param_2 != 0.0) && (param_3 != 0)) && (*(int *)(param_3 + 4) != 0)) {
    if (param_8 != 0) {
      FUN_0051fe60(param_1,param_2);
    }
    iVar6 = 0;
    if ('\0' < *(char *)((int)param_2 + 0x10)) {
      do {
        if ((param_8 == 0) || (*(char *)(iVar6 + *(int *)(iVar2 + 0x18)) == -1)) {
          iVar7 = *(int *)(param_1 + 0x28) + (uint)*(byte *)(*(int *)(iVar2 + 0x14) + iVar6) * 0x3c;
          if ((param_7 == 0.0) ||
             (iVar3 = FUN_005d6620(iVar7 + 0x10,param_7,&DAT_00806680), iVar5 = iVar4,
             fVar1 = local_14, iVar3 != 0)) {
            iVar7 = iVar7 + 0x10;
            fVar8 = (float10)FUN_005b3c50(param_5,iVar7,local_c);
            param_2 = (float)fVar8;
            if (local_14 < param_2) {
              if (param_6 != 0) {
                fVar8 = (float10)FUN_005b3c50(param_6,iVar7,local_c);
                fVar1 = (float)fVar8;
                if (fVar1 <= local_14) goto LAB_005201bf;
                if (fVar1 < param_2) {
                  param_2 = fVar1;
                }
              }
              iVar5 = iVar6;
              fVar1 = param_2;
              if ((param_4 == 0.0) || (fVar1 = param_2, param_2 < param_4 * param_4))
              goto LAB_005201c1;
            }
            goto LAB_005201bf;
          }
        }
        else {
LAB_005201bf:
          iVar5 = iVar4;
          fVar1 = local_14;
        }
LAB_005201c1:
        local_14 = fVar1;
        iVar6 = iVar6 + 1;
        iVar4 = iVar5;
      } while (iVar6 < *(char *)(iVar2 + 0x10));
      if (iVar5 != -1) {
        *(uint *)(*(int *)(param_3 + 4) + 0xa4) =
             *(int *)(param_1 + 0x28) + (uint)*(byte *)(*(int *)(iVar2 + 0x14) + iVar5) * 0x3c;
        *(undefined1 *)(*(int *)(iVar2 + 0x18) + iVar5) = *(undefined1 *)(param_3 + 0x28d);
      }
    }
  }
  return;
}

