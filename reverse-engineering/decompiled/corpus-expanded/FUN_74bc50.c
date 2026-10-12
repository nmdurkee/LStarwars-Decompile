/* Ghidra pseudocode, not original source.
 * ev_d88267bcb152659f8a516596ec9fcf93efabf83ae0338dc3d490a153d971aac8
 * Entry: 0x74bc50; label: FUN_0074bc50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_0074bc50(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0074b2a0(param_1);
  iVar2 = FUN_0074b2a0(param_2);
  return iVar2 < iVar1;
}

