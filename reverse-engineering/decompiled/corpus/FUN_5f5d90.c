/* Ghidra analysis pseudocode, not original source.
 * ev_7cb997f3f06904df49554a3614ea3c2031937e13b6d92041b838b169c363bf2a
 * Entry: 0x5f5d90; label: FUN_005f5d90
 */

void FUN_005f5d90(void)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = 1;
  do {
    FUN_005f5ce0();
    iVar1 = iVar1 + -1;
  } while (-1 < iVar1);
  *(undefined4 *)(in_ECX + 0x810) = 0x40800000;
  *(undefined4 *)(in_ECX + 0x808) = 0;
  *(undefined4 *)(in_ECX + 0x710) = 0;
  *(undefined4 *)(in_ECX + 0x814) = 0x3e800000;
  *(undefined4 *)(in_ECX + 0x800) = 0;
  *(undefined4 *)(in_ECX + 0x804) = 0;
  *(undefined4 *)(in_ECX + 0x80c) = 0x3f4ccccd;
  *(undefined4 *)(in_ECX + 0x824) = 0;
  *(undefined4 *)(in_ECX + 0x818) = 0;
  *(undefined4 *)(in_ECX + 0x70c) = 2;
  *(undefined4 *)(in_ECX + 0x81c) = 0x42c80000;
  *(undefined4 *)(in_ECX + 0x820) = 0x42dc0000;
  return;
}

