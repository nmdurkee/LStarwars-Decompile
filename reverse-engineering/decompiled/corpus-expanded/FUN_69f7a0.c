/* Ghidra pseudocode, not original source.
 * ev_3229c3221a199ea2fa72efff5d47b38f22dfc944c4167cffdb72b8afc53424db
 * Entry: 0x69f7a0; label: FUN_0069f7a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069f7a0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0069f540(param_1,param_2);
  while( true ) {
    if (0 < iVar1) {
      return 1;
    }
    if (iVar1 == 0) break;
    if (*(int *)(param_1 + 0x10) == 0) {
      *(undefined4 *)(param_1 + 0x10) = 1;
      return 0xffffffff;
    }
    iVar1 = FUN_0069f540(param_1,param_2);
  }
  return 0;
}

