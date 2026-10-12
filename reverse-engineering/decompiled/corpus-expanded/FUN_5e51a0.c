/* Ghidra pseudocode, not original source.
 * ev_dd2b431ee7d7df08292740893bb7b99558b7953fea1da99d97b81497b86ab5e2
 * Entry: 0x5e51a0; label: FUN_005e51a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

