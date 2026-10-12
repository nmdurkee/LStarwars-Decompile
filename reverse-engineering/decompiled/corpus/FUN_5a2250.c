/* Ghidra analysis pseudocode, not original source.
 * ev_0b4f3bc8b4a39fc427a7fcc8ed3e1304ee3926d0e45102a57071cb05acfa7baa
 * Entry: 0x5a2250; label: FUN_005a2250
 */

void FUN_005a2250(void)

{
  int in_EAX;
  int *piVar1;
  int in_ECX;
  int iVar2;
  
  if (in_ECX != 0) {
    if (1 < in_EAX + -1) {
      piVar1 = (int *)(in_ECX + 0xf8);
      iVar2 = in_EAX + -2;
      do {
        *piVar1 = (int)(piVar1 + 2);
        piVar1[1] = (int)(piVar1 + -0x3e);
        piVar1 = piVar1 + 0x20;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    *(int *)(in_ECX + 0x78) = in_ECX + 0x80;
    iVar2 = in_EAX * 0x80 + in_ECX;
    *(int *)(in_ECX + 0x7c) = iVar2 + -0x80;
    *(int *)(iVar2 + -8) = in_ECX;
    *(int *)(iVar2 + -4) = (in_EAX + -2) * 0x80 + in_ECX;
  }
  return;
}

