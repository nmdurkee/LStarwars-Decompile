/* Ghidra analysis pseudocode, not original source.
 * ev_0fe45ae231fd2dfd40158a7785e6912069fa204ac07eb0ac56676de85047f6bb
 * Entry: 0x5799f0; label: FUN_005799f0
 */

void FUN_005799f0(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_004f7fb0(param_1);
  if (iVar2 != 0) {
    uVar1 = FUN_00548a60(*(undefined4 *)(param_1 + 0x510),DAT_009248cc,0xffffffff);
    *(undefined2 *)(DAT_00951b74 + 0x9c) = uVar1;
    uVar3 = FUN_00694320(1,*(undefined4 *)(param_1 + 0x510));
    *(undefined4 *)(DAT_00951b74 + 0x11c) = uVar3;
    uVar3 = FUN_00694320(2,*(undefined4 *)(param_1 + 0x510));
    *(undefined4 *)(DAT_00951b74 + 0x124) = uVar3;
    uVar3 = FUN_00694320(0x20,*(undefined4 *)(param_1 + 0x510));
    *(undefined4 *)(DAT_00951b74 + 300) = uVar3;
  }
  return;
}

