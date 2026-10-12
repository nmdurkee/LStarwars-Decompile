/* Ghidra pseudocode, not original source.
 * ev_dfa41b6c39560a6d4e303a9a42849e633890ea31aa955743b15917c3077a3c9c
 * Entry: 0x5c2850; label: FUN_005c2850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c2850(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  uVar1 = FUN_006056f0(param_1 / 2,param_2 / 2,2,1,2);
  iVar3 = 0;
  *(undefined4 *)(in_ECX + 0x54) = uVar1;
  *(undefined4 *)(in_ECX + 100) = 0;
  iVar2 = param_2;
  do {
    if ((param_1 < 0x80) || (iVar2 < 0x80)) break;
    *(int *)(in_ECX + 100) = *(int *)(in_ECX + 100) + 1;
    param_1 = param_1 / 2;
    iVar2 = iVar2 / 2;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  uVar1 = FUN_006056f0(param_1,iVar2,1,1,2);
  *(undefined4 *)(in_ECX + 0x5c) = uVar1;
  if (param_2 < 0x2c0) {
    *(float *)(in_ECX + 0x7c) = *(float *)(in_ECX + 0x7c) - 1.0;
    *(float *)(in_ECX + 0x6c) = *(float *)(in_ECX + 0x6c) - 0.85;
    *(float *)(in_ECX + 0x60) = *(float *)(in_ECX + 0x60) - 0.5;
  }
  return;
}

