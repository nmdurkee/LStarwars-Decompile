/* Ghidra analysis pseudocode, not original source.
 * ev_05a50d78b1ac39cbc8ac7a43523eae9528fc8f40ae743077c5c3f4eab8d21813
 * Entry: 0x6e78dc; label: FUN_006e78dc
 */

void * FUN_006e78dc(void *param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  void *pvVar2;
  size_t sVar3;
  
  sVar3 = 0;
  if ((param_2 == 0) || (param_3 <= 0xffffffe0 / param_2)) {
    param_2 = param_2 * param_3;
    if (param_1 != (void *)0x0) {
      sVar3 = __msize(param_1);
    }
    pvVar2 = _realloc(param_1,param_2);
    if ((pvVar2 != (void *)0x0) && (sVar3 < param_2)) {
      _memset((void *)(sVar3 + (int)pvVar2),0,param_2 - sVar3);
    }
  }
  else {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0xc;
    FUN_006e9fc2(0,0,0,0,0);
    pvVar2 = (void *)0x0;
  }
  return pvVar2;
}

