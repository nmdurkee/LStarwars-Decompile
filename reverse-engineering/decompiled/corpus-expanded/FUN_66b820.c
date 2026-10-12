/* Ghidra pseudocode, not original source.
 * ev_c3511c7e9be8c9ea3f86dbf498dc77cf8080442af45acd9c68d26e3bdf8b902d
 * Entry: 0x66b820; label: FUN_0066b820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066b820(int *param_1)

{
  int iVar1;
  bool bVar2;
  
  if (DAT_02962b30 == 0) {
    DAT_02962b30 = *param_1;
  }
  *param_1 = *param_1 + 0xc800;
  iVar1 = *param_1;
  if (DAT_02962b34 == 0) {
    DAT_02962b34 = iVar1;
  }
  bVar2 = DAT_02947ca0 == 0;
  *param_1 = iVar1 + 0xc800;
  if (bVar2) {
    DAT_02947ca0 = iVar1 + 0xc800;
  }
  bVar2 = DAT_0292fb50 == 0;
  *param_1 = iVar1 + 0xe800;
  if (bVar2) {
    DAT_0292fb50 = iVar1 + 0xe800;
  }
  *param_1 = iVar1 + 0xee00;
  return;
}

