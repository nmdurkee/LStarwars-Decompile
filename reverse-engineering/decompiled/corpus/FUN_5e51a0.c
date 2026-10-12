/* Ghidra analysis pseudocode, not original source.
 * ev_56bf9e76ab0c031fab8380995f005739ca3b697a310321db3c480b01a4d86e23
 * Entry: 0x5e51a0; label: FUN_005e51a0
 */

void FUN_005e51a0(int *param_1,int param_2)

{
  size_t _Size;
  void *pvVar1;
  
  DAT_0096e570 = param_2;
  _Size = param_2 * 4;
  pvVar1 = (void *)(*param_1 + 3U & 0xfffffffc);
  DAT_0097157c = pvVar1;
  *param_1 = (*param_1 + 3U & 0xfffffffc) + _Size;
  _memset(pvVar1,0,_Size);
  pvVar1 = (void *)(*param_1 + 3U & 0xfffffffc);
  DAT_009716e4 = pvVar1;
  *param_1 = (*param_1 + 3U & 0xfffffffc) + _Size;
  _memset(pvVar1,0,_Size);
  DAT_00966380 = 0;
  FUN_005f8f80(param_1);
  return;
}

