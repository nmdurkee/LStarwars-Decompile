/* Ghidra pseudocode, not original source.
 * ev_d88267bcb152659f8a516596ec9fcf93efabf83ae0338dc3d490a153d971aac8
 * Entry: 0x74b900; label: FUN_0074b900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_0074b900(void *param_1,int param_2,void *param_3)

{
  rsize_t _DstSize;
  int iVar1;
  
  iVar1 = param_2 - (int)param_1 >> 2;
  _DstSize = iVar1 * 4;
  if (0 < iVar1) {
    _memmove_s(param_3,_DstSize,param_1,_DstSize);
  }
  return (void *)(_DstSize + (int)param_3);
}

