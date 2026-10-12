/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x41af70; label: FUN_0041af70
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041af70(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_004148a0(param_1 + 0x6c4,*(undefined4 *)(param_1 + 0x54));
  *(undefined4 *)(param_1 + 0x103c) = 0;
  *(undefined4 *)(param_1 + 0x200) = DAT_0093b0cc;
  *(undefined4 *)(param_1 + 0x204) = DAT_0093b0d0;
  uVar2 = DAT_0093b0d4;
  *(undefined4 *)(param_1 + 0xd60) = 0;
  *(undefined4 *)(param_1 + 0x208) = uVar2;
  uVar2 = _DAT_00802be8;
  *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) | 0x80;
  *(undefined4 *)(param_1 + 0xda4) = uVar2;
  uVar2 = FUN_00415050(param_1);
  FUN_004150d0(param_1,2,uVar2);
  if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 4) == 0) {
    FUN_0062e650(param_1 + 8,0xffffffff);
  }
  else {
    FUN_0062e650(param_1 + 8,1);
    FUN_0062e6c0(*(undefined4 *)(param_1 + 0x50),param_1 + 8);
  }
  iVar1 = *(int *)(param_1 + 0x54);
  *(undefined1 *)(param_1 + 0x282) = 0;
  *(undefined1 *)(param_1 + 0x281) = 0;
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(iVar1 + 0x3c);
  *(undefined4 *)(param_1 + 0xffc) = *(undefined4 *)(iVar1 + 0x30);
  *(undefined4 *)(param_1 + 0xff0) = *(undefined4 *)(iVar1 + 0x34);
  *(undefined4 *)(param_1 + 0xff4) = *(undefined4 *)(iVar1 + 0x38);
  FUN_0055ccd0(param_1);
  *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) & 0xfff8ffff;
  *(undefined4 *)(param_1 + 0x1000) = 0;
  *(undefined4 *)(param_1 + 0x1018) = 0;
  FUN_00570a60(*(undefined4 *)(param_1 + 0x7fc));
  *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) & 0xffffdfff;
  *(undefined4 *)(param_1 + 0x1d8) = 0;
  FUN_004988b0(param_1,1);
  return;
}

