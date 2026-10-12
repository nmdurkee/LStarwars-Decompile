/* Ghidra pseudocode, not original source.
 * ev_ab45728ea6dd43502824c472d7f84a4237b6985bbd98dd18e4509cbe0b313452
 * Entry: 0x696fa0; label: FUN_00696fa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00696fa0(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  undefined4 uStack_298;
  undefined4 uStack_294;
  undefined4 uStack_290;
  undefined4 uStack_28c;
  uint auStack_288 [17];
  undefined1 local_244 [4];
  undefined4 local_240;
  undefined4 local_230;
  undefined4 local_22c;
  uint local_228;
  undefined4 local_224;
  undefined1 *local_220;
  undefined4 local_21c;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  char local_20c [260];
  undefined1 local_108 [260];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&uStack_298;
  FUN_0069a1b0();
  if (DAT_00810dd0 == 0) {
    FUN_0069a330();
    goto LAB_006972ac;
  }
  if (DAT_02972bfc < param_2) {
    FUN_00696a90();
  }
  if (*(int *)(in_ECX + 0xd18) == 0) {
LAB_00697292:
    *(undefined1 *)(*(int *)(in_ECX + 0xd0c) + 0x405 + param_2 * 0x40c) = 1;
  }
  else {
    if (DAT_02972c30 == 0) {
      FUN_004f6900(local_108);
      _sprintf(local_20c,"%s%s",local_108,param_1);
    }
    else {
      _sprintf(local_20c,"%s",param_1);
    }
    iVar1 = FUN_0069a460(DAT_02972c30,local_20c,local_244);
    if (iVar1 < 0) goto LAB_00697292;
    local_228 = 0;
    local_224 = 0;
    local_220 = (undefined1 *)0x0;
    local_21c = 0;
    local_214 = 0;
    local_230 = 0x24;
    local_22c = 0xb8;
    local_218 = 0;
    local_210 = 0;
    uVar2 = FUN_0069a210();
    local_220 = local_244;
    local_228 = uVar2;
    if (0xfffffff < uVar2) {
      uVar2 = FUN_00696a90(local_20c,0xfffffff);
    }
    if (uVar2 < 4) {
      FUN_00696a90(local_20c,4);
    }
    iVar3 = param_2 * 0x40c;
    *(undefined4 *)(*(int *)(in_ECX + 0xd0c) + 0x408 + iVar3) = local_240;
    iVar1 = (**(code **)(**(int **)(in_ECX + 0xd18) + 0xc))
                      (*(int **)(in_ECX + 0xd18),&local_230,*(int *)(in_ECX + 0xd0c) + iVar3,0);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(**(int **)(*(int *)(in_ECX + 0xd0c) + iVar3) + 0x2c))
                        (*(undefined4 *)(*(int *)(in_ECX + 0xd0c) + iVar3),0,local_228,&uStack_290,
                         &uStack_298,&uStack_28c,&uStack_294,0);
      if (-1 < iVar1) {
        iVar1 = FUN_0069a680(uStack_290,uStack_298,auStack_288);
        if ((iVar1 < 0) || (auStack_288[0] != local_228)) {
          FUN_00696ab0(local_20c);
          *(undefined1 *)(*(int *)(in_ECX + 0xd0c) + 0x405 + iVar3) = 1;
        }
        (**(code **)(**(int **)(*(int *)(in_ECX + 0xd0c) + iVar3) + 0x4c))
                  (*(undefined4 *)(*(int *)(in_ECX + 0xd0c) + iVar3),uStack_290,uStack_298,
                   uStack_28c,uStack_294);
        FUN_0069a250();
        *(undefined1 *)(*(int *)(in_ECX + 0xd0c) + 0x404 + iVar3) = 1;
        FUN_0069a330();
        goto LAB_006972ac;
      }
      FUN_00696ab0(local_20c);
      FUN_0069a250();
      goto LAB_00697292;
    }
    FUN_00696ab0(local_20c);
    FUN_0069a250();
    *(undefined1 *)(*(int *)(in_ECX + 0xd0c) + 0x405 + iVar3) = 1;
  }
  FUN_0069a330();
LAB_006972ac:
  __security_check_cookie(local_4 ^ (uint)&uStack_298);
  return;
}

