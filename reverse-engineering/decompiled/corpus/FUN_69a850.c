/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x69a850; label: FUN_0069a850
 */

void FUN_0069a850(void)

{
  undefined4 *in_ECX;
  int iVar1;
  
  FUN_0069a1b0();
  *in_ECX = &PTR_FUN_0076eff8;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  in_ECX[0xc6] = 0;
  in_ECX[199] = 0;
  if (DAT_02973a00 == 0) {
    DAT_02973a00 = FUN_004ffa60();
    DAT_029739fc = FUN_004eef40(0x564,".\\pc\\oggreader.cpp",0x24);
  }
  iVar1 = 0;
  do {
    _memset((void *)(iVar1 + DAT_029739fc),0,0x114);
    iVar1 = iVar1 + 0x114;
  } while (iVar1 != 0x564);
  return;
}

