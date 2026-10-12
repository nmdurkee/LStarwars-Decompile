/* Ghidra analysis pseudocode, not original source.
 * ev_b9433c7f5b60e61c8ae549a75e6ee409cf02164bae1bfdd2a40ff6f2bd4737bb
 * Entry: 0x5687f0; label: FUN_005687f0
 */

void FUN_005687f0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_1 != (undefined4 *)0x0) {
    local_c = param_1[0xc];
    local_8 = param_1[0xd];
    local_4 = param_1[0xe];
    puVar1 = (undefined4 *)FUN_005d0330(param_1[0x29] + 0x30);
    puVar3 = param_1;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar3 = puVar3 + 1;
    }
    param_1[0xc] = DAT_0093b0cc;
    param_1[0xd] = DAT_0093b0d0;
    param_1[0xe] = DAT_0093b0d4;
    FUN_005b4f70(param_1,*(undefined2 *)((int)param_1 + 0xea));
    FUN_005b4dd0(param_1,*(undefined2 *)(param_1 + 0x3a));
    FUN_005b5060(param_1,*(undefined2 *)(param_1 + 0x3b));
    FUN_005b4900(param_1,&local_c);
  }
  return;
}

