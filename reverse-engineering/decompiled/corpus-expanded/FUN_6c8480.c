/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c8480; label: FUN_006c8480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006c8480(void)

{
  int *in_ECX;
  undefined4 unaff_ESI;
  int local_4;
  
  local_4 = FUN_004f6d10(in_ECX[0x11]);
  if (in_ECX[0x10] < 8) {
    in_ECX[in_ECX[0x10] + 8] = local_4;
    in_ECX[0x10] = in_ECX[0x10] + 1;
  }
  else {
    FUN_006b7c40();
  }
  (**(code **)(*in_ECX + 8))(&local_4,4,1);
  (**(code **)(*in_ECX + 0x14))(unaff_ESI,0);
  return unaff_ESI;
}

