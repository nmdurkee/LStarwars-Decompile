/* Ghidra pseudocode, not original source.
 * ev_d88267bcb152659f8a516596ec9fcf93efabf83ae0338dc3d490a153d971aac8
 * Entry: 0x74bef0; label: FUN_0074bef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0074bef0(undefined4 param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x11c) = param_4;
  *(undefined1 *)(in_ECX + 0x120) = param_3;
  *(undefined4 *)(in_ECX + 0x114) = 0;
  *(undefined4 *)(in_ECX + 0x118) = 0;
  *(undefined4 *)(in_ECX + 0x2c4) = 0;
  *(undefined4 *)(in_ECX + 0x458) = 0;
  FUN_0074ba90(param_1,param_2);
  FUN_0074bbc0();
  *(undefined4 *)(in_ECX + 0x11c) = 0;
  *(undefined1 *)(in_ECX + 0x120) = 0;
  return *(undefined4 *)(in_ECX + 0x114);
}

