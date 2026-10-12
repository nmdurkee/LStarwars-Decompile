/* Ghidra analysis pseudocode, not original source.
 * ev_ad38b5b12c7b5b6be74e46159191c12aead9520624245f9f1862d693e1fa9ce5
 * Entry: 0x6f9ea1; label: __set_errno_from_matherr
 */

/* Library Function - Single Match
    __set_errno_from_matherr
   
   Library: Visual Studio 2005 Release */

void __set_errno_from_matherr(int param_1)

{
  undefined4 *puVar1;
  
  if (param_1 == 1) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x21;
  }
  else if ((1 < param_1) && (param_1 < 4)) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x22;
    return;
  }
  return;
}

