/* Ghidra pseudocode, not original source.
 * ev_6614b6c0ec400e98b17ca3318749993ac398f4a5e7c651bffc9aeb30b42772d2
 * Entry: 0x5094b0; label: FUN_005094b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005094b0(int param_1,int param_2,undefined4 param_3,undefined *param_4,undefined4 param_5,
                 undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_44;
  if (100 < param_2 + 0x1f) {
    param_2 = 0x45;
  }
  if (0 < param_2) {
    puVar1 = &DAT_00800e0c;
    iVar3 = param_2;
    do {
      iVar3 = iVar3 + -1;
      puVar4 = (undefined4 *)(param_1 + -0x800e0c + (int)puVar1);
      puVar5 = puVar1;
      for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar1 = puVar1 + 7;
    } while (iVar3 != 0);
  }
  DAT_0080094c = param_2 + 0x1f;
  _sprintf(local_44,"Menus used: %d",DAT_0080094c);
  _DAT_0092143c = (uint)DAT_00921daa;
  _DAT_009213e8 = (uint)DAT_0080099c;
  _DAT_00800948 = param_3;
  _DAT_009213f4 = (uint)DAT_0080099d;
  DAT_009213f8._0_1_ = 0;
  if (param_4 != (undefined *)0x0) {
    PTR_FUN_00800964 = param_4;
  }
  DAT_00921d64 = param_5;
  DAT_00921d78 = param_6;
  DAT_00921d8c = FUN_005e4d00(1);
  *(uint *)(DAT_00921d8c + 0x40) = *(uint *)(DAT_00921d8c + 0x40) | 0xc000;
  *(uint *)(DAT_00921d8c + 0x40) = *(uint *)(DAT_00921d8c + 0x40) & 0xffffffdf | 0x10;
  *(uint *)(DAT_00921d8c + 0x40) = *(uint *)(DAT_00921d8c + 0x40) & 0xfffeffff | 0x20000;
  *(uint *)(DAT_00921d8c + 0x40) = *(uint *)(DAT_00921d8c + 0x40) & 0xfffffdff | 0x100;
  *(uint *)(DAT_00921d8c + 0x40) = *(uint *)(DAT_00921d8c + 0x40) & 0xfffff7ff | 0x400;
  *(uint *)(DAT_00921d8c + 0x40) = *(uint *)(DAT_00921d8c + 0x40) | 0x40000;
  *(uint *)(DAT_00921d8c + 0x40) = *(uint *)(DAT_00921d8c + 0x40) & 0xfffffff1 | 1;
  FUN_005e4b00(DAT_00921d8c);
  FUN_006d6b30(0xffffffff);
  __security_check_cookie(local_4 ^ (uint)local_44);
  return;
}

