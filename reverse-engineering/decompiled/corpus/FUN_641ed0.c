/* Ghidra analysis pseudocode, not original source.
 * ev_9b402c9e9507e171b8c16fab1dff2f919b44cba00aab1d6e0da1cdd21bc5614e
 * Entry: 0x641ed0; label: FUN_00641ed0
 */

void FUN_00641ed0(undefined4 param_1,int param_2)

{
  int iVar1;
  float10 fVar2;
  float *pfStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  float local_88 [28];
  uint uStack_18;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_88;
  uStack_94 = *(undefined4 *)(param_2 + 100);
  iVar1 = *(int *)(param_2 + 0xc);
  uStack_98 = 0x641ef9;
  fVar2 = (float10)FUN_004f28e0();
  local_88[0] = (float)fVar2;
  if (local_88[0] < *(float *)(iVar1 + 0x18)) {
    local_88[0] = *(float *)(iVar1 + 0x18);
  }
  if (*(float *)(iVar1 + 0x1c) < local_88[0]) {
    local_88[0] = *(float *)(iVar1 + 0x1c);
  }
  uStack_94 = 0;
  uStack_98 = 0;
  pfStack_9c = local_88;
  (**(code **)(**(int **)(iVar1 + 8) + 8))
            (*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10));
  FUN_004f2740(&uStack_98,*(undefined4 *)(iVar1 + 0x14),(double)(float)pfStack_9c);
  FUN_0061e530(param_2,&uStack_98);
  __security_check_cookie(uStack_18 ^ (uint)&pfStack_9c);
  return;
}

