/* Ghidra pseudocode, not original source.
 * ev_3c91a6b80548833a29ecc2d389e89e55b74ab0261b3e94a742c4850371a9aab1
 * Entry: 0x65f660; label: FUN_0065f660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065f660(int param_1)

{
  int iVar1;
  int iVar2;
  
  DAT_00810a90 = DAT_02921884;
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

