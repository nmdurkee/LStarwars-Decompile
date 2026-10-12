/* Ghidra analysis pseudocode, not original source.
 * ev_6eb3c0e5a4192d504e77ca733851733d52b37eecab747dc6ff26bd5be7535327
 * Entry: 0x61eb60; label: FUN_0061eb60
 */

void FUN_0061eb60(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  
  for (puVar1 = (undefined4 *)param_1[0x13]; puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    if (puVar1[2] == 0x13) {
      FUN_0061eb60(puVar1);
    }
    if (puVar1 == (undefined4 *)param_1[0x14]) break;
  }
  if ((param_1[0x13] != 0) && ((*(byte *)(param_1 + 0x15) & 1) != 0)) {
    piVar2 = (int *)param_1[0x14];
    *param_1 = *piVar2;
    if (*piVar2 != 0) {
      *(int **)(*piVar2 + 4) = param_1;
    }
    *(undefined4 *)(param_1[0x13] + 4) = 0;
    param_1[0x15] = param_1[0x15] & 0xfffffffe;
  }
  return;
}

