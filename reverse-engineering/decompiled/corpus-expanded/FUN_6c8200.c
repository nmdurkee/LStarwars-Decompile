/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c8200; label: FUN_006c8200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c8200(int param_1)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int *in_ECX;
  
  in_ECX[0x66] = param_1;
  pcVar2 = *(code **)(*in_ECX + 0x18);
  piVar1 = in_ECX + 1;
  *piVar1 = 0;
  iVar3 = (*pcVar2)("StreamInfo");
  if (iVar3 != 0) {
    (**(code **)(*in_ECX + 8))(piVar1,4,1);
    (**(code **)(*in_ECX + 0x1c))();
  }
  if (*piVar1 != param_1) {
    FUN_006b7c50(*piVar1,param_1);
  }
  return;
}

