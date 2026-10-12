/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4f0e10; label: FUN_004f0e10
 */

void FUN_004f0e10(int param_1)

{
  int in_EAX;
  int iVar1;
  char *pcVar2;
  int in_EDX;
  int iVar3;
  int unaff_EDI;
  
  iVar3 = in_EAX + -0x18;
  iVar1 = 0;
  pcVar2 = (char *)(in_EDX + 0x18);
  while (iVar3 != 0) {
    *pcVar2 = *pcVar2 - *(char *)(iVar1 + param_1);
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + -1;
    if (unaff_EDI <= iVar1) {
      iVar1 = 0;
    }
    pcVar2 = pcVar2 + 1;
  }
  *(uint *)(in_EDX + 0x10) = *(uint *)(in_EDX + 0x10) & 0xfffffffe;
  return;
}

