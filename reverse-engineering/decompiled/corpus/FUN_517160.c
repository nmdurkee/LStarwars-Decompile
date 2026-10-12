/* Ghidra analysis pseudocode, not original source.
 * ev_e9352ae8b4f9815c7bd33078f32d38974dd715693a5fa54abaaf9429a7276350
 * Entry: 0x517160; label: FUN_00517160
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

