/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c8430; label: FUN_006c8430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c8430(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  in_ECX[0x11] = param_1;
  pcVar1 = *(code **)(*in_ECX + 0x18);
  in_ECX[1] = param_2;
  iVar2 = (*pcVar1)("StreamInfo");
  if (iVar2 != 0) {
    (**(code **)(*in_ECX + 8))(in_ECX + 1,4,1);
    (**(code **)(*in_ECX + 0x1c))();
  }
  return;
}

