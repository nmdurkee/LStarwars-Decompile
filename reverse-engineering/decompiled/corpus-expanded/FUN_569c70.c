/* Ghidra pseudocode, not original source.
 * ev_b978e2ca46034d20a029bc1dc30b8253616b522a4771dca24a925efe269276a9
 * Entry: 0x569c70; label: FUN_00569c70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00569c70(int param_1,int param_2,int param_3,undefined4 param_4,float *param_5,
                float *param_6,int param_7,int param_8,undefined4 param_9)

{
  float *pfVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  int local_28;
  float local_20;
  int local_1c;
  undefined1 auStack_c [12];
  
  uVar7 = DAT_009507ac & 2;
  uVar4 = DAT_009507ac & 1;
  bVar3 = false;
  if ((param_1 != 0) &&
     (bVar3 = true, *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x28) <= 0.0)) {
    bVar3 = false;
  }
  iVar9 = *(int *)(PTR_DAT_00802c54 + 0x50c8);
  if (iVar9 == 0) {
    return 0;
  }
  local_20 = 1e+06;
  local_28 = 0;
  local_1c = 0;
  if (0 < *(int *)(PTR_DAT_00802c54 + 0x50c0)) {
    do {
      uVar2 = *(uint *)(iVar9 + 0x94);
      if ((((((uVar2 & 1) == 0) && ((uVar2 & 0x800000) != 0)) && ((uVar2 & 0x4000) != 0)) &&
          (((uVar4 == 0 || ((*(uint *)(iVar9 + 0x98) & 0x80000) == 0)) || (!bVar3)))) &&
         ((((uVar7 == 0 || ((*(uint *)(iVar9 + 0x98) & 0x200000) == 0)) ||
           (((param_8 != 8 && (param_8 != 9)) ||
            ((DAT_00950bbc == (code *)0x0 || (iVar5 = (*DAT_00950bbc)(iVar9,param_8), iVar5 == 0))))
           )) && ((param_7 == 0 ||
                  (((*(short *)(iVar9 + 0x102) == -1 && ((*(uint *)(iVar9 + 0x98) & 0x8000) != 0))
                   && (((*(uint *)(iVar9 + 0x98) & 0x80000) == 0 ||
                       ((param_1 != 0 && (*(int *)(param_1 + 0xcd0) != 0)))))))))))) {
        if (param_8 == 0) {
          if ((*(uint *)(iVar9 + 0x98) & 0x10000) != 0) {
LAB_00569dd9:
            if (((((((*(uint *)(iVar9 + 0x98) & 0x20) == 0) || (DAT_0087baf0 != 0)) &&
                  ((uint)(param_8 == 7) == (*(uint *)(iVar9 + 0x98) >> 6 & 1))) &&
                 ((pfVar1 = (float *)(iVar9 + 0x4c), *pfVar1 - *(float *)(iVar9 + 0xa8) <= *param_6
                  && (*param_5 <= *(float *)(iVar9 + 0xa8) + *pfVar1)))) &&
                ((*(float *)(iVar9 + 0x54) - *(float *)(iVar9 + 0xa8) <= param_6[2] &&
                 ((param_5[2] <= *(float *)(iVar9 + 0x54) + *(float *)(iVar9 + 0xa8) &&
                  (*(float *)(iVar9 + 0x50) - *(float *)(iVar9 + 0xa8) <= param_6[1])))))) &&
               ((param_5[1] <= *(float *)(iVar9 + 0x50) + *(float *)(iVar9 + 0xa8) &&
                (iVar5 = param_3 + -1, -1 < iVar5)))) {
              iVar8 = param_2 + iVar5 * 0xc;
              do {
                iVar6 = FUN_0054fc70(pfVar1,*(undefined4 *)(iVar9 + 0xa8),iVar8,param_4);
                if (iVar6 != 0) {
                  if (param_1 == 0) {
                    iVar5 = param_2 + iVar5 * 0xc;
                  }
                  else {
                    iVar5 = param_1 + 0x80;
                  }
                  fVar10 = (float10)FUN_005b3c50(iVar5,pfVar1,0);
                  if ((float)fVar10 < local_20) {
                    local_28 = iVar9;
                    local_20 = (float)fVar10;
                  }
                  break;
                }
                iVar5 = iVar5 + -1;
                iVar8 = iVar8 + -0xc;
              } while (-1 < iVar5);
            }
          }
        }
        else if ((param_8 != 3) || ((*(uint *)(iVar9 + 0x98) & 0x200000) == 0)) goto LAB_00569dd9;
      }
      local_1c = local_1c + 1;
      iVar9 = iVar9 + 0x114;
    } while (local_1c < *(int *)(PTR_DAT_00802c54 + 0x50c0));
    if (local_28 != 0) {
      if ((param_8 == 2) || (param_8 == 7)) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = 1;
        if (param_7 != 0) {
          iVar9 = FUN_005806a0(*(undefined1 *)(param_7 + 0x101),PTR_DAT_00802c54);
          uVar4 = (uint)*(byte *)(iVar9 + 0x3c);
          iVar9 = FUN_0056e0f0(2);
          if ((iVar9 != 0) && ((*(byte *)(param_7 + 0xf0) & 3) != 0)) {
            uVar4 = uVar4 * 2;
          }
        }
      }
      if (param_8 == 3) {
        iVar9 = 10;
      }
      else if ((param_8 == 2) || (param_8 == 7)) {
        iVar9 = 9;
      }
      else {
        iVar9 = (-(uint)(param_8 != 0) & 0xfffffff6) + 0xd;
      }
      iVar9 = FUN_00567800(local_28,1,iVar9,uVar4,0,1);
      if (iVar9 == 0) {
        if (param_7 != 0) {
          FUN_005b3800(auStack_c,local_28 + 0x30,param_7 + 0x88);
          FUN_005b3b30(auStack_c,auStack_c);
          FUN_0057fc80(param_7,param_7 + 0xac,auStack_c,param_9);
        }
      }
      else if (param_1 != 0) {
        FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3ecccccd,0);
        FUN_00549f10();
      }
      if (*(int *)(PTR_PTR_008040bc + 8) != 0) {
        (**(code **)(PTR_PTR_008040bc + 8))(param_1,param_2);
      }
    }
  }
  return local_28;
}

