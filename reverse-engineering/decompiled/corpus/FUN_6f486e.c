/* Ghidra analysis pseudocode, not original source.
 * ev_89d123adc6bf396b2f6b4ec3563e25957edd0c204114ec20eecbaddaafaf9a77
 * Entry: 0x6f486e; label: type_info::_Type_info_dtor
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    private: static void __cdecl type_info::_Type_info_dtor(class type_info *)
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl type_info::_Type_info_dtor(type_info *param_1)

{
  int *_Memory;
  int *piVar1;
  int *piVar2;
  
  __lock(0xe);
  _Memory = DAT_0297cae0;
  if (*(int *)(param_1 + 4) != 0) {
    piVar1 = (int *)&DAT_0297cadc;
    do {
      piVar2 = piVar1;
      if (DAT_0297cae0 == (int *)0x0) goto LAB_006f48b2;
      piVar1 = DAT_0297cae0;
    } while (*DAT_0297cae0 != *(int *)(param_1 + 4));
    piVar2[1] = DAT_0297cae0[1];
    _free(_Memory);
LAB_006f48b2:
    _free(*(void **)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  FUN_006f48d5();
  return;
}

