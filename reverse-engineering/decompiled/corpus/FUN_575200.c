/* Ghidra analysis pseudocode, not original source.
 * ev_fb3e2efa05f3fdcad8ac13641a8f1821f73d708273cedf9c40d68478f4bf822c
 * Entry: 0x575200; label: FUN_00575200
 */

void FUN_00575200(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_0055f460(*(undefined4 *)(param_1 + 0x510));
    uVar2 = FUN_0057c970(*(undefined4 *)(iVar1 + 0x2ab0));
    *(undefined4 *)(DAT_00951398 + 0x120) = uVar2;
  }
  return;
}

