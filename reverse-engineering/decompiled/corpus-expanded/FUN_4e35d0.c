/* Ghidra pseudocode, not original source.
 * ev_9cfa2c7caaff9bea1a8899eb9da7a192a21c6dc6359864cdd250e80ead8b0fa3
 * Entry: 0x4e35d0; label: FUN_004e35d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e35d0(int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int local_108;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_108;
  iVar3 = 1;
  puVar4 = &DAT_0087aad8;
  iVar5 = 0;
  local_108 = 2;
  do {
    _sprintf(local_104,"ball%ib",iVar3);
    iVar2 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),puVar4,local_104,1);
    if (iVar2 != 0) {
      FUN_005cfc00(puVar4,0);
    }
    *(undefined4 *)((int)&DAT_008895c0 + iVar5) = 0;
    _sprintf(local_104,"ball%i",iVar3);
    iVar2 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),puVar4,local_104,1);
    if (iVar2 != 0) {
      FUN_005cfc00(puVar4,0);
      iVar2 = FUN_005d0420(puVar4);
      *(int *)((int)&DAT_0087a810 + iVar5) = iVar2;
      *(undefined4 *)(iVar2 + 0x4c) = 0;
      puVar1 = (uint *)(*(int *)((int)&DAT_0087a810 + iVar5) + 0x50);
      *puVar1 = *puVar1 & 0xfffffffe;
    }
    iVar3 = iVar3 + 1;
    puVar4 = puVar4 + 3;
    iVar5 = iVar5 + 4;
    local_108 = local_108 + -1;
  } while (local_108 != 0);
  __security_check_cookie(local_4 ^ (uint)&local_108);
  return;
}

