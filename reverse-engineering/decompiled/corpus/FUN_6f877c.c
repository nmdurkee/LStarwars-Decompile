/* Ghidra analysis pseudocode, not original source.
 * ev_ad38b5b12c7b5b6be74e46159191c12aead9520624245f9f1862d693e1fa9ce5
 * Entry: 0x6f877c; label: ___DestructExceptionObject
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___DestructExceptionObject
   
   Library: Visual Studio 2005 Release */

void ___DestructExceptionObject(int *param_1)

{
  void *pvVar1;
  
  if ((((param_1 != (int *)0x0) && (*param_1 == -0x1f928c9d)) && (param_1[7] != 0)) &&
     (pvVar1 = *(void **)(param_1[7] + 4), pvVar1 != (void *)0x0)) {
    _CallMemberFunction0((void *)param_1[6],pvVar1);
  }
  return;
}

