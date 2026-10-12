/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4f0cb0; label: FUN_004f0cb0
 */

int FUN_004f0cb0(void)

{
  int in_EAX;
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  piVar2 = (int *)((in_ECX + 3) * 0x10 + in_EAX);
  if (*piVar2 == 0) {
    iVar1 = FUN_004fa3f0(*(undefined4 *)(in_EAX + 0xb8),(int)*(short *)(in_EAX + 0xb2),0,0);
    *piVar2 = iVar1;
    piVar2[2] = 0;
    piVar2[3] = 0;
    return iVar1;
  }
  return *piVar2;
}

