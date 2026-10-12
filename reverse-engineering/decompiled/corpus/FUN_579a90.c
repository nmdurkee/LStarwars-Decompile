/* Ghidra analysis pseudocode, not original source.
 * ev_0fe45ae231fd2dfd40158a7785e6912069fa204ac07eb0ac56676de85047f6bb
 * Entry: 0x579a90; label: FUN_00579a90
 */

void FUN_00579a90(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = FUN_004f7fb0(param_1);
  if (iVar2 != 0) {
    uVar1 = FUN_00650dc0(*(undefined4 *)(param_1 + 0x510));
    *(undefined2 *)(DAT_00951b74 + 0x96) = uVar1;
  }
  return;
}

