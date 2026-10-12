/* Ghidra analysis pseudocode, not original source.
 * ev_7c1f0ecd29c800f910a33bdaa344f8ed50b7b31113b7bd43cf044ecf7b83bf10
 * Entry: 0x6ea018; label: FUN_006ea018
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006ea018(size_t param_1)

{
  int iVar1;
  void *pvVar2;
  undefined **local_10 [3];
  
  do {
    pvVar2 = _malloc(param_1);
    if (pvVar2 != (void *)0x0) {
      return;
    }
    iVar1 = __callnewh(param_1);
  } while (iVar1 != 0);
  if ((_DAT_0297c1ac & 1) == 0) {
    _DAT_0297c1ac = _DAT_0297c1ac | 1;
    std::bad_alloc::bad_alloc((bad_alloc *)&DAT_0297c1a0);
    _atexit((_func_4879 *)&LAB_007506ca);
  }
  std::exception::exception((exception *)local_10,(exception *)&DAT_0297c1a0);
  local_10[0] = &PTR_FUN_0076a75c;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_10,&DAT_007eca48);
}

