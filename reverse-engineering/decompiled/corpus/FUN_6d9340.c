/* Ghidra analysis pseudocode, not original source.
 * ev_ce999f6f93348d1bea0c268e5ec4785c76bf2f100732e1944453dc4f4dda8e73
 * Entry: 0x6d9340; label: FUN_006d9340
 */

void FUN_006d9340(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_02975144;
  if (*(char *)(DAT_02975144 + 0x4e10) == '\0') {
    *(undefined1 *)(DAT_02975144 + 0x4e10) = 1;
    uVar2 = FUN_006d5990();
    *(undefined4 *)(iVar1 + 0x68b0) = uVar2;
  }
  return;
}

