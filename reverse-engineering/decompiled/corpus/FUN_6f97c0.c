/* Ghidra analysis pseudocode, not original source.
 * ev_ad38b5b12c7b5b6be74e46159191c12aead9520624245f9f1862d693e1fa9ce5
 * Entry: 0x6f97c0; label: __CallSettingFrame@12
 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* Library Function - Single Match
    __CallSettingFrame@12
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)__NLG_Notify1(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  __NLG_Notify1(param_3);
  return;
}

