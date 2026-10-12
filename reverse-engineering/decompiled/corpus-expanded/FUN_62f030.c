/* Ghidra pseudocode, not original source.
 * ev_be89c5742567956971c64ab2441aea6b3f78c2cf42a7c801ad7bb364f9087e2c
 * Entry: 0x62f030; label: FUN_0062f030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062f030(undefined4 *param_1,undefined4 *param_2)

{
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  param_2[5] = param_1[5];
  *(undefined1 *)(param_2 + 6) = *(undefined1 *)(param_1 + 0xc);
  *(undefined1 *)((int)param_2 + 0x19) = *(undefined1 *)((int)param_1 + 0x31);
  *(undefined2 *)((int)param_2 + 0x1a) = *(undefined2 *)((int)param_1 + 0x32);
  *(undefined2 *)(param_2 + 7) = *(undefined2 *)(param_1 + 0xd);
  *(undefined2 *)((int)param_2 + 0x1e) = *(undefined2 *)((int)param_1 + 0x36);
  *(undefined2 *)(param_2 + 8) = *(undefined2 *)(param_1 + 0xe);
  *(undefined2 *)((int)param_2 + 0x22) = *(undefined2 *)((int)param_1 + 0x3a);
  return;
}

