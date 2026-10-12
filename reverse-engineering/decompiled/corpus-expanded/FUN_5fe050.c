/* Ghidra pseudocode, not original source.
 * ev_e9e973cc1e732372fb6e3c1361e2c8e184c78a797f94e34f658706f6700bd0dd
 * Entry: 0x5fe050; label: FUN_005fe050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fe050(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  iVar2 = 0;
  do {
    iVar1 = *(int *)(param_1 + iVar2 * 4);
    if (iVar1 == -1) {
      iVar1 = 1;
    }
    iVar1 = FUN_005e5310(iVar1);
    FUN_006e5630(iVar2,*(undefined4 *)(iVar1 + 0x24));
    FUN_006e54e0(iVar2,1,1);
    FUN_006e54e0(iVar2,2,1);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  local_c = *(undefined4 *)(param_1 + 0xc);
  local_8 = -*(float *)(param_1 + 0x10);
  local_4 = 0;
  FUN_007412e0(0x60,&local_c);
  return;
}

