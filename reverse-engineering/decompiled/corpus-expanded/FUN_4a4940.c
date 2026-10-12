/* Ghidra pseudocode, not original source.
 * ev_a85b3e4898e579c25a43afce2c9968e46b76c95f9b8b71b7b173505cf03a6bab
 * Entry: 0x4a4940; label: FUN_004a4940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a4940(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_58;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40 [16];
  
  if (param_1 != 0) {
    iVar1 = FUN_005cfac0(param_1);
    if (iVar1 != 0) {
      if ((DAT_0087b8c8 != 0) && (DAT_0087b8d0 != 3)) {
        FUN_005cfc00(param_1,1);
        puVar2 = (undefined4 *)FUN_005d0330(param_1);
        puVar3 = local_40;
        for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
        local_58 = *(undefined4 *)(DAT_0087b8c8 + 0x19c);
        local_54 = *(float *)(DAT_0087b8c8 + 0x21c) + 0.005;
        local_50 = *(undefined4 *)(DAT_0087b8c8 + 0x1a4);
        local_44 = _DAT_0087b890;
        local_48 = _DAT_0087b890;
        local_4c = _DAT_0087b890;
        FUN_005b4500(local_40,&local_58);
        FUN_005b4c30(local_40,&local_4c);
        FUN_005ea570(param_1,local_40);
        FUN_005ea660(param_1);
        return;
      }
      FUN_005cfc00(param_1,0);
    }
  }
  return;
}

