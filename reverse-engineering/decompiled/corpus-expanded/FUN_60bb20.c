/* Ghidra pseudocode, not original source.
 * ev_8d558f2b7d37f7c2d88d0d36eae1cf7a4b5788ac1ea6cb26aea78645de7b2f49
 * Entry: 0x60bb20; label: FUN_0060bb20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060bb20(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)param_1[4];
  puVar3 = (undefined4 *)param_1[3];
  while (puVar3 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar3;
    FUN_00609b90(puVar3);
    puVar3 = puVar2;
  }
  for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
  }
  if ((int *)param_1[1] != (int *)0x0) {
    *(int *)param_1[1] = *param_1;
  }
  _DAT_02854f38 = _DAT_02854f38 + -1;
  if (*param_1 != 0) {
    *(int *)(*param_1 + 4) = param_1[1];
  }
  return;
}

