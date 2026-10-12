/* Ghidra pseudocode, not original source.
 * ev_3150f882b42e5d0bb9c96a5fbbe185870406793ef78dd50970469a73867d11f4
 * Entry: 0x648a50; label: FUN_00648a50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00648a50(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00810194 * 0x178;
  if ((&DAT_02913b0b)[iVar1] == '\0') {
    (&DAT_02913b0b)[iVar1] = 1;
    (&DAT_02913b0a)[iVar1] = 1;
  }
  else {
    (&DAT_02913b0b)[iVar1] = 0;
    (&DAT_02913b0a)[iVar1] = 0;
  }
  DAT_02920974 = (&DAT_02913b0b)[iVar1];
  iVar1 = *(int *)(param_1 + 0x40);
  iVar2 = 0;
  if (iVar1 != 0) {
    FUN_006279f0(param_1);
    iVar2 = iVar1;
  }
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
    (**(code **)(param_1 + 0x30))(param_1,iVar2);
  }
  return;
}

