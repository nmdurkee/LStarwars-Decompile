/* Ghidra analysis pseudocode, not original source.
 * ev_988aedce7a102035a37775149c4794654cf73d0aa98e786da352e425eaa98523
 * Entry: 0x433aa0; label: FUN_00433aa0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00433aa0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  int local_d0 [2];
  undefined4 *local_c8;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  int local_ac;
  undefined4 local_a4;
  code *local_94;
  code *local_84;
  code *local_7c;
  undefined4 local_44;
  undefined1 local_c;
  
  if (*(char *)(param_1 + 0x1082) != '\0') {
    iVar3 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x111);
    if ((iVar3 != -1) && (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar3 * 4) != 0)) {
      local_d4 = 0;
      local_dc = 0;
      local_d8 = 0x3f800000;
      uVar1 = FUN_0054fa60();
      FUN_005b3690(&local_dc,&local_dc,uVar1);
      uVar1 = FUN_0054fa60();
      FUN_005b35a0(&local_dc,&local_dc,uVar1);
      piVar4 = &DAT_00810210;
      piVar5 = local_d0;
      for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        piVar5 = piVar5 + 1;
      }
      local_bc = 0x3dcccccd;
      local_b8 = 0x3dcccccd;
      local_b4 = 0xc0a00000;
      local_d0[0] = iVar3 * 0x40 + 0x804 + param_1;
      local_c8 = &local_dc;
      local_ac = (*(byte *)(param_1 + 0x1082) + 0xf9) * 0x10 + *(int *)(PTR_DAT_00802c54 + 0x2ac0);
      local_44 = _DAT_00925018;
      local_a4 = 0x90;
      local_c = 1;
      local_84 = FUN_00571c50;
      local_7c = FUN_00571c80;
      local_94 = FUN_00571ba0;
      FUN_0064d270(local_d0);
    }
    *(undefined1 *)(param_1 + 0x1082) = 0;
  }
  return;
}

