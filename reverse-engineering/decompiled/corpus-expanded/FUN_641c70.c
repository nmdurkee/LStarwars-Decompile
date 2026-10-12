/* Ghidra pseudocode, not original source.
 * ev_e37270f00559fec6395d344dad7372e88dd7c59f9ebe0b46a7132c9ac87d1215
 * Entry: 0x641c70; label: FUN_00641c70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00641c70(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  int local_88 [28];
  uint uStack_18;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_88;
  uStack_94 = *(undefined4 *)(param_2 + 100);
  iVar1 = *(int *)(param_2 + 0xc);
  uStack_98 = 0x641c99;
  FUN_004f28e0();
  uStack_94 = 0x641ca1;
  local_88[0] = FUN_006e6b90();
  if (local_88[0] < *(int *)(iVar1 + 0x18)) {
    local_88[0] = *(int *)(iVar1 + 0x18);
  }
  if (*(int *)(iVar1 + 0x1c) < local_88[0]) {
    local_88[0] = *(int *)(iVar1 + 0x1c);
  }
  uStack_94 = 0;
  uStack_98 = 0;
  piStack_9c = local_88;
  (**(code **)(**(int **)(iVar1 + 8) + 8))
            (*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10));
  FUN_004f2740(&uStack_98,*(undefined4 *)(iVar1 + 0x14),piStack_9c);
  FUN_0061e530(param_2,&uStack_98);
  __security_check_cookie(uStack_18 ^ (uint)&piStack_9c);
  return;
}

