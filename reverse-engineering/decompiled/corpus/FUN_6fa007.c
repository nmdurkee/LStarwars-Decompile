/* Ghidra analysis pseudocode, not original source.
 * ev_ad38b5b12c7b5b6be74e46159191c12aead9520624245f9f1862d693e1fa9ce5
 * Entry: 0x6fa007; label: __handle_qnan2
 */

/* Library Function - Single Match
    __handle_qnan2
   
   Library: Visual Studio 2005 Release */

float10 __handle_qnan2(undefined4 param_1,double param_2,double param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  float10 fVar2;
  
  if (DAT_0082a740 == 0) {
    fVar2 = (float10)__umatherr(1,param_1,param_2,param_3,param_2 + param_3,param_4);
    return fVar2;
  }
  puVar1 = (undefined4 *)FUN_006ead5f();
  *puVar1 = 0x21;
  __ctrlfp();
  return (float10)(param_2 + param_3);
}

