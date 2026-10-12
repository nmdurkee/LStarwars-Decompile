/* Ghidra analysis pseudocode, not original source.
 * ev_ce999f6f93348d1bea0c268e5ec4785c76bf2f100732e1944453dc4f4dda8e73
 * Entry: 0x6d7960; label: FUN_006d7960
 */

undefined4 FUN_006d7960(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x4e10) == '\0') {
    *(undefined1 *)(in_ECX + 0x4e10) = 1;
    uVar1 = FUN_006d5990();
    *(undefined4 *)(in_ECX + 0x68b0) = uVar1;
  }
  return 1;
}

