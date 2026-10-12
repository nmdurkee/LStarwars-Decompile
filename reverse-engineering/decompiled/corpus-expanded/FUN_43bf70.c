/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43bf70; label: FUN_0043bf70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0043bf70(undefined4 param_1,short param_2,int param_3)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined1 auStack_84 [64];
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_94;
  local_94 = param_1;
  if ((param_3 < DAT_0093b278) &&
     (iVar2 = (int)*(short *)(*(int *)(DAT_029130e4 + 0x1c) + param_3 * 2), iVar2 != -1)) {
    psVar3 = (short *)(iVar2 * 0x54 + *(int *)(DAT_029130e4 + 0x18));
    iVar2 = (**(code **)(*psVar3 * 0x120 + DAT_0093b284))
                      (psVar3,local_44,
                       *(undefined4 *)
                        (*(int *)(*(int *)(DAT_029130e4 + 0x20) + 0x24 + param_3 * 0x4c) + 0xa0));
    if (0 < iVar2) {
      sVar1 = FUN_005be590((int)param_2,0x8000);
      uStack_90 = *(undefined4 *)(param_3 * 0x4c + 0x3c + DAT_0093b274);
      uStack_8c = uStack_90;
      uStack_88 = uStack_90;
      FUN_005b45a0(auStack_84,&uStack_90);
      FUN_005b4900(auStack_84,local_94);
      FUN_005b5060(auStack_84,(int)sVar1);
      FUN_00604c00(*(undefined4 *)(psVar3 + 2),auStack_84,iVar2,local_44);
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_94);
  return;
}

