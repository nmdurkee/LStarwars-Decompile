/* Ghidra pseudocode, not original source.
 * ev_7e454dac1a79555432f813726d68bcfcf5762a505a2d8dbf5e6e5fb42bc98c3e
 * Entry: 0x54dc30; label: FUN_0054dc30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0054dc30(void)

{
  int in_ECX;
  int iVar1;
  int *unaff_ESI;
  
  iVar1 = (int)*(char *)(*(int *)(*(int *)(in_ECX + 0x54) + 0x24) + 0x10a);
  if ((iVar1 == -1) || (*(int *)(*(int *)(in_ECX + 0x50) + 0x14 + iVar1 * 4) == 0)) {
    if ((*(byte *)(*(int *)(in_ECX + 0x798) + 0x1e) & 4) != 0) {
      *unaff_ESI = in_ECX + 0x80;
      return 1;
    }
    *unaff_ESI = in_ECX + 400;
  }
  else {
    *unaff_ESI = iVar1 * 0x40 + 0x834 + in_ECX;
    iVar1 = (int)*(char *)(*(int *)(*(int *)(in_ECX + 0x54) + 0x24) + 0x10b);
    if ((iVar1 != -1) && (*(int *)(*(int *)(in_ECX + 0x50) + 0x14 + iVar1 * 4) != 0)) {
      unaff_ESI[1] = iVar1 * 0x40 + 0x834 + in_ECX;
      return 2;
    }
  }
  return 1;
}

