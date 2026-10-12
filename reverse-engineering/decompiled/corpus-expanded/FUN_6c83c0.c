/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c83c0; label: FUN_006c83c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c83c0(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 0x80);
  if (iVar2 < 1) {
    iVar2 = FUN_006b7c40();
  }
  iVar2 = iVar2 + -1;
  *(int *)(in_ECX + 0x80) = iVar2;
  uVar1 = *(undefined4 *)(in_ECX + 0x28 + iVar2 * 0xc);
  iVar2 = *(int *)(in_ECX + 0x24 + iVar2 * 0xc) + *(int *)(in_ECX + 0x20 + iVar2 * 0xc);
  iVar3 = FUN_004f6d10(*(undefined4 *)(in_ECX + 0x198));
  if (iVar3 != iVar2) {
    FUN_004f6de0(*(undefined4 *)(in_ECX + 0x198),iVar2,iVar2 >> 0x1f,0);
  }
  *(undefined4 *)(in_ECX + 0x184) = uVar1;
  return;
}

