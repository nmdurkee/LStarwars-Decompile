/* Ghidra pseudocode, not original source.
 * ev_be89c5742567956971c64ab2441aea6b3f78c2cf42a7c801ad7bb364f9087e2c
 * Entry: 0x62e290; label: FUN_0062e290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062e290(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_64 [4];
  undefined4 local_60;
  float fStack_5c;
  undefined4 *local_58;
  int iStack_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_64;
  local_60 = param_4;
  local_48 = param_6;
  local_4c = param_3;
  local_58 = param_5;
  local_50 = param_7;
  iStack_54 = (*(code *)PTR_FUN_0080fb94)(param_1,local_44,param_8);
  if (iStack_54 < 1) goto LAB_0062e5d2;
  if (param_5 != (undefined4 *)0x0) {
    cVar2 = *(char *)((int)param_2 + 0x31);
    if (cVar2 == '\0') {
LAB_0062e415:
      if (((-1 < *(short *)((int)param_2 + 0x36)) &&
          (iVar6 = (int)*(short *)((int)param_2 + 0x36), iVar6 < *(int *)(DAT_029130e4 + 8))) &&
         (*(int *)(*(int *)(param_1 + 0x10) + iVar6 * 4) != 0)) {
        uVar3 = FUN_005d3a20(iStack_54,local_44,
                             *(undefined4 *)(*(int *)(param_1 + 0x10) + iVar6 * 4),*param_2);
        *param_5 = uVar3;
        goto LAB_0062e458;
      }
    }
    else {
      if (-1 < *(short *)((int)param_2 + 0x32)) {
        iVar6 = (int)*(short *)((int)param_2 + 0x32);
        param_5 = local_58;
        if (iVar6 < *(int *)(DAT_029130e4 + 8)) {
          iVar1 = *(int *)(param_1 + 0x10);
          if ((((*(int *)(iVar1 + iVar6 * 4) != 0) && (-1 < *(short *)(param_2 + 0xd))) &&
              (iVar5 = (int)*(short *)(param_2 + 0xd), iVar5 < *(int *)(DAT_029130e4 + 8))) &&
             (*(int *)(iVar1 + iVar5 * 4) != 0)) {
            fStack_5c = (float)param_2[2] / (float)param_2[3];
            uVar3 = FUN_005d3dc0(iStack_54,local_44,*(undefined4 *)(iVar1 + iVar6 * 4),param_2[4],
                                 *(undefined4 *)(iVar1 + iVar5 * 4),param_2[5],fStack_5c);
            *local_58 = uVar3;
            goto LAB_0062e458;
          }
          cVar2 = *(char *)((int)param_2 + 0x31);
        }
      }
      if (cVar2 == '\0') goto LAB_0062e415;
      if (((-1 < *(short *)(param_2 + 0xd)) &&
          (iVar6 = (int)*(short *)(param_2 + 0xd), iVar6 < *(int *)(DAT_029130e4 + 8))) &&
         (puVar4 = (undefined4 *)(*(int *)(param_1 + 0x10) + iVar6 * 4),
         *(int *)(*(int *)(param_1 + 0x10) + iVar6 * 4) != 0)) {
        uVar3 = param_2[5];
LAB_0062e3f8:
        uVar3 = FUN_005d3a20(iStack_54,local_44,*puVar4,uVar3);
        *param_5 = uVar3;
        goto LAB_0062e458;
      }
      if (cVar2 == '\0') goto LAB_0062e415;
      if (((-1 < *(short *)((int)param_2 + 0x32)) &&
          (iVar6 = (int)*(short *)((int)param_2 + 0x32), iVar6 < *(int *)(DAT_029130e4 + 8))) &&
         (puVar4 = (undefined4 *)(*(int *)(param_1 + 0x10) + iVar6 * 4),
         *(int *)(*(int *)(param_1 + 0x10) + iVar6 * 4) != 0)) {
        uVar3 = param_2[4];
        goto LAB_0062e3f8;
      }
      if (cVar2 == '\0') goto LAB_0062e415;
    }
    *param_5 = 0;
  }
LAB_0062e458:
  cVar2 = *(char *)((int)param_2 + 0x31);
  if ((cVar2 == '\0') || (*(short *)((int)param_2 + 0x32) < 0)) {
LAB_0062e4ee:
    if (cVar2 == '\0') {
LAB_0062e562:
      if (((*(short *)((int)param_2 + 0x36) < 0) ||
          (iVar6 = (int)*(short *)((int)param_2 + 0x36), *(int *)(DAT_029130e4 + 8) <= iVar6)) ||
         (*(int *)(*(int *)(param_1 + 0xc) + iVar6 * 4) == 0)) {
LAB_0062e59f:
        FUN_005d36d0(*(undefined4 *)(param_1 + 4),0,0,local_60);
      }
      else {
        FUN_005f38c0(*(undefined4 *)(param_1 + 4),
                     *(undefined4 *)(*(int *)(param_1 + 0xc) + iVar6 * 4),*param_2,0,0,local_60);
      }
    }
    else {
      if (((*(short *)(param_2 + 0xd) < 0) ||
          (iVar6 = (int)*(short *)(param_2 + 0xd), *(int *)(DAT_029130e4 + 8) <= iVar6)) ||
         (puVar4 = (undefined4 *)(*(int *)(param_1 + 0xc) + iVar6 * 4),
         *(int *)(*(int *)(param_1 + 0xc) + iVar6 * 4) == 0)) {
        if (cVar2 == '\0') goto LAB_0062e562;
        if (((-1 < *(short *)((int)param_2 + 0x32)) &&
            (iVar6 = (int)*(short *)((int)param_2 + 0x32), iVar6 < *(int *)(DAT_029130e4 + 8))) &&
           (puVar4 = (undefined4 *)(*(int *)(param_1 + 0xc) + iVar6 * 4),
           *(int *)(*(int *)(param_1 + 0xc) + iVar6 * 4) != 0)) {
          uVar3 = param_2[4];
          goto LAB_0062e540;
        }
        if (cVar2 == '\0') goto LAB_0062e562;
        goto LAB_0062e59f;
      }
      uVar3 = param_2[5];
LAB_0062e540:
      FUN_005f38c0(*(undefined4 *)(param_1 + 4),*puVar4,uVar3,0,0,local_60);
    }
  }
  else {
    iVar6 = (int)*(short *)((int)param_2 + 0x32);
    if (*(int *)(DAT_029130e4 + 8) <= iVar6) goto LAB_0062e4ee;
    iVar1 = *(int *)(param_1 + 0xc);
    if (((*(int *)(iVar1 + iVar6 * 4) == 0) || (*(short *)(param_2 + 0xd) < 0)) ||
       ((iVar5 = (int)*(short *)(param_2 + 0xd), *(int *)(DAT_029130e4 + 8) <= iVar5 ||
        (*(int *)(iVar1 + iVar5 * 4) == 0)))) {
      cVar2 = *(char *)((int)param_2 + 0x31);
      goto LAB_0062e4ee;
    }
    fStack_5c = (float)param_2[2] / (float)param_2[3];
    FUN_005f38f0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(iVar1 + iVar6 * 4),param_2[4],
                 *(undefined4 *)(iVar1 + iVar5 * 4),param_2[5],fStack_5c,0,0,local_60);
  }
  FUN_0062e1e0(param_1,local_4c,local_60,local_48,local_50);
LAB_0062e5d2:
  __security_check_cookie(local_4 ^ (uint)auStack_64);
  return;
}

