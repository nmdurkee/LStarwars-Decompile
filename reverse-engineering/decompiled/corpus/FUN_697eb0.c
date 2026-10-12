/* Ghidra analysis pseudocode, not original source.
 * ev_7a6f44793a1ae116413d84873b30ec9fe28028ad0afd3b3275dd7a03cd0119e5
 * Entry: 0x697eb0; label: FUN_00697eb0
 */

void FUN_00697eb0(void)

{
  void *pvVar1;
  
  pvVar1 = DAT_02972c04;
  if (DAT_02962bac != 0) {
    if (DAT_02972c04 != (void *)0x0) {
      FUN_006998f0();
      _free(pvVar1);
    }
    pvVar1 = DAT_02972c00;
    if (DAT_02972c00 != (void *)0x0) {
      FUN_006998f0();
      _free(pvVar1);
    }
    DAT_02972c04 = (void *)0x0;
    DAT_02972c00 = (void *)0x0;
    if ((DAT_02972c24 != (HANDLE)0x0) && (DAT_02972c28 != 0)) {
      DAT_02972c2c = 1;
      SetEvent(DAT_02972c24);
      while (DAT_02972c28 != 0) {
        Sleep(10);
      }
      DeleteObject(DAT_02972c24);
      DAT_02972c24 = (HANDLE)0x0;
      DAT_02972c28 = 0;
    }
    if (DAT_02972bf4 != 0) {
      FUN_004ef280(DAT_02972bf4,".\\pc\\nusound.cpp",0x72f);
    }
    DAT_02972bf4 = 0;
    DAT_02962bac = 0;
  }
  return;
}

