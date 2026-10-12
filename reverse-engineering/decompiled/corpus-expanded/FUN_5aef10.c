/* Ghidra pseudocode, not original source.
 * ev_18939eb5636c5080554c34c4c464805d15dff0cc807e45e19880c96644741519
 * Entry: 0x5aef10; label: FUN_005aef10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005aef10(int param_1,int param_2,code *param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  float10 fVar5;
  undefined1 auStack_8c [3];
  byte local_89;
  uint local_88;
  undefined4 local_84;
  undefined4 local_80;
  float local_7c;
  code *local_78;
  float local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 *local_4c;
  undefined4 *local_48;
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_8c;
  local_78 = param_3;
  local_80 = param_5;
  local_70 = param_6;
  local_84 = 1;
  local_89 = FUN_006218c0();
  local_88 = FUN_006218c0();
  local_88 = local_88 & 0xff;
  if (local_88 == 0) {
    __security_check_cookie(local_4 ^ (uint)auStack_8c);
    return;
  }
  do {
    cVar1 = FUN_006218c0();
    iVar4 = (int)cVar1;
    if (iVar4 != 0) {
      FUN_006216f0(local_44,iVar4);
    }
    fVar5 = (float10)FUN_006217a0();
    local_7c = (float)fVar5;
    fVar5 = (float10)FUN_006217a0();
    local_74 = (float)fVar5;
    if (local_89 < 2) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_006217e0();
    }
    if (iVar4 != 0) {
      if ((*(int *)(param_1 + 0x10) == 0) || (*(int *)(*(int *)(param_1 + 0x10) + 0xc) == 0)) {
        local_84 = 0;
      }
      puVar3 = (undefined4 *)
               FUN_005a1b10(param_1,*(undefined4 *)(param_2 + 0x13c),local_44,local_7c,local_74,0,
                            *(undefined4 *)(param_2 + 0x2ac8),local_80,local_70);
      if (puVar3 == (undefined4 *)0x0) {
        local_4c = puVar3;
        local_48 = puVar3;
        puVar3 = &local_6c;
        local_6c = 0;
        local_68 = 0;
        local_64 = 0;
        local_60 = 0;
        local_5c = 0;
        local_58 = 0;
        local_54 = 0;
        local_50 = 0;
      }
      puVar3[8] = uVar2;
      if (local_78 != (code *)0x0) {
        (*local_78)(puVar3,param_4);
      }
      if (local_89 < 3) {
        puVar3[8] = puVar3[8] & 0xfffffffd;
      }
    }
    local_88 = local_88 - 1;
  } while (local_88 != 0);
  __security_check_cookie(local_4 ^ (uint)auStack_8c);
  return;
}

