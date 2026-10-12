/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62efb0; label: FUN_0062efb0
 */

void FUN_0062efb0(undefined4 *param_1,undefined4 *param_2)

{
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  param_2[5] = param_1[5];
  *(undefined1 *)(param_2 + 0xc) = *(undefined1 *)(param_1 + 6);
  *(undefined1 *)((int)param_2 + 0x31) = *(undefined1 *)((int)param_1 + 0x19);
  *(undefined2 *)((int)param_2 + 0x32) = *(undefined2 *)((int)param_1 + 0x1a);
  *(undefined2 *)(param_2 + 0xd) = *(undefined2 *)(param_1 + 7);
  *(undefined2 *)((int)param_2 + 0x36) = *(undefined2 *)((int)param_1 + 0x1e);
  *(undefined2 *)(param_2 + 0xe) = *(undefined2 *)(param_1 + 8);
  *(undefined2 *)((int)param_2 + 0x3a) = *(undefined2 *)((int)param_1 + 0x22);
  *(undefined1 *)(param_2 + 0xf) = 0;
  *(undefined1 *)((int)param_2 + 0x3d) = 0;
  *(undefined1 *)((int)param_2 + 0x3e) = 0;
  *(undefined2 *)((int)param_2 + 0x42) = 0xffff;
  return;
}

