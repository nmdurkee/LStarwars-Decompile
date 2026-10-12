/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c84e0; label: FUN_006c84e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c84e0(void)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  int local_4;
  
  iVar1 = in_ECX[0x10];
  if (iVar1 < 1) {
    iVar1 = FUN_006b7c40();
  }
  in_ECX[0x10] = iVar1 + -1;
  iVar1 = in_ECX[iVar1 + 7];
  iVar2 = FUN_004f6d10(in_ECX[0x11]);
  local_4 = iVar2 - iVar1;
  FUN_004f6de0(in_ECX[0x11],iVar1,iVar1 >> 0x1f,0);
  (**(code **)(*in_ECX + 8))(&local_4,4,1);
  FUN_004f6de0(in_ECX[0x11],iVar2,iVar2 >> 0x1f,0);
  return;
}

