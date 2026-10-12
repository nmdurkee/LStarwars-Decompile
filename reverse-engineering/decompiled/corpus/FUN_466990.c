/* Ghidra analysis pseudocode, not original source.
 * ev_7062545ad2ab2af07ec33b13480d196f765b27a757bdc9b0fea79766ea2b2f64
 * Entry: 0x466990; label: FUN_00466990
 */

void FUN_00466990(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  if (((DAT_00877ad8 != 0) && (iVar2 = FUN_004f7fb0(param_1), iVar2 != 0)) &&
     (*(short *)(DAT_00877ad8 + 0x86) == -1)) {
    uVar1 = FUN_00650dc0(*(undefined4 *)(param_1 + 0x510));
    *(undefined2 *)(DAT_00877ad8 + 0x86) = uVar1;
  }
  return;
}

