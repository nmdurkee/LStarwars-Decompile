/* Ghidra analysis pseudocode, not original source.
 * ev_f6f29f3a3b14d12541c710eb91fc3c5282bb00f37b38cc241e06611dc1b7516b
 * Entry: 0x49f780; label: FUN_0049f780
 */

undefined4 FUN_0049f780(int param_1)

{
  int in_EAX;
  int iVar1;
  int *in_EDX;
  int *unaff_ESI;
  
  if ((*(char *)(param_1 + 0x28c) == '\0') || ((*(uint *)(param_1 + 0xe20) & 0x8000000) == 0)) {
    return 0;
  }
  if (in_EDX == (int *)0x0) {
    in_EDX = &param_1;
  }
  *in_EDX = in_EAX;
  iVar1 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x100 + in_EAX * 2);
  *unaff_ESI = iVar1;
  if ((iVar1 != -1) && (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar1 * 4) != 0)) {
    iVar1 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x101 + *in_EDX * 2);
    unaff_ESI[1] = iVar1;
    if ((iVar1 != -1) && (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar1 * 4) != 0)) {
      return 1;
    }
  }
  return 0;
}

