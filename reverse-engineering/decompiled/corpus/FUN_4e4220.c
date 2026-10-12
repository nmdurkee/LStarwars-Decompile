/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4e4220; label: FUN_004e4220
 */

void FUN_004e4220(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if ((DAT_00951b50 == 0) && (DAT_008895d8 == 0)) {
    FUN_004e3c90();
  }
  if (param_2 != 0) {
    iVar1 = FUN_004f8b10(param_2,"door_control");
    if (iVar1 == 0) {
      *(undefined1 *)(param_2 + 0xf7) = 1;
    }
  }
  return;
}

