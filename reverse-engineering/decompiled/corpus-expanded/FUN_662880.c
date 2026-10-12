/* Ghidra pseudocode, not original source.
 * ev_48e8314641b8677069cf0b2f56163e168ef7ac8043ee4515292faa1f02998c89
 * Entry: 0x662880; label: FUN_00662880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00662880(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined1 *)(*(int *)(DAT_0296209c + DAT_00810aec * 4) + 0x10) = DAT_0292118b;
  DAT_00810aec = 0xffffffff;
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

