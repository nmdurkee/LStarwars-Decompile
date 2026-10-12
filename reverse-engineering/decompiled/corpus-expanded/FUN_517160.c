/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x517160; label: FUN_00517160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_00517160(int *param_1,uint *param_2,size_t param_3)

{
  uint uVar1;
  void *pvVar2;
  
  if ((param_1 != (int *)0x0) && (param_2 != (uint *)0x0)) {
    if (*param_1 + param_3 < *param_2) {
      uVar1 = *param_1 + 0xf;
      pvVar2 = (void *)(uVar1 & 0xfffffff0);
      *param_1 = (uVar1 & 0xfffffff0) + param_3;
      _memset(pvVar2,0,param_3);
      return pvVar2;
    }
  }
  pvVar2 = (void *)FUN_00512850();
  return pvVar2;
}

