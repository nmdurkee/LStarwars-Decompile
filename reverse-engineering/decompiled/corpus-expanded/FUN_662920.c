/* Ghidra pseudocode, not original source.
 * ev_48e8314641b8677069cf0b2f56163e168ef7ac8043ee4515292faa1f02998c89
 * Entry: 0x662920; label: FUN_00662920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00662920(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_029231a8;
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    (&DAT_02924b94)[DAT_029231a8 * 0x16] = *(undefined4 *)(param_2 + 0x54);
    *(undefined4 *)((&DAT_02924b60)[iVar1 * 0x16] * 0x330 + 0x2e0 + DAT_029620a4) =
         *(undefined4 *)(param_2 + 0x54);
  }
  return;
}

