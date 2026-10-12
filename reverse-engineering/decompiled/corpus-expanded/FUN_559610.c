/* Ghidra pseudocode, not original source.
 * ev_ebdcb732153d7bf306588444e9af2e40ea41c4dbebef89d348e04ae4a29830a2
 * Entry: 0x559610; label: FUN_00559610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_00559610(int *param_1,uint *param_2,size_t param_3)

{
  uint uVar1;
  void *_Dst;
  
  _Dst = (void *)0x0;
  if (((param_1 != (int *)0x0) && (param_2 != (uint *)0x0)) && (*param_1 + param_3 < *param_2)) {
    uVar1 = *param_1 + 0xf;
    _Dst = (void *)(uVar1 & 0xfffffff0);
    *param_1 = (uVar1 & 0xfffffff0) + param_3;
    _memset(_Dst,0,param_3);
  }
  return _Dst;
}

