/* Ghidra analysis pseudocode, not original source.
 * ev_f6f29f3a3b14d12541c710eb91fc3c5282bb00f37b38cc241e06611dc1b7516b
 * Entry: 0x49e240; label: FUN_0049e240
 */

undefined4 FUN_0049e240(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x280) != -1) &&
     (((iVar1 = *(int *)(*(int *)(in_ECX + 0x50) + 0xc), *(int *)(iVar1 + 0x68) != 0 ||
       (*(int *)(iVar1 + 0x6c) != 0)) || (*(int *)(iVar1 + 0x70) != 0)))) {
    uVar2 = FUN_00571cf0();
    return uVar2;
  }
  return 0;
}

